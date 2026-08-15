# Project Spec

## What this is

A personal Pokémon Emerald romhack built on top of [pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion) (pret decomp + community expansion). Custom content is being added incrementally, largely by Claude Code agent sessions. This file exists so a fresh agent session has enough context to keep working without re-discovering the whole project from scratch.

Custom region so far: **Ouderkerk** (Dutch-themed), maps prefixed `data/maps/Ouderkerk*`. Content and NPC dialog for this hack are written in Dutch, often as in-jokes for a specific friend group.

## Repo layout notes

- This is a standard pret-style decomp. Source of truth for maps is `data/maps/<MapName>/map.json` and `data/layouts/layouts.json`.
- `header.inc`, `events.inc`, and `connections.inc` inside each map folder are **auto-generated from map.json and are gitignored** — never hand-edit them, edit `map.json` instead.
- To regenerate a map's `.inc` files after editing its `map.json` (without doing a full `make`):
  ```
  ./tools/mapjson/mapjson map emerald data/maps/<MapName>/map.json data/layouts/layouts.json data/maps/<MapName>
  ```
- To sanity-check a map/script change compiles without doing a full ROM build (the full `make` may be broken locally due to an unrelated missing-newlib-headers toolchain issue — see "Known environment issues" below):
  ```
  make build/emerald/data/map_events.o
  ```
  This runs the real preproc → cpp → as pipeline over all `scripts.inc`/`map.json`-derived data and will fail loudly on bad script/text syntax.

## Conventions used in this hack

- **NPC scripts**: standard pret macros — `lock`, `faceplayer`, `msgbox ..., MSGBOX_DEFAULT`, `goto_if_set`, `setflag`, `release`, `end`. Look at existing `data/maps/*/scripts.inc` files for the idiom.
- **"Talk once, then different dialog forever after" pattern**:
  ```
  EventScript_Foo::
      lock
      faceplayer
      goto_if_set FLAG_X, EventScript_FooRepeat
      msgbox Text_FooFirst, MSGBOX_DEFAULT
      setflag FLAG_X
      release
      end

  EventScript_FooRepeat::
      msgbox Text_FooRepeat, MSGBOX_DEFAULT
      release
      end
  ```
- **Flags for this kind of one-off story/dialog state**: reserved from the `FLAG_UNUSED_0x0xx` pool in `include/constants/flags.h` — rename one of those defines in place (don't delete the surrounding block, don't reuse a flag that's already meaningful elsewhere). Give it a descriptive name (e.g. `FLAG_TALKED_TO_MARGRIET`).
- **Object event placement**: `"flag": "0"` on an object_event means it's always visible (no hide-flag). Use `elevation` matching the metatile it stands on (check `data/layouts/<Layout>/map.bin` / the layout's tile grid if unsure — don't guess).
- **Dialog text**: `.string` macro. `\n` = line break within the same textbox, `\l` = further line within the same (3-line) box, `\p` = new textbox page (player presses A), `$` = end of string. Keep each line under ~38 characters. `charmap.txt` supports Dutch accented characters (`é`, `ë`, `ï`, etc.) if needed. In-game proper nouns/names are conventionally written in caps (e.g. `MARGRIET`, `POKéMON`).

### Cloning an existing map as a starting point for a new area

Porymap's "duplicate map" (and hand-copying a `map.json`) copies every symbolic name as-is. Names aren't auto-uniquified, so a cloned map silently keeps referencing/sharing the original's identity in a few places. Go through all of these on the clone before treating it as done — none of them cause a build error if skipped, which is exactly why they're easy to miss:

- **`local_id`** on object_events: becomes a `#define LOCALID_X <n>` in the auto-generated `include/constants/map_event_ids.h`. It's a plain macro, not scoped to the map, so if two maps reuse the same `local_id` name with *different* numeric positions, whichever is defined later in that generated header silently wins everywhere — including in the *original* map's own scripts. This showed up for real: `Ouderkerk` (cloned from `LittlerootTown`) and `LOCALID_LITTLEROOT_RIVAL`/`LOCALID_LITTLEROOT_BIRCH` colliding, breaking LittlerootTown's own intro script. Fixed by renaming the clone's `local_id`s to be map-specific (`LOCALID_OUDERKERK_*`). **Tell:** `-Wall -Werror` build logs a `'LOCALID_X' redefined` warning (see "Toolchain" for how to actually get a build that surfaces this). **Before renaming a colliding one, `grep -rn` the name repo-wide, not just the map's own `scripts.inc`** — a *shared* script (e.g. `data/scripts/players_house.inc`) can intentionally hardcode one `local_id` name used by multiple maps by design (matching indices on purpose, e.g. two gender-variant house maps). Renaming away from under that isn't a warning, it's a hard assembler error (`non-constant expression in ".if" statement`, because the now-undefined symbol isn't a number anymore). If you hit that, the fix is usually to have each map's own entry-point script pass its correct `local_id` into the shared script via a scratch var (`VAR_0x8008` or similar) instead of the shared script hardcoding a name — see the `LOCALID_PLAYERS_HOUSE_2F_MOM` fix in Status below for a worked example.
- **`flag`** on object_events (the per-object visibility/hide flag): this is a real save-file flag, and reusing the original map's flag name means the two objects share hidden/shown state — toggle one, the other changes too. **No build warning at all for this one.** `Ouderkerk`'s Fat Man/Mom currently still share `FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN`/`FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE` with LittlerootTown's — known, not yet fixed as of 2026-08-15 (see Status below). Give the clone's objects their own flags (reserve fresh ones the same way as the `FLAG_TALKED_TO_MARGRIET` example above).
- **`script`** references on object_events/bg_events/coord_events: cloning doesn't fork the script — the clone's objects keep calling the *original* map's `scripts.inc` symbols (e.g. `Ouderkerk`'s Twin/Fat Man/Mom/sign objects still call `LittlerootTown_EventScript_*`), which means the clone shows the original's text/logic verbatim (still says "LITTLEROOT", may reference the original map-specific vars/state) until you give the clone its own scripts and point these at them.
- Lower priority / only matters if the area needs to feel distinct: `region_map_section` (controls the Town Map / Fly list name), `music`.

## Toolchain

- The `arm-none-eabi-gcc` on `PATH` (Homebrew's) is missing newlib (`string.h`, `alloca.h`, etc.) and **cannot build this project** — a plain `make` fails immediately with `fatal error: string.h: No such file or directory`.
- A working toolchain **is** installed at `/opt/devkitpro/devkitARM/bin` (includes newlib). **Use `./reload`** (repo root) for the normal edit-build-play loop: it exports `DEVKITARM`/`DEVKITPRO` correctly, discards Porymap no-op rewrite noise from `git status`, runs a full `make -j`, then quits/relaunches `mGBA.app` with the freshly built `pokeemerald.gba`. The `Makefile` itself references `$(DEVKITARM)`, so as long as that env var is set (which `./reload` does), plain `make` works too — you don't need to manually prepend `PATH`.
  ```
  ./reload
  ```
  A clean build has **zero** warnings — treat any `redefined` warning in the log as a real bug to fix (see the map-cloning checklist above), not noise to ignore.
- For a quick syntax check of just map/script data without a full build:
  ```
  make build/emerald/data/map_events.o
  ```
  (works even without `DEVKITARM` set, since it doesn't touch C sources)
- No emulator CLI is set up for automated in-game verification — `mGBA.app` is GUI-only (no scripting/screenshot flags found). `./reload` opens it with the new build automatically; actually playing through a change still means clicking through by hand.
- The `tools/mapjson/mapjson event_constants` mode (regenerates `include/constants/map_event_ids.h` from every map.json) breaks/errors when passed the full ~943-file list as separate args — don't invoke it directly for that; a full `make`/`./reload` regenerates it correctly (it's gitignored, auto-generated, never commit it). If you need to hand-verify a `local_id` rename without a full build, it's safe to edit that generated header directly for local testing.

## Status / Latest work

_Updated before every commit. Newest entry on top — don't delete older entries, this is the changelog a new agent session should skim first._

- **2026-08-15**: Added a starter-picking scene to replace the skipped Birch intro. Three `OBJ_EVENT_GFX_ITEM_BALL` objects in `Ouderkerk_MargrietHouse_1F` (Shinx/Riolu/Piplup, `Ouderkerk_MargrietHouse_1F_EventScript_{Shinx,Riolu,Piplup}Ball` in that map's `scripts.inc`) ask (yes/no) then `givemon ..., 5` on yes; picking one hides/removes all three (shared `FLAG_HIDE_MARGRIET_HOUSE_1F_STARTER_BALLS`) and sets `FLAG_GOT_MARGRIET_STARTER`. Also sets `FLAG_SYS_POKEMON_GET` here — that's the flag `src/start_menu.c` checks to show the POKéMON option in the pause menu; vanilla sets it on Route 101 right after Birch's lab, which our skip-intro flow never passes through, so it had to move here or the menu option would never appear (this resolves the "no starter Pokémon" gap noted in the entry below). Also fixed a bug where `Ouderkerk_MargrietHouse_1F`'s upstairs warp still pointed at vanilla `LittlerootTown_MaysHouse_2F` instead of `Ouderkerk_MargrietHouse_2F` (made the Margriet NPC from the first session unreachable). **Map-cloning footgun encountered again, differently:** fixed a `LOCALID_PLAYERS_HOUSE_2F_MOM` collision between `LittlerootTown_BrendansHouse_2F`/`MaysHouse_2F` (introduced by trimming `MaysHouse_2F`'s object list, shifting its indices) — but unlike the earlier Ouderkerk case, a simple rename broke the build (hard assembler error, not just a warning), because `data/scripts/players_house.inc`'s shared "mom comes upstairs" cutscene hardcodes that one symbol and is called from both maps. Fixed by keeping the local_ids unique per-map but threading the correct one in via `VAR_0x8008`, set by each map's own `*_EventScript_WallClock` entry point before it jumps into the shared script, instead of the shared script hardcoding a name that has to mean two different things at once. Lesson for the map-cloning checklist above: before renaming a colliding `local_id`, grep for it repo-wide (not just the map's own `scripts.inc`) — shared/common scripts can depend on two maps' local_ids matching by design.
- **2026-08-15**: Added a "skip the intro" path for New Game. Selecting New Game from the title screen no longer runs the Professor Birch speech or the naming/gender-select screens — it hardcodes the player to male, name "FRITS", and warps straight to `HEAL_LOCATION_OUDERKERK_MARGRIET_HOUSE_2F`. Implementation: `src/main_menu.c`'s `ACTION_NEW_GAME` case (in `Task_HandleMainMenuAPressed`) now sets `gSaveBlock2Ptr->playerGender`/`playerName` directly and jumps to a new `CB2_NewGameSkipIntro` (added in `src/overworld.c`, declared in `include/overworld.h`) instead of starting the `Task_NewGameBirchSpeech_Init` task chain; `CB2_NewGameSkipIntro` mirrors `CB2_NewGame` but re-warps to the heal location (via `SetWarpDestinationToHealLocation` + `WarpIntoMap`) right after `NewGameInitData()` instead of using the truck-intro `gFieldCallback`. The old Birch speech task chain is left in place but is intentionally unreachable — `Task_NewGameBirchSpeech_Init` is still assigned to a task (then that task is immediately destroyed) purely so it stays *referenced*, since this build uses `-Werror -Wall` and an actually-orphaned static function would fail the build. **Known gap:** since the Birch scene is fully skipped, the player currently starts with an empty party (no starter Pokémon) — no replacement starter-grant logic has been added; flag this to the user if it comes up. Verified by a full `PATH=/opt/devkitpro/devkitARM/bin:$PATH make` ROM build succeeding cleanly; not yet verified by actually playing through New Game in an emulator (see "Toolchain" above for why that's manual).

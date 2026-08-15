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

## Known environment issues

- A full `make` currently fails early with `fatal error: string.h: No such file or directory` (and similar for `alloca.h`) — this is a broken/misconfigured `arm-none-eabi-gcc` newlib install on this machine, unrelated to any map/script content. It blocks producing a full `.gba` ROM locally until fixed. It does **not** block validating map/script/data changes — use `make build/emerald/data/map_events.o` for that instead.

## Status / Latest work

_Updated before every commit. Newest entry on top — don't delete older entries, this is the changelog a new agent session should skim first._

- **2026-08-15**: Added infra: this `spec.md` and the commit-time update rule in `CLAUDE.md`. Added first custom NPC: Margriet, in `Ouderkerk_MargrietHouse_2F`, standing in the bed (`OBJ_EVENT_GFX_HEX_MANIAC`, tile x=7,y=4, elevation 3 — the pillow tile). Reserved `FLAG_TALKED_TO_MARGRIET` (was `FLAG_UNUSED_0x020`). Script: `Ouderkerk_MargrietHouse_2F_EventScript_Margriet` in `data/maps/Ouderkerk_MargrietHouse_2F/scripts.inc`, first-visit dialog then a shorter repeat dialog once the flag is set. **Note:** the dialog text actually committed was rewritten from what was originally requested — the original included explicit sexual content referencing what appeared to be a real person, which was declined; the shipped version keeps the "worried mom asks you to find her son" premise without that content. If a different tone is wanted, edit the `.string` blocks in that file directly.

# Repo rules for agent sessions

This is a Pokémon Emerald romhack built on pokeemerald-expansion. Read [spec.md](spec.md) first — it has project context, conventions (map data, scripts, flags, dialog text), and a running status log of the latest work.

## Rule: update spec.md for major/config changes only

Before committing, add an entry to the **"Status / Latest work"** section at the bottom of `spec.md` **only if the commit is a major or config-level change** — new systems/mechanics, workflow or toolchain changes, cross-cutting fixes, anything a fresh session would otherwise waste time rediscovering. Examples: adding a new gameplay system, changing the build/toolchain setup, a non-obvious bugfix whose lesson generalizes (like the `local_id` collision footguns documented above).

**Don't** add an entry for routine content work — adding/editing a map, placing objects, wiring a script to an existing pattern, tweaking dialog text, tile edits. That's expected, ongoing work, not something worth a changelog line each time; logging every one of those would make the log useless (nobody will read 50 entries to find the one that matters).

When in doubt, ask: "would a fresh agent session be meaningfully worse off without this note?" If no, skip it.

When you do add an entry: newest first, don't delete older entries, summarize concretely enough (file paths, flag/script names) that a future session can act on it without re-discovering it. This is the only persistent memory across agent sessions and across machines for this project — keep it honest and current, but don't let it turn into a play-by-play.

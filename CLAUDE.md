# Repo rules for agent sessions

This is a Pokémon Emerald romhack built on pokeemerald-expansion. Read [spec.md](spec.md) first — it has project context, conventions (map data, scripts, flags, dialog text), and a running status log of the latest work.

## Rule: update spec.md before every commit

Right before creating a git commit in this repo, update the **"Status / Latest work"** section at the bottom of `spec.md`:

- Add a new entry at the top of the list (newest first, don't delete older entries).
- Summarize what changed and the current state, concretely enough that a future agent session with zero prior context can pick up the work without re-discovering it (file paths, flag/script names, what's done vs. still TODO).

This is the only persistent memory across agent sessions for this project — keep it honest and current.

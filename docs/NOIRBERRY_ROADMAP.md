# NoirBerry roadmap

NoirBerry is a research fork of [zortos293/Lichii](https://github.com/zortos293/Lichii), branched at Lichii build-88 (`55532f2d81`).

Remotes used below: `origin` (dewayneku/NoirBerry), `upstream` (zortos293/Lichii), `frizti` (Frizti/Lichii).

## Phase 1: Rebrand and first UI fixes (done, branch `noirberry/rebrand`)

- Renamed everything users see, the executable, release asset names, packaging ids and the update-check repository to NoirBerry. Saves, settings and shader caches still use the shared Eden/Lichii data folders.
- Added placeholder NoirBerry artwork (`dist/branding`, `tools/Generate-NoirBerryIcons.ps1`).
- Add-Ons can now install several mod ZIPs at once.
- Shortcuts fall back to the NoirBerry icon when a title has none (Home Menu), and generated icons keep their transparency.
- Open NoirBerry Folders gained Current Log File, Shader Cache, Screenshots and Config entries, plus a rebindable Open Log Folder hotkey (Ctrl+Shift+L).

## Phase 2: Port Frizti's fixes (next)

Source: [Frizti/Lichii `frizti-v1`](https://github.com/Frizti/Lichii/releases/tag/frizti-v1), a Windows build of Frizti's fork of Lichii.

Its release notes list:

- Ocarina of Time: no more one-frame white flashes, because the occlusion counter is paused instead of reset at each submission (`e44ee5c79f`, `87203d5936`, originally zortos293/Lichii#121 by Kajcsi).
- Ocarina of Time: a built-in Max Resolution patch (`1ceb8c972a`), plus the culling, vegetation, grass-pointer and fog fixes from `bisect/oot-6` and `fix/oot-fog`.
- Diagnostics: `EDEN_NX2_FLASH_WATCH`, `EDEN_NX2_PENDING_WRITE_TRACE`, `EDEN_NX2_TABLE_POINTER_TRACE`. All are off by default.

Reports say it reaches 60 FPS in Ocarina of Time. Build-88 already bundles Dark's Dynamic FPS mod, so the gain should be measured against NoirBerry, not assumed.

State as of 2026-11-06:

- `frizti-v1` and build-88 split at `8813b44794`. Frizti has 74 commits that build-88 lacks, and build-88 has 18 that Frizti lacks.
- Going by patch content (`git cherry HEAD frizti-v1`), 3 of Frizti's commits are already in NoirBerry and 55 are not. Upstream already merged some reviewed Frizti performance ports under different commit ids, so expect conflicts in `buffer_cache`, `vk_scheduler`, `vk_query_cache` and `shader_recompiler`.

Plan:

1. Branch `noirberry/frizti` from `noirberry/rebrand`.
2. Cherry-pick by area, oldest first, building after each group:
   - Ocarina rendering fixes (occlusion counter, vegetation/pointer loads, sky ambient fold, ISBEWR NaN, gather lowering).
   - Built-in Max Resolution patch.
   - Kernel and timing (`1ca792919a` core spin, MWAITX `d8d286ecea`, `35ab983ecf`).
   - Diagnostics and frame-dump tooling (off by default).
3. Leave out commits Frizti marks as experiments (`c6204e777e` "EXPERIMENT (not for nx2)", `1398d8a1e2`) and the opt-in `TEMPORARY` fog workaround (`4aa1e429a4`) unless testing shows they help.
4. Credit Frizti and the original authors in the commit messages, keeping their commits as cherry-picks with `-x`.
5. Test Ocarina of Time on Windows/NVIDIA: white flashes, resolution, frame rate with and without Dynamic FPS. Then smoke-test one more nx2 title.

## Phase 3: Catch up with upstream

- Merge `upstream/nx2` changes made after build-88, including the AMD fixes announced for the next Lichii build.
- After each upstream merge, re-check which Frizti patches upstream has absorbed.

## Ideas backlog

- Real NoirBerry artwork to replace the placeholders.
- Bake the git commit into local builds at build time instead of configure time, so the version string stays current.

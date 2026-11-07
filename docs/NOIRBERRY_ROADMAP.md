# NoirBerry roadmap

NoirBerry is a research fork of [zortos293/Lichii](https://github.com/zortos293/Lichii), branched at Lichii build-88 (`55532f2d81`).

Remotes used below: `origin` (dewayneku/NoirBerry), `upstream` (zortos293/Lichii), `frizti` (Frizti/Lichii).

## Phase 1: Rebrand and first UI fixes (done, branch `noirberry/rebrand`)

- Renamed everything users see, the executable, release asset names, packaging ids and the update-check repository to NoirBerry. Saves, settings and shader caches still use the shared Eden/Lichii data folders.
- Added placeholder NoirBerry artwork (`dist/branding`, `tools/Generate-NoirBerryIcons.ps1`).
- Add-Ons can now install several mod ZIPs at once.
- Shortcuts fall back to the NoirBerry icon when a title has none (Home Menu), and generated icons keep their transparency.
- Open NoirBerry Folders gained Current Log File, Shader Cache, Screenshots and Config entries, plus a rebindable Open Log Folder hotkey (Ctrl+Shift+L).

## Phase 2: Port Frizti's fixes (merged, branch `noirberry/frizti`, waiting on in-game testing)

Source: [Frizti/Lichii `frizti-v1`](https://github.com/Frizti/Lichii/releases/tag/frizti-v1).

Frizti's history contains 16 merge commits and several rebased duplicates of the same change, so `frizti-v1` was merged as a whole rather than cherry-picked one commit at a time.

Brought in:

- Ocarina of Time: the occlusion counter is paused instead of reset at each submission, so Link and the scene no longer flash white for a frame (`e44ee5c79f`, `87203d5936`, originally zortos293/Lichii#121 by Kajcsi).
- Ocarina of Time: vegetation and table-pointer storage bindings, sky-ambient multiply folding, the ISBEWR door NaN fix, and per-tap/F16/depth gather lowering.
- Kernel core spin for Switch 2 titles, native graphics storage buffer sizing, and redundant TAS callback suppression.
- Diagnostics, all off unless their variable is set: `EDEN_NX2_FLASH_WATCH`, `EDEN_NX2_PENDING_WRITE_TRACE`, `EDEN_NX2_TABLE_POINTER_TRACE`, and the debug-server memory and input tools.

How conflicts were resolved:

- NoirBerry's version was kept wherever upstream Lichii had already merged a newer version of the same change. That covers the Max Resolution and Dynamic FPS built-ins, the MWAITX deadline, the MaxContinuousRange cache, the native uniform-bank upload, the usage tracker and the debug-server tools.
- The Vulkan pipeline cache stays at v53.
- The frame dump keeps NoirBerry's `capture_frame` design. Frizti's rewritten frame dump, its per-draw pipeline-statistics probes and its skipped-draw records are left out.
- Removed the experiment switches: the OoT fog/exposure shader replacement (TEMPORARY), `EDEN_NX2_INVALIDATE_BEFORE_DISPATCH`, and `EDEN_NX2_WRITTEN_SSBO_MARK_KIB`.

Still to do:

1. Test Ocarina of Time on Windows/NVIDIA: white flashes, grass and vegetation, door NaN, resolution, and frame rate with and without Dynamic FPS. Reports claim 60 FPS; measure it.
2. Smoke-test another nx2 title for regressions from the buffer-binding changes.
3. Merge `noirberry/frizti` into the NoirBerry main line once it holds up.

## Phase 3: Catch up with upstream

- Merge `upstream/nx2` changes made after build-88, including the AMD fixes announced for the next Lichii build.
- After each upstream merge, re-check which Frizti patches upstream has absorbed.

## Ideas backlog

- Real NoirBerry artwork to replace the placeholders.
- Bake the git commit into local builds at build time instead of configure time, so the version string stays current.

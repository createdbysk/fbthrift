# Phase 5: Upstream Manifest Alignment & Python Isolation

## Ralph Loop Checkpoint

See checkpoint state: `/home/satishvk/gdrive/worklog/oss_thrift_python/.claude/ralph-loops/oss_thrift_python_phase_5_upstream_alignment.yaml`

Or activate with: `/satishvk-ralph-loop /home/satishvk/gdrive/worklog/oss_thrift_python/.claude/ralph-loops/oss_thrift_python_phase_5_upstream_alignment.yaml`

## Goal

Replace all local non-python manifests with upstream fbsource versions, ensure the complete dependency chain for `fbthrift-python` uses -python variants exclusively, and verify all tests pass.

## Context

Phases 2-3 created -python manifest variants with `BUILD_SHARED_LIBS=ON` to isolate Python's shared library requirement from default builds. The dependency graph shows no violations—all fbthrift-python dependencies correctly use -python variants as leaf nodes.

**Key insight**: The graph is clean. Every manifest in the fbthrift-python dependency chain either:
- Is a -python variant
- Is a non-python variant that should be replaced with an upstream version
- Is already using correct -python dependencies

## Steps

### 1. Fetch Upstream Manifests
Retrieve base (non-python) manifests from fbsource upstream for all dependencies in the chain:
- gflags, glog, openssl, liboqs (base versions)
- Any other non-python variants in the dependency graph

### 2. Replace Local Manifests
Replace local non-python manifest files with upstream versions to match fbsource baseline.

### 3. Verify Dependency Chain
Confirm all manifests in `fbthrift-python` dependency tree that reference base manifests have been correctly replaced:
- Check that no -python manifest still depends on base versions (except openssl-python → system openssl)
- Verify no circular dependencies introduced

### 4. Build & Test
Run the full build and test suite:
```bash
python3 build/fbcode_builder/getdeps.py build fbthrift-python
python3 build/fbcode_builder/getdeps.py test fbthrift-python
```

Expected result: All 347 tests pass.

### 5. Commit
Clean history with minimal, well-scoped commits explaining the alignment.

## Success Criteria

- ✅ All non-python manifests match upstream fbsource versions
- ✅ All fbthrift-python transitive dependencies use -python variants
- ✅ All 347 tests pass
- ✅ No regressions in build time or artifact size
- ✅ Dependency graph remains violation-free

## Checkpoints (Ralph Loop)

1. **Fetch & list** upstream manifests (verify against local)
2. **Replace** each non-python manifest (one at a time)
3. **Verify** dependency resolution (no broken links)
4. **Build** (check for compilation errors)
5. **Test** (all 347 tests must pass)
6. **Commit** (clean history)

## Notes

- The dependency diagram shows clean isolation—this should be a straightforward alignment exercise
- Focus on fidelity to upstream rather than creative optimization
- If a test fails, investigate root cause before proceeding (don't skip)

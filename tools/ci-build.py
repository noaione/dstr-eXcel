from pathlib import Path
import shutil
import os
from typing import List, Optional

base_dir = Path(__file__).absolute().parent.parent
build_dir = base_dir / "build"
target_dir = base_dir / "target"
if target_dir.exists():
    shutil.rmtree(target_dir, ignore_errors=True)
target_dir.mkdir(parents=True, exist_ok=True)

base_execute = ["cmake", "..", "-G", "Ninja"]
os_name = os.name


def clean():
    os.chdir(base_dir)
    shutil.rmtree(build_dir, ignore_errors=True)


def prepare():
    clean()
    build_dir.mkdir(parents=True, exist_ok=True)


def find_executable() -> Optional[Path]:
    executable = None
    for exec in (build_dir / "src").glob("*"):
        if exec.name.startswith("eXcelSystem"):
            executable = exec
            break
    return executable


def build(extra_flags: List[str] = [], debug_mode: bool = False, output_name: str = "eXcelSystem"):
    execute_this = base_execute + extra_flags
    if debug_mode:
        execute_this.append("-DDEBUG_MODE=on")
    print("-- Executing:", " ".join(execute_this))
    os.chdir(build_dir)
    os.system(" ".join(execute_this))
    os.system("ninja")
    executable = find_executable()
    if not executable:
        raise Exception("Failed to build the project, no exe found")
    output_name += ".exe"
    output_target = target_dir / output_name
    print(executable, "->", output_target)
    shutil.copy(executable, output_target)


print(f"Building for {os_name}")
prepare()
print("\n-- Building Linked List version")
build(output_name="eXcelSystem_linkedlist")
prepare()
print("\n-- Building Linked List version (debug)")
build(debug_mode=True, output_name="eXcelSystem_linkedlist_debug")
prepare()
print("\n-- Building Array Struct version")
build(extra_flags=["-DARRAY_STRUCT=on"], output_name="eXcelSystem_array")
prepare()
print("\n-- Building Array Struct version (debug)")
build(extra_flags=["-DARRAY_STRUCT=on"], debug_mode=True, output_name="eXcelSystem_array_debug")
os.chdir(base_dir)
clean()
print("\n-- Done")

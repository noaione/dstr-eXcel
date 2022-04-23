import os
import argparse
import shutil
from pathlib import Path
from typing import List, Optional

base_dir = Path(__file__).absolute().parent.parent
build_dir = base_dir / "build"
target_dir = base_dir / "target"
target_dir.mkdir(exist_ok=True)

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
    all_paths = list((build_dir / "src").glob("*"))
    for exec in all_paths:
        if exec.name.startswith("eXcelSystem"):
            executable = exec
            break
    return executable


def build(extra_flags: List[str] = [], debug_mode: bool = False, output_name: str = "eXcelSystem") -> Path:
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
    if os_name == "nt":
        output_name += ".exe"
    output_target = target_dir / output_name
    print(executable, "->", output_target)
    shutil.copy(executable, output_target)
    return output_target


parser = argparse.ArgumentParser(description="Build the project")
parser.add_argument("-d", "--debug", action="store_true", help="Build in debug mode")
# Create selection between linked list and array struct
parser.add_argument(
    "-b",
    "--build",
    choices=["linked", "array"],
    nargs="?",
    default="linked",
    const="linked",
    help="Build specific version, default is linked list",
)
args = parser.parse_args()
print(f"Building for {os_name}")
extra_flags = []
prt_txt = "\n-- Building Linked List Version"
output_name = "eXcelSystem_linkedlist"
if args.build == "array":
    extra_flags.append("-DARRAY_STRUCT=on")
    prt_txt = "\n-- Building Array Struct Version"
    output_name = "eXcelSystem_arraystruct"
if args.debug:
    prt_txt += " (debug)"
    output_name += "_debug"
prepare()
print(prt_txt)
out_dir = build(extra_flags=extra_flags, debug_mode=args.debug, output_name=output_name)
print(f"\n-- Build Complete: target/{out_dir.name}")

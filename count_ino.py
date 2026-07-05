from pathlib import Path

ino_files = list(Path(".").rglob("*.ino"))

print(f"Number of .ino files: {len(ino_files)}")

for file in ino_files:
    print(file)

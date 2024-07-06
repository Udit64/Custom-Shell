# Shell Command and Error Handling

## Internal Commands

1. **cd**: Change directory to the provided path. If no path is provided, change to the home directory.
    - **Options handled:**
        - `cd -`: Go to the previous directory.
        - `cd ~`: Go to the root directory.
    - **Errors handled:**
        - Attempting to change to a non-existent directory.
        - Too many arguments if multiple inputs are provided.

2. **pwd**: Print the current working directory.
    - **Options handled:**
        - `pwd -L`: Default implementation.
    - **Errors handled:**
        - Too many arguments if multiple inputs are provided.

3. **echo**: Print the provided input.
    - **Options handled:**
        - `echo -n`: No newline after printing.
        - `echo -E`: Default echo implementation.
    - **Assumption:** Echo will print whatever the user provides without corner cases.

## External Commands

*Note: External commands are handled using both fork and pthread. Options and error handling are the same for both, with the same C file producing the desired output.*

1. **ls**: List filenames in the current directory. Also supports `ls <path>` to list filenames in the specified directory.
    - **Options handled:**
        - `ls -a`: Show hidden files.
        - `ls -A`: Do not show `.` and `..` files.
    - **Errors handled:**
        - Directory does not exist.
        - Incorrect flag.

2. **cat**: Concatenate and display files.
    - **Options handled:**
        - `cat -n`: Number the output lines.
        - `cat -E`: Display `$` at the end of each line.
    - **Errors handled:**
        - File not found.
        - Directory provided instead of a file.

3. **rm**: Remove the specified file.
    - **Options handled:**
        - `rm -i`: Ask before removal.
        - `rm -f`: Force removal, no error if the file does not exist.
    - **Errors handled:**
        - Directory provided instead of a file.
        - File does not exist.

4. **mkdir**: Create a directory with the specified name.
    - **Options handled:**
        - `mkdir -v`: Provide feedback about directory creation.
        - `mkdir -p`: Create parent directories as needed.
    - **Errors handled:**
        - No directory name specified.
        - Directory already exists.

5. **date**: Display the current date and time.
    - **Options handled:**
        - `date -u`: Display UTC time.
        - `date -r`: Display the last modification time of the specified file.
    - **Errors handled:**
        - Incorrect flag.
        - File does not exist (for `date -r`).

## Test Cases

### Test Case 1:
```bash
ls
ls -a
mkdir udit
cd udit
mkdir -v hitesh
ls
echo I am a good boy
cd -
cd -
cd -
ls ./udit
mkdir -p udit/aa/bb
cat -n s1 s2
rm udit # This will throw an error
pwd
date -r s1
rm -i s1 s2
pwd

## Test Cases

### Test Case 2:
```bash
ls &t
ls -a &t
mkdir udit &t
cd udit &t
mkdir -v hitesh &t
ls &t
echo I am a good boy &t
cd - &t
cd - &t
cd - &t
ls ./udit &t
mkdir -p udit/aa/bb &t
cat -n s1 s2 &t
rm udit &t # This will throw an error
pwd &t
date -r s1 &t
rm -i s1 s2 &t
pwd &t

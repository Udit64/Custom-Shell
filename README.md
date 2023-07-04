The shall can handle the following commands and errors.
Internal Commands:
1) cd : change directory to given path provided .(if user enter only cd go to home directory)
	Options handled:
		1) cd - : Go to previous directory.
		2) cd ~ : Go to root directory.
	Errors handled:
		1) cd to directory which does not exist.
		2) too many arguments if multiple inputs provided.
2) pwd: only pwd and pwd -L (default implementation) is handled (as told by sir that we need to handle only default implementation in case of pwd).
	Error handled : too many arguments if multiple inputs provided.
3) echo: print whatever input provided.
	Options handled:
		1) echo -n: no next line after printing stuff.
		2) echo -E: default echo implementation
Assumption : unable to find any corner case as echo command will print whatever user provided.

External Commands:
Note : I have handled external commands using both fork and pthread. In both cases , options and error handling are same in both the same c file is running to produce the desired output.

1)ls : Gives filenames of the current directory. Also handled ls <path>, in this case gives filename of the given directory.
	Options handled:
		1) ls -a : Also shows the hiden files.
		2) ls -A : dont show files with starting . and .. .
	Errors handled:
		1) In case of directory which is not exist , it will throw an error.
		2) Incorrect flag
2)cat : concatenate user inputed files and print on terminal the same.(I had handled command in such a way that user can enter filename with word limit of 200)
	Options handled:
		1) cat -n: It will print the file content with line number.
		2) cat -E: It will print '$' at the end of line.
	Errors handled:
		1) File not found 
		2) In case directory provided instead of file 
3)rm : remove the file whose name is specified (I had handled command in such a way that user can enter filename with word limit of 200)
	Options handled:
		1) rm -i: Ask before removal
		2) rm -f: force removal and also dont specify if file does not exist.
	Errors handled:
		1) If directory given instead of file error it will throw error.
		2) File does not exist error.
4)mkdir: creates a directory with name specified by user.
	Options handled:
		1)mkdir -v: gives feedback to the user regarding formation of a directory.
		2)mkdir -p: also creates the parent directory if not already created.
	Errors handled:
		1) In case user does not specify any directory name .
		2) Unable to create directory in case of directory already existed.
5)date: Shows current date and time to user.
	Options handled:
		1)date -u: gives UTC time frame to user.
		2)date -r: gives last modification time of file provided.
	Errors handled:
		1) Incorrect flag.
		2) File does not exist error in case of date -r.

#Test Cases:
test case 1:
(I had to create some files s1 and s2 already in the directory for other functioning)
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
rm udit(will throw some error)
pwd
date -r s1
rm -i s1 s2
pwd

Test case 2:

Again do the above test case but use &t at the end of every command to check thread processes as well.

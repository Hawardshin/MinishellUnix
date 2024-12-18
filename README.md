## MiniShell: As beautiful as a shell

### Summary | 요약
This project is about creating a simple shell—a personal version of bash. You will gain deeper insights into processes and file descriptors by building this project.

이 프로젝트는 bash를 참고해서 개인용 버전인 간단한 셸을 만드는 프로젝트입니다. 이 프로젝트를 구축함으로써 프로세스와 파일 디스크립터에 대한 더 깊은 통찰력을 얻을 수 있습니다.
### Dependencies | 종속성
Before building and running MiniShell, you need to install the GNU Readline library, which is used for handling input. Here’s how you can install it on various systems:

MiniShell을 빌드하고 실행하기 전에 입력을 처리하는 데 사용되는 GNU Readline 라이브러리를 설치해야 합니다. 다양한 시스템에 설치하는 방법은 다음과 같습니다:
#### On Ubuntu/Debian
Run the following command in your terminal:
```bash
sudo apt-get install libreadline-dev
```
#### On Fedora
Run the following command in your terminal:
```bash
sudo dnf install readline-devel
```
#### On macOS
Using Homebrew, run the following command in your terminal:
```bash
brew install readline
```
- Make sure to link your compiler to the correct headers and libraries if your system has multiple versions of Readline installed or if Homebrew installs them in a non-standard location.
- 시스템에 여러 버전의 Readline이 설치되어 있거나 홈브루가 비표준 위치에 설치하는 경우 컴파일러를 올바른 헤더와 라이브러리에 연결해야 합니다.
- **`You must replace the makeFile with the path to your installed Readline to run it.`**
- **`makeFile을 설치된 Readline의 경로로 바꿔야 실행할 수 있습니다.`**
- The current Makefile is written for Macos installed with brew.
- 현재 Makefile은 brew로 설치된 MacOS를 기준으로 작성되었습니다.
### Building the Project | 프로젝트 빌드 방법
To build the project, run:
```bash
make
```

This will compile the source files and link the necessary libraries to create the `minishell` executable.

그러면 소스 파일을 컴파일하고 필요한 라이브러리를 연결하여 `minishell` 실행 파일을 생성합니다.
### Running MiniShell | 미니쉘 실행 방법
To run MiniShell, simply execute:
미니셸을 실행하려면 아래 명령을 실행하면 됩니다:
```bash
./minishell
```


## Mandatory part
 |Program name | minishell|
 |---|---|
 |Turn in files | Makefile, *.h, *.c|
|Makefile | NAME, all, clean, fclean, re|
|Arguments ||
|External functs.| readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs|
|Libft authorized |Yes|
|Description| Write a shell|

Your shell should:
- Display a prompt when waiting for a new command. 
- `명령을 기다릴 때 프롬프트를 표시합니다.`
- Have a working history.
- `히스토리를 가지고 있습니다.`
- Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path).
- `올바른 실행 파일을 검색하고 실행합니다(PATH 변수를 기반으로 하거나 상대 경로 또는 절대 경로를 사용합니다).`
- Avoid using more than one global variable to indicate a received signal. Consider
the implications: this approach ensures that your signal handler will not access your
main data structures. 
- `한 번에 하나 이상의 전역 변수를 사용하지 않고 수신된 신호를 나타내는 전역 변수를 사용하지 않습니다. 이 접근 방식은 시그널 핸들러가 가 주 데이터 구조에 액세스하지 않도록 보장합니다.`
- Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon)
- `명령어에 필요하지 않은 따옴표나 특수 문자를 해석하지 않습니다.`
- Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- `'(작은따옴표)를 처리하여 셸이 따옴표로 묶인 시퀀스의 메타문자를 해석하지 못하도록 해야 합니다.`
- Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
- `"(큰따옴표)를 처리하면 셸이 $(달러 기호)를 제외한 인용된 시퀀스의 메타문자를 해석하지 못하도록 해야 합니다.`
- Implement **redirections**: 
- `리다이렉션 구현 요구사항`
  - '<' should redirect input. 
  - `'<'는 입력을 리다이렉션해야 합니다.`
  - '>' should redirect output. 
  - `'>'는 출력을 리다이렉션해야 합니다.`
  - '<<' should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history! 
  - `(<<는 구분자를 지정하고, 그런 다음 구분자가 포함된 줄이 나타날 때까지 입력을 읽어야 합니다. 그러나 히스토리를 업데이트할 필요는 없습니다!)`
  - '>>' should redirect output in append mode. 
  - `('>>'는 추가 모드로 출력을 리다이렉션해야 합니다.)`
- Implement **pipes** (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe. 
- `파이프(| 문자)를 구현합니다. 파이프라인의 각 명령의 출력은 파이프를 통해 다음 명령의 입력에 연결됩니다.`
- Handle **environment variables** ($ followed by a sequence of characters) which should expand to their values. 
- `환경 변수($ 뒤에 문자 시퀀스)를 처리하여 해당 값을 확장해야 합니다.`
- Handle $? which should expand to the exit status of the most recently executed foreground pipeline. 
- `최근에 실행된 포그라운드 파이프라인의 종료 상태로 확장해야 하는 $?를 처리합니다.`
- Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash. 
- `ctrl-C, ctrl-D 및 ctrl-\를 bash와 같이 동작하도록 처리합니다.`
- In interactive mode: 
- `대화형 모드에서:`
  - ctrl-C displays a new prompt on a new line. 
  - `ctrl-C는 새 줄에 새 프롬프트를 표시합니다.`
  - ctrl-D exits the shell. 
  - `ctrl-D는 셸을 종료합니다.`
  - ctrl-\ does nothing. 
  - `ctrl-\는 아무것도 하지 않습니다.`
- Your shell must implement the following builtins: 
- `셸은 다음 내장 명령을 구현해야 합니다.`
  - echo with option -n 
  - `옵션 -n을 사용한 echo`
  - cd with only a relative or absolute path 
  - `상대 경로 또는 절대 경로만 있는 cd`
  - pwd with no options 
  - `옵션이 없는 pwd`
  - export with no options 
  - `옵션이 없는 export`
  - unset with no options 
  - `옵션이 없는 unset`
  - env with no options or arguments 
  - `옵션이나 인수가 없는 env`
  - exit with no options 
  - `옵션이 없는 exit`

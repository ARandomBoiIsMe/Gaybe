@ECHO OFF
SETLOCAL EnableDelayedExpansion

SET compiler=gcc

REM Get all C files
REM ---------------

SET c_files=
FOR %%f in (src\*.c) DO (
    SET c_files=!c_files! %%f
)

FOR %%f in (src\utils\*.c) DO (
    SET c_files=!c_files! %%f
)
REM ---------------

SET output=-o gaybe.exe

SET build_command=%compiler% %c_files% %output%

ECHO Building gaybe.exe...
%build_command%
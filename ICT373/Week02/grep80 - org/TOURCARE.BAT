@echo off
if "%1" == "/?"      goto 00_Usage
if "%2" == ""        goto 00_Usage
if "%3" == ""        goto 10_Start
if "%3" == "verbose" goto 10_Start
:00_Usage
echo usage:    TOURCARE  var1  var2
echo where "var1" is the name of the envionment variable to be set to a
echo displayable caret and "var2" is the name of the environment variable
echo to be set to a caret that can be included in other SET commands.
echo.
echo Special case: "TOURCARE C1 C2 verbose" displays diagnostic dumps.
echo (C1, C2, and verbose are case sensitive.)
goto 99_Done

###############################################################################

TOURCARE.BAT - set named environment variables to a caret (^)

Note: %G% is expected to contain the name of the GREP executable.

2005-04-11  author: Stan Brown, Oak Road Systems
            (After an idea from Matthew Miner.)

                 Copyright 2005   Stan Brown, Oak Road Systems
                           http://oakroadsystems.com
###############################################################################
:10_Start

rem Set ERRORLEVEL to 2.
%G% /? >nul:

rem Now if ^ is special, then the following line is just an ugly ECHO command
rem and ERRORLEVEL will stay at 2. But if ^ is non-special, then the following
rem line is a pipe to GREP and ERRORLEVEL will be set to 1.
echo ^|%G% /z1 .>nul:
if errorlevel 2 goto 20_Special
set %1=^
set %2=^
goto 98_Finish

:20_Special
rem If ^ is special, we need 8 of them in the SET command! It seems that the
rem number should be 16, but experiment shows that 8 actually works: when the
rem envvar is included on the right-hand side of another SET command, and that
rem second envvar is executed, both XP's command prompt and 4NT see the desired
rem single caret.
rem
rem Note the required blank lines after the SET commands. 4NT seems to get 
rem confused if a non-blank line follows the SET %1 line.
set %1=^^^^

set %2=^^^^^^^^


:98_Finish
rem This is different from 99_Done to allow for diagnostic output.
if not "%3" == "verbose" goto 99_Done
if not "%1" == "C1" goto 99_Done
if not "%2" == "C2" goto 99_Done
echo C1 is %C1% and C2 is %C2%
set A=The value of variable C1 is "%C1%"
echo With quotes in the SET command,    %A%
set A=The value of variable C1 is %C1%
echo Without quotes in the SET command, %A%
echo Now, using %%C2%% to construct a GREP command--
if "%G%" == "" set G=grep32
set A=%G% /z %C2%echo TOURCARE.BAT
echo %A%
%A%
echo Concatenating two occurrences of %%C%% we get (%C%%C%)
set A

:99_Done

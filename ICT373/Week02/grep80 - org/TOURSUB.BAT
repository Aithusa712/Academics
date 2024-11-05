@echo off
goto 00_Start
###############################################################################

TOURSUB.BAT - subprogram for TOUR.BAT

Environment variables expected to be set:
    G - GREP program (without .exe)
    X - options to be used
    Y - options to be used in a second (piped) command

Usage:
        call TOURSUB short|long
or:
        call TOURSUB short|long filename

parameters:
    short or long tells whether command output is short (no PAUSE required
                  before, no MORE required after)
    filename, if present, receives output instead of the screen

2001-11-25  author: Stan Brown, Oak Road Systems
2002-01-21  Add the possibility of piping to a second command.

               Copyright 2001-2005   Stan Brown, Oak Road Systems
                           http://oakroadsystems.com
###############################################################################
:00_Start

if "%2" == "" goto 20_Interactive
echo. >>%2
echo ================================================================== >>%2
if "%Y%" == "" goto 15_Auto_Nonpiped
    echo executing: %G% /Z%REG% %X% ! %G% /Z%REG% %Y% >>%2
    echo ================================================================== >>%2
    %G% /Z%REG% %X% | %G% /Z%REG% %Y% >>%2
    goto 19_Auto
:15_Auto_Nonpiped
    echo %G% /Z%REG% %X% >>%2
    echo ================================================================== >>%2
    %G% /Z%REG% %X% >>%2
:19_Auto
echo. >>%2
echo. >>%2
goto 99_Exit

:20_Interactive
if "%1" == "short" goto 30_InteractiveShort
echo.
if "%Y%" == "" goto 25_Interact_Nonpiped
    echo (You would use the vertical bar where you see the "!" in this example.)
    echo.
    echo ==================================================================
    echo about to execute: %G% /Z%REG% %X% ! %G% /Z%REG% %Y%
    pause
    %G% /Z%REG% %X% |  %G% /Z%REG% %Y% | more
    echo ==================================================================
    goto 29_Interact
:25_Interact_Nonpiped
    echo ==================================================================
    echo about to execute: %G% /Z%REG% %X%
    pause
    %G% /Z%REG% %X% | more
    echo ==================================================================
:29_Interact
pause
goto 99_Exit

:30_InteractiveShort
echo.
if "%Y%" == "" goto 35_Short_Nonpiped
    echo ==================================================================
    echo (You would use the vertical bar where you see the "!" in this example.)
    echo.
    echo executing: %G% /Z%REG% %X% ! %G% /Z%REG% %Y%
    echo.
    %G% /Z%REG% %X% | %G% /Z%REG% %Y%
    echo ==================================================================
    goto 39_Short
:35_Short_Nonpiped
    echo ==================================================================
    echo executing: %G% /Z%REG% %X%
    echo.
    %G% /Z%REG% %X%
    echo ==================================================================
:39_Short
echo.

:99_Exit
rem :: vim: ic tw=0 comments=n\:\:\:,n\:echo,n\:rem

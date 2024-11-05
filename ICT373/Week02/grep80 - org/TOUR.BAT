@echo off
goto 00_Start
###############################################################################

TOUR.BAT - demonstrate GREP software with the supplied sample files

Usage:    TOUR  [filename]
(With a filename, the tour runs non-interactively and writes its output to that
file. This is part of the actual regression tests for GREP.)

The following environment variables get overwritten:
    B32 -- "yes" or "no"
           records whether the 32-bit program is being used in the tour
    G   -- name of the program, e.g. "grep16"
    X   -- used for scratch work

2001-12-22  author: Stan Brown, Oak Road Systems
2002-01-01  Add /K option demo.
2002-01-21  Add demos for filename globbing and exclusion.
            Change "demo" to "tour" to avoid the misperception that this
            version of GREP is "just a demo".
2002-03-27  Add searching by word.
2004-07-04  Changed names for doccumentation files.
2004-10-18  Add /J2 and /J3.
2004-12-09  Add /G2; move binary searching nearer the front and revise the
            wording for the new output format.
2004-12-30  Change environment check so command line doesn't exceed 128 chars.
            Replace CHOICE calls with TOURKEY since CHOICE isn't in Windows XP.
2005-01-17  Simplify the regex in the 32-bit examples of paragraph mode.
2005-04-09  Add the /O option (output formats).
2005-04-11  (1) Clean up the different treatment of ^ between NT/XP/2000/4NT
            and DOS/3.x/95/98/ME/4DOS.
            (2) Add /o2 to the locale demos for more compact output.
            (3) Change GREP-by-word to GREP101: GREPMAN has too many hits.
            (4) Add missing CLS commands after some subsections.
            (5) Add "Section n (of 8)" to each section.
            (6) Reformat text to a 75-character line from 80.
2005-05-05  Display a short ID if the user types "TOUR /?".

               Copyright 2001-2005   Stan Brown, Oak Road Systems
                           http://oakroadsystems.com
###############################################################################
:00_Start
if not "%1" == "/?" goto 01_CheckEnv
echo.
echo This is the interactive tour of GREP.
echo To run it, type    TOUR    
echo.
goto 99_Exit

:01_CheckEnv
rem Check whether sufficient environment space is available.
set G=0123456789012345678901234567890123456789
set X=0123456789012345678901234567890123456789
set G=
if "%X%" == "0123456789012345678901234567890123456789" goto 02_EnvOK
echo.
echo This tour needs about 80 bytes of free environment space, but less than
echo that is available. Try running it in a secondary shell and specifying
echo environment space, like this:
echo           %%comspec%% /e:8192 /c %0
echo The figure of 8192 is just an example. Use a large enough number, which
echo depends on how much environment space you are already using. If you have a
echo SHELL statement in C:\CONFIG.SYS use that number plus 80 or so; otherwise
echo try /e:1024.
echo.
goto 99_Exit

:02_EnvOK
set X=
if "%2" == "" goto 03_ParamsOK
echo.
echo You invoked this batch file with two or more parameters. In normal use it
echo takes no parameters; the only optional parameter is a file name for output.
echo.
goto 99_Exit
:03_ParamsOK

if not "%1" == "" goto 04_32or16
cls
echo Copyright 2001-2005 Stan Brown, Oak Road System   http://oakroadsystems.com
echo.
echo                       +============================+
echo                       !  Tour of GREP Release 8.0  !
echo                       +============================+
echo.
echo To run this tour successfully, your current directory should be the
echo directory where you unzipped both GREP download files. For best results,
echo all the unzipped files should be in that directory, and no other files.
echo.
echo The DOS program MORE.COM needs to be somewhere in your PATH. If you have a
echo normal DOS or WINDOWS installation, the MORE program is already present in
echo the right place.
echo.
echo The tour can be run with 16-bit or 32-bit GREP. Some features are
echo available in 32-bit GREP but not 16-bit GREP. However, 32-bit GREP
echo requires a command prompt under a version of Windows 95/98/ME/NT/2000/XP
echo while 16-bit GREP will run in any DOS session.
echo.
:04_32or16
set B32=no
tourkey /c13q /n "Do you prefer the 16-bit or 32-bit tour? (1/3/Quit) "
if errorlevel 3 goto 98_ExitPrep
if errorlevel 2 set B32=yes
rem Now check that the executable program is actually available.
set G=grep16
if "%B32%" == "yes" set G=grep32
if exist %G%.exe goto 10_ExeFound
if not exist grep.exe goto 09_ExeNonexistent
echo.
echo %G%.exe doesn't exist in this directory, but grep.exe does.
tourkey /cny /n "Have you renamed %Q%.exe as grep.exe? (Y/N) "
if not errorlevel 2 goto 09_ExeNonexistent
set G=grep
goto 10_ExeFound
:09_ExeNonexistent
echo.
echo Please run this batch file from the same directory where the '%G%.exe'
echo program exists.
echo.
goto 99_Exit
:10_ExeFound
call tourcare C1 C2
if "%1" == "" goto 90_Welcome
echo Output of "%0 %1" >%1
echo ====================================================================== >>%1
echo.>>%1
echo. | date >>%1
echo.>>%1
%G% -z -d- zzzzz <TOUR.BAT >>%1
echo.>>%1
echo.>>%1
goto 95_AskReg
:90_Welcome
cls
echo Welcome to this tour of the GREP shareware program. At present this
echo tour focuses on recently added features. Future versions of the tour
echo may be more comprehensive.
echo.
echo NOTE: Every GREP command in this tour uses the /Z option. That's always a
rem (because TOURSUB.BAT inserts it)
echo good idea in a batch file, so that any setting of the environment variable
echo is disregarded and the options in effect are only those on the command
echo line.
echo.
echo.
echo Registered users can use the /Q1 option to suppress the program logo. This
echo is especially handy in reducing the volume of output from batch files.
set REG=
:95_AskReg
tourkey /n /cnyq "Are you running a registered copy? (Y/N/Quit) "
if errorlevel 3 goto 98_ExitPrep
if errorlevel 2 set REG=/Q1
echo.
:99_BeginTour
rem Prevent unwanted piping in TOURSUB.BAT
set Y=
if "%1" == "" cls

rem ============================================================================

if not "%1" == "" goto 810_Outfmt_Zero
echo.
echo Section 1 (of 8)
echo.
echo GREP 8.0 added the ability to specify output formats independently of
echo input formats, with the /O (letter O) option. Non-printing characters
echo can now be handled in a more useful way.
echo.
tourkey /cynq /n "Would you like to see the output formats? (Y/N/Quit) "
if errorlevel 3 goto 98_ExitPrep
if errorlevel 2 goto 899_Outfmt_Done
cls
echo.
echo When searching a text file that contains lots of control characters, you
echo may want to display the binary codes and text side by side. This is also
echo the default format for output of binary files.
echo.
echo Here's an illustration of binary output with the /O0 option, letter O
echo followed by digit zero. (Actually the /O0 option is redundant since that's
echo GREP's default for binary files. But we'll show it here for clarity.)
echo.
echo The supplied TEST255 file contains each character from 0 to 255 with its
echo numeric value. With the regex shown below we'll display characters 0 to 4
echo and 10 to 14. We'll read the file as 21-byte records (/R2 /W21) and
echo display record numbers (/N). Every character in the file is shown by its
echo two-digit hex code in the left column. In the right column, printable
echo characters are shown as themselves and non-printable characters are shown
echo as dots.
echo.
:810_Outfmt_Zero
set X=\s[1\s][0-4]) test255 /R2 /w21 /N /O0
call toursub long %1
if not "%1" == "" goto 820_Outfmt_One
echo.
echo Next, display the same output in "naive" text format (/O1 option, letter O
echo figure 1), simply dumping the characters to screen. This is often easier
echo to read, but special characters like NUL and Control-Z mess up the
echo display. (Notice that the first hit below will be truncated and two others
echo badly formatted. As you'll see in a moment, we can do better.)
echo.
:820_Outfmt_One
set X=\s[1\s][0-4]) test255 /R2 /w21 /N /O1
call toursub long %1
if not "%1" == "" goto 830_Outfmt_Two
echo.
echo Now let's try the same thing, but displayed using GREP's "safety filter"
echo (the /O2 option, letter O figure 2). This is usually the best choice for
echo text files that have a few control characters, and for binary files that
echo are mostly text characters.
echo.
echo You'll notice that character 1-4 and 10-14 are displayed as Control-A and
echo so on, non-printable character 0 is displayed as hex 00 in angle brackets,
echo and the printable characters are displayed normally. (In 16-bit GREP
echo characters 32-126 are printable. In 32-bit GREP you can change the locale
echo with the /M option, which changes the printable characters.)
echo.
echo And the missing hit has returned. Now we can see that the problem
echo was the leading zero byte.
echo.
:830_Outfmt_Two
set X=\s[1\s][0-4]) test255 /R2 /w21 /N /O2
call toursub long %1
if not "%1" == "" goto 840_Outfmt_Three
echo.
echo Finally we display the same output with GREP's "control filter" (/O3
echo option, letter O figure 3). This is similar to the "safety filter" shown
echo above, but it also breaks lines after carriage return and line feed
echo characters, which sometimes makes the formatting easier to see.
echo.
:840_Outfmt_Three
set X=\s[1\s][0-4]) test255 /R2 /w21 /N /O3
call toursub long %1
if not "%1" == "" goto 899_Outfmt_Done
echo.
echo There are general guidelines, but there's no hard-and-fast rule for which
echo output format is best; it depends on what the file looks like. In the
echo above examples, for instance, /O2 and /O0 are the only reasonable choices,
echo and /O2 is probably better because it's more compact.
echo.
echo If you don't specify an output format, GREP guesses based on the type of
echo the input. Binary files are displayed by default in the mixed hex and
echo character format; text files are displayed in "safety filter" except that
echo text files read as paragraphs (/G2 or higher) are displayed as naive text.
echo.
echo.
echo This concludes the tour of output formats.
echo.
:899_Outfmt_Done
if "%1" == "" cls

rem ============================================================================

set X=Text[\s\t\012\014]+File
if "%B32%" == "yes" set X=Text\s+File
if not "%1" == "" goto 710_GraphOne
echo.
echo Section 2 (of 8)
echo.
echo GREP 7.5 added the ability to search text files by paragraph or by line,
echo controlled by the /G option. Now you can find matches for a regex even if
echo they start on one line and end on a later line.
echo.
tourkey /cynq /n "Would you like to see paragraph searching? (Y/N/Quit) "
if errorlevel 3 goto 98_ExitPrep
if errorlevel 2 goto 799_GraphDone
cls
echo We'll illustrate searching for "Text File" in the Quick Start, grep101.htm.
echo.
if "%B32%" == "yes" goto 703_GraphExtRegex
echo The regex %X% allows for one or more whitespace
echo characters between the two words. ("More about Paragraph Modes" in the
echo manual, under the /G option, explains the rationale for this regex. In
echo GREP32, you could use an extended regex and replace the above with
echo Text\s+File by specifying the /E2 option.)
goto 709_GraphReady
:703_GraphExtRegex
echo The regex %X% allows for one or more whitespace
echo characters between the two words. ("More about Paragraph Modes" in the
echo manual, under the /G option, explains the rationale for this regex.)
:709_GraphReady
echo.
echo First we do a traditional search by line.
:710_GraphOne
set X=%X% grep101.htm /N
if "%B32" == "yes" set X=/E2 %X%
call toursub short %1
if not "%1" == "" goto 720_GraphTwo
echo.
echo GREP found only one occurrence, and it's displayed with its line number
echo (because of the /N option).
echo.
pause
cls
echo Now let's add the /G2 option to search by paragraphs. (A paragraph is one
echo or more non-blank lines. Paragraphs are separated by lines that are
echo entirely empty or contain only whitespace characters.)
:720_GraphTwo
set X=%X% /G2
call toursub long %1
if not "%1" == "" goto 798_GraphCleanup
echo.
echo As you see, GREP now finds two matches, including one where "Text" is at
echo the end of one line and "Files" is at the start of the next line. Note that
echo now the /N option gives you paragraph numbers beside the line numbers.
echo.
pause
echo.
echo Even if you only care about matches that occur within a single line, the
echo /G2 option is a great way to get context of your matches. (The older /P
echo option also gives context, but that's a fixed number of lines before and
echo after each match.)
echo.
:798_GraphCleanup
if "%1" == "" echo.
if "%1" == "" echo This concludes the tour of paragraph searching.
if "%1" == "" echo.
:799_GraphDone
if "%1" == "" cls

rem ============================================================================

if not "%1" == "" goto 201_BinaryOne
echo.
echo Section 3 (of 8)
echo.
echo GREP can handle both text and binary files, and you specify file format
echo with the /R option. (Registered users can specify /R-1 or /R-2 to tell GREP
echo to sense the file format automatically.)
echo.
echo Release 7.5 changed to a tabular format for binary output: a hex dump and
echo a text display side by side.
echo.
tourkey /cynq /n "Would you like to see binary file searching? (Y/N/Quit) "
if errorlevel 3 goto 98_ExitPrep
if errorlevel 2 goto 299_BinaryDone
cls
echo Suppose you want to find the word "warning" in the GREP executable, just
echo to see the warning messages. Use the regular expression [Ww]arning to get
echo both "warning" and "Warning". With a search in text mode, the special
echo characters in %G%.exe cause GREP to miss some or all occurrences:
:201_BinaryOne
set X=[Ww]arning %G%.exe /BN
call toursub long %1
if not "%1" == "" goto 202_BinaryTwo
echo.
echo As you see, GREP found enormous "lines" in that executable file, because
echo it's not formatted in real lines.
echo.
echo But in binary mode, GREP will find all occurrences of the sought-after
echo string in a buffer whose length you specify. Use /R3, not R2, because
echo %G%.exe is a free-format binary file. And use /W40 to limit the buffers to
echo 40 characters. (The sought-after string is 7 characters long, so /W40
echo meets the requirement for /R3 that the buffer should be at least double
echo the string size.)
:202_BinaryTwo
set X=%X% /R3 /W40
call toursub long %1
if not "%1" == "" goto 203_BinaryThree
echo.
echo Note that the text characters are shown normally, and the binary
echo characters are shown as hexadecimal values.
echo.
echo (Though this test does find all occurrences of "warning" and "Warning" in
echo the executable program, it obviously doesn't find all of GREP's warning
echo messages. The reason is that the word "warning" is not coded with each
echo message in the program, but is inserted at run time by a subroutine. All
echo warnings are listed in the reference manual.)
echo.
echo The registered version of GREP can sense the file type.
if "%REG%" == "" echo That part of the tour will be skipped, since you said your copy isn't
if "%REG%" == "" echo registered.
if "%REG%" == "" goto 298_BinaryCleanup
cls
echo The /R-1 option tells GREP to look at each file and figure out whether it's
echo text or binary. When you show filename headers -- i.e., when you don't use
echo the /H or /L or /U option -- GREP will tell you the type of each file.
echo.
echo Notice how the /W option lets you specify different widths for text and
echo binary files. I recommend you allow a full line width for text files, but
echo keep the buffer fairly small for binary files.
echo.
:203_BinaryThree
set X=[Ww]arning /R-1 /W255,40 /N %G%.exe grep101.htm
call toursub long %1
:298_BinaryCleanup
if "%1" == "" echo.
if "%1" == "" echo This concludes the tour of binary file features.
if "%1" == "" echo.
:299_BinaryDone
if "%1" == "" cls

rem ============================================================================

if not "%1" == "" goto 601_AllInstances
echo.
echo Section 4 (of 8)
echo.
echo Sometimes you want to find all matches for a regex, even multiple ones on a
echo line. This is especially useful in a binary file, where you may want to see
echo the matches without the rest of the buffer (which probably contains many
echo non-printable characters). Starting with release 7.4, you can do this with
echo the /J2 or /J3 option.
echo.
tourkey /cynq /n "Would you like an example of showing all matches? (Y/N/Quit) "
if errorlevel 3 goto 98_ExitPrep
if errorlevel 2 goto 699_AllInstancesDone
cls
echo To illustrate, let's find all strings of printable characters in the
echo program that contain the word "warning". An executable program is
echo free-format binary, which requires the /R3 option. It would also be nice
echo to know where the strings occur (/N option).
:601_AllInstances
set X="[ -~]*warning[ -~]*" %G%.EXE /R3 /J2 /N
echo.
if "%B32%" == "yes" goto 632_AllInstances32Bit
set X=%X% /W160
if not "%1" == "" goto 640_AllInstancesExecute
echo To avoid problems with a match that crosses a buffer boundary, make the
echo buffer width at least double the largest expected match. Since a user
echo alert can't be longer than the 80-column screen width, set the buffer to
echo 80 times 2 = 160.
goto 640_AllInstancesExecute
:632_AllInstances32Bit
set X=%X% /W200000
if not "%1" == "" goto 640_AllInstancesExecute
echo In GREP32, Windows virtual memory is available to the program. That lets us
echo set the buffer size larger than the program, avoiding worries about matches
echo that cross buffer boundaries.
:640_AllInstancesExecute
if not "%1" == "" goto 641_AllInstancesExecute
echo.
echo Notice that the regex begins and ends with a string of any length. This
echo scans slower than most, because GREP must examine every printable
echo character in the file and look ahead to see if it starts a string of
echo printable characters that contains "warning" somewhere down the line.
:641_AllInstancesExecute
call toursub long %1
if not "%1" == "" goto 642_AllInstancesExecute
echo This would have been a good way to list all warnings contained in the
echo program. Unfortunately, the string "warning" is in one place in the code,
echo and the actual warnings are scattered throughout.
echo.
:642_AllInstancesExecute
if "%B32%" == "yes" goto 652_AllInstancesExt32
if not "%1" == "" goto 699_AllInstancesDone
echo The 32-bit version of this tour illustrates finding all printable strings
echo of at least a certain length, but this uses extended regexes, which are
echo not supported in GREP16.
echo.
goto 699_AllInstancesDone
:652_AllInstancesExt32
if not "%1" == "" goto 653_AllInstancesExt32
echo Using extended regexes, it might be interesting to list all printable
echo strings in the program at least 40 characters long. This uses the regex
echo features described in "Character Class Names" and "{ } for Repetition" in
echo the manual. Since there are many such strings, we'll use the /K option to
echo limit output to the first 35.
:653_AllInstancesExt32
set X=[[:print:]]{40,} /E2 /R3 /J2 /N /K35 %G%.EXE
call toursub long %1
:699_AllInstancesDone
if "%1" == "" cls

rem ============================================================================

if not "%1" == "" goto 501_WordonlyOne
echo.
echo Section 5 (of 8)
echo.
echo A frequent request is for searching by word. For instance, you want to find
echo all instances of "plain" but not "explain", "plainsong", and so on. This
echo part of the tour shows you how to do it in GREP, and illustrates the new
echo feature of GREP32 release 7.1 that makes it much easier.
echo.
tourkey /cynq /n "Would you like to see grepping by word? (Y/N/Quit) "
if errorlevel 3 goto 98_ExitPrep
if errorlevel 2 goto 599_WordonlyDone
cls
echo First look at the occurrences of "plain" in GREP101.HTM:
:501_WordonlyOne
set X=plain grep101.htm
call toursub short %1
if not "%1" == "" goto 502_WordonlyTwo
echo.
echo As you see, the word "plain" occurs alone and as part of larger words.
if "%B32" == "yes" echo (Make note of the pseudo-word "plain55", which will be important later.)
echo To find it alone, there are two main methods. The first method is very
echo easy but will work only with 32-bit GREP: use the /E4 option.
if "%B32%" == "no" echo That part of the tour will be skipped because you're running
if "%B32%" == "no" echo 16-bit GREP.
if "%B32%" == "no" pause
if "%B32%" == "no" cls
:502_WordonlyTwo
if "%B32%" == "no" goto 520_Wordonly_FourRegex
set X=%X% /E4
call toursub long %1
if not "%1" == "" goto 503_WordonlyThree
echo.
echo Words like "explain" and "plains" are no longer found. You might be
echo surprised that "plain55" is no longer found. The reason is that not only
echo letters but digits (and the underscore) are considered "word" characters by
echo default. (This matches behavior of the UNIX grep -w option.) You can
echo control this with the /M option. Full details are in the reference manual,
echo but here's an example: use /Mfr,alpha to say that a "word" is any sequence
echo of letters. Then "plain55" will not be a "word" any more:
:503_WordonlyThree
set X=%X% /Mfr,alpha
call toursub long %1
if not "%1" == "" goto 521_WordonlyFour
echo.
echo Now "plain55" is treated as the word "plain" followed by the non-"word"
echo characters "55", so it is reported. You can control the meaning of "word"
echo in 32-bit GREP by using the /M option in this way.
pause
cls
:520_Wordonly_FourRegex
if not "%1" == "" goto 521_WordonlyFour
echo But what if you are running GREP16? In this case you can't use the /E4
echo option, but you can still get the job done. (The following technique works
echo in any current version of GREP.)
echo.
echo Think it out logically: If a word is a sequence of letters, then looking
echo for "plain" as a word means looking for "plain" preceded and followed by a
echo non-letter. In regexes, the character class [%C1%a-zA-Z] represents the non-
echo letters, so our regex for "plain" as a word might be
echo                             [%C1%a-zA-Z]plain[%C1%a-zA-Z]
echo But we have to think a little more. Suppose "plain" is at the start of a
echo line? Then that regex would not make a match, because it calls for a non-
echo letter character before the "p" of "plain". So there is a special case,
echo %C1%plain[%C1%a-zA-Z]. In the same way, "plain" might occur at the end of a
echo line, so we need to search for [%C1%a-zA-Z]plain$. Finally, "plain" might
echo occur alone on a line, so we also need to search for %C1%plain$. These four
echo basic regexes together will find all occurrences of "plain" as a word.
echo.
pause
echo.
echo Fortunately, GREP can search for multiple regexes in one pass. So we hand
echo these four regexes to GREP via the /F option:
:521_WordonlyFour
if "%TEMP%" == "" set TEMP=c:
set X=/Z%REG% /F- grep101.htm
if "%1" == "" goto 522_WordonlyFour_Console
echo. >>%1
type TOURREG1 >>%1
echo ================================================================== >>%1
echo executing: %G% %X% >>%1
echo ================================================================== >>%1
%G% %X% <TOURREG1 >>%1
goto 598_WordonlyCleanup
:522_WordonlyFour_Console
type TOURREG1
echo ==================================================================
echo about to execute: %G% %X%
%G% %X% <TOURREG1
echo ==================================================================
:598_WordonlyCleanup
if "%1" == "" echo.
if "%1" == "" echo This concludes the tour of grepping by word.
if "%1" == "" echo.
if "%1" == "" pause
:599_WordonlyDone
if "%1" == "" cls

rem ============================================================================

if not "%1" == "" goto 401_GlobExclude
echo.
echo Section 6 (of 8)
echo.
echo Filename globbing, input file lists, and exclusion lists were all added in
echo GREP release 7.0.
echo.
tourkey /cynq /n "Would you like to see these features? (Y/N/Quit) "
if errorlevel 3 goto 98_ExitPrep
if errorlevel 2 goto 499_GlobDone
cls
echo You can tell GREP to exclude files from consideration. For instance, let's
echo search for "Copyright" and "copyright" in every file, _except_ EXE files and
echo the license:
:401_GlobExclude
set X=[Cc]opyright /c /x*exe /xlice* *
call toursub long %1
if not "%1" == "" goto 402_GlobSimple
cls
echo Filename "globbing" includes DOS wildcarding with * and ?, but is more
echo flexible. For example, you can select only HTML files that begin with GREPM and
echo GREPH, using the construct GREP[MH]*.HTM, like this:
:402_GlobSimple
set X=Copyright grep[mh]*.htm
call toursub short %1
if not "%1" == "" goto 403_GlobMixed
echo GREP16 users, please note a change in the meaning of "*" between releases
echo 6.9 and 7.0. GREP16 now expands wildcards exactly like GREP32. So "ABC*"
echo means all files starting with ABC, including files with extensions like
echo ABCD.XYZ. If you want files without extensions, "ABCD*." will get them.
echo "ABC*.*" still means all files beginning with ABC, whether or not they
echo have an extension.
pause
cls
echo.
echo You've just seen selected GREPMAN.HTM and GREPHIST.HTM with the filespec
echo GREP[MH]*.HTM. Now you'll see "all HTM files except GREPHIST.HTM and
echo PCRE.HTM". The /X option lets you exclude files. Unlike other options, /X
echo can be used multiple times for multiple exclusions. It doesn't matter
echo where they occur on the command line; all /X exclusions will be checked
echo against all input filespecs.
:403_GlobMixed
set X=Copyright *htm /Xgrephist* /Xpcre*
call toursub short %1
if not "%1" == "" goto 404_GlobFilelist
pause
cls
echo Flexible though globbing can be, sometimes you need to specify a more
echo complicated selection of files. For this, you can use the /@ option to
echo specify a list of input files. (Each filespec in the list may contain
echo wildcards.)
echo.
echo /@file takes the list from a named file; /@- takes it from standard input.
echo This opens up the posibility to have some other program generate a list of
echo input files for GREP, which can then be passed to GREP via piping. For
echo example, to find the files that contain both the string "Copyright" and
echo the string "reserved", not necessarily on the same line, construct a
echo command this way:
echo.
echo    - Run GREP once, with the /L option, to get a list of files that
echo      contain the string "Copyright".
echo    - Run GREP a second time, using only those files as input, to see which
echo      of them contain the string "reserved".
echo.
pause
cls
echo In a production run, you wouldn't do those two steps as separate commands.
echo Instead you'd pipe the output of the first GREP (the list of files
echo containing "Copyright") to the second GREP. But to show the mechanism,
echo let's look at the output of just the first command:
:404_GlobFilelist
set X=Copyright /L *
call toursub short %1
if not "%1" == "" goto 404A_GlobPipe
pause
cls
echo You saw the first GREP command produce the list of files that contain
echo "Copyright". Now to do a production run, piping that output directly into
echo the second GREP. The /@- on the second GREP says to take a list of input
echo files from standard input, which in this case is piped from the first GREP
echo command.
echo.
echo Here's the command, with the results. These are the files that contain
echo both strings, but not necessarily on the same line. As you'll see, it's a
echo shorter list.
:404A_GlobPipe
set Y=reserved /@- /L
call toursub short %1
set Y=
if not "%1" == "" goto 499_GlobDone
pause
echo.
echo This concludes the tour of the /X /@ and filename globbing.
echo.
:499_GlobDone
if "%1" == "" cls

rem ============================================================================

if not "%1" == "" goto 301_KunOne
echo.
echo Section 7 (of 8)
echo.
echo The /K option -- report only so many hits in each file -- was added in GREP
echo release 7.0.
echo.
tourkey /cynq /n "Would you like to see limiting hits with the /K option? (Y/N/Quit) "
if errorlevel 3 goto 98_ExitPrep
if errorlevel 2 goto 399_KunDone
cls
echo Let's find the word "warning" in the GREP manuals. Use the regex
echo [Ww]arning to get both "warning" and "Warning". (The /N option displays
echo line numbers.)
:301_KunOne
set X=[Ww]arning grep*.htm /N
call toursub long %1
if not "%1" == "" goto 302_KunTwo
echo.
echo As you see, the output is quite lengthy. You can limit the output to just
echo the first few occurrences per file, for example 3. The /K3 option gives
echo only the first 3 hits from each file.
:302_KunTwo
set X=%X% /K3
call toursub long %1
if not "%1" == "" goto 303_KunThree
cls
echo When limiting hits with the /K option, you can still use the /P option to
echo display context lines. For instance, you can use /P0,2 in case a warning
echo message is continued on the next line or two:
:303_KunThree
set X=%X% /P0,2
call toursub long %1
:398_KunCleanup
if "%1" == "" echo.
if "%1" == "" echo This concludes the tour of the /K option (display a few hits per file).
if "%1" == "" echo.
:399_KunDone
if "%1" == "" cls

rem ============================================================================

if "%1" == "" echo.
if "%1" == "" echo Section 8 (of 8)
if "%1" == "" echo.
if "%1" == "" echo Locale support (/M option) was added to GREP32 release 6.9.
if "%B32%" == "yes" goto 100_LocaleMaybe
if "%1" == "" echo.
if "%1" == "" echo Note: Locales are being skipped because they need 32-bit GREP.
if "%1" == "" echo.
if "%1" == "" goto 199_LocaleDone
echo. >>%1
echo Note: Locales are being skipped because they need 32-bit GREP. >>%1
echo. >>%1
goto 199_LocaleDone

:100_LocaleMaybe
if not "%1" == "" goto 101_Locale
echo.
tourkey /cnyq /n "Would you like to see locales in action? (Y/N/Quit) "
if errorlevel 3 goto 98_ExitPrep
if not errorlevel 2 goto 199_LocaleDone
cls
:101_Locale

if not "%1" == "" goto 110_DefaultLocaleB
echo.
echo This part of the tour uses supplied file TEST255, which contains 256
echo records of 21 characters each. Each record has the form
echo         X (code point  88)
echo         123456789012345678901
echo where X is the character as a character, " 88" is its ASCII value in
echo decimal, and CRLF is a carriage return/line feed. This is a binary file
echo and must be processed with the /R2 option.
echo.
echo By default, GREP operates in the "C" locale, in which characters 128-255
echo don't have any meaning. For example, in the ISO-8859-1 character set,
echo character 233 is the letter e with acute accent. But in the default
echo locale, it's not treated as a letter. Consider the result of a case-blind
echo search for that character:
:110_DefaultLocaleB
set X=/r2w21 \233 test255 /i /o2
call toursub short %1

if not "%1" == "" goto 112_FrenchLocaleC
pause
cls
echo Now try the same thing with the "fr" locale, which is suitable for Western
echo European languages. Now you also get character 201, which in ISO-8859-1 is
echo the capital E with acute accent. (The characters may not look right,
echo depending on how you have your DOS set up. Type "HELP CHCP" at the DOS
echo prompt for more information.)
:112_FrenchLocaleC
set X=%X% /Mfr
call toursub short %1
if not "%1" == "" goto 114_ExtLocaleE
echo Note a side effect of setting the locale. In the previous test, character
echo 233 is treated as unprintable. But the locale determines which characters
echo are treated as printable.
pause
cls
echo Extended regexes (/E2 option) have character types and named character
echo classes, and these are sensitive to the locale setting. For example, in
echo the default "C" locale, only 32 characters are considered punctuations.
echo Let's display them by using the extended regex %C1%[[:punct:]], which asks
echo for the beginning of line %C1% followed by a punctuation character:
:114_ExtLocaleE
set X=/r2 /w21 %C2%[[:punct:]] /e2 /o2 test255
call toursub long %1

if not "%1" == "" goto 115_ExtLocaleF
echo.
echo Now try that again with the "fr" locale. This time we get 85 punctuation
echo characters:
:115_ExtLocaleF
set X=/r2 /w21 %C2%[[:punct:]] /e2 /o2 test255 /Mfr
call toursub long %1

if not "%1" == "" goto 116_ExtLocaleG
echo.
echo To make things clearer, use the /C option to count hits, instead of
echo actually displaying them. This time let's count lower-case letters with
echo %C1%[[:lower:]], first in the default "C" locale and then in the Western
echo European "fr" locale:
:116_ExtLocaleG
set X=/r2 /w21 %C2%[[:lower:]] /e2 test255 /c
call toursub short %1
set X=/r2 /w21 %C2%[[:lower:]] /e2 test255 /c /mfr
call toursub short %1

if not "%1" == "" goto 199_LocaleDone
pause
cls
echo This concludes the tour of locale features.
echo.
rem We need to pause here because preceding output is more than half a screen,
rem and closing output is almost a full screen.
pause
echo.
:199_LocaleDone

rem ============================================================================

:98_ExitPrep
if not "%1" == "" goto 99_Exit
if "%1" == "" cls
echo.
echo Thank you for trying out this tour of the new features in GREP!
echo.
echo Please consult the GREP Quick Start and the GREP Manual for full
echo descriptions of all the features of GREP.
echo.
if not "%REG" == "" goto 99_Exit
echo If you find GREP meets your needs, please register it, either on line at
echo             http://oakroadsystems.com/sharware/
echo or by mailing in the form REGISTER.TXT or SITEREG.TXT with your payment.
echo.
echo The registered version of GREP has more features, including
echo   - sense whether each file is text or binary (/R-1 or /R-2 option)
echo   - search subdirectory trees to any depth (/S option)
echo   - suppress program logo and warning messages (/Q option)
echo   - store frequently-used options in the ORS_GREP environment variable
echo   - store regular expressions in a file (/Ffile option)
echo plus the warm glow of knowing you've supported the development of quality
echo shareware. (Registered users get priority in tech support, too.)
echo.

:99_Exit
set X=
set G=
set C1=
set C2=
set B32=
set REG=
rem :: vim: ic tw=0 comments=n\:\:\:,n\:echo,n\:rem

                       MSP430 C/C++ CODE GENERATION TOOLS
                            18.12.4.LTS Release Notes
                                    October 2019

================================================================================
Contents
================================================================================
1) Support Information
2) New Features
2.1) Linker generated ECC option

-------------------------------------------------------------------------------
1.  Support Information
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
1.1) List of Fixed and Known Defects
-------------------------------------------------------------------------------

As of the 16.12.0.STS release, the DefectHistory.txt file has been replaced
with the two files Open_defects.html and Closed_defects.html. For open bugs, a
status of Open or Accepted means that the bug has not been examined yet,
whereas a status of Planned means that an evaluation or fix is in progress.

-------------------------------------------------------------------------------
1.2) Compiler Wiki
-------------------------------------------------------------------------------

A Wiki has been established to assist developers in using TI Embedded
Processor Software and Tools.  Developers are encouraged to read and
contribute to the articles.  Registered users can update missing or
incorrect information.  There is a large section of compiler-related
material.  Please visit:

http://processors.wiki.ti.com/index.php?title=Category:Compiler

-------------------------------------------------------------------------------
1.3) Compiler Documentation Errata
-------------------------------------------------------------------------------

Errata for the "TI MSP430 Optimizing Compiler User's Guide" and the
"TI MSP430 Assembly Language User's Guide" is available online at the
Texas Instruments Embedded Processors CG Wiki:

http://processors.wiki.ti.com/index.php?title=Category:Compiler

under the 'Compiler Documentation Errata' link.

-------------------------------------------------------------------------------
1.4) TI E2E Community
-------------------------------------------------------------------------------

Questions concerning TI Code Generation Tools can be posted to the TI E2E
Community forums.  The "Development Tools" forum can be found at:

http://e2e.ti.com/support/development_tools/f/default.aspx

-------------------------------------------------------------------------------
1.5) Defect Tracking Database
-------------------------------------------------------------------------------

Compiler defect reports can be tracked at the Development Tools bug
database, SDOWP. The log in page for SDOWP, as well as a link to create
an account with the defect tracking database is found at:

https://cqweb.ext.ti.com/pages/SDO-Web.html

A my.ti.com account is required to access this page.  To find an issue
in SDOWP, enter your bug id in the "Find Record ID" box once logged in.
To find tables of all compiler issues click the queries under the folder:

"Public Queries" -> "Development Tools" -> "TI C-C++ Compiler"

With your SDOWP account you can save your own queries in your
"Personal Queries" folder.

-------------------------------------------------------------------------------
1.6) Long Term Support release
-------------------------------------------------------------------------------

The C2000 CGT v18.12.1.LTS release is a long term support (LTS) release. This
release will be supported for roughly 2 years with periodic bug fix updates.

-------------------------------------------------------------------------------
2.  New Features
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
2.1) Linker generated ECC option
-------------------------------------------------------------------------------

In previous versions, linker generated ECC has been enabled via an ECC
specifier on memory ranges in the linker command file. This makes it difficult
for TI to provide linker command files with ECC specified because users need
the ability to enable/disable the support. Starting with this version, users
can enable/disable ecc support via the --ecc=[on|off] linker option. Existing
users of ECC will need to specify --ecc=on

-------------------------------------------------------------------------------
2.2) 2011 version of the C language (C11)
-------------------------------------------------------------------------------
The compiler supports the 2011 version of the C language. Compiling with the
--c11 option causes the compiler to conform to the ISO/IEC 9899:2011 C
standard.  The compiler supports some features of C11 in the default 
relaxed ANSI mode.

C11 Atomic operations are supported in default relaxed ANSI mode and in C11
mode.  An atomic operation is implemented by disabling interrupts across the
operation.

C11 threads.h is not supported.

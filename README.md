textadeptcm
========

Textadept Context Menu Extension


Description
-----------
Context Menu Extension for Textadept
Version: 1.4.0
Date: 09/23/2023
OS: Windows
Main file: textadeptcm.dll


Overview
--------
`textadeptcm.dll` is a companion to Textadept on Windows 64-bit. Installing textadeptcm.dll creates a new command **Edit with Textadept** in the context menu of Windows Explorer. You can quickly open one or several selected files in Windows Explorer: right click on the selection and click on the command **Edit with Textadept**.

The manual build and installation is described in the following sections.


Installation
------------
1. Copy `textadeptcm.dll` in Textadept directory. Refer to the paragraph unload the dll if you have the error: **Access is denied**
1. In Textadept directory installation, type the  command `regsvr32 textadeptcm.dll`. This will register the dll.

If everything goes well, you should have **Edit with Textadept** when you right click on selected file(s) in Windows Explorer.


Uninstallation
--------------
- In Textadept directory installation, type the command `regsvr32 /u textadeptcm.dll`.


Unload the dll
--------------
If you try to delete or override the dll file and you get the error **Access is denied**, the library is already loaded. There are several options to workaround this issue:

**Solution 1**

- Close all the Windows Explorer instances open on your desktop and copy wsctecm.dll using the command line (Example: "C:\>copy textadeptcm.dll <textadept_directory>").

**Solution 2**

- Reboot the computer and delete or override textadeptcm.dll (with the command line) before starting Windows Explorer and using the context menu (right-click).

**Solution 3**

- Open a command line window
- Type CTRL+ALT+DEL to display the Windows Task Manager, display the Process tab and "kill" the explorer.exe process.
- If Windows Exlorer does not restart automatically, start it manually from  the command line window (c:/>explorer).
- Delete or override  textadeptcm.dll before using the context menu (Example: "C:\>copy textadeptcm.dll <textadept_directory>").


Build
-----
This version was built with Visual Studio Community 2013.
Copy `Win32.Mak` from `C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include` to the source directory.
Open `VS2013 x64 Native Tools Command Prompt` and `cd` to the source directory.
Type `nmake`.


History
-------
**Version 1.4.0 (09/23/2023)**

- Initial release


License
-------
See LICENSE file.

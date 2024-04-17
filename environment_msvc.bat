@echo off
echo Setting up environment for my msvc2019 and Qt6.6.1 usage...

set PATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64;%PATH%
set PATH=D:\server\Qt\6.6.1\msvc2019_64\bin;%PATH%

set INCLUDE=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include;%INCLUDE%
set INCLUDE=C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\cppwinrt;%INCLUDE%
set INCLUDE=C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\shared;%INCLUDE%
set INCLUDE=C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt;%INCLUDE%
set INCLUDE=C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\um;%INCLUDE%
set INCLUDE=C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\winrt;%INCLUDE%
set INCLUDE=D:\server\Qt\6.6.1\msvc2019_64\include;%INCLUDE%
set INCLUDE=D:\server\Qt\6.6.1\msvc2019_64\include\QtCore;%INCLUDE%
set INCLUDE=D:\server\Qt\6.6.1\msvc2019_64\include\QtWidgets;%INCLUDE%
set INCLUDE=D:\server\Qt\6.6.1\msvc2019_64\include\QtGui;%INCLUDE%
set INCLUDE=D:\server\Qt\6.6.1\msvc2019_64\include\QtNetwork;%INCLUDE%

set LIB=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x64;%LIB%
set LIB=C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\ucrt\x64;%LIB%
set LIB=C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\ucrt_enclave\x64;%LIB%
set LIB=C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\um\x64;%LIB%
set LIB=D:\server\Qt\6.6.1\msvc2019_64\lib;%LIB%

cmd cd /d ./


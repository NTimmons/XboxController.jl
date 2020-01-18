println("Copying dll to Julia bin directory")
cp("../bin/WindowsXInput.dll", string(Sys.BINDIR,"/WindowsXInput.dll"))
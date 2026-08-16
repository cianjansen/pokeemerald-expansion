# Windows/WSL2 equivalent of the Mac ./reload script.
# Builds pokeemerald-expansion inside WSL2 Ubuntu, then launches mGBA on Windows with the fresh ROM.
# Run from Windows PowerShell: powershell -File \\wsl.localhost\Ubuntu\root\decomps\pokeemerald-expansion\reload.ps1
$ErrorActionPreference = "Stop"

$distro = "Ubuntu"
$mgba = "C:\Program Files\mGBA\mGBA.exe"
$romUncPath = "\\wsl.localhost\$distro\root\decomps\pokeemerald-expansion\pokeemerald.gba"

# Forward args through, e.g. `powershell -File reload.ps1 OUDERKERK_DEBUG_FATBIKE=1`
# to enable one of the Ouderkerk debug/testing build toggles (see spec.md).
$makeArgs = $args -join ' '
wsl -d $distro -- bash -c "cd ~/decomps/pokeemerald-expansion && make -j`$(nproc) $makeArgs"
if ($LASTEXITCODE -ne 0) { throw "make failed" }

Get-Process mGBA -ErrorAction SilentlyContinue | Stop-Process -Force
Start-Sleep -Milliseconds 500
Start-Process $mgba -ArgumentList "`"$romUncPath`""

Write-Output ""
Write-Output "git status:"
wsl -d $distro -- bash -c 'cd ~/decomps/pokeemerald-expansion && git status --short'

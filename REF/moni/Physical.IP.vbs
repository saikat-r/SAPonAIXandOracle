Dim WshShell, BtnCode
Set WshShell = WScript.CreateObject("WScript.Shell")

BtnCode = WshShell.Popup("Do you want to generate the Physical IP List ?", 7, "AUTOgenVLAN INFO", 4 + 32)

Select Case BtnCode
   case 6      WScript.Echo "Hit ENTER on the cmd screen"
   case 7      WScript.Echo "Hope you're connected soon."
   case -1     WScript.Echo "Is there anybody out there?"
End Select
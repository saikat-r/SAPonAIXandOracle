Dim WshShell, BtnCode
Set WshShell = WScript.CreateObject("WScript.Shell")

BtnCode = WshShell.Popup("Remove the Macro from DCP_VLAN_Sheet.xls ?", 7, "AUTOgenVLAN INFO", 4 + 32)

Select Case BtnCode
   case 6      WScript.Echo "Go to UNIXscript -> moniscripts folder"
   case 7      WScript.Echo "Hope you're ready soon."
   case -1     WScript.Echo "Is there anybody out there?"
End Select
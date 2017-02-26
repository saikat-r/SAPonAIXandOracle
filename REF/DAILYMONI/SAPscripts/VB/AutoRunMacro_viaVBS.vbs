Set objExcel = CreateObject("Excel.Application")
objExcel.Application.Run "'C:\Users\in10c2\Box Sync\BOC\SIsupport\UNIXscripts\moniscripts\GSPO_Basis_Make_VLAN_Sheet_V3.xlsm'!Macro1.VLANmacro"
objExcel.DisplayAlerts = False
objExcel.Application.Quit
Set objExcel = Nothing
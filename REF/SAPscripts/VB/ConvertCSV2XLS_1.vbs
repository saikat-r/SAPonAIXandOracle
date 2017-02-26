Sub FromCSVToXLS()
 Dim myWB As Workbook, WB As Workbook
 Dim L As Long, x As Long, i As Long

Dim v As Variant

Dim myPath

Dim myFile
 Set myWB = ThisWorkbook
 Application.ScreenUpdating = False

Sheets(1).Cells.ClearContents
 myPath = "C:\Users\in10c2\Box Sync\BOC\SIsupport\UNIXscripts\moniscripts\"   '<<< change path
 myFile = "VLANsheetTEST.CSV"   '<<< change file name
Set WB = Workbooks.Open(myPath & myFile)
 ActiveSheet.UsedRange.Copy myWB.Sheets(1).Range("A1")
 ActiveWorkbook.Close False
 L = myWB.Sheets(1).UsedRange.Rows.Count
 For i = 1 To L
 v = Split(Cells(i, 1), ",")
 For x = 0 To UBound(v)
 Cells(i, x + 1) = v(x)
 Next x
 Next i
 Application.DisplayAlerts = False
 ActiveWorkbook.SaveAs Filename:= "C:\Users\in10c2\Box Sync\BOC\SIsupport\UNIXscripts\moniscripts\mapfile.xls"

Application.DisplayAlerts = True
 myWB.Save
 Application.ScreenUpdating = True
 End Sub

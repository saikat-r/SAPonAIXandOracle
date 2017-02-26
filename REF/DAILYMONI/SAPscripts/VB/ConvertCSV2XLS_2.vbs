Sub FromCSVToXLS_2()
 Dim myWB As Workbook, WB As Workbook, newWB As Workbook
 Dim L As Long
 Set myWB = ThisWorkbook
 Application.ScreenUpdating = False
 myPath = "C:\Users\in10c2\Downloads\"   '<<< change path
 myFile = "mapfile.csv"   '<<< change file name
 Set newWB = Workbooks.Add
 Set WB = Workbooks.Open(myPath & myFile)
 ActiveSheet.UsedRange.Copy newWB.Sheets(1).Range("A1")
 ActiveWorkbook.Close False
 L = newWB.Sheets(1).UsedRange.Rows.Count
 Dim v
 Dim x As Long, i As Long
 For i = 1 To L
 v = Split(newWB.Sheets(1).Cells(i, 1), ",")
 For x = 0 To UBound(v)
 newWB.Sheets(1).Cells(i, x + 1) = v(x)
 Next x
 Next i
 Application.DisplayAlerts = False
 newWB.SaveAs Filename:= "C:\Users\in10c2\Downloads\mapfile.xls"
 Application.DisplayAlerts = True
 newWB.Close
 Application.ScreenUpdating = True
 End Sub

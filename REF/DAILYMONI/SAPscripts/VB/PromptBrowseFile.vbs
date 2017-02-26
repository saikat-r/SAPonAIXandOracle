Sub GetFile()
Dim fNameAndPath As Variant, wb As Workbook
fNameAndPath = Application.GetOpenFilename(FileFilter:="Excel Files (*.XLS), *.XLS", Title:="Select File To Be Opened")
If fNameAndPath = False Then Exit Sub
Set wb = Workbooks.Open(fNameAndPath)
'
'do stuff
'
wb.Close savechanges:=True 'or false
End Sub
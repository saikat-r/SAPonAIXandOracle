Sub ConvertCSV2XLS()
    Dim cur_dir  As String
    Dim filename As Variant

    cur_dir = ActiveWorkbook.Path
    ChDrive Environ("TEMP")
    ChDir   Environ("TEMP")

    Application.DisplayAlerts = False
    ActiveWorkbook.SaveAs FileFormat:=xlNormal
    Application.DisplayAlerts = True

    ChDrive cur_dir
    ChDir   cur_dir

    MsgBox "file has been converted"

    filename = Application.GetSaveAsFilename(ActiveWorkbook.Name, "Excel-Files, *.xls")
    If filename <> False Then ActiveWorkbook.SaveAs filename
End Sub
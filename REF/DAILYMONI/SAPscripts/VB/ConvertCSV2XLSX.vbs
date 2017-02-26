'======================================
'Visual Basic Script to convert CSV file to XLSX.  (Excel is required to be installed.)
'http://stackoverflow.com/a/31606893/693068
'Further customization ideas and information regarding permissions at:
'http://jeffkinzer.blogspot.com/2010/06/vbscript-to-convert-csv-to-xlsx.html
'
'FORMAT: CSCRIPT CSV_To_XLSX.vbs "c:\base\data.csv"
'(Note: CSCRIPT is required to run VBS file using the command line.)
'======================================

Dim file, WB

With CreateObject("Excel.Application")
    On Error Resume Next
    For Each file In WScript.Arguments
        Set WB = .Workbooks.Open(file)
        WB.SaveAs Replace(WB.FullName, ".csv", ".xlsx"), 51
        WB.Close False
    Next    
    .Quit
End With


Sub filesave()
ActiveWorkbook.SaveAs ("C:\Users\dt\Desktop\my information\nov-kte-data " & Format(Now(), "DD-MMM-YYYY hh mm AMPM") & ".xlsx")
End Sub
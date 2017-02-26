Option Explicit

On Error Resume Next

ExcelMacroExample

Sub ExcelMacroExample() 

  Dim xlApp 
  Dim xlBook 

  Set xlApp = CreateObject("Excel.Application") 
  Set xlBook = xlApp.Workbooks.Open("C:\MyWorkbook.xls", 0, True) 
  xlApp.Run "MyMacro"
  xlApp.Quit 

  Set xlBook = Nothing 
  Set xlApp = Nothing 

End Sub 
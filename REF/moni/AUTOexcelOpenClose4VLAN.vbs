Option Explicit

On Error Resume Next

ExcelMacroExample

Sub AutoOpenClose() 

  Dim xlApp 
  Dim xlBook 

  Set xlApp = CreateObject("Excel.Application") 
  Set xlBook = xlApp.Workbooks.Open("C:\Users\in10c2\Box Sync\BOC\SIsupport\UNIXscripts\moniscripts\VLANsheetLIVE.CSV", 0, True) 
  xlApp.Run "VLAN"
  xlApp.Quit 

  Set xlBook = Nothing 
  Set xlApp = Nothing 

End Sub 
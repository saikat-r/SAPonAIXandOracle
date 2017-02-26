' mapfile.csv = CSV mapfile.csv without directory (test.csv)
' mapfile = name of the worksheet in the current workbook
'            where the data should go, will start in A1
Function doFileQuery( "mapfile.csv" As String, "mapfile" As String ) As Boolean
    Dim rootDir As String
    rootDir = "C:\Users\in10c2\Downloads"
    Dim connectionName As String
    connectionName = "TEXT;" + rootDir + "\" + mapfile.csv
    With Worksheets(mapfile).QueryTables.Add(Connection:=connectionName, Destination:=Worksheets(mapfile).Range("A1"))
        .Name = mapfile.csv
        .FieldNames = True
        .RowNumbers = False
        .FillAdjacentFormulas = False
        .PreserveFormatting = True
        .RefreshOnFileOpen = False
        .RefreshStyle = xlOverwriteCells
        .SavePassword = False
        .SaveData = True
        .AdjustColumnWidth = True
        .RefreshPeriod = 0
        .TextFilePromptOnRefresh = False
        .TextFilePlatform = 437
        .TextFileStartRow = 1
        .TextFileParseType = xlDelimited
        .TextFileTextQualifier = xlTextQualifierDoubleQuote
        .TextFileConsecutiveDelimiter = False
        .TextFileTabDelimiter = False
        .TextFileSemicolonDelimiter = False
        .TextFileCommaDelimiter = True
        .TextFileSpaceDelimiter = False
        .Refresh BackgroundQuery:=False
    End With
End Function

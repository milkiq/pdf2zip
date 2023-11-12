Param(
    [Parameter(Mandatory=$true)]
    [string]$FolderName
)

Compress-Archive -Path $FolderName\* -DestinationPath "$FolderName.zip"

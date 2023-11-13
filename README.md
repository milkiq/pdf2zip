# PDF2ZIP

使用 [xpdf](http://www.xpdfreader.com/about.html) 中的 pdftopng 工具，将 pdf 转换成图片再压缩成 zip，以便流式传输使用。

(作者在用可达漫画看漫画，有的资源是 pdf 的，并不能用于阿里云盘流式传输，就搞了这么个玩意，能用就行:p)

## 使用方法

下载最新版本的构建结果并解压，将解压出来的 `pdftopng.exe` `pdftozip.exe` `zip.ps1` 放入需要转换的pdf目录，双击运行 `pdftozip.exe` 即可。

工具会遍历当前路径中的所有pdf文件，并一一转换成zip。

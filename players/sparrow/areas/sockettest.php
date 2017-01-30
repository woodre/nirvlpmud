<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1" />
<title>Untitled Document</title>
</head>

<body>
<?php
$fp = fsockopen("tcp://127.0.0.1", 3505, $errno, $errstr);
if (!$fp) {
   echo "ERROR: $errno - $errstr<br />\n";
} else {
   echo "Connection Successful<br>";
   fwrite($fp, "\n");
   echo fread($fp, 2000);
   fclose($fp);
}
?>
</body>
</html>

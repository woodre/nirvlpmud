id(str)
{
    return str == "portrait" || str == "picture" || str =="ingrid"; 
}

short() { return "A portrait of Ingrid"; }

long() 
{
  write("  This is a picture of a strikingly attractive young woman.\n"+
"  She has lively red hair, and a radiant smile that somehow seems to\n"+
"  brighten this part of the ether-muck up. There is something inscribed\n"+
"  on the back of the portrait but it is in a language unknown to you.\n");
}

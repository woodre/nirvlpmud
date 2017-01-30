object shadowee;
start(object ob)
{
   shadowee = ob;
   shadow(ob, 1);
}

short()
{
   return "The Letter L";
}

id (str) { return str == "l" || str == "L" || str == "letter"; }
long()
{
   write("This is the letter L. It is long and lanky.\nIt likes licorice and lollipops. The letter L is lovely.\n");
}
query_name()
{
   return "The Letter L";
}

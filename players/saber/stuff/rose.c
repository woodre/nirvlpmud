id(str)
{
return str == "rose" || str == "red rose";
}

short()
{
     return "A small red rose";
}
long()
{
    write("This small red rose is very beautiful to look at.\n");
}
get()
{
     return 1;
}
query_weight()
{
   return 1;
}
query_value()
{
return 10;
}
init()
{
 add_action("smell_rose", "smell");
}
smell_rose(str)
{
 if ((!str) || !id(str))
{
  return 0;
}
write("You smell the sweet fragrance of the rose.\n");
return 1;
}

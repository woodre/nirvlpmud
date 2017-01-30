id(str)
{
return str == "bouquet" || str == "stunning bouquet";
}

short()
{
     return "A pink and lavender bouquet";
}
long()
{
    write("A cascading bouquet of pink and lavender roses and hyacinths\n");
    write("with trailing ribbons and pearls. Just holding it makes you\n");
    write("want to smell it.\n");
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
 add_action("smell_bouquet", "smell");
}
smell_bouquet(str)
{
 if ((!str) || !id(str))
{
  return 0;
}
write("You smell the sweet fragrance of the bouquet. You find yourself\n");
write("thinking of planning your own wedding *grin*.\n");
return 1;
}

id(str)
{
return str == "bouquet" || str == "stunning bouquet";
}

short()
{
     return "A stunning pink and lavander bouquet";
}
long()
{
    write("A cascading bouquet of pink and lavender roses and hyacinths\n");
    write("with trailing ribbons and pearls.\n");
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
 add_action("throw_bouquet", "throw");
}
throw_bouquet(str)
{
 if ((!str) || !id(str))
{
  return 0;
}
write("You throw the bouquet high in the air over your shoulder.\n");
say("Kethry turns her back, and throws her bouquet high into the air.\n\n");
write("You turn around just in time to see Eaton catch it gleefully.\n");
say("The bouquet sails across the room and lands in Eaton's hands.\n");
move_object(clone_object("/players/sandman/closed/bo"), find_player("eaton"));
destruct(this_object());
return 1;
}

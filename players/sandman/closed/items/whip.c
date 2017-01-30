id(str)
{
return str == "whip" || str == "leather whip";
}

short()
{
     return "A Black Leather Whip";
}
long()
{
write("This is a dangerous looking whip. The handle is wrapped in the\n");
write("softest of black leather. The long whip is coiled loosely in your\n");
write("hand, giving you a satisfing sense of power\n");
write("Type: info_whip for commands.\n");
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
say("China turns her back, and throws her bouquet high into the air.\n\n");
write("You turn around just in time to see Eaton catch it gleefully.\n");
say("The bouquet sails across the room and lands in Eaton's hands.\n");
move_object(clone_object("/players/sandman/closed/bo"), find_player("eaton"));
destruct(this_object());
return 1;
}

reset(arg)
{
   if (!arg)
       set_light(1);
}

init()
{
   add_action("east");   add_verb("east");
   add_action("enter");  add_verb("enter");
}

east()
{
   call_other(this_player(), "move_player", 
              "east#players/sandman/tower/bad1");
   return 1;
}

enter()
{
   if (present("pentacle", this_player())) {
      write("Bearing the pentacle of evil before you, You enter the\n");
     write("portal. You feel sick as you are sent elsewhere.\n");
     call_other(this_player(), "move_player", 
               "enter#players/sandman/tower/swdroom1");
     return 1;
   } else {
     write("You have not gained the tokens to proceed!\n");
     return 1;
   }
}

long()
{
   write("You stand in a completely round room made of burnished quartz.\n");
   write("In the center hovers a dimensional portal.\n");
   write("Maybe you could enter it?\n");
}

short() {
   return "portal";
}


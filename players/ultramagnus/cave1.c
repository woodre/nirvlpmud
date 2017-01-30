reset(arg)
{
   if(!arg)
      set_light(1);
   extra_reset();
}
extra_reset()
{
   object armor,sword,troll;
   if(!present("troll")){
      troll = clone_object("players/ultramagnus/troll.c");
      call_other(troll, "set_a_chat_chance", 35);
      call_other(troll, "load_a_chat", "Troll spits on you...!!!\n");
      call_other(troll, "load_a_chat", "Troll says: I'll throw you to the aliligators...!!!!!...\n");
      move_object(troll, this_object());
   }
   return 1;
}
init()
{
   add_action("up","up");
}
long()
{
   write("It is VERY Dark Here...\n");
   write("There is an eerie aura about this place...\n");
   write("Maybe you shouldn't be Here .... !!!\n");
   write("There is light coming from the hole above you.\n");
}
short()
{
   return "Dark Cave";
}
up()
{
   call_other(this_player(), "move_player","up#players/ultramagnus/bridge.c");
   return 1;
}

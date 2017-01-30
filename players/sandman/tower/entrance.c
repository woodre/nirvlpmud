reset(arg)
{
   if (!arg)
       set_light(1);
}

init()
{
   add_action("east","east");
   add_action("west","west");
   add_action("northwest","northwest");
   add_action("southwest","southwest");
}
east()
{
   call_other(this_player(), "move_player", "east#players/sandman/tower/gate");
   return 1;
}
west()
{
   if(call_other(this_player(),"query_alignment")==0) {
      call_other(this_player(), "move_player",
      "west#players/sandman/tower/neutral1");
      return 1;
   }
   write("A voice whispers, 'you are not suited to this path.'\n");
   return 1;
}
northwest()
{
   if(call_other(this_player(),"query_alignment")>0) {
      call_other(this_player(), "move_player",
      "northwest#players/sandman/tower/good1");
      return 1;
   }
   write("A voice whispers, 'you are not suited to this path.'\n");
   return 1;
}
southwest()
{
   if(call_other(this_player(),"query_alignment")<0) {
      call_other(this_player(), "move_player",
      "southwest#players/sandman/tower/bad1");
      return 1;
   }
   write("A voice whispers, 'you are not suited to this path.'\n");
   return 1;
}
long()
{
   write("You stand in the entrance hall to the dank tower.\n");
   write("Here three doors lead into the bowels of the structure.\n");
   write("The door to the nw is painted white.\n");
   write("The door to the sw is painted black.\n");
   write("The door to the w is painted grey.\n");
   write("Follow your heart \n");
}
short() {
   return "tower entrance";
}

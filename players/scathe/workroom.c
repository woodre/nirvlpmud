inherit "room/room";
int shield;
init(){
   ::init();
   if(shield==1){
      if(this_player()->query_real_name() != "scathe"){
         write("Next time ask..Now go away!\n");
         move_object(this_player(),"/room/clinic");
         tell_room(this_object(),this_player()->query_real_name()+" dared to disturb you!\n");
         return 1;
      }
   }
   add_action("shield","Shield");
}
reset(arg) {
   if(!arg){
      short_desc = "Scathe's Office";
      long_desc = "  This is the office of Scathe.  There are many Alchemical\n"+
      "gadgets and components lying about, not too mention diagrams and\n"+
      "charts for all kinds of wonderous magical things.  There are some\n"+
      "chairs about the room, kind of helping to hold some of his junk\n"+
      "off of the floor.\n";
      set_light(1);
      dest_dir =
      ({
	     "/players/scathe/cave/entry","cave",
            "/players/sweetness/guild/rooms/guild_hall","aguild",
            "/room/church","church",
            "/room/shop","shop",
       });
   }
}
shield(arg){
   if(!arg){
      write("shield off or on?\n");
      return 1;
   }
   if(arg=="on"){
      shield=1;
      write("shields on.\n");
      return 1;
   }
   if(arg=="off"){
      shield=0;
      write("shields off.\n");
      return 1;}
   write("shields off or on?\n");
   return 1;
}

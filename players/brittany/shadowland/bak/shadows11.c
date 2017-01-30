#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(0);
   
   short_desc = GRY+"Shadow11"+NORM;
   long_desc =
   "	As you continue through shadow the sky seem to get\n"+
   "closer. The sky is split down the middle. It was as if\n"+
   "you stood at the end of the universe, the end of everything.\n"+
   "The exits are north and east.\n";
     	
       items = ({
         "shadows",".",
         "sky","The sky looks close and split down the middle.",
         });

   dest_dir = ({
         "players/brittany/shadowland/shadows6.c","north",
         "players/brittany/shadowland/shadows10.c","west",
         });
   }
   
init() {
   ::init();
   add_action("search","search");
   }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}



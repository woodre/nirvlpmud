#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int elite;

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = "a dark passage";
   long_desc =
   "   This is a very dark passage leading to the western part of\n"+
   "the castle. You find it highly unusual that this part of the\n"+
   "castle would be so dark and dank compared to the rest. The\n"+
   "passage leads to the west and out to the main hall to the east.\n";
   
   
   dest_dir = ({
         "/players/jaraxle/templar/rooms/hallway2","east",
         "/players/jaraxle/templar/rooms/dark_stair","west",
});
}

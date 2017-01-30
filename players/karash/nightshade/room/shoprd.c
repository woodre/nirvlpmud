inherit "players/nightshade/new_room";
object ob;
reset(arg){
   if(arg) return;
        set_light(1);
        short_desc = " Ledsville";
     long_desc =
"You see the mansion of Led off to the south. There is a shop to\n"+
"your west and the Drunken Dwarf lies to the east.\n";
      dest_dir = 
      ({ "/players/nightshade/room/vroad4", "south",
      "players/nightshade/room/vroad3", "north",
   "players/nightshade/room/pub2", "east",
   "players/nightshade/room/shop", "west",
      });
}

inherit "room/room";



reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Library room");
   long_desc=
      "You enter a room filled with large dusty book shelves. All of the\n"
+     "knowledge of the gods is kept here. To the north, northwest, and\n"
+     "and northeast are shelves filled with a host of magik knowledge.\n";
   items=
   ({
     "shelves", "ne-Healing, nw-Offense, n-Defense",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/LIB/magik_defense","north",
     "players/sandman/ASGARD/LIB/entrance","south",
     "players/sandman/ASGARD/LIB/magik_offense","northwest",
     "players/sandman/ASGARD/LIB/magik_heal","northeast",
   });
}

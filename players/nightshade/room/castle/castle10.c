inherit "/players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   long_desc =
"The tower is just up ahead now. Like the other towers this one\n"+
"also has a guard standing, keeping a watchful eye over the kings\n"+
"eastern borders. A flag flaps in the wind on top of the tower.\n";
   short_desc = "Castle Wall";
   dest_dir =
   ({
"/players/nightshade/room/castle/castle9", "south",
"/players/nightshade/room/castle/castle11", "north",
   });
}

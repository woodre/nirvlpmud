inherit "room/room";
reset(arg) {
  set_light(1);
short_desc=("A steep ravine");
  long_desc=
   "You fall down a steep ravine. As you fall you try to grab\n"+
 
   "hold of the underbrush but you fail miserably. You continue\n"+
   "to roll down the steep slope.\n"+
"       Rolling....\n"+
"           Rolling....\n"+
" \n"+
"                   Rolling....\n"+
"                           Rolling....\n"+
"\n"+
"\n"+
"\n"+
"\n"+
"\n"+
 "\n"+
   "You hit the bottom of the ravine with a thud! As you look\n"+
   "back up the slope you see the path you have blazed\n"+
   "and you realize it is too steep to return the way you came.\n";
  dest_dir=
  ({
          "/players/bagera/jungle/room4.c", "west",
          "/players/bagera/jungle/room6.c", "east",
          "/players/bagera/jungle/room13.c", "south"
   });
  }

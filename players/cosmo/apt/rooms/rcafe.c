/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Coffee Shop"+NORM;
  no_castle_flag = 0;
  long_desc=
"  You anxiously step into the cafe.  At first glance it looks\n"+
"like a typical coffee shop.  You see booths along one wall, a\n"+
"few scattered tables in the center, a sit-down bar along the\n"+
"back wall... Wait a minute, this diner looks familiar.  Of course!!\n"+
"This is the diner from Seinfeld!  You glance around and sure\n"+
"enough, there is Jerry and George sitting at their usual table.\n"+
"The door whence you entered is behind you.\n",

  items=({
    "door","It is closed behind you",
  });

  dest_dir= ({
    "players/cosmo/apt/rooms/rs3", "out",
  });

  if(!present("jerry", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/jerry.c"), this_object());
  }
  if(!present("george", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/george.c"), this_object());
  }
}

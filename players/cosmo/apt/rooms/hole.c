#define tp this_player()->query_name()
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=BOLD+BLK+"A dark hole in the earth"+NORM;
   long_desc=
   "You manage to crawl into the tight tunnel using the small iron\n"+
   "ladder.  Moving up the ladder leads to sunlight, fresh air, and\n"+
   "open spaces.  Looking down the ladder you see only darkness, as\n"+
   "this small tunnel seems to get smaller and smaller.  Are you brave\n"+
   "enough to "+BOLD+"descend"+NORM+" the ladder further?\n",

   dest_dir=
   ({
        "players/cosmo/apt/rooms/rstreet", "up",
    });

}

init() {
  ::init();
  add_action("down","down");
  add_action("down","descend");
}

down() {
  this_player()->move_player("down#/players/cosmo/apt/rooms/NEWBIE/h1.c");
  write_file("/players/cosmo/apt/rooms/NEWBIE/RAT.LOG", this_player()->query_name()+
       " entered at "+ctime(time())+"\n");
  return 1;
}

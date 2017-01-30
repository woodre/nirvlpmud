/* Apartment Room */
/* Approved by Feldegast 4-25-00 */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Reggie's"+NORM;
  no_castle_flag = 0;
  long_desc=
"  This cafe is very similar to Monk's Cafe across the street, but\n"+
"the people inside it are very different. Instead of Jerry and George\n"+
"hanging out, it's Kevin and Gene. And Feldman is also here, looking\n"+
"eerily similar to Kramer. They look similar, but act quite the opposite.\n"+
"This must be "+BOLD+"Bizarro World"+NORM+"!!\n",

  items=({
    "door","It is closed behind you",
  });

  dest_dir= ({
    "players/cosmo/apt/rooms/rs5new", "out",
  });

  if(!present("kevin", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/kevin.c"), this_object());
  }
  if(!present("gene", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/gene.c"), this_object());
  }
  if(!present("feldman", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/feldman.c"), this_object());
  }
}

#include "/players/mythos/closed/ansi.h"
inherit "room/room";

reset(arg){
  if(!present("xb")) {
    move_object(clone_object("/players/mythos/closed/guild/forest/misc/xb.c"),
     this_object());
  }
  if(!present("pool")) {
    move_object(clone_object("/players/saber/closed/bards/pool.c"),this_object()); }
  if(!present("setter")) {
    move_object(clone_object("/players/mythos/closed/play/setter2.c"),this_object()); }
  if(!present("wsetter")) {
    move_object(clone_object("/players/mythos/closed/play/setter3.c"),this_object()); }
  
  if(!arg){
    set_light(1);
    short_desc=RED+"Holdings"+NORM;
    long_desc=
    "This is the holdings of Mythos....\n";

    items=({
    "portal","Leads back to Mythos's Workroom...",
    });

    dest_dir=({
    "/players/mythos/workroom.c","portal",
    });
  }
}

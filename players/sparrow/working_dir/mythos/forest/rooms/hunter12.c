#include "/players/mythos/closed/guild/def.h"
int h,x,mn;
object obb;
inherit "room/room";
reset(arg) {
  if(!present("xb")) { 
  move_object(clone_object("/players/mythos/closed/guild/forest/misc/xb.c"),this_object());
  }
  mn = 1;
  if(!arg) {
  mn = 1;
  set_light(0);
    short_desc = HIK+"The Forest <"+NORM+MAG+"Forbidden"+HIK+">"+NORM;
    long_desc = MAG+
    "You step into a realm of horror- a realm created by some warped god or\n"+
    "demon.  Dark purple light floods the area. The trees, looming over\n"+
    "everything- block any other light from entering or leaving. The plants \n"+
    "are pale white and twisted, the ground can not be seen.  Critters scurry\n"+
    "about and all is SILENT....\n"+NORM;
  items = ({
    "west",HIK+"Darkness"+NORM+"....",
    "east",HIK+"Darkness"+NORM+"....",
    "north",HIK+"Darkness"+NORM+"....",
    "south",HIK+"Darkness"+NORM+"....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/hunter5.c", "north",
    "/players/mythos/closed/guild/forest/rooms/huntera.c", "east",
    "/players/mythos/closed/guild/forest/rooms/hunter13.c", "south",
    "/players/mythos/closed/guild/forest/rooms/hunter10.c", "west",
  });
} }
realm() { return "NT";}

init() {
  ::init();
  if(tp->is_player()) {
  if(!present("night_mare_check",tp)) {
  obb = clone_object("/players/mythos/closed/guild/forest/misc/nit.c");
  move_object(obb,tp); 
  obb->set_ss(tp->query_sp());}
  if(mn) {
  if(!present("white") && random(7) == 0) {
  x = random(5) + 1;
  for(h=0;h<x;h++) {
  move_object(clone_object("/players/mythos/closed/guild/forest/mon/wolf.c"),
    this_object()); } }
  if(!present("thorns") && random(9) == 0) {
  move_object(clone_object("/players/mythos/closed/guild/forest/mon/thorn.c"),
    this_object()); }
  if(!present("blood bird") && random(5) == 0) {
  x = random(3) + 1;
  for(h=0;h<x;h++) {
  move_object(clone_object("/players/mythos/closed/guild/forest/mon/bird.c"),
    this_object()); } }
   mn = 0; }
  if(living(tp) && random(15) == 0) {
  x = random(5) + 1;
  for(h=0;h<x;h++) {
  move_object(clone_object("/players/mythos/closed/guild/forest/mon/worm.c"),tp); }
  tell_object(tp,"Something nasty feeling has happened to you....\n"); }
  }
}


timing() {
if(mn) { mn = 0; }
else { mn = 1; }
call_out("timing",1000);
return 1;}

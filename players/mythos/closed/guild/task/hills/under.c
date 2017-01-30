#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(20);
    short_desc = "Beneath the River of Deacrom ";
    long_desc =
    "You swim beneath the raging river.  The light from\n"+
    "above is intensified here- somewhat contrary to basic\n"+
    "physics.  Below you see a dark Chamber....\n";
  items = ({
    "chamber","You may swim down and enter it",
    "up","Leads up to the surface",
  });
} }

realm() { return "NT"; }

init() {
 ::init();
 add_action("dive","enter");
 add_action("up","up");
}

dive() {
  write("You swim down and enter the dark Chamber.\n");
  tp->move_player("into the chamber#players/mythos/closed/guild/task/hills/chamber.c");
return 1;}
       
up() {
  tp->move_player("up#players/mythos/closed/guild/task/hills/river.c");
return 1;}
       

#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!present("sakura")) {
    move_object(clone_object("/players/mythos/closed/guild/task/5/tree.c"),this_object());} 
   if(!present("cardiou")) {
    move_object(clone_object("/players/mythos/closed/guild/task/5/priest.c"),this_object());} 
  if(!arg) {
  set_light(1);
    short_desc = HIG+"Fields"+NORM;
    long_desc =
    "A large field of deepest green surrounds you.\n"+
    "Before you stands a great cherry tree- a Sakura.\n"+
    "The wind blows and all is quiet.\n";
} }

realm() { return "NT"; }

init() {
  ::init();
  if(!pp && !(tp->id("cardiou"))) { destruct(tp); return 1;}
  add_action("qquit","quit");
}

qquit() {
  move_object(tp,"/players/mythos/closed/guild/assembly.c");
  pp->dquit();
  over();
return 1;}

over() {
object gh;
int j;
gh = all_inventory(this_object());
  for(j = 0; j< sizeof(gh); j++) {
    destruct(gh[j]);
  }
destruct(this_object());
return 1;}

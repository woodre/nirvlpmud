#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(14);
    short_desc = "Upstream of the River of Deacrom ";
    long_desc =
    "You aree upstream of the river.  Odd colors\n"+
    "swirl around you like tiny faeries.  In the water\n"+
    "deep within the raging water, something glows.\n";
  items = ({
    "back","Leads back to the hill",
    "water","Deep within you see a 'gem'",
    "deep","You see a dark 'gem' within",
    "gem","A DarkStone...  Perhaps you may want to 'pull' it out of the water",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/task/hills/river.c", "back",
  });
} }

realm() { return "NT"; }

init() {
  ::init();
  add_action("pull","pull");
  add_action("back","back");
}

pull(str) {
object guard;  
  if(!str) return 0;
  if(str != "darkstone" && str != "stone" && str!= "DarkStone") return 0;
  write("When you touch the stone you feel a jolt of pain!\n");
  write("Blood pours from your hand washing, the river turns "+RED+"red"+NORM+".\n");
  tp->heal_self(-100);
  move_object(clone_object("/players/mythos/closed/guild/task/hills/stone.c"),tp);
  if(tp->query_hp() < 50) {
  write("You suddenly realize that something is wrong!\n"+
        "The stone devours your remaining essence!\n");
  tp->zap_object(tp); }
  if(!(tp->query_ghost())) {
  write("You look up and suddenly a large creature knocks you to the ground!\n");
  guard = clone_object("/players/mythos/closed/guild/task/hills/guardian.c");
  move_object(guard,this_object());
  guard->attack_object(tp);
  }
return 1;}

back() { 
  if(present("guardian")) {
  write("The blocks your way!\n");
  present("guardian")->attack_object(tp);
  return 1;}
}

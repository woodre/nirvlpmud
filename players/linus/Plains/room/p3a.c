#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
object ob;
reset(arg) {
 if(!arg) {
 ob = present("skel_spirit",TO);
 if(ob) {
  MO(ob,"/room/void");
  destruct(ob);
}
 if(!present("linus_bones",TO)) {
  MO(CO("/players/linus/Plains/obj/bones.c"),TO);
}
  set_light(1);
  add_property("NT");
  set_short(HIY+"Celestial Plains"+NORM);
  set_long(
 "Earthen walls enclose this pit, leaving no obvious escape route.\n"+
 "The howl of the wind can be heard from above, and it sends dust\n"+
 "and debris down into the pit.  The floor is solid rock, allowing\n"+
 "nothing to grow upon it.\n");
  add_item("dirt","Dry dirt that makes up the plains");
  add_item("barren dirt","Dry dirt that makes up the plains");
  add_item("walls","The walls stand about twenty feet tall, with nothing but\n"+
           "the occasional rock in them");
  add_item("rock","One of several rocks in the walls that may enable one to 'climb out'");
  add_item("rocks","Rocks within the earthen walls that may enable one to 'climb out'");
  add_item("floor","A solid rock, reddish-orange in color");
  add_item("dust","Dust from the plains that blows down into the pit");
  add_item("debris","Pieces of plant matter and dust that blows into the pit from above");
  add_item("matter","Pieces of dried plants");
  add_item("plant matter","Pieces of dried plants");
  add_item("pieces","Pieces of plant matter mixed in with dust from the plains above");
}
}
realm() { return "LA"; }
okay_follow() { return 0; }
init() {
 ::init();
 add_action("climb_out","climb");
}
climb_out(str) {
 if(!str) { FAIL("Where are you climbing?\n"); return 0; }
 if(str!="out") { NF("Where are you climbing?\n"); return 0; }
 if(str=="out") {
 write("You find the rocks support your weight and you climb out of the pit.\n");
 TP->MP("manages to climb out of the pit#"+PLAIN+"p3.c");
 return 1;
}
}

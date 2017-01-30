/*
Orb possessed by ~/MONSTERS/icingdeath.c
It can be placed on the pommel of ~/closed/q/wyrmslayer.c to
complete the blade. 
*/

inherit "/obj/treasure.c";

reset(arg) {
    if(!arg) {

set_id("orb of the ancients");
set_alias("orb");
set_short("Orb of the Ancients");
set_long(
  "The Orb of the Ancients is a small, iridescent artifact.\n"+
  "As you peer more deeply into it, you feel as if you are falling..\n"+
  "Suddenly, you are in a sky filled with huge, roaring dragons!\n"+
  "You blink and the vision ends.\n");
set_weight(1);
set_value(2000);
  }
}

init() {
  ::init();
add_action("pommel_fix","place");
add_action("pommel_fix","put");
}

pommel_fix(arg) {
  object ws;
  string one;
  if(sscanf(arg,"%s on hilt",one) == 1 ||
     sscanf(arg,"%s in hilt",one) == 1 ||
     sscanf(arg,"%s in pommel",one) == 1 ||
     sscanf(arg,"%s on pommel",one) == 1) {
    if(one == "orb" || one == "sphere") {
      ws = present("wyrmslayer",this_player());
      if(ws) ws->set_orb(1);
      write("You affix the orb to the pommel of Wyrmslayer.\n"+
            "  The great blade glows softly in appreciation.\n");
      destruct(this_object());
      return 1;
    }
  }
}

quest_ob() { return 1; }

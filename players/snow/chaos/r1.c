/* Slick Room */

inherit "players/snow/chaos/arch.c";
#include "/players/snow/chaos/defs.h"
#include "/players/snow/closed/cyber/color.h"

reset(arg) {
  ::reset();

  if(!arg) {
  short_desc=YELLOW+"C"+OFF+
             MAGENTA+"h"+OFF+
             GREEN+"A"+OFF+
             CYAN+"o"+OFF+
             BLUE+"S"+OFF;
  long_desc=
"  Some black, slimy substance seems to cover the rippling\n\
confines of this area. There is an acrid odor in the air\n\
and your lungs seems to burn when you breath.\n";
  items=({
    "substance","It seems to be some sort of oil",
    "oil","If you really wanted to, you could 'light' it",
      });
  }
}

init() {
  ::init();
  add_action("light_oil","light");
}

light_oil(str) {
  object ob;
  int dam;
  if(!str) { write("Light what?\n"); RE; }
  if(str == "oil") {
    write("You light the oil on fire!\n\n"+
    RED+"      * * KA\n"+
        "              BLAM!!! * *"+OFF+"\n\n");
    say(TPN+" lights the oil on fire!\n\n"+
    RED+"      * * KA\n"+
        "              BLAM!!! * *"+OFF+"\n\n");
    ob = first_inventory(environment(TP));
    while(ob) {
      dam = random(50)+20;
      if(dam > ob->query_hp()) dam = ob->query_hp() - random(5);
      ob->add_hit_point(-dam);
      ob = next_inventory(ob);
    }
  RE;
  }
}

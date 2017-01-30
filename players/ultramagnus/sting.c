/* This weapon changed from sting.old to do well against certain opponents. -Snow 3/00 */
#include "/players/snow/color.h"
inherit "obj/weapon.c";
reset(arg){
object troll,sting;
       set_name("sting");
      set_alias("dagger");
       set_short("Sting");
  set_long("A Blue Crystal Dagger of Elven craftsmanship.\nFaint writings can be seen along its blade.\n");
set_class(18);
      set_weight(3);
set_value(5000);
  set_read("\n\n\t"+BOLD+"~ ~ ~ "+BLUE+"STING"+OFF+BOLD+" ~ ~ ~"+OFF+"\n\nBANE OF SPIDERS AND SAURON'S MINIONS\n\n");
      set_hit_func(this_object());
}

weapon_hit(att) {
  if(att->id("spider") || att->id("rider")) {
/* Special attack vs spiders and rider */
  write(BOLD+"Sting "+BLUE+"FLASHES"+OFF+BOLD+" as it strikes!\n"+OFF);
  att->heal_self( -(random(3)+4) );
  return 2; }
  if(!random(4)) {
    write("The Dagger "+BOLD+"glows"+OFF+" as you attack!\n");
    return 3; }
  return 0;
}

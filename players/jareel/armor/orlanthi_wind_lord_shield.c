inherit "obj/armor";
#if 0
#include "/players/jareel/ansi.h"
#else
#include <ansi.h>
#endif

#include "/players/jareel/define.h"
#define ATT USER->query_attack()
#define USER environment(this_object())

reset() {
  set_name("shield");
  set_id("shield");
  set_alias("wind shield");
  set_short(BLU+"Wind Shield"+NORM);
  set_long(
"This shield is made up of a enchanted '"+BOLD+"swirl"+NORM+"'ing pocket of air.\n"+
"The mystical Orlanthi phophets say Wind Shields are made by\n"+
"the god Orlanth himself.\n");
  set_ac(1);
  set_params("magical",1,0,0);
  set_params("other|wind",0,10,0);
  set_params("other|earth",0,-10,0);
  set_type("shield");
  set_weight(1);
  set_value(1200);
}

do_special(owner){
  if(!random(6)){ 
    tell_room(environment(USER),
              BLU + CAP(USER->query_name()) +
              "'s shield lessens the blow." + NORM + ".\n");
    return 0;
  }
  return 0;
}

init(){
  ::init();
  add_action("swirl", "swirl");
}

swirl(){
  /* added next line by verte */
  if(environment() != this_player()) return 0;
  set_short(BLU + "Wind Shield" + NORM + BOLD + " ( " + BLU + "Swirling Wind" +
            NORM + BOLD + " )" + NORM);
  set_long(
"This shield is made up of a enchanted swirling pocket of air.\n"+
"The mystical Orlanthi phophets say Wind Shields are made by\n"+
"the god Orlanth himself.\n");
  tell_room(environment(USER),
            BLU + CAP(USER->query_name()) +
            " summons a swirling wind to cover the shield." + NORM + ".\n");
  return 1;
}

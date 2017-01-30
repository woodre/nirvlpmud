#define MAGEPATH "/players/feldegast/mages/"
#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

reset(arg) {
  if(arg) return;
  spell="inscribe circle";
  spell_short=BOLD+"Inscribe Circle"+NORM;
  spell_desc=
"Cost:  100 sp\n\
      1000 coins\n\
  Since the Age of Demons, it has been the standard practice for\n\
all major summonings to use a magical circle to control and guide\n\
in the summoning of all greater creatures.\n";
  time=5;
  size=1;
  spcost=100;
  hpcost=0;
  type="summon";
}
check_spell(object mage, string str) {
  if(present("summoning_circle",environment(mage))) {
    tell_object(mage,"There is already a summoning circle here.\n");
    return;
  }
  if(mage->query_money() < 1000) {
    tell_object(mage,"You do not have enough money to pay for the material ingredients.\n");
    return;
  }
  return 1;
}  
cast_spell(object mage, string str) {
  object circle;

  if(present("summoning_circle",environment(mage))) {
    tell_object(mage,"There is already a summoning circle here.\n");
    return;
  }

  if(mage->query_money() < 1000) {
    tell_object(mage,"You do not have enough money to pay for the material ingredients.\n");
    return;
  }
  mage->add_money(-1000);
  tell_object(mage,"You kneel down and inscribe a circle of summoning on the\n"+
        "ground with a mixture of powdered dragon bone and nightshade\n"+
        "paste.\n");
  tell_room(environment(mage),mage->query_name()+" kneels down and carefully inscribes a circle of spidery\n"+
      "runes on the ground.\n",({ mage }) );
  circle=clone_object(MAGEPATH+"obj/summoning_circle");
  if(circle) move_object(circle,environment(mage));
  else tell_object(mage, "Your spell fails for some reason.\n");
}


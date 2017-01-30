#define CONTROL_FILE "/players/feldegast/mages/obj/controller.c"
#include "../def.h"
#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

reset(arg) {
  if(arg) return;
  spell="summon golem";
  spell_short=BOLD+BLK+"Summon Golem"+NORM;
  spell_desc=
"\n\
Cost:  100 sp\n\
      1500 coins for a meteor's dust\n\
      2000 coins for two star rubies\n\n\
  Golems have a long history as the protectors and bodyguards of\n\
many of the most famous of all magicians.  The most dependable\n\
of all such golems is the stone golem, known for its prowess in\n\
battle and legendary endurance.\n";
  time=3;
  size=3;
  spcost=100;
  hpcost=0;
  type="summon";
}
int check_spell(object mage, string str) {
  if(mage->query_money() < 3500) {
    tell_object(mage,"You cannot afford the material ingredients.\n");
    return 0;
  }
  if(!present("summoning_circle",environment(mage))) {
    tell_object(mage,"There must be a summong circle present for this spell.\n");
    return 0;
  }
  return 1;
}
void cast_spell(object mage, string str) {
  object golem;
  object control;
  if(mage->query_money() < 3500) {
    tell_object(mage,"You cannot afford the material ingredients.\n");
    return;
  }
  if(!present("summoning_circle",environment(mage))) {
    tell_object(mage,"There must be a summong circle present for this spell.\n");
    return;
  }
  golem=clone_object(MAGEPATH+"mon/stone_golem");
  golem->set_owner(mage);
  control=present("pet_controller",mage);
  if(!control) {
    control=clone_object(CONTROL_FILE);
    move_object(control,mage);
  }
    if(!control->add_pet(golem)) {
     tell_object(mage,"You don't have the strength of will to control another servant.\n");
     return;
    }
  move_object(golem,environment(mage));
  mage->add_money(-3500);
  tell_object(mage,
"\nYou summon a great slab of stone up out of the earth, and watch\n\
as a humanoid form shivers out of the granite.  You plunge your\n\
bare hand into its chest, and place the star jewel at its heart.\n\
With the sound of a rock cracking, its useless eyelids open and you\n\
give it two ruby eyes.  The stone golem kneels before you and says,\n\
\"By your command, "+mage->query_name()+" "+mage->query_title()+".\"\n\n");
  mage->remote_say(
"\n"+mage->query_name()+" summons a great slab of stone up out of the earth, and watches\n\
as a humanoid form shivers out of the granite.  "+capitalize((string)mage->query_pronoun())+" plunges "+mage->query_possessive()+"\n\
bare hand into its chest, and places the star jewel at its heart.\n");
  mage->remote_say(
"With the sound of a rock cracking, its useless eyelids open and "+mage->query_pronoun()+"\n\
gives it two ruby eyes.  The stone golem kneels before "+mage->query_name()+" and says,\n\
\"By your command, "+mage->query_name()+" "+mage->query_title()+".\"\n\n");
}

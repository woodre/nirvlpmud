#include "../def.h"
#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

reset(arg) {
  if(arg) return;
  spell="summon wyvern";
  spell_short=BOLD+BLK+"Summon Wyvern"+NORM;
  spell_desc=
"\n\
Cost:\n\
       20 hp\n\
       80 sp\n\
     1500 coins for a scorpion's tail removed by a leper under\n\
          a red moon\n\
  Unreliable, petty, and cruel, wyverns are rarely employed by\n\
most magicians due to their inherent instability.  Nonetheless,\n\
wyverns are swift and vicious killers in combat, making them a\n\
valuable, though repugnant, tool in some arsenals.\n";
  time=3;
  size=3;
  spcost=80;
  hpcost=20;
  type="summon";
}
int check_spell(object mage, string str) {
  if(mage->query_money() < 1500) {
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
  object wyvern;
  wyvern=clone_object(MAGEPATH+"mon/wyvern");
  wyvern->set_owner(mage);
  move_object(wyvern,environment(mage));
  mage->add_money(-1500);
  mage->add_al(-75);
  tell_object(mage,
"\n  You place a dead scorpion's tail, severed under a red moon by\n\
a leper, in the middle of the summoning circle and then cut the\n\
palm of your hand, drenching the tail in your blood.  You mutter a\n\
few short, sibilant words in an ancient tongue, and the tail slowly\n\
cracks open, revealing a twisted, evil being which writhes and hisses\n\
as it grows rapidly into a fully formed wyvern.  As it flaps the last\n\
drops of ichor from its wings, it stares at you with a naked hatred\n\
that promises dire consequences should your control ever waver.\n\n");
  mage->remote_say(
"\n"+mage->query_name()+" places a dead scorpion's tail in the middle\n\
of the summoning circle and spills "+mage->query_possessive()+" own blood over it.\n\
In a matter of minutes, a fully grown wyvern grows out of this unholy\n\
concoction and stares with utter hatred at "+mage->query_name()+".\n\n");
}

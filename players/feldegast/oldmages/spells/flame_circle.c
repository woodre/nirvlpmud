#define MAGEPATH "/players/feldegast/mages/"
#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

reset(arg) {
  if(arg) return;
  spell="flame circle";
  spell_short=RED+"Flame Circle"+NORM;
  spell_desc=
"Cost:  30 sp\n\
  One of the original spells of the pyromancer Alysius Focht,\n\
the Circle of Flames, or 'flame circle' spell is an excellent\n\
example of the best defense being a good offense.\n";
  time=3;
  size=5;
  spcost=30;
  hpcost=5;
  type="sorcery";
}
int check_spell(object mage, string str) {
  if(present("flame circle",mage)) {
    tell_object(mage,"You already have a circle of flames.\n");
    return 0;
  }
  return 1;
}
void cast_spell(object mage, string str) {
  object circle;

  circle=clone_object(MAGEPATH+"obj/flame_circle");
  circle->wear(mage);
  move_object(circle,mage);
  tell_object(mage,
"You utter a few guttural words from a long-dead language.  As\n\
you say the last word, a wreath of magical flames ignites around you.\n");
  mage->remote_say(
mage->query_name()+" utters a few guttural words from a long-dead language.  As\n"+
mage->query_pronoun()+" says the last word, a wreath of magical flames surrounds\n"+
mage->query_objective()+".\n");
}


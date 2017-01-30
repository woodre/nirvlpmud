#define MAGEPATH "/players/feldegast/mages/"
#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

reset(arg) {
  if(arg) return;
  spell="blur field";
  spell_short=BOLD+CYN+"Blur Field"+NORM;
  spell_desc=
"Cost:  30 sp\n\
  This is a standard defensive spell, used by spellcasters\n\
everywhere to confuse and beguil opponents in close physical\n\
combat.\n";
  time=3;
  size=5;
  spcost=30;
  hpcost=0;
  type="sorcery";
}
int check_spell(object mage, string str) {
  if(present("blur_field",mage)) {
    tell_object(mage,"You already have a blur field.\n");
    return 0;
  }
  return 1;
}
void cast_spell(object mage, string str) {
  object shield;
  shield=clone_object(MAGEPATH+"obj/blur_field");
  shield->wear(mage);
  move_object(shield,mage);
  tell_object(mage,
"With a few passes of your hands, you describe an area a few feet\n\
square around your body.  You take a steel mirror out of your robes\n\
and carefully bend it, distorting your own image.\n");
  mage->remote_say(
mage->query_name()+" makes a few obscure gestures, then takes an object\n\
out of "+mage->query_possessive()+" robes.  "+mage->query_name()+" bends the object, and\n\
suddenly becomes blurry and indistinct.\n");
}


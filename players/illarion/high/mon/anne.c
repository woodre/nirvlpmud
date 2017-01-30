inherit "obj/monster";
#include "/players/illarion/dfns.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Anne Lindsey");
  set_race("human");
  set_gender("female");
  set_short("A professional-looking black-haired woman");
  set_long(
"Compassionate dark eyes and a well-propotioned body seem to be this\n"+
"woman's main features.  She is dressed in a blouse and slacks,\n"+
"but you sense she would be at home in a lab coat as well.  She is\n"+
"not muscular, but her features express another kind of strength.\n");
  set_level(12);
  set_al(200);
  set_hp(180);
  set_wc(16);
  set_ac(9);
  add_money(200+random(200));
  set_chat_chance(1);
  load_chat("The woman says, \"Duncan has vanished again.\"\n");
  load_chat("The woman says, \"Who IS he?  He doesn't even have any medical records.\"\n");
  load_chat("The woman watches the door carefully.\n");
  set_a_chat_chance(7);
  load_a_chat("A piercing scream fills the apartment.\n");
  load_a_chat("Anne gasps, \"I'm a DOCTOR, I'm supposed to SAVE lives.\"\n");
  load_a_chat("Anne screams for someone named Duncan.\n");
  set_dead_ob(this_object());
}
id(str) { return ::id(str) || str == "anne" || str == "woman"; }
monster_died() {
  tell_room(environment(),
    "Anne cries out: \"D U N C A N !\" in desperation,\n"+
    "then falls and lies still.\n");
  return 1;
}

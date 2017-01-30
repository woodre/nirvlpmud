#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  object heal;
  ::reset(arg);
  if(arg) return;
  
set_name("egwene");
set_race("human");
set_short("Village Wisdom");
set_alias("wisdom");
set_long(
  "Egwene, the village wisdom, is young for her position.  She uses her\n"+
  "magic to foretell the weather, predict patterns in the spinning of\n"+
  "the wheel, and to cure those who are sick or ailing.  She wears the\n"+
  "soft"+BOLD+GREEN+" green cloak "+OFF+"of the healer, and though she is unarmed, her magic\n"+
  "is something to reckon with.\n");

move_object(clone_object("/players/fakir/inn/ARM/gcloak.c"),
this_object());
init_command("wear cloak");

set_level(18);
set_hp(450);
set_al(1000);
set_wc(26);
set_ac(15);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("Egwene says: Are you in need of my healing arts stranger?\n");
set_a_chat_chance(15);
  load_a_chat("The Wisdom traces a"+YELLOW+" symbol"+OFF+" in the air and scatters"+CYAN+" dust"+OFF+" from her bag.\n");

set_chance(10);
set_spell_dam(50);

set_spell_mess1(
  "Egwene traces a "+YELLOW+"symbol "+OFF+"in the air and "+CYAN+" blue lightning"+OFF+" flashes overhead. \n");
set_spell_mess2(
  "Egwene "+YELLOW+" traces a symbol in the air "+OFF+"and"+CYAN+" blue lightning"+OFF+" flashes overhead.  \n");
heal=clone_object("/players/fakir/inn/OBJ/dustheal.c");
move_object(heal,this_object());



}


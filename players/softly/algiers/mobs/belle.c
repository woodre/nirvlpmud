#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("belle");
  set_alt_name("madam");   
  set_alias("woman");
  set_long("\nBelle is a statuesque woman of indeterminate age who\n\
clearly takes pride in her appearance.  She wears a tight\n\
fitting black silk dress with long sleeves and a beaded\n\
bodice that shows her ample cleavage.  Her dark auburn\n\
hair is decorated with two long thin black feathers.  Her\n\
red lips curve into an inviting smile.\n");
  set_short("Belle");
  set_race("human");
  set_gender("female");
  set_level(15);
  set_al(0);
  set_aggressive(0);
  add_money(850+random(150));
  set_chat_chance(10);
  load_chat("Belle says: Welcome to my parlor.  Make yourself comfortable.\n");
  load_chat("Belle smiles: You know you're always welcome here.\n");
  load_chat("Belle remarks: My girls are always so happy to see you.\n");
}

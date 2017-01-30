/* Changed to barterable item 8/17/02 - Eurale  */

inherit "obj/treasure";
#define TP this_player()
#define ETP environment(this_player())
#include "/open/ansi.h"

reset(arg) {
  if(arg) return;

set_id("nail");
set_alias("brontosaurus nail");
set_short(HIW+"brontosaurus nail"+NORM);
set_long(
  "This thick brontosaurus nail is a favorite among scrimshaw\n"+
  "carvers.  They would pay a handsome price for a piece of\n"+
  "raw material like this.  Bartering will bring the highest price.\n");

set_weight(3);
set_value(4000);
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
num = 4800 + random(400);
if(!present("madame rue",ETP)) return;
if(str == "nail" || str == "brontosaurus nail") {
  write("Rue looks at you and spits in disgust...\n\n\n"+
      "She gently takes the huge brontosaurus nail.  She winks at you\n"+
      "and says, 'The scrimshaw carvers will pay a hefty price for a\n"+
      "piece this size.'  She tucks it away and hands you "+num+" coins\n"+
      "for your trouble.\n");
  TP->add_money(num);
  destruct(this_object());
  return 1; }
}

#include "/players/eurale/closed/ansi.h"
#define ETP environment(this_player())
#define TP this_player()
#define TPRN this_player()->query_real_name()
inherit "obj/armor";

reset(arg) {
set_name("scale");
set_alias("shadowscale");
set_short(BOLD+"Shadowscale"+NORM);
  set_long(
  "The scaley skin from a shadow dragon.  It still possesses some\n"+
  "kind of life from its owner but would bring a good price if it\n"+
  "were bartered.\n");

set_ac(4);
/* params added by illarion may 2005 */
set_params("magical",3,0,0);
set_params("other|dark",0,20,0);
set_params("other|light",0,-20,0);
set_type("armor");
set_weight(4);
set_value(2850 + random(1500));
set_no_clean(1);
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Talk"); add_xverb("'");
  add_action("Talk","say");
  add_action("Barter","barter");
}

Talk(str) {
if(worn_by) {
  say(BOLD+"Dragonslayer hisses: "+str+"\n"+NORM);
  write(BOLD+"Dragonslayer hisses: "+str+"\n"+NORM);
  return 1; }
}

Barter(str) {
if(str == "scale" || str == "shadowscale" && present("sedjak",ETP)) {
int coins;
coins = 4500 + random(500);
if(worn_by) {
  write("Sedjak whispers, 'Not while you're wearing it.'\n");
  return 1; }
write("Sedjak quickly grabs the beautiful shadowscale.  He shoves\n"+
      "it into his trunk while whispering, 'I've wanted one of\n"+
      "these a long time....' and he gives you "+coins+" coins.\n");
TP->add_money(coins);
destruct(this_object());
return 1; }
}

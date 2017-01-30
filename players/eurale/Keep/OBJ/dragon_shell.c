/* Values changed due to upgrade in level of the monster
completed by Pestilence per Dragnar 8-9-2014 */
#define TP this_player()
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("shell");
set_alias("dragon shell");
set_short(HIG+"Sea Dragon Shell"+NORM);
set_long(
  "This thick rugged shell came from the mighty sea dragon of the\n"+
  "Keep.  It is nearly impervious to damage and makes a very tough\n"+
  "body armor for whomever can wear it.  It is also a sought after\n"+
  "treasure by many.  All you need do is 'barter' it.\n");
set_ac(5);
set_type("armor");
set_weight(6);
set_value(3300);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int amt;
if(!str || !present("sedjak",ETP)) { write("What?\n"); return 1; }
if(str == "shell" || str == "dragon shell") {
  amt = (8000 + random(1500));
  write("Sedjak takes the dragon shell from you and gives you "+amt+" coins.\n");
  say("Sedjak takes something and hides it quickly.\n");
  TP->add_money(amt);
  destruct(this_object());
  return 1; }
}

wear(a) {
  int r;
if(id(a) && environment() == TP) {
  if(TP->query_extra_level() < 10) {
    write("You are not high enough level to utilize this armor!\n");
    return 1; }
  r = ::wear(a);
  }
return r;
}

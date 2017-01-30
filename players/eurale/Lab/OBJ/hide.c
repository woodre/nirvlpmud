#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("hide");
set_alias("bugbear hide");
set_short(YEL+"bugbear hide"+NORM);
set_long(
  "A yellow bugbear hide.  Pieces of meat still cling to the hide but\n"+
  "it is still valued by those who are willing to barter for it.\n");

set_weight(4);
set_value(1111 + random(222));
}

query_no_save() { return 1; }
init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int money;
if(str == "hide" || str == "bugbear hide") {
if(present("rue",ETP)) {
money = 3500 + random(800);
write("Madame Rue looks at you and then the bugbear hide.  She gives\n"+
      "a slight cackle and whispers, 'I'll take that off yer hands'\n"+
      "and gives you "+money+" coins for it.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
if(present("sedjak",ETP)) {
  write("Sedjak looks at the hide and grunts.  Then he snarls, 'I\n"+
        "have plenty of bugbear hides, better take that to Madame\n"+
        "Rue, I hear she's still buying them.'\n");
  return 1; }
}
}

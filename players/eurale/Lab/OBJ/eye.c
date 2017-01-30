#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
#define TP this_player()
#define TO this_object()

reset(arg) {
set_name("eye");
set_alias("catoblepas eye");
set_short(GRY+"hovering catoblepas eye"+NORM);
set_long(
  "The bloodshot eye of a catoblepas.  Through some magical means\n"+
  "it hovers in the air unassisted.  This magical item would surely\n"+
  "bring a high price to anyone who would barter it.\n");

set_ac(1);
set_type("misc");
set_weight(1);
set_value(1500);
set_no_clean(1);
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int coins;
if(!present("sedjak",environment(TP))) return 0;
  coins = 4750 + random(600);
if(str == "eye" || str == "catoblepas eye") {
  write("You push the hovering eye toward Sedjak.  He quickly grabs\n"+
        "it out of the air and stows it in his trunk.  He turns and\n"+
        "hands you "+coins+" coins as he whispers, 'Thanks!'\n");
  TP->add_money(coins);
  destruct(TO);
  return 1; }
}

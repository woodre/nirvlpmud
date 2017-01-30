#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define ETO environment(this_object())
#define TO this_object()
#define TP this_player()
int NUM;

reset(arg) {
  if(arg) return;
NUM = 2;

set_id("skin");
set_alias("toad skin");
set_short(HIR+"toad skin"+NORM);
set_long(
  "The poisonous skin from a giant toad.  It is red, dry, rough and\n"+
  "very warty.  Powerful potions require it, thus its value at the\n"+
  "local barter shop.  It can also be used to cure players who have\n"+
  "been infected by the poisonous owner with 'rubskin'.\n");

set_weight(1);
set_value(300 + random(100));
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
  add_action("Rubskin","rubskin");
}

Barter(str) {
int money;
if(!present("sedjak",ETP)) return 0;
if(str == "skin" || str == "toad skin") {
money = NUM * (3750 + random(600));
write("Sedjak gasps! He looks around the shop and opens the chest.\n"+
      "He motions for you to drop it into his chest and as you\n"+
      "finish, he slams the top closed and gives you "+money+" coins\n"+
      "for the valuable potion item.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
}

Rubskin(str) {
object ob;
if(!present("toadtox",ETO)) {
  write(HIR+"You rub your arms and legs with the skin and feel "+
        "nothing.\n"+NORM);
  NUM = NUM - 1;
  if(NUM == 0) destruct(this_object());
  return 1; }
ob = present("toadtox",ETO);
write(HIR+"You rub the toadskin all over your arms and legs and feel "+
      "much better.\n"+NORM);
destruct(ob);
NUM = NUM - 1;
if(NUM == 0) destruct(this_object());
return 1;
}

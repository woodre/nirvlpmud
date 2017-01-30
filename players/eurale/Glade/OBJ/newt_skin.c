#define tp this_player()
inherit "obj/treasure";
#define TP this_player()
#define ETP environment(this_player())

reset(arg) {
  if(arg) return;

set_id("newt skin");
set_alias("skin");
set_short("A large, dried newt skin");
set_long(
  "This is a large, dried-out skin from the spotted newt.  It is\n"+
  "rumored to have powerful medicinal powers.  In the hands of the\n"+
  "right person, it could be used to concoct amazing potions.  All\n"+
  "that need be done is to 'barter' for it's appropriate value.\n");

set_weight(1);
set_value(20 + random(10));
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
if(!present("madame rue",ETP)) { write("What?\n"); return 1; }
if(str == "skin" || str == "newt skin") {
int coins;
coins = 3800 + random(200);
write("Rue cackles and takes the spotted skin.  She looks it over...\n"+
      "She smiles a toothless grin and after some friendly bartering\n"+
      "she hands you "+coins+" coins for it...\n");
  TP->add_money(coins);
  destruct(this_object());
  return 1; }
}

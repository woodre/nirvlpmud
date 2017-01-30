#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
reset(arg) {
set_name("kong fur");
set_alias("fur");
set_short("Kong fur");
set_long(
  "This dusty, matted piece of King Kong's fur would make an excellent\n"+
  "cape for the needy adventurer or it could be 'barter'ed in for coins.\n");
set_ac(2);
set_type("misc");
set_weight(3);
set_value(3500);
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!present("sedjak",ETP)) return 0;
if(str == "kong fur" || str == "fur") {
  if(worn == 1) {
    write("You must remove your fur before you can barter it in!\n");
    return 1; }
  num = 4500 + random(500);
  write("Sedjak says, 'I see you've slain the mighty Kong, well done!'\n"+
        "He hands you "+num+" coins and then puts the dusty, stinky\n"+
        "fur in his trunk.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}

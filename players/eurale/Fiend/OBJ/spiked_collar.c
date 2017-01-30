#include "/players/eurale/closed/ansi.h"
#define ETP environment(this_player())
inherit "obj/armor";
reset(arg) {
set_name("spiked collar");
set_alias("collar");
set_short("Spiked leather collar");
set_long(
  "This black leather collar has a large buckle and pointed metal\n"+
  "spikes along it's entire length.  It can be worn or 'barter'ed.\n");
set_ac(1);
set_type("necklace");
set_weight(1);
set_value(1500);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!present("sedjak",ETP)) return 0;
if(str == "spiked collar" || str == "collar") {
  if(worn == 1) {
    write("You must remove your collar before you can barter it!\n");
    return 1; }
  num = 1950 + random(100);
  write("Sedjak snickers at your collar but gives you "+num+" coins.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}

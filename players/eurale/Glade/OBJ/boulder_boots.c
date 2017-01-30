#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("boulder boots");
set_alias("boots");
set_short("Boulder boots");
set_long(
  "These solid stone boots were cut from a single stone and shaped to\n"+
  "fit one's feet.  They provide superior armor or they can can be\n"+
  "bartered for their value.\n");

set_ac(2);
set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(4);
set_value(430);
set_arm_light(0);
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!str) { write("What?\n"); return 1; }
if(!present("sedjak",environment(this_player()))) return 0;
if(str == "boulder boots" || str == "boots") {
  if(worn == 1) {
    write("Sedjak whispers, 'You gotta take them off first, mate.'\n");
    return 1; }
  num = 4800 + random(150);
  write("Sedjak takes the heavy boots and grins.  He quickly hands you "+num+
       "\ncoins for these rare items.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}

#include "/players/eurale/closed/ansi.h"
#define ETP environment(this_player())
inherit "obj/armor";

reset(arg) {
set_name("skull helmet");
set_alias("skull");
set_short(CYN+"Skull helmet"+NORM);
set_long(
  "This blue, bone skull has been cut away to allow the wearer to\n"+
  "slip it over their head and peer through the eyeholes.  It must\n"+
  "have come from a huge creature as the bone is very thick.  It\n"+
  "can be worn or bartered for gold.\n");

set_ac(2);
set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(2);
set_value(4300);
set_arm_light(2);  /*  makes the armor glow with strength 2  */
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!present("sedjak",ETP)) return 0;
if(str == "skull helmet" || str == "skull") {
  if(worn == 1) {
    write("The skull helmet must be removed before it can be bartered.\n");
    return 1; }
  num = 4400 + random(150);
  write("You offer the blue skull helmet to Sedjak.  At first he seems\n"+
        "uninterested but then he grabs it and gives you "+num+" coins\n"+
        "from his pocket.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}

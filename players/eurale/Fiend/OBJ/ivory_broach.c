#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
reset(arg) {
set_name("ivory broach");
set_alias("broach");
set_short(HIW+"ivory broach"+NORM);
set_long(
  "This beautiful broach is made of ivory inlaid into a gold backing.\n"+
  "It is the intricately carved silouette of lady's head with a formal\n"+
  "hat.  All one need do is 'barter' it to find out its value.\n");
set_ac(1);
set_type("necklace");
set_weight(1);
set_value(2000);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!present("rue",ETP)) return 0;
if(str == "ivory broach" || str == "broach") {
  if(worn == 1) {
    write("You must remove your broach before you can barter it in!\n");
    return 1; }
  num = 2000 + random(100);
  write("Rue looks the broach over carefully and grins a toothless\n"+
        "grin.  She whispers to you, 'I've been waiting a long time\n"+
        "for one of these, thanks.'  And with that she slides "+num+"\n"+
        "coins in your money purse.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}

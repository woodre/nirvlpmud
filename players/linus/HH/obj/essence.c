inherit "/obj/treasure.c";
#include "/players/linus/def.h"
int mon;
string BLAH;
id(str) { return str == "essence" || str == "angel essence" || str=="crystal"
|| str=="crystalline"; }
reset(arg) {
  if(arg) return;
   BLAH = "HIW";
  set_long("  Essence is the very life force of a angel.  It is translucent which\n"+
  "means you can see through it, but can also tell it is there.  It is a\n"+
  "vaporous material, but freezes into a crystalline form when it comes\n"+
  "in contact with the ground.  It has been told that angelic essence\n"+
  "is used for spell components, as well as in the crafting of jewellry.\n"+
  "Those in the trade industry are always looking to barter for items\n"+
  "of this nature.\n");
  set_weight(1);
  set_value(500);
}
short() {
 return "Angel Essence "+BLAH+"["+HIW+"Crystalline"+BLAH+"]"+NORM; }
 init() {
  ::init();
add_action("pay_me_mofo","barter");
mon = (3000+random(2001));
}
pay_me_mofo(string str) { 
 if(id(str)) {
if(present("hank_the_ugly_barter_dude",ENV(TP))) {
  write("  Hank examines the crystal carefully.  He leans in to you\n"+
        "and whispers: The essence crystal of Celestia is a very\n"+
        "valuable item.  He then hands you "+mon+" coins.  'If you\n"+
        "get any more, be sure to see me!'\n");
      TP->add_money(mon);
      TP->add_weight(-1);
      destruct(TO);
        return 1;
   }
  }
  FAIL("Barter what?\n");
    return 0;
}

set_color(arg) { BLAH = arg; }

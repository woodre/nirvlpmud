#include <ansi.h>

inherit "obj/treasure";
reset(arg) {
  if(arg) return;

set_id("recall_orb");
set_alias("orb");
set_short(HIC+"Orb of Recall "+NORM+"("+WHT+"Market"+NORM+")");
set_long("A small, perfectly cut crystalline orb, the Orb of Recall can transport\n"+
         "anyone directly to the Bone Marketplace within the City of Qual'tor.\n"+
         "A series of runes cover the magical device.\n");
set_weight(1);
set_light(1);
set_value(175);
}

init() {
  add_action("read_runes","read");
  add_action("market_return","recall_me");
}

read_runes(str) {
if(!str) {write("What do you want to read?\n");  return 1; }

if(str == "runes" || str == "orb" || str == "recall orb") {
write("The Orb of Recall, fashioned by Xion in the Bone Marketplace.\n"+
      "To return to the market, the command is <"+HIR+"recall_me"+NORM+">\n");
return 1; }
return 0;
}

market_return() {
write("There is a flash of bright light, and you find yourself in the Bone Market.\n");
/*
say("A blinding flash of light occurs, and "+this_player()->query_name()+" is gone.\n");
*/
  this_player()->move_player("in a blinding flash of light#players/daranath/qualtor/newstuff/bone_market.c");
destruct(this_object());
return 1;
}


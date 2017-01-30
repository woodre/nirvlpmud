#include "/players/feldegast/defines.h"
#include "/players/feldegast/log/logs.h"
short() {
  return "The Skybeast";
}
id(str) {
  return str=="skybeast"||str=="beast";
}
long() {
  write(
"This huge beast hovers above the jungle, keeping an eye out for\n"+
"would-be intruders.  It's mottled grey skin seems to absorb light\n"+
"as it passes in front of the sun, its batlike wings spreading a\n"+
"shadow across the jungle.  Its hideous head is scarred and red,\n"+
"a glowing red liquid dripping from its mouth burning even the\n"+
"beast itself.\n"
  );
}
init() {
  add_action("block","east");
}
block() {
  object ob;
  ob=present("quest_snake_armor",this_player());
  if(ob && TP->query_guild_name()=="cyberninja") {
    write(
"You wrap the snakeskin armor around your cybernetic implants before running\n"+
"down the path beneath the Skybeast.  The Skybeast rains "+HIR+"JELLY-FIRE"+NORM+" down upon\n"+
"you.  It seeths, bubbles, and burns, but you manage to make your way\n"+
"to safety.\n"
    );
    passed();
    return 0;
  }
  if(ob && TP->query_guild_name()=="rangers") {
    write("You wrap the snakeskin armor around yourself before running\n"+
"down the path beneath the Skybeast.  The Skybeast rains "+HIR+"JELLY-FIRE"+NORM+" down upon\n"+
"you.  It seeths, bubbles, and burns, but you manage to make your way\n"+
"to safety.\n"
    );
    passed();
    return 0;
  }
  if(ob && ob->query_owner() == this_player()->query_name()) {
    write(
"You tighten and cinch every strap on your snakeskin armor before running\n"+
"down the path beneath the Skybeast.  The Skybeast rains "+HIR+"JELLY-FIRE"+NORM+" down upon\n"+
"you.  It seeths, bubbles, and burns, but you manage to make your way\n"+
"to safety.\n"
  );
    passed();
    return 0;
  }
  write(
"The Skybeast sprays its "+HIR+"JELLY-FIRE"+NORM+" upon you from above.  On\n"+
"contact, the gelatinous substance burns skin and hair.  Fleeing further\n"+
"damage, you run back the way you came.\n"
  );
  return 1;
}
passed() {
#ifdef PATHLOG
  write_file(PATHLOG,ctime(time())+" "+TPN+" passed the Skybeast.\n");
#endif
}

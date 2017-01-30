#define ENVQN environment()->query_name()
#include "/players/linus/def.h"
inherit "/obj/treasure";
object skel;
id(str) { return str=="pile" || str=="bones" || str=="linus_bones"; }
reset(arg) {
 if(arg) return;
 set_short("A pile of bones");
 set_long(
 "The bones look humanoid in nature, and judging from the dust and\n"+
 "debris covering them, have been here for some time.  One of the \n"+
 "leg bones is snapped in half, revealing the cause of this creatures\n"+
 "demise.  Upon closer inspection, you see something under the pile.\n"+
 "Maybe you could move the bones to to see what it is.\n");
 set_weight(10000);
 set_value(0);
}
get() { return 0; }
init() {
 ::init();
 add_action("uh_oh","move");
}
uh_oh(str) {
 object me;
 if(!str || str!="bones") { NF("Move what?\n"); return 0; }
 write("\nYou reach down to move the bones...\n\n\n"+
       "    Suddenly the bones move, and a skeletal hand grabs you!\n\n\n"+
       "       The bones start coming together...\n"+
       "       A skeleton grabs the "+RED+"rusty"+NORM+" sword and rises.\n\n");
 me = this_player();
 say("\n"+TPN+" reaches down to move the bones...\n\n\n"+
       "    Suddenly the bones move, and a skeletal hand grabs "+TPO+"!\n\n\n"+
       "       The bones start coming together...\n"+
       "      A skeleton grabs the "+RED+"rusty"+NORM+" sword and rises.\n\n");
 skel = CO("players/linus/Plains/NPC/g_skel.c");
 MO(skel,environment(TP));
 MO(TO,"/room/void");
 command("look",me);
 destruct(TO);
 return 1;
}

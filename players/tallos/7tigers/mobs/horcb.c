inherit "/obj/monster.c";
#include "/obj/ansi.h"
#define tpn this_player()->query_name()

object chain;
reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name(RED+"The Half-Orc Brute"+NORM);
  set_alias("brute");
  set_race("orc");
  set_short(BOLD+RED+"The Half-Orc Brute"+NORM);
  set_long(
    "  This huge hulking beast is the half-orc brute.  He\n"+
    "wields a huge spiked chain and swings it around like\n"+
    "its nothing!\n");
  
  add_money(3000);
  chain = clone_object("/players/tallos/7tigers/objects/mcspiked.c");
  move_object(chain, this_object());
  command("wield chain", this_object());  
  set_level(19);
  set_hp(750);
  set_al(-1000);
  set_ac(22);
  set_wc(31);
  set_aggressive(0);
  set_armor_params("other|physical",0,3,0);
  set_chat_chance(10);
  load_chat("The brute says, \"What the #%$& do you want?\"\n");
  load_chat("The brute looks at you and grinds his teeth.\n");
  load_chat("The brute says, \"You wanna fight? Lets do it!\"\n");
  load_chat("The brute says, \"Heh, your weapon #%$&ing sucks!\"\n");
  add_spell("Rage",
  "#MN# starts to foam at the mouth as he:\n"+
  " \n"+
  "                  "+HIR+" R A G E S!!!!"+NORM+"\n"+
  " \n",
  "            #MN# goes into a "+HIR+"R A G E!!!"+NORM+"\n",
    20,50,"other|physical");
}

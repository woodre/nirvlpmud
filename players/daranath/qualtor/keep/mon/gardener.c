inherit "/obj/monster";

#include "/players/saber/closed/esc.h"
#include <ansi.h>

reset(arg) {
 object ob, gold;
   ::reset(arg);
   if (!arg) {

set_name("Dark Gardener");
set_short("A frail old man is bent over the flowers");
set_alias("man");
set_alt_name("old man");
set_race("human");
set_gender("male");
set_long("The old man completly ignores you while he goes about his work here within\n"+
         "the garden. A strong looking quarterstaff lies next to him,\n"+
         "always within reach. He glances over in your direction.\n");
set_level(15);
set_ac(12);
set_wc(16 + random(10));
set_hp(200 + random(100));
set_al(-1000);
set_aggressive(0);
set_chat_chance(8);
load_chat("The old man grumbles something about getting out of his garden.\n");
load_chat("The old man growls at you while you are within his garden.\n");
load_chat("A sinister feeling lies about the garden here.\n");
load_chat("The old man turns to face you, his eyes glowing softly.\n");

gold = clone_object("obj/money");
gold->set_money(random(380)+500);
move_object(gold,this_object());
ob = clone_object("/players/daranath/qualtor/keep/wep/ironwood.c");
move_object(ob,this_object());
init_command("wield staff");
   }
  }


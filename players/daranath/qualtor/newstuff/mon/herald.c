#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

set_name("Herald of Qual'tor");
set_short("The Herald of Qual'tor");
set_alias("herald");
set_alt_name("citymon");
set_race("human");
set_gender("male");
set_long("A tall, yet robust individual, the Herald of Qual'tor generally stays\n"+
         "here to help those new or adventuring within the city. \n"+
         "Type <"+HIW+"info"+NORM+"> for a list of ways the Herald can help.\n");
set_level(17);

set_ac(18);
/* High Ac and Wc for level 17 mon */
set_wc(24 + random(6));
set_hp(320 + random(40));
set_al(750);
set_aggressive(0);

set_chat_chance(12);
load_chat("The Herald says: Welcome to Qual'tor!\n");
load_chat("The Herald says: Welcome to Qual'tor!\n");
load_chat("The Herald says: Ask me for help, I can offer plenty of advice.\n");
load_chat("The Herald says: Qual'tor is coming back from the dead, mark my words.\n");
load_chat("The Herald says: Qual'tor needs plenty of help driving the evil from the city.\n");
load_chat("The Herald carefully arranges the messages on the board.\n");
   }
}

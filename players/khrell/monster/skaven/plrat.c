#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name(GRN+"Plague"+YEL+" rat"+NORM);
  set_alt_name("plague");
  set_alias("rat");
  set_short(GRN+"Plague"+YEL+" rat"+NORM);
  set_long(
"   The plague rats are vessels that the Clan Pestilens uses to spread\n"+
"their diseases.\n");  
  set_race("rat");
  set_level(5);
  set_wc(30);
  set_ac(10);
  set_hp(20);
  set_al(-1000);
  set_aggro(1, 50, 100);  

  set_a_chat_chance(10);
load_a_chat("The rat squeaks madly.\n");

  set_chance(10);
  set_spell_dam(5);
  set_spell_mess1( 
"The rat bites and scratches at your face in a frenzy!\n");

  set_spell_mess2(
"The rat attacks in a mad frenzy!\n");

  set_multi_cast(0);
  
  add_spell("bad bite",
"The rat sinks it's frothing fangs into your arm!\n",
"The rat bits it's foe!\n",
10,({10,10}),({"physical","other|poison"}));  

}

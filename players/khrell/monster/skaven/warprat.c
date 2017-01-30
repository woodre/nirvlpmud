#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name(YEL+"warped rat"+NORM);
  set_alt_name("warped");
  set_alias("rat");
  set_short(YEL+"Warped rat"+NORM);
  set_long("\
This rat has seen better times.  It's fur is mange covered and soiled\n\
with blood and various offal.  It has a lean predatory look in it's  \n\
near beastial eyes, and is the size of a average canine.\n");
  set_gender("male");
  set_race("rat");
  set_level(18);
  set_wc(30);
  set_ac(10);
  set_hp(200);
  set_al(0);
set_aggressive(1);
  add_money(1000);  

set_chat_chance(10);
load_chat("The rat twitches it's haggard whiskers.\n");
load_chat("Maddening chittering echoes loudly.\n");
load_chat("The rat gnaws on something unidentifiable.\n");

set_a_chat_chance(10);
load_a_chat("The rat squeaks madly.\n");

  set_chance(10);
set_spell_dam(40);
set_spell_mess1( 
"The rat bites and scratches at your face in a frenzy!\n");

set_spell_mess2(
"The rat attacks in a mad frenzy!\n");

gold = clone_object("obj/money");
gold->set_money(300);
move_object(gold,this_object());
}

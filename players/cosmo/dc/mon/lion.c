#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("lion");
set_alias("lion");
set_alt_name("guardian");
set_race("creature");
set_short("Lion Guardian");
set_long(
  "A beautiful golden lion that was brought to life by\n"+
  "your touch.   This lion doesn't act quite like Simba\n"+
  "though.  It's a mean, ferocious guardian that attacks\n"+
  "anything near him.  You may regret bringing it to life.\n");

set_level(18);
  set_hp(425+random(50));
  set_al(-200);
  set_wc(30);
  set_ac(10);
  set_heal(3,20);
  set_aggressive(1);
  set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("The lion paces back and forth in your path. \n");
set_a_chat_chance(10);
  load_a_chat("The lion  "+RED+"R O A R S"+NORM+"  with rage. \n");

set_chance(10);
set_spell_dam(30);

set_spell_mess1(
  "\n"+
  "The lion  "+GRN+"L E A P S"+NORM+"  into the air and pounces "+
  "on his prey.\n");
set_spell_mess2(
  "\n"+
  "You shrink back in utter  "+BLU+"F E A R"+NORM+"  as the lion "+
  "bounds on top of you.\n");

gold = clone_object("obj/money");
gold->set_money(950+random(50));
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
	"The lion's soul is freed as it  "+YEL+"M E L T S"+NORM+
        "  back into a golden form.\n");
return 0; }


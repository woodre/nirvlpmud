#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"
inherit "obj/monster.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

set_name("caterchipillar");
set_alias("creature");
set_race("caterpillar");
set_gender("creature");
set_short(HIM + "C" + OFF + HIW + "a" + OFF + HIB + "t" + OFF + HIC + "e" + OFF + HIY +
		  "r" + OFF + HIR + "c" + OFF + HIG + "h" + OFF + HIM + "i" + OFF + HIW + "p" +
		  OFF + HIB + "i" + OFF + HIC + "l" + OFF + HIY + "l" + OFF + HIR + "a" + OFF +
		  HIG + "r" + OFF);
set_long(
	"This is a very large type of caterpillar.  Carnivorous, it feeds on\n" +
	"various small animals in the forest.  The web from a caterchipillar is\n" +
	"said to contain petrifying powers, so be wary.  Its teeth and jaws \n" +
	"are powerful enough to crush its prey.\n");

set_level(14);
set_hp(210);
set_al(10 - random(20));
set_wc(18);
set_ac(11);
set_heal(4,20);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(3);
load_chat("The Caterchipillar wriggles along forest floor.\n");
set_a_chat_chance(10);
load_a_chat(HIM + "C" + OFF + HIW + "a" + OFF + HIB + "t" + OFF + HIC + "e" + OFF + HIY +
		    "r" + OFF + HIR + "c" + OFF + HIG + "h" + OFF + HIM + "i" + OFF + HIW + "p" +
		    OFF + HIB + "i" + OFF + HIC + "l" + OFF + HIY + "l" + OFF + HIR + "a" + OFF +
		    HIG + "r" + OFF + CYN + " leaps at you and sinks its teeth in, biting hard!\n" + OFF);

set_chance(15);
set_spell_dam(15 + random(5));
set_spell_mess1(
	 HIM + "C" + OFF + HIW + "a" + OFF + HIB + "t" + OFF + HIC + "e" + OFF + HIY +
	 "r" + OFF + HIR + "c" + OFF + HIG + "h" + OFF + HIM + "i" + OFF + HIW + "p" +
	 OFF + HIB + "i" + OFF + HIC + "l" + OFF + HIY + "l" + OFF + HIR + "a" + OFF +
	 HIG + "r" + OFF + CYN + " spits a web around its attacker.\n" + OFF);

set_spell_mess2(
	 HIM + "C" + OFF + HIW + "a" + OFF + HIB + "t" + OFF + HIC + "e" + OFF + HIY +
	 "r" + OFF + HIR + "c" + OFF + HIG + "h" + OFF + HIM + "i" + OFF + HIW + "p" +
	 OFF + HIB + "i" + OFF + HIC + "l" + OFF + HIY + "l" + OFF + HIR + "a" + OFF +
	 HIG + "r" + OFF + CYN + " wraps you in a cocoon, paralyzing you!\n" + OFF);
}

monster_died()
{
	move_object(clone_object("/players/laera/balamb/forests/obj/web.c"),
      environment(this_object()));
   	tell_room(environment(this_object()),
     CYN+"Writhing in agony, the " + OFF + HIM + "C" + OFF + HIW + "a" + OFF + HIB +
     "t" + OFF + HIC + "e" + OFF + HIY + "r" + OFF + HIR + "c" + OFF + HIG + "h" +
     OFF + HIM + "i" + OFF + HIW + "p" + OFF + HIB + "i" + OFF + HIC + "l" + OFF +
     HIY + "l" + OFF + HIR + "a" + OFF + HIG + "r" + OFF + CYN +
     " falls to the ground and dies.\n"+OFF);

   return 0;
}

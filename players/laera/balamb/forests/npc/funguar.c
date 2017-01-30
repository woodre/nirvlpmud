#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"
inherit "obj/monster.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

set_name("funguar");
set_alias("creature");
set_race("fungus");
set_gender("creature");
set_short(HIR + "F" + OFF + HIY + "u" + OFF + HIR + "n" + OFF +
	HIY + "g" + OFF + HIR + "u" + OFF + HIY + "a" + OFF + HIR + "r" + OFF);
set_long(
	"Mushroom-like, this fungus is actually a living creature.  It is \n" +
	"rooted the the ground and looks like a colourful toadstool.  Funguar\n" +
	"attacks by sending acidic spores over its prey as it gets closer, \n" +
	"lured in by the attractive patterns of Funguar's body.\n");

set_level(12);
set_hp(180);
set_al(10 - random(20));
set_wc(16);
set_ac(9);
set_heal(4,20);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(3);
load_chat("Funguar tries to blend in with the trees.\n");
set_a_chat_chance(10);
load_a_chat(HIR + "F" + OFF + HIY + "u" + OFF + HIR + "n" + OFF +
	        HIY + "g" + OFF + HIR + "u" + OFF + HIY + "a" + OFF +
	        HIR + "r" + OFF + HIY + " shakes, sending acidic spores all over you!\n" + OFF);

set_chance(15);
set_spell_dam(10 + random(5));
set_spell_mess1(
	HIR + "F" + OFF + HIY + "u" + OFF + HIR + "n" + OFF +
	HIY + "g" + OFF + HIR + "u" + OFF + HIY + "a" + OFF +
	HIR + "r" + OFF + HIY + " butts his head into his attacker's stomach.\n" + OFF);

set_spell_mess2(
	HIR + "F" + OFF + HIY + "u" + OFF + HIR + "n" + OFF +
	HIY + "g" + OFF + HIR + "u" + OFF + HIY + "a" + OFF +
	HIR + "r" + OFF + HIR + " butts his head into your stomach.  OOF!!\n" + OFF);
}

monster_died()
{
	move_object(clone_object("/players/laera/balamb/forests/obj/mstpiece.c"),
      environment(this_object()));

   	tell_room(environment(this_object()),
   	HIR + "F" + OFF + HIY + "u" + OFF + HIR + "n" + OFF +
	HIY + "g" + OFF + HIR + "u" + OFF + HIY + "a" + OFF +
	HIR + "r" + OFF + HIY+" shrivels up and withers away.\n"+OFF);

   return 0;
}

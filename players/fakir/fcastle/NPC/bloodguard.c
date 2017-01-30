#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("bloodguard");
set_alias("guard");
set_race("undead");
set_short(RED+"Bloodguard"+OFF);
set_long(
  "   Bound by oath to never die unless in defense of the castle,\n"+
  "this "+RED+"Bloodguard"+OFF+" has lived many centuries, and seen many a battle.\n"+
  "His skills remain as sharp as ever.  His eyes fill with blood as\n"+
  "he watches and waits for your next move.\n");

set_level(20);
set_hp(400+random(200));
set_al(0);
set_wc(60+random(20));
set_ac(14+random(6));
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("The "+RED+"Bloodguard"+OFF+" neither breaths nor blinks...he only waits.\n");
set_a_chat_chance(15);
  load_a_chat("The "+RED+"Bloodguard"+OFF+" barely moves, or so it seems, but his weapon skims your arm.\n");
  load_a_chat("Shifting only slightly, the "+RED+"Bloodguard"+OFF+" blocks your attack.\n");
  load_a_chat("In a single movement, the "+RED+"Bloodguard"+OFF+" feints left and bloodies your cheek.\n");

set_chance(20);
set_spell_dam(30);

set_spell_mess1(
  "The "+RED+"Bloodguard"+OFF+" moves so fast you eyes fail to follow, but your arm goes limp.\n");
set_spell_mess2(
  "Blood drips from your scalp and clouds your vision...you reel in agony.\n");

}

monster_died() {
  move_object(clone_object("/players/fakir/fcastle/OBJ/blooddust.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
	"The "+RED+"Bloodguard"+OFF+" dies at last and his body crumbles into dust.\n");
return 0; }

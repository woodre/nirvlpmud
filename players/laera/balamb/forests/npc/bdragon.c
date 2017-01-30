#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"
inherit "obj/monster.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

set_name("blue dragon");
set_alias("creature");
set_race("dragon");
set_gender("creature");
set_short(BLU + "Blue Dragon" + OFF);
set_long(
	"Standing tall on its hind legs, this dragon is the color of midnight.\n" +
	"Its yellow eyes glare out from beneath wide lids.  Its nostrils flare\n" +
	"letting out puffs of white smoke with each breath.  Huge talons grace\n" +
	"its feet, razor sharp, and ready to slice into its next victim.\n");

set_level(18 + random(3));
set_hp(450 + random (150));
set_al(10 - random(50));
set_wc(26 + random (4));
set_ac(15);
set_heal(4,20);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(3);
load_chat("The Blue Dragon breathes softly, singeing the nearby leaves.\n");
set_a_chat_chance(10);
load_a_chat(BLU + "Blue Dragon breathes fire, burning everything in the path of its flame.\n" + OFF);

set_chance(20);
set_spell_dam(30 + random(30));
set_spell_mess1(
     BLU + "Blue Dragon aims a steady stream of fire at his attacker.\n" + OFF);
set_spell_mess2(
     BLU + "Blue dragon burns you with a burst of hot fire.\n" + OFF);
}

monster_died()
{
	move_object(clone_object("/players/laera/balamb/forests/obj/dskin.c"),
      environment(this_object()));

   	tell_room(environment(this_object()),
     BLU+"With a final roar, the Blue Dragon falls to the ground, dead.\n"+OFF);
   return 0;
}

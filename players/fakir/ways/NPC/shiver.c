#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("shiver");
set_race("spirit");
set_short("A Cold Shiver");
set_long(
  "A tangible presence of chilling cold, drawn from the shadows\n"+
  "of the ways by fear and hesitation.  It looks harmless, but\n"+
  "looks can be deceiving in the ways.\n");

set_level(10);
set_hp(150 +random(50));
set_al(-400);
set_wc(14);
set_ac(8);
set_aggressive(1);
set_dead_ob(this_object());
add_money(400 +random(100));

set_chat_chance(10);
  load_chat("You feel a deep chill in the marrow of your bones.\n");
  load_chat("The air bites your lungs with crystal shards as you breath.\n");
  load_chat("The Shiver probes you with icy fingers...searching...searching...\n");
  load_chat("Your mind grows hazy from the numbing cold, and your vision begins to blur.\n");
set_a_chat_chance(15);
  load_a_chat("The Shiver whispers: 'Your fears have summoned me here. You called...I came.\n");
  load_a_chat("The Shiver hisses: 'You will never leave this place. It will consume you.\n");
  load_a_chat("The Shiver impales you with an icy finger.\n");

set_chance(20);
set_spell_dam(20);

set_spell_mess1(
  "The Shiver gathers the chill from the air and points its finger.\n");
set_spell_mess2(
  "The Shiver gathers the chill from the air and *POINTS* to your heart.\n");

}

monster_died() {
    tell_room(environment(this_object()),
	"The Shiver warms and dies, dropping to the ground.\n");
return 0; }

#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("random");
set_alias("man");
set_alt_name("prince");
set_race("human");
set_short("Prince Random");
set_long("A wily-looking man, with a sharp nose and laughing mouth.  His\n"+
"hair is straw colored and he is dressed in a Renaissance costume\n"+
"of orange, red, and brown.  He wears a long tunic and an attached\n"+
"trimmed cape with a tight-fitted embroidered doublet.  A small\n"+
"sword is attached to his belt.\n");
  
set_gender("male");
set_level(8);
   set_hp(120);
   set_wc(12);
   set_ac(7);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());

set_chat_chance(5);
load_chat("Random exclaims.  They are here!\n");
load_chat("Random says:  They crawled out of the shadows.\n");
load_chat("Random says:  All the roads lead to Amber.\n");

/*set_chance(15);
 *  set_spell_dam(30);

*set_spell_mess1(
*"The prince slaps it's opponent across the face hard.\n");
*set_spell_mess2(
*"The prince slaps you across the face hard.\n");*/
  
   gold = clone_object("obj/money");
gold->set_money(350);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The prince curses you, then dies.\n");
   return 0; }
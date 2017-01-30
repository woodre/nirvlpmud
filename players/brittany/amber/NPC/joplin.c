#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("joplin");
set_alias("man");
set_alt_name("keeper");
set_race("human");
set_short("Joplin of Cabra");
set_long("A man about five and a half feet tall.  His beard is long and it\n"+
"is the color of smoke.  His lips are dry-lookin and his skin is\n"+
"as porous as an orange rind.  He has dark eyes and his breath\n"+
"reeks of wisky.n");

set_gender("male");
set_level(8);
   set_hp(120);
   set_wc(12);
   set_ac(7);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());

set_chat_chance(5);
load_chat("Joplin asks:  Can I help you?\n");
load_chat("Joplin asks:  Why do you come here?\n");
load_chat("Joplin asks:  Who are you?\n");
 
   gold = clone_object("obj/money");
gold->set_money(350);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "Joplin crys and drops to the ground.\n");
   return 0; }
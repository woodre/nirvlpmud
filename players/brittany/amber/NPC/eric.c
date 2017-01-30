#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("eric");
set_alias("man");
set_alt_name("prince");
set_race("human");
set_short("Lord Eric");
set_long("A handsome man, his hair is so dark it almost look blue.\n"+
"His beard curls around the mouth, and he is dressed in a\n"+
"leather jacket, leggings, a plain cloak and high black boots.\n"+
"He is wearing the colors black, red, and silver.  His red\n"+
"sword belt is bearing a long silvery saber and clasped with a\n"+
"ruby.  His high cloak collar round his head is lined with red,\n"+
"which matches the trimmings of his sleeves.  A pair of black\n"+
"gloves are jutted from the belt near his right hip.\n");
set_gender("male");
set_level(12);
   set_hp(180);
   set_wc(16);
   set_ac(9);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Eric exclaims.  You want the throne?\n");
load_chat("Eric says:  Slay me, and the throne is yours.\n");
load_chat("Eric says:  Try it.  I don't think you will succeed.\n");
load_chat("Eric says:   You're a fool to have come here.\n");
 
   gold = clone_object("obj/money");
gold->set_money(550);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The coldness sweeps the room as the prince falls dead.\n");
   return 0; }
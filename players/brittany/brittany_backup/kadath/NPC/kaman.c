#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
set_name("kaman");
   set_alias("man");
   set_alt_name("priest");
   set_race("human");
set_short("An Elderly Priest");
set_long("An elderly bearded priest, overseer of the caverns of fire.\n"+
"His long red robe is trimmed in gold.  He wears a golden\n"+
"medallion around his neck which is engraved with a symbol\n"+
"known from the mendicant orders.\n");
   set_gender("male");
set_level(15);
set_hp(225);
set_wc(20);
set_ac(12);
set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
   set_chat_chance(5);
load_chat("Priest exclaims. Ah, unknown Kadath, In our dreamland, the city\n"+
"might be reached.\n");
load_chat("Priest says:  Only three human souls since time began ever crossed\n"+
"and recrossed the land.\n");
load_chat("Priest says:  Of the three, two returned quite mad.\n");
load_chat("Priest says:  Descend the steps if you are brave, enter the peril\n"+
"of confusing.\n");
   
   set_chance(15);
   set_spell_dam(30);

set_spell_mess1(
"The priest slaps it's opponent across the face hard.\n");
set_spell_mess2(
"The priest slaps you across the face hard.\n");
   
   gold = clone_object("obj/money");
gold->set_money(875);
   move_object(gold,this_object());
}

monster_died() {
   tell_room(environment(this_object()),
"A slight cry is heard on his last breathe\n");
   return 0; }

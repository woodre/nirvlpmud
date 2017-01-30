#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("caine");
set_alias("man");
set_alt_name("prince");
set_race("human");
set_short("Lord Caine");
set_long("A dark-eyed swarthy looking man, dressed all in satin that\n"+
"is black and green.  He is wearing a dark three-cornered hat\n"+ 
"set at a stylish angle, a green plume of feathers are trailing\n"+
"down his back.  He is standing in profile, one arm akimbo, and\n"+
"the toes of his boots curled upwards.  He wears an emerald-\n"+
"studded dagger at his belt.\n");
set_gender("male");

set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Caine exclaims. Surrender, I got you outnumbered!\n");
load_chat("Caine says:  Lay down your arms.\n");
load_chat("Caine says:  One day I will praise you.\n");
   
   gold = clone_object("obj/money");
gold->set_money(450);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The prince curses you, then dies.\n");
   return 0; }
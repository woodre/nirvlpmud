#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("gerard");
set_alias("man");
set_alt_name("prince");
set_race("human");
set_short("Lord Gerard");
set_long("A big powerful looking man, with a fringed beard and a light\n"+
"mustache.  He is wearing a dressing gown of blue and gray clasped\n"+
"about the middole with a wide, black belt.  Around his neck on a\n"+
"heavy cord there hangs a silver hunting horn. \n");
set_gender("male");

set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Gerard exclaims.  He has been stabbed!\n");
load_chat("Gerard says:  Step back or I'll kill you.\n");
load_chat("Gerard grabs an ax and runs towards you.\n");
   
   gold = clone_object("obj/money");
gold->set_money(450);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The prince swears, then dies.\n");
   return 0; }

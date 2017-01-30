#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("brand");
set_alias("man");
set_alt_name("prince");
set_race("human");
set_short("Lord Brand");
set_long("A petite beardless man with green eyes and dark hair.  He\n"+
"is wearing a riding suit of green, with black boots.  A\n"+
"small sword is attached to a belt around his waist.\n");
set_gender("male");

set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Brand exclaims.  Help me!\n");
load_chat("Brand says:  Deliver me from this place.\n");
load_chat("Brand says:  Anything you name shall be yours in return.\n");
   
   gold = clone_object("obj/money");
gold->set_money(450);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The prince screams a tormented squeak as he falls dead.\n");
   return 0; }
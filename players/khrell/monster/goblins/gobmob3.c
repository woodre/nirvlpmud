#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
   set_name("goblin");
   set_alt_name("guard");
   set_alias("night goblin");
   set_short("A"+HIK+" Night"+NORM+HIG+" Goblin Guard"+NORM);
   set_long( "This is an elite night goblin.  Usually given positions of power in the\n\
warlords retinue based on cruelty or just the ability to drink heavily.\n");
   set_gender("male");
   set_race("goblin");
   set_level(15);
move_object(clone_object("/players/khrell/armors/goblins/gobshield.c"));
move_object(clone_object("/players/khrell/armors/goblins/gobrobe.c"));
init_command("wear shield");
init_command("wear robe");   
   set_ac(12);
move_object(clone_object("/players/khrell/weapons/goblins/gobsword.c"));
init_command("wield sword");  
   set_wc(14);
   set_hp(220);
   set_al(-400);
   set_aggressive(2);
   add_money(100);  

 set_chat_chance(10);
   load_chat("The goblin sneers at you with hate filled eyes.\n");
   
 set_a_chat_chance(10);
   load_a_chat("The goblin bites you with it's sharp teeth!\n");
     set_chance(10);
   set_spell_dam(5);
   set_spell_mess1( 
   "The goblin wails a piercing battle cry!\n");
   
   set_spell_mess2(
   "The goblin kicks you in the shin!\n");
   
gold = clone_object("obj/money");
gold->set_money(25);
move_object(gold,this_object()); 
}   

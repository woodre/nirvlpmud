#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("monster");
   set_short("A big monster");
   set_race("monster");
   set_long("A big scary monster\n");
   set_level(50);
   set_ac(20);
   set_wc(0);
   set_hp(1);
   set_al(0);
   /* If agressive is 1, than the monster will attack others
   even before it is attacked     */
   set_aggressive(0);
   set_chat_chance(0);
   /* The chance per heartbeat that the monster is IN COMBAT
   that it will call a load_a_chat()     */
   set_a_chat_chance(0);
   
   load_chat("The monster tries to scare you\n");
   load_chat("The monster tries to scare you again\n");
   load_a_chat("The monsters tries to attack you harder\n");
   load_a_chat("The monsters tries to attack you harder again\n");
   
   set_chance(0);
   set_spell_dam(0);
   
   set_spell_mess1("This is an attack emote\n");
   set_spell_mess2("This is another attack emote\n");
   move_object(clone_object("/players/puppy/EX/armor.c"), this_object());
   init_command("wear armor");
   move_object(clone_object("/players/puppy/EX/wep.c"), this_object());
   init_command("wield weapon");
   move_object(clone_object("/players/puppy/EX/item.c"), this_object());
   
   gold = clone_object("obj/money");
   gold->set_money(100);
   move_object(gold,this_object());
   
}

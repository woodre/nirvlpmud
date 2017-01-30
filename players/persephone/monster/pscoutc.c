inherit "obj/monster";
#include "/players/persephone/rooms.h"
object gold;
reset(arg) {
 ::reset();
  if (arg) return;
   gold = clone_object("obj/money");
   gold->set_money(700);
   move_object(gold, TOB);
   set_name("guard");
   set_alias("pirate");
   set_level(13);
   set_al(-100);
   set_short("A pirate guard");
   set_long("One of the famed advance guards of Jeny.\n"+
            "You wonder why you see him so far away from his master.\n"); 
   set_hp(195);
   init_command("wield cutlass");
   set_wc(17);
   set_ac(10);
   set_aggressive(0);
   set_chance(5);
   set_spell_dam(5);
   set_spell_mess1("Skillfully thrusts his cutlass.\n");
   set_spell_mess2("Strikes you with a sudden slice of his cutlass\n");
   set_chat_chance(25);
   set_a_chat_chance(20);
   load_chat("Jeny's Guard charges Vvladimirs forces.\n");
   load_chat("Jeny's Guard shouts: Vvladimir will betray you like he betrayed us.\n");
   load_chat("Jeny's Guard states: This is our town now\n");
   load_a_chat("Jeny's Guard screams: You cannot clear this town\n");
   load_a_chat("Jeny's Guard scoffs: So you work for Vvladimir do you\n");
   load_a_chat("Jeny's Guard giggles inanely\n");
 }

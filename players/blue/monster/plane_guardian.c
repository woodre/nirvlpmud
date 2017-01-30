inherit"obj/monster";
#include "/players/beck/MortalKombat/MKQuestNPC.h"

   object wep, coins;

reset(arg) {
   
   ::reset(arg);

   if(!arg) {

   set_level(15);
   set_name("Plane Warrior");
   set_alias("warrior");
   set_short("A Warrior of the Planes");
   set_long(
"This is a mighty warrior who guards these planes from those seeking\n"+
"treasure.  He is dressed in complete blackness and stares at you with silent "+
   "\nintesnsity.\n");
   
   set_level(15);
   set_wc(20);
   set_ac(12);
   set_hp(225);
   
   wep=clone_object("players/blue/weapons/obsidian_sword.c");
   move_object(wep, this_object());
   set_chat_chance(30);
   set_a_chat_chance(30);
   
   load_chat("The great warrior looks down at you.\n");
   load_chat("The warrior begins to chant.\n");
 load_a_chat(capitalize(this_object()->query_name()) + " lets out a war cry.\n");
   load_a_chat(capitalize(this_object()->query_name()) + " scowls.\n");
  move_object(clone_object("/players/dragnar/MKScar/scar"),this_object());
   
   }
}

#define TP this_player()
#define TO this_object()
#define TPN capitalize(TP->query_name())
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TR tell_room
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_short("...");
     set_name("dark crawler");
     set_race("shadowcreature");
     set_alias("haze");
     set_long("You see nothing more than a dark haze.\n");
     set_level(random(12)+6);
     set_ac(random(10)+10);
     set_wc(random(10)+8);
     set_hp(random(40)+80);
     set_heal(1,1);
     set_al(-200);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("Scratch... scratch...\n");
     load_chat("Shlupp...\n");
     load_a_chat("A dark haze swirls around your feet.\n");
set_chance(10);
set_spell_mess1("The haze grows darker!\n");
set_spell_mess2("The haze grows darker!\n");
set_spell_dam(20);
   }
}
 

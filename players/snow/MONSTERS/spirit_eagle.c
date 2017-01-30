/*
Monster called through use of /p/s/armor/eagle_helmet.c
*/
 
#define TO this_object()
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("spirit eagle");
     set_short("A Spirit Eagle");
     set_race("spirit");
     set_alias("eagle");
     set_long(
"The Spirit of an Eagle called to wreak vengeance on monsters.\n");
     set_level(15);
     set_ac(1);
     set_wc(1);
     set_hp(200);
     set_heal(0,0);
     set_al(0);
     set_aggressive(0);
     set_a_chat_chance(10);
     load_a_chat("The Spirit Eagle cries out in anger!\n");
set_chance(20);
set_spell_mess1(
"The Spirit Eagle buffets its foe with its wings!\n");
set_spell_mess2(
"The Spirit Eagle buffets you with its wings!\n");
set_spell_dam(4);
call_out("eagle_life",20);
   }
}
 
eagle_life() {
    call_out("eagle_life",1);
  if(!MEAT) {
    tell_room(environment(TO),
"The Spirit Eagle flies off in search of other prey.\n");
destruct(this_object());
  }
return 1;
}

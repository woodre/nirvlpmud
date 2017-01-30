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
 
object gold,ob;
string shortdesc;
int R;
 R = random(5);
  if(R == 0) shortdesc = "A slavering Shadow Wolf";
  if(R == 1) shortdesc = "A Shadow Wolf";
  if(R == 2) shortdesc = "A silver-black Shadow Wolf";
  if(R == 3) shortdesc = "A ferocious Shadow Wolf";
  if(R == 4) shortdesc = "A skulking Shadow Wolf";
  
     set_name("shadow wolf");
     set_short(shortdesc);
     set_race("shadowcreature");
     set_alias("wolf");
     set_long(
"A ranging survivalist on the shadow plane, this dark wolf-like form\n"+
"is lean and deadly. It is dangerous even when not in a pack.\n");
     set_level(random(4)+15);
     set_ac(random(3)+5);
     set_wc(random(20)+25);
     set_hp(random(80)+150);
     set_heal(3,1);
     set_al(-10);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The Shadow Wolf glares hungrily at you.\n");
     load_chat("The Shadow Wolf moves without making a sound.\n");
     load_a_chat("The Shadow snarls silently at you.\n");
     load_a_chat("The Shadow Wolf moves in a blur!\n");
set_chance(20);
set_spell_mess1("The Shadow Wolf attacks without fear!\n");
set_spell_mess2("The Shadow Wolf attacks without fear!\n");
set_spell_dam(10);
   }
}
 

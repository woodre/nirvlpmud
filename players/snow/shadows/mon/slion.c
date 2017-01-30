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
  if(R == 0) shortdesc = "A huge Shadow Lion";
  if(R == 1) shortdesc = "A Shadow Lion";
  if(R == 2) shortdesc = "A dark-black Shadow Lion";
  if(R == 3) shortdesc = "A fearsome Shadow Lion";
  if(R == 4) shortdesc = "A noble Shadow Lion";
 
     set_name("shadow lion");
     set_short(shortdesc);
     set_race("shadowcreature");
     set_alias("lion");
     set_long(
"A huge dark catlike shape. The fur of this Shadow Lion is like black velvet.\n"+
"It moves with the smooth grace of a confident predator. Close to the top of\n"+
"the food chain in the shadow realm, this lion fears almost nothing.\n");
     set_level(20);
     set_ac(random(10)+10);
     set_wc(random(25)+20);
     set_hp(random(200)+200);
     set_heal(2,1);
     set_al(-10);
     set_aggressive(random(2));
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The Shadow Lion's eyes gleam a shiny black.\n");
     load_chat("The Shadow Lion moves without making a sound.\n");
     load_a_chat("The Shadow Lion lets out a silent roar!\n");
     load_a_chat("The Shadow Lion moves in a blur!\n");
set_chance(20);
set_spell_mess1("The Shadow Lion pounces on its foe!\n");
set_spell_mess2("The Shadow Lion pounces on you!\n");
set_spell_dam(20);
   }
}
 

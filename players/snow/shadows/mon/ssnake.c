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
  if(R == 0) shortdesc = "A sinewy Shadow Snake";
  if(R == 1) shortdesc = "A Shadow Snake";
  if(R == 2) shortdesc = "A speckled Shadow Snake";
  if(R == 3) shortdesc = "A deadly Shadow Snake";
  if(R == 4) shortdesc = "A coiled Shadow Snake";
 
     set_name("shadow snake");
     set_short(shortdesc);
     set_race("shadowcreature");
     set_alias("snake");
     set_long(
"The small, dark snake slides swiftly across the shadow landscape. When you\n"+
"can catch a decent glimpse, you see a skin that shimmers like silk and\n"+
"some deadly sharp fangs.\n");
     set_level(random(3)+12);
     set_ac(random(3)+3);
     set_wc(random(25)+20);
     set_hp(random(50)+40);
     set_heal(2,1);
     set_al(-10);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The Shadow Snake looks at you with dead-black eyes.\n");
     load_chat("The Shadow Snake slithers without making a sound.\n");
     load_a_chat("The Shadow Snake's fangs drip black poison!\n");
     load_a_chat("The Shadow Snake moves in a blur!\n");
set_chance(40);
set_spell_mess1("The Shadow Snake strikes!\n");
set_spell_mess2("The Shadow Snake strikes!\n");
set_spell_dam(20);
   }
}
 

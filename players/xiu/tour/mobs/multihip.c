inherit "/obj/monster";
reset(arg){
string *random_names;
string *random_longs;
object gold,beer;
  int me;
   if(arg) return;
  me = random(3);
set_name("hippy");
set_name("guy");
   set_race("human");
set_alias("guy");
set_alias("dude");

  random_names=({
"A dirty hippy",
"Some dude with a goofy grin",
"A random guy dancing wildly",
"A hippy with nasty dreadlocks",
 "A dancing hippy",
"Some spaced-out hippy dude", 
"A half-naked hippy",
"A hippy with a blank stare",
"An old hippy",
   });
  short_desc = random_names[random(sizeof(random_names))];
random_longs=({
"This is a die hard music fan of the hippy variety.\n"+
"His eyes are the deepest bloodshot red.\n",
"With a long beard and strange, circular sunglasses,\n"+
"this hippy somewhat resembles a mix between John Lennon and Charles Manson.\n",
"A hippy in a tye died shirt sits on the ground here,\n"+
"He exhales a puff of smoke as he flashes a goofy smile.\n",
    "I bet you could kick him where the sun doesnt shine, and nothing would\n"+
    "happen...\n",
"The hippy closes and eyes and bobs their head to each side slowly\n"+
"his long dread locks fall over his face as he sways to and fro\n",
  });
long_desc = random_longs[random(sizeof(random_longs))];
  ::reset(arg);
add_money(random(200)+3500);
set_level(19);
set_hp(450 + 18*me);
set_al(-20);
 set_wc(20+ 2*me);
set_ac(17);
   set_chat_chance (5);
load_chat("The hippy dances wildly.\n");
load_chat("Marijuana smoke wafts through the air. \n");
  load_chat("The hippy's eyes dart around nervously.\n");
   set_a_chat_chance(20);
load_a_chat("A hippy burns you with their lighter.\n");
load_a_chat("Cigarette ashes are flicked into your eyes by the hippy!\n");
   if (random(10)<=2) {
beer=clone_object("/players/xiu/tour/items/beer.c");
move_object(beer,this_object());
   }
}

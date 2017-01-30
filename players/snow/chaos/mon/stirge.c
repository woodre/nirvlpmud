/* Stirge Demon
 * A vicious flying monster that follows its prey. 
 * Very high damage and healing, multiple attacks
 * Another of the annoying monsters in ChAoS without coins
 */
 
#define TO this_object()
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define MO move_object
#define CO call_other
#define FP find_player
#define ENV environment
#define TR tell_room
#define LC lower_case
#define CAP capitalize
 
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("stirge");
     set_short("A Stirge Demon");
     set_race("chaoscreature");
     set_alias("demon");
     set_long(
"This is an aggressive flying demon about 1 meter long. It has a long,\n"+
"sharp probiscus protruding from its head and beady, evil eyes.\n");
     set_level(15);
     set_ac(6);
     set_wc(28);
     set_hp(random(100) + 50);
     set_heal(1,10);
     set_al(-400);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The stirge gazes hungrily at you.\n");
     load_chat("The stirge buzzes around your head.\n");
     load_a_chat("The stirge dives at your luscious body!\n");
     load_a_chat("The stirge glows an evil bluish-black!\n");
set_chance(30);
set_spell_mess2("The stirge rips into you with its claws!\n");
set_spell_mess1("The stirge rips into its foe with its claws!\n");
set_spell_dam(10);
   }
}

heart_beat() {
  ::heart_beat();
  if(!environment()) return 1;
  if(!MEAT) return 1;
    if(ENV(MEAT) == ENV(TO)) {
TR(ENV(TO),"The Stirge Demon sucks blood from "+MEATN+"!\n");
  MEAT->heal_self(-random(6)-4);
  heal_self(random(4)+2);
return 1;
  }
else
  if(ENV(MEAT)->query_chaos() != "devour") return 1;
  MO(TO,ENV(MEAT));
TR(ENV(MEAT),
  "The Stirge Demon flies in and plunges its probiscus into "+MEATN+"'s back!\n");
CO(MEAT,"heal_self",-(random(5)+2));
return 1;
}


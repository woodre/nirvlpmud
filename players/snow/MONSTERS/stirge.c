/*A vicious flying monster that follows its prey.*/
 
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
 
     set_name("Stirge Demon");
     set_short("A Stirge Demon");
     set_race("demon");
     set_alias("stirge");
     set_long(
"This is an aggressive flying demon about 1 meter long. It has a long,\n"+
"sharp probiscus protruding from its head and beady, evil eyes.\n");
     set_level(15);
     set_ac(6);
     set_wc(28);
     set_hp(random(50) + 50);
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
call_out("stirge_life",1);
   }
}
 
init() {
  ::init();
    if(this_player()->query_level() > 21) {
add_action("mon_attack","stirgeattack");
    }
}
 
mon_attack(arg) {
  object meat;
  string name,meatname,moname;
meat = present(arg,environment(this_object()));
name = capitalize(this_player()->query_real_name());
meatname = capitalize(arg);
moname = this_object()->query_real_name();
  if(!meat) { say(meatname+" is not here!\n"); return 1; }
  if(living(this_object())) {
call_other(this_object(),"attack_object",meat);
  }
  log_file("snow.atk",
ctime(time())+" "+name+" forced "+moname+" to attack "+meatname+"\n");
return 1;
}

stirge_life() {
while (remove_call_out("stirge_life") != -1);
  call_out("stirge_life",1);
    if(!ENV()) return;
    if(ENV(MEAT) == ENV(TO)) {
TR(ENV(TO),"The Stirge Demon sucks blood from "+MEATN+"!\n");
CO(MEAT,"heal_self",-(random(4)+1));
CO(TO,"heal_self",random(5));
return 1;
  }
else
  MO(TO,ENV(MEAT));
TR(ENV(MEAT),
  "The Stirge Demon flies in and plunges its probiscus into "+MEATN+"'s back!\n");
CO(MEAT,"heal_self",-(random(5)+2));
return 1;
}

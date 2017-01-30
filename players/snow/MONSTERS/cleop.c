/* A tough demon */
 
inherit "/obj/monster";
 
#define TP this_player()
#define TO this_object()
#define TE tell_player
#define TR tell_room
#define CO call_other
#define ENV environment
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define RAN random(100)
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold,ob;
  gold = clone_object("obj/money");
  gold->set_money(random(3000) + 2000);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/ITEMS/bdiamond.c");
move_object(ob,this_object());
 
     set_name("cleoprites");
     set_short("Cleoprites, the Demon of Night");
     set_race("demon");
     set_alias("demon of night");
     set_long(
"You see before you a figure of substance nearly intangible but \n" +
"also of the deepest darkness. Its movements around the room \n" +
"seem slow at first but quickly build up speed. As you are \n" + 
"starting to feel dizzy, he starts a wailing howl that nearly drives \n" + 
"you to your knees. You know now that this must be Cleoprites, \n" +
"the Demon of Night.\n");
     set_level(25);
     set_ac(35);
     set_wc(30);
     set_wc_bonus(20);
     set_hp(600);
     set_heal(5,1);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("Cleoprites blurs your sight with his movements.\n");
     load_chat("Cleoprites screams: LEAVE MORTALS!\n");
     load_a_chat("Cleoprites flickers about, blurring your vision.\n");
     load_a_chat("Cleoprites screams in vicious fury!\n");
set_chance(70);
set_spell_mess1("Cleoprites attacks with blinding speed!\n");
set_spell_mess2("Cleoprites attacks with blinding speed!\n");
set_spell_dam(40);
call_out("cleop_life",1);
   }
}
 
cleop_life() {
  call_out("cleop_life",5);
  if(MEAT) {
    if(MEAT == TO) pissed();
    if(TO->query_wc() < 25) pissed();
    if(RAN < 30) lightning();
  }
  return 1;
}

pissed() {
  TO->stop_fight();
  TO->stop_fight();
  TO->stop_hunter();
  TO->set_wc(50);
  TO->heal_self(300);
  TO->set_heal(10,1);
  return 1;
}

lightning() {
  if(ENV(MEAT) != ENV(TO)) return 1;
  TR(ENV(MEAT),
    "Cleoprites sends black lightning burning from its claws!\n\n"+
    "~~~~~~~~~~ "+MEATN+" is severely burned!\n");
  MEAT->hit_player(random(30)+50, "other|electric");
  return 1;
}

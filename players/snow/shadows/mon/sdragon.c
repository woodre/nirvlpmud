#define TP this_player()
#define TO this_object()
#define TPN capitalize(TP->query_name())
#define MEAT TO->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TR tell_room
#define ENV environment
#define MO move_object
#define SD BOLD+"Shadow Dragon"+OFF
 
#include "/players/snow/MONSTERS/color.h"
inherit "/obj/monster";
 
int BREATH;
set_breath(b) { BREATH = b; }

reset(arg) {
   ::reset(arg);
   if (!arg) {
 
  object GEM;
  GEM = clone_object("/players/snow/shadows/stuff/sgem");
  MO(GEM,TO); MO(GEM,TO); MO(GEM,TO); MO(GEM,TO);
    set_name(SD);
    set_short(SD);
     set_short("A Shadow Dragon");
     set_race("shadowcreature");
     set_alias("dragon");
     set_long(
"A huge wyrm of the shadow realm. It is black as night with huge claws\n"+
"and teeth. It has surprisingly beautiful indigo eyes that seem to draw\n"+
"you in and dissect you. You have heard tales of the immense power these \n"+
"dragons possess. Take care not to die.\n");
     set_level(24);
/* These stats upped from 6, 20, 400 -Snow 6/8 */
     set_ac(random(10)+10);
     set_wc(random(12)+30);
     set_hp(random(150)+500);
/* BONUS FACTORS */
  set_ac_bonus(2); /* Healing */
  set_wc_bonus(8); /* Area attack heal self damage */
     set_heal(1,1);
     set_al(-800);
     set_aggressive(random(2));
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The "+SD+" gazes at you with eyes of swirling evil.\n");
     load_chat("The "+SD+" rips huge pieces of shadow-turf out of\n"+
               "the ground with its claws.\n");
     load_a_chat("The "+SD+" shows obsidian teeth as it attacks.\n");
     load_a_chat("The "+SD+" moves in a blur!\n");
set_chance(40);
set_spell_mess1("The "+SD+" glows darkly.\n");
set_spell_mess2("The "+SD+" glows darkly.\n");
set_spell_dam(40);
call_out("drag_life",1);
BREATH = 8;
   }
}
 
drag_life() {
  call_out("drag_life",1);
  drag_heal();
  drag_fight();
  checkup();
}
 
drag_heal() {
    if(TO->query_hp() < 300) {
      if(random(30) < 10) {
        TO->heal_self(5);
      }
    }
return 1;
}
 
drag_fight() {
  object ob;
  int dam;
    if(!environment(TO)) return 1;
dam = random(30)+30;
  if(!MEAT) return 1;
  if(random(100) > BREATH) return 1;
  tell_room(environment(TO),
    "The "+SD+" breathes forth a "+BLINK+BOLD+"dark, churning mass!"+OFF+OFF+"\n"+"\n");
  tell_room(environment(TO),"\n"+"\n"+"\n"+"\n");
 ob = first_inventory(ENV(TO));
   while(ob) {
     if(living(ob)) {
       if(!(ob->query_race() == "shadowcreature")) {
         tell_object(ob,BOLD+"The dragonbreath drains you of life!\n"+OFF);
         if((ob->query_hp() < 0 || ob->query_sp() < 1)) {
           call_other(ob,"hit_player",dam);
         }
           if(ob) {
            if((ob->query_hp() > 0 && ob->query_sp() > 0)) {
           call_other(ob,"heal_self",-dam);
          } }
     if(environment(ob))
         tell_room(environment(ob),capitalize(ob->query_name())+
                  " is weakened by the dragon breath!\n");
       }
     }
    ob = next_inventory(ob);
    }
return 1;
}
checkup() {
  if(attacker_ob) {
    if(attacker_ob == TO) pissed();
    if(weapon_class < 25) pissed();
  }
  return 1;
}
 
pissed() {
  TO->stop_fight();
  TO->set_wc(70);
  TO->heal_self(200);
  TO->set_heal(10,1);
  return 1;
}

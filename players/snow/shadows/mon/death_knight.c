#define TP this_player()
#define TO this_object()
#define TPN capitalize(TP->query_name())
#define TR tell_room
#define MWIL call_other(MEAT,"query_attrib","wil")
#define BB BOLD+"Balathuil"+OFF
#include "/players/snow/MONSTERS/color.h"
 
inherit "/obj/monster";
 
int FINGER, FEAR, can_heal_damage;
int delay1, delay2;
set_finger(f) { FINGER = f; }
set_fear(f) { FEAR = f; }

reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold,ob,ob2,ob3;
  gold = clone_object("obj/money");
  gold->set_money(5000);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/shadows/stuff/plate");
  ob2 = clone_object("/players/snow/shadows/stuff/nightshade");
  ob3 = clone_object("/players/dragnar/MKScar/scar");
move_object(ob,this_object());
move_object(ob2,this_object());
move_object(ob3,this_object());
 
    set_name(BB);
    set_short(BB+", the Death Knight");
     set_race("knight");
     set_alias("balathuil");
     set_long(
"  You see before you a tall, dark, and brooding figure. His skin is the color of ash\n"+
"in all but two places: a blood "+RED+"red"+OFF+" scar burns brightly on his left forearm and\n"+
"his eyes still gleam a vibrant "+GREEN+"green"+OFF+".\n"+
"  Once a Paladin, "+BB+" succumbed to the lure of evil. His power\n"+
"grew with his death, as did his shame at what he had become. The\n"+
"values of honor remained strong however. In regret for his fall from\n"+
"grace, "+BB+" banished himself to the Shadow Plane and was resigned\n"+
"to spending eternity here. He is extremely proud and his paladin fighting\n"+
"skills have not eroded at all. Beware his wrath.\n");
     set_level(25);
init_command("wear platemail");
     set_ac(40);
init_command("wield nightshade");
     set_wc(45);
     set_hp(1000);
     set_heal(2,5);
     set_al(-1000);
     set_aggressive(0);
      set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat(""+BB+" gazes sadly at you.\n");
     load_chat(""+BB+" says: Leave before I am forced to destroy you.\n");
     load_a_chat(""+BB+" says: It is good to battle once again!\n");
     load_a_chat(""+BB+" is surrounded by an aura of blackness.\n");
set_chance(75);
set_spell_mess1(""+BB+"'s eyes burn black!\n");
set_spell_mess2(""+BB+"'s eyes burn black!\n");
    set_wc_bonus(40); /* added by Vertebraker [6.3.01] */
set_ac_bonus(5 + 14); /* added by Vertebraker [6.3.01] */
set_spell_dam(35);
FINGER = 15;
FEAR = 15;
   }
}

monster_died() {
  write_file("/players/snow/closed/q/mon", ctime(time())+" "+
    query_attack()->query_name()+" killed Balathuil.\n");
  return 0; }
 
heart_beat() {
  ::heart_beat();
  if(!environment()) {
    if(present("scar")) destruct(present("scar"));
    return 1; }
  knight_heal();
  if(attacker_ob)
  if(present(attacker_ob, environment())) {
  knight_finger();
  knight_wave();
  }
  checkup();
  can_heal_damage = 1;
return 1;
}
 
knight_heal() { if(hit_point < 700 && !random(3)) hit_point += random(5) + 5; }

knight_finger() {
/* Umm. -snow
  if(delay1) { delay1 --; return; }
*/
  if(!attacker_ob) return 1;
  if(random(100) < FINGER) {
    delay1 = 6;
    TR(environment(),
      ""+BB+" raises a finger...\n"+
      "      He points at "+attacker_ob->query_name()+"...\n"+
      "           An evil stream of light hits "+attacker_ob->query_name()+" in the heart!\n");
    tell_object(attacker_ob,BOLD+"You feel death grip your heart in an iron grasp!\n"+OFF);
    if(!attacker_ob->is_player()) { attacker_ob->heal_self(-300); return 1; }
    if(!random(3) || random(30) < attacker_ob->query_attrib("wil") ) {
      attacker_ob->add_hit_point(-(random(60)+40));
    return 1;
    }
  else
  attacker_ob->add_hit_point(-200);
  }
return 1;
}
 
knight_wave() {
  object ob;
/* Umm. -snow
  if(delay2) { delay2 --; return; }
*/
  ob = first_inventory(environment());
  if(!attacker_ob) return 1;
  if(random(100) < FEAR) {
    delay2 = 10;
  TR(environment(TO),""+BB+" waves his hand.\n");
    while(ob) {
       if(living(ob)) {
        if(ob->is_player() &&
           (random(40) > ob->query_attrib("wil")) ) {
          say(capitalize(ob->query_name())+
             " screams in fear and runs away!\n");
          tell_object(ob,"You cannot control your fear!\n");
          ob->run_away();
        }
      }
      ob = next_inventory(ob);
    }
  }
return 1;
}
checkup() {
  if(attacker_ob)
  if(attacker_ob = TO) { attacker_ob = 0; }
  if(weapon_class < 30) pissed();
  return 1;
}

pissed() { set_wc(75); hit_point += 400; }

heal_self(int num) {
  if(num < 0) {
    if(!can_heal_damage) return 1;
    can_heal_damage = 0; }
  ::heal_self(num);
  return 1; }

#include "/players/beck/MortalKombat/MKQuestNPC.h"

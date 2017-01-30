#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
int i;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(""+YEL+"Kaliz"+NORM+""); 
  set_alt_name("templar_trainer");
  set_alias("kaliz");
  set_short(""+YEL+"Kaliz, infantry trainer of the Army"+NORM+"");
set_long("Kaliz is a longtime friend of Pestilence.  He is a\n"+
         "large and fierce fighter.  Hand to hand combat and\n"+
         "other up close fighting techniques are his speciality.\n"+
         "Now he is here to help train those who wish to learn\n"+
         "the infantry class.\n");
  set_race("human");
  set_gender("male");
  set_level(20);
  set_wc(60+random(20));
  set_ac(40+random(20));
  set_hp(1500);
  set_heal(30,3);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat(""+YEL+"Kaliz"+NORM+" says: Do you need to train?\n");
  load_chat(""+YEL+"Kaliz"+NORM+" says: Just type train infantry.\n");
  set_chat_chance(5);
  set_spell_mess2(""+YEL+"Kaliz"+NORM+" charges you, knocking you to the ground.\n");
  set_spell_mess1(""+HIK+"Kaliz"+NORM+" charges his attacker, knocking them to the ground.\n");
  set_chance(10);
  set_spell_dam(60);
}



monster_died() {
  tell_room(environment(this_object()),
        "As the "+YEL+"Kaliz"+NORM+" hits the ground, he screams, 'Revenge Shall be Mine!'.\n");
return 0; }



flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say(""+YEL+"Kaliz"+NORM+" smashes "+ATT_NAME+" fiercely with his fists.\n");
attacker_ob->hit_player(35+random(90), "other|dark"); 


}

flesh_impale(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
     say(""+YEL+"Kaliz"+NORM+" leaps into the air.\n\n"+YEL+"Kaliz"+NORM+"\n               "+HIR+"E V I S C E R A T E S"+NORM+"\n"+ATT_NAME+" with a devastating blow.\n");

attacker_ob->hit_player(35+random(90), "other|dark");
}

mass_attack() {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say(""+YEL+"Kaliz"+NORM+" attacks ferociously, landing several blows on "+ATT_NAME+".\n");
if(attacker_ob->query_npc())
attacker_ob->hit_player(35+random(90), "other|dark");

}


heart_beat(){
int i,z,a;
  ::heart_beat();
if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = 3;
for(a=0;a<z;a++){
    already_fight = 0;
    this_object()->attack(attacker_ob);
if(attacker_ob){
i = random(25); 
switch(i){


    case 0..3: flesh_tear();
  break;
    case 4..8: flesh_impale();
  break;

    case 9..10: return 0;
  break;

    case 11..14: mass_attack();
  break;

    case 15..24: return 0;
  break;
    }
  }
}
}
}
id(str) { return (::id(str) || str == "trainer"); }

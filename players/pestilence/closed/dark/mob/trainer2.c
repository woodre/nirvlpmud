#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
object leg, leg1;
int i;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
          leg=clone_object("/players/pestilence/closed/dargsword.c"),
        move_object(leg, this_object());
		        leg1=clone_object("/players/pestilence/closed/dargsword.c"),
        move_object(leg1, this_object());
				leg1->offwield( this_object() );
  set_name(""+HIK+"Dajerias"+NORM+""); 
  set_alt_name("order_trainer");
  set_alias("dajerias");
  set_short(""+HIK+"Dajerias, trainer of the Dark Order"+NORM+"");
set_long("Dajerias is a longtime servant of Pestilence.  He is a\n"+
         "large and fierce warrior, with many skills from the Dark\n"+
         "Order.  Pestilence has brought him here to help teach some\n"+
         "of the skills to players.  This can be done through the use\n"+
         "of advance.\n");
  set_race("demon");
  set_gender("male");
  set_level(19);
  set_wc(60+random(4));
  set_ac(40+random(4));
  set_hp(1500);
  set_ac_bonus(8);
  set_wc_bonus(16);
  set_heal(5,15);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-700);
  load_chat(""+HIK+"Dajerias"+NORM+" says: Do you need to train?\n"+
            ""+HIK+"Dajerias"+NORM+" says: Just type advance rank, or combat which ever you need.\n");
  load_chat(""+HIK+"Dajerias"+NORM+" says: how can i help you?\n");
  set_chat_chance(5);
  set_spell_mess2(""+HIK+"Dajerias"+NORM+" charges you, knocking you to the ground.\n");
  set_spell_mess1(""+HIK+"Dajerias"+NORM+" charges his attacker, knocking them to the ground.\n");
  set_chance(10);
  set_spell_dam(40);
}



monster_died() {
if(leg) destruct(leg); 
if(leg1) destruct(leg1);
  tell_room(environment(this_object()),
        "As the "+HIK+"Dajerias"+NORM+" hits the ground, the axe falls from his hand.\n");
write_file("/players/pestilence/closed/dark/log/trainer",""+attacker_ob->query_real_name()+" "+attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+" killed the Dajerias -> "+ctime()+"\n");
return 0; }



flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say(""+HIK+"Dajerias"+NORM+" slashes "+ATT_NAME+" fiercly with his axe.\n");
attacker_ob->hit_player(85+random(90), "other|dark");


}

flesh_impale(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
     say(""+HIK+"Dajerias"+NORM+" leaps into the air.\n\n"+HIK+"Dajerias"+NORM+"\n               "+HIR+"E V I S C E R A T E S"+NORM+"\n"+ATT_NAME+" with a devastating blow.\n");

attacker_ob->hit_player(85+random(90), "other|dark");
}

mass_attack() {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say(""+HIK+"Dajerias"+NORM+" attacks ferociously, landing several blows on "+ATT_NAME+".\n");
if(attacker_ob->query_npc())
attacker_ob->hit_player(85+random(90), "other|dark");

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

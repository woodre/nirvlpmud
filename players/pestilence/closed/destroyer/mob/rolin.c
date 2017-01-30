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

  move_object(clone_object("/players/pestilence/closed/destroyer/wep/rolinaxe.c"),
        this_object());
  command("wield");
  set_name(""+YEL+"Rolin"+NORM+""); 
  set_alt_name("templar_trainer");
  set_alias("rolin");
  set_short(""+YEL+"Rolin, trainer of the Army"+NORM+"");
set_long("Rolin is a longtime friend of Pestilence.  He is a\n"+
         "large and fierce fighter, with many skills.  He has been\n"+
         "implanted with superior DNA, which enhances his finely tuned\n"+
         "skills.  He is here to share his training with the members of\n"+
         "the Destroyer Guild.\n");
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
  load_chat(""+YEL+"Rolin"+NORM+" says: Do you need to train?\n");
  load_chat(""+YEL+"Rolin"+NORM+" says: Just type advance rank.\n");
  set_chat_chance(5);
  set_spell_mess2(""+YEL+"Rolin"+NORM+" charges you, knocking you to the ground.\n");
  set_spell_mess1(""+HIK+"Rolin"+NORM+" charges his attacker, knocking them to the ground.\n");
  set_chance(10);
  set_spell_dam(60);
}



monster_died() {
  tell_room(environment(this_object()),
        "As the "+YEL+"Rolin"+NORM+" hits the ground, he screams, 'Revenge Shall be Mine!'.\n");
return 0; }



flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say(""+YEL+"Rolin"+NORM+" slashes "+ATT_NAME+" fiercely with his axe.\n");
attacker_ob->hit_player(35+random(90), "other|dark");


}

flesh_impale(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
     say(""+YEL+"Rolin"+NORM+" leaps into the air.\n\n"+YEL+"Rolin"+NORM+"\n               "+HIR+"E V I S C E R A T E S"+NORM+"\n"+ATT_NAME+" with a devastating blow.\n");

attacker_ob->hit_player(35+random(90), "other|dark");
}

mass_attack() {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say(""+YEL+"Rolin"+NORM+" attacks ferociously, landing several blows on "+ATT_NAME+".\n");
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

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
  move_object(clone_object("/players/pestilence/CONTARMY/dreadaxe.c"),
        this_object());
  command("wield");
  set_name(""+HIK+"Flailing Dreadnaught"+NORM+""); 
  set_alt_name("flailing dreadnaught");
  set_alias("dreadnaught");
  set_short(""+HIK+"A large Flailing Dreadnaught"+NORM+"");
  set_long("This is a very large Flailing Dreadnaught.  He appears to be ticked off, and\n"+
           "isn't very happy your here bothering him.\n");
  set_race("undead");
  set_gender("male");
  set_level(20);
  set_wc(16);
  set_ac(18+random(4));
  set_hp(550+random(200));
  set_ac_bonus(8);
  set_wc_bonus(16);
  set_heal(15,5);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-700);
  load_chat(""+HIK+"Dreadnaught"+NORM+" says: You shouldn't be here.\n");
  load_chat(""+HIK+"Dreadnaught"+NORM+" says: are you looking at me, mortal?\n");
  set_chat_chance(20);
  load_a_chat("The Flailing Dreadnaught flails about almost hitting you in the head.\n");
  set_a_chat_chance(20);
  set_spell_mess2(""+HIK+"Dreadnaught"+NORM+" charges you, knocking you to the ground.\n");
  set_spell_mess1(""+HIK+"Dreadnaught"+NORM+" charges his attacker, knocking them to the ground.\n");
  set_chance(10);
  set_spell_dam(40);
}



monster_died() {
  tell_room(environment(this_object()),
        "As the "+HIK+"Dreadnaught"+NORM+" hits the ground, the axe falls from his crusty hand.\n");
return 0; }



flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say("The "+HIK+"Dreadnaught"+NORM+" slashes "+ATT_NAME+" fiercly with his axe.\n");
attacker_ob->hit_player(20+random(10), "other|laser");


}

flesh_impale(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
     say("The "+HIK+"Dreadnaught"+NORM+" leaps into the air.\n\nThe "+HIK+"Dreadnaught"+NORM+"\n               "+HIR+"E V I S C E R A T E S"+NORM+"\n"+ATT_NAME+" with a devastating blow.\n");

attacker_ob->hit_player(20+random(10), "other|water");
}

mass_attack() {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say("The "+HIK+"Dreadnaught"+NORM+" flails hysterically, landing several blows on "+ATT_NAME+".\n");
if(attacker_ob->query_npc())
attacker_ob->hit_player(20+random(10), "other|poison");

}


heart_beat(){
 ::heart_beat();

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

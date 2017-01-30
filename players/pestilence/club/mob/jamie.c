#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define attacker attacker_ob
int i;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/pestilence/club/wep/axe.c"),
        this_object());
  command("wield axe");
  set_name("Jamie");
  set_alt_name("jamie");
  set_alias("jamie johnson");
  set_short("Jamie Johnson");
  set_long("Jamie is the oldest and biggest of the Johnson brothers.  He is\n"+
           "slightly overweight, with a lot of muscle from cutting wood with\n"+
           "his axe.  He stand 6'3 inches tall and weighs 280.\n");
  set_race("human");
  set_gender("male");
  set_level(20);
  set_wc(36);
  set_ac(18);
  set_hp(550);
  set_wc_bonus(18); /* 4.8+4.8+8.8=18.4 */
  set_heal(5,3);
  add_money(2000+ random(600));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(200);
  load_chat("Jamie says: All we need to do is regroup.\n");
  load_chat("Jamie says: You boys follow me, and I'll lead the way.\n");
  set_chat_chance(20);
  load_a_chat("Jamie pushes you to the ground.\n");
  load_a_chat("Jamie looks at you foolishly.\n");
  set_a_chat_chance(30);
  set_spell_mess2("Jamie "+HIK+"SLAMS"+NORM+" you onto the ground.\n");
  set_spell_mess1("Jamie "+HIK+"SLAMS"+NORM+" his attacker onto the ground.\n");
  set_chance(20);
  set_spell_dam(35);
}
id(str) { return (::id(str) || str == "johnson"); }


flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
     say("Jamie thrusts his axe into "+ATT_NAME+", leaving a large wound.\n");
attacker_ob->hit_player(15+random(30));


}

flesh_impale(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
     say("Jamie "+HIR+"eviscerates"+NORM+" "+ATT_NAME+" with a solid swing of his axe.\n");
attacker_ob->hit_player(15+random(30));
}

mass_attack() {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say("Jamie massacred "+ATT_NAME+" into tiny fragments.\n"+
        "Jamie massacred "+ATT_NAME+" into tiny fragments.\n");
attacker_ob->hit_player(35+random(40));

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

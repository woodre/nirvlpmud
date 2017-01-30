#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define attacker attacker_ob
int i;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/pestilence/club/wep/jackknife.c"),
        this_object());
  command("wield knife");

  move_object(clone_object("/players/pestilence/club/arm/hat.c"),
        this_object());
  command("wear hat");

  set_name("Ray");
  set_alt_name("ray");
  set_alias("ray johnson");
  set_short("Ray Johnson");
  set_long("Ray is the brother of Jim Bob.  He is very similiar physically to\n"+
           "Jim Bob.  He is overweight, with very few teeth.  He doesn't have\n"+
           "much hair, but usually covers it with his John Deere hat.\n");
  set_race("human");
  set_gender("male");
  set_level(21);
  set_wc(32);
  set_ac(16);
  set_hp(500);
  set_wc_bonus(18); /* 4.8+4.8+8.8=18.4 */
  set_heal(5,3);
  add_money(1500+ random(600));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(200);
  load_chat("Ray says: You gotta do something Jim Bob.\n");
  load_chat("Ray says: The ants must die.\n");
  set_chat_chance(20);
  load_a_chat("Ray spits in your eyes.\n");
  load_a_chat("Ray punches you in the nose.\n");
  set_a_chat_chance(30);
  set_spell_mess2("Ray slices you with his jack-knife.\n");
  set_spell_mess1("Ray slices his attacker with his jack-knife.\n");
  set_chance(15);
  set_spell_dam(35);
}
id(str) { return (::id(str) || str == "johnson"); }


flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
     say("Ray rams into "+ATT_NAME+", knocking "+ATT_NAME+" over.\n");
attacker_ob->hit_player(15+random(30));


}

flesh_impale(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
     say("Ray slams "+ATT_NAME+"'s head into the ground.\n");
attacker_ob->hit_player(15+random(30));
}

mass_attack() {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   say("Ray massacred "+ATT_NAME+" into tiny fragments.\n"+
        "Ray smashed "+ATT_NAME+" with a bone crushing sound.\n");
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

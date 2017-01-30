#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define attacker attacker_ob
int i;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/pestilence/club/wep/booey.c"),
        this_object());
  command("wield knife");

  move_object(clone_object("/players/pestilence/club/arm/shirt.c"),
        this_object());
  command("wear shirt");
  set_name("Jim Bob");
  set_alt_name("jim bob");
  set_alias("jim");
  set_short("Jim Bob Johnson");
  set_long("Jim Bob is a life long resident of Amity.  He is the typical small\n"+
           "town man.  He is overweight, and has very few teeth.  He has one\n"+
           "thing on his mind, and that is to rid Amity of the ants.\n");
  set_race("human");
  set_gender("male");
  set_level(19);
  set_wc(32);
  set_ac(16);
  set_wc_bonus(18); /*4.8 for flesh tear 4.8 for flesh_impale 8.8 for massattack = 18.4 rounded to 18 */
  set_hp(500);
  set_heal(5,3);
  add_money(2000+ random(600));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(200);
  load_chat("Jim Bob says: we have to get rid of the ants.\n");
  load_chat("Jim Bob says: maybe if one of us can get into the hole we can blow it up.\n");
  set_chat_chance(20);
  load_a_chat("Jim Bob says: listen here, maybe yall quit fightin' me and join us against the ants.\n");
  load_a_chat("Jim Bob spits some snuff in your face.\n");
  set_a_chat_chance(30);
  set_spell_mess2("Jim Bob slashes you with his booey knife.\n");
  set_spell_mess1("Jim Bob slashes his attacker with his booey knife.\n");
  set_chance(15);
  set_spell_dam(35);
}
id(str) { return (::id(str) || str == "johnson"); }


flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
     say("Jim Bob slashes "+ATT_NAME+" fiercely with his knife.\n");
attacker_ob->hit_player(15+random(30));


}

flesh_impale(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
     say("Jim Bob visciously attacks "+ATT_NAME+" with a devastating blow.\n");
attacker_ob->hit_player(15+random(30));
}

mass_attack() {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say("Jim Bob massacres "+ATT_NAME+" into tiny fragments.\n"+
        "Jim Bob smashed "+ATT_NAME+" with a bone crushing sound.\n");
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

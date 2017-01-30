#include "/players/pestilence/ansi.h"
inherit "obj/monster";
#define attacker attacker_ob
#define TP this_player()
#define TO this_object()
object club;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/pestilence/Cahara/wep/bclub.c"),
        this_object());
  command("wield");
        club=clone_object("/players/pestilence/Cahara/wep/bclub.c"),
        move_object(club, this_object());
  club->offwield( this_object() );
  set_name("jahuba"); 
  set_alias("cannibal");
  set_short("Jahuba the cannibal");
  set_long("Jahuba is a large cannibal.  He has several scars covering his body.  There is a\n"+
           "necklace made from bone around his neck..\n");
  set_race("human");
  set_gender("male");
  set_level(21);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_ac_bonus(3);
  set_wc_bonus(1 +random(10));
  set_hp_bonus(250);
  set_heal(10,10);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-200);
  load_chat("Jahuba says: leave my island now.\n");
  load_chat("Jahuba says: Your skin will look nice on my kitchen table.\n");
  set_chat_chance(20);
  load_a_chat("Jahuba bites you to the "+HIW+"bone"+NORM+".\n");
  load_a_chat("Jahuba lunges at you.\n");
  set_a_chat_chance(30);
  set_spell_mess2("Jahuba smashes you with his bone club, leaving"+RED+" blood "+NORM+"flowing from your wound.\n");
  set_spell_mess1("Jahuba smashes his opponent with his bone club leaving"+RED+" blood "+NORM+"flowing from the wound.\n");
  set_chance(30);
  set_spell_dam(15);
}


heart_beat(){
int z;
  ::heart_beat();
if(attacker_ob && present(attacker_ob,environment(this_object()))){

z = random(60);
if(z>50){
   tell_room(environment(TO), 
    "Jahuba "+RED+"devastates"+NORM+" his attacker with wreckless abandon.\n");
call_other(attacker_ob,"hit_player",random(30)+5);
return;
}
}
}

monster_died() {
  move_object(clone_object("/players/pestilence/Cahara/obj/bone.c"),
        this_object());
  tell_room(environment(this_object()),
        "Jahuba makes a loud thump as his body splits, when it hits the ground.\n");
return 0; }

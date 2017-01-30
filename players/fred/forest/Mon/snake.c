#include "/players/fred/ansi.h"
inherit "/obj/monster.c";
int n, i, randomnum;
string where;
object skin, attacked;
#define attacked (this_object()->query_attack())

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("snake");
  set_race("creature");
  set_short(BOLD+GRN+"Two"+NORM+BOLD+"-"+GRN+"headed "+NORM+"Snake");
  set_long(
    "  A large snake that is jet black in color. It has yellow\n"+
    "rings all along it's body.  Then you notice that it has two\n"+
    "heads. Each head has a set of large fangs.\n");
  
  set_level(18);
  set_hp(400+random(100));
  set_al(-800);
  set_ac(18);
  set_wc(26+random(2));
  set_wc_bonus(14);
  set_aggressive(1);
  set_dead_ob(this_object()); 
  set_chance(20);
  set_spell_dam(15);
  set_spell_mess1(
    "The Snake "+BOLD+YEL+"~"+NORM+BOLD+"Hisses"+YEL+"~"+NORM+" loudly and lashess out at it's opponent.");
  set_spell_mess2(
    "The Snake "+BOLD+YEL+"~"+NORM+BOLD+"Hisses"+YEL+"~"+NORM+" loudly and"+BOLD+" bites"+NORM+" you!");
}

heart_beat(){
  ::heart_beat();
    if(random(2) < 1){
    n = random(5);
    switch(n) {
      case 0: where = "shoulder"; break;
      case 1: where = "leg"; break;
      case 2: where = "arm"; break;
      case 3: where = "head"; break;
      case 4: where = "neck"; break;
      return 1;
    }
    randomnum = random(2);
    for(i=0; i<randomnum; i++){
    tell_object(attacked,
    "The second head "+BOLD+BLK+" S T R I K E S "+NORM+" at your "+BOLD+where+NORM+".\n");
    if(attacker_ob && !attacker_ob->query_ghost()){
    already_fight = 0;
    attack();
    }
   }
  }
 }

monster_died(){
  tell_object(attacked,
  "You quickly skin the snake as it drops to the ground.\n");
  move_object(clone_object("/players/fred/forest/Obj/snakeskin.c"),
  this_object());
  }  



#include "living.h"

    int handnum, gold, flg, starts_thinking;
    int atflg;
    object yesply, notply;
short() { return "A little old man"; }

long(str) {
     write("The Little Lotto Wizard.\n");
   write("He is dressed in all green with a pointy green hat with lotto balls\n"+
     "drawn on it.  He has a long white beard and seems to have some special powers.\n");
	return;
}

id(str) {
   return str =="lotto"||str =="man"||str=="wizard";
}
 reset(arg) {
yesply = clone_object("obj/weapon");
call_other(yesply, "set_id", "gun");
call_other(yesply, "set_name", "lotto gun");
call_other(yesply, "set_alias", "gun");
call_other(yesply, "set_class", 18);
call_other(yesply, "set_weight",2);
call_other(yesply, "set_value",1900);
        call_other(yesply, "set_short", "A lotto ball gun");
   move_object(yesply,this_object());
   if (arg)
  return;

    cap_name = "The Little-Lotto Wizard";
    money = 5067;
    name = "little-lotto wizard";
    level = 21;
   experience = 1600000;
    max_hp = 500;
    hit_point = 550;
    weapon_class = 27;
    armor_class = 9;
    is_npc = 1;
    alignment = 60;
    enable_commands();
}

catch_tell(str) {
   int ran, expl;
   string who, what;
   int repro;
   object offspring;
/*
 if (attacker_ob) {
  set_heart_beat(1);
   return;
 }
*/
     if (sscanf(str, "Wizard %s\n", who) == 1 ) {
    return 1;
  }
       if (sscanf(str, "%s Wizard %s", who,what) == 2) return 1;
   ran = random(16);
   if (ran == 1) {
     say("Wizard says: Play little lotto.\n");
     random_move();
    return 1;
     }
  if (ran == 11)
     say("Wizard says: The odds be with you.\n");
  if (ran == 3) {
    say("Wizard says: Little lotto is more fun than anything else in the world.\n");
    random_move();
      }
  if (ran == 4)
   {
    say("A voice asks: Oh, great Wizard, why have we come?\n");
    random_move();
   }
  if (ran == 5)
     say("Wizard says: Play Litto-Lotto.\n");
  if (ran == 6)
     say("Little-Lotto Wizard fires lotto balls into the air in a dazling arragement.\n");
  if (ran == 10 || ran == 0)
     say("Little-Lotto Wizard cocks his lotto ball gun.\n");
   if (ran == 7)
     say("Little Lotto Wizard reloads his lotto ball gun.\n");
   if (ran == 15)
    say("Wizard says: Today's winning numbers are 06, 24, 18, 09, and 10.\n");
   if (ran == 8)
  say("Wizard says: A new drawing every week!!\n");
   if (ran == 9)
  say ("Wizard says: Only a buck a ticket!\n");
     if (ran == 2) {
     random_move();
     repro = random(100);
}
return 1;
}

 heart_beat() {
    age += 1;
  if (hit_point < max_hp)
    call_out("heal_me", 20);
    already_fight = 0;
    handnum=random(100);
  if(!query_attack()) return; /* by verte */
   if (handnum < 40){
    tell_object(attacker_ob, "The Litto-Lotto Wizard shoots instant lottery tickets out of his finger at\n"+
   "you, causing many paper cuts. Ouch!\n");
    say("The Litto-Lotto Wizards fires lottery tickets at his attacker.\n");
   attacker_ob->hit_player(random(60));
   }
   if (handnum > 40 && handnum < 60) {
   tell_object(attacker_ob, "The Little-Lotto Wizard throws blinding flashes of color at\n"+
    "at you, and you become dazed as he hits you with a fireball from your\n"+
   "blind side.\n");
   say("The Little Lotto wizard sends out bright flashes of colored light followed by \n a fireball.\n");
   call_other(attacker_ob, "hit_player", random(80));
   }
   if(alt_attacker_ob != attacker_ob) {
   if(alt_attacker_ob && handnum > 70) {
    tell_object(alt_attacker_ob, "The Little Lotto Wizard fires lotto balls into both your eyes!\n");
     say("The Little Lotto Wizard dances happily after he hits "+alt_attacker_ob->query_name() + "\n"+
    "in both eyes with balls from his gun.\n");
    alt_attacker_ob->hit_player(random(50));
    }
   }
   attack();
/*
   set_heart_beat(0);
*/
}
random_move() {
    int n;
    n = random(4);
    if (n == 0)
	command("west");
    else if (n == 1)
	command("east");
    else if (n == 2)
	command("south");
    else if (n == 3)
	command("north");
}

heal_me(){
   if(hit_point < max_hp)
   hit_point += 2;
   if (hit_point < max_hp)
     call_out("heal_me", 20);
    return;
  }

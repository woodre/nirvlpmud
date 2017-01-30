inherit "obj/living.c";

#include "security.h"
#include "/obj/lib/living/settings.h"



    int handnum, gold, flg, starts_thinking;
    int atflg;
    object yesply, notply;
   int busyct;
short() {return "The black sphere of anti-life"; }

long(str) {
    write("It is a giant sphere of blackness, absorbing all energy.\n");
    write("You have a gut feeling that it would be un-wise to attack."+
    "\n");
     write("You feel as though this creature will suck the life force from you.\n");
	return;
}

id(str) {
   return str == "anti-life";
}
 reset(arg) {
   if (arg)
  return;

    cap_name= "The Anti-life";
    name = "anti-life";
    level = 15;
    experience = -600000;
    max_hp = 120;
    hit_point = 120;
    weapon_class = 19;
    armor_class = 6;
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
   if(attacker_ob) return;
    if(busyct) return;
     busyct = 1;
     if (sscanf(str, "%s anti-life %s\n", who , what) == 2 ) {
      busyct = 0;
    return 1;
  }
   ran = random(25);
   if (ran == 1) {
     say("The anti-life flashes brightly for a split second.\n");
     random_move();
    busyct = 0;
    return 1;
     }
  if (ran == 11)
     say("The anti-life contracts and expands.\n");
  if (ran == 3) {
     say("The anti-life makes a gurgling sound.\n");
    random_move();
      }
  if (ran == 4)
   {
     say("The anti-life sucks in all the avialible light for 3 seconds.\n");
    random_move();
   }
  if (ran == 5)
     say("The anti-life rises and falls.\n");
  if (ran == 6)
     say("The anti-life moves side to side.\n");
  if (ran == 10 || ran == 0)
      say("The anti-life moves toward at you.\n");
   if (ran == 7)
      say("The anti-life rolls along the ground.\n");
   if (ran == 15)
     {
      expl = random(100);
      if (expl > 3)
      { busyct = 0;
            return 1;
       }
       say("A anti-life explodes suddenly sending bits of its self into the sky.\n");
       destruct(this_object());
       }
   if (ran == 8)
     say("A anti-life rolls over on the ground.\n");
   if (ran == 9)
     say ("The anti-life expands and contracts.\n");
     if (ran == 2) {
       repro = random(100);
     if (repro > 20)
 {
    random_move();
     busyct = 0;
           return 1;
  }
     offspring = clone_object("players/boltar/things/sqrl2.c");
    if (random(100) < 3) 
    move_object(clone_object("players/boltar/things/waste.c"),offspring);
     say("The anti-life becomes two!!!\n");
     move_object(offspring, environment(this_object()));
     call_other(offspring, "random_move", 0);
     random_move();
     busyct =0;
     return 1;
     }
    busyct = 0;
    return 1;
}

 heart_beat() {
    age += 1;
    already_fight = 0;
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

living_save(){ return 1;}

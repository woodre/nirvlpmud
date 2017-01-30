#include <security.h>
#include "/obj/lib/living/settings.h"

inherit "obj/living.c";

    int handnum, gold, flg, starts_thinking;
    int atflg;
    object yesply, notply;
    int busyct;
short() { return "A squirrel"; }

long(str) {
   write ("A cute little squirrel.\n");
	return;
}

id(str) {
   return str == "squirrel";
}
 reset(arg) {
   if (arg)
  return;

    cap_name = "A Squirrel";
    name = "squirrel";
    level = 3;
    experience = 2000;
    max_hp = 99;
    hit_point = 99;
    weapon_class = 5;
    armor_class = 3;
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
    if(!this_player()) return 1;

   if(attacker_ob) return 1;
     if(busyct) return;
      busyct = 1;
     if (sscanf(str, "%s squirrel %s\n", who , what) == 2 ) {
     busyct = 0;
    return 1;
  }
   ran = random(25);
   if (ran == 1) {
     say("A squirrel shows his teeth.\n");
     random_move();
   busyct =0;
    return 1;
     }
  if (ran == 11)
     say("A squirrel sits on his hind legs.\n");
  if (ran == 3) {
     say("A squirrel nibbles on a small acorn.\n");
    random_move();
      }
  if (ran == 4)
   {
     say("A squirrel sticks his head up and looks around.\n");
    random_move();
   }
  if (ran == 5)
     say("A squirrel scurries around.\n");
  if (ran == 6)
     say("A squirrel nibbles on a twig.\n");
  if (ran == 10 || ran == 0)
      say("A squirrel looks at you.\n");
   if (ran == 7)
      say("A squirrel scurries about your feet and nibbles on your shoes.\n");
   if (ran == 15)
     {
      expl = random(100);
      if (expl > 13)
        { busyct = 0;
            return 1;
         }
       say("A squirrel explodes suddenly sending squirrel guts everywhere.\n");
       destruct(this_object());
       }
   if (ran == 8)
     say("A squirrel rolls over on the ground.\n");
   if (ran == 9)
     say("A squirrel gives you the look of a mad, rabid creature.\n");
     if (ran == 2) {
       repro = random(100);
     if (repro > 20)
 {
    random_move();
      busyct=0;
           return 1;
  }
     offspring = clone_object("players/boltar/things/sqrl2.c");
    if (random(100) < 20) 
    move_object(clone_object("players/boltar/things/waste.c"),offspring);
     say("The squirrel becomes two!!!\n");
     move_object(offspring, environment(this_object()));
     call_other(offspring, "random_move", 0);
     random_move();
    busyct = 0;
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

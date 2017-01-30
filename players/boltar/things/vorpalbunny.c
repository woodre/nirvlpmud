#include "living_pretypes.h"

    int handnum, gold, flg, starts_thinking;
    int atflg;
    object yesply, notply;
short() { return "A small white bunny"; }

long(str) {
     write("A small white bunny.\n");
   write("This is no ordinary rabbit\n"+
     "It has large fangs and sharp, pointy teeth. You notice dried blood on its fur.\n");
	return;
}

id(str) {
   return str =="bunny"||str =="vorpalbunny"||str=="rabbit";
}
 reset(arg) {
   if (arg)
  return;

    cap_name = "Bunny";
    money = 0;
    name = "bunny";
    level = 21;
   experience = 1600000;
    max_hp = 990;
    hit_point = 1050;
    weapon_class = 30;
    armor_class = 11;
    is_npc = 1;
    alignment = -70;
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
     if (sscanf(str, "Bunny %s\n", who) == 1 ) {
    return 1;
  }
       if (sscanf(str, "%s Bunny %s", who,what) == 2) return 1;
   ran = random(16);
  if (ran == 3) {
    random_move();
      }
  if (ran == 4)
   {
    random_move();
   }
     if (ran == 2) {
     random_move();
}
return 1;
}

 heart_beat() {
    age += 1;
  if (hit_point < max_hp)
    call_out("heal_me", 20);
    already_fight = 0;
    handnum=random(100);
   if (handnum < 40){
    tell_object(attacker_ob, "The Vorpal Bunny jumps and bites your neck in the most savage manner.\n");
    say("The Vorpal Bunny jumps up and grabs hold of his attacker's neck by its teeth.\n");
   attacker_ob->hit_player(random(60));
   }
   if (handnum > 40 && handnum < 60) {
   tell_object(attacker_ob, "The Vorpal Bunny bites with the strength of an guilutine.\n");
   say("The Vorpal Bunny goes for a head severing bite.\n");
   call_other(attacker_ob, "hit_player", random(80));
   }
   if(alt_attacker_ob != attacker_ob) {
   if(alt_attacker_ob && handnum > 70) {
    tell_object(alt_attacker_ob, "The Vorpal Bunny bites with the strength of an guilutine.\n");
     say("The The Vorpal Bunny dances happily after he bites "+alt_attacker_ob->query_name() + "\n"+
    "in the neck causing blood to spurt wildly.\n");
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

#include "living_pretypes.h"
int done;
int busyct;
int handnum, gold, flg, starts_thinking;
object billy;
int atflg;
object yesply, notply;

short() { return "A casino security guard"; }

long(str) {
write("A man in a spiffy blue uniform with a badge. He appears very \n"+
      "offical and serious.\n");
	return;
}

id(str) {
   return str == "security guard" || str == "cop" || str == "keeper" || str =="guard";
}

reset(arg) {
  if (arg)
  return;
    cap_name = "Security Guard";
    name = "guard";
    level = 15;
    experience = 60000;
    max_hp = 600;
    hit_point = 600;
    armor_class = 9;
    is_npc = 1;
    alignment = 200;
    enable_commands();
billy = clone_object("obj/weapon");
call_other(billy, "set_id", "billy");
call_other(billy, "set_name", "billy club");
call_other(billy, "set_alias", "club");
call_other(billy, "set_class", 18);
call_other(billy, "set_weight",3);
call_other(billy, "set_value",7000);
        call_other(billy, "set_short", "A billy club");
        move_object(billy, this_object());
}

catch_tell(str) {
  int rr,i;
  string where,who,what;
  object check;
  if(busyct) return;
  busyct = 1;
  check = allocate(50);
  if (sscanf(str, "%s Guard %s\n", who , what) == 2 ) {
    busyct = 0;
    return 1;
  }
  if (done !=4) { 
    done = 4;
    command("wield club");
    }

   rr = random(50);
   if (rr < 20)
   random_move();
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
    if(!attacker_ob) {
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
}

crime_to_attack() { return 1;}

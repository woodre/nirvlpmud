#include "living.h"
int done;
int busyct;

    int handnum, gold, flg, stophb;
    int last_move;
    int atflg;
    object yesply, notply;
short() { return "A Hound from Hell"; }

long(str) {
write("A Demonic Hound sent from the gates of hell to devour you.\n");
write("It would be wise not to anger this beast.\n");
        return;
}

id(str) {
   return str == "hound" || str == "dog" || str == "monster" || str =="dog";
}
 reset(arg) {
   if (arg)
  return;

    cap_name = "Hell Hound";
    name = "hound";
    level = 19;
    experience = 200000;
    gender="male";
    max_hp = 900;
    hit_point = 900;
    weapon_class = 35;
    armor_class = 9;
    is_npc = 1;
    alignment = -200;
    enable_commands();
}



catch_tell(str) {
  int rr,i;
  object blah;
 string where,who,what;
  object check;
  if(busyct) return;
  busyct = 1;
  check = allocate(50);
     if (sscanf(str, "%s Monster %s\n", who , what) == 2 ) {
     busyct=0;
    return 1;
  }
  blah=present("corpse");
  if(blah) {
  move_object(blah,this_object());
  say("The Hell Hound takes "+blah->short()+"\n");
  say("The Hell Hound devours the corpse.\n");
  say("The Hell Hound's eyes glow red.\n");
/*
  log_file("hoth_monster", "consumed "+blah->short()+"\n");
*/
  destruct(blah);
  }
  if(sscanf(str, "%s leaves %s.\n", who, where) == 2 && call_other(find_living(lower_case(who)), "is_pet", 0) == 1)
  if(sscanf(where, "following %s", who) == 1 && find_living(lower_case(who)) ){
  say("The Hell Hound chases after "+who+"\n");
  move_object(this_object(), environment(find_living(lower_case(who))));
  say("The Hell Hound arrives.\n");
  } else
    command(where);
if(sscanf(str, "%s leaves %s\n", who, where) == 2 && call_other(find_living(lower_case(who)), "is_pet", 0) == 1)
   if(sscanf(where, "following %s", who) == 1 && find_living(lower_case(who)) ){
  say("The Hell Hound Chases after "+who+"\n");
  move_object(this_object(), environment(find_living(lower_case(who))));
  say("The Hell Hound arrives.\n");
  } else
    command(where);
   check = all_inventory(environment(this_object()));
   i = 0;
   while (i<sizeof(check)){
   if (call_other(check[i], "is_pet",0) == 1) {
/*
   log_file("hoth_monster", "attacked "+check[i]->short()+"\n");
*/
   say("The Hound sees his next victum.\n");
   say("The Hell Hound proceeds to make "+check[i]->query_name()+" his next meal.\n");
   say("The Hell Hound attacks with his giant teeth, sending his prey's blood flying several\nfeet.\n");
   attack_object(check[i]);
   busyct=0;
   return 1;
   i = sizeof(check);
   }
   i += 1;
   }
  rr = random(50);
   if (rr < 8)
   random_move();
   busyct = 0;
    return 1;
}

 heart_beat() {
    age += 1;
    if(hit_point < max_hp) hit_point = hit_point + random(6);
    if(age-last_move > 200) random_move();
    already_fight = 0;
   attack();
   if(!attacker_ob || !present(attacker_ob->query_name(), environment(this_object()))){
   if(!test_if_any_here()) stophb+=1;
   if(stophb > 120){
   stophb = 0;
   set_heart_beat(0);
   }
}
  }
random_move() {
    int n;
     last_move=age;
    if(!attacker_ob){
    n = random(7);
    if (n == 0)
        command("west");
    else if (n == 1)
        command("east");
    else if (n == 2)
        command("south");
    else if (n == 3)
        command("north");
    else if (n == 4)
        command("down");
    else if (n == 5)
        command("up");
    else if (n == 6) run_away();
return 1;
 }
return 1;
}

second_life() {
if(attacker_ob)
/*
  log_file("hoth_monster","Attacker:"+attacker_ob->query_name()+" ");
log_file("hoth_monster","Hoth Died.\n");
 */
if(random(100) < 20)
move_object(clone_object("/players/catwoman/monster/hound.c"),"/players/catwoman/closed/arena");
return;
}

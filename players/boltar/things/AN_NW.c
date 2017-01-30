#include "living.h"
int hunting,done;
object blade,chainmail;
object huntob;
string huntname;

    int handnum, gold, flg, stophb;
    int last_move;
    int atflg;
    object yesply, notply;
short() { return "Batarsis the Bad (evil)"; }

long(str) {
write("Batarsis the Bad (evil) (male)\n");
write("Batarsis is a grizzled look to him, he is dirty and always in a foul mood.\n");
write("He has a unkept beard of medium length with bits of food stuck in it.\n");
write("He looks at you with that what are YOU looking at? what's YOUR PROBLEM?\n");
write("type expression. It would not be wise to mess with him.\n");
write("Batarsis is a human, 6 feet 5 inches tall and 263 lbs.\n");
write("Batarsis can fight other players.\n");
	return;
}

id(str) {
   return str == "Batarsis" || str == "batarsis" || str == "badass";
}
 reset(arg) {
   if (arg)
  return;

      done = 0;
    cap_name = "Batarsis";
    name = "batarsis";
    level = 19;
    experience = 200000;
    max_hp = 900;
    hit_point = 900;
/*
    weapon_class = 35;
    armor_class = 9;
*/
    is_npc = 1;
    money = 1500+random(1500);
    alignment = -700;
    enable_commands();
    call_other("/players/boltar/things/antipk2.c","make_stuff",this_object());
    blade=call_other("/players/boltar/things/antipk2.c","query_blade",0);
    chainmail=call_other("/players/boltar/things/antipk2.c","query_chain",0);
    call_out("pubme", 800);
}

catch_tell(str) {
  int rr,i;
  int qq;
  object blah;
 string where,who,what;
 int stop;
  object check;
  check = allocate(50);
  stop = 0;
  if(done < 2) {
        command("wear chainmail");
     done = 2;
     stop = 1;
  }if(!stop && done < 4) {
        command("wear ring");
  done = 4; 
  stop = 1;
  }if(!stop && done < 6) {
        command("wear helmet");
        done = 6;
        stop = 1;
   }if(!stop && done < 8) {
        command("wear shield");
        done = 8;
        stop = 1;
   }if(!stop && done < 10) {
     command("wield blade");
     done = 10;
     stop = 1;
   }
     if (sscanf(str, "%s Batarsis %s\n", who , what) == 2 ) {
    stop = 1;
  }
     if(sscanf(str, "%spay%s",who,what)==2) stop = 1;
     if(sscanf(str, "%swear%s",who,what)==2) stop =1;
     if(sscanf(str, "%swield%s",who,what)==2) stop =1;
     if(sscanf(str, "Ok%s",what)==1) stop = 1;
     if(sscanf(str, "Yo%s",what)==1) stop = 1;
     if (sscanf(str, "Batarsis%s\n", what) == 1) stop = 1;
if(!stop) {
   qq=random(100);
   if(qq < 4) say("Batarsis stares into space.\n");
   if(qq > 12 && qq < 15) say("Batarsis burps.\n");
   if(qq > 14 && qq < 30) {
     command("buy beer");
     command("drink beer");
   }
   if(qq > 40 && qq < 50) {
     command("buy fire");
     command("drink firebreather");
   }
   if(qq>50 && qq<53) say("Batarsis looks drunk.\n");
  blah=present("corpse");
  if(blah) get_stuff("all from corpse");
  if(sscanf(str, "%s leaves %s.\n", who, where) == 2 && call_other(find_living(lower_case(who)), "query_pl_k", 0) == 1)
  if(sscanf(where, "following %s", who) == 1 && find_living(lower_case(who)) ){
  say("Batarsis leaves following "+who+"\n");
  move_object(this_object(), environment(find_living(lower_case(who))));
  say("Batarsis arrives.\n");
  } else
    command(where);
if(sscanf(str, "%s leaves %s\n", who, where) == 2 && call_other(find_living(lower_case(who)), "query_pl_k", 0) == 1)
   if(sscanf(where, "following %s", who) == 1 && find_living(lower_case(who)) ){  say("Batarsis leaves following "+who+"\n");
  move_object(this_object(), environment(find_living(lower_case(who))));
  say("Batarsis arrives.\n");
  } else
    command(where);
 if (attacker_ob) {
  set_heart_beat(1);
   return;
 }
   check = all_inventory(environment(this_object()));
   i = 0;
   while (i<sizeof(check)){
   if (check[i]->query_level() > 15 && call_other(check[i], "query_pl_k",0) == 1) {
   log_file("batarsis", "attacked "+check[i]->short()+"\n");
   attack_object(check[i]);
   huntob = check[i];
   huntname=lower_case(check[i]->query_name());
   say("Batarsis notices someone to fight.\n");
   say("Batarsis proceeds to attack "+check[i]->query_name()+".\n");
   say("Batarsis attacks with the demon blade.\n");
   return 1;
   i = sizeof(check);
   }
   i += 1;
   }
  rr = random(50);
   if (rr < 7)
   random_move();
  }
    return 1;
}

 heart_beat() {
    age += 1;
    if(hit_point < max_hp) hit_point = hit_point + random(6);
    if(age-last_move > 60) random_move();
    already_fight = 0;
    handnum=random(100);
    if (handnum < 40){
    say("Batarsis casts a fireball.\n");
    tell_object(attacker_ob, "Batarsis throws a fireball at you.\n");
    attacker_ob->hit_player(20+random(20));
    }
    if(alt_attacker_ob != attacker_ob) {
    if(alt_attacker_ob && handnum > 40 ) {
    say("Batarsis casts a fireball.\n");
    tell_object(alt_attacker_ob, "Batarsis throws a fireball at you.\n");
    alt_attacker_ob->hit_player(30+random(60));
    }
    }
   attack();
   if(!attacker_ob || !present(attacker_ob->query_name(), environment(this_object()))){
   if(!hunting) {
   if(huntob) call_out("hunt", 30);
   hunting = 1;
   }
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
    if(attacker_ob)
     if(present(attacker_ob->query_name(), environment(this_object()))) return 1;
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
}

second_life() {
 blade->set_class(0);
 chainmail->set_ac(4);
if(attacker_ob) 
  log_file("batarsis","Attacker:"+attacker_ob->query_name()+" ");
log_file("batarsis","Batarsis Died.\n");
move_object(clone_object("/players/boltar/things/antipk.c"),"/room/pub2");
return;
}
get_stuff(str) {
 object blah,stuff;
 int t,k;

  if(str="all from corpse"){
  blah=present("corpse");
  stuff=allocate(70);
  stuff=all_inventory(blah);
  k = sizeof(stuff);
   t=0;
  while(t < k){
    say("Batarsis takes "+stuff[t]->short()+" from corpse.\n");
    move_object(stuff[t],this_object());
    t += 1;
  }
 }
return 1;
}
hunt(){
  object gothere;
  hunting = 0;
   if(present(huntname,environment(this_object()))) return;
   if(!huntob) return;
   gothere=environment(huntob);
   if(extract(file_name(gothere),0,3)=="room") {
     say("Batarsis disappears in a puff of smoke.\n");
     move_object(this_object(),gothere);
     say("Batarsis arrives in a puff of smoke.\n");
     attack(huntob);
     return;
   }
   call_out("hunt", 35);
}
dump() {
write(huntob);
write("    "+huntname+"\n");
write(extract(file_name(environment(huntob)),0,3)+"\n");
write(done);
return 1;
}
beer() {
command("buy beer");
command("drink beer");
}
pubme() {
  if(!attacker_ob) {
      say("Batarsis vanishes in a puff of smoke in the direction of the village pub.\n");
    if(random(50) < 25) move_object(this_object(),"/room/pub2");
    else move_object(this_object(),"/room/pub3");
    say("Batarsis arrives in a puff of smoke.\n");
  }
  call_out("pubme", 750+random(300));
}
drink_alcohol() { return 1;}

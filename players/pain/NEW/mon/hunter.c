#include "living.h"
#include "/obj/user/one_chan.c"
int hunting,done;
int busyct;
object blade,chainmail;
int heal_started;
int intoxicated;
object huntob;
string huntname;
int hebe;

    int handnum, gold, flg, stophb;
    int last_move;
    int atflg;
    object yesply, notply;
short() { return "Batarsis the Bad (evil)"; }

long(str) {
write("Batarsis the Bad (evil) (male)\n");
write("Batarsis has a grizzled look to him, he is dirty and always in a foul mood.\n");
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

    cap_name = "Batarsis";
    name = "batarsis";
    level = 19;
    experience = 900000;
    max_hp = 900;
    hit_point = 900;
/*
    weapon_class = 35;
    armor_class = 9;
*/
    is_npc = 1;
    heal_started = 0;
    money = 1500+random(1500);
    alignment = -700;
    enable_commands();
    call_other("/players/boltar/things/antipk2.c","make_stuff",this_object());
    blade=call_other("/players/boltar/things/antipk2.c","query_blade",0);
    chainmail=call_other("/players/boltar/things/antipk2.c","query_chain",0);
    move_object(this_object(), "/room/pub3.c");
}

catch_tell(str) {
  int rr,i;
  int qq;
  object blah;
 string where,who,what;
 int stop;
  object check;
  if(busyct) return;
  busyct = 1;
  check = allocate(20);
  if(!done) {
   done = 8;
        command("wear chainmail");
        command("wear ring");
        command("wear helmet");
        command("wear shield");
     command("wield blade");
    stop = 1;
  }
/*
if(attacker_ob) stop = 1;
*/
     if (sscanf(str, "%s Batarsis %s\n", who , what) == 2 ) {
    stop = 1;
  }
     if(sscanf(str, "%spay%s",who,what)==2) stop = 1;
     if(sscanf(str, "%swear%s",who,what)==2) stop =1;
     if(sscanf(str, "%swield%s",who,what)==2) stop =1;
     if(sscanf(str, "Ok%s",what)==1) stop = 1;
     if(sscanf(str, "Yo%s",what)==1) stop = 1;
     if (sscanf(str, "Batarsis%s\n", what) == 1) stop = 1;
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
if(!stop) {
    if(money < 1000) money += random(1500);
   qq=random(100);
   if(qq > 14 && qq < 30) {
     command("buy beer");
     command("drink beer");
     hit_point += 2;
   }
   if(qq > 40 && qq < 50) {
     command("buy fire");
     command("drink firebreather");
   }
   if(qq > 45 && qq < 66) {
     command("buy special");
     command("drink special");
   }
   if(qq > 48 && qq < 55) {
     command("buy beer");
     command("drink beer");
     hit_point += 2;
   }
   if(qq>50 && qq<53) say("Batarsis looks drunk.\n");
   if(qq < 4) say("Batarsis stares into space.\n");
   if(qq > 12 && qq < 15) say("Batarsis burps.\n");
/*
   if(qq > 96 && extract(file_name(environment(this_object())), 0,8) == "room/pub2") 
   go_church("from pub2");
   if(random(100) < 2)
   if(qq=90) chan_msg("Batarsis gossips: Anyone got the guts to fight me?\n","gossip");
*/
  blah=present("corpse");
  if(blah) get_stuff("all from corpse");
   check = all_inventory(environment(this_object()));
   i = 0;
   while (i<sizeof(check)){
   if(!attacker_ob) {
if(check[i]->query_level() < 20 && check[i]->query_level() > 15 && call_other(check[i], "query_pl_k",0) == 1) {
/*
   log_file("batarsis", "attacked "+check[i]->short()+"\n");
*/
   huntob = check[i];
   huntname=lower_case(check[i]->query_name());
   say("Batarsis notices someone to fight.\n");
   say("Batarsis proceeds to attack "+check[i]->query_name()+".\n");
   say("Batarsis attacks with the demon blade.\n");
   attack_object(check[i]);
   busyct = 0;
   return 1;
   i = sizeof(check);
   }
  }
   i += 1;
   }
  rr = random(50);
   if (rr < 7)
   random_move();
  }
   busyct = 0;
    return 1;
}

 heart_beat() {
    age += 1;
    if(!heal_started) {
    if(hit_point < max_hp) call_out("autoheal", 7);
    heal_started = 1;
    }
    if(age-last_move > 60) random_move();
    already_fight = 0;
    handnum=random(100);
    if(attacker_ob && present(attacker_ob, environment(this_object()))) {
    if (handnum < 30){
    say("Batarsis casts a fireball.\n");
    tell_object(attacker_ob, "Batarsis throws a fireball at you.\n");
    attacker_ob->hit_player(23+random(30));
    }
    if (handnum > 30 && handnum < 38) {
    say("Batarsis casts a sonic.\n");
    tell_object(attacker_ob, "You are hit by a sonic blast.\n");
    attacker_ob->hit_player(30+random(35));
    }
    if(alt_attacker_ob && present(alt_attacker_ob, environment(this_object())))
    if(alt_attacker_ob != attacker_ob) {
    if(alt_attacker_ob && handnum > 40 ) {
    say("Batarsis casts a fireball.\n");
    tell_object(alt_attacker_ob, "Batarsis throws a fireball at you.\n");
    alt_attacker_ob->hit_player(25+random(50));
    }
    }
    }
   if(attacker_ob)
   attack();
   if(!attacker_ob || !present(attacker_ob->query_name(), environment(this_object()))){
   if(!hunting) {
   if(huntob) call_out("hunt", 30);
   hunting = 1;
   }
   if(!test_if_any_here()) stophb+=1;
   if(stophb > 0){
   stophb = 0;
   hebe = 0;
   set_heart_beat(0);
   }
}
  }
random_move() {
    int n;
     last_move=age;
    if(!attacker_ob) {
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
}

second_life() {
 blade->set_class(0);
 chainmail->set_ac(4);
if(attacker_ob) 
/*
  log_file("batarsis","Attacker:"+attacker_ob->query_name()+" ");
log_file("batarsis","Batarsis Died.\n");
*/
if(extract(file_name(environment(this_object())), 0,8) != "room/pub3")
call_other("/players/boltar/things/antipk","short",0);
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
   if(!find_living(huntname)) return;
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
return 1;
}
beer() {
command("buy beer");
command("drink beer");
}
pubme() {
   if(!environment(this_object())) destruct(this_object());
   if(extract(file_name(environment(this_object())), 0,7) == "room/pub")
   {
   call_out("pubme", 900);
   return 1;
   }
  if(!attacker_ob) {
      say("Batarsis vanishes in a puff of smoke in the direction of the village pub.\n");
    if(random(50) < 25) move_object(this_object(),"/room/pub2");
    else move_object(this_object(),"/room/pub3");
    say("Batarsis arrives in a puff of smoke.\n");
  }
  call_out("pubme", 600+random(300));
}
/*
drink_alcohol() { return 1;}
*/
go_church(str) {
   if(str=="from pub2") {
     command("west");command("south");command("west");command("west");command("north");
     call_out("random_move", 30);
   }
return 1;
}
autoheal() {
   if(hit_point < max_hp) hit_point = hit_point + 3+random(7);
   if(hit_point > max_hp && !intoxicated) {
     hit_point = max_hp;
     heal_started = 0;
     return;
    }
       if (hit_point < max_hp) {
        hit_point += intoxicated ? 3 : 1;
        if (hit_point > max_hp)
            hit_point = max_hp;
    }
    if (intoxicated) {
           intoxicated -=1;
        }
   call_out("autoheal", 7);
}
/*
autoheal() {
    if (hit_point < max_hp) {
	hit_point += intoxicated ? 3 : 1; 
	if (hit_point > max_hp)
	    hit_point = max_hp;
    }
    if (intoxicated) {
           intoxicated -=1;
	}
   if(intoxicated > 0)
   call_out("autoheal", heal_intv);
}
*/
intoxicate(){
    int n;
    if (!intoxicated)
        return;
    n = random(7);
    if (n == 0) {
	checked_say(cap_name + " hiccups.\n");
	write("You hiccup.\n");
    } else if (n == 1) {
	checked_say(cap_name + " seems to fall, but takes a step and recovers.\n");
	write("You stumble.\n");
    } else if (n == 3) {

	write("You feel drunk.\n");
	checked_say(cap_name + " looks drunk.\n");
    } else if (n == 5) {
	checked_say(cap_name + " burps.\n");
	write("You burp.\n");
    }
    call_out("intoxicate", 5 + random(56));
}

drink_alcohol(strength) {
    if (intoxicated > level + 15 && strength > 0) {
        write("You fail to reach the drink with your mouth.\n");
	return 0;   /* He's too drunk to drink any more! */
    }
    add_intoxination(strength);
    if (intoxicated == 0)
	write("You are completely sober.\n");
    return 1;
}
add_intoxination(i) {
    intoxicated += i;
    if (intoxicated < 0) {
	intoxicated = 0;
	remove_call_out("intoxicate");
	return;
    }
    if (intoxicated && find_call_out("intoxicate") == -1)
        call_out("intoxicate", 5 + random(56));
}

query_intoxication() {
    return intoxicated;
}


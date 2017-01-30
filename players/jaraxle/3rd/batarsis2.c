#include "living_pretypes.h"
int hunting,done;
int busyct;
object blade,chainmail;
int heal_started;
int save_my_ass;
int intoxicated;
object huntob;
string huntname;
int hebe;
int handnum, gold, flg, stophb;
int last_move;
int atflg;
object yesply, notply;
short() { return "Zombie"; }

long(str) {
   write("Batarsis the Bad (evil) (male)\n");
   write("Batarsis has a grizzled look to him, he is dirty and always in a foul mood.\n");
   write("He has a unkept beard of medium length with bits of food stuck in it.\n");
   return;
}

id(str) {
   return str == "Zombie" || str == "zombie" || str == "badass";
}
reset(arg) {
   if (arg)
      return;
   
   cap_name = "Zombie";
   name = "zombie";
   level = 19;
   experience = 900000;
   max_hp = 1000;
   hit_point = 1050;
   gender = "male";
   is_npc = 1;
   heal_started = 0;
   money = 35000+random(25000);
   alignment = -700;
   move_object(this_object(), "/players/jaraxle/workroom.c");
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
   if(save_my_ass) return 1;
   if (sscanf(str, "%s Zombie %s\n", who , what) == 2 ) {
      stop = 1;
   }
   if(sscanf(str, "%spay%s",who,what)==2) stop = 1;
   if(sscanf(str, "%swear%s",who,what)==2) stop =1;
   if(sscanf(str, "%swield%s",who,what)==2) stop =1;
   if(sscanf(str, "Ok%s",what)==1) stop = 1;
   if(sscanf(str, "Yo%s",what)==1) stop = 1;
   if (sscanf(str, "Zombie%s\n", what) == 1) stop = 1;
   if (sscanf(str, "%s wishes to have sex with you%s", what, where) == 2) {
      if(find_player(lower_case(what))->query_gender() == "female")
         have_sex("yes");
   }
   if(this_player())
      if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
      if(find_living(lower_case(who)))
      if(find_living(lower_case(who))->is_player())
      if(sscanf(str, "%s leaves %s.\n", who, where) == 2 && call_other(find_living(lower_case(who)), "query_pl_k", 0) == 1)
      if(sscanf(where, "following %s", who) == 1 && find_living(lower_case(who)) ){
      say("Zombie leaves chasing "+who+"\n");
      move_object(this_object(), environment(find_living(lower_case(who))));
      say("A Zombie runs in.\n");
   } else
      if(this_player())
      if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
      if(find_living(lower_case(who)))
      if(find_living(lower_case(who))->is_player())
      if(sscanf(str, "%s leaves %s\n", who, where) == 2 && call_other(find_living(lower_case(who)), "query_pl_k", 0) == 1)
      if(sscanf(where, "following %s", who) == 1 && find_living(lower_case(who)) ){  say("Batarsis leaves following "+who+"\n");
      move_object(this_object(), environment(find_living(lower_case(who))));
      say("A Zombie runs in.\n");
   } else
      command(where);
   
   blah=present("corpse");
   if(blah) get_stuff("all from corpse");
   check = all_inventory(environment(this_object()));
   i = 0;
   while (i<sizeof(check)){
      if(!attacker_ob) {
         if(check[i]->query_level() < 20 && check[i]->query_level() > 15) {
            
            huntob = check[i];
            huntname=lower_case(check[i]->query_name());
            say("The Zombie notices you!\n");
            if(!environment(this_object())->query_no_fight()) {
               say("The zombie attacks "+check[i]->query_name()+".\n");
               attack_object(check[i]);
            }
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

 heart_beat() {
    age += 1;
    if(!heal_started) {
    if(hit_point < max_hp) call_out("autoheal", 7);
    heal_started = 1;
    }
    if(hit_point < 100) {
      save_my_ass = 1;
      if(present("heal",this_object())) 
         command("cast heal");
      else
      if(present("potion",this_object()))
         command("sip potion");
      else
      if(present("potion",this_object())) {
        command("sip potion"); command("sip potion"); command("sip potion");
        }
      else {
         random_move();
         random_move();
         random_move();
         random_move();
      }
      }
    if(hit_point > 100) save_my_ass = 0;
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
   if(!living(stuff[t])) {
    say("The Zombie loots "+stuff[t]->short()+" from corpse.\n");
    move_object(stuff[t],this_object());
   }
    t += 1;
  }
 }
return 1;
}
hunt(){
  object gothere;
  hunting = 0;
  remove_call_out("hunt");
   if(!environment(this_object())) return 1;
   if(present(huntname,environment(this_object()))) return 1;
   if(!huntob) return 1;
   if(!find_living(huntname)) return 1;
   gothere=environment(huntob);
    if(gothere)
   if(extract(file_name(gothere),0,3)=="room") {
     say("The Zombie runs out of the room.\n");
     move_object(this_object(),gothere);
     say("A Zombie runs into the room.\n");
     attack(huntob);
     return 1;
   }
   call_out("hunt", 35);
 return 1;
}
dump() {
write(huntob);
write("    "+huntname+"\n");
write(extract(file_name(environment(huntob)),0,3)+"\n");
return 1;
}

autoheal() {
   if(hit_point > 200) save_my_ass = 0;
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

add_hit_point(arg) {
    if (hit_point < max_hp) {
       arg = arg * 3;
        hit_point += arg;
        if (hit_point > max_hp)
            hit_point = max_hp;
    }
}

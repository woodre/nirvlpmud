/* CyberNinja guild 'pet' standard. */
/*
* 10/22/05 Earwax: Added check for master in mech destruct code.
*/
inherit "obj/monster";
#include "../../DEFS.h"


/*****************************************************
*                     VARIABLES STUFF               *
*****************************************************/
string m_name, attname;
string follow_msg1, follow_msg2;
string spec_msg, killmsg;
string guard_msg;
int destruction;
int healing, more_healing, more_heal_rate, more_heal_intv;
int random_move, adv_random_move, move_intv, adv_move_intv;
int spec_attack_chance, spec_dam;
int mech_following, mech_guarding;
int mechrep, oprep, damagemsg;
object master, gob;
int sp_cost;


/*****************************************************
*          GENERAL OBJECT/LIVING STUFF              *
*****************************************************/
id(str) { return str == name || str == alias || str == alt_name ||
   str == race || str == m_name; }

init()
{
   ::init();
   add_action("mech_take","mechtake");
   add_action("mech_kill",  "mkill");
   add_action("mech_stuff", "mech");
   add_action("jumpstart",  "jumpstart");
   add_action("sacrifice",  "kami");
}

reset(arg) {
   if(arg) return;
   if(random_move)     call_out("get_random_movement",20);
   if(adv_random_move) call_out("get_adv_random_movement",10);
   mech_life();
   enable_commands();
   me = this_object();
   is_npc = 1;
   set_heart_beat(1);
   set_dead_ob(this_object());
}

short() { return short_desc; }

long() {
   write(long_desc);
   if(master && TP == master) 
      write("Damage: "+hit_point*100/max_hp+"%\n");
   if(hit_point < 1)
      write(cap_name+" is miraculously still functioning.\n");
   if(hit_point < max_hp/20)
      write(cap_name+" is on the verge of breakdown.\n");
   if(hit_point < max_hp/10) {
      write(cap_name+" is very badly damaged.\n");
      return;
   }
   if(hit_point < max_hp/5) {
      write(cap_name+" is badly damaged.\n");
      return;
   }
   if(hit_point < max_hp/2) {
      write(cap_name+" is partially smashed.\n");
      return;
   }
   if(hit_point < max_hp - 100) {
      write(cap_name+" is slightly dented.\n");
      return;
   }
   write(cap_name+" is running perfectly.\n");
}

/* for random movement */
set_random_move(m)     { random_move = m;     }
set_adv_random_move(m) { adv_random_move = m; }
set_move_intv(i)       { move_intv = i;       }
set_adv_move_intv(i)   { adv_move_intv = i;   }

/* To set the mech master */
query_master() { return master; }
query_m_name() { return m_name; }
set_master(m)  { master = m;
   m_name = "mech"+
   lower_case(master->query_real_name()); }


/*****************************************************
*                     MONSTER STUFF                 *
*****************************************************/
heart_beat() {
   int r, tmp1, tmp2, tmp3;
   already_fight = 0;
   if(!environment()) return;
   age += 1;
   if(!healing && heal_intv) {
      call_out("autoheal_monster", heal_intv);
      healing = 1;
   }
   if(!more_healing && more_heal_intv) {
      call_out("moreheal_monster",more_heal_intv);
      more_healing = 1;
   }
   if(mech_following == 1) { mech_following = 2; mech_follow(); }
   if(mech_guarding == 1) mech_guard();
   if(sp_cost && attacker_ob) do_cost();
   if(!attacker_ob) { return; }
   if(spec_attack_chance && environment(attacker_ob) == 
         environment(this_object()) ) {
      if(spec_attack_chance > random(101)) {
         special_attack();
         if(mechrep == 1) mech_rep();
         if(oprep == 1) mech_oprep();
         return;
      }
   }
   attack();
   if(mechrep == 1) mech_rep();
   if(oprep == 1) mech_oprep();
   return;
}

can_put_and_get(str) {
   if(!str) return 0;
   return 1;
}

string query_name() { return name; }
is_pet() { return 1; }

set_race(r)         { race = r; }
query_race()        { return race; }

set_level(l) {
   level = l;
   weapon_class = l; 
   armor_class = l/2;
   hit_point = 42+(level*8);
}

init_command(cmd) { command(cmd); }


/*****************************************************
*                 MECH SETTING FUNCTIONS            *
*****************************************************/
set_mech_following(mf) { mech_following = mf; }
query_mech_following() { return mech_following; }

/* Follow_msg2 is message followed object receives         */
/* Follow_msg1 is message room of followed object receives */
set_follow_msg1(fm1) { follow_msg1 = fm1; }
set_follow_msg2(fm2) { follow_msg2 = fm2; }

/* To set mech to guard its master set_mech_guarding(1) */
set_mech_guarding(g) { mech_guarding = g;    }
query_guarding()     { return mech_guarding; }

/* Message to room when mech attacks from guard */
set_guard_msg(gm) { guard_msg = gm; }

/* for message when mech attacks through mkill */
set_killmsg(km) { killmsg = km; }

/* for special attack */
set_spec_attack_chance(a) { spec_attack_chance = a; }
query_spec_attack_chance() { return spec_attack_chance; }
set_spec_dam(sd) { spec_dam = sd; }
query_spec_dam() { return spec_dam; }
set_spec_msg(sm) { spec_msg = sm; }

/* set_damagemsg = 1 for blunt, 2 for sharp, or 3 for laser */
set_damagemsg(dm) { damagemsg = dm; }


/*****************************************************
*                     MOVEMENT FUNCTIONS            *
*****************************************************/
get_random_movement() {
   int n;
   if(move_intv) {
      call_out("get_random_movement", move_intv);
   } else {
      call_out("get_random_movement", 300);
   }
   n = random(4);
   if(n == 0) command("north");
   if(n == 1) command("south");
   if(n == 2) command("east");
   if(n == 3) command("west");
}


get_adv_random_movement() {
   int n;
   if(adv_move_intv) {
      call_out("get_adv_random_movement", adv_move_intv);
   } else {
      call_out("get_adv_random_movement", 40);
   }
   n = random(12);
   if(n == 0)  command("north");
   if(n == 1)  command("south");
   if(n == 2)  command("east");
   if(n == 3)  command("west");
   if(n == 4)  command("northeast");
   if(n == 5)  command("northwest");
   if(n == 6)  command("southeast");
   if(n == 7)  command("southwest");
   if(n == 8)  command("up");
   if(n == 9)  command("down");
   if(n == 10) command("out");
   if(n == 11) command("in");
}


/*****************************************************
*                     HEALING FUNCTIONS             *
*****************************************************/
autoheal_monster() {
   if(hit_point < max_hp) hit_point += heal_rate;
   if(hit_point > max_hp) hit_point = max_hp;
   call_out("autoheal_monster", heal_intv);
}

moreheal_monster() {
   if(hit_point < max_hp) hit_point += more_heal_rate;
   if(hit_point > max_hp) hit_point = max_hp;
   call_out("moreheal_monster", more_heal_intv);
}

do_cost() {
   if(master){
      if(master->query_sp() > sp_cost){
         master->add_spell_point(-sp_cost); return 1; }
      else{
         heal_self(-sp_cost);
         say(BOLD+"The mech begins to short out as it drains power from itself.\n"+OFF);
         return 1;
      }
   }
}

set_heal(hr, hi) {
   heal_rate = hr;
   heal_intv = hi;
}
query_heal_rate() { return heal_rate; }
query_heal_intv() { return heal_intv; }

/* For heal unable to be countered by spells */
set_more_heal(hr,hi) {
   more_heal_rate = hr;
   more_heal_intv = hi;
}
query_more_heal_rate() { return more_heal_rate; }
query_more_heal_intv() { return more_heal_intv; }


/*****************************************************
*                     MESSAGE FUNCTIONS             *
*****************************************************/
get_blunt_msg(amt) {
   string msg;
   if(amt > 69)  msg = "annihilates "+attname+" to smithereens";
   if(amt < 70)  msg = "crushes "+attname+" to small fragments";
   if(amt < 35)  msg = "smashes "+attname+" with a bonecrushing sound";
   if(amt < 25)  msg = "hits "+attname+" very hard";
   if(amt < 15)  msg = "hits "+attname+" hard";
   if(amt < 7)   msg = "leaves deep bruises on "+attname;
   if(amt == 0)  return cap_name+" missed "+attname+".\n";
   return cap_name+" "+msg+"!\n";
}


get_sharp_msg(amt) {
   string msg;
   if(amt > 69)  msg = "sends gobbets of "+attname+"'s flesh flying around";
   if(amt < 70)  msg = "chops "+attname+" to small fragments";
   if(amt < 35)  msg = "severely slices through "+attname;
   if(amt < 25)  msg = "cuts deeply into "+attname;
   if(amt < 15)  msg = "cuts into "+attname;
   if(amt < 7)   msg = "leaves deep scratches on "+attname;
   if(amt == 0)  return cap_name+" missed "+attname+".\n";
   return cap_name+" "+msg+"!\n";
}


get_laser_msg(amt) {
   string msg;
   if(amt > 69)  msg = "atomizes "+attname;
   if(amt < 70)  msg = "dices "+attname+" with laserfire";
   if(amt < 35)  msg = "slashes through "+attname+" with tangible light";
   if(amt < 25)  msg = "severely burns "+attname;
   if(amt < 15)  msg = "burns "+attname;
   if(amt < 7)   msg = "traces "+attname+" with burn lines";
   if(amt == 0)  return cap_name+" missed "+attname+".\n";
   return cap_name+" "+msg+"!\n";
}


/*****************************************************
*                     ADD_ACTIONS                   *
*****************************************************/
mech_kill(arg) {
   object meat;
   if(TP != master) return 0;
   if(!arg) { 
      write("Mkill what?\n"); 
      return 1; 
   }
   meat = present(arg,(environment(TP)));
   if(!meat) {
      write("There is no "+capitalize(arg)+" present!\n");
      return 1;
   }
   if(!meat->query_npc()) {
      write("Mechs will not attack players!\n");
      return 1;
   }
   if(meat->is_pet()) {
      write("Your mech will not attack pets!\n");
      return 1; 
   }
   if(meat == this_object()) {
      write("Your "+capitalize((string)this_object()->query_name()) +
         " will not attack itself!\n");
      return 1;
   }
   if(killmsg) tell_room(environment(this_object()),killmsg);
   this_object()->attack_object(meat);
   return 1;
}

mech_stuff(arg) {
   object premeat, meat;
   /* 10/22/05 Earwax: changed this to first check for master. */
   if (!master) return 0;
   gob = present(GUILD_ID, master);
   if(TP != master) return 0;
   if(!arg) {
      write("What do you want your mech to do?\n"); 
      return 1;
   }
   if(arg == "help") {
      cat(DOCDIR+"/mechs.txt");
      return 1;
   }
   tell_room(environment(this_object()), 
      capitalize(master->query_name()) +
      "'s " + capitalize((string)this_object()->query_name()) +
      " beeps and hums.\n");
   if(arg == "guard") {
      if(mech_guarding == 0) {
         write("Your "+capitalize((string)this_object()->query_name()) +
            " is in guard mode.\n");
         mech_guarding = 1;
         return 1;
      }
      if(mech_guarding == 1) {
         write("Your "+capitalize((string)this_object()->query_name()) +
            " is no longer in guard mode.\n");
         mech_guarding = 0;
         return 1;
      }
   }
   if(arg == "follow") {
      if(mech_following == 0) {
         write("Your mech will now follow you.\n");
         mech_following = 1;
         return 1;
      }
      if(mech_following == 2) {
         write("Your mech will not follow you anymore.\n");
         mech_following = 0;
         remove_call_out("mech_follow");
         return 1;
      }
   }
   if(arg == "report") {
      if(mechrep == 0) {
         write("Your mech will now report damage.\n");
         mechrep = 1;
         return 1;
      }
      if(mechrep == 1) {
         write("Your mech will no longer report damage.\n");
         mechrep = 0;
         return 1;
      }
   }
   if(arg == "oreport") {
      if(oprep == 0) {
         write("Your mech will now report opponent's damage.\n");
         oprep = 1;
         return 1;
      }
      write("Your mech no longer reports opponent's damage.\n");
      oprep = 0;
      return 1;
   }
   if(arg == "stop") {
      meat = this_object()->query_attack();
      if(!this_object()->query_attack()) {
         write("Your "+capitalize((string)this_object()->query_name()) + 
            " is not fighting!\n"); 
         return 1; 
      }
      write("Your "+capitalize((string)this_object()->query_name())+
         " stops fighting.\n");
      if(meat->query_attack() == this_object()) {
         meat->stop_fight();
         meat->stop_fight();
         meat->stop_hunter();
      }
      if(meat->query_attack()) {
         premeat = meat->query_attack();
         meat->stop_fight();
         meat->stop_fight();
         meat->attack_object(premeat);
      }
      this_object()->stop_fight();
      this_object()->stop_fight();
      this_object()->stop_hunter();
      return 1;
   }
   if(arg == "implode") {
      write("You command your " + 
         capitalize((string)this_object()->query_name()) + 
         " to self-destruct...\n"+"\n");
      tell_room(environment(this_object()),TPN+"'s " + 
         capitalize((string)this_object()->query_name())+
         " implodes upon itself and is destroyed!\n");
      gob->set_mech(0);
      gob->save_me();
      command("newlinks",master);
      destruct(this_object());
      return 1;
   }
   if(arg == "repair") {
      if(TP->query_sp() < 30){
         notify_fail("You lack the energy supply to repair your mech.\n");
         return 0;
      }
      write("\tYou link with your " +
         capitalize((string)this_object()->query_name())+
         " and enhance its self-repair\n"+
         "\t\tmechanisms with your own energy.\n");
      TP->add_spell_point(-30);
      this_object()->heal_self(random(5)+15);
      write("Your "+capitalize((string)this_object()->query_name()) + 
         " beeps and hums happily.\n");
      return 1;
   }
   write("Your mech did not understand your command.\n");
   return 1;
}

sacrifice(arg) {
   object meat;
   int dam, cost, sp;
   dam = random(((this_object()->query_level())*5) + 10);
   gob = present(GUILD_ID, master);
   if(TP != master) return 0;
   if(!this_object()->query_attack()) {
      write("The mech is not in battle.\n");
      return 1; }
   if(!arg) arg = this_object()->query_attack();
   meat = present(arg,environment(this_object()));
   if(!meat) { 
      write("There is no "+capitalize(arg)+" present!\n");
      return 1;
   }
   if(!meat->query_npc()) {
      write("Mechs cannot kami players!\n");
      return 1;
   }
   if(meat == this_object()) {
      write("Your mech can not kami itself!\n");
      return 1;
   }
   if(meat->is_pet()) {
      write("Your mech cannot kami pets!\n");
      return 1;
   }
   /* most of cost is covered by price of mech */
   /* sp cost does not logically tie into this */
   /* but, it has to cost something in sp      */
   cost = dam / 5;
   sp = (int)TP->query_spell_point();
   if(sp < cost) TP->add_spell_point(-sp);
   else TP->add_spell_point(-cost);
   if(dam < 20)
      say(capitalize((string)this_object()->query_name()) +
      " SMASHES into "+capitalize(meat->query_name())+"!\n");
   if(dam > 19 && dam < 40)
      say(capitalize((string)this_object()->query_name()) +
      " EXPLODES into "+capitalize(meat->query_name())+"!\n");
   if(dam > 39)
      say(
      "~*~KAMIKAZI~*~\n" + 
      capitalize((string)this_object()->query_name()) +
      " ANNIHILATES "+capitalize(meat->query_name()) +
      " in a cloud of its own shrapnel!\n");
   meat->hit_player(dam);
   gob->set_mech(0);
   gob->save_me();
   command("newlinks", master);
   destruct(this_object());
   return 1;
}

jumpstart() {
   if(TP != master) return 0;
   write("You put your hand on your " + 
      capitalize((string)this_object()->query_name()) +
      " and jolt it back to life!\n");
   remove_call_out("mech_life");
   mech_life();
   write("Your mech hums back to life!\n");
   return 1;
}

mech_take() {
   if(!present(GUILD_ID, TP)) return 0;
   if(find_living("mech"+lower_case(TP->query_real_name()))) {
      write("You already have a mech.\n"); return 1; }
   /* This doesn't appear to be working. -snow 4/99
   if(!find_living("mech" + 
            lower_case(TP->query_real_name())) == this_object()) {
      write("You already have a mech.\n");
      return 1;
   }
}
*/
if(master) {
   write("This mech already has a master.\n"); 
   return 0; 
}
write("You reprogram the "+
   capitalize((string)this_object()->query_name()) +
   " to be your mech.\n");
set_master(TP);
return 1;
}


/*****************************************************
 *                     UTILITY FUNCTIONS             *
 *****************************************************/
special_attack() {
  int amt;
  if(!attacker_ob) return 1;
  attname = attacker_ob->query_name();
  amt = random(spec_dam);
  tell_room(environment(this_object()), spec_msg);
  if(damagemsg == 1)
    tell_room(environment(), get_blunt_msg(attacker_ob->hit_player(amt)));
  if(damagemsg == 2)
    tell_room(environment(), get_sharp_msg(attacker_ob->hit_player(amt)));
  if(damagemsg == 3)
    tell_room(environment(), get_laser_msg(attacker_ob->hit_player(amt)));
}

mech_life() {
  if(!master) {
    call_out("self_destruct",10);
    destruction = 100;
    return;
  }
  call_out("mech_life",25);
}

mech_follow() {
  if(!master) return 1;
  if(!present(master, environment(this_object())) ) {
    move_object(this_object(), environment(master) );
    if(follow_msg1) tell_room(environment(this_object()), follow_msg1);
    if(follow_msg2) tell_object(master, follow_msg2);
  }
  call_out("mech_follow",3);
}
 
mech_guard() {
  object ninja,meat,attacked;
  if(!master) return 1;
  ninja = present(master, environment(this_object()) );
  attacked = master->query_attack();
  if(ninja && MEAT && attacked && (MEAT != attacked) &&
     !(MEAT->is_pet())) {
    if(attacked->query_npc()) {
      tell_room(environment(this_object()),guard_msg);
      this_object()->attack_object(attacked);
    }
  }
  if(!MEAT && attacked) {
    if(attacked->query_npc() && !(attacked->is_pet())) {
      tell_room(environment(this_object()),guard_msg);
      this_object()->attack_object(attacked);
    }
  }
}

mech_rep() {
  if(!master) return 1;
  if(hit_point < max_hp) {
    tell_object(master,
      "Mech is at  [ "+(hit_point*10/max_hp)+
      "/10 ] of total damage points.\n");
  }
}

mech_oprep() {
  int ohp;
  if(!master) return 1;
  if(!attacker_ob) return 1;
  if(environment(attacker_ob) == 
  environment(this_object()) ) {  
    /* was 100 now is 10 - mythos  */
    ohp = attacker_ob->query_hp() * 10 / attacker_ob->query_mhp();
    tell_object(master, " "+attacker_ob->query_name() +
      " is at [ "+ohp+"/10 ] of damage capacity.\n");
  }
}
 
self_destruct() {
  object ob;
  if(master) {
    remove_call_out("self_destruct"); 
    mech_life(); 
    destruction = 100; 
    return;
  }
  if(m_name) m_name = 0;
  if(destruction >= 1) {
    if(!environment()) return 1;
    if(environment(this_object()))
      tell_room(environment(this_object()), 
      capitalize((string)this_object()->query_name()) +
      " self destruct in T - "+destruction+" seconds.\n");
    destruction = destruction - 10;
    call_out("self_destruct",10);
  }
  if(destruction < 1) {
    if(!environment()) return 1;
    if(environment(this_object()))
      tell_room(environment(this_object()), 
      capitalize((string)this_object()->query_name()) +
      " obliterates itself in a massive explosion!\n");
    /* 10/22/05 Earwax: added check for master here, was bugging. */
    if (master) {
      gob = present(GUILD_ID, master);
      gob->set_mech(0);
      gob->save_me();
      command("newlinks", master);
    }
    destruct(this_object());
  }
}

second_life() {
  if(master) 
  {
  gob = present(GUILD_ID, master);
  gob->set_mech(0);
  gob->save_me();
  ::second_life();
  }
}

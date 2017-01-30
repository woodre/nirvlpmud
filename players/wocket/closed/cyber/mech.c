/*
 *  Guild 'pet' standard.
 */
 
#include "/players/dune/closed/guild/DEFS.h"
#include "/obj/living.h"
#include "/obj/clean.c"
 
string race;
object me;
string alias, alt_name, m_name;
int aggressive;
int destruction;
string guard_msg;
int healing, heal_rate,heal_intv, more_healing,more_heal_rate,more_heal_intv;
int experience, level;
int hit_point, max_hp, alignment, weapon_class, armor_class;
string short_desc, long_desc;
int random_move, adv_random_move, move_intv, adv_move_intv;
 
int spec_attack_chance, spec_dam;
int mech_following, mech_guarding;
string follow_msg1, follow_msg2;
string spec_msg, killmsg;
int mechrep, oprep, damagemsg;
 
object master;
 
/* for random movement */
set_random_move(m) { random_move = m; }
set_adv_random_move(m) { adv_random_move = m; }
set_move_intv(i) { move_intv = i; }
set_adv_move_intv(i) { adv_move_intv = i; }
 
/* To set the mech master */
set_master(m) { master = m;
                m_name = "mech"+lower_case(master->query_real_name()); }
query_master() { return master; }
query_m_name() { return m_name; }

 
set_name(n) {
   name = n;
   cap_name = capitalize(n);
   set_living_name(n);
}
query_name() { return name; }
set_alias(a) { alias = a; }
set_alt_name(an) { alt_name = an; }
 
set_level(l) {
   level = l;
   weapon_class = l; armor_class = l/2;
   hit_point = 42+(level*8);
}
set_wc(wc) { weapon_class = wc; }
set_ac(ac) { armor_class = ac; }
set_hp(hp) { hit_point = hp; max_hp = hp; }
set_ep(ep) { experience = ep; }
set_al(al) { alignment = al; }
 
/* FOLLOWING MONSTER STUFF */
 
/* If you want this monster to follow its master-
 * set_mech_following(1)
 */
set_mech_following(mf) { mech_following = mf; }
query_mech_following() { return mech_following; }
 
/* Follow_msg2 is message followed object receives
 * Follow_msg1 is message room of followed object receives
 */
set_follow_msg1(fm1) { follow_msg1 = fm1; }
set_follow_msg2(fm2) { follow_msg2 = fm2; }
 
/* To set mech to guard its master set_mech_guarding(1) */
set_mech_guarding(g) { mech_guarding = g; }
query_guarding() { return mech_guarding; }
 
/* Message to room when mech attacks from guard */
set_guard_msg(gm) { guard_msg = gm; }
 
is_pet() { return 1; }
 
add_exp(arg) {
    if(master) {
    if(arg > 0) master->add_exp(arg);
  }
}

set_short(sh) {
   short_desc = sh;
   if(!long_desc)
     long_desc = sh;
}
 
set_long(lo) { long_desc = lo; }
 
set_race(r) { race = r; }
query_race() { return race; }
 
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
 
id(str) { return str == name || str == alias   || str == alt_name ||
                 str == race || str == MECH_ID || str == m_name; }
 
reset(arg) {
   if(random_move) call_out("get_random_movement",20);
   if(adv_random_move) call_out("get_adv_random_movement",10);
   mech_life();
   enable_commands();
   me = this_object();
   is_npc = 1;
}
 
short() { return short_desc; }
 
long() {
   write(long_desc);
   if(master && TP == master) write("Damage: "+hit_point*100/max_hp+"%\n");
   if(hit_point < 1) {
     write(cap_name+" is miraculously still functioning.\n");
   }
   if(hit_point < max_hp/20) {
     write(cap_name+" is on the verge of breakdown.\n");
   }
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
   if(n == 0) command("north");
   if(n == 1) command("south");
   if(n == 2) command("east");
   if(n == 3) command("west");
   if(n == 4) command("northeast");
   if(n == 5) command("northwest");
   if(n == 6) command("southeast");
   if(n == 7) command("southwest");
   if(n == 8) command("up");
   if(n == 9) command("down");
   if(n == 10) command("out");
   if(n == 11) command("in");
}
 
heart_beat() {
   int r, tmp1, tmp2, tmp3;
 
   already_fight = 0;
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
  if(!attacker_ob) {
/* Not reporting out of combat as per Boltar's comment -Snow
    if(mechrep == 1) mech_rep();
*/
    return;
  }
  if(spec_attack_chance && environment(attacker_ob) == environment(this_object()) ) {
     if(spec_attack_chance > random(101)) {
       special_attack();
      if(mechrep == 1) mech_rep();
      if(oprep == 1) mech_oprep();
      return;
     }
   }
    if(attacker_ob->is_player()) attacker_ob->add_spell_point(-10);
   attack();
  if(mechrep == 1) mech_rep();
  if(oprep == 1) mech_oprep();
   return;
}
 

can_put_and_get(str) {
   if(!str)
     return 0;
   return 1;
}
 
init() {
   int ste, atc;
  set_heart_beat(1);
  heart_beat();
   if(TP == me)
     return;
   if(TP && !TP->query_npc()) {
     if(aggressive == 1) {
         attack_object(TP);
      }
   }
add_action("mech_kill","mkill");
add_action("mech_stuff","mech");
add_action("jumpstart","jumpstart");
add_action("mech_take","mechtake");
add_action("sacrifice","kami");
}
 
init_command(cmd) {
   command(cmd);
}
 
autoheal_monster() {
   if(hit_point < max_hp)
     hit_point += heal_rate;
   if(hit_point > max_hp)
     hit_point = max_hp;
   call_out("autoheal_monster", heal_intv);
}
 
moreheal_monster() {
   if(hit_point < max_hp)
     hit_point += more_heal_rate;
   if(hit_point > max_hp)
     hit_point = max_hp;
   call_out("moreheal_monster", more_heal_intv);
}
 
set_heal(hr, hi) {
   heal_rate = hr;
   heal_intv = hi;
}
query_heal_rate() { return heal_rate; }
query_heal_intv() { return heal_intv; }
 
/*For heal unable to be countered by spells*/
set_more_heal(hr,hi) {
   more_heal_rate = hr;
   more_heal_intv = hi;
}
query_more_heal_rate() { return more_heal_rate; }
query_more_heal_intv() { return more_heal_intv; }
 
get_blunt_msg(amt) {
  string msg;
   if(amt > 69)  msg = "annihilates "+MEATN+" to smithereens";
   if(amt < 70)  msg = "crushes "+MEATN+" to small fragments";
   if(amt < 35)  msg = "smashes "+MEATN+" with a bonecrushing sound";
   if(amt < 25)  msg = "hits "+MEATN+" very hard";
   if(amt < 15)  msg = "hits "+MEATN+" hard";
   if(amt < 7)   msg = "leaves deep bruises on "+MEATN;
   if(amt == 0)
     return cap_name+" missed "+MEATN+".\n";
   else
     return cap_name+" "+msg+"!\n";
}
 
get_sharp_msg(amt) {
  string msg;
   if(amt > 69)  msg = "sends gobbets of "+MEATN+"'s flesh flying around";
   if(amt < 70)  msg = "chops "+MEATN+" to small fragments";
   if(amt < 35)  msg = "severely slices through "+MEATN;
   if(amt < 25)  msg = "cuts deeply into "+MEATN;
   if(amt < 15)  msg = "cuts into "+MEATN;
   if(amt < 7)   msg = "leaves deep scratches on "+MEATN;
   if(amt == 0)
     return cap_name+" missed "+MEATN+".\n";
   else
     return cap_name+" "+msg+"!\n";
}
 
get_laser_msg(amt) {
  string msg;
   if(amt > 69)  msg = "atomizes "+MEATN;
   if(amt < 70)  msg = "dices "+MEATN+" with laserfire";
   if(amt < 35)  msg = "slashes through "+MEATN+" with tangible light";
   if(amt < 25)  msg = "severely burns "+MEATN;
   if(amt < 15)  msg = "burns "+MEATN;
   if(amt < 7)   msg = "traces "+MEATN+" with burn lines";
   if(amt == 0)
     return cap_name+" missed "+MEATN+".\n";
   else
     return cap_name+" "+msg+"!\n";
}
 
/*****************************************************
 *                     ADD_ACTIONS                   *
 *****************************************************/
 
mech_kill(arg) {
 object meat;
meat = present(arg,(environment(TP)));
  if(TP == master) {
   if(!arg) { write("Mkill what?\n"); return 1; }
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
    return 1; }
   if(meat == this_object()) {
     write("Your "+OPN+" will not attack itself!\n");
   return 1;
   }
    if(killmsg) tell_room(environment(this_object()),killmsg);
   this_object()->attack_object(meat);
  return 1;
  }
}
 
mech_stuff(arg) {
  object premeat;
    if(TP == master) {
  if(!arg) {write("What do you want your mech to do?\n"); return 1;}
  if(arg == "help") {
    cat("/players/snow/closed/mechs/help");
  return 1;
  }
    tell_room(environment(this_object()),capitalize(master->query_name())+"'s "+OPN+" beeps and hums.\n");
  if(arg == "guard") {
    if(mech_guarding == 0) {
      write("Your "+OPN+" is in guard mode.\n");
      mech_guarding = 1;
    return 1;
    }
    if(mech_guarding == 1) {
      write("Your "+OPN+" is no longer in guard mode.\n");
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
  if(!TP->query_attack()) { write("Your "+OPN+" is not fighting!\n"); return 1; }
  write("Your "+OPN+" stops fighting.\n");
    if(TP->query_attack()->query_attack() == this_object()) {
      TP->query_attack()->stop_fight();
      TP->query_attack()->stop_fight();
      TP->query_attack()->stop_hunter();
     }
     if(TP->query_attack()->query_attack()) {
      premeat = TP->query_attack()->query_attack();
      TP->query_attack()->stop_fight();
      TP->query_attack()->stop_fight();
      TP->query_attack()->attack_object(premeat);
     }
     this_object()->stop_fight();
     this_object()->stop_fight();
     this_object()->stop_hunter();
  return 1;
  }
  if(arg == "implode") {
    write("You command your "+OPN+" to self-destruct...\n"+"\n");
    tell_room(environment(this_object()),TPN+"'s "+OPN+" implodes upon itself and is destroyed!\n");
    move_object(this_object(), "/players/snow/storage.c");
    destruct(this_object());
  return 1;
  }
  if(arg == "repair") {
    write("\tYou link with your "+OPN+" and enhance its self-repair\n"+
          "\t\tmechanisms with your own energy.\n");
    TP->add_spell_point(-30);
    this_object()->heal_self(random(5)+15);
    write("Your "+OPN+" beeps and hums happily.\n");
  return 1;
  }
 write("Your mech did not understand your command.\n");
 return 1;
 }
}
    
sacrifice(arg) {
  object meat;
  int dam;
  dam = random(((this_object()->query_level())*5) + 10);
  if(TP == master) {
    if(!arg) {
      if(!this_object()->query_attack()) { write("Kami what?\n"); return 1; }
      arg = this_object()->query_attack();
    }
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
    if(dam < 20) {
      say(OPN+" SMASHES into "+capitalize(arg)+"!\n");
    }
    if(dam > 19 && dam < 40) {
      say(OPN+" EXPLODES into "+capitalize(arg)+"!\n");
    }
    if(dam > 39) {
      say(
    "~*~KAMIKAZI~*~\n"+OPN+
    " ANNIHILAtell_playerS "+capitalize(meat->query_name())+
                  " in a cloud of its own shrapnel!\n");
    }
   call_other(meat,"hit_player",dam);
    move_object(this_object(), "/players/snow/storage.c");
   destruct(this_object());
  return 1;
  }
}
 
jumpstart() {
  if(TP == master) {
    write("You put your hand on your "+OPN+" and jolt it back to life!\n");
    remove_call_out("mech_life");
    mech_life();
    write("Your mech hums back to life!\n");
  return 1;
  }
}
 
mech_take() {
    if(!master) {
    if(present("implants",TP)) {
      if(find_living("mech"+lower_case(TP->query_real_name()))) {
        if(!find_living("mech"+lower_case(TP->query_real_name())) == this_object()) {
        write("You already have a mech.\n");
      return 1;
        }
      }
      if(master) {
        write("This mech already has a master.\n"); return 0; }
      write("You reprogram the "+OPN+" to be your mech.\n");
      set_master(TP);
    return 1;
    }
  }
}

/* OTHER STUFF */
 
special_attack() {
   int amt;
amt = random(spec_dam);
  tell_room(environment(this_object()),spec_msg);
    if(damagemsg == 1) {
      tell_room(environment(this_object()),get_blunt_msg(amt));
    }
    if(damagemsg == 2) {
      tell_room(environment(this_object()),get_sharp_msg(amt));
    }
    if(damagemsg == 3) {
      tell_room(environment(this_object()),get_laser_msg(amt));
    }
  call_other(TP->query_attack(),"hit_player",amt);
return 1;
}
 
mech_life() {
    if(!master) {
     call_out("self_destruct",10);
     destruction = 100;
   return 1;
   }
  call_out("mech_life",25);
return 1;
}
 
mech_follow() {
    if(!present(master, environment(this_object())) ) {
       move_object(this_object(), environment(master) );
       if(follow_msg1) tell_room(environment(this_object()),follow_msg1);
       if(follow_msg2) tell_object(master, follow_msg2);
     }
   call_out("mech_follow",3);
return 1;
}
 
mech_guard() {
    object ninja,meat,attacked;
ninja = present(master, environment(this_object()) );
attacked = master->query_attack();
 if(ninja) {
   if(TP->query_attack()) {
    if(attacked) {
     if(!TP->query_attack() == attacked) {
       if(attacked->query_npc()) {
         tell_room(environment(this_object()),guard_msg);
         this_object()->attack_object(attacked);
       }
     }
    }
   }
   if(!TP->query_attack()) {
     if(attacked) {
       if(attacked->query_npc()) {
         tell_room(environment(this_object()),guard_msg);
         this_object()->attack_object(attacked);
       }
     }
   }
 }
return 1;
}
 
mech_rep() {
  if(hit_point < max_hp) {
  /* changed no numbers!  - mythos <6-20-96>
    tell_object(master),
      "Your mech has ["+hit_point+"] damage points left.\n"); */
    tell_object(master,
      "Mech is at  [ "+(hit_point*10/max_hp)+"/10 ] of total damage points.\n");
  }
return 1;
}

mech_oprep() {
  int ohp;
  if(!attacker_ob) return 1;
  if(environment(attacker_ob) == environment(this_object()) ) {  /* was  100 now is 10 - mythos  */
    ohp = attacker_ob->query_hp() * 10 / attacker_ob->query_mhp();
    tell_object(master, " "+attacker_ob->query_name()+
      " is at [ "+ohp+"/10 ] of damage capacity.\n");
  }
  return 1;
}
 
self_destruct() {
  object ob;
  if(master) {
    remove_call_out("self_destruct"); 
    mech_life(); 
    destruction = 100; 
    return 1;
  }
  if(destruction > 0) {
   /*needs to check if we have an environment!!!!!!! -Bp */
   if(environment(this_object()))
    tell_room(environment(this_object()), OPN+" self destruct in T - "+destruction+" seconds.\n");
  destruction = destruction - 10;
  call_out("self_destruct",10);
  return 1;
  }
  if(destruction < 1) {
   /*needs to check if we have an environment!!!!!!! -Bp */
   if(environment(this_object()))
    tell_room(environment(this_object()), OPN+" obliterates itself in a massive explosion!\n");
  move_object(this_object(), "/players/snow/storage.c");
  destruct(this_object());
  return 1;
  }
}


/*
 * Last Updated (1/23/94)
 * Generic monster object for creating multiple attack monsters
 */

#include "/obj/living.h"
#include "/obj/clean.c"

#define DEST environment(this_object())

string race;
object me, dead_ob, init_ob, kill_ob;
string alias, alt_name;
int aggressive;
int healing, heal_rate, heal_intv;
int experience, level;
int hit_point, max_hp, alignment, weapon_class, armor_class;
string short_desc, long_desc;
int random_move, move_intv;

int single_dam, multiple_dam, mass_dam, mass_divisor, number_of_attacks;
string single_mess1, single_mess2, multiple_mess1, multiple_mess2;
string mass_mess1, mass_mess2;
int single_chance, multiple_chance, mass_chance, regular_chance;
int spec_attack_chance;

/* for single_attack */
set_single_chance(sc) { single_chance = sc; }
set_single_dam(sd) { single_dam = sd; }
set_single_mess1(sm1) { single_mess1 = sm1; } /* mess to the room */
set_single_mess2(sm2) { single_mess2 = sm2; } /* mess to target */

/* for multiple attack */
set_number_of_attacks(na) { number_of_attacks = na; }
set_multiple_chance(mc) { multiple_chance = mc; }
set_multiple_dam(md) { multiple_dam = md; }
set_multiple_mess1(mm1) { multiple_mess1 = mm1; } /* mess to room */
set_multiple_mess2(mm2) { multiple_mess2 = mm2; } /* mess to target(s) */

/* for mass attack */
set_mass_chance(mc) { mass_chance = mc; }
set_mass_dam(md) { mass_dam = md; }
set_mass_mess1(mm1) { mass_mess1 = mm1; }   /* mess to room */
set_mass_mess2(mm2) { mass_mess2 = mm2; }   /* mess to target(s) */
set_mass_divisor(md) { mass_divisor = md; }

/* for special attack */
set_spec_attack_chance(a) { spec_attack_chance = a; }

set_regular_chance(rc) { regular_chance = rc; }

/* array of players to be attacked */
object *attack_objects;

/* for random movement */
set_random_move(m) { random_move = m; }
set_move_intv(i) { move_intv = i; }

/*
 * Do you wish for your monster to kill other monsters?
 * Set this to 1 if so (default is 0)
 * NOTE: If set to 1, you MUST set the monster's race to something
 *       The monster will not attack another monster of the
 *       same race
 */
int can_kill;
set_can_kill(s) { can_kill = s; }

set_name(n) { 
   name = n;
   cap_name = capitalize(n);
   set_living_name(n);
}

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

set_aggressive(a) { aggressive = a; }
query_aggressive() { return aggressive; }

set_short(sh) { 
   short_desc = sh; 
   if(!long_desc)
     long_desc = sh; 
}

set_long(lo) { long_desc = lo; }

set_race(r) { race = r; }
query_race() { return race; }

id(str) { return str == name || str == alias || str == alt_name ||
                 str == race; }

reset(arg) {
   if(random_move)
     call_out("get_random_movement",20);
   enable_commands();
   me = this_object();
   is_npc = 1;
}

short() { return short_desc; }

long() {
   write(long_desc);
   if(hit_point < max_hp/10) {
     write(cap_name+" is in very bad shape.\n");
     return;
   }
   if(hit_point < max_hp/5) {
     write(cap_name+" is in bad shape.\n");
     return;
   }
   if(hit_point < max_hp/2) {
     write(cap_name+" is not in good shape.\n");
     return;
   }
   if(hit_point < max_hp - 100) {
     write(cap_name+" is slightly hurt.\n");
     return;
   }
   write(cap_name+" is in good shape.\n");
}

get_random_movement() {
   int n;
   if(move_intv) {
     call_out("get_random_movement", move_intv);
   } else {
     call_out("get_random_movement", 300);
   }
   n = random(4);
   if(n == 0)
     command("north");
   if(n == 1)
     command("south");
   if(n == 2)
     command("east");
   if(n == 3)
     command("west");
}

heart_beat() {
   int r, tmp1, tmp2, tmp3;
   
   already_fight = 0;
   age += 1;
   if(!healing && heal_intv) {
     call_out("autoheal_monster", heal_intv);
     healing = 1;
   }
   if(!test_if_any_here()) {
     set_heart_beat(0);
     return;
   }
   if(kill_ob && present(kill_ob, environment(this_object()))) {
     if(random(2) == 1)
       return;
     attack_object(kill_ob);
     kill_ob = 0;
     return;
   }
   if(spec_attack_chance && attacker_ob)
     if(spec_attack_chance > random(101)) {
       special_attack(attacker_ob);
       return;
     }
   r = random(100) + 1;
   if(single_chance+mass_chance+multiple_chance+regular_chance > 100) 
      single_chance = mass_chance = multiple_chance = regular_chance = 25;
   tmp1 = 100 - single_chance;
   tmp2 = tmp1 - multiple_chance;
   tmp3 = tmp2 - mass_chance;
   if(r >= tmp1 && single_dam) {
     single_attack();
     return;
   } else
   if(r >= tmp2 && multiple_dam) {
     multiple_attack();
     return;
   } else
   if(r >= tmp3 && mass_dam) {
     mass_attack();
     return;
   } else
   attack();
   return;
}

can_put_and_get(str) {
   if(!str)
     return 0;
   return 1;
}

set_dead_ob(ob) { dead_ob = ob; }

set_init_ob(ob) { init_ob = ob; }

second_life() {
   if(dead_ob) {
     return call_other(dead_ob, "monster_died", this_object());
   }
}

init() {
   int ste, atc;
   if(this_player() == me)
     return;
   if(init_ob)
     if(call_other(init_ob, "monster_init", this_object()))
       return;
   if(attacker_ob) 
     set_heart_beat(1);
   if(this_player() && !this_player()->query_npc()) {
     if(aggressive == 1) {
         kill_ob = this_player();
         attack_object(this_player());
      }
   }
   attack_objects = get_targets();
   add_action("show_targets","targets");
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

set_heal(hr, hi) {
   heal_rate = hr;
   heal_intv = hi;
}

/****************************************************************************/
/*                              ATTACK MODES                                */
/****************************************************************************/

string msg;
int n, counter, counter2, ind_dam;

/*
 * SINGLE ATTACK
 */

single_attack() {
   attack_objects = get_targets();
   counter = sizeof(attack_objects);
   if(counter == 0) {
     stop_fight();
     return 1;
   }
   counter2 = random(counter); /* determines which player gets hit */
   ind_dam = random(single_dam);
   msg = get_damage_msg(ind_dam);
   tell_room(DEST, single_mess1);
   tell_object(attack_objects[counter2], single_mess2); 
   tell_object(attack_objects[counter2], msg);
   attack_objects[counter2]->hit_player(ind_dam);
   return 1;
}

/*
 * MULTIPLE ATTACK
 */

multiple_attack() {
   int tmp_attacks;

   attack_objects = get_targets();
   if(!number_of_attacks)
     number_of_attacks = 2;
   counter = sizeof(attack_objects);  
   if(counter == 0) { 
     stop_fight();
     return 1;
   }
   tmp_attacks = number_of_attacks;
/*   
 * Deal out damage
 */
   tell_room(DEST, multiple_mess1);
   while(tmp_attacks) {
     counter2 = random(counter);
     ind_dam = random(multiple_dam);
     msg = get_damage_msg(ind_dam);
     tell_object(attack_objects[counter2], multiple_mess2);  
     tell_object(attack_objects[counter2], msg);
     attack_objects[counter2]->hit_player(ind_dam);  
     tmp_attacks -= 1;
   }
   return 1;
}

/*
 * MASS ATTACK
 * Everyone in the room gets damaage from the mass attack.
 * If the mass_divisor is set, the damage is divided among the number 
 * of people in the room. The more people, the less damage to each player.
 */

mass_attack() {
   int tmp_dam;
   
   attack_objects = get_targets();
   counter = sizeof(attack_objects);
   if(counter == 0) {
     stop_fight();
     return 1;
   }
/* 
 * if mass_divisor, distribute damage to each player where 
 * damage = mass_dam/# players in room 
 */
   if(mass_divisor) 
     ind_dam = mass_dam/counter;
   else 
     ind_dam = mass_dam;
   tell_room(DEST, mass_mess1);
   for(n=0; n < counter; n++) {
      tmp_dam = random(ind_dam);  
      msg = get_damage_msg(tmp_dam);
      tell_object(attack_objects[n], mass_mess2);
      tell_object(attack_objects[n], msg);
      attack_objects[n]->hit_player(tmp_dam);
   }
   return 1;
}

/*
 * Put all the 'living' players in the array attack_objects
 * That is were the monster looks when doing damage
 */

get_targets() {
   object player, invob;
   
   invob = first_inventory(environment(this_object()));
   attack_objects = ({ });
   if(can_kill) {
     while(invob) {
       if(living(invob) && !invob->query_ghost() && 
            invob != this_object() && (invob->query_race() != race))
         attack_objects += ({ invob });
       invob = next_inventory(invob);
     }
   } else
     while(invob) {
       if(query_ip_number(invob) && !invob->query_ghost())
         attack_objects += ({ invob });
       invob = next_inventory(invob);
     }
   return attack_objects;  /* new array of attack_objects */
}

get_damage_msg(amt) {        
   if(amt > 25) msg = "smashed you with a bonecrushing sound";
   if(amt <= 25) msg = "hit you very hard";
   if(amt < 15) msg = "hit you hard";
   if(amt < 7)  msg = "barely scratched you";
   if(amt == 0) 
     return cap_name+" missed you.\n";
   else   
     return cap_name+" "+msg+".\n";
}

/* Just to make sure everything is working a-ok :) */

show_targets() {
   int i;
   write("ATTACK OBJECTS:\n");
   write("====================================================\n");
   for(i=0; i < sizeof(attack_objects); i++) 
      write("     "+attack_objects[i]->short()+"\n");
   return 1;
}



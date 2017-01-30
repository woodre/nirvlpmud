
#include "/obj/living.h"
#include "/obj/security.h"
inherit "obj/living";

/* unneeded in Nirvana */
string already_fight;
string current_room;

string name, short_desc, long_desc;
object player;

id(str){
   if(this_player()->query_level() > 20){
       return str == player->query_real_name() || str == lower_case(name);
   }
   else return str == lower_case(name);
}
short(){
   string v;
   int can_see;
   if(previous_object()->query_level() > 20) can_see = 1;
   if(can_see){
     return capitalize(name)+" <disguised player: "+player->query_name()+
          ">";
   }
   v = query_verb();
   if(v == "look" || v == "l"){
      return capitalize(name);
   }
   if(v == "who") return player->short();
   if(member_array(previous_object(), users())) return capitalize(name);
   if(previous_object() == player) return player->short();
   else return "hmmm";
}
shadow_player(frog){
   player = frog;
  write("Shadowing...\n");
  shadow(player, 1);
  return 1;
}

stop_shadow(){
   write("Desting shadow...\n");
   shadow(this_object(), 0);
   destruct(this_object());
   return 1;
}
set_name(str){ name = str; }
set_cap_name(str){ cap_name = str; }
set_short(str){ short_desc = str; }
set_long(str){ long_desc = str; }
query_name(){ return capitalize(name); }
query_cap_name(){ return capitalize(name); }
query_invis(){ return player->query_invis(); }
query_level(){ return player->query_level(); }

teleport(){
   write("You are moving around.\n");
   say(cap_name+" moves around.\n");
   return 1;
}

attacked_by(ob){
    return player->attacked_by(ob);
}

attack_object(ob){
    return player->attack_object(ob);
}
move_player(dir_dest)
{
  string dir, dest;
  object ob;
  int is_light;

  if(!dir_dest)
	return 0;

  if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
    tell_object(player, "Move to bad dir/dest\n");
	return;
  }
  current_room = dest;
  hunting_time -= 1;
  if (hunting_time == 0) {
	if (hunter)
      call_other(hunter, "stop_hunter");
	hunter = 0;
	hunted = 0;
  }
  if (attacker_ob && present(attacker_ob)) {
	hunting_time = 10;
    tell_object(player, "You are now hunted by " +
        call_other(attacker_ob, "query_name", 0) + ".\n");
	hunter = attacker_ob;
  }
  if (!msgout)
    msgout = "leaves";
  if (ghost)
	tell_room(environment(player),
        NAME_OF_GHOST + " " + msgout + " " + dir + ".\n");
  else if (dir == "X" && query_invis() < INVIS_TELEPORT)
	tell_room(environment(player),
        query_cap_name()+ " " + mmsgout + ".\n");
  else
	tell_room(environment(player),
        query_cap_name()+ " " + msgout + " " + dir + ".\n");
  move_object(player, dest);
  is_light = set_light(0);
  if (is_light < 0)
	is_light = 0;
  if (level >= 20)
    tell_object(player, dest + "\n");
  if (!msgin)
    msgin = "arrives";
  if (ghost && is_light)
	tell_room(environment(player),
        NAME_OF_GHOST + " " + msgin + ".\n");
  else if (query_invis() < INVIS_TELEPORT && dir == "X")
	tell_room(environment(player),
        cap_name + " " + mmsgin + ".\n");
  else
	tell_room(environment(player),
        cap_name + " " + msgin + ".\n");
  if (hunted && present(hunted))
	player->attack_object(hunted);
  if (hunter && present(hunter))
    call_other(hunter, "attack_object", this_object());
  if (is_npc)
	return;
  ob = environment(player);
  if (brief) {
    write(call_other(ob, "short", 0));
    write(".\n"); /* killed '+' --Wulkwa */
  } else
    call_other(ob, "long", 0);
  ob = first_inventory(ob);
  while(ob) {
        if(ob != player){
	  string short_str;
      short_str = call_other(ob, "short");
	  if (short_str)
    write(short_str + ".\n");
	}
	ob = next_inventory(ob);
  }
}

long() {
	int hp, mhp;
	hp = player->query_hp();
	mhp = player->query_max_hp();
    write(short()+".\n");
	if (hp < mhp/10) {
    write(cap_name + " is in very bad shape.\n");
	return;
	}
	if (hp < mhp/5) {
    write(cap_name + " is in bad shape.\n");
	return;
	}
	if (hp < mhp/2) {
    write(cap_name + " is somewhat hurt.\n");
	return;
	}
	if (hp < mhp - 20) {
    write(cap_name + " is slightly hurt.\n");
	return;
	}
    write(cap_name + " is in good shape.\n");
}

attack()
{
  int tmp;
  string mfight,thingone,thingtwo;
  int whit,weap_tmp;
  int intox_no;
  string name_of_attacker;
  if (!is_npc)
   intox_no = call_other(this_object(), "query_intoxination", 0)/5;
 else
   intox_no = 0;

	if(alt_attacker_ob) {
	if(alt_attacker_ob->query_ghost())
	 alt_attacker_ob = attacker_ob;
   }
	if (already_fight)
{
	   return 0;
 }
  if (!attacker_ob) {
	spell_cost = 0;
	return 0;
  }
 /* Stop fighting if one party is disconnected */
  /* Stop player disconnected player from fighting */
 if (!is_npc && !call_other(this_object(), "query_interactive",0))
{
	alt_attacker_ob=0;
	attacker_ob =0;
  return 0;
}
  /* stop monster from fighting disconnected player */
 if (is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
   stop_fight();
  /* stop player from fighting disconnected player */
if(!is_npc && !call_other(attacker_ob, "query_interactive",0) && !call_other(attacker_ob, "query_npc", 0))
  stop_fight();
  name_of_attacker = call_other(attacker_ob, "query_name", 0);
  if ((!name_of_attacker) ||
	  (name_of_attacker == NAME_OF_GHOST) ||
	  (environment(attacker_ob) != environment(this_object()))) {
	if (!hunter && name_of_attacker &&
    !call_other(attacker_ob, "query_ghost", 0)) {
      tell_object(this_object(), "You are now hunting " +
              call_other(attacker_ob, "query_name", 0) + ".\n");
	  hunted = attacker_ob;
	  hunting_time = 10;
	}
	attacker_ob = 0;
	if (!alt_attacker_ob)
	  return 0;
	attacker_ob = alt_attacker_ob;
	alt_attacker_ob = 0;
	if (attack()) {
      tell_object(this_object(), "You turn to attack " +
          call_other(attacker_ob, "query_name", 0) + ".\n");
	already_fight=1;
	  return 1;
	}
	return 0;
  }
  call_other(attacker_ob, "attacked_by", this_object());
  if (spell_cost) {
	if (level < 20) spell_points -= spell_cost;
    tell_object(attacker_ob, "You are hit by a " + spell_name + ".\n");
    write("You cast a " + spell_name + ".\n");
  }
  if(name_of_weapon)
    whit = call_other(name_of_weapon,"hit",attacker_ob);
/* use weap_tmp as a weapon class limit as wizards dont listen.*/
	weap_tmp = weapon_class;
	if (!is_npc && this_object()->query_level() < 20 && weapon_class > 18) {
	  weap_tmp = 18;
	 }
   if(whit) {
	weap_tmp = weap_tmp + whit;
  if(!is_npc && this_object()->query_level()<20 && 1*weap_tmp > 30)
   weap_tmp = 10 + random(12);
   if(!is_npc && this_object()->query_level() <20 && weap_tmp > 22){
	weap_tmp = 22;
	 }
   }
  if(whit != "miss")
    tmp = call_other(attacker_ob, "hit_player",
			 random(weap_tmp - intox_no) + spell_dam);
  else
	tmp = 0;
  if (tmp == 0) {
    tell_object(this_object(), "You missed.\n");
    checked_say(query_cap_name()+" missed "+name_of_attacker+".\n");
	spell_cost = 0;
	spell_dam = 0;
	already_fight = 1;
   if(!is_npc && name_of_weapon) {
	name_of_weapon->count_misses();
   if(name_of_weapon->query_wear() > 40)
  {
	 if(!is_npc && random(3500000/name_of_weapon->query_wear()) < 10)
	name_of_weapon->weapon_breaks();
	 }
	}
	return 1;
  }
  experience += tmp;
  tmp -= spell_dam;
  spell_cost = 0;
  spell_dam = 0;
  /* Does the enemy still live ? */
  if (attacker_ob &&
      call_other(attacker_ob, "query_name", 0) != NAME_OF_GHOST) {
	string how, what;
    how = " to small fragments";
    what = "massacre";
	if (tmp < 30) {
      how = " with a bone crushing sound";
      what = "smashed";
	}
	if (tmp < 20) {
      how = " very hard";
      what = "hit";
	}
	if (tmp < 10) {
      how = " hard";
      what = "hit";
	}
	if (tmp < 5) {
      how = "";
      what = "hit";
	}
	if (tmp < 3) {
      how = "";
      what = "grazed";
	}
	if (tmp == 1) {
      how = " slightly";
      what = "scratched";
	}
    tell_object(this_object(), "You " + what + " " + name_of_attacker +
        how + ".\n");
	if (query_invis() >= INVIS_ACTION)
      tell_object(attacker_ob, query_cap_name() + " " + what + " you" + how +
          ".\n");
    checked_say(query_cap_name() + " " + what + " " + name_of_attacker + how +
        ".\n");
   already_fight = 1;
   if(name_of_weapon && !is_npc) {
   name_of_weapon->count_hit_made();
   if(!is_npc && name_of_weapon->query_wear() > 1)
   {
  if(!is_npc && random(4500000/name_of_weapon->query_wear()) < 10)
  name_of_weapon->weapon_breaks();
   }
   }
	return 1;
  }
  tell_object(this_object(), "You killed " + name_of_attacker + ".\n");
  attacker_ob = alt_attacker_ob;
  alt_attacker_ob = 0;
   already_fight = 1;
  if (attacker_ob)
	return 1;
}


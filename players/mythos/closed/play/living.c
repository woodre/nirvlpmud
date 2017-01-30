#include "/players/mythos/closed/ansi.h"

static int already_fight;
static int dam;
static object zap,h_check;
int money;
int is_npc;
int level;
int armor_class;
int hit_point;
int spell_dam;
int max_hp;
int spell_points;
int max_spell;
int experience;
int weapon_class;
int local_weight;
int hunting_time;
int age;
int sd_mode;
int is_invis;
int view;
int alignment;
string name;
string gender;
string msgin,msgout;
string mmsgout,mmsgin;
string cap_name;
string auto_load;
string current_room;
object attacker_ob;
object alt_attacker_ob;
object hunted,hunter;

move_player(dir_dest) {
  string dir, dest;
  object ob;
  int is_light;
  if(!dir_dest) return 0;
  if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
    tell_object(this_object(), "Move to bad dir/dest\n"); return;
  }
  current_room = dest;
  hunting_time -= 1;
  if (hunting_time == 0) {
    if (hunter) hunter->stop_hunter();
    hunter = 0;
    hunted = 0;
  }
  if (attacker_ob && present(attacker_ob)) {
    hunting_time = 10;
    tell_object(this_object(),"You are now hunted by "+attacker_ob->query_name() + ".\n");
    hunter = attacker_ob;
  }
  if (!msgout) msgout = "leaves";
  is_light = set_light(0);
  if (is_light < 0) is_light = 0;
  else if (dir == "X" && query_invis() < 40)
    say(cap_name + " " + mmsgout + ".\n");
  else if (query_invis() < 60 && is_light)
    say(cap_name + " " + msgout + " " + dir + ".\n");
  move_object(this_object(), dest);
  is_light = set_light(0);
  if (is_light < 0) is_light = 0;
  if (!msgin) msgin = "arrives";
  else if (query_invis() < 40 && dir == "X")
    say(cap_name + " " + mmsgin + ".\n");
  else if (query_invis() < 60 && is_light)
    say(cap_name + " " + msgin + ".\n");
  if (hunted && present(hunted))
    attack_object(hunted);
  if (hunter && present(hunter)) hunter->attack_object(this_object());
  is_light = set_light(0);
  write(BOLD+"Light:"+RED+" "+is_light+NORM+"\n");
  if(view) {
    write(dest+"\n");
    if(view == 1) {
    call_other(ob, "long", 0);
  ob = first_inventory(ob);
  while(ob) {
    if (ob != this_object()) {
      string short_str;
      short_str = call_other(ob, "short");
      if (short_str)
	write(short_str + ".\n");
    }
    ob = next_inventory(ob);
  } 
  if(view == 2) {
    ob = first_inventory(ob);
  while(ob) {
    write(ob);
    write("\n");
    }
    ob = next_inventory(ob);
  } 
 } }
}

hit_player(dam,zap) {
    int i,dam2;
    object pro_object;   /* paladin weapon pro & combat method object */

  if (this_player() && this_player() != this_object() && 
       this_player()->query_level() < 21) {
    /* -= Protection =- */  
    if ( this_player()->is_player() &&
         this_player()->query_attack() != this_object() &&
         !this_player()->valid_attack( this_object()))
    { /* bad attack, could be logged */
      write( "Your attack fails.\n");
      return 0;
    }
    if (attacker_ob == alt_attacker_ob || !alt_attacker_ob) 
      attacked_by( this_player());
  dam2 = dam;
  dam -= random(armor_class + 1);
  if (random(10) == 0) {
    tell_object(this_object(), "Your luck comes through for you.\n");
       dam = dam/10;
  }
  if (dam <= 0) return 0;
/* PUT a cap on damage a player can do in one hit. */
    if(!zap) zap = attacker_ob;
   if(attacker_ob && zap && zap->query_level() < 21)
   {
   if (is_npc && dam > 40 && attacker_ob->query_level() < 21) dam = 40;
    }
/* penalize multiple calls to hit_player() by the same player in one hb */
  if(this_player() && is_npc) { 
        if(this_player()->query_level() > 99) write("DAMAGE = "+dam+" \n");
     if(h_check==this_player()) { dam = dam/10;
        if(this_player()->query_level() > 99) write("DAMAGE REDUCED to "+dam+"\n");
     }}
  if (dam > hit_point+1) dam = hit_point+1;
  hit_point = hit_point - dam;
  if (hit_point<0) {
    tell_room(environment(this_object()),
       cap_name+" grins and suddenly is fully healed!\n");
    hit_point = max_hp;
  return 0;} }
  return dam;
}

transfer_all_to(string dest)
{
  object ob;
  object next_ob;

  if(!dest) return 0;
  ob = first_inventory(this_object());
  while(ob) {
    next_ob = next_inventory(ob);
    if (!call_other(ob, "drop", 1))
     if(ob)
      move_object(ob, dest);
    ob = next_ob;
  }
  local_weight = 0;
  if (money == 0)
    return;
  ob = clone_object("obj/money");
  call_other(ob, "set_money", money);
  move_object(ob, dest);
  money = 0;
}

query_name() {
  return cap_name;
}

query_real_name() {
  return name;
}

query_alignment() {
  return alignment;
}

query_npc() {
  return is_npc;
}

attacked_by(ob) {
  if (!attacker_ob) {
    attacker_ob = ob;
    set_heart_beat(1);
    return;
  }
  if (!alt_attacker_ob || alt_attacker_ob == attacker_ob) {
    alt_attacker_ob = ob;
    return;
  }
}

query_level() {
  return level;
}

query_value() { return 0; }

get() { return 0; }

attack()
{
  int tmp;
  string mfight,thingone,thingtwo;
  int tmpk,pal_tmp,whit,weap_tmp;
  int intox_no;
  string name_alt_at;
  string name_of_attacker;
  object pro_object;     /* paladin object */
  pal_tmp = 0;
  if(is_npc) h_check = 0;
   intox_no = 0;
    if(alt_attacker_ob) {
    if(alt_attacker_ob->query_ghost())
     alt_attacker_ob = attacker_ob;
   }
    if (already_fight) 
{
       return 0;
 }
 if (is_npc && !call_other(attacker_ob, "query_interactive",0) && 
    !call_other(attacker_ob, "query_npc", 0) && !sd_mode) stop_fight();
  name_of_attacker = call_other(attacker_ob, "query_name", 0);
  if ((!name_of_attacker) ||
      (environment(attacker_ob) != environment(this_object()))) {
    if (!hunter && name_of_attacker) {
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
    weap_tmp = weapon_class;
   if(alt_attacker_ob)
  if(!alt_attacker_ob->query_name()) alt_attacker_ob = attacker_ob;
  if(alt_attacker_ob && alt_attacker_ob != attacker_ob){
     if(present(alt_attacker_ob))
   hit_pet(weap_tmp,spell_dam);
   }
    tmp = call_other(attacker_ob, "hit_player", 
		     random(weap_tmp - intox_no) + weap_tmp/2);
  if (tmp == 0) {
    tell_object(this_object(), "You missed.\n");
    checked_say(cap_name + " missed " + name_of_attacker + ".\n");
    already_fight = 1;
  experience += tmp;
  /* Does the enemy still live ? */
  if (attacker_ob && !attacker_ob->query_ghost()) {
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
      how = " in the stomach";
      what = "tickled";
    }
    tell_object(this_object(), "You " + what + " " + name_of_attacker +
		how + ".\n");
    if (query_invis() >= 60)
      tell_object(attacker_ob, cap_name + " " + what + " you" + how +
		  ".\n");
    checked_say(cap_name + " " + what + " " + name_of_attacker + how +
		".\n");
   already_fight = 1;
    return 1;
  }
  tell_object(this_object(), "You killed " + name_of_attacker + ".\n");
  attacker_ob = alt_attacker_ob;
  alt_attacker_ob = 0;
   already_fight = 1;
  if (attacker_ob) return 1;
} }

query_attack() {
  return attacker_ob;
}

drop_all_money(verbose) {
  object mon;
  int tmp;
  if (money == 0)
    return;
  mon = clone_object("obj/money");
  call_other(mon, "set_money", money);
   tmp = money;
  move_object(mon, environment());
  money = 0;
}

add_weight(w) {
  local_weight += w;
  return 1;
}

heal_self(h) {
  if (!h) return;
  if(h < -20) { h = -20; }
  hit_point += h;
  spell_points += h;
  if (hit_point > max_hp) hit_point = max_hp;
  if (spell_points > max_spell) spell_points = max_spell;
  if(hit_point == 0) hit_player(1);
}

can_put_and_get(str)
{
  return str != 0;
}

attack_object(ob)
{
  if(!ob) {
    stop_hunter();
    return 0;
  }
  if (call_other(ob, "query_ghost", 0) && !sd_mode) return;
  set_heart_beat(1);    /* For monsters, start the heart beat */
  if (attacker_ob == ob) {
    attack();
    return 1;
  }
  if (alt_attacker_ob == ob) {
    alt_attacker_ob = attacker_ob;
    attacker_ob = ob;
    attack();
    return 1;
  }
  if (!alt_attacker_ob)
    alt_attacker_ob = attacker_ob;
  attacker_ob = ob;
  attack();
  return 1;
}

query_ghost() { return 0; }

test_if_any_here()
{
  return 1;
}

show_age() {
  int i;
  
  write("age:\t");
  i = age;
  if (i/43200) {
    write(i/43200 + " days ");
    i = i - (i/43200)*43200;
  }
  if (i/1800) {
    write(i/1800 + " hours ");
    i = i  - (i/1800)*1800;
  }
  if (i/30) {
    write(i/30 + " minutes ");
    i = i - (i/30)*30;
  }
  write(i*2 + " seconds.\n");
}

stop_hunter()
{
  hunter = 0;
  tell_object(this_object(), "You are no longer hunted.\n");
}

add_money(m) {
  money = money + m;
}

query_money() {
  return money;
}

query_exp() {
  return experience;
}

run_away() { return 1; }

query_hp() {
  return hit_point;
}

query_current_room() {
  return current_room;
}

checked_say(str) {
  if (query_invis() >= 60) return;
  say(str);
}

query_invis(num) {
  if (!num) {
    return is_invis;
  } else {
    if (level <= num || num >= 100) {
      return -is_invis;
    } else { return is_invis;}
  }
}

stop_fight() {
  attacker_ob = alt_attacker_ob;
  alt_attacker_ob = 0;
}
query_gender_string() {
 return gender;
}

query_pronoun() {
    if (gender == "creature")
	return "it";
    else if (gender == "male")
	return "he";
    else
	return "she";
}

query_possessive() {
    if (gender == "creature")
	return "its";
    else if (gender == "male")
	return "his";
    else
	return "her";
}

query_objective() {
    if (gender == "creature")
	return "it";
    else if (gender == "male")
	return "him";
    else
	return "her";
}

query_age() {
      return age;
}
query_wc() {return weapon_class;}
query_ac() {return armor_class;}
query_sp() {return spell_points;}
query_msp() {return max_spell;}
query_mhp() {return max_hp;}

query_hunted() {return hunted;}
hit_pet(k1,k2){
int tmpk;
string name_alt_at;
      if(is_npc && alt_attacker_ob->is_pet() && random(100) < 37) {
           already_fight=0;
           if(!k2 || k2 < 1) k2 = k1;
           name_alt_at=alt_attacker_ob->query_name();
           tmpk = alt_attacker_ob->hit_player(random(k1)+k2);
           if(tmpk == 0) say(cap_name +" missed "+name_alt_at+".\n");
           if(tmpk < 10) say(cap_name +" hits "+name_alt_at+" with a side attack.\n");
           if(tmpk > 10) say(cap_name +" hits "+name_alt_at+" hard with a side attack.\n");
           }
return 1;
}

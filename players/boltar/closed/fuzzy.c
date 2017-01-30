#include "living.h"
#include "clean.c"
#include "chat_include.c"
#include "catch_talk_include.c"

/*
 * The heart beat is always started in living.h when we are attacked.
 */

string kdes,short_desc, long_desc, alias, alt_name, race, info;
string title;
int nameflag,move_at_reset, aggressive, can_kill;
int intoxicated;
object kill_ob;
object desc_ob;
object follow;

object chat_head;
int heal_start;
int heal_rate;
int heal_intv;
int chat_chance;
int chat_nr;
int kidage;

object a_chat_head;
int a_chat_chance;
int a_chat_nr;

object head;
object talk_ob;
string talk_func;
string talk_match;
string talk_type;
string the_text;
int have_text;


object dead_ob;
object init_ob;

int random_pick;

int spell_chance, spell_dam;
string spell_mess1, spell_mess2;
object me;

set_desc_ob(ob) { desc_ob = ob; }

valid_attack(ob)
{
    /* Don't attack other monsters unless specifically allowed to. */
    return (!call_other(ob, "query_npc", 0) || can_kill);
}

reset(arg)
{
    if (arg) {
	if (move_at_reset)
	    random_move();
	return;
    }
    is_npc = 1;
    /* Only let this monster kill other monsters if specifically allowed. */
    can_kill = 0;
    enable_commands();
    me = this_object();
    set_name("fuzzy");
    set_hp(10000);
    set_ac(50);
    set_wc(25);
    move_object(clone_object("obj/kid_soul"), this_object());
    set_level(100);
    set_chat_chance(10);
    load_chat("Fuzzy barks loudly.\n");
    load_chat("Fuzzy smiles.\n");
    load_chat("Fuzzy wags her tail.\n");
    load_chat("Fuzzy sniffs around.\n");
    
    short_desc="Fuzzy, Boltar's dog";
    long_desc="A 25lb dog, colored varried from black to white through\nbrowns much like a husky is colored in greys.\nShe has short powerful legs, with paws like a sled dog.\n She stands firm with her tail curled over her back.\n";
    set_gender("female");
}

random_move()
{
    int n;
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

short() {
    return short_desc;
}

/*
long() {
    if (desc_ob) {
        call_other(desc_ob,"monster_long",0);
	return;
    }
    write (long_desc);
}
*/

long() {
    if (desc_ob) {
        call_other(desc_ob,"monster_long",0);
	return;
    }
if (gender)
    write(short() + " ("+gender+")\n");
     write(long_desc+"\n");
    if(hit_point < max_hp/10) {
      write(cap_name+" is in very bad shape.\n");
      return;
    }
    if(hit_point < max_hp/5) {
      write(cap_name+" is in bad shape.\n");
      return;
    }
    if(hit_point < max_hp/2) {
      write(cap_name+" is somewhat hurt.\n");
      return;
    }
    if(hit_point < max_hp - 20) {
      write(cap_name+" is slightly hurt.\n");
      return;
    }
    write(cap_name+" is in good shape.\n");
}
id(str) {
    if (desc_ob) return call_other(desc_ob,"monster_id",str);
    return str == alt_name || str == name || str == alias || str == race;
}

heart_beat()
{
    int c;

    age += 1;
    if (!heal_start)
    {
       call_out("autoheal", heal_intv);
        heal_start = 1;
     }
     
    already_fight = 0;
    /* If there is none here test_if_any_here will turn of heat_beat */
    if(!test_if_any_here()) {
	if(have_text && head) {
	    have_text = 0;
	    call_other(head, "test_match", the_text);
	} else {
	    set_heart_beat(0);
	    return;
	}
    }
    if (kill_ob && present(kill_ob, environment(this_object()))) {
	if (random(2) == 1)
	    return;		/* Delay attack some */
	attack_object(kill_ob);
	kill_ob = 0;
	return;
    }
    if (attacker_ob && present(attacker_ob, environment(this_object())) &&
      spell_chance > random(100)) {
	say(spell_mess1 + "\n", attacker_ob);
	tell_object(attacker_ob, spell_mess2 + "\n");
	call_other(attacker_ob, "hit_player", random(spell_dam));
    }
    attack();
    if (attacker_ob && whimpy && hit_point < max_hp/5)
	run_away();
    if(chat_nr > 0 || a_chat_nr > 0){
	c = random(100);
	if(attacker_ob && a_chat_nr > 0) {
	    if(c < a_chat_chance){
		c = random(a_chat_nr);
                a_chat(c);
	    }
	} else {
	    if(c < chat_chance && chat_nr > 0){
		c = random(chat_nr);
                chat(c);
	    }
	}
    }
    if(random_pick) {
	c = random(100);
	if(c < random_pick)
	    pick_any_obj();
    }
    if(have_text && talk_done) {
	have_text = 0;
        test_match(the_text);
    }
}

can_put_and_get(str)
{
    if (!str)
	return 0;
    return 1;
}

int busy_catch_tell;

catch_tell(str) {
    string who;

    if (busy_catch_tell)    /* Should not happen, but does! */
	return;
    busy_catch_tell = 1;
    if(talk_done) {
	if(have_text) {
	    who = the_text;
	    the_text = str;
	    have_text = 1;
            test_match(the_text);
	} else {
	    the_text = str;
	    have_text = 1;
	}
    }
    busy_catch_tell = 0;
}

/*
 * Call the following functions to setup the monster.
 * Call them in the order they appear.
 */

set_name(n) {
    n = lower_case(n);
    name = n;
    cap_name = capitalize(n);
   return 1;
}

set_level(l) {
    level = l;
    if(!weapon_class)
      weapon_class = WEAPON_CLASS_OF_HANDS;
    if(!hit_point)
      hit_point = 50 + (level - 1) * 8;	/* Same as a player */
    if(!experience)
      experience = call_other("room/adv_guild", "query_cost", l-1);
   if(!heal_intv) {
      heal_intv = 35;
      heal_rate = 2;
    }
  set_max_hp();
}

/* Optional */
set_alias(a) { alias = a; }
/* Optional */
set_race(r) { race = r; }
/* optional */
set_hp(hp) {
   hit_point = hp;
   set_max_hp();
   if(hit_point > max_hp) hit_point = max_hp;
  }
set_max_hp(){
    max_hp=10000;
   }
set_ep(ep) { experience = ep; }
set_al(al) {
    /* Limit alignment to keep wizards from making their monsters worth
       much too much */
    if (al > 1000)
	al = 1000;
    if (al < -1000)
	al = -1000;
    alignment = al;
}
/* optional */
set_short(sh) { 
  short_desc = sh;
  if(!long_desc)
    long_desc = short_desc + "\n";
}
/* optional */
set_long(lo) { long_desc = lo; }
/* optional */
set_wc(wc) { weapon_class = wc; }
/* optional */
set_ac(ac) { armor_class = ac; }
/* optional */
set_move_at_reset() { move_at_reset = 1; }
/* optional
 * 0: Peaceful.
 * 1: Attack on sight.
 */
set_aggressive(a) {
    aggressive = a;
}
/* optional
 * 0: Can't attack other monsters.
 * 1: Can attack other monsters.
 */
set_can_kill(a) {
    can_kill = a;
}
/*
 * Now some functions for setting up spells !
 */
/*
 * The percent chance of casting a spell.
 */
set_chance(c) {
    spell_chance = c;
}
/* Message to the victim. */
set_spell_mess1(m) {
    spell_mess1 = m;
}
set_spell_mess2(m) {
    spell_mess2 = m;
}
set_spell_dam(d) {
    spell_dam = d;
}

/* Set the frog curse. */
set_frog() {
    frog = 1;
}

/* Set the whimpy mode */
set_whimpy() {
    whimpy = 1;
}

/*
 * Force the monster to do a command. The force_us() function isn't
 * always good, because it checks the level of the caller, and this function
 * can be called by a room.
 */
init_command(cmd) {
    command(cmd);
}

/* Load chat */

set_chat_chance(c) {
    chat_chance = c;
}




/* Load attack chat */

set_a_chat_chance(c) {
    a_chat_chance = c;
}


/* Catch the talk */

set_dead_ob(ob)
{
    dead_ob = ob;
}

second_life()
{
    /* We have died remove chat and catch_talk */
    if(head)
	call_other(head,"collaps");
    if(chat_head)
	call_other(chat_head,"collaps");
    if(a_chat_head)
	call_other(a_chat_head,"collaps");
    if(dead_ob)
	call_other(dead_ob,"monster_died",this_object());
}

set_random_pick(r)
{
    random_pick = r;
}

pick_any_obj() {
    object ob;
    int weight;

    ob = first_inventory(environment(this_object()));
    while(ob) {
	if (call_other(ob, "get", 0) && call_other(ob, "short")) {
	    weight = call_other(ob, "query_weight", 0);
	    if (!add_weight(weight)) {
		say(cap_name + " tries to take " + call_other(ob, "short", 0) +
		    " but fails.\n");
		return;
	    }
	    move_object(ob, this_object());
	    say(cap_name + " takes " + call_other(ob, "short", 0) + ".\n");
	    if (call_other(ob, "weapon_class", 0))
		call_other(ob, "wield", call_other(ob,"query_name"));
	    else if (call_other(ob, "armor_class", 0))
		call_other(ob, "wear", call_other(ob,"query_name"));
	    return;
	}
	ob = next_inventory(ob);
    }
}

dumpa(str)
{
    string foo;
    if (sscanf(str, "players/%s", foo)) return 0;
    if(!str)
	str = "MONSTER_DUMP";
    save_object(str);
}

set_init_ob(ob)
{
    init_ob = ob;
}


init() {
  int ste,atc;
       add_action("khp","khp");
       add_action("command_me", "com");

    if(this_player() == me)
	return;
    if(dead_ob)
	if(call_other(dead_ob,"monster_init",this_object()))
	    return;
    if (attacker_ob) {
	set_heart_beat(1); /* Turn on heart beat */
    }
    if(this_player() && !call_other(this_player(),"query_npc")) {
	set_heart_beat(1);
    }
}

set_info(str) { info = str; }
query_info() {return info; }
autoheal_monster() {
     if (hit_point < max_hp) {
        hit_point += heal_rate+random(intoxicated);
     }
        if (hit_point > max_hp)
               hit_point = max_hp;
      if (hit_point < max_hp)
   call_out("autoheal_monster", heal_intv);
  }
set_heal(hr, hi){
    heal_rate = hr;
     heal_intv = hi;
    }
set_alt_name(n) { alt_name = n; }
set_gender(str) { gender = str;}
get() {
    return "You pick up "+cap_name+"\n";
   }
query_gender() { return gender;}
command_me(str){
string st1,mand,arg,cmd_ob_file,st2,me,cmd;
    if (sscanf(str, "%s %s", me, cmd) != 2)
         return 0;
   if(me != name) return 0;
    if(this_player()->query_real_name() != "boltar") {
      write("The fuzz dog ingores you.\n");
      return 1;
      }
   if(cmd == "follow") set_follow();
   if(cmd == "stop") clear_follow();
    if(sscanf(cmd, "%s %s", st1,st2) == 2 && st1 == "say") {
    talk(st2);
   return 1;
  }
    if(sscanf(cmd, "%s %s", st1, st2) == 2 && st1 =="kill") {
       kill(st2);
       return 1;
     }
    if(sscanf(cmd, "%s %s", st1, st2) == 2 && st1 =="emote") {
       say(cap_name+ " "+st2+"\n");
       return 1;
     }
    if(sscanf(cmd, "%s %s",st1,st2)==2 && st1 =="drop") {
       drop_thing(st2);
        return 1;
      }
    if(sscanf(cmd, "%s %s",st1,st2)==2 && st1 =="get") {
       get_thing(st2);
        return 1;
      }
    if(sscanf(cmd, "%s %s",st1,st2)==2 && st1 =="take") {
       get_thing(st2);
        return 1;
   }
/*
if(sscanf(cmd, "%s %s",mand, arg)!=2)
  mand=cmd;
cmd_ob_file="/bin/_"+mand;
if(file_size(cmd_ob_file + ".c") > 0 )
*/
/*
     return call_other(cmd_ob_file, "cmd_"+mand, arg);
  call_other(present("soul"),"cmd_hook",cmd);
*/
  if(!command(cmd))
   command("atm "+cmd);
   write("The fuzz dog does as you command.\n");
   return 1;
  }
kill(str) {
    object ob;
    if (ghost)
	return 0;
    if (!str) {
        write("Kill what?\n");
	return 1;
    }
    ob = present(lower_case(str), environment(this_player()));
    if (!ob) {
	write("No " + str + " here !\n");
	return 1;
    }
    if (!living(ob)) {
	write(str + " is not a living thing !\n");
	checked_say(cap_name + " tries foolishly to attack " + str + ".\n");
	return 1;
    }
    if (ob == this_object()) {
	write("What? Attack yourself?\n");
	return 1;
    }
    if (attacker_ob == ob) {
	write("Yes, yes.\n");
	return 1;
    }
 if (call_other(ob, "is_player"))
 {
    write("Cannot attack players.\n");
   return 1;
   }
    if (!attack_object(ob))
	write("You can't attack " + call_other(ob, "query_name") + "!\n");
    return 1;
}

set_follow() {
   follow = this_player();
   write(cap_name + " is now following you.\n");
   call_out("do_follow", 4);
   return 1;
   }
clear_follow() {
   follow = 0;
   remove_call_out("do_follow");
  write(cap_name + " no longer follows you.\n");
   return 1;
  }
do_follow() {
    if(environment(this_object()) != environment(follow)) {
     say(cap_name + " leaves following " + "boltar" +"\n");
    move_object(this_object(), environment(follow));
    say(cap_name + " arrives following " + "boltar"+"\n");
     }
    call_out("do_follow", 4);
   }
khp(str) {
  if(str != name) return 0;
  if (this_player()->query_real_name() != "boltar") return 0;
  write(cap_name + " has "+ hit_point + " of " + max_hp +" hit points\n");
   write("Level "+level+" with "+experience+" Experience points.\n");
  return 1;
  }
drop_thing(obj) {
  object thing;
    thing = present(obj,this_object());
   if(!thing) {
   write(cap_name+" tells you I have no "+obj+".\n");
    return 1;
   }
    thing->drop(obj);
    move_object(thing, environment(this_object()));
    local_weight -= thing->query_weight();
  say(cap_name +" drops "+thing->short()+"\n");
   return 1;
  }
add_exp(arg) {experience += arg; 
          return 1;}
talk(str){
    say(cap_name+" says: "+str+"\n");
    return 1;
   }
get_thing(obj) {
  object thing;
    if(environment(this_object())->is_player())
      {
          write("The fuzz dog cannot take items from your inventory.\n");
          return 1;
       }
    thing = present(obj, environment(this_object()));
   if(!thing) {
   write(cap_name+" tells you there is no "+obj+".\n");
    return 1;
   }
            if(!add_weight(thing->query_weight())) {
		say(cap_name + " tries to take " + call_other(thing, "short", 0) +
		    " but fails.\n");
		return 1;
	    }
    move_object(thing, this_object());
  say(cap_name +" takes "+thing->short()+"\n");
   return 1;
  }
crime_to_attack() { return 1; }
autoheal() {
    if (hit_point < max_hp) {
	hit_point += intoxicated ? 3 : 1; 
	if (hit_point > max_hp)
	    hit_point = max_hp;
    }
    if (intoxicated) {
           intoxicated -=1;
	}
   call_out("autoheal", heal_intv);
}
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
    if (intoxicated > level + 3 && strength > 0) {
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

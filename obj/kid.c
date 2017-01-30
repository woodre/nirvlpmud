/*
 * A general purpose monster. Clone this object,
 * and call local functions to configure it.
 */
#include "living.h"
#include "/obj/lib/living/settings.h"
#include <security.h>
#include "clean.c"
#include "chat_include.c"
#include "prego.c"

/*
 * The heart beat is always started in living.h when we are attacked.
 */

#undef INFUSE_LIMIT
#define INFUSE_LIMIT 9*level/2 /* Limit on infusion of hit+spell points */
int infuse;
string kdes,parent,short_desc, long_desc, alias, alt_name, race, info;
string nparents;
string parenttwo,title;
int nameflag,move_at_reset, aggressive, can_kill;
int npu;
int intoxicated;
object kill_ob;
object desc_ob;
object follow;
int stuffed;            /* How many ticks to stay stuffed */
int soaked;             /* How many ticks to stay soaked */

object chat_head;
object daycare; /* what is our daycare of orgin */
int dc_num;
int heal_start;
int heal_rate;
int heal_intv;
int chat_chance;
/* LD no like
int chat_nr;
*/
int kidage;

object a_chat_head;
int a_chat_chance;
/* LD no like -Bp
int a_chat_nr;
*/

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

/* LD no like -Bp
int spell_dam;
*/
int spell_chance;
string spell_mess1, spell_mess2;
object me;

set_desc_ob(ob) { desc_ob = ob; }

valid_attack(ob)
{
    /* Don't attack other monsters unless specifically allowed to. */
   if(ob)
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
    if (desc_ob) return call_other(desc_ob,"monster_short",0);
   if(title) return cap_name + " " + title;
   if(kidage < 16000)
    return short_desc;
    if(kidage < 32000)
    return "A small child named "+cap_name;
    if(kidage < 54000)
        return "A child named "+cap_name;
    if(kidage < 100000)
       return cap_name+" the young adventurer";
   if(gender == "male")
         return cap_name+" the son of "+capitalize(parent);
   return cap_name+" the daughter of "+capitalize(parent);
}

long() {
  int ptime;
    if (desc_ob) {
        call_other(desc_ob,"monster_long",0);
	return;
    }
if (gender)
    write(short() + " ("+gender+")\n");
   if(kdes)
     write(kdes+"\n");
  if(pregnancy) {
    ptime=kidage-pregnancy;
    if(ptime > 4000)
   write(cap_name+" looks");
       if(ptime > 4000 && ptime < 5001) write(" about 3 months pregnant.\n");
       if(ptime > 5000 && ptime < 7200) write(" about 4 months pregnant.\n");
        if(ptime > 7199 && ptime < 9000) write(" about 5 months pregnant.\n");
        if(ptime > 8999 && ptime < 10800) write(" about 6 months pregnant.\n");
        if(ptime > 10799 && ptime < 12700) write(" about 7 months pregnant.\n");
        if(ptime > 12699 && ptime < 14400) write(" about 8 months pregnant.\n");
        if(ptime > 14399 && ptime < 163000) write(" about 9 months pregnant.\n");
    }
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
    if(pregnancy) preg_ticker();
    if (!heal_start)
    {
       call_out("autoheal", heal_intv);
        heal_start = 1;
     }
     
    already_fight = 0;
      if (stuffed)
    stuffed--;
  if (soaked)
    soaked--;
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
	if(attacker_ob && a_chat_head) {
	    if(c < a_chat_chance){
		c = random(a_chat_nr);
                chat(c);
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
    if(have_text && head) {
	have_text = 0;
	call_other(head, "test_match", the_text);
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
    if(head) {
	if(have_text) {
	    who = the_text;
	    the_text = str;
	    have_text = 1;
	    call_other(head, "test_match", the_text);
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
  if(nameflag > 1) return 1;
   nameflag += 1;
    n = lower_case(n);
    name = n;
    set_living_name(n);
    cap_name = capitalize(n);
  if(name !="baby" && short_desc)
    short_desc = short_desc + " named "+cap_name;
    if(!short_desc)
      short_desc = cap_name;
    if(!long_desc)
      long_desc = "You see nothing special.\n";
/*    move_object(clone_object("obj/soul"), this_object()); */
/* why is this here?? */
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
  if (hp > 200) hp = 200;
   hit_point = hp;
   set_max_hp();
   if(hit_point > max_hp) hit_point = max_hp;
  }
set_max_hp(){
    max_hp= 24 + level*6 + kidage/2000;
     if(kidage > 54000) max_hp = 50 + level*8;
    if(max_hp > 200) max_hp = 200;
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

set_object(ob) { 
    talk_ob = ob; 
}

set_function(func) { 
    talk_func = func; 
}

set_type(type) { 
    talk_type = type; 
}

set_match(match) {
    object old;

    talk_match = match; 
    if(head)
	old = head;
    head = clone_object("obj/catch_talk");
    call_other(head, "set_object", talk_ob);
    call_other(head, "set_function", talk_func);
    call_other(head, "set_match", talk_match);
    call_other(head, "set_type", talk_type);
    if(old)
	call_other(head, "link", old);
}

remove_match(match) { 
    head = call_other(head,"remove_match",match);
}

set_dead_ob(ob)
{
    dead_ob = ob;
}

second_life()
{
int exptmp,cexp;
if(!level) return 0;
    /* We have died remove chat and catch_talk */
    if(head)
	call_other(head,"collaps");
    if(chat_head)
	call_other(chat_head,"collaps");
    if(a_chat_head)
	call_other(a_chat_head,"collaps");
    if(dead_ob)
	call_other(dead_ob,"monster_died",this_object());
  exptmp=experience - experience/4;
  experience=exptmp;
  cexp=call_other("room/adv_guild", "check_level", level);
    if(experience < cexp) 
    call_other("room/adv_guild", "correct_level", this_object());
  if(daycare)
  daycare->set_exp_death(dc_num,exptmp,level);
  daycare->save_dc();
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
      add_action("childname","childname");
      add_action("child_title", "kidtitle");
       add_action("kid_desc", "kdesc");
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
	if (aggressive == 1)
    {
     atc = random(50);
     ste = call_other(this_player(), "query_attrib", "ste");
     if (ste < atc)
	    kill_ob = this_player();
   }
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
   if(kidage > 54000) return 0;
    return "You pick up "+cap_name+"\n";
   }
is_kid() {return 1;}
is_pet() {return 1;}
query_gender() { return gender;}
set_kidage(n) {kidage = n;}
query_kidage() {return kidage;}
command_me(str){
string st1,mand,arg,cmd_ob_file,st2,me,cmd,otherpar,tmpz,st3,pt1,pt2;
    if (sscanf(str, "%s %s", me, cmd) != 2)
         return 0;
   if(me != name) return 0;
    if(this_player()->query_real_name() != parent && this_player()->query_real_name() != parenttwo) {
      write("The child ignores you.\n");
      return 1;
      }
    if(this_player()->query_ghost()) {
      write("The child cannot hear you when you are a ghost.\n");
      return 1;
     }

   if(cmd == "follow") { set_follow(); return 1; }
   if(cmd == "stop") { clear_follow(); return 1; }
   if(sscanf(cmd, "%s %s", st1,st2) == 2 && st1 == "sex") {
     if(kidage < 95000) {write("Too young for that.\n"); return 1;}
     st3 = st2;
     if(st2=="yes") st3 = current_room;
       if(sscanf(nparents,"%s"+st3,tmpz)==1 || 
          sscanf(nparents,st3+"%s",tmpz)==1) {
          write("No sex with parents!\n");
          return 1;
         }
       if(find_living(st3)->is_kid()){
         otherpar=find_living(st3)->query_nparents();
         sscanf(otherpar,"%s#%s",pt1,pt2);
         if(sscanf(nparents,"%s"+pt1,tmpz)==1 ||
            sscanf(nparents,pt1+"%s",tmpz)==1 ||
            sscanf(nparents,"%s"+pt2,tmpz)==1 ||        
            sscanf(nparents,pt2+"%s",tmpz)==1) {
            write("No sex with siblings!\n");
            return 1;
         }
       }
     have_sex(st2);
     return 1;
   }
    if(sscanf(cmd, "%s %s", st1,st2) == 2 && st1 == "say") {
    talk(st2);
   return 1;
  }
    if(sscanf(cmd, "%s %s", st1, st2) == 2 && st1 == "assist") {
     string nm;
      if(!find_player(st2)) return 0;
      if(!find_player(st2)->query_attack()) return 0;
      nm = (string)find_player(st2)->query_attack()->query_name();
    if(nm)  command_me(name+" kill "+nm);
     else write("You cannot use kid-assist against this monster.\n");
     return 1;
   }
    if(sscanf(cmd, "%s %s", st1, st2) == 2 && st1 =="kill") {
    object iii;
    iii=present(lower_case(st2),environment(this_object()));
    if(random(20) > level && this_player()->query_attrib("wil") < random(23)){
    if(iii)
    if(level < iii->query_level()) {
      clear_follow();
      say(name+" screams in fear.\n");
      run_away();
      return 1;
      }
    }
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
   if (cmd == "eat") { 
     if(!present("munchies")) {
       say(cap_name+ " says: I need some munchies.\n");
        return 1;
       }
     say(cap_name+ " opens a bag of munchies and eats them all.\n");
     hit_point +=  4 +random(10);
     if (hit_point > max_hp) hit_point = max_hp;
     destruct(present("munchies"));
     local_weight -= 1;
    return 1;
   }
/*
if(sscanf(cmd, "%s %s",mand, arg)!=2)
  mand=cmd;
cmd_ob_file="/bin/soul_"+mand;
if(file_size(cmd_ob_file + ".c") > 0 )
*/
/*
     return call_other(cmd_ob_file, "cmd_"+mand, arg);
  call_other(present("soul"),"cmd_hook",cmd);
*/
  if(!command(cmd))
   command("atm "+cmd);
   write("The child does as you command.\n");
   return 1;
  }
set_parent(str) { parent = str; }
query_parent(str) { return parent; }
set_parenttwo(str) { parenttwo = str; }
kill(str) {
    object ob;
    if (ghost)
	return 0;
    if (!str) {
        write("Kill what?\n");
	return 1;
    }
    ob = present(lower_case(str), environment(this_object()));
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

childname(str) {
 string hmm;
 string btt,ctt;
if(str == "boltar") { write("Illegal name.\n"); return 1;}
  if(!str) { write("What name would you like?\n"); return 1; }
 if(sscanf(str,"%s %s",btt,ctt)==2) {
   write("No spaces allowed in the name.\n");
   return 1;
 }
    if(name!="baby") return 0;
   str = lower_case(str);
     if(call_other("/obj/kidcheck", "check_name", str)) {
         write("That name is taken.\n");
         return 1;
     }
      hmm = call_other("players/boltar/sprooms/daycare.c", "check_names", str);
    if(!hmm)
      hmm = call_other("players/boltar/sprooms/daycare2.c", "check_names", str);
   if(!hmm)
      hmm = call_other("players/boltar/sprooms/daycare3.c", "check_names", str);
   if(!hmm)
      hmm = call_other("players/boltar/sprooms/daycare4.c", "check_names", str);
    if(!hmm)
      hmm = call_other("players/boltar/sprooms/daycare5.c", "check_names", str);
   if(hmm == str) {
    write("That name is already in use, please choose another.\n");
    return 1;
   }
  set_name(str);
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
   while(remove_call_out("do_follow") != -1);
  write(cap_name + " no longer follows you.\n");
   return 1;
  }
do_follow() {
    if(environment(this_object())->is_player()) {
      tell_object(environment(this_object()), cap_name+" wiggles free of your grasp.\n");
      command("drop "+name, environment(this_object()));
      while(remove_call_out("do_follow") != -1);
      call_out("do_follow", 4);
      return 1;
    }
    if(follow)
    if(follow->query_ghost()) {
             call_out("do_follow", 4);
      return 1;
     }
    if(follow && environment(follow)) {
    if(environment(this_object()) != environment(follow)) {
     say(cap_name + " leaves following " + parent +"\n");
    move_object(this_object(), environment(follow));
    say(cap_name + " arrives following " + parent+"\n");
     }
     }
    while(remove_call_out("do_follow") != -1);
    call_out("do_follow", 4);
   }
khp(str) {
  int pregzz;
  if(str != name) return 0;
  if (this_player()->query_real_name() != parent) return 0;
  write(cap_name + " has "+ hit_point + " of " + max_hp +" hit points\n");
   write("Level "+level+" with "+experience+" Experience points.\n");
   if(pregnancy) {
   pregzz = kidage-pregnancy;
   if(pregzz > 4000) {
     write("Pregnant: "+pregzz+"/16200\n");
/*
     write(pregnancy + " " + pregtoo+"\n");
     write(kidage + " " + age +"\n");
*/
    }
    }
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
child_title(str) {
   if(this_player()->query_real_name() != parent) return 0;
   title = str;
    write("title changed.\n");
    return 1;
   }
get_thing(obj) {
  object thing;
  string hh;
    if(environment(this_object())->is_player())
      {
          write("The child cannot take items from your inventory.\n");
          return 1;
       }
    thing = present(obj, environment(this_object()));
   if(!thing) {
   write(cap_name+" tells you there is no "+obj+".\n");
    return 1;
   }
  hh=thing->short();
      if(!thing->is_money())
      if(!add_weight(thing->query_weight()) || !thing->get()) {
		say(cap_name + " tries to take " + call_other(thing, "short", 0) +
		    " but fails.\n");
		return 1;
	    }
    move_object(thing, this_object());
  say(cap_name +" takes "+hh+"\n");
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
        if (intoxicated < 0) intoxicated = 0;
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

kid_desc(str) { 
    if(this_player()->query_real_name() != parent) {
      write("The child ingores you.\n");
      return 1;
      }
        kdes = str;
       return 1;
}
query_weight() {
    if(npu) { npu = 0; return 0; }
   if(kidage < 16000) return 2;
   if(kidage < 32000) return 4;
   return 6;
}
set_npu() {npu = 1;}
query_spell_point() {
  return 0;
 }
set_daycare(dc) { daycare = dc; }
set_dc_num(a) { dc_num = a; }
custom_clean() {
   if(parent)
   if(find_player(parent)) return 1;
   return 0;
}
query_nparents() {return nparents;}
set_nparents(arg) { nparents = arg;}
add_stuffed(i) {
  if(i < 0) {
    if (-i > stuffed / 10)
      i = -stuffed / 10;
  }
  stuffed += i;
  if (stuffed < 0)
    stuffed = 0;
}
 
add_soaked(i) {
  if(i < 0) {
    if (-i > soaked / 10)
      i = -soaked / 10;
  }
  soaked += i;
  if (soaked < 0)
    soaked = 0;
  if (soaked > level * 8) soaked = level * 8;
}
 
query_stuffed() {
  return stuffed;
}
query_soaked() {
  return soaked;
}
 
drink_soft(strength) {
  if (soaked + strength > level * 8) {
    write("You can't possibly drink that much right now!\n" + 
      "You feel crosslegged enough as it is.\n");
    return 0;
  }
  soaked += strength * 2;
  if (soaked < 0)
    soaked = 0;
  if (soaked == 0)
    write("You feel a bit dry in the mouth.\n");
  return 1;
}
 
eat_food(strength) {
int jun;
  if (stuffed + strength > level * 8) {
    write("This is much too rich for you right now! Perhaps something"+
      " lighter?\n");
    return 0;
  }
  stuffed += strength * 2;
  if(stuffed > level*8 && random(100) < 15) {
    write("You really shouldn't eat so much.\n");
    add_phys_at(3,random(1));
    return 1;
  }
  if (stuffed < 0)
    stuffed = 0;
  if (stuffed == 0)
    write("Your stomach makes a rumbling sound.\n");
  return 1;
}
add_hit_point(arg) {
  object thypl;
  int TGR; 
  int INF_MIN, INF_MAX, INF_ADD;
  int liv_infuse,LIV_INFUSE_LIMIT;
  thypl = this_player();
  if(thypl)
    if (level < EXPLORE && thypl->query_interactive() && thypl != this_object()){
        if(environment(thypl) != environment(this_object())) {
          arg = 0;
          /* tell_object(thypl,"Player to Player Hit Point transfers are not allowed.\n"); */
          tell_object(thypl,cap_name+" is not here.\n");
          tell_object(this_object(),"Attempted Hit Point transfer Aborted.\n");
        return 1; }
        if(thypl->query_guild_name() == "healer") { 
           TGR = thypl->query_guild_rank();   /* between 5 and 40 */ 
           INF_MIN = liv_infuse + (3 - TGR/10)*arg/2; 
           INF_MAX = LIV_INFUSE_LIMIT/2 + TGR; 
           /* INF_ADD = (3 - TGR/10)*arg/2; */
           /* changed by Verte and Maledicta per Boltar 4.23.01 */
           INF_ADD = ((6 - (TGR / 7)) * arg / 2);
           if(INF_MIN < 0) INF_MIN = 0; 
           if(INF_MAX < 0) INF_MAX = 0;
           if(INF_ADD < 0) INF_ADD = 0; 
        } else { INF_MIN = infuse+3*arg/2; INF_MAX = (INFUSE_LIMIT)/2; INF_ADD = 3*arg/2; }
        if((INFUSE_LIMIT) < INF_MIN || infuse > INF_MAX) {
          int blah;
          blah = 2*((INFUSE_LIMIT) - infuse)/3;
          tell_object(thypl,cap_name+" must wait before absorbing "+arg+" hit points.\n");
          if(infuse < INF_MAX && blah > 0 )
            tell_object(thypl,cap_name+" may absorb up to "+blah+" hit points.\n");
          tell_object(this_object(),"You must wait before absorbing more hit points.\n");
          arg = 0;
        return 1; }
        if(arg > 0) infuse += INF_ADD;
    }

    hit_point += arg;
    if (hit_point > max_hp) hit_point = max_hp;
    if (hit_point < 0) hit_point = 0;
}
preg_ticker() {
  kidage += 1;
  if (pregnancy) {
    int pregtmp;
    pregtmp = kidage - pregnancy;
    if(pregtmp < 3000 && pregtmp > 500) {
      if(random(4000) < 3) { 
        if(random(100) < 10) {
          say(cap_name+" doubles over and pukes.\n");
        }
      }
    }
    if(pregtmp > 1000 && pregtmp < 18000) {
      object bbb;
      if(random(8200) < 2) {
        say(cap_name+" wiggles uncomfortably as though her top is too tight.\n");
        bbb=present("boobs",this_object()); 
        if(bbb) {
          bbb->add_cup(1);
          bbb->add_bust(1);
        }
      }
    }

    if(pregtmp > 12000) {
      if(random(25000) < 40) {
         say(cap_name+" jumps up as though something startled her.\n");
      }
    }

    if(pregtmp > 16200+random(500)) 
      if(random(900000) < pregtmp) 
      child_birth();
  }
}

set_kidpreg(arg) {
   if(!arg) arg = kidage;
   pregnancy = arg;
/*
   call_out("preg_ticker",2);
*/
}
set_kidptoo(arg) {
   pregtoo=arg;
}
add_phys_at(arg,blah) {
   return 1;
}
query_total_level() { return level; }

query_save_flag() { return 1; }

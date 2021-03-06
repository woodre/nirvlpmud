#include "/obj/living.h"
#include "/obj/clean.c"
#include "/players/mythos/dmon/def.h"

string short_desc, long_desc, alias, alt_name, race, hbflag,info;
int aggressive, can_kill;
object kill_ob;
object desc_ob;

object chat_head;
int heal_start;
int heal_rate;
int heal_intv;
int chat_chance;
int chat_nr;

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
int intel, itl;

object dead_ob;
object init_ob;

int spell_chance, spell_dam, pet_command, wander;
string spell_mess1, spell_mess2, pet_cmd1, pet_cmd2;

object me;

int mult_at, mult_dam1, mult_chance, mult_dam2, mult_set;
int extra_dam;
int haunt_set;
int dischance;

int mass_dam, mass_chance;
string mass_spell, haunt, owner;

#include "/players/mythos/dmisc/power/ra_dam.h"
set_desc_ob(ob) { desc_ob = ob; }

valid_attack(ob)
{
    /* Don't attack other monsters unless specifically allowed to. */
    return (!call_other(ob, "query_npc", 0) || can_kill);
}

reset(arg)
{
    if (arg) return;
    is_npc = 1;
    /* Only let this monster kill other monsters if specifically allowed. */
    can_kill = 0;
    mult_set = 0;
    intel = 0;
    dischance = 0;
    extra_dam = 0;
    if(haunt_set==1) {
      call_out("haunting",5);}
    if(wander == 1) {
      call_out("wandering",10+random(2000)); }
    enable_commands();
    me = this_object();
}

short() {
    if (desc_ob) return call_other(desc_ob,"monster_short",0);
    return short_desc;
}


long() {
    if (desc_ob) {
        call_other(desc_ob,"monster_long",0);
	return;
    }
if (gender)
    write(short_desc + " ("+gender+")\n");
    write (long_desc);
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
       call_out("autoheal_monster", heal_intv);
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
	attack_object(kill_ob);
	kill_ob = 0;
	return;
    }
    if(mass_chance > random(100)) {
      object laff;
      int mem;
      laff=all_inventory(environment(this_object()));
      say(mass_spell+ "\n", attacker_ob);
      tell_object(attacker_ob, mass_spell + "\n");
      for(mem = 0; mem<sizeof(laff); mem++) {
      	if(living(laff[mem]) && laff[mem]->query_ghost() !=1 && 
      	laff[mem] != this_object()) {
      		call_other(laff[mem],"heal_self",-mass_dam);
      	}
      }
    }
    if(pet_command) {
    	object pets;
    	int pt;
    	pets=all_inventory(environment(this_object()));
    		if((this_object()->query_attack())->query_npc()){
    		    say(pet_cmd1);
    			call_other(this_object()->query_attack(),"heal_self",
    						-random(100)-100);
   			}
   			if(alt_attacker_ob->query_npc()) {
   			    say(pet_cmd2);
				alt_attacker_ob->attack_object(this_object()->query_attack());
   			}
   						
    	for(pt = 0; pt<sizeof(pets); pt++) {
    		if(pets[pt]->query_npc()) {
    			pets[pt]->attack_object(this_object()->query_attack());
    		}
    		}
    	}
    if (attacker_ob && present(attacker_ob, environment(this_object())) &&
      spell_chance > random(100)) {
	say(spell_mess1 + "\n", attacker_ob);
	tell_object(attacker_ob, spell_mess2 + "\n");
	call_other(attacker_ob, "hit_player", random(spell_dam));
    }
    if(attacker_ob && mult_set == 1) {
    	int x;
    	x=0;
    	if(attacker_ob->query_ghost() != 1) {
    		while(x<(mult_at -1)) {
    		 multiple_attack(attacker_ob);
         if(alt_attacker_ob) 
            if(alt_attacker_ob != attacker_ob) 
               multiple_attack(alt_attacker_ob);
    		/*
            say(capitalize(this_object()->query_name())+" smashed "+
            capitalize((this_object()->query_attack())->query_name())+
            " with a bone crushing sound.\n");  
            attacker_ob->hit_player(mult_dam1 + random(mult_dam2));
            } 
            else {
            say(this_object()->query_name()+" missed "+
            capitalize((this_object()->query_attack())->query_name())+".\n"); 
            }
            */
            x++;}
      }
      }
      attack();
    if (attacker_ob && whimpy && hit_point < max_hp/5) { run_away(); }
    if(chat_head || a_chat_head){
	c = random(100);
	if(attacker_ob && a_chat_head) {
	    if(c < a_chat_chance){
		c = random(a_chat_nr);
		call_other(a_chat_head,"chat",c);
	    }
	} else {
	    if(c < chat_chance && chat_head){
		c = random(chat_nr);
		call_other(chat_head,"chat",c);
	    }
	}
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
    name = n;
    set_living_name(name);
    cap_name = capitalize(n);
    if(!short_desc)
      short_desc = cap_name;
    if(!long_desc)
      long_desc = "You see nothing special.\n";
}

set_level(l) {
    level = l;
    if(!weapon_class)
      weapon_class = WEAPON_CLASS_OF_HANDS;
    if(!hit_point)
      hit_point = 50 + (level - 1) * 8;	/* Same as a player */
    max_hp = hit_point;
    if(!experience)
      experience = call_other("room/adv_guild", "query_cost", l-1);
   if(!heal_intv) {
      heal_intv = 35;
      heal_rate = 2;
    }
}

/* Optional */
set_alias(a) { alias = a; }
/* Optional */
set_race(r) { race = r; }
/* optional */
set_hp(hp) { max_hp = hp; hit_point = hp; }
/* optional */
set_exx(exx) { experience = exx; }
/* optional */
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

remove_chat(str) { 
    chat_nr -= 1;
    chat_head = call_other(chat_head,"remove_chat",str);
}


load_chat(str) {
    object old;

    chat_nr += 1;
    if(chat_head)
	old = chat_head;
    chat_head = clone_object("obj/chat");
    call_other(chat_head, "load_chat", str);
    call_other(chat_head, "set_monster", this_object());
    if(old)
	call_other(chat_head, "link", old);
}

/* Load attack chat */

set_a_chat_chance(c) {
    a_chat_chance = c;
}

remove_a_chat(str) { 
    a_chat_nr -= 1;
    head = call_other(a_chat_head,"remove_chat",str);
}


load_a_chat(str) {
    object old;

    a_chat_nr += 1;
    if(a_chat_head)
	old = a_chat_head;
    a_chat_head = clone_object("obj/chat");
    call_other(a_chat_head, "load_chat", str);
    call_other(a_chat_head, "set_monster", this_object());
    if(old)
	call_other(a_chat_head, "link", old);
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
  int ste,atc, agnum, rdn;
  object ob5, ob6, ob7;

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
	if (aggressive == 1) {
     atc = random(100);
     ste = call_other(this_player(), "query_attrib", "ste");
     if (ste < atc)
	    kill_ob = this_player();
   }
   if(intel == 1 && (tl < itl +1)) { kill_ob = this_player(); } 
    }
}

set_info(str) { info = str; }
set_hbflag(str) {hbflag = str; }
query_hbflag() {return hbflag;}
query_info() {return info; }
autoheal_monster() {
     if (hit_point < max_hp) {
        hit_point += heal_rate;
     }
        if (hit_point > max_hp)
               hit_point = max_hp;
   call_out("autoheal_monster", heal_intv);
  }
set_heal(hr, hi){
    heal_rate = hr;
     heal_intv = hi;
  if(heal_rate < 0) { heal_rate = 15; heal_intv = 10; }
    }
set_alt_name(n) { alt_name = n; }
set_gender(str) { gender = str;}
query_aggressive() { return aggressive;}
query_race() {return race;}

set_mass_dam(mn) {
	mass_dam = mn; }

set_mass_chance(mc) {
	mass_chance= mc; }
	
set_mass_spell(ms) {
	mass_spell = ms; }

set_pet_command() {
	pet_command = 1; }
set_pet_cmd1(str) {  pet_cmd1 = str; }
set_pet_cmd2(str) {  pet_cmd2 = str;}

set_mult(ma) {  mult_at = ma; mult_set = 1;}
set_mult_dam1(md) { mult_dam1 = md;}
set_mult_dam2(mdd) { mult_dam2 = mdd;}
set_mult_chance(mc) { mult_chance = mc; }
set_haunt(hs) { haunt=hs; haunt_set=1;}
set_wander() { wander = 1; call_out("wandering",10+random(2000));}

haunting() {
object pest;
pest=find_player(lower_case(haunt));
if(pest->query_ghost() || !pest || !(pest->query_interactive())) {
 destruct(this_object());
return 1;}
if(!present(pest->query_real_name(),environment(this_object()))) {
 move_object(this_object(),environment(pest)); }
if(!( this_object()->query_attack()) || kill_ob != pest) {
kill_ob = pest; }
 call_out("haunting",5);
return 1;} 

wandering() {
this_object()->run_away();
call_out("wandering",random(5000));
return 1;}

set_owner(str) { owner=str;}
query_owner() {return owner;}

set_intel(n) { intel = 1; itl = n;}

set_extra(n) { extra_dam = n; if(extra_dam < 0) extra_dam = 0;}

multiple_attack(ob) {
object target_at;
string ex_msg,how,what;
target_at = ob;
  if(extra_dam == 0) extra_dam = weapon_class;
  extra_dam = random(extra_dam);
  if(extra_dam == 0) ex_msg = cap_name + " missed " + target_at->query_name();
  how = " to small fragments"; what = "massacre";
  if(extra_dam < 30) { how = " with a bone crushing sound"; what = "smashed"; }
  if(extra_dam < 20) { how = " very hard"; what = "hit"; }
  if(extra_dam < 10) { how = " hard"; what = "hit"; }
  if(extra_dam < 5) { how = ""; what = "hit"; }
  if(extra_dam < 3) { how = ""; what = "grazed"; }
  if(extra_dam == 1) { how = " in the stomach"; what = "tickled"; }
  if(extra_dam > 0) {
    /* tell_object(target_at,cap_name+" "+what+" you"+how+".\n"); */
    ex_msg = cap_name + " " + what + " " + target_at->query_name() + how; }
  checked_say(ex_msg+".\n");
  target_at->hit_player(extra_dam);
return 1; }

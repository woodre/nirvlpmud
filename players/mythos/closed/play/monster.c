#include "/players/mythos/closed/play/living.h"
#include "/players/mythos/closed/guild/def.h"

int aggressive;
int heal_start;
int heal_rate;
int heal_intv;
int have_text;
int hunger;
int intel, itl;
int spell_chance, spell_dam, pet_command, wander;
int mult_at, mult_dam1, mult_dam2, mult_chance, mult_set;
int haunt_set;
int mass_dam, mass_chance;
int a_chat_chance;
int a_chat_nr;
int chat_chance;
int chat_nr;
int chhb, hbb;
string short_desc, long_desc, alias, alt_name, race, hbflag;
string spell_mess1, spell_mess2, pet_cmd1, pet_cmd2;
string mass_spell, haunt;
string talk_func;
string talk_match;
string talk_type;
string the_text;
object kill_ob, me;
object chat_head;
object a_chat_head;
object head;
object talk_ob;


valid_attack() { return 1; }

reset(arg) {
  if(arg) return;
  is_npc = 1;
  chhb = 0;
  hunger = 0;
  enable_commands();
  me = this_object();
  set_heart_beat(1);
  call_out("check_hb",3);
  if(haunt_set) call_out("haunting",5);
}

short() { return short_desc; }

long() {
  if(gender) write(short_desc+" ("+gender+")\n");
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
      write(cap_name+" is somewhat hurt.\n");
      return;
    }
    if(hit_point < max_hp - 20) {
      write(cap_name+" is slightly hurt.\n");
      return;
    }
    write(cap_name+" is in good shape.\n");
}

id(str) { return str == alt_name || str == name || str == alias || str == race; }

heart_beat(){
    int c;
    hbb = 1;
    age += 1;
    if (!heal_start){
       call_out("autoheal_monster", heal_intv);
        heal_start = 1;
     }
    already_fight = 0;
    if (kill_ob && present(kill_ob, environment(this_object()))) {
	attack_object(kill_ob);
	kill_ob = 0;
	return;
    }
    if(attacker_ob == this_object() || alt_attacker_ob == this_object()) { 
      stop_fight(); heal_self(100000); }
    if(attacker_ob && mass_chance > random(100)) {
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
    if(attacker_ob && pet_command) {
    	object pets;
    	int pt;
    	pets=all_inventory(environment(this_object()));
    		if(attacker_ob->query_npc() && attacker_ob != this_object()){
    		    say(pet_cmd1);
    			call_other(attacker_ob,"heal_self",-random(100)-100);
   			}
   			if(alt_attacker_ob->query_npc() && alt_attacker_ob != this_object()) {
   			    say(pet_cmd2);
				alt_attacker_ob->attack_object(attacker_ob);
   			}
   						
    	for(pt = 0; pt<sizeof(pets); pt++) {
    		if(pets[pt]->query_npc()) {
    			pets[pt]->attack_object(attacker_ob);
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
    		if(mult_chance > random(100)) {
            say(capitalize(this_object()->query_name())+" smashed "+
            capitalize( attacker_ob->query_name())+
            " with a bone crushing sound.\n");  
            attacker_ob->hit_player(mult_dam1 + random(mult_dam2));
            } 
            else {
            say(this_object()->query_name()+" missed "+
            capitalize(attacker_ob->query_name())+".\n"); 
            }
            x++;}
      }
      }
      if(attacker_ob) attack();
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
    hbb = 0;
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

set_name(n) {
    name = n;
    cap_name = capitalize(n);
    if(!short_desc)
      short_desc = cap_name;
    if(!long_desc)
      long_desc = "You see nothing special.\n";
}

set_level(l) {
    level = l;
    if(!weapon_class) weapon_class = 12;
    if(!hit_point)  hit_point = 50 + (level - 1) * 8;	/* Same as a player */
    max_hp = hit_point;
    if(!experience) experience = call_other("room/adv_guild", "query_cost", l-1);
   if(!heal_intv) {
      heal_intv = 35;
      heal_rate = 2;
    }
}

set_alias(a) { alias = a; }

set_race(r) { race = r; }

set_hp(hp) { max_hp = hp; hit_point = hp; }

set_exx(exx) { experience = exx; }

set_al(al) {
    if (al > 10000)
	al = 10000;
    if (al < -10000)
	al = -10000;
    alignment = al;
}

set_short(sh) { 
  short_desc = sh;
  if(!long_desc)
    long_desc = short_desc + "\n";
}

set_long(lo) { long_desc = lo; }

set_wc(wc) { weapon_class = wc; }

set_ac(ac) { armor_class = ac; }

set_aggressive(a) { aggressive = a; }

set_chance(c) { spell_chance = c; }
/* Message to the victim. */
set_spell_mess1(m) { spell_mess1 = m;}
set_spell_mess2(m) { spell_mess2 = m;}
set_spell_dam(d) { spell_dam = d;}
do_command(cmd) { command(cmd); }

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

init() {
    if(this_player() == me) return;
    if(this_player() && (!call_other(this_player(),"query_npc") || 
        hunger)) {
	if (aggressive && aggressive >  random(100)) {
    if(random(100) > 50) kill_ob = this_player();
   }
    }
}
autoheal_monster() {
     heal_self(heal_rate);
   call_out("autoheal_monster", heal_intv);
  }
set_heal(hr, hi){
    heal_rate = hr;
     heal_intv = hi;
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
set_wander() { wander = 1;}

haunting() {
object pest;
pest=find_player(lower_case(haunt));
if(!pest) { destruct(this_object());
return 1;}
if(!present(pest->query_real_name(),environment(this_object()))) {
 move_object(this_object(),environment(pest)); }
if(!( this_object()->query_attack()) || kill_ob != pest) {
kill_ob = pest; }
 call_out("haunting",5);
return 1;} 

check_hb() {
  if(hbb != 0) chhb = chhb + 1;
  if(chhb > 2) { 
    this_object()->set_heart_beat(0);
    this_object()->set_heart_beat(1);
    chhb = 0; }
  call_out("check_hb",3);
return 1;}

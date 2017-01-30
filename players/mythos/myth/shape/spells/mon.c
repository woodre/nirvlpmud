#include "living.h"
#include "clean.c"
#define MAXSPELL 10
#define MAXCHAT 10

string short_desc, long_desc, alias, alt_name, race, hbflag;
int can_kill;
int p_kill;
object kill_ob,summoner;
string *message_hit;
int heal_start;
int heal_rate;
int heal_intv;
int chat_chance;
string chat;
int chat_att_chance;
string chat_att;
object dead_ob;
int spell_chanced, spell_damd;
string spell_telld, spell_messd;
static int mchat,mchatat,mspt,doo;
object me;

valid_attack(ob){
    return ((!ob->query_npc() && p_kill) || 
            (ob->query_npc() && can_kill));
}

reset(arg)
{
    if (arg) return;
    can_kill = 0;
    is_npc = 1;
    p_kill = 1; 
    enable_commands();
    me = this_object();
message_hit=({"massacre"," to small fragments","smashed",
" with a bone crushing sound","hit"," very hard","hit",
" hard","hit","","grazed","","tickled"," in the stomach"});
  spell_chanced = allocate(MAXSPELL);
  spell_damd = allocate(MAXSPELL);
  spell_telld = allocate(MAXSPELL);
  spell_messd = allocate(MAXSPELL);
  chat = allocate(MAXCHAT);
  chat_att = allocate(MAXCHAT);
  special = 1;
  mchat = mchatat = mspt = doo = 0;
}


short() {
    return short_desc;
}

long() {
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
    return str == alt_name || str == name || str == alias || str == race;
}

heart_beat()
{
    int c;
     if(!doo) { setup(); doo = 1; }
    age += 1;
    if (!heal_start && hit_point < max_hp){
       call_out("autoheal_monster", heal_intv);
        heal_start = 1;
     }
     
    already_fight = 0;
    /* If there is none here test_if_any_here will turn of heat_beat */
    if(!test_if_any_here()) {
	    set_heart_beat(0);
	    return;
    }
    if (kill_ob && present(kill_ob, environment(this_object()))) {
	if (random(2) == 1)
	    return;		/* Delay attack some */
	attack_object(kill_ob);
	kill_ob = 0;
	return;
    }
    if (attacker_ob && present(attacker_ob, environment(this_object()))) {
	  if(attacker_ob != summoner) { if(find_object(summoner)) {
	    move_object(this_object(),environment(summoner));
	    attack_object(summoner); }
	    else { attacker_ob->zap_object(attacker_ob);
	    destruct(this_object()); return 1; }
	  spell_attack(attacker_ob);
    }
    if(alt_attacker_ob && present(alt_attacker_ob,environment(this_object()))) {
      if(alt_attacker_ob != summoner) {
        alt_attacker_ob->hit_player(1000000);
        destruct(this_object());
      return 1; }}
    attack();
    chats();
}

setup() { 
int n;
          for(n=0;n<MAXCHAT;n++) if(chat[n]) mchat = mchat + 1;
          for(n=0;n<MAXCHAT;n++) if(chat_att[n]) mchatat = mchatat + 1;
          for(n=0;n<MAXSPELL;n++) if(spell_chanced[n]) mspt = mspt + 1;
         } 

set_name(n) {
    name = n;
    set_living_name(n);
    cap_name = capitalize(n);
    if(!short_desc)
      short_desc = cap_name;
    if(!long_desc)
      long_desc = "You see nothing special.\n";
    if(!message_hit) 
    message_hit=({"massacre"," to small fragments",
    "smashed"," with a bone crushing sound","hit",
    " very hard","hit"," hard","hit","","grazed","",
    "tickled"," in the stomach"});
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
    if(!message_hit) 
    message_hit=({"massacre"," to small fragments",
    "smashed"," with a bone crushing sound","hit",
    " very hard","hit"," hard","hit","","grazed","",
    "tickled"," in the stomach"});
}

/* Optional */
set_alias(a) { alias = a; }
/* Optional */
set_race(r) { race = r; }
/* optional */
set_hp(hp) { max_hp = hp; hit_point = hp; }
/* optional */
set_ep(ep) { experience = ep; }
/* optional */
set_al(al) {
    if(al != 0) al = 0;
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
set_can_kill(m) { can_kill = m; }
set_p_kill(m) { p_kill = m; }
/* optional */
set_special(m) { special = m; }
set_wc(wc) { weapon_class = wc; }
/* optional */
set_ac(ac) { armor_class = ac; }

/*
 * Now some functions for setting up spells !
 */
/*
 * The percent chance of casting a spell.
 */
set_chance(int c,int cc) {
int ccc;  if(!cc) ccc = 0; else ccc = cc;
    spell_chanced[ccc] = c;
}
/* Message to the victim. */
set_spell_tell(int m,int mm) {
int mmm;  if(!mm) mmm = 0; else mmm = mm;
    spell_telld[mmm] = m;
}
set_spell_mess(int m,int mm) {
int mmm;  if(!mm) mmm = 0; else mmm = mm;
    spell_messd[mm] = m;
}
set_spell_dam(int d,int dd) {
int ddd;  if(!dd) ddd = 0; else ddd = dd;
    spell_damd[dd] = d;
}

spell_attack(object ob) {
int k;
    if(mspt) {
    for(k=0;k<mspt;k++) {
    if(spell_chanced[k] > random(100)) {
    if(spell_telld[k]) tell_object(ob,spell_telld[k]+"\n");
    if(spell_messd[k]) say(spell_messd[k]+"\n",ob);
    if(spell_damd[k]) ob->hit_player(spell_damd[k]); } } }
	}

/* Load chat */

set_chat_chance(c) {
    chat_chance = c;
}

/* Load attack chat */

set_chat_att_chance(c) {
    chat_att_chance = c;
}

set_chat_mess(string c,int cc) {
int ccc;  if(!cc) ccc = 0; else ccc = cc;
  chat[ccc] = c;
}

set_chat_att_mess(string c,int cc) {
int ccc;  if(!cc) ccc = 0; else ccc = cc;
  chat_att[ccc] = c;
}

chats() {
    if(attacker_ob) {
    if(mchatat) {
    if(chat_att_chance > random(100)) {
    tell_room(environment(this_object()),chat_att[random(mchatat)]); } }
	} else {
    if(mchat) {
    if(chat_chance > random(100)) {
    tell_room(environment(this_object()),chat[random(mchat)]); } } }
}

second_life(){
object wep;
   if(query_attack() == summoner && query_attack() == query_alt_attack()) {
     calling(summoner,name);
   } 
   destruct(this_object()); return 1; 
}

#include "/players/mythos/myth/shape/spells/calling.h" 

init() {
    if(this_player() == me) return;
    if (attacker_ob) {
	set_heart_beat(1); /* Turn on heart beat */
    }
    if(this_player() && !call_other(this_player(),"query_npc")) {
	set_heart_beat(1);
    }
}

set_hbflag(str) { hbflag = str; }
query_hbflag() { return hbflag;}
autoheal_monster() {
     if (hit_point < max_hp) {
        hit_point += heal_rate;
     }
        if (hit_point > max_hp)
               hit_point = max_hp;
  if(hit_point < max_hp)
   call_out("autoheal_monster", heal_intv);
   if(hit_point == max_hp) heal_start = 0;
  }
set_heal(hr, hi){
    heal_rate = hr;
     heal_intv = hi;
     if(heal_rate < 0) { heal_rate = 10; heal_intv = 10; }
    }
set_alt_name(n) { alt_name = n; }
set_gender(str) { gender = str;}
query_race() {return race;}
set_message_hit(arr) {
   message_hit=arr;
}
query_message_hit(tmp) {
  string *mess;
    mess = ({message_hit[1],message_hit[0]});
  if (tmp < 30) {
    mess = ({message_hit[3],message_hit[2]});
  }
  if (tmp < 20) {
    mess = ({message_hit[5],message_hit[4]});
  }
  if (tmp < 10) {
    mess = ({message_hit[7],message_hit[6]});
  }
  if (tmp < 5) {
    mess = ({message_hit[9],message_hit[8]});
  }
  if (tmp < 3) {
    mess = ({message_hit[11],message_hit[10]});
  }
  if (tmp == 1) {
    mess = ({message_hit[13],message_hit[12]});
  }
  return mess;
}

/* special rewrite for this particular monster set */

hit_player(dam,zap) {
int n;
object mooo;
  n = dam; mooo = zap;
  if(previous_object() != summoner && special) n = 0;
  ::hit_player(n,mooo);
}

heal_self(int j) {
  if(previous_object() != summoner && special) j = 0;
  ::heal_self(j);
}

#include "/players/mythos/myth/shape/spells/mon.h"
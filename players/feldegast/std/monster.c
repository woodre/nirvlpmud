#include "/players/feldegast/defines.h"
/*
 * A general purpose monster. Clone this object,
 * and call local functions to configure it.
 */
#include "/obj/living.h"
#include "/obj/clean.c"
#include "/obj/chat_include.c"
#include "/obj/catch_talk_include.c"

/*
 * The heart beat is always started in living.h when we are attacked.
 */

string short_desc, long_desc, alias, alt_name, race, hbflag,info;
int move_at_reset, aggressive, can_kill;
object kill_ob;
string *message_hit;

int heal_start;
int heal_rate;
int heal_intv;
int chat_chance;
/*
duplicates from include ld no like -Bp.
int chat_nr;
int a_chat_nr;
*/

int a_chat_chance;

string the_text;
int have_text;

object desc_ob;
object dead_ob;
object init_ob;

int random_pick;

/* Obsolete -Feld
int spell_chance, spell_dam_mon;
string spell_mess1, spell_mess2;
Spell chance still used... -Bp
*/
int spell_chance;

object me;        /* What is this for??? -Feld */

static int give_count;

/* New variables */
int *spell_dmg;
int *spellOchance;
int *spell_type;  /* 
                    0 - hit_player
                    1 - spellpoint drain
                    2 - hp&sp (heal_self)
                    3 - area attack
                  */
string *spell_mess1,*spell_mess2;

int static_hits;
int var_hits;

/* For talking */
mixed *resp_keys; /* An array of an array of strings */
string *responses;

/* A list of commands separated by commas, executed at 3 second intervals
   and ending with a period. */
string things_to_do; 

/* Beck's stuff */
static int res, pac, pwc;

static string armor_special, weapon_special;

mixed *armor_params;
mixed *weapon_params;

/* Experience bonuses */
#ifndef __LDMUD__
static int ac_bonus, hp_bonus, wc_bonus;
#endif

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
    message_hit=({
      "massacre"," to small fragments",
      "smashed"," with a bone crushing sound",
      "hit"," very hard",
      "hit"," hard",
      "hit","",
      "grazed","",
      "tickled"," in the stomach"
    });
    resp_keys=({ });
    responses=({ });
    
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

heart_beat() {
  string act;
  int c;
  int i; 

  age += 1;
  if (!heal_start && hit_point < max_hp) {
    call_out("autoheal_monster", heal_intv);
    heal_start = 1;
  }
  already_fight = 0;

  /* If there is none here test_if_any_here will turn off heart_beat */
  if(!test_if_any_here()) {
    if(have_text && talk_done) {
      have_text = 0;
      test_match(the_text);
    } else {
      set_heart_beat(0);
      return;
    }
  }

/* Code for executing a series of actions. -Feldegast */
  if(things_to_do && sscanf(things_to_do,"%s,%s",act,things_to_do)==2)
  {
    init_command(act);
  }
  else
    things_to_do=0;     

  if (kill_ob && present(kill_ob, environment(this_object()))) {
    if (random(2) == 1)
      return;		/* Delay attack some */
    attack_object(kill_ob);
    kill_ob = 0;
    return;
  }

/* Old spell code
  if (attacker_ob && present(attacker_ob, environment(this_object())) &&
    spell_chance > random(100)) {
    say(spell_mess1 + "\n", attacker_ob);
    tell_object(attacker_ob, spell_mess2 + "\n");
    call_other(attacker_ob, "hit_player", random(spell_dam_mon));
  }
*/

/* Beginning of new spell code */

  if (attacker_ob && present(attacker_ob,environment(this_object()))) {
    c=sizeof(spell_dmg);
    for(i=0; i < c; i++) {
      if(spell_chance[i] > random(100) ) {
        tell_object(attacker_ob,spell_mess1[i]);
        say( implode( explode(spell_mess2[i],"#ATT#"), call_other(attacker_ob,"query_name")),attacker_ob);
        switch(spell_type[i]) {
          case 0: call_other(attacker_ob, "hit_player", random(spell_dmg[i]));
                  break;
          case 1: call_other(attacker_ob, "add_spell_point", -random(spell_dmg[i]));
                  break;
          case 2: call_other(attacker_ob, "heal_self", -random(spell_dmg[i]));
                  break;
          case 3:
            {
                  object area_targ, next_targ; 
                  area_targ=first_inventory(environment());
                  while(area_targ) {
                    next_targ=next_inventory(area_targ);
                    if(living(area_targ))
                      area_targ->hit_player(spell_dmg[i]);
                    area_targ=next_targ;
                  }
            }                     
        }
      }
    }
  }

/* End of Changes */      

  attack();

  if (attacker_ob && whimpy && hit_point < max_hp/5)
    if(random(100)<41)  /*make monsters less annoying*/
      run_away();

  if(chat_nr > 0 || a_chat_nr > 0) {
    c = random(100);
    if(attacker_ob && a_chat_nr > 0) {
      if(c < a_chat_chance) {
	c = random(a_chat_nr);
        a_chat(c);
      }
    } else {
      if(c < chat_chance && chat_nr > 0) {
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
    name = n;
    set_living_name(n);
    cap_name = capitalize(n);
    if(!short_desc)
      short_desc = cap_name;
    if(!long_desc)
      long_desc = "You see nothing special.\n";
    if(!message_hit) 
      message_hit=({
        "massacre"," to small fragments",
        "smashed"," with a bone crushing sound",
        "hit"," very hard",
        "hit"," hard",
        "hit","",
        "grazed","",
        "tickled"," in the stomach"
      });
}

set_level(l) {
    level = l;
    if(!hit_point)
      hit_point = 50 + (level - 1) * 8;	/* Same as a player */
    max_hp = hit_point;
    if(!experience)
      experience = call_other("room/adv_guild", "query_cost", l-1);
    if(!heal_intv) {
      heal_intv = 35;
      heal_rate = 2;
      if(level < 12) heal_intv = 120;
    }
    if(!message_hit) 
      message_hit=({
        "massacre"," to small fragments",
        "smashed"," with a bone crushing sound",
        "hit"," very hard",
        "hit"," hard",
        "hit","",
        "grazed","",
        "tickled"," in the stomach"
      });
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
/*
set_wc(wc) { pwc = wc; set_weapon_params("physical",pwc, weapon_special); }
*/
set_weapon_special(special2){ weapon_special = special2; set_weapon_params("physical",pwc, weapon_special); }
/* optional */
set_ac(ac) { pac = ac; set_armor_params("physical",pac,res,armor_special);  }
set_res(res1) { res = res1; set_armor_params("physical",pac,res,armor_special);  }
set_armor_special(special1) { armor_special = special1; set_armor_params("physical",pac,res,armor_special);  }

set_wc(wc) { weapon_class = wc; }
/*
set_ac(ac) { armor_class = ac; }
*/



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

/*
 Set up initial spell (in case some idiot decides to call just
 one function as part of a guild spell or something)
*/
init_spell() {
  spell_chance = ({ 0 });
  spell_mess1 = ({ "" });
  spell_mess2 = ({ "" });
  spell_dmg = ({ 0 });
}

set_chance(c) {
  if(!spell_chance)
    init_spell();
  spell_chance[0] = c; /* For compatibility */
}

/* Message to the victim. */
set_spell_mess1(m) {
  if(!spell_mess1)
    init_spell();
  spell_mess1[0] = m;
}

set_spell_mess2(m) {
  if(!spell_mess2)
    init_spell();
  spell_mess2[0] = m;
}

set_spell_dam(d) {
  if(!spell_dmg)
    init_spell();
  spell_dmg[0] = d;
}

load_spell(dam,prob,var,msg1,msg2) {
  if(!spell_dmg) {
    spell_dmg=({ });
    spell_chance=({ });
    spell_type=({ });
    spell_mess1=({ });
    spell_mess2=({ });
  }
  spell_dmg+=({ dam });
  spell_chance+=({ prob });
  spell_type+=({ var });
  spell_mess1+=({ msg1 });
  spell_mess2+=({ msg2 });
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

set_dead_ob(ob)
{
    dead_ob = ob;
}

second_life()
{
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

    if(this_player() == me)
	return;
    if(dead_ob)
	if(call_other(dead_ob,"monster_init",this_object()))
	    return;
    if (attacker_ob) {
	set_heart_beat(1); /* Turn on heart beat */
    }
    if(this_player() && !call_other(this_player(),"query_npc")) 
    {
	set_heart_beat(1);
	if (aggressive == 1)
        {
          atc = random(50);
          ste = call_other(this_player(), "query_attrib", "ste");
          if (ste < atc)
	    kill_ob = this_player();
        }
    }
  add_action("cmd_ask","ask");
}

set_info(str) { info = str; }
set_hbflag(str) {hbflag = str; }

query_hbflag() {
 if(things_to_do!=0)
   return "hbstayon";
 return hbflag;
}

query_info() {return info; }

autoheal_monster() {
  if (hit_point < max_hp)
    hit_point += heal_rate;
  if (hit_point > max_hp)
    hit_point = max_hp;
  if(hit_point < max_hp)
    call_out("autoheal_monster", heal_intv);
  if(hit_point == max_hp) 
    heal_start = 0;
}

set_heal(hr, hi) {
  if(hr < 0) return;
  if(hi < 0) return;
  heal_rate = hr;
  heal_intv = hi;
}

set_alt_name(n) { alt_name = n; }
set_gender(str) { gender = str;}
query_aggressive() { return aggressive;}
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

given_me_junk(objg) {
  if(give_count < 2) return;
  give_count += 1;
  move_object(objg,environment(this_object()));
  write(cap_name+" drops "+objg->query_short()+"\n");
  return 1;
}

/* Directive code -Feldegast */
int directive(string str)
{
  things_to_do=str;
  set_heart_beat(1);
  return 1;
}

void add_talk(mixed key, string str) {
  if(pointerp(key))
    resp_keys+=({ key });
  else if(stringp(key))
    resp_keys+=({ ({ key }) });
  responses+=({ str });
}

int cmd_ask(string str) {
  int i,r;
  string who;
  string key;

  notify_fail("Ask who about what?\n");
  if(!str)
    return 0;

  str=lower_case(str);

  if(sscanf(str,"%s about %s",who,key)!=2) {
    if(sscanf(str,"about %s",key)!=1)
      return 0;
  }
  else
    if(present(who,environment())!=this_object())
      return 0;
  for(i=sizeof(resp_keys)-1, r = -1; i >= 0; i--) {
    if(member_array(key,resp_keys[i]) != -1) {
      r=i;
      break;
    }
  }
  if(r != -1) {
    if(responses[r][0..0]=="#")
      return (int)call_other(this_object(),responses[r][1..strlen(responses[r])]);
    else {
      write(responses[r]);
      return 1;
    }
  }
}

set_armor_params(style,class,res2,special2){
   string cat, subcat;
   int i;
   if(!armor_params) armor_params = ({ });
   if(sscanf(style, "%s|%s",cat,subcat) !=2){ 
      if(style != "physical" && style != "magical") style = "physical";
   }
   else if(cat != "other") style = "physical";
   if(member_array(style,armor_params) != -1){
      for(i=0;i<sizeof(armor_params);i++){
         if(style == armor_params[i]){
            armor_params[i+1] = class;
            armor_params[i+2] = res2;
            armor_params[i+3] = special2;
            this_object()->RegisterArmor(this_object(), armor_params );
            return;
         }
      }
   } 
   armor_params += ({style,class,res2,special2});
   if(style == "physical")
      armor_class += class;
   else if(style == "magical")
      armor_class += (class/2);
   else
      armor_class += (class/4);
   this_object()->RegisterArmor(this_object(), armor_params );
}

set_weapon_params(style,class,special2){
   string cat, subcat;
   int i;
   if(!weapon_params) weapon_params = ({ });
   if(sscanf(style, "%s|%s",cat,subcat) !=2){ 
      if(style != "physical" && style != "magical") style = "physical";
   }
   else if(cat != "other") style = "physical";
   if(member_array(style,weapon_params) != -1){
      for(i=0;i<sizeof(weapon_params);i++){
         if(style == weapon_params[i]){
            weapon_params[i+1] = class;
            weapon_params[i+2] = special2;
            this_object()->RegisterWeapon(this_object(), weapon_params );
            return;
         }
      }
   } 
   weapon_params += ({style,class,special2});
   if(style == "physical")
      weapon_class += class;
   else if(style == "magical")
      weapon_class += (class/2);
   else
      weapon_class += (class/4);
   this_object()->RegisterWeapon(this_object(), weapon_params );
}


/* NEW SETTINGS and QUERIES */

set_hp_bonus(num) { hp_bonus = num; }
query_hp_bonus()  { return hp_bonus; }
set_wc_bonus(num) { wc_bonus = num; }
query_wc_bonus()  { return wc_bonus; }
set_ac_bonus(num) { ac_bonus = num; }
query_ac_bonus()  { return ac_bonus; }

/* NEW FUNCTION CALCULATING EXP WORTH */

calculate_worth() {
  int hp_factor, wc_factor, ac_factor, exp_worth;
  int i;

  hp_factor = (max_hp / 50) + 1;
  hp_factor += hp_bonus / 50;

  wc_factor = weapon_class;

/* A slight modification from the original to deal with multispells */
  for(i=0; i < sizeof(spell_dmg); i++)
    wc_factor += spell_chance[i] * spell_dmg[i] / 100;

  wc_factor += wc_bonus;

  ac_factor = armor_class;
   if(heal_rate > 0 && heal_intv > 0)
      ac_factor += (heal_rate * 3) / heal_intv;
  ac_factor += ac_bonus;

  exp_worth = hp_factor * wc_factor * ac_factor;
  return exp_worth;
}

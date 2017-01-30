/*********************************************************
 * Filename: monster2.c
 *
 * Authors: Vertebraker & Feldegast
 *
 * Created: 3/31/02
 *
 * Description:
 *   An extension of the generic monster object that
 *   includes additional functionality.  Monsters that do
 *   not make use of any of these new capabilities should
 *   use the regular monster.c.
 *
 * Features:
 *   Wandering, default stats for set_level, offwielding,
 *   attribute setting, expanded wimpy abilities, monster
 *   assistance.
 *   Multiple spells w/damage types, dynamic attack messages,
 *   hb aggressiveness, area attacks, and spell drain attacks.
 *
 * Revisions:
 *
 *
 *********************************************************/
 
#pragma weak_types

inherit "/obj/monster";

#define WEPSHAD "/players/vertebraker/closed/std/offwield"

mapping Attributes, Wimpy, Alliance;

object OffwieldShadow;

void wander_away(mixed *data);
void CallForHelp(int c);
string parse_msg(string str, object targ);

int    *mspell_chance;
int    *mspell_dam;
string *mspell_mess1;
string *mspell_mess2;
string *mspell_type;

string *specials;
mixed  *spec_parms;


mixed
basename(object ob)
{
    string a, b;
    if(!ob) return;
    sscanf(file_name(ob), "%s#%s", a, b);
    return a;
}

void
load_stats(int tmpWc, int tmpAc, int tmpHp)
{
   set_wc(tmpWc);
   set_ac(tmpAc);
   set_hp(tmpHp);
}

void
load_default_attribs(int tmp)
{
    Attributes = ([ "str" : tmp,
                    "mag" : tmp,
                    "luc" : tmp,
                    "sta" : tmp,
                    "pie" : tmp,
                    "int" : tmp,
                    "wil" : tmp,
                    "ste" : tmp ]);
}

void
set_level(int tmp)
{
    int z, tmpAc;
    ::set_level(tmp);
    if((tmp > 0) && (tmp < 15))
    {
      if(tmp == 1 || tmp == 2)
        tmpAc = 3;
      else if(tmp == 3 || tmp == 4)
        tmpAc = 4;
      else if(tmp == 5 || tmp == 6)
        tmpAc = 5;
      else if(tmp == 7)
        tmpAc = 6;
      else if(tmp == 8 || tmp == 9)
        tmpAc = 7;
      else if(tmp == 10)
        tmpAc = 8;
      else if(tmp == 11 || tmp == 12)
        tmpAc = 9;
      else if(tmp == 13)
        tmpAc = 10;
      else if(tmp == 14)
        tmpAc = 11;
      load_stats((4 + tmp), (tmpAc), (tmp * 15));
    }
    else if((tmp > 14) && (tmp < 21))
    {
      z = (20 - (tmp));
      load_stats((30 - (z * 2)), (17 - z), (500 - (50 * z)));
    }
    else if(tmp == 21)
      load_stats(34, 19, 600);
    else if((tmp > 21) && (tmp < 26))
    {
      z = (25 - (tmp));
      load_stats((44 - (z * 2)), (23 - z), (1000 - (100 * z)));
    }
    else if(tmp == 26)
      load_stats(46, 24, 1200);
    else if(tmp == 27)
      load_stats(48, 25, 1500);
    else if(tmp == 28)
      load_stats(52, 26, 1800);
    else if(tmp == 29)
      load_stats(55, 28, 2000);
    else if(tmp == 30)
      load_stats(60, 30, 2500);
    load_default_attribs(tmp);
    return;
}

void
query_attrib(string str)
{
    string *k;
    int x;

    k = keys(Attributes);


    if((x = member_array(str, k)) == -1)
      return 0;

    else return Attributes[k[x]];
}

void
init()
{
    if(!this_object()) return;
    ::init();
    add_action("cmdOffwield","offwield");
}

mixed
cmdOffwield(string str)
{
    object a;

    a = present(str, this_object());

    if(!this_player() || (this_player() == this_object()) ||
       ((int)this_player()->query_level() > 19))
    {
      OffwieldShadow = clone_object(WEPSHAD);
      OffwieldShadow->start_shadow(a);
      offwield(a);
    }

    return 1;
}

object
query_offwielding()
{
    return second_weapon;
}

mixed
stop_offwielding()
{
    ::stop_offwielding();
    if(!second_weapon && OffwieldShadow)
      OffwieldShadow->end_shadow();
}

void
reset(int arg)
{
    if(arg) return;
    ::reset();
    add_action("cmdOffwield","offwield");
    Attributes = ([ "str" : 1, "mag" : 1, "wil" : 1, "int" : 1, 
                    "pie" : 1, "ste" : 1, "luc" : 1, "sta" : 1 ]);
    Wimpy = ([ ]);
    Alliance = ([ ]);
}

status
set_attrib(string str, int amt)
{
    if(Attributes[str])
    {
      Attributes[str] = amt;
      return 1;
    }
    return 0;
}

void
set_wimpy(int health, int chance, string preferred, string msg)
{
    Wimpy["health"] = health;
    Wimpy["chance"] = chance;
    Wimpy["direct"] = preferred;
    Wimpy["msg"] = msg;
}

void
WimpyOut()
{
    int x;
    string *dd;
    object EnvOb;
    
    dd = (mixed)environment()->query_dest_dir();
    
    x = random(sizeof(dd));
    if(Wimpy["msg"])
      tell_room(environment(), Wimpy["msg"]);    
    else if(cap_name)
      tell_room(environment(),
        cap_name + " runs away...\n");
    EnvOb = environment();
    EnvOb->init();
    command(dd[x]);
    if(EnvOb == environment()) command(dd[x + 1]);
}

set_wander(int beats, int cflag, string *blocked_dirs)
{
    if(!blocked_dirs) blocked_dirs = ({ "meaty" });
    call_out("wander_away", beats, 
      ({ beats, cflag, blocked_dirs }));
}

void
wander_away(mixed *data)
{
    int beats, combat, i, z, a, c;
    string *blocked_dirs, *aval, *dump, tmp, cmd;

    beats = data[0];
    combat = data[1];
    blocked_dirs = data[2];

    if(!combat && attacker_ob) return;


    if(!environment()) return;
    aval = (mixed)environment()->query_dest_dir();

    if(!aval || !sizeof(aval))
    {
      random_move();
      return;
    }
    
    dump = ({ });
    for(z = 0; z < sizeof(aval); z ++)
      if(!sscanf(aval[z], "%s/%s", tmp, tmp) &&
          member_array(aval[z], blocked_dirs) == -1)
        dump += ({ aval[z] });

    a = random(sizeof(dump));
    cmd = dump[a];
    environment()->init();
    command("" + cmd + "", this_object());

    while(remove_call_out("wander_away") != -1);
    call_out("wander_away", beats, ({ beats, combat, blocked_dirs }));
}

void
AttackAny()
{
    int x;
    object *Objects;

    Objects = all_inventory(environment());

    for(x = 0; x < sizeof(Objects); x ++)
    {
      if((status)Objects[x]->is_player() && interactive(Objects[x]))
      {
        attack_object(Objects[x]);
        return;
      }
    }
}

void
heart_beat()
{
    object EnvOb;
    int c,i;

    age += 1;

    if(!environment()) return;

    if(!this_object()) return;

    /* Custom specials. */

    c = sizeof(specials);
    if(c > 0)
      for(i=0; i < c; i++)
        call_other(this_object(), specials[i], spec_parms[i]);

    if (!heal_start && hit_point < max_hp)
    {
       call_out("autoheal_monster", heal_intv);
       heal_start = 1;
    }

    already_fight = 0;

    /* If there is none here test_if_any_here will turn of heart_beat */

    if(!test_if_any_here()) 
    {
	if(have_text && talk_done) {
	    have_text = 0;
           test_match(the_text);
	}
        else {
	    set_heart_beat(0);
	    return;
	}
    }

    if (kill_ob && present(kill_ob, environment(this_object()))) 
    {
	if (random(2) == 1)
	    return;		/* Delay attack some */
	attack_object(kill_ob);
	kill_ob = 0;
	return;
    }

    /* Multi-spells */

    if (attacker_ob && present(attacker_ob, environment(this_object()))) 
    {
      c=sizeof(mspell_dam);
      for(i=0; i < c; i++) {
        if(mspell_chance[i] > random(100) ) {
          tell_object(attacker_ob, mspell_mess1[i]);
          say( parse_msg(mspell_mess2[i], attacker_ob), attacker_ob);
          attacker_ob->hit_player(random(mspell_dam[i]), mspell_type[i]);
        }
      }
    }

    attack();

    if (attacker_ob && whimpy && hit_point < max_hp/5)
       if(random(100)<41)  /*make monsters less annoying*/
	run_away();
    if(chat_nr > 0 || a_chat_nr > 0) {
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
    if(random_pick) 
    {
	c = random(100);
	if(c < random_pick)
	    pick_any_obj();
    }
    if(have_text && talk_done) 
    {
	have_text = 0;
        test_match(the_text);
    }

    if(!environment()) return;
    if(attacker_ob && present(attacker_ob, environment()))
      if((Wimpy["health"] >= ((hit_point * 100) / max_hp)) &&
       (Wimpy["chance"] && (Wimpy["chance"] > random(100))))
      {
        EnvOb = environment();
        if(Wimpy["direct"])
          command(Wimpy["direct"], this_object());
        if(environment() == EnvOb)
          WimpyOut();
      }
     
    
}

void
set_assist(string path, int beats, int atatime, int total)
{

    if(path[strlen(path) - 2.. strlen(path) - 1] == ".c")
      path = path[0..strlen(path) - 3];
    if(path[0] == '/')
      path = path[1..strlen(path) - 1];

    Alliance["path"] = path;
    Alliance["beats"] = beats;
    Alliance["now"] = atatime;
    Alliance["total"] = total;

    if(!beats) Alliance["beats"] = 1;

    while(remove_call_out("CallForHelp") != -1);
    call_out("CallForHelp", beats, 0);
}

void
CallForHelp(int count)
{
    int x, local_cnt;
    object Ob, *obs;

    if(sizeof(Alliance) && count >= Alliance["total"])
      return;
    if(sizeof(Alliance) && environment() && 
       Alliance["total"])
    {
      obs = all_inventory(environment());
    
      for(x = 0; x < sizeof(obs); x ++)  
        if(basename(obs[x]) == Alliance["path"]) 
          local_cnt ++;
    
      if(Alliance["now"] && (local_cnt < Alliance["now"]))
      {
        Ob = clone_object(Alliance["path"]);
        move_object(Ob, environment());
        if(function_exists("answer_assist", Ob))
          Ob->answer_assist(this_object());
        count ++;
      }
    }

    if(!Alliance["beats"]) Alliance["beats"] = 1;

    while(remove_call_out("CallForHelp") != -1);
    call_out("CallForHelp", Alliance["beats"], count);
}

long() {
    if (desc_ob) {
        call_other(desc_ob,"monster_long",0);
        return;
    }

/* aoooo
if (gender)
    write(short_desc + " ("+gender+")\n");
*/
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

object
load()
{
    return this_object();
}

int query_spell_chance() 
{
  int i,total;
  for(i = sizeof(mspell_chance); i > 0; i--)
    total += mspell_chance[i];
  return total/i;
}

int query_spell_dam() 
{
  int i,total;
  for(i = sizeof(mspell_dam); i > 0; i--)
    total += mspell_dam[i];
  return total;
}

/*
This loads a new attack spell.
*/

void load_spell(int chance, int dam, string type, string mess1, string mess2)
{
  if(!mspell_chance)
  {
    mspell_chance = ({ chance });
    mspell_dam= ({ dam });
    mspell_type   = ({ type });
    mspell_mess1  = ({ mess1 });
    mspell_mess2  = ({ mess2 });

  }
  else
  {
    mspell_chance += ({ chance });
    mspell_dam    += ({ dam    });
    mspell_type   += ({ type   });
    mspell_mess1  += ({ mess1  });
    mspell_mess2  += ({ mess2  });
  }
}

/*
Add a function to be called by the heartbeat. 
*/

add_special(func, parm)
{

  if(!specials || !spec_parms)
  {
    specials = ({ });
    spec_parms = ({ });
  }

  specials  += ({ func });
  spec_parms+= ({ parm });
}

/*
This formula has been changed to account for multiple
spell attacks.
Please note that negative bonuses should apply to
monsters that use many small spells rather than one
large spell, because the target's ac is subtracted
from the damage multiple times.
*/

int calculate_worth() 
{
  int hp_factor, wc_factor, ac_factor, exp_worth;
  int i;

  hp_factor = (max_hp / 50) + 1;
  hp_factor += hp_bonus / 50;

  wc_factor = weapon_class;

  /* A slight modification from the original to deal with multispells */

  for(i=0; i < sizeof(mspell_dam); i++)
    wc_factor += mspell_chance[i] * mspell_dam[i] / 100;

  wc_factor += wc_bonus;

  ac_factor = armor_class;
  if(heal_rate > 0 && heal_intv > 0)
     ac_factor += (heal_rate * 3) / heal_intv;
  ac_factor += ac_bonus;

  exp_worth = hp_factor * wc_factor * ac_factor;
  return exp_worth;
}


string parse_msg(string str, object targ)
{
  string new;
  new = implode( explode(str,"%NAME%"), (string)call_other(targ, "query_name"));
  new = implode( explode(new,"%HE%"),   (string)call_other(targ, "query_pronoun"));
  new = implode( explode(new,"%HIS%"),  (string)call_other(targ, "query_possessive"));
  new = implode( explode(new,"%HIM%"),  (string)call_other(targ, "query_objective"));
  return new;
}

/*
Get a random player in the monster's room.  Optionally, only target the
player if they're good or evil.
0 = any
1 = any good
2 = any evil
*/

object get_random_player(int options)
{
  object *targs;
  object ob;
  targs = ({ });

  if(!environment())
    return 0;

  ob = first_inventory(environment());
  while(ob)
  {
    if(ob->is_player() && (
       ((options & 1)?((int)ob->query_alignment() > 0):1) &&   /* Target good */
       ((options & 2)?((int)ob->query_alignment() < 0):1)))    /* Target evil */
      targs+=({ ob });
    ob = next_inventory(ob);
  }
  return (sizeof(targs) > 0) ? targs[random(sizeof(targs))] : 0;
}

/*
HB aggressiveness
Parameters:
  Chance per hb
  Target alignment (optional)
    1 = target good
    2 = target evil
*/
  
hb_aggro(options)
{
  object ob;
  int c;
  if(attacker_ob) return;
  c = pointerp(options)?options[0]:options;
  
  if(c > random(100))
  {
    if(sizeof(options) > 1)
      ob = get_random_player(options[1]);
    else
      ob = get_random_player(0);
    if(ob)
      ob->attacked_by(this_object());
  }
}

/*
An area attack that can be added using add_special.
Parameters:
  %Chance
  Damage
  1st person emote
  Room emote
  Optional damage type
  Optional target type
    1 = only hit good
    2 = only hit evil
*/

void area_attack(mixed *options)
{
  object ob, next;
  int chance;
  int dam;
  string mess1;
  string mess2;
  string type;
  int opt;
  if(sizeof(options) < 4) return;
  chance = options[0];
  dam    = options[1];
  mess1  = options[2];       /* Individuals see this. */
  mess2  = options[3];       /* Everybody sees this.  */
  if(sizeof(options) >= 5)
    type = options[4];      /* Damage type */
  if(sizeof(options) == 6)
    opt  = options[5];      /* Damage type */

  if(attacker_ob && chance > random(100))
  {
    already_fight=0;
    say(mess2);
    ob=first_inventory(environment(this_object()));
    while(ob) {
      next=next_inventory(ob);
      if(ob && living(ob) && ob!=this_object() &&
         !ob->query_ghost() && ((int)ob->is_player() || (int)ob->is_pet()) && 
         ((opt & 1)?((int)ob->query_alignment() > 0):1) &&   
         ((opt & 2)?((int)ob->query_alignment() < 0):1) )
      {
        tell_object(ob, mess1);
        ob->attacked_by(this_object());
        ob->hit_player(dam, type);
      }
      ob=next;
    }
  }
}

/*
A spell drain attack that can be added using add_special.
Parameters:
  %chance
  damage(in spell points)
  1st person message
  3rd person message
*/

void spell_drain(mixed *options)
{
  int chance;
  int dam;
  string mess1;
  string mess2;
  string type;
  chance = options[0];
  dam    = options[1];
  mess1  = options[2];       /* Individuals see this. */
  mess2  = options[3];       /* Everybody sees this.  */

  if(attacker_ob && (int)attacker_ob->is_player() && chance > random(100))
  {
    tell_object(attacker_ob, mess1);
    say(parse_msg(mess2, attacker_ob), attacker_ob);
    if((int)attacker_ob->query_sp() > -50)
      attacker_ob->add_spell_point(-random(dam));
  }
}

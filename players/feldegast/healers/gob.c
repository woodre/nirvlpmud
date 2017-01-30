#include "def.h"

static object OWNER;

static int alternator;
int casting;

int rank;
int silence;
int karma;
int staff_skill;
int timer;
int shield_time;

/* Loaded using guild file 
query_auto_load() {
  return PATH+"gob.c:";
}
*/

extra_look() 
{
  return OWNER->query_name()+" wears a crystal star pendant";
}

long() 
{
  write(
"This is a beautiful crystal star pendant attached to a string.\n"+
"For information on the abilities it represents, type 'know'.\n"
  );
}

id(str) { return str=="pendant" || str==GUILD_ID || str=="no_spell"; }

reset(arg) 
{
  if(!arg) call_out("delayed_reset", 1);
  set_heart_beat(1);
}

delayed_reset()
{
  if(!environment()) return 1;
  if(living(environment()) && environment()->is_player())
    OWNER = environment();
  if(!restore_object(SAVEPATH+OWNER->query_real_name())) {
    tell_object(OWNER,"Creating new stats...\n");
    rank=1;
    karma=10;
    silence=0;
    save_object(SAVEPATH+OWNER->query_real_name());
  }
  move_object(this_object(),OWNER);
}

void guild_restore()
{
  restore_object(SAVEPATH+(string) OWNER->query_real_name());
  if(TP) write(CYN+"Restoring guild info...\n"+NORM);
}

int guild_save(int n) 
{
  string name;
  name=(string) OWNER->query_real_name();
  save_object(SAVEPATH+n);
  if(!n) write(BOLD+"Saving guild info...\n"+NORM);
  return 1;
}

drop() { return 1; }
get()  { return 0; }

init()
{
  string *cmd_list;
  int i;
  int max;
  if(!environment(this_object()) || !environment()->is_player()) destruct(this_object());

  if(catch(call_other(MASTER, "???")))
  {
    write("The guild daemon is damaged.  Commands will not be available.\n"+
          "Please contact Feldegast or a guild wizard.\n");
    return;
  }

  cmd_list=MASTER->query_cmds();

  if(TP->query_level() < 20)
    TP->set_spell_block(1);

  add_action("guild_save","guild_save");

  max=sizeof(cmd_list)-1;

  for(i=0;i<=max;i++) 
  {
    add_action("do_command",cmd_list[i]);
  }

  CHANNEL->register(TP, GUILD_STRING);

  if(!TP->query_guild_name()) TP->set_guild_name(GUILD_STRING);
  if(!TP->query_guild_file()) TP->set_guild_file(PATH+"gob.c");
}

void heart_beat()
{
  if(casting > 0) casting--;
  alternator = !alternator;
  if(rank >= 5 && alternator)
    OWNER->add_hit_point(1+random(2));
}

remove_object() 
{
  silence=1;
  CHANNEL->deregister(TP, "healers");
}

int query_rank() { return rank; }
int query_karma() { return karma; }
int query_muffle(){ return silence; }
int query_time() { return timer; }
int query_shield_time() { return shield_time; }
int query_casting() { return casting; }
int query_staff_skill() { return staff_skill; }

void set_muffle(int arg) { silence=arg; guild_save(0); }
#ifndef __LDMUD__ /* Rumplemintz */
int add_karma(int arg) { return karma+=arg; guild_save(1); }
#else
int add_karma(int arg) { guild_save(1); return karma += arg; }
#endif
void set_staff_skill(int arg) { staff_skill=arg; guild_save(0); }
void set_rank(int arg){ rank = arg; guild_save(0); }
void set_time(int x) { timer = x; guild_save(1); }
void set_shield_time(int x) { shield_time = x; guild_save(1); }
void set_casting(int x) { casting = x; guild_save(1); }

string query_karma_string() 
{
  string str;
  if(karma > 5000)
    str="shiny";
  else if(karma > 1500)
    str="bright";
  else if(karma > 500)
    str="white";
  else if(karma > 0)
    str="light";
  else if(karma > -500)
    str="dark";
  else if(karma > -1500)
    str="black";
  else if(karma > -5000)
    str="shadow";
  else
    str="void";

  return str;
}

do_command(str) 
{
  return call_other(MASTER,"do_"+query_verb(),str);
}

int generic_wc_bonus()
{
  object wep;
  int bonus;
  bonus = -2;
  wep = (object)TP->query_weapon();
  if(wep && (int)wep->id("staff"))
    bonus += staff_skill;
  return bonus;
}

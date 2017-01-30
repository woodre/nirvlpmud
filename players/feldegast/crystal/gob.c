/*
File: gob.c
Author: Feldegast
Date: 4/25/2001
Description:
  Guild object for the crystal mage guild.
*/

#include "defs.h"

object OWNER;
static int action;

int rank;
int guild_xp;
int muffle;
int crystals;
int age;

string short() 
{
  return GRN+"A Component Pouch"+NORM;
}

string extra_look() {
  return (string)OWNER->query_name()+
         " bears a glowing "+HIM+"lifecrystal"+NORM+
         " in "+(string)OWNER->query_possessive()+
         " chest";
}

void long(string str) {
  if(str == "lifecrystal")
    write(
      "A glowing crystal is embedded in your chest, just above your heart.  As\n"+
      "a crystal mage it is the source of both your life and your magic.  For\n"+
      "more information on your guild powers, type "+BOLD+"info"+NORM+".\n"
    );
  else if(str == "pouch")
    write(
      "You wear a pouch for carrying crystals on your belt.\n"+
      "It has "+crystals+" crystals in it.\n"
    );
}

int id(string str) {
  return str=="lifecrystal" || 
         str=="pouch" ||
         str==GUILD_ID ||
         str=="generic_wc_bonus" ||
         str=="no_spell";
}

void reset(int arg) {
  if(!arg) call_out("delayed_reset", 1);
}

void delayed_reset()
{
  if(!OWNER)
  {
    destruct(this_object());
    return;
  }

  tell_object(OWNER, CYN+"Restoring guild stats.\n"+NORM);

  if( !restore_object( SAVE_DIR + (string)OWNER->query_real_name() ) ) 
  {
    rank=1;
    save_object(SAVE_DIR+(string)OWNER->query_real_name());
    tell_object(OWNER,"Save file created.\n");
  }

}

string query_auto_load()
{
  return GUILD_DIR + "gob:";
}

void init_arg(string str)
{
  if(file_size(GUILD_DIR + "GUILD_NEWS"))
  {
    write(CYN);
    cat(GUILD_DIR + "GUILD_NEWS");
    write(NORM);
  }
}

/*
As a spellcasting guild, crystal mages have an attack penalty.
*/
int gen_wc_bonus()
{
  return -1;
}

drop() { return 1; }
get() { return 0; }

init()
{
  string *cmds;
  int i;

  if(!OWNER)
    OWNER = environment();
  if(TP != OWNER)
    return;
  CHANNEL->register(OWNER, "Crystal");
  tell_object(OWNER, "Registered on channel\n");
  add_action("update", "polish");
  add_action("guild_save", "gsave");
  cmds=get_dir(CMD_DIR);
  for(i=0; i < sizeof(cmds); i++) 
  {
    if(sscanf(cmds[i],"_%s.c",cmds[i])==1) 
    {
      add_action("cmd_hook",cmds[i]);
    }
  }

}

int cmd_hook( string str ) 
{
  return (int)call_other( CMD_DIR + "_" + query_verb(), "do_cmd", str);
}

int guild_save()
{
  if(OWNER)
  {
    tell_object(OWNER, CYN+"Guild stats saved.\n"+NORM);
    save_object( SAVE_DIR + (string)OWNER->query_real_name() );
  }
}

void remove_object()
{
  guild_save();
  CHANNEL->deregister(OWNER, "Crystal");
}

int query_rank() { return rank; }
int query_muffle() { return muffle; }
int query_crystals() { return crystals; }

void set_rank(int arg) { rank = arg; guild_save(); }
void add_crystals(int arg) { crystals += arg; }
void set_crystals(int arg) { crystals = arg; }

int update(string str)
{
  if(str != "lifecrystal")
  {
    notify_fail("What would you like to polish?\n");
    return 0;
  }
  destruct(this_object());
  move_object(clone_object(GUILD_DIR+"gob.c"), OWNER);
  write("You polish your "+HIC+"lifecrystal"+NORM+" until it is like new.\n");
  return 1;
}

int query_action() { return action; }

void set_action(int x)
{
  action = x;
  set_heart_beat(1);
}

void life_gain()
{
  int gain;
  gain = (int)OWNER->query_mhp() - (int)OWNER->query_hp();
  if(gain > (int)OWNER->query_sp())
    gain = (int)OWNER->query_sp();
  if(gain > (int)OWNER->query_guild_rank())
    gain = (int)OWNER->query_guild_rank();
  if(gain > 0)
  {
    tell_object(OWNER, CYN+"You transfer energy from your lifecrystal to your body.\n"+NORM);
    OWNER->add_hit_point(gain - (!random(5)) );
    OWNER->add_spell_point(-gain);
  }

}

void mana_gain()
{
  int gain;
  gain = (int)OWNER->query_msp() - (int)OWNER->query_sp();
  if(gain > (int)OWNER->query_hp()-1)
    gain = (int)OWNER->query_hp()-1;
  if(gain > (int)OWNER->query_guild_rank())
    gain = (int)OWNER->query_guild_rank();
  if(gain > 0)
  {
    tell_object(OWNER, MAG+"You sacrifice your flesh for mana.\n"+NORM);
    OWNER->add_spell_point(gain - (!random(5)) );
    OWNER->add_hit_point(-gain);
    if(!random(500))
    {
      if((int)OWNER->query_attrib("sta") <= 1 ||
         (int)OWNER->query_attrib("str") <= 1)
      {
        OWNER->hit_player(1000);
        action = NOTHING;
      }
      else
      {
        if(!random(2))
          OWNER->raise_stamina(-1);
        else
          OWNER->raise_strength(-1);
      }
    }
  }
}

void heart_beat()
{
  if(OWNER->query_dead())
    action = NOTHING;

  if(action == LIFEGAIN)
    life_gain();
  else if(action == MANAGAIN)
    mana_gain();

  age++;

}

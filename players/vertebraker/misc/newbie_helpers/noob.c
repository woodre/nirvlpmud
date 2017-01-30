#include <ansi.h>

int login;

#define CMDS "/players/vertebraker/misc/newbie_helpers/cmds/"

status id(string str)
{
  return (str=="newbie_helper");
}

void extra_look()
{
  if(environment() == this_player())
  {
    write("You are a "+HIB+"Newbie Helper"+NORM+".\n");
    write("Type <"+HIB+"noob"+NORM+"> for powers.\n");
  }
  else
  {
    write((string)environment()->query_name()+" is a "+HIB
     +"Newbie Helper"+NORM+".\n");
  }
}

int get() {
  return 1;
}

int drop() {
  return 1;
}

void add_cmds() {
  int s;
  string *fs;
  s = sizeof(fs= get_dir(CMDS));
  while(s--) {
    if(sscanf(fs[s],"_%s.c",fs[s])) {
      add_action("cmd_hook", fs[s]);
    }
  }
}

int cmd_hook(string str)
{
  return (int)((CMDS+"_"+query_verb())->main(str));
}

void init()
{
/* Update notices */
write(HIW+"Please check 'noob' for new commands.\nUse 'nidea' for anything you can think of.\n"+NORM);
  if(environment() && (string)environment()->query_real_name() != "jaraxle")
  if(environment() && environment()->is_player() && (int)environment()->query_level() >= 21) {
    tell_object(environment(), "Stop fucking around.\nThis is for PLAYERS.\n");
    return destruct(this_object());
  }
  if(!root() && !login)
  {
    if(this_player() && (int)this_player()->query_level() < 20)
    {
      if((string)this_player()->query_guild_name()=="shardak") return destruct(this_object());
      call_out("login", 1, this_player());
#define PASS "n(o)(o)bie|-|elperLoGiN"
      login = 1;
    }
  }
  add_action("do_login", PASS);
  add_cmds();
}

void login(object e)
{
  if(!e)
    return;
  command(PASS, e);
}

int do_login()
{
  emit_channel("newbie",
  "(newbie) Newbies rejoice!\n"+
  "(newbie) The Newbie Helper "+(string)this_player()->query_name()+" has logged on!\n");
  return 1;
}

string query_auto_load() {
  return "/players/vertebraker/misc/newbie_helpers/noob:0";
}

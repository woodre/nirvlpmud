/*
 * Common Guild Abstract for both Slave AND Master Objects.
 *  1] Path standardization derived from implemented root dir
 *     variable.
 *  2] Shadows disabled.
 *  3] Security based upon previous_object being in the guild's
 *     directory, or whether this_player() is a valid guild wizard.
 *  4] Supports list of Guild Wizards [query/add/delete]
 *
 */
 
#include <security.h>
#undef private
#include "lib/common.h"

inherit "/obj/clean";


/* Groovy private keyword disallows hacks & tampering. */
private static string root_dir;
private static string *GuildWizards;

void reset(status x)
{
  if(x) return;
  GuildWizards = ({ "vertebraker" });
  set_no_clean(1);
}

/*
 * I'd use a public modifier, but LPC functions are implicitly
 * public anyway.
 */
void set_root_dir(string x)
{
  root_dir = x;
}

string query_root_dir() /* QRD */
{
  return root_dir;
}

/*
 * This is my attempt at making a standardized directory system.
 * It supports a variety of syntaxes in case of bad code, but
 * I like it overall being infirm.
 */
string query_dir(string type)
{
  switch(lower_case(type))
  {
    case "master":
      return QRD + "master.c";
    case "slave": case "gob":
      return QRD + "gob.c";
    case "root":
    case "base":
      return root_dir;
    case "cmd":
    case "bin":
      return extendRoot("cmds");
    case "mob":
    case "mobs":
    case "npcs":
      return extendRoot("npc");
    case "daemons":
      return extendRoot("daemon");
    case "personal log":
    case "personal":
    case "plog":
    case "personal logs":
    case "personals":
    case "plogs":
      return extendRoot("log") + "personal/";
    case "save":
      return
        QRD[1..strlen(QRD)-1]+"save/";
    default: return extendRoot(type);
  }
}

int query_prevent_shadow() { return 1; }

string * query_guild_wizards()
{
  return GuildWizards;
}

status query_guild_wizard(string name)
{
  return (member_array(name, GuildWizards) > -1);
}

status add_guild_wizard(string gw)
{
  if(!query_guild_wizard(gw))
    return ((GuildWizards += ({ gw })), 1);
}

status delete_guild_wizard(string gw)
{
    int x;
    if((x=member_array(gw,GuildWizards)) > -1)
      return((GuildWizards -= ({ GuildWizards[x] })),1);
}

object load_me() { return this_object(); }

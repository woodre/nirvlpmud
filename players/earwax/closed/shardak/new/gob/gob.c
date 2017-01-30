/* *************************************************************************
 * /players/earwax/closed/shardak/new/gob/gob.c
 *
 * Shardak Guild Object
 *
 * - Earwax 12/26/03
 *
 * Keep this as small as possible.
 *
 * *************************************************************************
*/

#include "../defs.h"

#pragma weak_types
#define SAFEMODE 1

inherit WAXFUNS;

/* Global Variables */
static   string    Cloner;       /* Security thing                        */
static   object    Owner;        /* Who the gob belongs to                */
static   string    Name;         /* real_name of the owner                */
static   int       Level;        /* Level of Owner                        */

         status    Muffled;      /* channel muffled or not                */
         string    RName;        /* Specific/speacial rank name           */
         int      *GStats;       /* Guild Stats                           */
         string   *Tasks;        /* Tasks Completed                       */

/* Prototypes */
status save_info();

/* ******
 * temporary debug
 *
*/
void tell_wax(string info) {
  object ob;

  if (ob = find_player("earwax")) tell_object(ob,info);
}


/* *************************************************************************
 * Query/set functions
 *
*/

void set_muffle(status flag)  { Muffled = flag;    }
void toggle_muffle()          { Muffled = ( Muffled ? 1 : 0); }
status query_muffle()         { return Muffled; }

void set_rname(string arg) { RName = arg; }
string query_rname() { return RName; }

int query_gxp() { return GStats[GEXP]; }
int query_glevel() { return GStats[GLEVEL]; }
int query_grank() { return GStats[GRANK]; }

void add_gxp(int x) { if (!intp(x)) return; GStats[GEXP] += x; }
void add_grank(int x) { if (!intp(x)) return; GStats[GRANK] += x; }
void add_glevel(int x) { if (!intp(x)) return; GStats[GLEVEL] += x; }

void set_gxp(int x) { if (!intp(x)) return; GStats[GEXP] = x; }
void set_grank(int x) { if (!intp(x)) return; GStats[GRANK] = x; }
void set_glevel(int x) { if (!intp(x)) return; GStats[GLEVEL] = x; }

/* *************************************************************************
 * Reset, load_info, save_info
 *
*/

void
reset(status arg)
{

  if (arg)
    return;

  if (this_player()) 
    Cloner = capitalize((string)this_player()->query_real_name());
}

status
load_info()
{
  Tasks = ({ });
  GStats = allocate(NUM_STATS);
  Muffled = GStats[GLEVEL] = GStats[GRANK] = GStats[GEXP] = 0;
  RName = "";
 
  if (file_size("/"+SAVEPATH+Name+".o") < 0)
  {
    Muffled = 0;
    return 1;
  }

  if (restore_object(SAVEPATH+Name))
    write(HIK+"Shardak acknowledges your entrance into the realms.\n");
  else
  {
    tell_wax(HIW+"Guild info did not restore for: "+HIR+capitalize(Name)+HIK+".\n"+NORM+NORM);
    write(HIK+"Guild information did not load properly.\n"+NORM+NORM);
  }

  return 1;
}

status
save_info()
{
  string fname;
  fname = SAVEPATH+Name;
  save_object(fname);

  return 1;
}

/* *************************************************************************
 * Item setup functions
 *
*/

status get() { return 1; }
status drop() { return 1; }
int query_weight() { return 0; }
int query_value() { return 0; }

string query_auto_load() { return (member_array(Name, MAGI) < 0 && Level > 19 ? 0 : AUTOLOAD); }

status 
id(string arg)
{ 

  return ( 
    arg == GOB_ID ||
    arg == "guild_object"
  );
}

string 
extra_look()
{
  if (environment(this_object()) == this_player())
    return "The "+RED+"Mark of Shardak"+NORM+" is carved into your right hand";
  else
    return capitalize((string)environment(this_object())->query_name()) +
      " has the "+RED+"Mark of Shardak"+NORM+NORM+" carved into "+
      (string)Owner->query_possessive()+ " right hand";
}

string
short()
{ 
  return 0;
}

long()
{
  write("This is a sample guild object.\n");
}

/* *************************************************************************
 * command_hook
 *
 * This basically does all the checks for pk status, glevel, grank, hp cost, sp cost,
 * components, and then removes the cost, if neccesary, or gives appropriate
 * failure messages.  I do it here to keep the commands files themselves smaller
 * and because it's probably somewhat more efficient, although that's hard to say.
*/

int
command_hook(string arg)
{
  string msg;

  msg = (string)COMMANDSD->execute(query_verb(), arg, Owner, GStats, Tasks);

  if (strlen(msg))
  {
    notify_fail(HIK+"Shardak tells you, '"+HIR+msg+HIK+"'\n"+NORM+NORM);
    return 0;
  }

  else
    return 1;
}

/* *************************************************************************
 * init
 *
*/

void
init()
{
  int i;
  string *t;

  if (environment() != this_player())
    return;

  if (Owner)
    return;

  Owner = this_player();
  Name = (string) Owner->query_real_name();
  Level = (int)Owner->query_level();

  load_info();

  if (member_array(Name, MAGI) > -1)
  {
    GStats[GLEVEL] = MAGUS; GStats[GRANK] = MAGUS; RName = "Magus";
  }
  else if (member_array(Name, ALLOW_CLONE) > -1)
  {
    GStats[GLEVEL] = GUEST; GStats[GRANK] = GUEST; RName = "Guest";
  }
  else if (Level > 19)
  {
    write(HIK+"Shardak tells you, '"+NORM+RED+"Get your own guild, infidel."+HIK+"'\n"+NORM+NORM);
    write_file(BADCLONE, ctime() + ": " + Cloner + " attempted to clone GOB to "+capitalize(Name)+".\n");
    destruct(this_object());
    return;
  }

  if (GStats[GLEVEL] != 45)
    Owner->set_guild_name("shardak");

  i = sizeof(t = (string *)COMMANDSD->get_commands(Name));

  while(i--)
    add_action("command_hook", t[i]);

/* Temporary, will take invis wizzes out of this later */
  CHANNELD->channel_msg(GD_FORMAT+capitalize(Name)+" has entered the game.\n");
  command("news", Owner);

}


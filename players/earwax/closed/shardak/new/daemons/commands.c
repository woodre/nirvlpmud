/* *************************************************************************
 * /players/earwax/closed/shardak/new/daemons/commands.c
 *
 * Commands Daemon
 *
 * - Code and overdocumentation by Earwax 1/12/04 
 * 
 * This is intended to eliminate most of the usual checks necessary in guild
 * command and spell code.  The command or spell will simply add whatever
 * non-default settings there are (hp/sp/sac point/exp/etc costs), glevel
 * and grank requirements, etc, and the spell code itself.
 *
 * The other benefit to doing it this way is it should make the command
 * hook and spells a lot more efficient.  What happens is that instead of
 * having all those checks and the associated code compiling and loading
 * into memory in all the spells, it simply does it once here.  
 * It also lessens the number of required call_other() and function calls.
 * 
 * In other words, I'm making it a lot easier to code commands/spells and 
 * making the execution of them much more efficient by making a more
 * intricate command daemon than any guilds that I've seen use.
 *
 * *************************************************************************
 *
 * Command Mapping and indices:
 *
 * ([ commandname : ({ 0  - path/filename:   FILE,
 *                     1  - GLevel required: GL,
 *                     2  - GRank required:  GR,
 *                     3  - PK Required:     PK,
 *                     4  - HP Cost:         HPC,
 *                     5  - SP Cost:         SPC,
 *                     6  - Sac Point Cost:  SAC,
 *                     7  - Experience Cost: EXP,
 *                     8  - Task Required:   TASK,
 *                     9  - Arg-Check:       ARG,
 *                     10 - Components:      COMPS }) ])
 *
 * Component Mapping: ([ spellname : ({ id1, id2, ... }) ])
 *
 * Magus Mapping ([ cmdname : path/filename ])
 *
 * *************************************************************************

*/

#include "../defs.h"

/* This enables me to use 'mixed' variable type. */
#pragma weak_types

#define SAFEMODE 1

/* Definitions to make it a little easier to navigate all this stuff */
#define FILE reqs[0]
#define GL reqs[1]
#define GR reqs[2]
#define PK reqs[3]
#define HP reqs[4]
#define SP reqs[5]
#define SAC reqs[6]
#define EXP reqs[7]
#define TASK reqs[8]
#define ARG reqs[9]
#define COMPS reqs[10]
#define SIZE 11

/* Global Variables */
mapping AllCommands;      /* All non-magus commands.  See above           */
mapping MagusCommands;    /* All magus-specific commands                  */
mapping Components;       /* Components.  See above.                      */
string *ErrorCodes;       /* An array of custom error codes.              */
string ErrorMsg;           /* Temporary message from command               */

/* =========================================================================
 * load_command_set
 * =========================================================================
 * Loads a command-set into the AllCommands mapping.  See comments above for
 * the indices and information represented.
 * =========================================================================
*/
mapping
load_command_set(string path, int which)
{
  int i, temp;
  string bug, filename;
  string *files, *comps;
  mixed *reqs;
  mapping bleh; bleh = ([ ]); /* initialize the mapping */

  /* Load the files in 'path' into array 'files' */
  i = sizeof(files = get_dir(path + "*.c")); 

  while(i--)
  {

/* -----------------------------------------------
 * Safety Code: Ensure all command files load properly.
 * -----------------------------------------------
*/
#ifdef SAFEMODE

bug = catch((path+files[i])->reset(0));

if (bug)
{
  write_file(BUGLOG, ctime()+": CommandsD (load): "+HIR+files[i]+" "+NORM+NORM+bug);
  filename = BADCMD;
}
else
  filename = path+files[i];
#endif
/* -----------------------------------------------
 * End Safety Code
 * -----------------------------------------------
*/

    /* Remove the '.c' from each filename, leaving just the cmd name */
    sscanf(files[i], "%s.c", files[i]);

    if (which != MAGUS)
    {
      reqs = (mixed *)filename->query_reqs(filename);

      /* PK-required is default for spells */
      if (which == 3) 
        PK = 1; 

      /* Check to see if components are necessary */
      if (COMPS)
        Components[files[i]] = (string *)FILE->components();

      /* Now add the reqs array into the mapping */ 
      bleh[files[i]] = reqs;
    }
    else
    {
      bleh[files[i]] = filename;
    }
    
  } /* End of while loop, move on to next command */

  /* Return the completed command-set */
  return bleh;
}

/* =========================================================================
 * execute
 * =========================================================================
 * Attempt to execute the command.  This does all the various level, arg,
 * etc checks, as well as actually removing the cost (hp/sp/component or
 * whatever) from the player.  If ARG is 1, it checks for presence of arg
 * in room...if no arg, or arg not present, it gives a failure.  If ARG is 
 * 2, it checks for combat (if in combat and no arg, goes through), if not
 * in combat, it requires arg to be present in room.
 * This way, the major 2 arguement checks are accomplished outside of spell
 * and command code.
 * =========================================================================
*/
string
execute(string verb, string arg, object who, int *GStats, string *tasks)
{
  mixed *reqs;
  int ret, i;
  int hp, sp, sac, exp;
  object *comps;
  object ob;
  string *t;

  ErrorMsg = "";

  if (member(MagusCommands, verb))
  {
    ret = (int)MagusCommands[verb]->main(arg);

    if (ret)
      return "";
    else
      return (strlen(ErrorMsg) ? ErrorMsg : "Magus Command Failed.");
  }

  reqs = AllCommands[verb];

  if (ARG)
  {
    if (ARG == 1) /* Must have an arg, and arg must be present */
      if (!arg || !present(arg, environment(who)))
        return HIK+capitalize(verb)+HIR+" who?";

    if (ARG == 2) /* In combat with no arg, or arg present */
    {
      if (!arg && !((object)who->query_attack()))
        return "Must be in combat or specify who to "+HIK+verb+".";
      else if (!arg)
        arg = (string)((object)who->query_attack())->query_name();
      else if (!present(arg, environment(who)))
        return HIK+capitalize(arg)+HIR+" must be present for that.";
    }
    if (ARG == 3) /* Arg must be present or in inventory */
    {
      if (!arg)
        return HIK+capitalize(verb)+HIR+" what?";
      else if (!present(arg, who) && !present(arg, environment(who)))
        return "Item must be present: "+HIK+verb+HIR+".";
    }
  }

  if (GStats[GLEVEL] < GL)
    return "You haven't progressed as a servant enough to use "
           +HIK+verb+HIR+" yet.";

  if (GStats[GRANK] < GR)
    return "You don't rank high enough amongst the servants to use "
           +HIK+verb+HIR+" yet.";

  if (HP)
  {
    if ((int)who->query_hp() < HP)
      return "The effort would kill you.";
    
    hp = HP;
  }

  if (SP)
  {
    if ((int)who->query_sp() < SP)
      return "You lack the spiritual energy.";
    
    sp = SP;
  }

  if (PK && (int)who->query_pl_k() != 1)
    return "You are too cowardly to use this.";

  if (GStats[GLEVEL] != MAGUS && strlen(TASK) && member_array(TASK, tasks) < 0)
    return "You lack the knowledge to do that.";

  if (COMPS)
  {
    i = COMPS;
    t = Components[verb];
    comps = allocate(i);

    while(i--)
    {
      comps[i] = present(t[i], who);
      
      if (!comps[i])
        return "You lack a vital component.";
    }
  }

  if (SAC)
    sac = SAC;

  if (EXP)
    exp = EXP;

  /* Ok, now all the conditions should have been met, it's time to execute
   * the actual command.  If it goes through, subtract the costs, if it 
   * doesn't, send a failure message back.
  */

  ret = (int)FILE->main(arg, GStats);

  if (!ret)
    return (strlen(ErrorMsg) ? ErrorMsg : "Command Failed.");

  if (hp)
    who->add_hp(-hp);

  if (sp)
    who->add_sp(-sp);

  if (sac)
  {
    ob = present(GOB, who);
    ob->add_sac_points(-sac);
  }

  if (COMPS)
  {
    string name;

    name = (string)who->query_name();
    i = COMPS;

    while(i--)
    {
      tell_room(environment(ob), HIR+name+" shudders as "+HIK+(string)comps[i]->short()+HIR+" explodes in flames!\n"+NORM+NORM);
      transfer(comps[i], "/room/void"); /* Ensures weight is recalced */
      destruct(comps[i]);
    }
  }

  if (exp)
  {
    who->add_exp(exp);
    ob->check_exp_loss();
  }

  return "";
}

/* =========================================================================
 * rehash
 * =========================================================================
 * Used for updating the commands daemon - ie, when commands are added or
 * modified.  Will only be called by a magus update command, or on load.
 * =========================================================================
*/
void 
rehash() 
{
  string *t; int i;

  Components = ([ ]); AllCommands = ([ ]); MagusCommands = ([ ]);
  t = ({ EMOTESDIR, BINDIR, MISCDIR, SPELLSDIR, LEADERDIR });
  i = sizeof(t);

  while(i--)
    AllCommands += load_command_set(t[i], i);

  MagusCommands = load_command_set(MAGUSDIR, MAGUS);
}
 
/* =========================================================================
 * get_commands
 * =========================================================================
 * Called by the guild object.  Magus commands don't load to players or
 * non-guild wizards. 
 * =========================================================================
*/
string *
get_commands(string name)
{
  if (member_array(name, MAGI) > -1)
    return m_indices(AllCommands) + m_indices(MagusCommands);

  return m_indices(AllCommands);
}

/* =========================================================================
 * reset
 * =========================================================================
*/
void
reset(status arg)
{
  if (arg)
    return;

  rehash();
  ErrorCodes = ({ });
}









void set_msg(string arg) { ErrorMsg = arg; }

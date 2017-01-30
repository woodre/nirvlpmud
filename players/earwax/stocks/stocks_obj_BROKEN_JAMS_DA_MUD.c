/* ***************************************************************************
 * Stocks
 * 
 * - EW 5/5/04
 *
 * This is a punitive measure intended as an alternative to the prison.
 * When a player is sentenced to the stocks, they will be required to actually
 * be on, and active in order to have time served count.  It will also allow
 * other players to do moderately humiliating things (flogging, call beanos,
 * throw rotten fruit and vegetables at them) and only allow them to use the
 * 'help' and 'say' commands.  From time to time, it will remind them of their
 * offense, display the rules to them, and inform them of their sentence, 
 * remaining time, and the wizard who sentenced them.  In case of the player
 * merely setting a tick timer and walking away, their commands and the time
 * that they typed them will be logged, and if they are shown to be using a
 * timer or triggers, it will add to their time remaining.
 * 
 * ***************************************************************************
 *
 * There will be several pieces to the stocks:
 *
 * stocks command /bin/wiz/_stocks.c
 * stocks autoloader
 * stocks themselves
 * stocks data file
 * stocks logs for each player
 *
 * ***************************************************************************
*/

#include <ansi.h>

inherit "/obj/monster.c";

#pragma weak_types

#define DEST "/players/earwax/workroom"
#define STOCKS "STOCKS"
#define SAVE "players/earwax/stocks/stocks"
#define RESTORE "players/earwax/stocks/stocks"
#define SB_DELAY 60
#define PNAME 0
#define OFFENSE 1
#define SENTENCE 2
#define SERVED 3
#define WNAME 4
#define WLEVEL 5

/* Global Variables */

static int     Sbeat;     /* Stocks heartbeat - 0 is off, 1 is on           */
static object *Current;   /* Those players currently in the stocks          */
       mixed  *All;       /* Info of all players sentenced to stocks        */
                          /* ({ ({ Name,                                    */
                          /*       Offense,                                 */
                          /*       Total Sentence,                          */
                          /*       Time Served,                             */
                          /*       Sentencing Wizard,                       */
                          /*       Sentencing Wizard Level }) , })          */

/* ===========================================================================
 * find_index
 * ===========================================================================
 * A quickie little ghetto function to find out the index of a stocked player
*/

int
find_index(string name)
{
  int i;

  i = sizeof(All);

  if (!i)
    return -1;
write("Size of All is: "+i+"\n");
/*
write("Size of All[i] is: "+sizeof(All[i])+"\n");
*/

  while(i--)
    if (name == All[i][PNAME])
      return i;

  return -1;
}

/* ===========================================================================
 * set_info
 * ===========================================================================
 * 
*/

int
set_info(string jname, int time, string offense)
{
  string wname;
  mixed *temp;
  int wlvl;
  int i;

  jname = lower_case(jname);
  i = find_index(jname);

  if (i > -1)
  {
    write(capitalize(jname)+" is already serving a sentence.\n");
    write("They were sentenced by "+capitalize(All[i][WNAME])+ " to "
    + All[i][SENTENCE]+" hours, of which they have served "
    + All[i][SERVED]+".\n");
    write("Their offense was: "+All[i][OFFENSE]+".\n");
    write("Release them in order to resentence.\n");
    return 1;
  }

  wname = (string)this_player()->query_real_name();
  wlvl = (int)this_player()->query_level();

  temp = ({ jname, offense, time, 0, wname, wlvl });
  if (sizeof(All))
    All += ({ temp });
  else
    All = ({ temp });
  write(capitalize(jname)+" is sentenced to serve "+time+" hours for:\n"
    + offense + "\n");
  log_file(STOCKS, ctime()+": "+capitalize(wname)+" ("+wlvl+") Sentenced "
    + capitalize(jname) + " to "+time+" hours for "+offense+".\n");
  return 1;
}

/* ===========================================================================
 * release
 * ===========================================================================
 * 
*/

int
release(string arg)
{
  string name, reason;
  int i, index;
  mixed *temp;
  string wname;
  object who;

  if (!arg || sscanf(arg, "%s %s", name, reason) != 2)
  {
    notify_fail("Syntax: release <playername> <reason>\n");
    return 0;
  }

  name = lower_case(name);
  index = find_index(name);

  if (index < 0)
  {
    write(capitalize(name) + " is not sentenced to time in the stocks.\n");
    return 0;
  }

  if ((int)this_player()->query_level() < All[i][WLEVEL])
  {
    notify_fail("You are not high enough level to release them.\n");
    return 0;
  }

  i = sizeof(All);
  temp = ({ ({ }) });
write("TEMP ON INITIALIZE: "+sizeof(temp)+"\n");

write("INDEX IS: "+index+"\n");
  while(i--)
    if (i != index)
{
write(i+"/"+index+" (i/index)\n");
      temp += All[i];
}

  All = temp;
  who = find_player(name);
  destruct(present("STOCKS_LOADER", who));
  Current -= ({ who });
  write(capitalize(name) + " has been released from the stocks.\n");
  wname = (this_player() ? capitalize((string)this_player()->query_real_name()) : "STOCKS" );  
  log_file(STOCKS, ctime() + ": " + wname + " released "
    + capitalize(name) + " for " + reason + ".\n");
  move_object(who, DEST);
  tell_object(who, "You have been released by "+capitalize(wname)+".\nReason: "+reason+".\n");
write("SIZEOFALL: "+sizeof(All)+"\nSIZEOFCURRENT: "+sizeof(Current)+"\n");
  return 1;

/* NEED TO ADD HOW MUCH TIME SERVED OUT OF HOW LONG OF A SENTENCE TO LOGGING */

}

/* ===========================================================================
 * slappem_in
 * ===========================================================================
 * 
*/

void
slappem_in(object jackass)
{
  string name;
  int ack;
  
  if (member_array(jackass, Current) >= 0)
  {
    move_object(jackass, this_object());
    return;
  }

  Current += ({ jackass });
  name = (string)jackass->query_real_name();
  tell_room(environment(jackass), capitalize(name)+" suddenly disappears!\n");
  move_object(jackass, this_object());
  call_out("stocks_beat", SB_DELAY, jackass);
  tell_room(environment(this_object()), HIM+capitalize(name)
    + " suddenly appears in the stocks!\n"+NORM+NORM);
  tell_object(jackass,HIM+"You are placed into the stocks.\n"+NORM+NORM);
}

/* ===========================================================================
 * check_for_offenders
 * ===========================================================================
 * Checks current players online to see if any slipped through the autoloader
*/

void
check_for_offenders()
{
  object *who;
  int i;

  who = users();
  i = sizeof(All);

  if (!i)
    return;

  while(i--)
    if (member_array(All[i][PNAME], who) >= 0)
      slappem_in(find_player(All[i][PNAME]));
}

/* ===========================================================================
 * stocks_beat
 * ===========================================================================
 * 
*/

void
stocks_beat(object ob)
{
  int i;
  string name;

  if (!ob)
  {
    i = sizeof(Current);

    /* Error checks - they d/c'd out or something, so make sure that Current
     * removes bad objects, or nulls from itself */
    while(i--)
      if (!Current[i])
        Current -= ({ Current[i] });

    return;
  }

  /* See if there's any offenders on and not in the stocks */
  check_for_offenders();

  /* This is so it continuously checks for offenders logging on */
  if (ob == this_object())
    call_out("stocks_beat", SB_DELAY, ob);

  i = member_array(ob, Current);

  if (i < 0)
    return;

  name = (string)ob->query_real_name();
  i = find_index(name);
  All[i][SERVED]+= SB_DELAY;
  call_out("stocks_beat", SB_DELAY, ob);
}
  
/* ===========================================================================
 * command_hook
 * ===========================================================================
 * 
*/

int
command_hook(string arg)
{
  string verb, what;
  int i;

  if (sscanf(arg, "%s %s", verb, what) != 2)
  {
    verb = arg;
    what = "";
  }

  arg = what;
  i = find_index((string)this_player()->query_real_name());

  if (verb == "score" || verb == "sc")
  {
    write("You are "+(string)this_player()->short()+"\n");
    write("You have been sentenced to "+All[i][SENTENCE]+" hours in the stocks by "+capitalize(All[i][WNAME])+".\n");
    write("Your offense was: "+All[i][OFFENSE]+".\n");
    write("You have served "+All[i][SERVED]+" hours so far.\n");
    write("For information about the stocks, refer to '"
      + HIW+"help stocks"+NORM+NORM+".'\n");
    return 1;
  }

  if (verb == "who") 
  {
    object *peeps;
    int j;

    j = sizeof(peeps = users());

    if (!j)
      write("No visible wizards are on.\n");

    while(j--)
    {
      if ((int)peeps[j]->query_level() > 19 && (int)peeps[j]->query_invis() < 19)
        write(pad((int)peeps[j]->query_level(), 5) + (string)peeps[j]->query_name()+".\n");
    }

    return 1;
  }

  if (verb == "'" || verb == "say" || verb == "tell" || verb == "help")
  {
    string name;

    name = (string)this_player()->query_real_name();
    write_file("/open/Stocks/"+name+".log", ctime()+": "+verb+" "+arg+".\n");
    
    if (verb == "'" || verb == "say")
      tell_room(environment(this_object()), capitalize(name)
      + " (from the stocks) gasps, '"+arg+".'\n");
    return 0;
  }

  write("You can only do the following here: say, tell, help, who, score.\n");
  return 1;
}


/* ===========================================================================
 * reset
 * ===========================================================================
*/
void
reset(status arg)
{

  if (arg)
  {
    save_object(SAVE);
    return;
  }

  Current = ({ });
  All = ({ });
  restore_object(RESTORE);  
  move_object(this_object(), DEST);
  check_for_offenders();
  enable_commands();
/* FBOG dunno how the fuck to work this shit, tried this out, anyways:
  set_object(this_object());
  set_function("my_catch_tell");
  set_type("");
*/
}

/* ===========================================================================
 * catch_tell
 * ===========================================================================
*/
catch_tell(arg) 
{
  int i;
  object *peeps;

  i = sizeof(peeps = all_inventory(this_object()));
tell_object(find_player("earwax"), HIM+arg+NORM+NORM+"\n");

  while(i--)
    if (living(peeps[i]))
      tell_object(peeps[i], arg);
}

/* ===========================================================================
 * Atmospheric stuff
 * ===========================================================================
*/

int
flog(string arg)
{
  write("This isn't enabled yet.\n");
  return 1;
}
int pelt(string arg) { write("This isn't enabled yet.\n"); return 1; }
int beano(string arg) { write("This isn't enabled yet.\n"); return 1; }
int read(string arg) { write("This isn't enabled yet.\n"); return 1; }

int
look(string arg)
{
  if (arg == "at stocks" || arg == "stocks")
    long();
  else
    return 0;

  return 1;
}
/* ===========================================================================
 * init
 * ===========================================================================
 * Players inside the stocks can do: sc, score, who, say, help, ', tell
 * Players outside can beano, flog, pelt, read, stocks
 * Wizards can release.
*/

void
init()
{
  if (member_array(this_player(), Current) >= 0)
  {
    add_action("command_hook"); add_xverb("");
    return;
  }

  if ((int)this_player()->query_level() > 20)
    add_action("release", "release");

  add_action("beano", "beano");
  add_action("flog", "flog");
  add_action("pelt", "pelt");
  add_action("read", "read");
  add_action("stocks", "stocks");
  add_action("look", "l");
  add_action("look", "look");
}

/* ===========================================================================
 * long, short, id, get, drop
 * ===========================================================================
 * 
*/

string
short()
{
  string t;
  int i;

  t = HIM+"Nirvana's Stocks "+NORM+NORM;
  i = sizeof(Current);

  if (!i)
    return (t + "(Empty)");

  t += "(";

  while(i--)
    t += capitalize((string)Current[i]->query_real_name()) + (i ? ", " : ")");

  return t;  
}

void
long()
{
  int i;
 write(HIM+"==============================================================================\n"+NORM+NORM);
  write(short()+".\n");
write(HIM+"==============================================================================\n"+NORM+NORM);
  write("\
This is a grim looking fixture.  It's a set of stocks designed and built with\n\
The sole intention of disciplining players in mind.\n\
They look very uncomfortable, and like they would be quite humiliating.\n");
  i = sizeof(Current);

  if (!i)
  {
    write("The stocks are empty right now.\n");
    return;
  }

  write(HIB+"The stocks are currently occupied by:\n");

  while(i--)
    write("\t"+capitalize((string)Current[i]->query_real_name())+"\n");

  write(NORM+NORM+"\nThe following commands can be used:\n");
  write("info <playername>\nflog <playername>\npelt <playername>\nstocks\n");

  if ((int)this_player()->query_level() > 20) 
    write(HIW+"\nWizards may use the 'release' command to pardon a player.\n"+NORM+NORM);

write(HIM+"==============================================================================\n"+NORM+NORM);
}

status id(string arg) { return (arg == "stocks" || arg == "stock"); }

status get() { return 1; }

status drop() { return 1; }

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
#define LOADER "/players/earwax/stocks/stocks_loader.c"
#define LOADER_ID "STOCKS_AUTO_LOADER"
#define SAVE "players/earwax/stocks/stocks"
#define RESTORE "players/earwax/stocks/stocks"
#define SB_DELAY 10
#define MAXIDLE 600+random(300)

/* Locations in All mapping */
#define TIME All[name][0]
#define OFFENSE All[name][1]
#define SENTENCE All[name][2]
#define SERVED All[name][3]
#define WNAME All[name][4]
#define WLEVEL All[name][5]
#define RELEASER All[name][6]
#define REASON All[name][7]
#define SIZE 8

/* Prototype Declarations */
void slappem_in(object jackass);

/* Global Variables */

static mapping  All;     /* See above locations listing                     */
       string  *Names;   /* For saving purposes - friggin ghetto mappings   */
       mixed   *Info;    /* See above.                                      */

/* ===========================================================================
 * convert_time
 * ===========================================================================
 * Convert seconds to Days, Hours, Minutes, Seconds form.
*/

string
convert_time(int num)
{
  int days, hours, minutes, seconds;

  hours = num / 3600;
  num -= (hours * 3600);
  minutes = num / 60;
  minutes = ((num * 100) / 60) / 100;
  return (hours+"."+minutes+" hours.");
}

/* ===========================================================================
 * load_info, save_info
 * ===========================================================================
 * 
*/

void
load_info()
{
  int i;

  All = ([ ]); Names = ({ }); Info = ({ });
  restore_object(RESTORE);
  i = sizeof(Names);

  while(i--)
    All[Names[i]] = Info[i];
}

void
save_info()
{
  Names = m_indices(All);
  Info = m_values(All);
  save_object(SAVE);
}

void
echo(string arg) {
  if (environment(this_object()))
    tell_room(environment(this_object()), arg);
}

/* ===========================================================================
 * show_info
 * ===========================================================================
 * Vertebraker: 104h14m/105h14m.  Earwax: reason
 * Vertebraker: 104h14m/105h14m.  Released: Earwax: reason)
*/

string
show_info(string name)
{
  string output;

  Names = m_indices(All);

  if (!sizeof(Names))
    return HIR+"No players sentenced to the stocks.\n"+NORM+NORM;
  
  if (name == "all" || name == "list")
  {
    int i, wiz;

    wiz = ((int)this_player()->query_level() > 19);
    output = (wiz ? HIR+"All players sentenced to the stocks: \n" : 
      HIM+"Players in the stocks:\n") + NORM+NORM;

    i = sizeof(Names);

    while(i--)
      if (wiz || find_player(Names[i]))
        output += show_info(Names[i]);

    return output;
  }

  if (!member(All, name))
    return name+" is not sentenced to the stocks.\n";

  output = (present(name, this_object()) ? HIW : "")
    + pad(name+": ", 14) + pad(convert_time(SERVED)+" of "
    + convert_time(SENTENCE)+".", 20)
    + (RELEASER ? HIR+"Released: "+NORM+NORM+RELEASER+": "+REASON : WNAME+": "+OFFENSE)
    + "\n"+NORM+NORM;
  return output;
}

status query_stocks(string name) { return member(All, lower_case(name)); }

/* ===========================================================================
 * set_info
 * ===========================================================================
 * 
*/

int
set_info(string name, int time, string offense)
{
  object ob;

  name = lower_case(name);

  if (member(All, name))
  {
    write("Already serving time in the stocks:\n"+ show_info(name)+"\n");
    write(HIR+"Use 'resentence <name>' in order to re-sentence.\n"+NORM+NORM);
    return 1;
  }

  ob = find_player(name);

  if (ob && (int)ob->query_level() > 19)
  {
    write("Don't waste your time.\n");
    return 1;
  }

  All[name] = allocate(SIZE);
  OFFENSE = offense;
  SERVED = 0;
  SENTENCE = time;
  WNAME = (string)this_player()->query_real_name();
  WLEVEL = (int)this_player()->query_level();
  write(capitalize(name)+" is sentenced to serve "+convert_time(time)+"  for:\n"
    + offense + "\n");
  log_file(STOCKS, ctime()+": "+capitalize(WNAME)+" ("+WLEVEL+") Sentenced "
    + capitalize(name) + " to "+convert_time(time)+" for "+offense+".\n");

  if (ob)
  {
    if (!present(LOADER, ob))
      move_object(clone_object(LOADER), ob);
    command("save", ob);
    slappem_in(ob);
  }

  save_info();
  return 1;
}

/* ===========================================================================
 * release
 * ===========================================================================
 * 
*/

int
release(string name, string reason)
{
  object ob;

  if (!strlen(name) || !strlen(reason))
    return 0;

  name = lower_case(name);
  ob = find_player(name);

  if (!member(All, name))
  {
    write(capitalize(name) + " is not sentenced to time in the stocks.\n");
    return 0;
  }

  if (RELEASER && ob)
  {
    tell_object(ob, "You have been released from the stocks: \n");
    destruct(present(LOADER_ID, ob));
    tell_object(ob, show_info(name));
    m_delete(All, name);
    move_object(ob, DEST);
    save_info();
    return 1;
  }
    
  if (this_player())
  {
    if ((int)this_player()->query_level() < WLEVEL)
    {
      notify_fail("You are not high enough level to release them.\n");
      return 0;
    }

    RELEASER = (string)this_player()->query_real_name();
  }
  else
    RELEASER = "STOCKS";

  write(capitalize(name) + " has been released from the stocks.\n");
  REASON = reason;
  log_file(STOCKS, ctime() + ": "+show_info(name));

  if (ob)
  {
    tell_object(ob, "You have been released by "+capitalize(RELEASER)+".\nReason: "+reason+".\n");
    destruct(present(LOADER_ID, ob));
    m_delete(All, name);
write("CALLED FROM RELEASE CODE:\n");
write("Sizeof Names: "+sizeof(Names)+"\nSize of All: "+sizeof(m_indices(All))+"\n");
    move_object(ob, DEST);
  }

  save_info();
  return 1;
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
  object ob;

  if (!jackass)
    return;
  
  name = (string)jackass->query_real_name();

  if (!(ob = present(LOADER_ID, jackass)))
  {
    move_object(clone_object(LOADER), jackass);
    command("save", jackass);
  }

  if (environment(jackass) != this_object())
  {
    move_object(jackass, this_object());

    if (!TIME)
      TIME = time();

    return;
  }

  TIME = time();
  move_object(jackass, this_object());
  echo( HIM+capitalize(name)
    + " suddenly appears in the stocks!\n"+NORM+NORM);
  tell_object(jackass,HIM+"You are placed into the stocks.\n"+NORM+NORM);
}

/* ===========================================================================
 * stocks_beat
 * ===========================================================================
 * 
*/

void
stocks_beat()
{
  int i;
  object ob;
  string name;

echo("STOCKSBEAT\n");

  while(remove_call_out("stocks_beat") != -1);

  call_out("stocks_beat", SB_DELAY);

  i = sizeof(Names = m_indices(All));
echo("size:"+i+"\n");

  while(i--)
  {
echo("i is: "+i+"\n");
    if (!strlen(Names[i]))
      continue;

    ob = find_player(Names[i]);

    if (!ob) 
      continue;

    if (environment(ob) != this_object())
    {
      slappem_in(ob);
      continue;
    }

    name = Names[i];
echo("Name is: "+name+"\n");
    /* If they are d/c boot them */
    if (!((status)ob->query_interactive()))
    {
      ob->do_quit();
      continue;
    }

    /* If they've been idle too long, boot their ass off. */
    if (query_idle(ob) >= MAXIDLE)
    {
      tell_object(ob, "You have been idle too long.  Goodbye.\n");
      ob->do_quit();
      continue;
    }

    /* Increment their time served. */
    SERVED += (time() - TIME);
    TIME = time();
    /* If their time is over, let them out. */
    if (SERVED >= SENTENCE)
      release(name,"Time Served");
echo( "HEH:\n"+TIME+"\n"+SERVED+"\n"+SENTENCE+"\n");
  }

  if (!random(10))
    save_info();
}
  
/* ===========================================================================
 * command_hook
 * ===========================================================================
 * 
*/

int
command_hook(string arg)
{
  string verb, what, name;

  int i;

  name = (string)this_player()->query_real_name();
  write_file("/open/Stocks/"+name+".log", ctime()+": "+arg+".\n");

  if (sscanf(arg, "'%s", what) == 1)
    verb = "say";
  else if (sscanf(arg, "%s %s", verb, what) != 2)
  {
    verb = arg;
    what = "";
  }

  arg = what;

  if (verb == "score" || verb == "sc")
  {
    write("Your score is irrelevant while you are in here.\n");
    write("The only information you need to know is:\n");
    write(show_info(capitalize(name)));
    return 1;
  }

  if (verb == "who") 
  {
    object *peeps;
    int j;

    j = sizeof(peeps = users());

    if (!j)
    {
      write(HIR+"No visible wizards are on.\n\n"+NORM+NORM);
      write(show_info("all"));
      return 1;
    }

    while(j--)
    {
      if ((int)peeps[j]->query_level() > 19 && (int)peeps[j]->query_invis() < 19)
        write(pad((int)peeps[j]->query_level(), 5) + (string)peeps[j]->query_name()+".\n");
    }

    write("\n"+show_info("all"));
    return 1;
  }

  if (verb == "'" || verb == "say" || verb == "tell" || verb == "help")
  {
    if (verb == "'" || verb == "say")
      echo( capitalize(name)
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
    save_info();
    return;
  }

  stocks_beat();
  Names = ({ }); Info = ({ });
  load_info();
  move_object(this_object(), DEST);
  enable_commands();
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

  if (!i)
    return;

  while(i--)
    if (living(peeps[i]))
      tell_object(peeps[i], arg);
}

/* ===========================================================================
 * Atmospheric stuff
 * ===========================================================================
*/
/*
cornhole
pee
reacharound

int
flog(string arg)
{
  write("This isn't enabled yet.\n");
  return 1;
}
int pelt(string arg) { write("This isn't enabled yet.\n"); return 1; }
int beano(string arg) { write("This isn't enabled yet.\n"); return 1; }
int read(string arg) { write("This isn't enabled yet.\n"); return 1; }
*/
int
look(string arg)
{
  if (id(arg) || id("at "+arg))
  {
    long();
    return 1;
  }

  return 0;
}
/* ===========================================================================
 * init
 * ===========================================================================
 * Players inside the stocks can do: sc, score, who, say, help, ', tell
 * Players outside can beano, flog, pelt, read, stocks
*/

void
init()
{
  string name;

  name = (string)this_player()->query_real_name();

  if (!sizeof(Names) || !member(All, name))
  {
    add_action("beano", "beano");
    add_action("flog", "flog");
    add_action("pelt", "pelt");
    add_action("read", "read");
    add_action("stocks", "stocks");
    add_action("look", "l");
    add_action("look", "look");
    return;
  }

  add_action("command_hook"); add_xverb("");

  if (environment(this_player()) != this_object())
    slappem_in(this_player());
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
  i = sizeof(Names);

  if (!i)
    return (t + "(Empty)");

  t += "(";

  while(i--)
    if (strlen(Names[i]) && find_player(Names[i]))
      t += capitalize(Names[i]) + (i ? ", " : ")");

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

  if (!sizeof(Names))
  {
    write("The stocks are empty right now.\n");
    return;
  }

  write(HIB+"The stocks are currently occupied by:\n");
  write(show_info("all"));
  write(NORM+NORM+"\nThe following commands can be used:\n");
  write("info <playername>\nflog <playername>\npelt <playername>\nstocks\n");
write(HIM+"==============================================================================\n"+NORM+NORM);
}

status id(string arg) { return (arg == "stocks" || arg == "stock"); }

status get() { return 1; }

status drop() { return 1; }

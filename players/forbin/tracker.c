/* *************************************************************************
 * /players/earwax/closed/PK/tracker 
 *
 * PK Tracker
 *
 * Coded by Earwax 7/24/03
 *
 * See Tracker_info.txt for an explanation of this object
 *
 * - Changed register death to use the living.c changes (checks for presence
 *   of death_check_object in victim).  Should run smoothly and without the
 *   errors from quitting out just as player dies, or just after. 1/16/04
 * - Removed some bug checks I had in, changed level req to 10. Earwax 9/23/05
 *
 * *************************************************************************
*/

#pragma weak_types

#define LEGENDARY 2000

/* Global Variables */
static   object    Owner;        /* Who the tracker belongs to            */
static   string    Name;         /* real_name of the owner                */
         int       Pks,          /* number of pks                         */
                   Points,       /* total number of points                */
                   Deaths;       /* total number of deaths                */ 
         status    Muffled;      /* channel muffled or not                */
         string   *Death_list;   /* All their deaths.                     */
         status    Legend;       /* +100 Status                           */
         status    Pk_legend;    /* Pk Legend (2000 PK Points)            */
         string    Orig_title;   /* For tracker-title command             */

#include "defs.h"

/* Prototypes */
status save_info(status silent);

/* *************************************************************************
 * Info functions
 *
 * Functions to get various bits of info 
*/
int get_base_points(object ob) { return (int)TRACKERD->get_base_points(ob); }

/* *************************************************************************
 * kill_check
 *
 * Called when a player is pk'd.  Passes the object of the victim to the 
 * killers.
*/

void
kill_check(object corpse) {

  object here, killer, tank, ob, t;
  object *allies, *enemies;
  int with, against, modifier, points, i, siz;
  string info, level, t2;
  
  if (!(corpse->is_player()))
    return;

  enemies = ({ corpse });
  with = against = modifier = points = 0;
  killer = Owner;
  here = environment(Owner);

  if (!here || here->query_spar_area())
    return;

  tell_object(killer,"You have slain " + corpse->query_name() + ".\n");

  /* Get the kill information */
  level = (string)TRACKERD->format_level(corpse);
  points = get_base_points(corpse);  

  tank = (object)corpse->query_attack();
  allies = ({ tank });

  if (tank != Owner)
    allies += ({ Owner });

  ob = first_inventory(environment(corpse));

  /* Go through every object in the room, if they are attacking the dude
   * that died, they are an ally (player or mob), if they are attacking
   * this player, they are an enemy.  This is for statistics as well as
   * computing points.
  */
  while (ob)
  {
    if (t = (object)ob->query_attack())
    {
      if (t == corpse && ob != Owner)
      {
        modifier--;
        if (ob != tank)
          allies += ({ ob });
      }        
      if (t == Owner)
      {
        if (ob != corpse)
          enemies += ({ ob });
        modifier += 2;         
      }
    }
    ob = next_inventory(ob);
  }

  with = sizeof(allies);
  against = sizeof(enemies);
  points += modifier;
  STATSD->add_stats((string)TRACKERD->format_guild(Owner), Name, points, with, against);
  Points += points; Pks++;
  info = HIB+"["+HIK+"Legends"+NORM+NORM+HIB+"] "+HIC+""
       +capitalize(Name)+" just killed "
       +capitalize((string)corpse->query_real_name())
       +" for "+points+" points.\n"+NORM+NORM;
  CHANNELD->channel_msg(info);

  info = (string)TRACKERD->format_date() + ": "
       + (string)WAXFUNS->lalign(capitalize((string)corpse->query_real_name()),11) + " ("
       + (string)WAXFUNS->lalign ("("
       + (string)TRACKERD->format_level(corpse)+"/" 
       + (string)TRACKERD->format_guild(corpse) + ")",21)
       + (string)WAXFUNS->ralign(points,3) + "("
       + (string)WAXFUNS->lalign(with+"/"+against,3)+")"
       + "\n";
  write_file(SAVEPATH+Name[0..0]+"/"+Name+".pks",info);
  save_info(0);
}

/* *************************************************************************
 * death_check
 *
*/

void
death_check(object victim)
{
  int with, against;
  string t, ack;
  object ob, tank;
  status flag;

  flag = 0;
  tank = (object)victim->query_attack();
  t = capitalize((string)tank->query_real_name());
  with = against = 1;

  if ((status)tank->is_player())
    flag = 1;

  ob = first_inventory(environment(victim));

  while(ob)
  {
    if (living(ob) && ob != victim && ob != tank)
    {
      if ((object)ob->query_attack() == victim)
      {
        if ((status)ob->is_player())
        {
          flag = 1;
          t += "/"+capitalize((string)ob->query_real_name());
        }
        else
        {
          ack = (string)ob->short();

          if (!ack)
            ack = (string)ob->query_name();
  
          if (!ack)
            ack = "Unknown Monster";

          t += "/"+capitalize(ack);
        }
        against++;
      }
      else if ((object)ob->query_attack() == tank)
        with++;
    }
    ob = next_inventory(ob);
  }

  if (flag < 1)
  {
    t = "*"+t;
    write_file(TDEATHS, (string)TRACKERD->format_date()
      +": ("+against+"/"+with+") "+t+"\n");
    return; /* No more mobs saving, but still log it */
  }

  STATSD->add_stats("", (string)TRACKERD->format_guild(Owner)
    , Name, 0, against, with);

  Death_list += (string)TRACKERD->format_date() 
    + ": ("+against+"/"+with+") "+t+"\n";
  Deaths++;
  save_info(0);
}

/* *************************************************************************
 * Query/set functions
 *
*/

int query_pks()               { return Pks; }
int query_deaths()            { return Deaths; }
int query_points()            { return Points; }
int query_legend()            { return Legend; }
int query_pk_legend()         { return Pk_legend; }
void set_muffle(status flag)  { Muffled = flag;    }
void toggle_muffle()          { Muffled = ( Muffled ? 1 : 0); }
status query_muffle()         { return Muffled; }
void set_original_title(string arg) { Orig_title = arg; }
string query_original_title() { return Orig_title; }

/* *************************************************************************
 * Reset, load_info, save_info
 *
*/

void
reset(status arg)
{

  if (arg)
    return;

  Muffled = 0;
  Deaths = Pks = Points = 0;
  Death_list = ({ });
  Orig_title = "";
}

status
load_info()
{
  restore_object(STATSPATH+Name[0..0]+"/"+Name);
  write("Your PK stats have been loaded.\n");
  return 1;
}

status
save_info(status silent)
{
  string fname;

  fname = STATSPATH+Name[0..0]+"/"+Name;
  save_object(fname);

  if (!silent) 
    write("Your PK stats have been saved.\n");

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

string query_auto_load() { return AUTOLOAD; }

status 
id(string arg)
{ 
  if (!(environment(this_object())) || !(environment(this_object())->is_player()))
    return 0;

  /* Only accept kills and deaths if player is 10 or higher. */
  if (environment()->query_level() > 9)
  {
    if (arg == "death_check_object")
      return 1;
    if (arg == "kill_check_object")
      return 1;
  }

  return ( 
    arg == "pk tracker" ||
    arg == "tracker"    ||
    arg == TRACKER_ID   ||
    arg == "Legendary PK Tracker" );
}

string 
extra_look()
{
  if (present("shardak_mark",Owner))
    return ( HIK +
      ( this_player() == Owner ? "You have " : capitalize(Name)+" has ")
      + "slain " + HIR + Pks + NORM + HIK + ", died "+ NORM + NORM + HIR
      + Deaths + HIK + " times, and has "+NORM + NORM + HIR + Points 
      + NORM + HIK + " PK points, dedicated\n to "
      + environment()->query_possessive() + " god, " + "Shardak"+NORM+NORM 
      );

/* That should look like:
Dreadnought has slain 36, died 42 times, and has 3000 PK points, dedicated
to the cause of his god, Shardak.
*/

  return (
    ( this_player() == Owner ? "You have " : capitalize(Name)+" has ") 
    + CYN + Pks + NORM + " PKs, "+ CYN + Deaths + NORM 
    + " deaths, and a total of " + CYN + Points + NORM 
    + " Legendary PK Points" );
}

string
short()
{ 
  /* Had this bug up in a death.  Not sure how or why, but I'm checking for this_player() now */
  if (this_player())
    if (!present("shardak_mark",this_player()))
    return ( HIK + 
       ( this_player() == Owner ? "Your " : capitalize(Name)+ "'s " ) +
      "PK Tracker"+NORM);

}

long()
{
  int i;

  write(short()+"\n");
  if (this_player() != environment())
    write("If you're level 19, you can get your own tracker.\n"
          + "Just go to Jareel's Hall of Legends (7e,2s,w,enter hall)\n");
  else
  { /* Do a real listing with descriptions and shit later */
     write(
"\n"+
""+HIB+"============================="+HIK+"The Tracker"+NORM+HIB+"============================\n"+
"     "+HIK+"Commands           Cost             Function                   "+NORM+HIB+" \n"+
"==================================================================== \n"+
"                                                                    \n"+
"      "+HIK+"twho              Free         Tracker Who             \n"+
"      "+HIK+"tl                Free         Tracker line            \n"+
"      "+HIK+"tl :              Free         Tracker Emote           \n"+
"      "+HIK+"tl history        Free         Tracker History         \n"+
"      "+HIK+"tl off            Free         Stop listening          \n"+ 
"      "+HIK+"tl on             Free         Start listening         \n"+
"      "+HIK+"ttitle            Free         Set your Tracker title  \n"+
"      "+HIK+"tpretitle         Free         Set your Tracker pretitle  \n"+
"      "+HIK+"tupdate           Free         Update your tracker   \n"+
/*.
"      "+HIK+"tbest             Free         See the Tracker's top 10   \n"+
"      "+HIK+"tlegends          Free         See Nirvana's Legends      \n"+
*/
"      "+HIK+"tkills <player>   Free         See a players kills      \n"+
"      "+HIK+"tdeaths <player>  Free         See a players deaths     \n"+
/*
"      "+HIK+"tw <player>       100 sps      See where a player is      \n"+
*/
"                                                                       \n"+
""+HIB+"===================================================================="+NORM+" \n");
  }
}

/* *************************************************************************
 * command_hook
 *
*/

int
command_hook(string arg)
{
  if (Owner->query_level() < 10) 
  {
    notify_fail("You lack the experience to use this command.\n"+
               "You must be level 10 for the tracker to function.\n");
    return 0;
  }

  return (int)(BINDIR+query_verb())->main(arg);
}

/* *************************************************************************
 * init
 *
*/

void
init()
{
  int i;
  string *commands;

  if (environment() != this_player())
    return;

  if (Owner)
    return;

  Owner = this_player();
  Name = (string) Owner->query_real_name();
  load_info();

  if (!Legend)
    if ((int)this_player()->query_extra_level() == 100)
      Legend = 1;

  if (!Pk_legend)
    if (Points >= LEGENDARY)
      Pk_legend = 1;

  i = sizeof(commands = (string *)COMMANDSD->get_commands());

  while (i--) 
    add_action("command_hook",commands[i]);

}

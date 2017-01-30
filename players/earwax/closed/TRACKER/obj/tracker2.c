/* *************************************************************************
 * /players/earwax/closed/PK/tracker 
 *
 * PK Tracker
 *
 * Coded by Earwax 7/24/03
 *
 * See Tracker_info.txt for an explanation of this object
 *
 * *************************************************************************
*/

/* Global Variables */
static   object    Owner;        /* Who the tracker belongs to            */
static   string    Name;         /* real_name of the owner                */
         int       Pks,          /* number of pks                         */
                   Points,       /* total number of points                */
                   Deaths;       /* total number of deaths                */ 
static   string   *Commands;     /* all commands they can use             */
         status    Muffled;      /* channel muffled or not                */
static   int       With, Against;

#include "defs.h"

inherit WAXFUNS;

/* Prototypes */
status save_info(status silent);

/* ******
 * temporary debug
 *
*/
void tell_wax(string info) {
  object ob;

  if (ob = find_player("earwax")) tell_object(ob,info);
}

/* *************************************************************************
 * Info functions
 *
 * Functions to get various bits of info 
*/

string
format_level(object ob)
{
  int lvl, xlvl;
  string level;

  lvl = (int)ob->query_level();
  level = lalign(lvl,2);
  if (lvl == 19)
    if (xlvl = (int)ob->query_extra_level())
      level += "+"+xlvl;
  level = lalign(level,6);
  return level;
}

string
format_date()
{
  string old, new, t;
  
  old = ctime();
  switch(old[4..6])
  {
    case "Jan" : new = "01"; break;
    case "Feb" : new = "02"; break;
    case "Mar" : new = "03"; break;
    case "Apr" : new = "04"; break;
    case "May" : new = "05"; break;
    case "Jun" : new = "06"; break;
    case "Jul" : new = "07"; break;
    case "Aug" : new = "08"; break;
    case "Sep" : new = "09"; break;
    case "Oct" : new = "10"; break;
    case "Nov" : new = "11"; break;
    case "Dec" : new = "12"; break;
  }
  
  new += "/" + old[8..9] + "/" + old[22..23] + " " + old[11..15];
  return lalign(new,14);
}

int
get_base_points(object ob)
{
  int lvl, xlvl, points, modifier;
  object t;

  lvl = (int)ob->query_level();
  modifier = (lvl < 10 ? 0 : lvl);
  if (lvl == 19)
  {
    xlvl = (int)ob->query_extra_level();
    if (xlvl)
      modifier += 1 + ((int)ob->query_extra_level() / 10);
  }

  if (t = present(TRACKER_ID,ob))
    modifier += ((int)t->query_points() / 100);
  
  return modifier;
}

string
get_weapon()
{
  object wep;
  string wepname;

  if(wep = (object)Owner->query_weapon());
  {
    if (wepname = (string)wep->short())
      return wepname;
    else
      switch ((string)Owner->query_guild_name())
      {
        case "fallen"     : return "Hands (Fallen)";
        case "cyberNinja" : return "Chi (CyberNinja)";
        case "ranger"     : return "Hands (Ranger)";
        default           : return "Unknown";
      }
  }
  return "None";
}

string
format_guild(object ob)
{
  string name;

  name = (string)ob->query_guild_name();
  if (name == 0 || name == "0") name = "none";
  name = capitalize(name);
  return name;
}
  
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
  level = format_level(corpse);
  points = get_base_points(corpse);  

  tank = (object)corpse->query_attack();
  allies = ({ tank });

  if (tank != Owner)
    allies += ({ Owner });

  ob = first_inventory(environment(corpse));

  /* Go through every object in the room, if they are attacking the dude
   * that died, they are an ally (player or mob), if they are attacking
   * this player, they are an enemy.  This is for statistical tracking as
   * well as the points system.
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
  if (t = present(TRACKER_ID,corpse))
  {
    t->set_with(with); t->set_against(against);
    t->register_death_2(allies);
  }
/*
  STATSD->killer_stats(Owner, corpse, with, against);  
  t2 = format_guild(Owner);
  STATSD->add_stats(get_weapon(), t2, Name, points, with, against)
*/
  Points += points; Pks++;
  info = RED+"<"+HIK+"PKS"+NORM+NORM+RED+"> "+HIC+"DAEMON REPORTS: "
       +capitalize(Name)+" just killed "
       +capitalize((string)corpse->query_real_name())
       +" for "+points+" points.\n"+NORM+NORM;
tell_wax(info);
/*
  CHANNELD->channel_msg(info);
*/

  /* Log the kill information.  This will be done with write_file() instead
   * of clogging up memory with tracking it in an array.  This way, each
   * player can have a very large number of deaths and kills they are 
   * associated with, and the only time it needs to be spit out is with the
   * lookup commands - accessible in the area I'll put in, or by the 
   * commands in the tracker itself - a simple display will work for this.
  */
  info = format_date() + ": "
       + lalign(capitalize((string)corpse->query_real_name()),11) + " ("
       + lalign ("("+format_level(corpse)+"/" 
       + format_guild(corpse) + ")",21)
       + ralign(points,3) + "("+lalign(with+"/"+against,3)+")"
       + "\n";
/*
tell_wax("trying to write to: "+SAVEPATH+Name[0..0]+"/"+Name+".pks\n");
*/
  write_file(SAVEPATH+Name[0..0]+"/"+Name+".pks",info);
  save_info(0);

}

/* 
05/02/01 03:55: Vertebraker (19+100/Black Circle) 34 (3/1)
09/10/03 16:55: Earwax      (17    /Shardak)       6 (2/5)
*/
/* *************************************************************************
 * Query/set functions
 *
*/

int query_pks()        { return Pks; }
int query_deaths()     { return Deaths; }
int query_points()     { return Points; }
void set_muffle()      { Muffled = 1;    }
void toggle_muffle()   { Muffled = ( Muffled ? 1 : 0); }
status query_muffle()  { return Muffled; }
void set_with(int w) { With = w; }
void set_against(int a) { Against = a; }


/* *************************************************************************
 * Reset, load_info, save_info
 *
*/

void
reset(status arg)
{

  if (arg)
    return;

  /* initialize variables */
  Deaths = Pks = Points = 0;

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

  if (!silent) write("Your PK stats have been saved.\n");

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
  /* Only accept kills if the player is level 19 or bigger. No Legions */
  if (environment() && environment()->query_level() > 18)
    if (arg == "kill_check_object")
      return 1;

  return ( 
    arg == "pk tracker" ||
    arg == "tracker"    ||
    arg == TRACKER_ID ||
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
      + NORM + HIK + " PK points, dedicated\n to the cause of "
      + environment()->query_possessive() + " god, " + "Shardak."+NORM+NORM 
      );

/* That should look like:
Dreadnought has slain 36, died 42 times, and has 3000 PK points, dedicated
to the cause of his god, Shardak.
*/

  return (
    ( this_player() == Owner ? "You have " : capitalize(Name)+" has ") 
    + CYN + Pks + NORM + " PKs, "+ CYN + Deaths + NORM 
    + " deaths, and a total of " + CYN + Points + NORM 
    + " Legendary PK Points." );
}

string
short()
{ 
  if (!present("shardak_mark",this_player()))
  return ( HIK + 
    ( this_player() == Owner ? Name + "'s " : "Your ") +
    "Legendary PK Tracker"+NORM);

}

long()
{
  int i;

  write(short()+"\n");
  if (this_player() != environment())
    write("If you're level 19, you can get your own tracker!\n"
          + "Just goto Jareel's Hall of Legends (7e,2s,w,enter hall)\n");
  else
  { /* Do a real listing with descriptions and shit later */
    write("You can use the following commands.\n");
    i = sizeof(Commands); 
    while (i--)
      write("\t"+Commands[i]+"\n");
  }
}

/* *************************************************************************
 * register_death
 *
*/

void
register_death_2(object *killers)
{
  call_out("register_death", 1, killers);
}

void
register_death(object *killers)
{
  int i, siz;
  string info, t;

  while (remove_call_out("register_death") > -1);
  info = format_date() + ": ("+With+"/"+Against+") ";
  siz = sizeof(killers);

  for (i = 0; i < siz; i++)
  {
    if (killers[i]->is_player())
      t = (string)killers[i]->query_real_name();
    else
    {
    /* If it's a mob have to check for a short first */
      t = (string)killers[i]->short();
      if (!t)
        t = (string)killers[i]->query_name();
      if (!t)
        t = "Unknown Monster";
    }
    t = capitalize(t);
    if (i + 1 < siz)
      info += t + "/";
    else
      info += t;
  }
/*
  if (t = (string)Owner->query_guild_name())
    t = capitalize(t);
  else
    t = "None";
  STATSD->add_stats("", t, Name, 0, With, Against);
*/
  info += "\n";
tell_wax(HIB+"Info: "+info+NORM+NORM);
  write_file(SAVEPATH+Name[0..0]+"/"+Name+".d",info);
  write_file("/players/earwax/blahhh",info);
  write("GOt here!!!!\n");
  t = SAVEPATH+Name[0..0]+"/"+Name+".deaths";
tell_wax("T is : "+t+"\n");
write_file(t,info);
  write_file(SAVEPATH+Name[0..0]+"/"+Name+".dts","BLEH\n");
  Deaths++;
  save_info(0);
}

/* *************************************************************************
 * command_hook
 *
*/

int
command_hook(string arg)
{
  if (Owner->query_level() < 19) 
  {
    notify_fail("You lack the experience to use this command.\n"+
               "You must be level 19 for the tracker to function.\n");
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

  if (environment() != this_player())
    return;

  if (Owner)
    return;

  Owner = this_player();
  Name = (string) Owner->query_real_name();
  load_info();
  i = sizeof(Commands = (string *)COMMANDSD->get_cmds());
  while (i--) add_action("command_hook",Commands[i]);
  if (!Muffled) CHANNELD->register(Owner);  
}

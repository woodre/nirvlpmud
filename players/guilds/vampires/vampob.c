/******************************************************************************
 *
 *  File:         vampob.c
 *
 *  Function:     Handle all of the basic guild functions or pass them off to
 *                the correct objects
 *  Author(s):    Vital
 *
 *  Copyright:    Copyright (c) 2007 Vital-Dev
 *                All Rights Reserved.
 *
 *  Source:       Started anew.
 *
 *  Notes:      
 *
 *  Change History:
 *      2007-05-06    Added Header, Started recoding
 *      2007-06-09    Added custom save and restore functionality
 *  
 *****************************************************************************/

/*  ANSI is the color abbreviation, player_object are macros related   */
/*  to players and guild is for guild specific functions               */

#include <ansi.h>
#include "headers/player_object.h"
#include "headers/guild.h"

inherit "/players/guilds/vampires/lib/id_obj.c";
inherit "/players/guilds/vampires/lib/custom_save.c";

/*  Global Variable Declarations                                       */
/*  Note: Original code used all caps on variables - these have been   */
/*        changed to lowercase throughout.                             */

mapping vampire;

/******************************************************************************
 * silent_save
 * Arguments: none
 * Type:      int
 * Edited:    2007-06-09 added in custom_save format
 ******************************************************************************/
int
silent_save()
{
  string save_data;
  save_data = vampire["show_fangs"] + DELIMITER +
              vampire["telepathy_on"] + DELIMITER +
              vampire["blood_points"] + DELIMITER +
              vampire["storage"] + "\n";
  custom_save(BASE + "members/" + TPRN + ".save", save_data);
  return 1;
}

/******************************************************************************
 * silent_restore
 * Arguments: none
 * Type:      int
 * Edited:    
 ******************************************************************************/
 int
 silent_restore()
 {
  string temp;
  if (file_size(BASE + "members/" + TPRN + ".save"))
    temp = custom_restore(BASE + "members/" + TPRN + ".save");
  else
    return 0;
  if (sscanf(temp, "%d" + DELIMITER + "%d" + DELIMITER + "%d" +
      DELIMITER + "%d\n", vampire["show_fangs"], vampire["telepathy_on"], vampire["blood_points"], vampire["storage"]) == 4 )
    return 1;
  else
    return 0;
 }

/******************************************************************************
 * extra_look
 * Arguments: string
 * Type:      void
 * Purpose:   Can't Hide From Family!
 * Edited:    
 ******************************************************************************/
void
extra_look(string str)
{
  if (ENV() == TP)
  {
    write(HIK + "~o~ " + HIR + "You are a Member of the Family!" + HIK +
          " ~o~\n" + NORM);
  }
  else
  if ( TP && PFANGS )
  {
    write(HIK + "~o~ " + HIR + (string)ENV()->query_name() +
          " is a Member of the Family!" + HIK + " ~o~\n" + NORM);
  }
  else return 0;
}

/******************************************************************************
 * set/query functions for guild
 * Arguments: string, mixed
 * Type:      void & int
 * Edited:    2007-06-02  grouped the set/query functions
 *            2007-06-09  converted to mappings
 ******************************************************************************/
varargs void
set(string key_variable, mixed value)
{
  vampire[key_variable] = value;
}

mixed
query(mixed key_variable)
{
  if (member(vampire, key_variable))
    return vampire[key_variable];
  else
    return;
}

void
add(mixed key_variable, mixed value)
{
  if (member(vampire, key_variable) &&
      intp(value) &&
      intp(vampire[key_variable]))
    vampire[key_variable] = vampire[key_variable] + value;
  else
    set(key_variable, value);
}

/******************************************************************************
 * wolf_location
 * Arguments: none
 * Type:      string
 * Edited:    
 ******************************************************************************/
string
wolf_location()
{
  if(vampire["wolf_obj"] && ENV(vampire["wolf_obj"]))
  {
    if(vampire["wolf_location"] = (string)ENV(vampire["wolf_obj"])->short())
      return (string)ENV(vampire["wolf_obj"])->short();
  }
  return "none";
}

/******************************************************************************
 * reset
 * Arguments: status
 * Type:      void
 * Purpose:   initialize all internal variables
 * Edited:    
 ******************************************************************************/
void
reset(status arg)
{
  if (arg) return;
  vampire = ([ "blood_points" : 0,
               "show_fangs"   : 1,
               "telepathy_on" : 1,
               "storage"      : 0,
               "levitating"   : 0,
               "wolf_location": "",
               "target"       : 0,
               "wolf_obj"     : 0, ]);
  set_name("fangs");
  set_alias("vfangs");
  set_alt_name("vital_vampires");
  set_alt("brittany_vampires");
  set_ids( ({ name, alias, alt, alt_name, "GI", "vampire_fangs",
              "dark_sight_object", "canines", "teeth", "vampire fangs",
              "bfangs", "guild object", "guild_object"
           }) );
  remove_call_out("light_damage");
  call_out("light_damage", 3);
  set_heart_beat(1);
}

string
short()
{
  return vampire["show_fangs"] ?  RED + "long, canine fangs \( " + HIW + "dripping" + NORM +
    RED + "\)" + NORM : 0;
}

void
long()
{
  write("A pair of long, blood stained, canine teeth that protrude down from \n\
your upper gums and stick out over your thin bottom lip.\n");
}

/******************************************************************************
 * init
 * Arguments: none
 * Type:      void
 * Purpose:   adds Illarion weapon bonus and command hook
 * Edited:    
 ******************************************************************************/
void
init()
{
  TP->RegisterWeaponBonus(TO, 0, "vampire_strength_bonus");
  add_action("vampire_hook"); add_xverb("");
  if ((string)TP->query_guild_file() != GUILDOBJ)
    TP->set_guild_file(GUILDOBJ);
  if ((string)TP->query_guild_name() != GUILDNAME)
    TP->set_guild_name(GUILDNAME);
  silent_save();
  set_heart_beat(1);
}

/******************************************************************************
 * guild_login
 * Arguments: none
 * Type:      int
 * Purpose:   checks membership [also for guild login notes]
 * Edited:    
 ******************************************************************************/
int
guild_login()
{
  int membership;
  if (ETO &&
      TP &&
      TP->is_player() &&
      (TP == ETO) &&
      TPL < 20)
    call_other(MEMBER, "???", 0);
/*   membership = (int)MEMBER->query_member(TPRN);*/
    membership = 1;
    if (!membership && (int)TPL < 59)
    {
      write_file(LOG + "illegal_fangs.txt", TPRN + " " + ctime() +"\n");
      destruct(TO);
      return 1;
    }
    if (silent_restore())
    {
      write("CUSTOM RESTORE\nVampire 3.0 Guild Login\n\n\tNEW ITEMS\n");
      if (file_size(DOC + "vampire.news"))
        cat(DOC + "vampire.news");
    }
    else
    {
      write("Error restoring guild information.\nPlease contact a guild wiz \
to get this corrected.\n");
      destruct(TO);
    }
    if ((string)TP->query_guild_file() != GUILDOBJ)
      TP->set_guild_file(GUILDOBJ);
    if ((string)TP->query_guild_name() != GUILDNAME)
      TP->set_guild_name(GUILDNAME);
    silent_save();
    return 1;
}

/******************************************************************************
 * init_arg
 * Arguments: none
 * Type:      void
 * Purpose:   gets everything started on login
 * Edited:    
 ******************************************************************************/
void
init_arg()
{
  guild_login();
}

/******************************************************************************
 * vampire_hook
 * Arguments: string
 * Type:      int
 * Purpose:   command hook checks vampire commands directory
 * Edited:    
 ******************************************************************************/
int
vampire_hook(string str)
{
  string command, arguments, file, verb;
  verb = query_verb();
  if (!str)
  {
    notify_fail("Vampire Command Hook\n\"vampob\", vampire_hook, no str\n");
    return 0;
  }
  write(vampire["show_fangs"] ? HIR + ":[ " + NORM : "");
  if (sscanf(str, "%s %s", command, arguments) != 2)
  {
    if (sscanf(str, "%s.", command) != 1)
    {
      command = str;
    }
  }
  if (file_size(file = COMMAND + command + ".c") > 0)
    return (int)file->main(arguments);
  else if (file_size(file = VEMOTES + command + ".c") > 0)
  {
    return (int)file->main(arguments);
  }
  return 0;
}

/******************************************************************************
 * tell_my_room
 * Arguments: string, string
 * Type:      int
 * Purpose:   tells the room but not me
 * Edited:    
 ******************************************************************************/
int
tell_my_room(string msg, string ignore)
{
  object players_here;
  if (ETO && ETP)
  {
    players_here = first_inventory(ROOM);
    while (players_here)
    {
      if (living(players_here) &&
          !players_here->query_npc() &&
          players_here != TP &&
          (string)players_here->query_real_name() != ignore)
      {
        tell_object(players_here, msg + "\n");
      }
      players_here = next_inventory(players_here);
    }
    return 1;
  }
}

/******************************************************************************
 * sort_list_of_players
 * Arguments: array
 * Type:      string
 * Purpose:   converts array of players into sorted list
 * Edited:    
 ******************************************************************************/
array
sort_list_of_players(string *str)
{
  int i, j, sorted;
  string tmp;
  if (!str) return "No Argument Passed to sort_list_of_players";
  j = sizeof(str);
  sorted = 0;
  while(!sorted)
  {
    sorted = 1; j--;
      for (i=0; i < j; i++)
        if (str[i]->query_total_level() < str[i+1]->query_total_level())
        {
          tmp=str[i];
          str[i]=str[i+1];
          str[i+1]=tmp;
          sorted = 0;
        }
   }
   return str;
}

/******************************************************************************
 * light_damage
 * Arguments: none
 * Type:      int
 * Purpose:   does damage to vampires in lighted rooms
 * Edited:    
 ******************************************************************************/
int
light_damage()
{
  int pain;
  remove_call_out("light_damage");
  if (!ENV()) return 1;
  if (!ENV(ENV()) || ENV(ENV())->no_light_damage())
    return (call_out("light_damage", 3), 1);
  pain = set_light(0);
  if (ETO->query_level() < 20 && !ETO->query_ghost())
  {
    if (pain > 1)
      TELLOBJ(ETO, "You feel the " + HIY + "light" + NORM +
                    "sear your skin and flesh...\n");
    if (pain < -1 && ETO->query_mhp() != ETO->query_hp())
      TELLOBJ(ETO, "The soothing " + HIK + "darkness" + NORM +
                    " soothes your flesh and rejuvenates your soul...\n");
    if ( ((int)ETO->query_hp() - pain) > 0 )
    {
      if (pain > 5) pain = 5;
      if (pain < -5) pain = -5;
      if (ETO->query_interactive())
      {
        ETO->add_hit_point(-pain);
        ETO->add_spell_point(-pain);
      }
    }
    remove_call_out("light_damage");
    call_out("light_damage", 3);
    return 1;
  }
  return 1;
}

status get() { return 1; }
status drop() { return 1; }

/******************************************************************************
 * heart_beat
 * Arguments: none
 * Type:      void
 * Purpose:   allows for double attack
 * Edited:    
 ******************************************************************************/
void
heart_beat()
{
  object weapon;
  int vdiv, speed;
  if (!ENV()) return;
  if (!living(ENV())) return;
  if (ETO->query_ghost()) set("blood_points");
  if (ETO->query_attack())
  {
    if (ETO->query_weapon()) weapon = (object)ETO->query_weapon();
    vdiv = (671 - (int)GRANK);
    if (vdiv < 1 || vdiv > 5) vdiv = 5;
    speed = (((int)ETODEX * 2) + (int)ETOLUC + ((int)ETOSTE/2) -
             ((int)ETOSTR)/vdiv);
    if (speed > random(75))
    {
      TELLOBJ(ETO, HIK + "You merge with the shadows to strike again!\n" + NORM);
      TELLROOM(ENV(ETO), HIK + ETO->query_real_name() + " merges with the shadows...\n\t...and strikes a second time with vampire speed.\n");
      weapon->hit(ENV()->query_attack());
      ETO->toggle_already_fight(1);
      ETO->attack();
    }
  }
  return;
}

/******************************************************************************
 * vampire_strength_bonus
 * Arguments: none
 * Type:      int
 * Purpose:   buffs vampires in combat by level via modifier
 * Edited:    
 ******************************************************************************/
int
vampire_strength_bonus()
{
  int adjwc;
  if((int)environment()->query_level() > 19)
    tell_object(environment(),"Vampire strength bonus.\n");
  if((int)GRANK <= 0) adjwc = 0;
  else if((int)GRANK == 1 ||
          (int)GRANK == 2) adjwc = 1;
  else if((int)GRANK == 3) adjwc = 2;
  else if((int)GRANK >= 4) adjwc = 6;
  return (adjwc);
}

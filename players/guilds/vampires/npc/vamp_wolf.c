/******************************************************************************
 *
 *	File:			vamp_wolf.c
 *
 *	Author(s):		Vital
 *
 *	Copyright:		Copyright (c) 2007 Vital-dev
 *                All Rights Reserved.
 *
 *	Source:			Started anew from Nooneelse/Eurale code.
 *
 *	Notes:			
 *
 *	Change History:
 *			2007-05-25  started over
 *      2007-05-26  added additional types
 *      2007-05-27  added help, strict typing, new guild include
 *      2007-05-28  invis'd the shadow type, uploaded and debugged
 *	
 *****************************************************************************/

#pragma strict_types
#include <ansi.h>
#include "../headers/player_object.h"
#include "../headers/guild.h"

inherit "obj/monster";
inherit "/players/guilds/vampires/lib/id_obj.c";

string str, str2, type, master_name, wolf_name, cheat1, cheat2, display;
int wait_here, time_counter, wolf_muffled, wolf_protecting;
int wolf_ac, wolf_wc, wolf_hp, wolf_level;
object obj, obj2, master;

void
init()
{
  ::init();
  add_action("wolf_do",wolf_name);
}

void
setup_type(string str)
{
  string temp;
  if(!str)
  {
    temp = "wolf";
    type = temp;
    return;
  }
  else
  {
    switch(str)
    {
      case   "wolf":
        wolf_hp = 120;
        wolf_ac = 6;
        wolf_wc = 14;
        wolf_level = 8;
        display = str;
        break;
      case   "dire":
        wolf_hp = 130;
        wolf_ac = 7;
        wolf_wc = 15;
        wolf_level = 10;
        display = "dire wolf";
        break;
      case "shadow":
        wolf_hp = 150;
        wolf_ac = 8;
        wolf_wc = 16;
        wolf_level = 12;
        display = "shadow wolf";
        break;
      case "spirit":
        wolf_hp = 180;
        wolf_ac = 9;
        wolf_wc = 18;
        wolf_level = 14;
        display = "spirit wolf";
        break;
    }
    type = str;
    set_level(wolf_level);
    set_ac(wolf_ac);
    set_wc(wolf_wc);
    set_hp(wolf_hp);
  }
}

string
query_type()
{
  return type;
}

string
query_display()
{
  return display;
}


/******************************************************************************
 *
 *  wolf_do
 *
 *  Function:     This function is for all that the wolf can do.
 *
 *  Source:       Started anew.
 *
 *  Change History:
 *      2007-05-28  Recoded & Added Header
 *      2007-06-13  updated for new guild object
 *****************************************************************************/
int
wolf_do(string str)
{
  object obj;

  if(!master)
  {
    say("The " + BOLD + display + NORM +
        " looks lost and lopes off looking for " +
        capitalize(master_name)+".\n");
    destruct(this_object());
    return 1;
  }

  if(!str || str == "")
  {
    notify_fail("What did you want " + wolf_name + " to do?\n\Type \<" + wolf_name + " help\> to see what commands are available.\n");
    return 0;
  }

  if(!TP)
  {
    notify_fail("Command failed to come from valid player object.\n");
    return 0;
  }
  
  if(TP != master)
  {
    notify_fail("You cannot control someone else's " + display + ".\n");
    return 0;
  }

  if(str == "help")
  {
    short();
    write("Command him with: "+wolf_name+" <command>\n");
    write("He can do the following:\n\n"+
          "command           description\n"+
          "----------------  ------------------------------------------------------\n"+
          "help              display this message\n"+
          "stay              tells the wolf to wait here\n"+
          "heel              the wolf will begin following you\n"+
          "wolf come to me   calls the wolf from wherever you told it to wait\n"+
          "dismissed         send the wolf away\n"+
          "attack <monster>  attack a specific monster\n"+
          "stop attack       stop the attack\n"+
          "protect me        attack any aggressive monster it gets near (toggle)\n"+
          "drain corpse      drain a corpse to heal itself\n"+
          "\n");
    return 1;
  }

  if(lower_case(str) == "dismissed")
  {
    tell_room(environment(TO),
      "The " + BOLD + display + NORM + " seems to nod at " +
      capitalize(master_name) + " and lopes away.\n");
    obj = present("vampire fangs", master);
    obj->set("wolf_obj", 0);
    destruct(this_object());
    return 1;
  }

  if(str == "stay")
  {
    say("The " + BOLD + display + NORM +
        " pads into a dark area to sit and wait.\n");
    wait_here = 1;
    return 1;
  }

  if(str == "heel")
  {
    say("The " + BOLD + display + NORM +
        " scrambles to its feet and stands at " + capitalize(master_name) +
        "'s left side.\n");
    wait_here = 0;
    return 1;
  }

  if(sscanf(str, "attack %s", str2)==1 || sscanf(str, "kill %s", str2)==1)
  {
    obj = present(str2, environment(TO));
    if(obj) TO->attack_object(obj);
    else
      notify_fail("The " + BOLD + display + NORM + " growls:  " +
                  str2 + " is not here!\n");
    return 0;
  }

  if(sscanf(str, "stop %s", str)==1)
  {
    if(str == "attack")
    {
      obj = (object)TO->query_attack();
      if(obj)
        if(present(obj, environment(TO)))
        {
          obj->stop_fight();
          obj->stop_fight();
          obj->stop_hunter();
        }
      TO->stop_fight();
      TO->stop_fight();
      TO->stop_hunter();
      write("The " + BOLD + display + NORM + " stops fighting.\n");
      return 1;
    }
  }

  sscanf(str, "drain %s", str2);
  if(str2 == "corpse")
  {
    obj = present("corpse", environment(TO));
    if(!obj)
    {
      notify_fail("A corpse must be present to do that.\n");
      return 0;
    }

    if(TO->query_hp() > 100)
    {
      notify_fail("The " + BOLD + display + NORM +
                  " pants: I'm healthy.\n");
      return 0;
    }

    if(!obj->heal_value())
    {
      notify_fail("That corpse has no value.\n");
      return 0;
    }
    say(capitalize(master_name) +
        " snorts strangely and growls at the corpse.\n");
    heal_self(obj->heal_value());
    destruct(obj);
    say("The " + BOLD + display + NORM +
        " excitedly jumps on the corpse and " + BOLD + "RIPS" + NORM +
        " through its\nflesh to get at a vein.  It then sinks its FANGS " +
        "into the\ncorpse and greedily " + HIR + "laps up its BLOOD" +
        NORM + ".\n");
    return 1;
  }

  if(str == "protect me")
  {
    if(wolf_protecting)
    {
      wolf_protecting = 0;
      write("The wolfs protection mode is now " + HIR + "OFF" + NORM + ".\n");
      return 1;
    }
    else
    {
      wolf_protecting = 1;
      write("The wolf's protection mode is now " + HIR + "ON" + NORM + ".\n");
      return 1;
    }
  }
}

int
follow()
{
  if(wait_here) return 1;

  if(!environment(TO)) return 1; /* added by verte 6.11.01 */
  if(master)
    if(master && !present(master, environment(TO)))
    {
      tell_room(environment(TO), "The " + BOLD + display + NORM +
                " lopes away after " + capitalize(master_name) + ".\n");
      move_object(TO, environment(master));
      tell_room(environment(master), "A " + BOLD + display + NORM +
                " lopes in and stands at " + capitalize(master_name) +
                "'s left side.\n");
      return 1;
    }
}

void
reset(status arg)
{
  ::reset(arg);
  if (arg) return;

  wolf_muffled = 1;
  set_name("wolf");
  set_alias("pet");
  setup_type(str);
  wolf_name = "wolf";
  set_ids( ({ name, alias, alt, alt_name, display, wolf_name,
              "guild_pet", "guild_monster", "guild pet", "guild monster",
              master_name + "_wolf", master_name + " " + type
            }) );
  set_level(wolf_level);
  set_hp(wolf_hp);
  set_ac(wolf_ac);
  if(!present("wolfangs", TO)) /* EDIT THIS AND RELOCATE */
  {
    move_object(clone_object("/players/eurale/VAMPIRES/OBJ/wolf_fangs.c"),
      TO);
  }
  init_command("wield wolfangs");
  set_wc(wolf_wc);
  set_can_kill(1);
  set_aggressive(0);
  master_name = "null"; 
  enable_commands();
  set_heart_beat(1);
  set_death_emote("The " + display +
                  " slumps to the ground, lifeless.\n");
}

string
query_master_name() { return master_name; }


object
query_master() { return master; }

void
heart_beat()
{
  object wolf_obj;

  if(hit_point < max_hp) hit_point += 3;
  if(hit_point > max_hp) hit_point = max_hp;

  if(environment(TO))
  {
    if(!master)
    {
      if(!master_name)
      {
        destruct(this_object()); 
        return;
      }
      master = find_player(master_name);
    }

    wolf_obj = 0;
    wolf_obj = present("wolf", environment(TO));
    if(wolf_obj && wolf_obj != TO)
    {
      if ((string)wolf_obj->query_master_name() ==  master_name)
      {
        destruct(wolf_obj);
        destruct(this_object());
      }
    }

  if(query_attack()) /*  Removed pk check  -Vital  */
    if(TO->query_attack() && ((object)query_attack() == master ))
    {
      TO->stop_fight();
      TO->stop_fight();
      TO->stop_hunter();
    }

    time_counter++;
    follow();

    if(master && wolf_protecting)
    {
      if(master->query_attack())
        attack_object(master->query_attack());
    }
  }
  ::heart_beat();
}

int
query_save_flag() { return 1; }

int
am_i_a_servant() { return 1; }

int
am_i_a_wolf() { return 1; }

string
short()
{
  if(display == "shadow wolf") return 0;
  if(!this_player()) return "A dangerous looking wolf";
  if((string)TPRN == master_name)
  if(wolf_name)
    return capitalize(master_name) + "'s " + BOLD + display + NORM +
           " named '" + capitalize(wolf_name) + "'";
  else
    return capitalize(master_name) + "'s " + BOLD + display + NORM;
  else
    return "A dangerous looking wolf";
}

int
long()
{
  if(!this_player())
  {
    write(short() + "\n"); 
    return 1;
  }
  if((string)TPRN == master_name)
    write(short() + ".\n"+
          "Type '" + wolf_name + " help' to see how to talk to him.\n");
  else
    write(short() + ".\n");
  str2 = "wolf";
  if(wolf_name)
    str2 = capitalize(master_name) + "'s " + BOLD + display + NORM +
           " named '" + wolf_name + "'";
  else
    str2 = capitalize(master_name) + "'s " + display;
  return 1;
}

int
set_master(string str)
{
  master_name = str;
  master = find_player(master_name);
  return 1;
}

int
set_name(string str)
{
  wolf_name = str;
  name = lower_case(str);
  cap_name = capitalize(str);
  return 1;
}

/* tell wolf to come to me */
int
summon_wolf()
{
  tell_room(environment(this_object()),
           "The " + BOLD + "wolf's" + NORM +
           " ears stand up for a second.  He scrambles to his feet\n"+
           "and lopes away.\n");
  wait_here = 0;
  follow();
  return 1;
}

int
is_pet() { return 1; }

void
monster_died()
{
  int sps, hps;
  if(environment(TO))
  {
    if(!master)
    {
      if(!master_name || !find_player(master_name))
      {
        destruct(this_object()); 
        return;
      }
      master = find_player(master_name);
    }
    sps = (int)master->query_spell_point();
    hps = (int)master->query_hp();
    if (sps > 50 || hps > 50)
    {
      tell_object(master, "\nYour heart grieves at the death of " +
              capitalize(wolf_name) + ".\nIt's as if a piece of your soul has been ripped from your body.\n");
      TP->add_spell_point(-wolf_level);
      TP->do_damage(wolf_level, "other|grief");
    }
  }
}

string
get_help(string str)
{
  string help;
  if (!str)
  {
    wolf_do("help");
    return "Internal Help File";
  }
  switch(str)
  {
    case   "wolf": help = read_file(HELP + "wolf.txt"); break;
    case   "dire": help = read_file(HELP + "wolf.txt"); break;
    case "shadow": help = read_file(HELP + "wolf.txt"); break;
    case "spirit": help = read_file(HELP + "wolf.txt"); break;
    default:       wolf_do("help"); return "Internal Help File";
  }
  return help;
}

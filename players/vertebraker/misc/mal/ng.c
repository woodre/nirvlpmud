#include <ansi.h>

/*
 * Night Vision Goggles
 */

inherit "/obj/armor";

static status  Activated;
int            BatteryLife;

void reset(int arg)
{
    if(arg) return;
    ::reset();
    set_id("nightvision goggles");
    set_alias("goggles");
    set_weight(1);
    set_ac(0);
    set_type("eyewear");
    set_short(BOLD + BLK + "Night" + NORM + "Vision goggles");
    set_value(2500);
    set_long("\
This is a pair of thick, clunky night vision goggles.\n\
You are able to wear this over other armor to see in the dark.\n");
}

void long()
{
    ::long();
    if(BatteryLife)
      write(HIY + (BatteryLife / 60) + NORM + " minutes of battery life remaining.\n");
    else
      write("There isn't any battery life remaining in the chamber.\n");

    write("The goggles are " + (!Activated ? "de" : "") + "activated.\n");
}

status
id(string arg)
{
    if(::id(arg) || arg == "night vision goggles")
      return 1;
    if(Activated)
      return (arg == "dark_sight_object");
}

BatteryLife(x) { return (x ? (BatteryLife += x) : BatteryLife); }

verte_night_vision_goggles() { return 1; }

query_activated() { return Activated; }

init()
{
    ::init();
    add_action("cmd_activate",   "activate");
    add_action("cmd_deactivate", "deactivate");
}

cmd_activate(string arg)
{
    if(environment() != this_player()) return 0;

    if(!arg) return (notify_fail("Activate what?\n"), 0);
    if(!id(arg))
      return (notify_fail("You may activate the night vision goggles.\n"), 0);
    if(Activated)
      return (notify_fail("They are already activated.\n"), 0);
    if(!worn)
      return (notify_fail("\
You must be wearing the night vision goggles to activate them.\n"), 0);
    if(!BatteryLife)
      return (notify_fail("\
The goggles have run out of battery power.\n\
You may buy another battery pack from " + HIG + "Derellia IV" + NORM + ".\n"), 0);
    write("You activate the " + short_desc + ".\n");
    say((string)this_player()->query_name() + 
     " activates " + possessive(this_player())
    + " " + short_desc + ".\n");
    set_heart_beat(1);
    Activated ++;
    return 1;
}

drop()
{
    if(Activated)
    {
      write("You deactivate the " + short_desc + ".\n");
      if(this_player())
        say(this_player()->query_name() + " deactivates " +
          possessive(this_player()) + " " + short_desc + ".\n");
      Activated --;
    }
    return ::drop();
}

cmd_deactivate(string arg)
{
    if(environment() != this_player()) return 0;

    if(!arg) return (notify_fail("Deactivate what?\n"), 0);
    if(!id(arg))
      return (notify_fail("You may deactivate the night vision goggles.\n"), 0);

    if(!Activated)
      return (notify_fail("They are already deactivated.\n"), 0);
    if(!worn)
      return (notify_fail("\
You must be wearing the night vision goggles to deactivate them.\n"), 0);
    write("You deactivate the " + short_desc + ".\n");
    say((string)this_player()->query_name() + 
     " deactivates " + possessive(this_player())
    + " " + short_desc + ".\n");

    Activated --;
    return 1;
}

heart_beat()
{
    if(!Activated)
      return set_heart_beat(0);
    if(BatteryLife > 0)
      BatteryLife--;
    else
    {
      if(worn)
        tell_object(worn_by, "The batteries in your " + short_desc
                    + " die.\n");
      Activated --;
      set_heart_beat(0);
    }
}

string
locker_arg() 
{
    return BatteryLife + "";
}

void locker_init(string x)
{
    BatteryLife = atoi(x);
}

string
short()
{
    string sh, x;
    if(sscanf((sh = (string)::short()), "%s(worn)", x) && worn_by)
      return x + "(worn over " + ((this_player() && this_player() == worn_by) ?
                                  "your" : possessive(worn_by)) + " eyes)";
    else return sh;
}

remove(str)
{
    if((environment() == this_player()) && id(str) && worn)
      cmd_deactivate("night vision goggles");
    return ::remove(str);
}

status
generic_object()
{ 
    return 1;
}

status
restore_thing(string str)
{
    restore_object(str);
    return 1;
}

status
save_thing(string str)
{
    save_object(str);
    return 1;
}

int is_socketable() { return 1; }

int MaxBatteryLife() { return 7200; } /* two hours */

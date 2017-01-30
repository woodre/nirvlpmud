#include <ansi.h>

/*
 * General purpose Power Battery
 * See /players/vertebraker/misc/mal/battery.h
 * for battery implementation.
 */

inherit "/obj/treasure";

int Units;

void reset(int arg)
{
    if(arg) return;
    set_id("powerbattery");
    set_alias("battery");
    set_short(HIY + "PowerBattery" + NORM);
    set_long("\
A dual-celled PowerBattery for general use.\n\
To use it on an item, type \"socket battery in <what>\".\n");
    set_weight(1);
}

void init()
{
    ::init();
    add_action("cmd_socket", "socket");
}

cmd_socket(str)
{
    string what, dest;
    object obj;
    int max_life, curr_life, unit_ded;

    if(environment() != this_player()) return 0;
    if(!str)
      return (notify_fail("Socket what in what?\n"), 0);
    if(sscanf(str, "%s in %s", what, dest) < 2 ||
       !id(what)) 
      return (notify_fail("You may socket the battery in something.\n"), 0);
    if(!(obj = present(dest, this_player())))
      return (notify_fail("You don't have " + dest + " in your inventory.\n"), 0);
    if(!obj->is_socketable())
      return (notify_fail("You can't plug the battery into that.\n"), 0);
    if((curr_life = (int)obj->BatteryLife()) ==
       (max_life  = (int)obj->MaxBatteryLife()))
      return (notify_fail(
        (string)obj->short() + " is fully charged.\n"), 0);
    if((curr_life + Units) > max_life)
      unit_ded = (max_life - curr_life);
    else
      unit_ded = Units;
    write("You plug the battery into " + (string)obj->short() + " and push the button.\n" +
          "The battery beeps.\n");
    say((string)this_player()->query_name() + " plugs a battery into " +
        (string)obj->short() + " and pushes a button.\n" +
        "You hear a 'beep'.\n");

    obj->BatteryLife(unit_ded);
    Units -= unit_ded;
    if(!Units)
    {
      write("The battery is dead, so you throw it away.\n");
      say((string)this_player()->query_name() + " throws away a dead battery.\n");
      destruct(this_object());
    }
    else
      write("Battery units remaining: " + Units + ".\n");

    return 1;
}

string short() { return (::short() + " [" + HIY + Units + "u" + NORM + "]"); }

void long()
{
   ::long();
   write("There are " + Units + " units remaining.\n");
}
      

Units(x) { return (x ? (Units = x) : Units); }

int
query_value()
{
    return (Units * 1000 / 4000);
}

int
query_save_flag()
{
    return 1;
}

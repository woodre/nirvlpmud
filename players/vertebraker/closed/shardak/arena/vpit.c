#include "../def.h"

#define ABOVE_PIT (PATH + "above_arena")

inherit "/players/vertebraker/room";

#define block "/players/vertebraker/closed/shardak/arena/block"
#define blockid "shardak_arena_block"

string curr_revive;

void reset(int arg)
{
    if(arg) return;
    enable_commands();
    short_desc = ("A pit");
    long_desc = ("\
You are in a deep, dark pit.  High above you can see the remainder of the\n\
Shardak cave.  Moss grows on the sides of this humid chamber.  Metal grates\n\
against the crumbling rock walls provide a channel for the moisture.  A\n\
metal gate is closed tightly above your head.\n");
    items = ({ 
      "cave", "The Shardak cave looms above your head",
      "moss", "\
Plush, soft green moss has been growing in this chamber for centuries.\n\
The moisture of this place brings with it life for this organism",
      "sides", "Moss is growing upon the sides of this chamber",
      "chamber", long_desc,
      "grates", "\
Small metal grates with vertical slits to allow the moisture to pass\n\
through", 
      "gate", "\
The sliding metal gate has been latched shut.\n\
Perhaps you could \"unlatch\" it?" });

    property = ({ "no_teleport", "spar_area" });
}

string short()
{
    return "A pit";
}

void init()
{
    ::init();
    add_action("cmd_unlatch", "unlatch");
}

int cmd_unlatch(string str)
{
    if(str == "gate") {
      write("Do you really want to unlatch the gate?\nYour spar will end.\n[y/n] ");
      return(input_to("confirm"), 1);
    }
    if(!str) return (notify_fail("Unlatch what?\n"), 0);
    else return (notify_fail("You may \"unlatch\" the gate.\n"), 0);
}

confirm(str)
{
    if(str != "y") return (notify_fail("Wise choice, warrior.\n"), 0);
    else {
      write("You unlatch the gate, and climb out.\n");
      BootPlayers();
      return 1;
    }
}

BootPlayers()
{
    object obj, obj2;
    obj = first_inventory(this_object());
    while(obj) { 
      obj2 = next_inventory(obj);
      if(living(obj)) {
        tell_object(obj, "\n\tYou appear above the pit.\n\n");
        move_object(obj, (PATH + "above_arena"));
      }
      else destruct(obj);
      obj = obj2;
    }
}

void catch_tell(string str)
{
    object obj;
    string who;

    if(!str) return;

    if(sscanf(str, "%s died.", who) == 1)

    {
      object ob;
 
      if((ob = find_player(lower_case(who))) && 
          (environment(ob) == this_object()) && ((int)ob->query_hp() <= 0)
          && !curr_revive)
      {
        mixed att;

        move_object(clone_object(block), ob);
        if(att = (object)ob->query_attack())
        {
          move_object(clone_object(block), att);
          att = (string)att->query_real_name();
        }
        call_out("Obituary", 1, ({ lower_case(who), att }));
      }
    }

    if(obj = find_object(ABOVE_PIT))
      tell_room(obj, "%" + str);
}

Obituary(arr)
{
    object obj;
    CHANNELD->broadcast(capitalize(arr[0]) + " was slain in the Pit by " +
                        capitalize(arr[1]) + ".\n", 0, "[Servants]");

    if(obj = find_player(arr[0]))
    {
      object c;
      if(c = present("corpse", this_object()))
      {
        move_object(c, obj);
        c->move_stuff(c);
        obj->recalc_carry();
      }
      obj->remove_ghost();
      if(c = present(blockid, obj))
        destruct(c);
      tell_object(obj, "\n\tYou magically revive.\n\n");
    }

    if(obj = find_player(arr[1]))
      if(obj = present(blockid, obj)) destruct(obj);

    BootPlayers();

    if(obj = find_object(ABOVE_PIT))
      tell_room(obj, "\
Water fills the pit, rises to the gate, and then falls back down,\n\
leaving absolutely nothing remaining.\n");
}

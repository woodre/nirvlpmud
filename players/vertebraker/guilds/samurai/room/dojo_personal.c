#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  set_short("Dojo - Lockers");
  set_long("\
Dojo - Lockers\n\
A large curtain wraps around this room, behind which are\n\
numerous lockers for the Samurai guild.\n\
A potted bonsai plant rests in the corner of the room.\n\
You may \"store\", \"retrieve\", \"list\" or \"clear\" items\n\
from your lockers.\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_sc","east",
  });
}

init()
{
  ::init();
  if(this_player()->query_guild_name()=="samurai")
  {
    add_action("cmd_store","store");
    add_action("cmd_retrieve","retrieve");
    add_action("cmd_list","list");
    add_action("cmd_clear","clear");
  }
}

#define LOCKERD "/players/vertebraker/guilds/samurai/room/lockerd"

int
can_store(object who)
{
    return (int)who->query_guild_rank();
}

cmd_store(string str)
{
    object ob, scar;
    string tmp, name;

    if (!str || !(ob = present(str, this_player()))) {
	notify_fail("Store what?\n");
	return 0;
    }
    name = (string) this_player()->query_real_name();
    if ((int) LOCKERD->items_stored(name) >= can_store(this_player()))
      return (write("There is not room for it.\n"), 1);
    if (tmp = (string) ob->query_name())
      str = tmp;
    if (ob->drop()) {
	write("You are not able to put it in the room.\n");
	return 1;
    }
    if (!LOCKERD->store_item(name, ob)) {
	write("It refuses to go into the room.\n");
	return 1;
    }
    if (ob) destruct(ob);
    write("Your " + str + " has been stored.\n");
    return 1;
}

cmd_retrieve(string str)
{
    object ob;
    string name;
    int x;

    if (!str) return (notify_fail("Retrieve which item?\n"), 0);
    name = (string) this_player()->query_real_name();
    x = atoi(str);
    if (x < 1 || (x > (int) LOCKERD->items_stored(name))) {
	write("You do not have such a thing stored.\n");
	return 1;
    }
    ob = (object) LOCKERD->retrieve_item(name, str);
    if (!ob)
	write("You were unable to retrieve it.\n");
    else {
	if (transfer(ob, this_player()))
	  transfer(ob, this_object());
	name = (string)ob->query_name() || "thing";
	write("You retrieve your " + name + ".\n");
    }
    return 1;
}

cmd_list(string str)
{
    object scar;
    string tmp, name;

    name = (string) this_player()->query_real_name();
    tmp = (string) LOCKERD->list_items(name);
    if (!tmp)
      write("You have nothing in your room.\n");
    else
      write(tmp);
    
    if (can_store(this_player()) == 1)
      write("You have room for a total of 1 item in your room.\n");
    else
      write("You have room for a total of " + can_store(this_player()) +
	    " items in your room.\n");
    return 1;
}

cmd_clear(string str)
{
    int x;
    string name;

    if (!str) return (notify_fail("Clear out which spot?\n"), 0);
    name = (string) this_player()->query_real_name();
    x = atoi(str);
    if (x < 1 || (x > (int) LOCKERD->items_stored(name))) {
	write("You do not have such a thing stored.\n");
	return 1;
    }
    LOCKERD->remove_item(name, str);
    write("It has been disintegrated.\n");
    return 1;
}

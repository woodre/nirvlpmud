/*  Changed rooms to a locker system - and ripped Vertes shardaks
    niche system for it. 
    - Maledicta "Something about reinventing the wheel"
*/
#include "/players/maledicta/ansi.h"
#define LOCKERD   ("/players/maledicta/templar/rooms/locker")
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Templar Weapon Lockers "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  You stand within a large open room that is filled with\n"+
"huge storage lockers.  Each locker is made of an unbreakable\n"+
"mithril steel with heavy enchantments on them.  A door leads\n"+
"south back to the Training hall.  A sign hangs on the wall\n"+
"with instructions on it.\n";

items = ({
"lockers",
"Huge lockers that line the walls of the room. Each is made of\n"+
"an unbreakable mithril with heavy enchantments to protect them",
"door",
"A door that leads south to the training hall",
"sign",
"A sign that you can read",
});

dest_dir = ({
  "/players/maledicta/templar/rooms/adv_guild","south",
});

}

init(){
    ::init();
    add_action("read_sign", "read");
    add_action("cmd_list", "list");
    add_action("cmd_store", "store");
    add_action("cmd_retrieve", "retrieve");
    add_action("cmd_clear", "clear");
  this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }


read_sign(){ 
write("You read the sign...\n\n\n"+
      "The following commands may be used to operate the locker\n"+
      "system:\n\n"+
      "List            -   List the current items stored.\n"+
      "Store <item>    -   Store an item in a locker.\n"+
      "Retrieve <item> -   Get an item from a locker.\n"+
      "Clear <item>    -   Clear out an item from a locker.\n\n");
return 1;
}

static int
can_store(object who)
{
    object cross;
    int total;
    
    if (objectp(who) && (cross = present("KnightTemplar", who))) {
        total = 3;
    if(who->query_guild_rank() > 8) total += 1;
	 else if (total > 4) total = 4;
	 return total;
    }
}

status
cmd_store(string str)
{
    object ob, cross;
    string tmp, name;

    if (!(cross = present("KnightTemplar", this_player()))) return 0;
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
	write("You are not able to put it in the locker.\n");
	return 1;
    }
    if (!LOCKERD->store_item(name, ob)) {
	write("It refuses to go into the locker.\n");
	return 1;
    }
    if (ob) destruct(ob);
    write("Your " + str + " has been stored.\n");
    return 1;
}

status
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

status
cmd_list(string str)
{
    object cross;
    string tmp, name;

    if (!(cross = present("KnightTemplar", this_player()))) return 0;
    name = (string) this_player()->query_real_name();
    tmp = (string) LOCKERD->list_items(name);
    if (!tmp)
      write("You have nothing in your lockers.\n");
    else
      write(tmp);
    
      write("You have room for a total of " + can_store(this_player()) +
	    " items in your locker.\n");
    return 1;
}

status
cmd_clear(string str)
{
    int x;
    string name;

    if (!str) return (notify_fail("Clear out which item?\n"), 0);
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


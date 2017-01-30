/*
 * Shardak guild is (tm) Dragnar/John
 * Change log:
 * 960702 - created
 * 030715 - added color, tweaked desc and added
 *          exits viewable by shardaks only [linus]
 * 030719 - fixed long to allow add_items [linus]
 */

#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/daemons.h"
#include "../include/ansi.h"
inherit ROOM;

void
create()
{
    ::create();
    set_short(RED+"Niche room"+NORM);
    set_long(HIK+"\
The passage opens into a long and narrow room.  The western wall\n\
bears deep niches carved into the rock.  Each and every servant\n\
of Shardak has a private niche to store their equipment in.\n"+NORM);
    set_exits(([
	"east" : (PATH + "throne"), 
	]));
    add_item("niche",
	     "In your own niche you can store and retrieve items.\n" +
	     "You can also list the contents of the niche.\n" +
	     "If something is causing trouble, then clear it.\n");
    add_item("wall",
             "The wall bears deep niches carved into the rock.\n");
    set_light(1);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

/* Room long description, and shows exits only to shards */

void
long(string arg) {
 if(!arg) {
  if((int)this_player()->query_brief() != 2) 
   write(RED+"Niche room\n"+NORM);
    ::long(arg);
  if (present("shardak_mark",this_player())) 
   write("\t"+NORM+RED+"\There is one exit: east.\n"+NORM);
    return;
 }
 else ::long(arg);
}

/*
 * 4 additional actions
 */
void
init()
{
    ::init();
    add_action("cmd_list", "list");
    add_action("cmd_store", "store");
    add_action("cmd_retrieve", "retrieve");
    add_action("cmd_clear", "clear");
}

static int
can_store(object who)
{
    object scar;
    int total;
    
    if (objectp(who) && (scar = present(OBJID, who))) {
        total = ((int) scar->GuildClass() + 2)/10;
	if (!total) total = 1;
	else if (total > 3) total = 3;
	return total;
    }
}

status
cmd_store(string str)
{
    object ob, scar;
    string tmp, name;

    if (!(scar = present(OBJID, this_player()))) return 0;
    if (!str || !(ob = present(str, this_player()))) {
	notify_fail("Store what?\n");
	return 0;
    }
    name = (string) this_player()->query_real_name();
    if ((int) LOCKERD->items_stored(name) >= can_store(this_player()))
      return (write("There is not room for it.\n"), 1);
    if (tmp = (string) ob->query_name())
      str = tmp;
/*    
    if (ob == (object) this_player()->query_weapon()) {
	write("You must unwield it first.\n");
	return 1;
    }
    if (ob->query_worn()) {
	write("You must first take it off.\n");
	return 1;
    }
 */
    if (ob->drop()) {
	write("You are not able to put it in the niche.\n");
	return 1;
    }
    if (!LOCKERD->store_item(name, ob)) {
	write("It refuses to go into the niche.\n");
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
    object scar;
    string tmp, name;

    if (!(scar = present(OBJID, this_player()))) return 0;
    name = (string) this_player()->query_real_name();
    tmp = (string) LOCKERD->list_items(name);
    if (!tmp)
      write("You have nothing in your niche.\n");
    else
      write(tmp);
    
    if (can_store(this_player()) == 1)
      write("You have room for a total of 1 item in your niche.\n");
    else
      write("You have room for a total of " + can_store(this_player()) +
	    " items in your niche.\n");
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

/* Vertebraker - 2000
 * 030715 - Added color, exits only visible to shardaks and tweaked desc [linus]
 * 030719 - Changed long format to allow for items to work [linus]
 */
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/ansi.h"
#define STORE (PATH + "mushroom")
inherit ROOM;

/* stuff..
vokal(string str) { return (index(str[0], "aeiouy") >= 0);}
*/

void
create()
{
    ::create();
    set_short(GRN+"The imp's garden"+NORM);
    set_long(HIK+"\
The black soil covering the floor is sprawled with clusters of\n\
iron-grey toadstools and white-spotted green mushrooms. The air\n\
is fetid and deficient in oxygen. Standing against the northern\n\
wall is a wooden workbench, littered with vials and racks of test\n\
tubes.  A rickety ladder pokes up through a small hole in the low\n\
ceiling.\n"+NORM);  
    set_items(([
        "soil" : "\
You glance at the dark black soil and spy all of the toadstool\n\
and mushroom spores growing out of the ground.\n",
        ({ "toadstools", "mushrooms", }) : "\
The grey toadstools and mushrooms sprout out menacingly from the\n\
soil around your feet here in the garden.\n",
        ({ "workbench", "vials", "tubes", }) : "\
Vials and tubes lie askew on this workbench, filled with\n\
fertilizers and grow sprays.\n",
        ({ "ladder", "rickety ladder", }) : "\
A half-rotted ladder made of wood.  It is still sturdy\n\
enough to permit one to climb up it.\n",
    ]));
    set_exits((["up" : (PATH + "deepdown")]));
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

/* Room long description, shows exits only to Shards */
void
long(string arg) {
   if(!arg) {
    if((int)this_player()->query_brief() != 2) 
     write(GRN+"The imp's garden\n"+NORM);
      ::long(arg);
 if (present("shardak_mark",this_player())) 
  write("\t"+NORM+RED+"\The only exit is: up.\n"+NORM);
   return;
 }
  else ::long(arg);
}

void
reset(int arg)
{
    object      imp;

    ::reset(arg);
    if (!(imp = present("imp"))) {
        imp = clone_object("/obj/monster");
        imp->set_name("imp");
	  imp->set_gender("neuter");
        imp->set_short(GRN+"An imp"+NORM);
	  imp->set_long(GRN+"\
The scrawny imp has a sick pale green complexion. Its large staring\n\
eyes are white and blind from always working in the dark, nourishing\n\
the magical fungi here. Delicate little black claws adorn its hands.\n\
The imp lets you 'list' and 'buy' its goods.\n"+NORM);
        imp->set_level(7);
        imp->set_wc(11);
        imp->set_ac(6);
        move_object(imp, this_object());
    }
}

void
init()
{
    ::init();
    add_action("cmdList", "list");
    add_action("cmdBuy", "buy");
}

status
cmdList(string arg)
{
    if (arg || !present("imp", this_object()))
        return 0;
    if (!STORE->cmd_list())
        write("The imp mutters, \"I have nothing to sell at the moment.\"\n");
    return 1;
}

status
cmdBuy(string arg)
{
    if (!present("imp", this_object()))
        return 0;
    if (!arg) {
        notify_fail("Buy what?\n");
        return 0;
    }
    if(arg == "toadstools") arg = "basket of toadstools";
    if(arg == "mushrooms") arg = "basket of mushrooms";
    if(arg == "elixir") arg = "elixir of life";
    switch ((int) STORE->cmd_buy(arg)) {
        case -3:
            write("The imp says, \"You are not able to carry more.\"\n");
            break;
        case -2:
            write("The imp frowns at you, \"Come back when you can pay.\"\n");
            break;
        case -1:
            write("The imp looks puzzled. \"I cannot sell you that\", it says.\n");
            break;
        case 0:
            write("The imp retorts, \"I have no such thing for sale!\"\n");
            break;
        default:
            write("You pay the imp for the " + arg + ".\n");
            say(this_player()->query_name() + " buys one " + arg + ".\n");
            break;
    }
    return 1;
}

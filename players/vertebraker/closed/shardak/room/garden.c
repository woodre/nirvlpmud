/*
 * 
 */
#include "/players/balowski/lib.h"
#include "../def.h"
#define STORE (PATH + "mushroom")
inherit ROOM;

/* stuff..
vokal(string str) { return (index(str[0], "aeiouy") >= 0);}
*/

void
create()
{
    ::create();
    set_short("The imp's garden");
    set_long("\
A rickety ladder has led you down into a dark hollow with a low\n\
ceiling. The black soil covering the floor is sprawled with clusters\n\
of iron-grey toadstools and white-spotted green mushrooms. The air\n\
is fetid and deficient in oxygen. By the wall is a wooden workbench,\n\
littered with vials and racks of test tubes.\n");
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
    ]));
    set_exits((["up" : (PATH + "deepdown")]));
    set_property("fight area", 1);
    set_property("no teleport", 1);
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
        imp->set_short("An imp");
	imp->set_long("\
The scrawny imp has a sick pale green complexion. Its large staring\n\
eyes are white and blind from always working in the dark, nourishing\n\
the magical fungi here. Delicate little black claws adorn its hands.\n\
The imp lets you 'list' and 'buy' its goods.\n");
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

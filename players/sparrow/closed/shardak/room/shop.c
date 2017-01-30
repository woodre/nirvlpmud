/*
 * Shardak guild, (tm) Dragnar/John
 * Shop (Demon merchant) is (c) Balowski/Rasmus, 950201
 * Last change: April 1st 1995 (made it a room)
 * October 16th '95: Added list, buy, value commands
 *   "Mowing down mc's like I'm mowing the lawn"
 */
#include "/players/balowski/lib.h"
#include "../def.h"
#define STORAGE (PATH + "backshop")

inherit ROOM;

int             total;          /* total price */
int             items;          /* number of items sold */
object          merchant;       /* the salesperson */

/*
 * room functions
 */
void
create()
{
    ::create();
    set_short("The demon merchant's");
    set_long("\
You are in a secluded corner of the grotto. The flickering torch\n\
light does not have much strength here. A red glow from the north\n\
is dominant, and it produces strange shadows among the stalagmites.\n\
\tYou see two exits: west and north.\n");
    set_exits( ([
	"north" : (PATH + "smithy"),
	"west"  : (PATH + "grotto"),
	]));
    set_light(1);
    set_property("fight area", 1);
}

void
reset(int arg)
{
    ::reset(arg);
    if (!merchant) {
	merchant= clone_object(PATH + "shopkeep");
	merchant->move_player("in#" + file_name(this_object()));
    }
}

/*
 * The demon merchant can be called upon. For this purpose:
 */
object
query_merchant()
{
    return merchant;
}

/*
 * merchant functions
 */

/*
 * needed prototypes because of recursive sell
 */
void do_sell(object ob);

void
annoy()
{
    say( "The demon seems slightly annoyed with " +
	(string) this_player()->query_name() + ".\n");
}

void
sell_contents(object bag)
{
    object ob, next;

    ob = first_inventory(bag);
    if (!ob)
	write("The demon mumbles, \"Hmm... empty.\"\n");

    for (; ob; ob = next) {
	next = next_inventory(ob);
	do_sell(ob);
    }
}

void
do_sell( object ob)
{
    int value;

    value = (int) ob->query_value();
    if (value == 0) {
	write("The demon shakes its head in refusal, \"Worthless.\"\n");
	return;
    }

    if (query_attribute( "*", ob)) {
	write("The demon says, \"" + ob->short() + " is tagged.\"\n");
	return;
    }

    if (ob->query_worn() || ob == (object) this_player()->query_weapon()) {
	write("The demon says, \"" + ob->short() + " is equipped.\"\n");
	return;
    }

    if (ob->can_put_and_get())
	sell_contents(ob);

    if (transfer(ob, STORAGE)) {
	if (!ob)
	    write("The demon throws back its head and cackles with glee.\n");
	else
	    write("The demon shrugs and says, \"" + ob->short() +
		  " will not move into my Sack.\"\n");
	return;
    }

    if (value > 1000) {
        if(value < 1500) value = (1000 + random(value-1000));
        else value = 1000+random(500);

	print("\
The demon says, \"Principles prevent me from paying you more than " +
value + " golden Coins for " + ob->short() + ".\"\n");
    }
    else
	print("The demon says, \"For " + ob->short() + " I shall pay you " +
	      value + " golden coins.\"\n");

    items++;
    total+= value;
}

void
sell_all()
{
    object ob, next;

    for (ob= first_inventory( this_player()); ob; ob= next) {
	next= next_inventory( ob);
	/* only sell invisible object is player explicitly says so */
	if (ob->short())
	    do_sell( ob);
    }
}

status
sell(string what)
{
    object ob;

    items = total = 0;

    if (!what) {
	write( "The demon asks you slightly annoyed, \"Sell what?\"\n");
	annoy();
	return 1;
    }

    if (what == "all")
	sell_all();
    else {
	ob= present( what, this_player());
	if (!ob) {
	    write( "The demon hisses, \"Such an Item hast Thou not.\"\n");
	    annoy();
	}
	else
	    do_sell( ob);
    }

    if (environment( this_player()) != this_object()) {
	/* Pay a fee for the portable shop service.
	 * 5 % for guild members. 10 % for others */
	if ((string) this_player()->query_guild_name() == GUILDNAME)
	    total-= total/20;
	else
	    total-= total/10;
    }

    if (items) {
	write( "\
The demon fetches an abacus from its enormous sack. Its clawed fingers\n\
dance skilledly across the rack moving bone pellets left and right.\n\
It tosses the abacus back into the sack and hands you " + total + " golden\n\
coins from its purse.\n\
The demon smiles and says, \"Pleased to do Business with Thou.\"\n");
	this_player()->add_money( total);
	say( "\
Money and goods change hands between the demon and " +
this_player()->query_name() + ".\n");
    }
    return 1;
}

status
list(string str)
{
    write("The demon lets you have a peek into its sack.\n");
    if (STORAGE->cmd_list(str))
	write("The demon asks, \"Can any of my goods tempt you?\"\n");
    else
	write("The sack is empty.\n");
    return 1;
}

status
buy(string str)
{
    int price;
    if (!str) {
	write("The demon peers quizzically at you, \"Buy what?\"\n");
	return 1;
    }

    switch (price = (int) STORAGE->cmd_buy(str)) {
    case 0:
	write("\
The demon hisses, \"Please choose from the List of Articles in my Sack.\"\n");
	break;
    case -1:
	write("\
The demon mutters, \"An odd Object that is. I will not part with It.\"\n");
	break;
    case -2:
	write("\
The demon pokes you in the ribs with a clawed finger, \"Sufficient gold\n\
Coins hast Thou not. There will be no bargain.\"\n");
	break;
    case -3:
	write("\
The demon hisses, \"Your burden is already too big. I will not add more.\"\n");
	break;
    default:
	write("\
The demon hands you the wanted " + str + ". You pay the " + price + "\
 gold coins in return.\n");
	say( "\
Goods and money change hands between the demon and " +
this_player()->query_name() + ".\n");
	break;
    }
    return 1;
}

status
value(string str)
{
    return (status) STORAGE->cmd_value(str);
}

void init() { ::init(); 
add_action("bog", "2heheheheheh"); }

bog() { move_object(this_player(), this_object()); }

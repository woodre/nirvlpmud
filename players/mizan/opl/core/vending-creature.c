#define HEALS "players/mizan/opl/heals/"
#define ITEMS "players/mizan/opl/items/"
inherit "/players/mizan/opl/core/monster.c";
#include "/obj/ansi.h";

string desc;
string item;
int cost;
int stock;
int items_for_sale;

set_items_for_sale(arg)
{
    items_for_sale = arg;
}

reset(arg) 
{
    object gold, stick;

    if(!desc)
    {
	desc = allocate(15);
	desc[0] = "Unstocked.........................................0 coins";
	desc[1] = "Unstocked.........................................0 coins";
	desc[2] = "Unstocked.........................................0 coins";
	desc[3] = "Unstocked.........................................0 coins";
	desc[4] = "Unstocked.........................................0 coins";
	desc[5] = "Unstocked.........................................0 coins";
	desc[6] = "Unstocked.........................................0 coins";
	desc[7] = "Unstocked.........................................0 coins";
	desc[8] = "Unstocked.........................................0 coins";
	desc[9] = "Unstocked.........................................0 coins";
	desc[10]= "Unstocked.........................................0 coins";
	desc[11]= "Unstocked.........................................0 coins";
	desc[12]= "Unstocked.........................................0 coins";
	desc[13]= "Unstocked.........................................0 coins";
	desc[14]= "Unstocked.........................................0 coins";
    }

    if (!item) 
    {
        item = allocate(15);
        item[0] = ITEMS+"potato.c";
        item[1] = ITEMS+"potato.c";
        item[2] = ITEMS+"potato.c";
        item[3] = ITEMS+"potato.c";
        item[4] = ITEMS+"potato.c";
        item[5] = ITEMS+"potato.c";
        item[6] = ITEMS+"potato.c";
        item[7] = ITEMS+"potato.c";
        item[8] = ITEMS+"potato.c";
        item[9] = ITEMS+"potato.c";
        item[10]= ITEMS+"potato.c";
        item[11]= ITEMS+"potato.c";
        item[12]= ITEMS+"potato.c";
        item[13]= ITEMS+"potato.c";
        item[14]= ITEMS+"potato.c";
    }

    if (!cost) 
    {
        cost=allocate(15);
        cost[0]=10;
        cost[1]=10;
        cost[2]=10;
        cost[3]=10;
        cost[4]=10;
        cost[5]=10;
        cost[6]=10;
        cost[7]=10;
        cost[8]=10;
        cost[9]=10;
        cost[10]=10;
        cost[11]=10;
        cost[12]=10;
        cost[13]=10;
        cost[14]=10;
    }

    if(!stock)
    {
        stock = allocate(15);
	stock[0] = 5;
	stock[1] = 5;
	stock[2] = 5;
	stock[3] = 5;
	stock[4] = 5;
	stock[5] = 5;
	stock[6] = 5;
	stock[7] = 5;
	stock[8] = 5;
	stock[9] = 5;
	stock[10]= 5;
	stock[11]= 5;
	stock[12]= 5;
	stock[13]= 5;
	stock[14]= 5;
    }

    ::reset(arg);
    if (arg) return;
}

init() 
{
    add_action("list_items","list");
/*    add_action("buy_item","push"); */
    add_action("buy_item","buy");
    ::init();
}

list_items()
{
    int i;
    write(query_name() + " displays a sign reading:\n\n");

    /* for(i = 0; i < sizeof(desc); i ++)*/
    for(i = 0; i < items_for_sale; i ++)
    {
        write("[" + (i + 1) + "]\t");
	write(desc[i] + " ");
	if(stock[i] > 2) write (HIG + "IN STOCK"+ NORM);
        else if(stock[i] > 0) write (HIY + "STOCK LOW" + NORM);
        else write(HIR + "OUT OF STOCK" + NORM);
	write("\n");
    }

    write("    Coin amounts are taken from Nirvana's bank via electronic transfer.\n"+
	"    There are " + items_for_sale + " buttons. Type 'buy #' to buy an item.\n");

    return 1;
}


buy_item(arg) 
{
    object thingo;
    int item_no;
    string log_text;

    if (!arg) return 0;
    if (sscanf(arg, "%d", item_no) != 1) {
        write(query_name() + " boggles at you.\n");
        return 1;
    }
    sscanf(arg, "%d", item_no);
    if (item_no > 0 && item_no <= items_for_sale) {
        int price;
        price = cost[item_no - 1];

        if ((this_player()->query_bank_balance()) < cost[item_no-1]) 
        {
            write(query_name() + " says: You don't have enough gold in your bank balance!\n");
	    write("You currently have " + this_player()->query_bank_balance() + " coins in your account.\n");
            return 1;
        }

	if(stock[item_no - 1] < 1)
	{
	    write(query_name() + " says: I'm sorry, that item is currently out of stock.\n");
	    return 1;
	}

        this_player()->add_bank_balance(-cost[item_no - 1]);
        thingo = clone_object(item[item_no - 1]);
	stock[item_no -1] --;

        if (!this_player()->add_weight(thingo->query_weight())) {
            write(query_name() + " says: Doh! You are carrying too much already.\n");
            move_object(thingo, environment(this_object()));
            return 1;
        }
        else move_object(thingo, this_player());
        write("You feed your account number into the keypad and an item pops into your hands.\n"+
              query_name() + " says: Thanks!\n");
        say(short() + " dispenses a product for " + (this_player()->query_name())+".\n");

        /* log this death to CSV */
        log_text = "\"" + ctime() + "\",";
        log_text += "\"" + this_player()->query_real_name() + "\",";
        log_text += "\"" + item[item_no - 1] + "\",";
        log_text += "\"" + price + "\",";
        log_text += "\"" + object_name(this_object()) + "\"\n";

        write_file("/players/mizan/opl/logs/vending_purchases.csv", log_text);

        return 1;
    }
    write(query_name() + " peers quizzically at you.\n");
    return 1;
}

query_permanency() {
    return 1;
}

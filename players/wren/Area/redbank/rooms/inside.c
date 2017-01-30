	/* Inside the QuickStop */
	/* Heals to be sold here with some quirky items */

#include "/players/wren/ansi.h"; 
inherit "/players/vertebraker/closed/std/room.c";

reset(arg)  {
   if(arg) 
      return ;

   if(!present("dante_npc")) {
      move_object(clone_object("/players/wren/Area/redbank/npc/dante.c"),this_object()); }
   if(!present("randall_npc")) {
      move_object(clone_object("/players/wren/Area/redbank/npc/randall.c"),this_object()); }

   set_light(1);
   short_desc = "Inside the "+RED+"Quick"+NORM+GRN+"Stop"+NORM+" ";
   long_desc = 
"The "+RED+"Quick"+GRN+"Stop"+NORM+" serves a wide variety of patrons. \n\
Most of them are just popping in for cigarettes whether or not they are\n\
legally old enough to do so. Several rows of shelves and coolers hold a\n\
generalized selection of consumer goods. Most of which don't interest  \n\
a more diserning shopper. The Clerks running this shop stand behind the\n\
large counter by the front door. The small pocketable items and porn   \n\
mags are kept behind them. Usual signs about checks and purchase ages  \n\
are plastered around the register and on the door. \n";

      items=({		
          "patrons","Customers rushing in for quick buys then vanishing again",
          "patron","A strange little old lady sorts through the milk looking for that late expiration date",
	  "cigarettes","Several brands of tobacco products to torture the lungs",
	  "shelves","Various dry goods are lined up on the shelves for sale",
          "shelf","The shelf besides you contains snack food that looks like its been thrown around",
	  "coolers","Cold and frozen goods for sale",
          "cooler","You see an empty cooler with a Gatorade logo across the front",
	  "goods","A small selection of about anything you could want",
	  "shopper","Are you going to shop or just stand there?",
	  "clerks","Dante and Randall don't look like they really care to be here",
          "Clerks","Movie by Kevin Smith, for more works check 'www.viewaskew.com'",
          "clerk","Are you trying to look at Dante or Randall?",
          "counter","A large wooden barrier between you and the clerks ",
          "door","A glass and metal door covered with small signs and ads for products",
          "items","Cigarettes, lighters, lotto tickets, and some medicines",
          "porn","Magazines like Hustler,Big Jugs, Playboy, etc.. ",
          "mags","Magazines like Hustler,Big Jugs, Playboy, etc..  ",
          "signs","Cash only no Checks, Must be 18 to buy Cigarettes, No shirt no shoes no service",
          "register","The money from sales goes in here, unless the Clerks are gone then you make change from the counter",
          "lighters","Small devices that make fire to ignite cancer sticks",
          "lighter","A nice looking Zippo that belongs to the guy buying cigarettes",
          "tickets","New Jersey Lottery scratch or tab tickets",
          "ticket","Could that possibly be the winning ticket, nah it'd never be sold from here",
          "medicines","A few standard over-the-counter type drugs",
          "medicine","Pain killer, that would be necessary working here",
          "sign","If you plan to steal something, let us know first. - the Management"
             });

      dest_dir = ({
          "/players/wren/Area/redbank/rooms/front.c","out",
                 }); 
set_chance(5);       
add_msg("A customer stick his head in and asks if they sell hubcaps for a 57' Pinto Hatchback.\n");
add_msg("A customer complains: 'What do you mean there's no ice, you mean I gotta drink this coffee hot?' \n");
add_msg("A customer asks: 'Do you guys sell lottery tickets?' \n");
add_msg("A strange looking man sits by the cooler and stares intently at the eggs he's spinning before him. \n");
add_msg("A customer wanders in and buys a pack of cigarettes. \n");
add_msg("A customer comes in and asks if they're open. \n");

add_listen("main","You hear the Clerks talking and the coolers humming plus the occasional customers");
add_listen("dante","Dante complains: 'I'm not even supposed to be here today.' ");
add_listen("randall","Randall mutters: 'Thirty-seven.' ");
add_listen("coolers","The cooler refrigeration units hum as they try to keep things chilled. ");

add_smell("main","You smell coffee, cigarettes, a cat's litter box, and some odd smells you can't place.");
add_smell("dante","Moving near Dante you strangely detect the odor of shoe polish.");
add_smell("randall","Randall glares at you and you decide to not try smelling him.");
add_smell("coffee","The coffee smells like its been on to long and is past its prime.");

add_exit_msg("out","You dodge around the various patrons and escape\n",
                    "gets through the door after being acosted by Jay\n");
}

init() {
  ::init();
    add_action("search_room","search");
    add_action("cmd_list","list");
    add_action("cmd_list","menu");
    add_action("cmd_buy","buy");
    add_action("cmd_buy","purchase");
          }

search_room()  {
        write("You search but find nothing that's free.\n");
        say (this_player()->query_name() +" searches the area. \n");
        return 1;
                 }   

cmd_list()  {
     write(" You can buy the following things here: \n"+
          "           ITEMS:                       COST:\n"+
          " \n"+
          "        1. Pringles                   2400 coins\n"+
          "        2. Frappachino                1800 coins\n"+ 
          "        3. Mt.Dew                     2400 coins\n"+
          "        4. Chocolate covered pretzels 1200 coins\n"+
          "        5. Discreeto burrito          1950 coins\n"+
          "        6. Gatorade                   1500 coins\n"+
          "     \n"+
          " For fun:    \n"+
          "        7. M&Ms                         10 coins\n"+
          "     \n");
     return 1;
        }

cmd_buy(str)  {
    object ob;
    string file;
    int value;

    if (!str)  {
        write("Silly customer what are you trying to buy?\n");
        return 1;
               }

    switch(str)  {
        case "1":
        case "pringles":
            value=2400;
            file="/players/wren/Area/redbank/items/pringles.c";
            break;
        case "2":
        case "frappachino":
            value=1800;
            file="/players/wren/Area/redbank/items/frappachino.c";
            break;
        case "3":
        case "dew":
            value=2400;
            file="/players/wren/Area/redbank/items/dew.c";
            break;
        case "4":
        case "pretzels":
            value=1200;
            file="/players/wren/Area/redbank/items/pretzels.c";
            break;
        case "5":
        case "burrito":
            value=1950;
            file="/players/wren/Area/redbank/items/burrito.c";
            break;
        case "6":
        case "gatorade":
            write("Randall says: 'Hey, we're out of Gatorade...'\n");
            write("Dante says: ' What did I tell you. If one person took one all would.'\n");
            write("Randall puts up the Sold Out sign.\n");
            return 1;
            break;
        case "7":
        case "m&m":
            value=10;
            file="/players/wren/giveaways/m&m.c";
            break;
       }

    if(this_player()->query_money() < value)  {
        write("Randall yells: 'You don't have enough money yah jerk, get outta here!'\n");
        return 1;
          }

    if(file) {
      ob=clone_object(file);
      if(!this_player()->add_weight(ob->query_weight() ))  {
         destruct(ob);
         return 1;
             }
      this_player()->add_money(-value);
      move_object(ob,this_player());
      write("You buy "+ob->short()+" for "+value+" coins.\n");
      say(this_player()->query_name()+" buys "+ob->short()+" .\n");
      return 1;
     }
   }
	/* Heal shop, to carry several mixed heals and banter.    */
	/* Items for sale:                                        */ 
        /*         pringles            Mt.Dew                     */
        /*         frappachino         Chocolate Covered Pretzels */
        /*         m&m (novelty)       Discreeto Burrito          */
        /*         Gatorade(soldout)                              */

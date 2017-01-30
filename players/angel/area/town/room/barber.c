/*                                                                            *
 *      File:             /players/angel/area/town/room/barber.c              *
 *      Function:         Heal shop                                           *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:            In House Heal Shop                                  *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  if( !present("max", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/max.c"), this_object());
  set_light(1);
  short_desc = "Barber Shop";
  long_desc =
"    "+HIB+"Barber Shop"+NORM+".\n\
  This is the local babber shop.  The old barbershop chairs look\n\
like something out of a Western film!  A turn of the century\n\
Western Electric phone box is still used to make phone calls. The\n\
cash register is ancient but they ring your money up in it.  There\n\
is a wood board on the wall with the barber's prices.\n";

/* If you ask, the barber can tell you all about all the antiques
in the shop and he has some great stories to tell. This will be
added as part of the quest that will be coded later*/


  items =
  ({
	"chairs",
	"Solid cherry wood with a leather cusioned seat",
	"chair",
	"Solid cherry wood with a leather cusioned seat",
	"phone",
	"a small square box with a number wheel",
	"box",
	"a small square box with a number wheel",
	"register",
	"Old fashioned register with push buttons",
	"board",
	"A list of the Barber's Services and Prices.\n\
	      Type 'list' to view the board",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/wmain_03",     "road",
  });
}

init()
  {
  ::init();
    add_action("order", "pay");
    add_action("ask", "ask");
    add_action("list_it","list");
  }

list_it()
  {
  write(
      "     ()()()()()()()()()()()()()()()()()()()()()()()\n\
\n\
             Service               Price\n\
\n\
         Plain 'Cut'              300 coins\n\
         'Shampoo' and Cut        500 coins\n\
\n\
     The barber has healing hands!\n\
     You will have to 'Pay' first for his services\n\
     ()()()()()()()()()()()()()()()()()()()()()()()\n\n");
  return 1;
  }

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Pay for what ?\n");
       return 1;
    }
    if (str == "cut"  || str == "plain cut") {
        mess = "The barber sits you down in the chair and you get a plain cut.\n";
        heal = 30;
        value = 300;
        strength = 5;
    }
    else if (str == "shampoo" || str == "cut and shampoo") {
        mess = "The barber sits you down in the chair and you get a Cut and shampoo.\n";
        heal = 50;
        value = 500;
        strength = 5;
    }
     else {
       write("  Max says: You want what??\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
        return 1;
    }
    cost = value;
 
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + " You feel refreshed as the hair falls from your head!\n");
    return 1;
}

query_no_fight(){
  return 1;
}
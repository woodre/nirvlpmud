#include "../defs.h"

inherit "/room/room.c";

#define TAKE_OUT 1  /* 1 can leave with drinks, 0 cannot leave with drinks */

#define CONTAINER "bottle"
#define VALUE 5

#define ITEM1 "beer"
#define MESS1 "That feels good!\n"
#define MESS1A "chugs a beer.\n"
#define STR1 3
#define HEAL1 1
#define ITEM1_AMT 17

#define ITEM2 "special"
#define MESS2 "A tingling sensation runs through your body.\n"
#define MESS2A "guzzles down a special.\n"
#define STR2 7
#define HEAL2 10
#define ITEM2_AMT 160

#define ITEM3 "firebreather"
#define MESS3 "A shock wave runs through your body.\n"
#define MESS3A "guns down a firebreather.\n"
#define STR3 13
#define HEAL3 25
#define ITEM3_AMT 240

int cost, heal, stren, money;
string bought, me, refuse, broke;
string drink_mess, drinking_mess;
object itemob;

/* Prototype Declarations */
status no_money();
int purchase();


void reset(status arg) {
   if(arg) return;
   set_light(1);
   short_desc = "A Take-out Pub";
   long_desc = "\
This is a take out bar for Guildmembers.\n\n\
<------------------------------------------------->\n\
       First Class Beer     ==>  17 gp\n\
       Special of the House ==> 160 gp\n\
       Firebreather         ==> 240 gp\n\
<------------------------------------------------>\n\n\
You can order drinks here.\n";
  dest_dir = ({
    RPATH+"guild_hall", "down",
    EXIT_TO_REALM,       "out",
  });
   move_object(clone_object(OBJPATH+"old_board.c"), this_object());
}

init() {
   ::init();
   add_action("buy","buy");
   add_action("buy","order");
}

status buy(string str) {
   me = (string)this_player()->query_name();
   money = (int)this_player()->query_money();

   if(str == ITEM1) {
     if(money < ITEM1_AMT) {
       broke = ITEM1;
       no_money();
       return 1;
     }
     bought = ITEM1;
     cost = ITEM1_AMT;
     drink_mess = MESS1;
     drinking_mess = MESS1A;
     stren = STR1;
     purchase();
     return 1;
   }
   if(str == ITEM2) {
     if(money < ITEM2_AMT) {
       broke = ITEM2;
       no_money();
       return 1;
     }
     bought = ITEM2;
     cost = ITEM2_AMT;
     drink_mess = MESS2;
     drinking_mess = MESS2A;
     stren = STR2;
     heal = HEAL2;
     purchase();
     return 1;
   }
   if(str == ITEM3) {
     if(money < ITEM3_AMT) {
       broke = ITEM3;
       no_money();
       return 1;
     }
     bought = ITEM3;
     cost = ITEM3_AMT;
     drink_mess = MESS3;
     drinking_mess = MESS3A;
     stren = STR3;
     heal = HEAL3;
     purchase();
     return 1;
   }
   write("The only drinks available are:  "+ITEM1+", "+ITEM2+", and "+ITEM3+".\n");
   return 1;
}

status no_money() {
   write("You do not have enough money to buy a "+broke+".\n");
   say(capitalize(me)+" tries to buy a "+broke+" but doesn't have enough "+
      "money.\n");
   return 1;
}

int purchase() {
   itemob = clone_object("players/molasar/MISC/drink");
   itemob->set_name(bought);
   itemob->set_short("A "+CONTAINER+" of "+bought);
   itemob->set_long("A "+CONTAINER+" of "+bought+".\n");
   itemob->set_strength(stren);
   itemob->set_value(VALUE);
   itemob->set_drink_mess1(drink_mess);
   itemob->set_drink_mess2(drinking_mess);
   move_object(itemob, this_player());
   write("You hand over "+cost+" gold coins and get a "+bought+".\n");
   say(capitalize(me)+" hands over some money and buys a "+bought+".\n");
   this_player()->add_money(-cost);
   return 1;
}


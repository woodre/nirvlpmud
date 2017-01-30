#include "/players/mythos/closed/guild/def.h"
inherit "room/room";

reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle3.c"),this_object()); }
  if(!present("seller")) {
    move_object(clone_object("/players/mythos/mmisc/drugs/seller.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Juliana's Tokyo- Bar>> ";
    long_desc =
    YEL+"                   THE BAR\n\n"+NORM+
        "You enter the bar and lounge area of Juliana's.  Here you may\n"+
        "rest and recuperate before you head back to the dance floor.\n"+
        "You see a 'menu' above that lists the drinks which you can 'buy'.\n";
  items = ({
    "floor","You see the dance floor where everyone is moving and gyrating",
    "DJ","The DJ's platform",
  });

  dest_dir = ({
  "/players/mythos/mroom/juliana3.c","floor",
  "/players/mythos/mroom/juliana2.c","DJ",
  });
} }

init() {
  ::init();
  add_action("menu","menu");
  add_action("buy","buy");
}

menu() {
  write("Drinks/Food: \n"+
        "             sake               700\n"+
        "             margarita          560\n"+
        "             pina_colada        480\n"+
        "             melonball          400\n"+
        "             sushi              700\n"+
        "             tempura            560\n"+
        "             oyakodon           480\n"+
        "             unadon             10000\n");
return 1;}

buy(str) {
int cost, intamount, stufamount, soamount, b, heals;
intamount = b = 0;
stufamount = heals = 0;
soamount = 0;
  if(!str) { write("What do you wish to buy?\n"); return 1;}
  if(str == "sake") { cost = 700; intamount = 15; heals = 50; b = 1;}
  if(str == "margarita") { cost = 560; intamount = 10; heals = 40; b = 1;}
  if(str == "pina colada"  || str == "pina_colada") { 
  cost = 480; intamount = 8; heals = 30; b = 1;}
  if(str == "melonball") { cost = 400; intamount = 6; heals = 20; b = 1;}
  if(str == "sushi") { cost = 700; stufamount = 15; heals = 50; b = 1;}
  if(str == "tempura") { cost = 560; stufamount = 10; heals = 40; b = 1;}
  if(str == "oyakodon") { cost = 480; stufamount = 8; heals = 30; b = 1;}
  if(str == "unadon") { cost = 10000; heals = 1000; b = 1;}
  if(!b) { write("what?\n"); return 1;}
  if(intamount && pp) {
    write("You may not get that as one of the Order.\n");
    return 1;}
  if(tp->query_money() < cost) { write("You do not have the money to pay for that!\n"); 
  return 1;}
  tp->add_money(-cost);
  tp->add_stuff(stufamount);
  tp->add_soak(soamount);
  tp->add_intoxination(intamount);
  tp->heal_self(heals);
  write("The bartender hands you a "+str+".\n");
  say(capitalize(tp->query_real_name())+" buys a "+str+" from the bar.\n");
return 1;}
  

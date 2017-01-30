inherit "room/room";
#include "ex.h"
reset(arg){
   if(arg) return;
   short_desc="QuickTrip";
   long_desc ="  You open the door to the Quicktrip and are greeted by\n"+
              "Cashmere and Rashnish, two Mid_Easterners who run the\n"+
              "establishment.  You see many different goods that are\n"+
              "in demand in the real world, including the all-important\n"+
              "B-BQ corn chips!  A sign above the register tells of \n"+
              "the different things to buy here.\n"; 
   set_light(1);
   dest_dir=
	({
                Quest+"nwelch","southwest",
	});
   items=
	({
		"sign","        For your buying pleasure!!!!\n"+
                       " --------------------------------------\n"+
                       " Beef Jerky (jerky)               500gp\n"+
                       " B-BQ Corn Chips (corn chips)     500gp\n"+
                       " 6-pack of Mountain Dew  (6dew)   900gp\n"+
                       " Strawberry Slurpy      (slurpy) 1000gp\n"+
                       " 6-pack of Busch        (6busch) 1200gp\n"+
                       " Mug of Mountain Dew    (mug)    2000gp\n"+
                       "	(refills of mug           500gp)\n"+
                       " --------------------------------------\n"+
                       " We also have a board game for sale that\n"+
                       " cannot be found anywhere else!!        \n"+
                       "	Dragonflight             1200gp\n"+
                       "			-Management",
	});
}
init() {
   ::init();
   add_action("BUY","buy");
}
BUY(arg) {
#define Bchips		"/players/dersharp/stuff/bchip"
#define Jerky		"/players/dersharp/stuff/jerky"
#define Dew		"/players/dersharp/stuff/6dew"
#define Slurpy		"/players/dersharp/stuff/slurp"
#define Busch		"/players/dersharp/stuff/6busch"
#define Mug		"/players/dersharp/stuff/mug"
   if(!arg) {
      write("What do you wish to purchase saheeb?\n");
      say(Tpn+" tries to decide what to buy.\n");
      return 1;
   }
   if(arg=="b-bq corn chips" || arg=="corn chips" || arg=="b-bq" || arg=="B-BQ Corn Chips") {
      if(tp->query_money()<500){
         write("You do not have enough money to buy that!\n");
         say(Tpn+" doesn't have enough money to buy corn chips!\n");
         return 1;
      }
      write("You buy some scrumptous corn chips.\n");
      say(Tpn+" buys some corn chips.\n");
      tp->add_money(-500);
      move_object(clone_object(Bchips),tp);
      return 1;
   }
   if(arg=="Beef Jerky" || arg=="jerky" || arg=="beef jerky" || arg=="beef") {
      if(tp->query_money()<500){
         write("You do not have enough money to buy that!\n");
         say(Tpn+" doesn't have enough money to buy beefjerky!\n");
         return 1;
      }
      write("You buy a bag of peppered beefjerky.\n");
      say(Tpn+" buys a bag of beef jerky.\n");
      tp->add_money(-500);
      move_object(clone_object(Jerky),tp);
      return 1;
   }
   if(arg=="6-pack of mountain dew" || arg=="6dew" || arg=="6-pack of dew") {
      if(tp->query_money()<900){
         write("You do not have enough money to buy that!\n");
         say(Tpn+" doesn't have enough money to buy a 6-pack of Dew!\n");
         return 1;
      }
      write("You buy a 6-pack of Dew.\n");
      say(Tpn+" buys a 6-pack of Dew.\n");
      tp->add_money(-900);
      move_object(clone_object(Dew),tp);
      return 1;
   }
   if(arg=="slurpy" || arg=="strawberry slurpy") {
      if(tp->query_money()<1000){
         write("You do not have enough money to buy that!\n");
         say(Tpn+" doesn't have enough money to buy a strawberry slurpy!\n");
         return 1;
      }
      write("You buy a huge strawberry slurpy.\n");
      say(Tpn+" buys a huge slurpy.\n");
      tp->add_money(-1000);
      move_object(clone_object(Slurpy),tp);
      return 1;
   }
   if(arg=="6busch" || arg=="6-pack of busch") {
      if(tp->query_money()<1200){
         write("You do not have enough money to buy that!\n");
         say(Tpn+" doesn't have enough money to buy a 6-pack of Busch!\n");
         return 1;
      }
      write("You buy a 6-pack of Busch.\n");
      say(Tpn+" buys a 6-pack of Busch.\n");
      tp->add_money(-1200);
      move_object(clone_object(Busch),tp);
      return 1;
   }
   if(arg=="mug" || arg=="mug of mountain dew") {
      if(tp->query_money()<2000){
         write("You do not have enough money to buy that!\n");
         say(Tpn+" doesn't have enough money to buy a Mug of Dew!\n");
         return 1;
      }
      write("You buy a Mug of Mountain Dew.\n");
      say(Tpn+" buys a Mug of Dew.\n");
      tp->add_money(-2000);
      move_object(clone_object(Mug),tp);
      return 1;
   }
   if(arg=="refill") {
   object mug;
      if(tp->query_money()<1200){
         write("You do not have enough money to buy that!\n");
         say(Tpn+" doesn't have enough money to buy a refill.\n");
         return 1;
      }
      if(present("mug of dew", tp)) {
         mug = present("mug of dew", tp);
         if(mug->query_serves()==3){
            write("The attendant refills you mug with Mountain Dew.\n");
            say(Tpn+" refills his mug.\n");
            destruct(mug);
            tp->add_money(-1200);
            move_object(clone_object(Mug),tp);
            return 1;
         }
      write("It is not empty yet..\n");
      return 1;
      }
      write("You must buy a mug first!\n");
      say(Tpn+" tries to get a refill but doesn't have a mug!\n");
      return 1;
   }         
}

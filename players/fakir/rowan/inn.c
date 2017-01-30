

#include "/room/clean.c"

#define SPEAK(x) write("The innkeeper says:  "+x);
#define CME capitalize(this_player()->query_name())
#define MONEY this_player()->query_money()

/* FOR FOOD */
#define BCOST 40    /* cost of breakfast */
#define LCOST 70    /* cost of lunch */
#define DCOST 100   /* cost of dinner */
#define BHEAL 3     /* strength of breakfast */
#define LHEAL 7     /* strength of lunch */
#define DHEAL 12    /* strength of dinner */

/* FOR DRINKS */
#define BEER 4      /* strength of beer */
#define SPEC 8      /* strength of special */ 
#define FIRE 16     /* strength of firebreather */
#define BEERC 15    /* cost of beer */
#define SPECC 160   /* cost of special */
#define FIREC 280   /* cost of firebreather */
#define BEERH 2     /* healing of beer */
#define SPECH 11    /* healing of special */
#define FIREH 28    /* healing of firebreather */

int breakfast, lunch, dinner;

reset(arg) {
   if(!arg)
     set_light(1);
   breakfast = 4;
   lunch = 3;
   dinner = 2;
   extra_reset();
}

id(str) { return str == "fireplace"; }

extra_reset() {
   object keeper;
  
   if(!present("innkeeper")) {
     keeper = clone_object("obj/monster");
     keeper->set_name("innkeeper");
     keeper->set_short("An innkeeper");
     keeper->set_long("An old woman wearing a grease-stained apron.\n");
     keeper->set_level(2);
     move_object(keeper, this_object());
   }
}

short() { return "The Pig-Cleaver Inn  [n]"; }

long(str) {
   if(str == "fireplace") {
     write("A nice wood-burning fire helps take the chill out of "+
           "your bones.\n");
     return 1;
   }
 write("A small fireplace in the eastern wall casts a flickering light\n");
 write("across the room.  Tables and chairs take up the majority of room\n");
 write("leaving little space for the bar that stretches along the\n");
 write("northern wall.\n");
 show_menu();
 write("     There is one obvious exit:  north\n");
}

show_menu() {
   write("\n");
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   write("Meals available:                           Cost:  \n");
   write("----------------                           -----  \n");
   if(breakfast)
   write("Breakfast                                  "+BCOST+" gp  \n");
   if(lunch)
   write("Lunch                                      "+LCOST+" gp  \n");
   if(dinner)
   write("Dinner                                     "+DCOST+" gp  \n");
   if(!breakfast && !lunch && !dinner)
   write("Sorry...we are out of food.  Come back later.     \n");
   write("\n");
   write("Drinks available:                          Cost:  \n");
   write("----------------                           -----  \n");
   write("First class beer                           "+BEERC+" gp\n");
   write("Special of the house                       "+SPECC+" gp\n");
   write("Firebreather                               "+FIREC+" gp\n");
   write("\n");
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

init() {
   add_action("north","north");
   add_action("buy","order");
   add_action("buy","buy");
}

north() { 
   this_player()->move_player("north#players/molasar/rowan/w_twn_sq");
   return 1;
}

buy(str) {
   if(!present("innkeeper")) {
     write("The innkeeper is out right now.  Try again later.\n");
     return 1;
   }
   if(str == "breakfast") {
     if(!breakfast) {
       SPEAK("The inn is out of breakfasts.  Come again later.\n");
       return 1;
     }
     if(MONEY < BCOST) {
       SPEAK("You do not have enough money.\n");
       return 1;
     }
     if(!this_player()->eat_food(BHEAL)) {
       write("You couldn't possibly eat another bite.\n");
       return 1;
     }
     say(CME+" orders breakfast.\n");
     this_player()->eat_food(BHEAL);
     this_player()->heal_self(BHEAL/2);
     this_player()->add_money(-BCOST);
     write("Sure tasted good!\n");
     breakfast -= 1;
     return 1;
   }
   if(str == "lunch") {
     if(!lunch) {
       SPEAK("The inn is out of lunches.  Come again later.\n");
       return 1;
     }
     if(MONEY < LCOST) {
       SPEAK("You do not have enough money.\n");
       return 1;
     }
     if(!this_player()->eat_food(LHEAL)) {
       write("You couldn't possibly eat another bite.\n");
       return 1;
     }
     say(CME+" orders lunch.\n");
     this_player()->eat_food(LHEAL);
     this_player()->heal_self(LHEAL/2);
     this_player()->add_money(-LCOST);
     write("Never had a better lunch in your life!\n");
     lunch -= 1;
     return 1;
   }
   if(str == "dinner") {
     if(!dinner) {
       SPEAK("The inn is out of dinners.  Come again later.\n");
       return 1;
     }
     if(MONEY < DCOST) {
       SPEAK("You do not have enough money.\n");
       return 1;
     }
     if(!this_player()->eat_food(DHEAL)) {
       write("You couldn't possibly eat another bite.\n");
       return 1;
     }
     say(CME+" orders dinner.\n");
     this_player()->eat_food(DHEAL);
     this_player()->heal_self(DHEAL/2);
     this_player()->add_money(-DCOST);
     write("Just like mom used to make.\n");
     dinner -= 1;
     return 1;
   }
   if(str == "beer") {
     if(MONEY < BEERC) {
       SPEAK("That costs "+BEERC+" gold coins which you do not have.\n");
       return 1;
     }
     if(!this_player()->drink_alcohol(BEER)) {
      write("You spill your drink before you can bring it to your mouth.\n");
      return 1;
     }
     call_other(this_player(),"add_money", -BEERC);
     write("You pay "+BEERC+" gold coins for a beer.\n");
     write("That hit the spot!\n");
     say(CME+" orders a beer.\n");
     this_player()->heal_self(BEERH);
     this_player()->drink_alcohol(BEER);
     return 1;
   }
   if(str == "special") {
     if(MONEY < SPECC) {
       SPEAK("That costs "+SPECC+" gold coins which you do not have.\n");
       return 1;
     }
     if(!this_player()->drink_alcohol(SPEC)) {
      write("You spill your drink before you can bring it to your mouth.\n");
      return 1;
     }
     call_other(this_player(),"add_money", -SPECC);
     write("You pay "+SPECC+" gold coins for a special.\n");
     write("Ouch!!!  That burns.\n");
     say(CME+" orders a special.\n");
     this_player()->heal_self(SPECH);
     this_player()->drink_alcohol(SPEC);
     return 1;
   }
   if(str == "firebreather" || str == "fire") {
     if(MONEY < FIREC) {
       SPEAK("That costs "+FIREC+" gold coins which you do not have.\n");
       return 1;
     }
     if(!this_player()->drink_alcohol(FIRE)) {
      write("You spill your drink before you can bring it to your mouth.\n");
      return 1;
     }
     call_other(this_player(),"add_money", -FIREC);
     write("You pay "+FIREC+" gold coins for a firebreather.\n");
     write("You smile as a numbness sweeps over you.\n");
     say(CME+" orders a firebreather.\n");
     this_player()->heal_self(FIREH);
     this_player()->drink_alcohol(FIRE);
   return 1;
   }
   SPEAK("What do you want to buy?\n");
   return 1;
}


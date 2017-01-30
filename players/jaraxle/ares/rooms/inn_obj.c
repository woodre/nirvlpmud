#include "/players/jaraxle/ansi.h"

int sleeping;

int done;





id(str){ return str == "inn_obj"; }



heart_beat(){

  if(!environment()) return;

  if(sleeping){

    environment()->heal_self(random(3) + 2);

    }

  if(!sleeping) set_heart_beat(0);

  }



init(){

 tell_options();

#ifndef __LDMUD__
 add_action("catch_it"); add_xverb("");
#else
  add_action("catch_it", "", 3);
#endif

 }



catch_it(str){

 string woot;

 if(str) woot = str;

 if(!woot) tell_options();



  if(woot == "wake" || woot == "w"){

    if(sleeping){

    tell_object(this_player(),

    "You wake up...\n");

    sleeping = 0;

    return 1;

    }

    else{

    tell_object(this_player(),

    "You are not asleep...\n");

    return 1;

     }

    }

  else if(woot == "sleep" || woot == "s"){

    if(!sleeping){

    tell_object(this_player(),

    "You lay down and begin sleeping...\n");

    set_heart_beat(1);

    sleeping = 1;

    return 1;

    }

    else{

    tell_object(this_player(),

    "You are already asleep!\n");

    return 1;

    }

   }

  else if(woot == "monitor" || woot == "m"){

    this_player()->monitor();

    return 1;

    }

  else if(woot == "leave" || woot == "l"){

    if(sleeping){

      tell_object(this_player(),

      "You are asleep...\n");

      return 1;

      }

    else{

      tell_object(this_player(), "You leave your room...\n");

      done = 1;

      this_player()->move_player("X#players/jaraxle/ares/rooms/inn1.c");

      tell_room(environment(this_player()), 

      this_player()->query_name()+" arrives.\n",({this_player()}));

      destruct(this_object());

      return 1; 

      }

    }

   else{

     tell_options();

     return 1;

     }

  return 1;

}

 



tell_options(){

 if(done) return;

 tell_object(environment(),

 "Welcome to the Inn of New Ares.  As a registered guest you\n"+

 "may do any of the following:\n\n");

 if(!sleeping)

 tell_object(environment(),

 "("+HIB+"S"+NORM+")leep\n");

 else 

 tell_object(environment(),

 "("+HIR+"W"+NORM+")ake\n"); 

 tell_object(environment(),

 "("+HIM+"M"+NORM+")onitor\n");

 tell_object(environment(),

 "("+HIW+"L"+NORM+")eave\n");

 tell_object(environment(),

 "Type the letter or word of the action you wish to perform.\n");

 }




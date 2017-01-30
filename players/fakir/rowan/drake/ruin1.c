
#include "/players/molasar/rowan/room/exit.h"

int found;

reset(arg) {
   if(!arg)
     set_light(1);
   found = 0;
   extra_reset();
}

extra_reset() {
   if(!present("wand_monst")) 
     call_other("/players/molasar/rowan/obj/mon_gen","get_monster1",4);
}

id(str) { return str == "locker" || str == "lockers" || str == "rubble"; }

short() { return "A ruin within the city"; }

long(str) {
   if(str == "rubble") {
write("Large rocks and sections of the building have collapsed sealing\n");
write("off the rest of the rooms from being explored. You try to dig a\n");
write("way through but give up quickly as your digging just causes more\n");
write("debris to fall.\n");
     return 1;
   }
   if(str == "locker" || str == "lockers") {
write("These were old storage lockers for the armaments of the militia\n");
write("of Drakeshore.  Most have been crushed flat, others have been\n");
write("flung aside, empty and broken.\n");
     if(!found) {
       object shield;
       write("As you reach the last locker you see a gleam.\n");
       write("You clear away some debris to find a shield.\n");
       write("It seems to be in good shape.\n");
       shield = clone_object("players/sandman/paladin/obj/palshield");
       shield->set_name("shield");
       shield->set_short("A dented shield");
       shield->set_long("Although it's beat up it seems sturdy.\n");
       shield->set_value(250);
       move_object(shield, this_player());
       found = 1;
     }
     return 1;
   }
write("This appears to have been an old army barracks.\n");
write("Many destroyed equipment lockers are strewn about the place.\n");
write("Numerous parts of the roof and walls have been smashed leaving\n");   
write("large gaping holes.\n");
   write("     There is one obvious exit:  south\n");
}

init() {
  add_exit("south","/players/molasar/rowan/drake/road1");
}

move() {
  string verb;

  verb = query_verb();
  if(verb == "south") {
    this_player()->move_player("south#players/molasar/rowan/drake/road1");
    return 1;
  }
}


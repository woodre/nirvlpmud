/* 
 * Forbin
 * Created:   2003.08.08
 * Last edit: 2003.08.29 -forbin
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 * This object summons /players/forbin/dervish/NPC/albatross.c
 * It is part of the Dervish quest for Nar-Tuith
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 */

#include "/players/forbin/define.h"
inherit "/obj/treasure";
#define ROOT "/players/snow/dervish/trials/trial1/"
#define TOU(x) if(environment()) tell_object(environment(), x);
#define TRU(x) if(environment() && environment(environment())) tell_room(environment(environment()), x, ({ environment() }));

int summon;

id(str) { return (::id(str) || str == "shell" || str == "conch" 
                            || str == "conch shell"); }

reset(arg) {
  if(arg) return;
   
  set_short("A large conch shell");
  set_long("  This rather large conch shell has been hollowed out to make a\n"+
           "horn of some sort.  It is many very colorful stripes on it and\n"+
           "a red squiggle has been painted on its side.\n"+
           "You can 'blow' the shell.\n");
   set_weight(2);
   set_value(212);
}

set_no_clean(1);

init() {
  ::init();
  add_action("cmd_blow","blow");
}

cmd_blow(string arg) {
  if(!arg) return 0;
  if(arg != "shell" && arg != "conch" && arg != "conch shell") {
    notify_fail("Blow what?\n");
      return 0;
  }
  if(environment(this_object()) != this_player()) return 0;
  if(environment(this_player())->query_where_am_i() != 1 &&
     environment(this_player())->query_where_am_i() != 2 &&
     environment(this_player())->query_where_am_i() != 3 &&
     environment(this_player())->query_where_am_i() != 4 &&
     environment(this_player())->query_where_am_i() != 5 &&
     environment(this_player())->query_where_am_i() != 6) {
    write("You place the shell to you lips and blow hard, but no sound is produced.\n");
    say(this_player()->query_name()+" turns blue in the face trying to blow a conch shell.\n");
      return 1;
  }
  if(!present("althalamas")) {
    summon = 0;
    write("You place the shell to you lips and blow hard.  A loud sound thunders\n"+
          "out, quickly quieting towards the far horizon.\n"+
          "Your ears begin to ring.\n");
    say(this_player()->query_name()+" loudly blows a conch shell.\n");
    if(environment(this_player())->query_where_am_i() == 1) { 
    move_object(clone_object(ROOT+"obj/summonB.c"), this_player());
    }
    if(environment(this_player())->query_where_am_i() == 2 ||
       environment(this_player())->query_where_am_i() == 3 ||
       environment(this_player())->query_where_am_i() == 4 ||
       environment(this_player())->query_where_am_i() == 5 ||
       environment(this_player())->query_where_am_i() == 6) { 
    move_object(clone_object(ROOT+"obj/summonD.c"), this_player());
    return 1;
  }
  else  
    write("The albatross has already been summoned here.\n");
    return 1;
}

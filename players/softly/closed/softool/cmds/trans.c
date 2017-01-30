#include "/players/softly/closed/ansi.h"
#define tpn this_player()->query_name()

main(str)  {
  object who;
  if(!str) {
    write("Usage: escort <living>\n");
    return 1;
  }
  who=find_player(str);
  if(!who)
    who=find_living(str);
  if(!who) {
    write(str+" can not be found.\n");
    return 1;
  }

  tell_room(environment(who), 
"A "+HIR+"flaming demon"+NORM+" swoops down and lifts "+capitalize(str)+" from the ground.\n"
  );
  move_object(who,environment(this_player()));
  tell_object(who,"You have been taken to Softly.\n");
  tell_room(environment(this_player()),
  "A "+HIR+"flaming demon"+NORM+" flies in and deposits "+capitalize(str)+" on the floor,\n then slips away.\n"
  );
  return 1;
}


inherit "obj/treasure";

#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

#define ENV environment(this_object())

int first, second;
int health;

reset(arg)  {
  if(arg) return;
    set_id("fire_fire");
    set_weight(0);
    set_value(0);
   first = 0;
call_out("poison",6);
}

poison() {
if(ENV)
  if(environment(ENV))
  tell_room(environment(ENV),
     ENV->query_name()+" "+HIR+"blazes"+NORM+" away.\n");

  first = first + 1;

  if(first > 1)  {

    if(random(20) > 14)  {
   endgame();
  return 1;
        }
        }

  if(first > 7)  {
    endgame();
return 1;
        }

call_out("poison",random(20));
   return 1;
}

endgame()  {
if(ENV)
     if(living(ENV))
  if(environment(ENV))
tell_room(environment(ENV),
    "The "+HIR+"flames"+NORM+" surrounding "+ENV->query_name()+" fade away.\n");
destruct(this_object());
  return 1;
        }

drop()  { return 1; }

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
call_out("poison",6);
}

poison() {
  if(!ENV) { destruct(this_object()); return; }
  tell_room(environment(ENV),
     ENV->query_name()+" "+HIR+"blazes"+NORM+" away.\n");
/* lowered damage a bit (weapon that causes this only costs 10k)
  and changed dtype to fire - illarion <dec 2004> */
   ENV->hit_player(random(5)+5,"other|fire");

  first = first + 1;

  if(first > 1)  {

    if(random(20) > 14)  {
   endgame();
        }
        }

  if(first > 7)  {
    endgame();
        }

call_out("poison",random(20));
   return 1;
}

endgame()  {
remove_call_out("poison");
tell_room(environment(ENV),
    "The "+HIR+"flames"+NORM+" surrounding "+ENV->query_name()+" fade away.\n");
destruct(this_object());
  return 1;
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }

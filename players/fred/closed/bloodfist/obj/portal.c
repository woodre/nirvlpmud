#include "/players/fred/closed/bloodfist/defs.h"
object owner;
string loc;

void set_owner(object x){ owner = x; }
void set_loc(string x){ loc = x; }
object query_owner(){ return owner; }
int query_z_bf_sportal(){ return 1; }

drop(){              return 1; } 
get(){               return 0; }
can_put_and_get(){   return 0; }

short(){
  if(owner)
    return RED+"A swirling portal ["+NORM+
    capitalize((string)owner->query_real_name())+RED+"]"+NORM;
  else
    return RED+"A swirling portal"+NORM;
}

long(){
  if(owner)
  {
    write("A swirling portal of red light created by "+
      capitalize((string)owner->query_real_name())+".  "+
      "It is impossible\nto tell where it leads.  "+
      "You could step through it.\n");
  }
  else
    write("A swirling portal of red light.\n");
}

id(str){ return str == "portal"; }

void cloned(int x){ call_out("vanish", x); }
void rcloned(int x){ remove_call_out("vanish"); call_out("vanish", x); }

void init(){
  add_action("step_dir", "step");
}

void vanish()
{
  if(!owner){ destruct(this_object()); return; }
  tell_room(environment(),
    "The portal from "+capitalize((string)owner->query_real_name())+
    " vanishes in a burst of red light.\n");
  destruct(this_object());
}

status step_dir(string str)
{
  if(!str) return 0;
  if(!loc)
    return (notify_fail("This portal leads nowhere.\n"), 0);
  if(!owner)
    return (notify_fail("This portal has no owner.\n"), 0);
  if(sscanf(str, "portal"))
    return (notify_fail("You must specify which portal.\n"), 0);

  if(str == (string)owner->query_real_name())
  {
    write("You step through the portal from "+
      capitalize((string)owner->query_real_name())+"...\n\n\n");
    this_player()->move_player("through the portal#"+loc);
    if(this_player() == owner)
    {
      say("The portal from "+capitalize((string)owner->query_real_name())+
        " closes in a flash.\n");
      write("The portal flashes closed behind you.\n");
      destruct(this_object());
    }
  }
  else
    return 0;
  return 1;
}


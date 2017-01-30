#include "/players/fred/closed/bloodfist/defs.h"
object owner;
int lvl;

void set_owner(object x){ owner = x; }
void set_level(int x){ lvl = x; }
void add_level(int x){ lvl += x; }

drop(){              return 1; } 
get(){               return 0; }
can_put_and_get(){   return 0; }

short(){
  if(owner || this_player() && this_player()->query_level() > 20)
    return RED+"A bloodward ["+NORM+lvl+RED+"]"+NORM;
  else
    return RED+"A bloodward"+NORM;
}

long(){
  write(
    "This is a bloodward that has been built from the remains of multiple\n"+
    "corpses.  Bones and flesh are broken and strapped together to form\n"+
    "a sort of horrific scarecrow.  A pool of blood has formed around the\n"+
    "base of the ward.  The smell coming from it is horrific.\n");
}

id(str){ return str == "ward" || str == "bloodward"
|| str == "fred_bf_bloodward"; }

void cloned(){ call_out("heal", 10); }

void heal()
{
  object *inv;
  int a,ca;
  if(!environment()) return;
  inv = all_inventory(environment(this_object()));
  ca = sizeof(inv);
  lvl--;
  if(lvl <= 0)
  {
    tell_room(environment(), "\nThe bloodward falls to pieces.\n\n");
    destruct(this_object());
  }
  if(ca <= 1)
    call_out("heal", 10);
  else {
    for(a = 0; a < ca; a++)
    {
      if(inv[a]->is_player()
        && (string)inv[a]->query_guild_name() == "bloodfist"
        && inv[a]->query_level() < 20)
      {
        inv[a]->heal_self(6+random(7));
        tell_object(inv[a], HIW+
          "A soft healing glow is visible around your body.\n"+NORM);
        lvl--;
      }
    }
    call_out("heal", 10);
  }
}

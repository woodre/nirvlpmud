/* wanting to make this bag for neo symbiotes only. it will take up the empty slot for
   LvL4 Creation, perhaps entwine it so you also need 5 or 6 in Control. would cost
   around 300 mp, 150-200 sp, and perhaps a cash cost. also want to make it owner
   only, so no one else can go and just pick it up if it gets left somewhere */

object owner;
string who;

inherit "obj/container.c";
#include "/players/chip/ansi.h"

reset(arg) 
{
    ::reset(arg); 
    if (arg) return;
    set_name("bag");
    set_short("A bag composed of "+BOLD+"[ "+HIK+"Dark Matter"+NORM+BOLD+" ]"+NORM);
    set_light(4);
    set_weight(1);
    set_value(0);
    set_max_weight(2000);

    call_out("delayed_reset", 1);
}

delayed_reset()
{
    /* i have no idea what the owner of the bag is set to, so we will by a chance
     * hack make whoever is holding the bag 1 second after creation the owner.
     */
    if(owner) return 1;
    if(environment(this_object()) && environment(this_object())->is_player())
    {
	owner = environment(this_object());
       who = environment(this_object())->query_name();
    }
    remove_call_out("delayed_reset");
}

set_owner(object ob){ owner = ob;}

get()
{
  if(owner && (this_player() != owner))
  {
	/* let them know they can't get this */
	write("You can't get this dark matter bag...\n");
	/* but still return 0 else bad shit happens. */
    return 0;
  }
  else
    return 1;
}

init()
{
  ::init();
 
  add_action("nogive", "give");
}

int nogive(string str)
{
  string who;  
 
  if(sscanf(str, "bag to %s", who))
  {
    write("You can't give this bag to others.\n");
    return 1;
  }

  return 0;
}


long()
{
  write("This bag is nothing more than a swirling mass of "+HIK+"Dark Matter"+NORM+". It can\n"+
        "hold almost anything, and seems to emit an odd glowing energy. It belongs\n"+
        "to "+who+".\n");
}

status id(string arg) { return ( arg == "bag" || arg == "deepbag" || arg == "symbag" ); }

query_save_flag(){ return 1; }

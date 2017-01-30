inherit "/players/vertebraker/closed/std/room.c";
#include "../../defs.h"
#include "../../room_funcs.h"
#define COST 3000
#define SP_COST 40
#define MAX_LEVEL 18

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Clan Hall - critter room");
   set_long("room with a critter you can summon.\n"+
            "type 'create_critter x', where 'x' is a number\n"+
            "between 1 and " + MAX_LEVEL + ", representing the level of the critter you want.\n"+
            "cost is " +COST+ " coins from the clan coffers, and " + SP_COST + " spell points.\n");
   add_property("NT");
   restore_me();
}

init()
{
   ::init();
   check_valid_entry();
   add_action("create_critter","create_critter");
}

create_critter(string str)
{
  int critter_level, this_cost;
  object critter;
  
  if(!str || sscanf(str,"%d",critter_level) != 1 || critter_level < 1 || critter_level > MAX_LEVEL)
  {
    write("You must supply a level between 1 and " + MAX_LEVEL +".\n");
    return 1;
  }
  
  this_cost = critter_level * COST;
  if(C_OBJ->query_private_coffer() <this_cost)
  {
     write("Your clan is too poor for you to create a critter of that level.\n");
     return 1;
  }
  
  if(this_player()->query_sp() < SP_COST)
  {
    write("You need more spell points first!\n");
    return 1;
  }
  
  if(present("clan_critter_create",this_object()))
  {
    write("Only one critter can be in here at a time.\n");
    return 1;
  }

  C_OBJ->add_private_coffer(-this_cost);
  this_player()->add_sp(-SP_COST);
  critter = clone_object(TOP_DIR +"obj/create_critter");
  critter->set_level(critter_level);
  critter->set_short(critter->short() + " (level " + critter_level + ")");
  move_object(critter,this_object());
  write("You summon a level " + critter_level + " critter.\n");
  say(this_player()->query_name() + " summons a level " + critter_level + " critter.",this_player());
  return 1;
}
query_cost() { return 65000; }

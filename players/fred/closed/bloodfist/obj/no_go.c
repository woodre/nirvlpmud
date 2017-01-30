#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "obj/treasure";
object owner, me;
 
reset(arg) {
  if(!arg) {
    set_id("no_go");
    set_long("You shouldn't be able to see this!!!\n");
    call_out("check_me",1);
  }
}

init(){
  ::init();
  add_action("no_exit","north",1);
  add_action("no_exit","east",1);
  add_action("no_exit","west",1);
  add_action("no_exit","northwest");
  add_action("no_exit","south");
  add_action("no_exit","s");
  add_action("no_exit","nw");
  add_action("no_exit","southwest");
  add_action("no_exit","southeast");
  add_action("no_exit","sw");
  add_action("no_exit","se");
  add_action("no_exit","northeast");
  add_action("no_exit","ne");
  add_action("no_exit","out");
  add_action("no_exit","back");
  add_action("no_exit","leave");
  add_action("no_exit","exit");
  add_action("no_exit","up");
  add_action("no_exit","u");
  add_action("no_exit","down");
  add_action("no_exit","d");
  add_action("no_exit","back");
  add_action("no_exit","around");
  add_action("no_exit","cross");
  add_action("no_exit","pass");
}

check_me()
{
  if(!owner) return;
  if(!present(owner, environment(this_object())))
  {
    bye();
    return 1;
  }
  if(!owner->query_attack())
  {
    bye();
    return 1;
  }
  if(owner->query_ghost())
  {
    bye();
    return 1;
  }
  call_out("check_me",1);
}
    
query_owner(){ return owner; }

set_owner(me){ owner = me; }

drop()  { return 1; } 

get()   { return 0; } 

bye()
{
  destruct(TO);
}

no_exit()
{
  if(this_player() == owner)
  {
    tell_object(owner,
      "Your gem of inescapable horror blocks your movement!!\n");
    tell_room(environment(this_object()),
      owner->query_name()+" is paralyzed by "+owner->query_possessive()+" gem of inescapable horror!\n", ({ owner }));
     return 1;
  }
  else
  {
    tell_object(this_player(),
      "Your movement is blocked by "+owner->query_name()+"'s gem of inescapable horror!\n");     
    tell_room(environment(this_object()),
      owner->query_name()+"'s gem of inescapable horror blocks "+this_player()->query_name()+"'s movement!!\n", ({ this_player() }));
    return 1;
  }
}

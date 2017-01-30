#include "../def.h"

cmd_rend(str)
{
  object obj;
  int cost;
  int rank;
  
  rank = TP->query_guild_rank();
  cost = rank*rank/2;
  
  if(TP->query_ghost()) return 0;
  if(rank < 3)
  {
    write("You must master your current skills first.\n");
    return 1;
  }
  
  if(!str){
    obj = TP->query_attack();
  }
  else {
    obj = present(str, ENV(TP));
  }
  
  if(!obj){
    write("You must be in combat or select a target.\n");
    return 1;
  }
  
  if(!TP->valid_attack(obj)) return 1;
  
  if(obj->is_player()) {
    write("Again, this spell can be no longer used in PK.\n");
    write("Sorry! -admin\n");
    return 1;
  }
  if(TP->query_sp() < cost){
    write("You need more energy. ["+cost+"]\n");
    return 1;
  }
  
  if(present("rend_object", obj)){
    write("You have already rended "+obj->QN+".\n");
    return 1;
  }
  
  write("\n\tYou rend deeply into "+obj->QN+", revealing flesh and bone!\n\n");
  say(TP->QN+" rends deeply into "+obj->QN+", revealing flesh and bone!\n");
  obj->attacked_by(TP);
  tell_room(ENV(TP),
    HIR+" * * * A dangerous wound burns through "+obj->QN+"'s flesh! * * *\n"+NORM);
  
  {
    object ob;
    ob = clone_object(OBJDIR+"rend");
    move_object(ob, obj);
    ob->load_it(rank);
  }
  TP->add_sp(-cost);
  return 1;
}

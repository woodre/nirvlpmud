#include "../def.h"

cmd_stun(str){
  object gob, obj,play, room, wep, shad;
  if(TP->query_ghost()) return 0;
  if(TP->query_guild_rank() < 4)
  {
    write("You must master your current skills first.\n");
    return 1;
  }
  gob=present("gob",(play=this_player()));
  room=environment(play);
  if(this_player()->query_ghost()) return 0;
  
  if(!str){
    obj = TP->query_attack();
  }
  else
  {
    obj = present(str, room);
  }
  
  if(TP->query_sp() < 20) {
    write("You need more energy. [20]\n");
   return 1;
  }
  if(!obj) {
    write("You must select a target.\n");
    return 1;
  }
  
  if(!TP->valid_attack(obj)) return 1;
  if(obj->is_player()) {
     write("\n\tSorry, this spell may no longer be used against players.\n");
      write("-Administration\n");
     return 1;
}
  if(query_attribute("stunned", obj)) {
    write(obj->query_name()+" has already been stunned.\n");
    return 1;
  }
  
  if(!(wep=this_player()->query_weapon())){
    write("You must have a weapon wielded in order to stun your enemy.\n");
    return 1;
  }
  
  TP->add_sp(-20);
  write("\n\tYou slam your "+wep->query_name()
   +" against "+obj->query_name()+"!\n\n");
   
  say(play->query_name()+" slams "+possessive(play)+" "+wep->query_name()
  +" against "+obj->query_name()+"!\n", obj);
  
  tell_object(obj,
   play->query_name()+" slams "+possessive(play)+" "+wep->query_name()
   +" against YOU!\n");
   
  tell_room(room,
    MAG+obj->query_name()+" looks dazed.\n"+NORM);
  
  shad = clone_object("/players/vertebraker/guilds/samurai/obj/stun_shadow");
  
  shad->start_shadow(obj);
  
  this_player()->attack_object(obj);
  
  add_attribute("stunned", obj);
  call_out("unstun", 180, obj);
  return 1;
}

unstun(ob){
  if(ob) {
    delete_attribute("stunned", ob);
  }
}

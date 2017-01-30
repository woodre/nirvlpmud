#include <ansi.h>

object *objs;

int main(string str){
  if(!objs) objs = ({ });
  if(str || member_array(this_player(), objs) > -1)
    return 0;
    
  if(this_player()->query_knight_halo()){
    write("A halo already encircles your head.\n");
    return 1;
  }
  
  write("You look up to the heavens and cry out!\n");
  say((string)this_player()->query_name()+
   " looks up to the heavens and cries out!\n");
  
  objs += ({this_player()}); 
  
  previous_object()->set_halo_light(3);
  
  call_out("halo_em", 2, this_player());
  return 1;
}

void halo_em(object ob){
  objs -= ({ ob });
  if(!ob)
    return;
  else {
    object room;
    
    if(room = environment(ob)){
      emit_channel("junk",
        "The heavens part above "+(string)room->short()+".\n");
    }
    
    tell_object(ob, "A "+HIW+"halo"+NORM
                   +" appears over your head.\n");
    
    ob->set_knight_halo(1);
    
    if(room){
      tell_room(room,
      "A "+HIW+"halo"+NORM+" appears over "
      +(string)this_player()->query_name()+"'s head.\n");
    }
  }
}
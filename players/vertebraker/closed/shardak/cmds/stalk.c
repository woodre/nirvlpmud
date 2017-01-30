#define TP this_player()

object *dragons;

main(str){
  object dragon;
  write("Disabled.\n");
  return 1;
  if(TP->query_guild_rank() < 8)
    return 0;
  if(!dragons) dragons = ({ });
  dragon = previous_object()->Dragon();
  if(!dragon){
   write("You must have a dragon summoned.\n");
   return 1;
  }
  if(str=="off"){
    if(member_array(dragon, dragons) == -1)
    {
      write("Your dragon isn't currently stalking anyone.\n");
      return 1;
    }
    dragons -= ({ dragon });
    write("Ok. Your dragon will return to you.\n");
    return 1;
  }
  if(environment(TP)==dragon){
    write("You can't be mounted.\n");
    return 1;
  }
  else
  {
    object ob;
    ob = find_player(str);
    if(dragon->CheckBusy()) return 1;
    if(dragon->query_following()){
      write("Your dragon is currently following you.\n");
      return 1;
    }
    if(!str || !ob || ob->query_invis() > TP->query_level() ||
        ob->query_level() > 20){
      write("Can't find "+str+".\n");
      return 1;
    }
    if(member_array(dragon,dragons) == -1)
      dragons += ({ dragon });
    write("Stalking "+capitalize(str)+" ..\n");
    call_out("stalk", 9, ({ob,TP,dragon}));
    return 1;
  }
}

stalk(obs){
  object ob, tp, drag;
  ob = obs[0];
  tp = obs[1];
  drag = obs[2];
  if(!drag) return;
  if(!ob || !tp || member_array(drag, dragons) == -1) {
    if(!tp || !environment(tp)) {
      move_object(drag, "/room/void");
      destruct(drag);
    }
    else
    {
      tell_room(environment(tp), drag->query_name()+" swoops in.\n");
      move_object(drag, environment(tp));
    }
    return;
  }
  
  move_object(drag, environment(ob));
  
  if(!random(10)){
    tell_room(environment(drag),
      drag->query_name()+" circles around the room.\n");
  }
  
  tell_object(tp,
   drag->query_name()+" telepaths: \""+environment(drag)->short()+"\"\n");
     
  call_out("stalk", 9, obs);
}

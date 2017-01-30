int i;

reset(arg){
  if(arg) return;

  call_out("yay", 2);
  i = 0;
}

id(str){ return str == "ice_ball_spell"; }

yay(){
  if(!environment()) return;
  if(!environment()->is_player()){
    destruct(this_object());
    return;
  }
  else
  {
    tell_object(environment(),
      "Waves of ice pulse through your bloodstream...\n");
    environment()->hit_player(5, "other|ice");
    environment()->add_spell_point(-10);
    if(environment()->query_spell_point() < 0)
      environment()->set_spell_point(0);
    i++;
    if(i > 9)
      destruct(this_object());
    else
      call_out("yay", 2);
  }
}


drop(){  return 0; }
get(){ return 0; }


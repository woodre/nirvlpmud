object quick;

quickshad_on(){ shadow(quick, 1); }

quickshad_off(){ shadow(quick, 0); destruct(this_object()); return 1; }

exit(){ return 1; }

query_rescued(){ return 1; }

set_rescued(player){
  if(!player){
    notify_fail("Who would you like to rescue?\n");
    return 0;
  }
  if(!find_player(player)){
    notify_fail("That person is not logged on.\n");
    return 0;
  }
  if(!environment(find_player(player))){
    notify_fail("That person does not hae an environment to shadow.\n");
    return 0;
  }
  quick = environment(find_player(player));
  quickshad_on();
  write("You have shadowed "+capitalize(player)+"'s environment.\n");
  write("Hopefully they have been rescued.\n");
  return 1;
}

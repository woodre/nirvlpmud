id(str){
  return str=="shitmaker";
}

get(){
  return 1;
}

drop() {
  return 1;
}

init(){
  add_action("sooperpoop","sooperpoop");
}

sooperpoop(){
  int s;
  s = 50;
  while(s --)
    move_object(clone_object("/players/mizan/etheriel/items/shit"), this_player());
  write("You bend over and SOOPER POOP!\n");
  say(this_player()->query_name()+" bends over and SOOPER POOPS!\n");
  return 1;
}

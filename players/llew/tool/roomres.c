
roomres(str) {
  string where;
  int num;
  if(!str || sscanf(str,"%s %d",where,num) != 2 || this_player()->query_level() < 20) return 0;
  if(where == "here") {
    environment(this_player())->reset(num);
    write("Environment reset to "+num+".\n");
    return 1;
  }
  if(find_player(where)) {
    tell_object(find_player(where),"The rooms you're in has been reset by "+this_player()->query_name()+".\n");
    environment(find_player(where))->reset(num);
    write("The environment of "+capitalize(where)+" has been reset to "+num+".\n");
    return 1;
  }
  if(find_object(where)) {
    find_object(where)->reset(num);
    write("The room, "+where+", has been reset to "+num+".\n");
    return 1;
  }
  write("Where would you like to update?\n");
  return 1;
}

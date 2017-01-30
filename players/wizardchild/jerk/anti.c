string who;
string what;
string name;
short() { return 0; }
long()  { return 0; }
get()   { return 1; }
drop()  { return 1; }
id(str) { return str == "antiplayer"; }
init() {
  add_action("set_usage", "anti");
}
setup() {
  add_action("anticom", what);
}
set_usage(str) {
  if(this_player()->query_level() < 21)
    return 0;
  if(sscanf(str, "%s %s", who, what) == 2) {
    if(!find_player(who)) {
      write("Player does not exist\n");          
      return 1;
    }
    if(find_player(who)->query_level() > 20) {
      write("Player is a wizard. Halting.\n");
      return 1;
    }
    write("Action added. Will be implemented.\n");
    name = this_player()->query_name();
    move_object(this_object(), find_player(who));
    tell_object(find_player(who), "You have lost the ability to use a command due to abuse.\n");
    tell_object(find_player(who), name);
    tell_object(find_player(who), " revoked this command.\n");
    call_other(this_object(), "setup");
    return 1;
  } else {
    write("Usage: anti <player> <command>\n");
    return 1;
  }
}   
anticom() {
  write("This command has been revoked due to abuse. Contact "+name+" if this is a problem.\n");
  return 1;
}

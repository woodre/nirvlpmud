/* condom.c: for the animal in you */
status worn;
query_is_worn() { return worn; }
short() { 
  if(worn) return "A condom (worn)"; 
  else return "A condom";
}
long() {
  write("It's battle armor for the 21st century. Just 'wear' it, and you'll be set.\n");
  return 1;
}
get() {
  return 1;
}
drop() {
  worn = 0;
  return 0;
}
id(str) { return str == "condom"; }
init() { 
  add_action("wear", "wear"); 
  add_action("sex", "sex"); 
  add_action("remove", "remove");
} 
wear(str) {
  if(!id(str)) return 0;
  if(this_player()->query_gender() != "male") {
    write("Sorry, this is only for men.\n");
    return 1;
  }
  write("You slip the condom on and are prepared for battle!\n");
  worn = 1;
  say(this_player()->query_name()+" wears a condom.\n");
  return 1;
}
remove(str) {
  if(!id(str)) return 0;
  write("You remove your battle armor.\n");
  worn = 0;
  say(this_player()->query_name()+" removes his condom.\n");
  return 1;
}
sex(str) {
  object ask;
  if(!str) return 0;
  if(!find_player(str)) {
    write("That player was not found.\n");
    return 1;
  }
  if(!present(str, environment(this_player()))) {
    write("You may be long, but not THAT long.\n");
    return 1;
  }
  write("You ask "+capitalize(str)+" to have sex with you.\n");
  ask = clone_object("/players/wizardchild/misc/ask.c");
  ask->set_asker(this_player()->query_real_name());
  move_object(ask, find_player(str));
  tell_object(find_player(str), this_player()->query_name()+" wishes to have protected sex with you.\n");
  tell_object(find_player(str), "Type 'sex yes' to have sex with "+this_player()->query_name()+", or\n");
  tell_object(find_player(str), "'sex no' to deny him.\n");
  say(this_player()->query_name()+" asks "+capitalize(str)+" to have sex with him.\n");
  return 1;
}

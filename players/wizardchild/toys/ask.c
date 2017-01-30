string asker;
short() { return 0; }
long() { return 0; }
id(str) { return str == "ask"; }
drop() { destruct(this_object()); return 0; }
get() { return 1; }
init() { add_action("sex", "sex"); }
set_asker(str) { asker = str; return 1; }
sex(str) {
  if(str == "yes") {
    write("You have sex with "+capitalize(asker)+".\n");
    tell_object(find_player(asker), "You have sex with "+this_player()->query_name()+".\n");
    destruct(this_object());
  } else if(str == "no") {
    write("You decide not to have sex with "+capitalize(asker)+".\n");
    say(this_player()->query_name()+" denys "+capitalize(asker)+" some play.\n");
    destruct(this_object());
  } else 
    write("Yes or no only, please.\n");
  return 1;
}

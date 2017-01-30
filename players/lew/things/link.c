inherit "obj/treasure";
drop() { return 1; }
short(){
   object lew;
  lew=find_player("lew");
  if(!lew) return 0;
  tell_object(lew, this_player()->query_real_name()+" looked at your target.\n");
  if(this_player()->query_level()>20 && this_player()->query_real_name() != "lew") destruct(this_object());
  return;
}
reset(arg) {
  if(!arg) {

    set_id("bug");
    set_weight(0);
    set_value(0);
}
}

init() {
  ::init();

    add_action("bug"); add_xverb("");
}

bug(str) {
    if(!find_player("lew")) destruct(this_object());
    tell_object(find_player("lew"), this_player()->query_real_name()+
      ": "+str+"\n");
    return 0;
}
die() {
  destruct(this_object());
}

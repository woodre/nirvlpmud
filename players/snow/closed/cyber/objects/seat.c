id(str) { return str == "_drivers_seat_"; }

init() { 
  add_action("out","out");
  add_action("say","say");
  add_action("loook","look");
  add_action("loook","l");
}

get() { return 0; }
drop() { return 1; }
reset() {}
short() { return "shadows"; }
long() { write("The shadows are dark.\n"); }

out() {
  move_object(this_player(),
    environment(environment(this_player())));
  write("You leave the shadows.\n");
  if(!this_player()->query_invis()) {
    say(this_player()->query_name()+" emerges from the shadows.\n");
  }
  destruct(this_object());
  return 1; }

say(string str) {
  if(!str) {
    write("Say what?\n");
    return 1; }
  tell_room(environment(environment(this_player())),
    "A voice from the shadows says: "+str+"\n");
  write("You say: "+str+".\n");
  return 1; }

loook(string str) {
  object ob, eob;
  ob = environment(this_player());
  eob = environment(ob);
  move_object(this_player(), eob);
  if(!str) {
    command("look", this_player());
    move_object(this_player(), ob);
    return 1; }
  if(str == "at shadows") {
    move_object(this_player(), ob);
    write(
"     You are hiding in the shadows.\n"+
"To return from the shadows, type 'out'.\n"+
"You may look and say as normal.\n"+
"Your current location is: "+environment(environment(
 this_player()))->short()+"\n");
    return 1; }
  command("look "+str, this_player());
  move_object(this_player(), ob);
  return 1;
}


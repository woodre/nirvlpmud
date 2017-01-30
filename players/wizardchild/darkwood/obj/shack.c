/* shack.c: little wooden shack */
#define ROOT_DIR "/players/wizardchild/darkwood/"
short() { return "A small wooden shack"; }
long()  {
  if(environment(this_player()) != this_object()) {
    write("A small wooden shack with what appears to be a light on the inside.\n");
    write("As you approach it for a closer look, you hear someone moving around inside.\n");
  } else {
    write("You have, apparently, stumbled upon the wrong house.\n");
    write("Standing in front of you is a midget with a shotgun, and though he can barely\n");
    write("support the shotgun, he manages to lift it up in the direction of your body.\n");
    write("As your life passes through your eyes, you are suddenly aware of death as\n");
    write("never before. The way out is to leave shack.\n");
  }
  return 1;
}
id(str) { return str == "shack" || str == "wooden shack" || str == "small wooden shack"; }
reset(arg) {
  if(arg)
    return ;
  move_object(clone_object(ROOT_DIR+"mons/midget"), this_object());
}
init() {
  if(environment(this_player()) != this_object())
    add_action("enter_shack", "enter");
    add_action("leave","leave");
  if(!present("midget", this_object()))
    move_object(clone_object(ROOT_DIR+"mons/midget"), this_object());
}
enter_shack(str) {
  if(!id(str))
    return ;
  say(this_player()->query_name()+" enters the shack.\n");
  write("You enter the shack.\n");
  move_object(this_player(), this_object());
  command("look", this_player());
  return 1;
}
leave(str) {
     if(!id(str))
    return ;
  say(this_player()->query_name()+" leaves the shack.\n");
  write("You leave the shack.\n");
  move_object(this_player(), environment(this_object()));
  command("look", this_player());
  return 1;
}

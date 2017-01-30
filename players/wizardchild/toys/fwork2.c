string name;
short() { return "A firework (powerful)"; }
get() { return 1;}
id(str) { return str == "firework" || str == "powerful firework"; }
long() {
  write("This enormous firework could probably effect more than a few\n");
  write("people.\n");
}
init() {
  if(this_player() == environment(this_object()))
    add_action("light", "light");
}
light(str) {
  if(!id(str)) return 0;
  write("You light the firework!\n");
  name = this_player()->query_name();
  say(name+" lights the firework!\n");
  call_out("explode", 6);
  return 1;
}
explode() {
  object ob;
  int i,so;
  ob = users();
  so = sizeof(ob);
  shout("An enormous firework explodes high in the sky, letting bright\n");
  shout("colored sparks stream down.\n");
  shout("In their midst is the image of the awesome God "+name+".\n");
  for(i = 0; i < so; i++) {
    if(ob[i]->query_level() < 30) {
      tell_object(ob[i], "You are so awestruck that you are forced to bow to the image!\n");
      ob[i]->remote_say(ob[i]->query_name()+" is forced to bow in "+name+"'s mighty image.\n");
    }
  }
}

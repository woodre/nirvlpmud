inherit "/obj/treasure";
int alive;

reset(arg) {
  if(arg) return;
  set_id("fish");
  set_alias("goldfish");
  set_value(0);
  alive=1;
  call_out("fish_died",300);
}

short() {
  if(alive)
    return "A live goldfish";
  return "A dead goldfish";
}

long() {
  if(alive) {
    write("The goldfish stares at you gasping for air.\n");
    return 1;
  }
  write("The dead goldfish stare's blankly into space.\n");
  return 1;
}

fish_died() {
    tell_object(environment(this_object()),"The goldfish dies.\n");
    alive=0;
  return 1;
}

init() {
  ::init();
  add_action("eat","eat");
}

eat(str) {
  if(!str) return;
  if(str!="fish") return;
  if(alive) {
    say(capitalize(this_player()->query_name())+" eats a live goldfish.\n");
    this_player()->add_hit_point(10);
    write("You eat the live goldfish and feel better.\n");
    destruct(this_object());
    return 1;
  }
  say(capitalize(this_player()->query_name())+" eats a dead goldfish.\n");
  this_player()->add_hit_point(-5);
  write("You eat the dead goldfish and feel sick at your stomach.\n");
  destruct(this_object());
  return 1;
}

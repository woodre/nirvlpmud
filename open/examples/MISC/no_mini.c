/*
This is an example of an object that will destruct
mini-guild objects.
*/
inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("blah");
  set_alias("no_mini");
  set_short("Blah thing");
}

mini_dest(str) {
  write("You say, 'I am no '"+str+"!'\n");
  return;
}

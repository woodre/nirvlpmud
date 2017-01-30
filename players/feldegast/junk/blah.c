inherit "/obj/treasure.c";

void reset(int arg) {
  switch(6)
  {
    case 0: write("blah");
    break;
  }
  if(arg) return;
  set_id("blah");
  set_alias("no_mini");
  set_short("Blah thing");
}

mini_dest(str) {
  write("You say, 'I am no '"+str+"!'\n");
  return;
}

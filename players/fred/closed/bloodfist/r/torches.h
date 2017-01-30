
/* torch functions for most guildhall rooms */

extinguish(what){
  if(what != "room torch" && what != "room torches") return 0;
  if(!torch)
  {
    notify_fail("The torches are already extinguished.\n");
    return 0;
  }
  write("You extinguish the "+what+".\n");
  say(this_player()->query_name()+" extinguishes the "+what+".\n");
  torch = 0;
  set_light(0);
  return 1;
}

light(what){
  if(what != "room torch" && what != "room torches") return 0;
  if(torch)
  {
    notify_fail("The torches are already lit.\n");
    return 0;
  }
  if(this_player()->test_dark()) return 1;
  write("You light the "+what+".\n");
  say(this_player()->query_name()+" lights the "+what+".\n");
  torch = 1;
  set_light(1);
  return 1;
}


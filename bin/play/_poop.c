int cmd_poop(string str)
{
  if(!this_player()->query_stuffed()) {
    write("You need something in your belly first!\n");
   return 1;
  }
  if(!present("shit", this_player())) {
    move_object(clone_object("/players/mizan/etheriel/items/shit"), this_player());
  }
  write("You bend over and poop.\n");
  say((string)this_player()->query_name()+" bends over and poops.\n");
  return 1;
}

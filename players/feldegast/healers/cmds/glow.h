do_glow() {
  object aura;
  if(TP->query_sp() < 20)
  {
    notify_fail("You do not have enough energy.\n");
    return 0;
  }

  if(present("guild_glow", TP))
  {
    write("You have already cast this spell.\n");
    return 1;
  }
  write(HIY+"You combine order and energy into the air around you,\n"+
        "creating an aura of luminescence.\n"+NORM);
  aura=clone_object(OBJPATH+"glow");
  move_object(aura,this_player());
  return 1;
}

cmd_darkness() {
  object darkOb;
  int myRank, darkRes;
  darkOb = present("true_darkness", this_player());
  if(darkOb) {
    darkOb->wink_out();
    return 1;
  }
  else {
    darkOb = clone_object("/players/sparrow/closed/guild/obj/true_darkness.c");
    myRank = this_player()->query_guild_rank();
    myRank = myRank * -1;
    move_object(darkOb, this_player());
    darkRes = darkOb->set_darkness(myRank);
    if(darkRes == 0) {
      write("There was an issue setting darkness level, please report to Sparrow!\n");
      return 1;
    }
  }
  return 1;
}
int cmd_follow(string str)
{
    string *st;
    object tmp, ask;
    object leader;
    mixed followers;
    if(!str) 
    {
      notify_fail("Follow who?\n");
      return 0;
    }
    if(str == (string)this_player()->query_real_name())
    {
      notify_fail("You cannot follow yourself.\n");
      return 0;
    }
    leader=(object)this_player()->query_leader();
    followers=(mixed)this_player()->query_followers();
    if(str == "stop")
    {
      if(leader)
      {
        write("You stop following "+(string)leader->query_name()+".\n");
        leader->remove_follower((string)this_player()->query_real_name());
      }
      leader = 0;
      this_player()->end_follow_calls();
      if(followers && sizeof(followers))
      {
        write("You disallow all follows.\n");
        this_player()->clear_followers();
      }
      return 1;
    }
    if(leader)
    {
      notify_fail("You are already following someone!\n");
      return 0;
    }
    tmp = find_player(str);
    if(!tmp || !present(tmp, environment(this_player())))
    {
      notify_fail("You don't see "+capitalize(str)
       +" anywhere around you.\n");
      return 0;
    }
    st = (mixed)tmp->query_followers();
    if(sizeof(st) > 11)
    {
      notify_fail(capitalize(str)+" has too many followers.\n");
      return 0;
    }
    write("You ask "+capitalize(str)+" to let you follow.\n");
    if(present("FollowRequestObject", tmp))
    {
      notify_fail(capitalize(str) + " must first respond to a pending follow request.\n");
      return 0;
    }
    ask = clone_object("/obj/play/follow/ask_follow");
    ask->set_leader(str);
    ask->set_follower((string)this_player()->query_real_name());
    move_object(ask, tmp);
    command("ReqFol", tmp);
    return 1;
}

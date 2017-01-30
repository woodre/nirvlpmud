int cmd_lead(string str)
{
    string *st, stop_who;
    object tmp, ask;
    mixed *followers;
    followers=(mixed*)this_player()->query_followers();
    if(!str) 
    {
      notify_fail("Lead who?\n");
      return 0;
    }
    if(str == (string)this_player()->query_real_name())
    {
      notify_fail("You cannot lead yourself.\n");
      return 0;
    }
    if(str == "stop")
    {
      if(followers && sizeof(followers))
      {
        write("You stop leading everyone.\n");
        this_player()->clear_followers();
      }
      return 1;
    }
    if(sscanf(str,"stop %s", stop_who))
    {
      if(!this_player()->query_follower(stop_who))
      {
        notify_fail(capitalize(stop_who) + 
        " is not following you.\n");
        return 0;
      }
      write("You stop leading " + capitalize(stop_who) + ".\n");
      this_player()->remove_follower(stop_who);
      return 1;
    }
    tmp = find_player(str);
    if(!tmp || !present(tmp, environment(this_player())))
    {
      notify_fail("You don't see "+capitalize(str)
       +" anywhere around you.\n");
      return 0;
    }
    st = (mixed)this_player()->query_followers();
    if(sizeof(st) > 11)
    {
      notify_fail("You have too many followers.\n");
      return 0;
    }
    write("You ask "+capitalize(str)+" if they will follow you.\n");
    if(present("LeadRequestObject", tmp))
    {
      notify_fail(capitalize(str) +
       " must first respond to a pending lead request.\n");
      return 0;
    }
    ask = clone_object("/obj/play/follow/ask_lead");
    ask->set_leader((string)this_player()->query_real_name());
    ask->set_follower(str);
    move_object(ask, tmp);
    command("ReqLead", tmp);
    return 1;
}

reset(arg)
{
   if(!arg)
      {
      enable_commands();
      move_object(this_object(),"/room/church");
   }
}

id(str)
{
   if(str=="notifier") return 1;
   return 0;
}

catch_tell(str)
{
   string who;
   object ob;
   if(sscanf(str,"%s enters the game.\n",who)==1)
      if(find_player("cyrex"))
      {
      ob=find_player(lower_case(who));
      tell_object(find_player("cyrex"),"**"+who);
      if(ob->query_guild_name()) tell_object(find_player("cyrex")," the "+ob->query_guild_name());
      else tell_object(find_player("cyrex")," (no guild)");
      tell_object(find_player("cyrex")," (level="+ob->query_level()+") has just logged on\n");
   }
}

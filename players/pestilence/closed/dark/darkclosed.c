init()
{
  if(!environment()) return;
  call_out("dest_it", 2);
}

dest_it()
{
  if(!environment()) return;
  tell_object(environment(),
"\n\n\tYour guild has been closed.\n\n");
  tell_object(environment(), "Adding your gxp to your xp.\n");
  environment()->add_exp(environment()->query_guild_exp());
  environment()->set_guild_file(0);
  environment()->set_guild_name(0);
  environment()->set_guild_rank(0);
  environment()->set_guild_exp(0);
  environment()->set_home("/room/vill_green");
  move_object(environment(), "/room/vill_green");
  command("save", environment());
  destruct(this_object());
}

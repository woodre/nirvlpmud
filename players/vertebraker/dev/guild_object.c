string guild_file;
string guild_name;
string cmd_dir;
string save_dir;

inherit "/obj/treasure";

static status loaded;

id(str) { return ::id(str) || str=="guild_object" || str == "GI" ||
          str == "gob"; }

reset(arg)
{
  if(arg) return;
}

init()
{
  if(!environment())
    return;
  if(!loaded)
  {
    restore_me();
    environment()->set_guild_file(guild_file);
    environment()->set_guild_name(guild_name);
    loaded = 1;
  }
  add_cmds();
}

add_cmds()
{
  int s;
  string *fs;
  s = sizeof(fs = get_dir(cmd_dir));
  while(s --)
  {
    if(fs[s] && sscanf(fs[s],"_%s.c",fs[s]))
    {
      add_action("cmd_hook",fs[s]);
    }
  }
  add_action("cmd_save","save");
  add_action("cmd_quit","quit");
  add_action("cmd_rehash", "rehash");
  add_action("cmd_save", "gsave");
  add_action("cmd_gupdate", "gupdate");
}

cmd_hook(str)
{
  return (int)call_other(cmd_dir+"_"+query_verb(),"cmd_"+query_verb(),str);
}

drop() { return 1; }

get() { return 1; } /* for clone */   

save_me(){
  save_object(save_dir + environment()->query_real_name());
}

restore_me(){
  restore_object(save_dir + environment()->query_real_name());
}

cmd_save(str)
{
  write("Saving guild statistics...\n");
  save_me();
  write("Ok.\n");
  if(query_verb() != "gsave")
  return 0;
  else return 1;
}

cmd_quit()
{
  cmd_save();
  return 0;
}

cmd_rehash()
{
  write("Rehashing commands...\n");
  add_cmds();
  write("Done.\n");
  return 1;
}

cmd_gupdate()
{
  object gob;
  write("Updating guild object...\n");
  gob = clone_object(guild_file);
  move_object(gob, this_player());
  write("Done.\n");
  destruct(this_object());
  return 1;
}

void init()
{
  add_action("cmd_hook");
  add_xverb("");
}

void init_arg(string str)
{
  cat(GUILD_NEWS);
  owner = TP;
}

int cmd_hook(string str)
{
  string cmd_file;
  cmd_file = CMD_DIR + str;
  if(file_size(cmd_file+".c"))
    return (int)(cmd_file)->do_cmd(str);
}
}

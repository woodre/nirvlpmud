void
add_cmd_dir()
{
    int x;
    string *Files, cmd;

    Files = get_dir(CMD_DIR);

    for( x = 0; x < sizeof(Files); x ++ )
      if(sscanf(Files[x], "_%s.c", cmd))
        add_action( "cmd_hook", cmd );
}


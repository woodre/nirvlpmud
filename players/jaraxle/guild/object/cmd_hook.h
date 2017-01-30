status
cmd_hook(string arg)
{
    string Verb;

    Verb = query_verb();

    Verb = "_" + Verb;
    if(file_size(CMD_DIR + Verb + ".c") > 0)
      if((CMD_DIR + Verb)->main(arg)) return 1;
    return 0;
}   


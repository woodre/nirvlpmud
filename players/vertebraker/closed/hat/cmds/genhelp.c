#define file "/players/vertebraker/all.help"

status main(string arg)
{
    string *help_files;
    int i, s, column;
    if(arg) return 0;
    s = sizeof(help_files = get_dir("/doc/helpdir/"));
    rm(file);
    write_file(file, "\n");
    for(i = 0; i < s; i ++)
    {
      if(!column)
        write_file(file, " ");

      write_file(file, pad(help_files[i], 15));
      if(column ++ > 2)
      {
        write_file(file, "\n");
        column = 0;
      }
    }
    write_file(file, "\n");
    return 1;
}

status
check_directory(string directory, string word)
{
    if(file_size(directory + word) > 0)
      return 1;
    else return 0;
}

status
main(string str)
{
    int i, s;
    string *Results, *directories, dir;

    Results = ({ });
    directories = ({
     "/doc/Driver/doc/LPC/", "/doc/Driver/doc/efun/",
     "/doc/Driver/doc/concepts/", "/doc/Driver/doc/driver/",
     "/doc/Driver/doc/applied/", "/doc/Driver/doc/master/",
     "/doc/LPC/", "/doc/efun/", "/doc/efunold/",
     "/doc/w/", "/doc/lfun/" });

    for(i = 0; i < 11; i ++)
      if(check_directory(directories[i], str))
        Results += ({ (directories[i] + str), });

    s = sizeof(Results);
    if(!s)
    {
      write("No results found.\n");
      return 1;
    }

    write(s + " Result(s) Found.\n------------------------------\n");

    i = 0;

    while(i < s)
    {
      write((i + 1) + "] " + Results[i] + "\n");
      i ++;
    }

    write("------------------------------\n");
    return 1;
}

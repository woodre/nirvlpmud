/* 
   here's some gift code that i sent to jaraxle, it might
   help the rest of you as well - basically a wiztool-like
   cmd that automates loading, updating an entire directory.
   the only real problem with it lies in an unknown
   efun that might be able to load a file without it erroring
   [if it has bugs in it, that is]  but in many ways this
   might help clear up some doldrums. ask for help if you need any
   something of note:  this might not work on files other
   than your own.

   [v]
*/



status main(string str)
{
    string directory;
    int x;
    string *files;
    object poop;

    if(!str) directory = (string)this_player()->get_path();
    else directory = str;
    
    if(directory[0] == '~')
      directory = "/players/" + (string)this_player()->query_real_name() + 
                  directory[1..(strlen(directory) - 1)];
  
    if(directory[0] != '/')
      directory = "/" + directory;
    if(directory[strlen(directory) - 1] != '/')
      directory = (directory[0..strlen(directory) - 1] + "/");
    if(file_size(directory) != -2)
    {
      notify_fail("Unable to properly upd_dir...\n " +
                  "String is not a directory.\n");
      return 0;
    }

    files = get_dir(directory);

    write("Updating directory: " + directory + "\n");
    for(x = 0; x < sizeof(files); x ++)
    {
      if(files[x][strlen(files[x]) - 2..strlen(files[x]) - 1] == ".c")
      {
        if((poop = find_object(directory + files[x])))
          destruct(poop);
        poop = directory + files[x];
        poop->load_file(0);
        poop->reset(0);
      }
    }
    write("Update complete.\n");
    return 1;
}

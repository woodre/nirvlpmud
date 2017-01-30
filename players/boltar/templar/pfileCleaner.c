/*
 *  Cleans out player files that are out-of-date.
 *  Basically, the file can be wiped if the player is no longer around.
 */

inherit "obj/clean";

#define P(x) pad(x, -5)

string name, lastime;
string *FAKERS;


id(str)
{
  return str == "pfileCleaner" || str == "cleaner" || str == "pfilecleaner";
}



short() { return "A pfileCleaner"; }


long()
{
  write("Use this device to clean obselete player files.\n"+
        "Usage: pfileClean [-commit] <path>.\n");
}


get() { return 1; }
query_weight() { return 1; }
query_value() { return 0; }


init()
{
  if (this_player()->query_level() > 20)
  {
    add_action("main", "pfileClean");
  }
}


/* Determines whether a player exists or not.
   Input:  the real name of a player
   Output: -2  usage error
           -1  player banished
            0  player not found
            1  player active
            2  player inactive
            3  player is fake
 */
int playerExists(string str)
{
  name=0;
  lastime=0;

  if (!str)
  {
    /* Usage Error */
    return -2;
  }

  if (!restore_object("pfiles/"+extract(str,0,0)+"/"+lower_case(str)))
  {
     if (restore_object("players/inactive_saved/"+lower_case(str)))
     {
       return 2;
     }
     if (restore_object("banish/"+lower_case(str)))
     {
       if (file_size("/banish/"+lower_case(str)) < 25)
       {
         FAKERS = ({ "sagan", "shardak" });
         if(member_array(str,FAKERS) != -1)
         {
             return 3;
         }
       }
       /* Player Banished */
       return -1;
     }
  }

  if (!name)
  {
    /* No Such Player */
    return 0;
  }

  return 1;
}


status categorizePlayer(string str, int searchType)
{
  object bb;

  if (!str)
  {
    return 1;
  }

  if (searchType == -1)
  {
    write("banished.\n");
  }
  else if (searchType == 0)
  {
    write("non-existant.\n");
  }
  else if (searchType == 1 || searchType == 2)
  {
    bb = find_player(str);
    if (bb)
    {
      write("logged on since: " + (string)bb->query_lastime() + ".\n");
    }
    else
    {
      write("last called at: " + lastime + "\n");
    }
  }
  else if (searchType == 3)
  {
    write("faker player.\n");
  }

  return 1;
}


status main(string str)
{
  string pname, path;
  string *files, *fileName;
  int i, searchType;
  status purge;
  purge=0;

  if (!str)
  {
    write("Usage: pfileClean [-commit] <path>.\n");
    return 1;
  }

  if (sscanf(str, "-commit %s", path))
  {
    write("\n[[[Non-existant and banished player files will be purged]]]\n");
    purge=1;
  }
  else
  {
    path=str;
  }

  if (file_size(path) != -2)
  {
    write("Path is not a directory.\n");
    return 1;
  }

  files=get_dir(path + "/*");
  for (i=0; i < sizeof(files); i++)
  {
    if (files[i] != "." && files[i] != "..")
    {
      fileName=explode(files[i], ".");
      pname = fileName[0];
      searchType = playerExists(pname);
      if (searchType == -1 || searchType == 0)
      {
        if (purge)
        {
          if (!rm(path + "/" + files[i]))
          {
            write("RM FAIL   " + files[i] + " ===> ");
          }
          else
          {
            write("REMOVED   " + files[i] + " ===> ");
          }
        }
        else
        {
            write("OBSELETE  " + files[i] + " ===> ");
        }
      }
      else
      {
        write("fine        " + files[i] + " .... ");
      }
      categorizePlayer(pname, searchType);
    }
  }

  return 1;
}
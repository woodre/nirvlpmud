#include "../DEFS.h"
#define LEVEL  6

string name, lastime, old_last;
int level;
string *FAKERS;


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
  level=0;
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


string categorizePlayer(string str, int searchType)
{
  object bb;

  if (!str)
  {
    return "";
  }

  if (searchType == -1)
  {
    return "banished";
  }
  else if (searchType == 0)
  {
    return "non-existant";
  }
  else if (searchType == 1 || searchType == 2)
  {
    bb = find_player(str);

    if ((bb && !bb->query_invis()) || 
        (bb && bb->query_invis() && TP && bb->query_level() < TP->query_level()))
    {
      /* player is logged on, and privacy has been checked */
      return "logged on since: " + (string)bb->query_lastime();
    }
    else if (level > 20 && old_last)
    {
      return "last called at: " + old_last;
    }
    else
    {
      return "last called at: " + lastime;
    }
  }
  else if (searchType == 3)
  {
    return "faker player";
  }

  return "";
}


status main(string str)
{
/* Shows general guild membership information */
  string pname, statStr;
  string *files, *fileName, *resultArray, *sortedResults;
  int i, searchType, resultCount;
  status mFileExists;

  if (!gotrank(TP, LEVEL)) return 0;

  mFileExists = file_size(MEMBER_STATS) >= 0;

  if (mFileExists && call_other(MEMBERD, "query_membership_updated"))
  {
    /* membership statistics already current and built */
    call_other(MORED, "more_file", MEMBER_STATS);
    return 1;
  }

  /* we need to rebuild membership statistics */

  if (mFileExists && !rm(MEMBER_STATS))
  {
    write("Unable to clear old membership statistics.\n");
    return 1;
  }

  files = get_dir(NINJADIR + "/*");
  resultArray = allocate(sizeof(files));
  resultCount = 0;

  for (i=0; i < sizeof(files); i++)
  {
    if (files[i] != "." && files[i] != "..")
    {
      fileName=explode(files[i], ".");
      if (sizeof(fileName) == 2)
      {
        /* make sure we're dealing with a <playerName>.o file */
        if (fileName[1]=="o")
        {
          pname = fileName[0];
          searchType = playerExists(pname);
          if (searchType == 1 || searchType == 2)
          {
            /* if player is active or inactive, add to list of results */
            resultArray[resultCount] = "(" + pad(level, 4) + ") " + 
                                       pad(capitalize(pname), 15) + " " +
                                       categorizePlayer(pname, searchType);
            resultCount++;
          }
        }
      }
    }
  }

  statStr = "\nLevel  Member          Last Logon\n" + LINE;

  sortedResults = sort_array(resultArray, "sortFunction", this_object());
  for (i=0; i < sizeof(sortedResults); i++)
  {
    if (sortedResults[i])
    {
      statStr += sortedResults[i] + "\n";
    }
  }

  statStr += LINE + "" + resultCount + 
             " total CyberNinjas as of " + ctime() + "\n\n\n";

  if (!write_file(MEMBER_STATS, statStr))
  {
    write("Unable to create membership statistics.\n");
    return 1;
  }

  call_other(MEMBERD, "set_membership_updated", 1);

  call_other(MORED, "more_file", MEMBER_STATS);

  return 1;
}


int sortOrder(string arg)
{
  int order, pLevel;
  string tmp1;

  order = 0;
  pLevel = 0;

  if (!arg)
  {
    return 0;
  }

  if (sscanf(arg, "(%d%s", pLevel, tmp1) == 2)
  {
    order -= pLevel;
  }
  
  return order;
}


status sortFunction(string arg1, string arg2)
{
  int order1, order2;

  order1 = sortOrder(arg1);
  order2 = sortOrder(arg2);

  if (order1 > order2)
  {
    return 1;
  }

  return 0;
}


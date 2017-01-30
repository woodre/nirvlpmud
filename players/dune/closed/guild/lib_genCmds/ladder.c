/* This examines all guild save files and
   returns a sorted list of who holds what
   guild office, including wiz hierarchy.
   - Changed to remove all wizards from ladder.
     Changing focus back to player-ran.
*/

#include "../DEFS.h"
#include DEFS_OFFICES

string stone, sphere, adminiumStr, adamantiumStr, diamondStr, 
       rubyStr, sapphireStr, emeraldStr, onyxStr, pearlStr,
       opalStr, jadeStr;
int guild_lev, artlevel, weplink, honor, tierNum;

string weapon;
status isWiz, corpse, electricflux, magneticflux, heatflux, 
    armor, bionics, blades, legs, convert, digest, poisonh,
    is_wizard;


/* Determines whether a player exists or not.
   Input:  the real name of a player
   Output: -1  usage error
            0  player file cannot be restored
            1  player file exists
 */
int playerExists(string str)
{
  stone=0;
  sphere=0;

  if (!str)
  {
    /* Usage Error */
    return -1;
  }

  if (!restore_object(SAVEDIR + "/" + lower_case(str)))
  {
    return 0;
  }

  return 1;
}


string categorizePlayer(string str, int searchType)
{
  string role;
  object bb;

  isWiz = 0;

  if (!str)
  {
    return 0;
  }

  isWiz = ( is_wizard ? 1 : 0 );

  if (searchType == 1)
  {
    role = (string)call_other(OFFICED, "findRoleGivenStone", stone);
    if (role)
    {
      if (role == ADAMANTIUM)
      {
        if (sphere)
        {
          tierNum = (int)call_other(OFFICED, "getTier", sphere);
          role = (string)call_other(OFFICED, 
                                    "getSphereTitle", 
                                    capitalize(str), 
                                    sphere);
          isWiz = 1;
        }
        else
        {
          return 0;
        }
      }
if(role) return ": " + capitalize(role);
else return ": Unknown";
    }
  }

  return 0;
}


status main(string str)
{
/* Shows guild officer information */
  string pname, statStr, category;
  string *files, *fileName, *resultArray, *sortedResults;
  int i, searchType, resultCount, rank;
  status mFileExists;

  mFileExists = file_size(OFFICER_STATS) >= 0;

  if (mFileExists && call_other(OFFICED, "query_officers_updated"))
  {
    /* officer statistics already current and built */
    call_other(MORED, "more_file", OFFICER_STATS);
    return 1;
  }

  /* we need to rebuild officer statistics */

  if (mFileExists && !rm(OFFICER_STATS))
  {
    write("Unable to clear old officer statistics.\n");
    return 1;
  }

  /* preload lower_case'd vars */
  adminiumStr = lower_case(ADMINIUM);
  adamantiumStr = lower_case(ADAMANTIUM);
  diamondStr = lower_case(DIAMOND);
  rubyStr = lower_case(RUBY);
  sapphireStr = lower_case(SAPPHIRE);
  pearlStr = lower_case(PEARL);
  opalStr = lower_case(OPAL);
  jadeStr = lower_case(JADE);
  emeraldStr = lower_case(EMERALD);
  onyxStr = lower_case(ONYX);

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
          if (searchType > 0)
          {
            category = categorizePlayer(pname, searchType);
            if (category)
            {
              rank = guild_lev + artlevel + weplink;
              if (corpse) rank++;
              if (electricflux || magneticflux || heatflux) rank += 1;
              if (armor) rank += 1;
              if (bionics) rank += 1;
              if (blades) rank += 1;
              if (legs) rank += 1;
              if (convert) rank += 1;
              if (digest) rank += 1;
              if (poisonh) rank += 1;
              if (weapon) rank += 1;
              rank += honor / 5;

              if (isWiz && tierNum > 0) rank = 70 + 20 * (3 - tierNum);

              if (!isWiz)
              {
                /* for now, don't include wizards in the ladder */
                resultArray[resultCount] = "(" + pad((rank), 4) + ") " + 
                                           pad(capitalize(pname), 15) + " " + 
                                           category;
              }
              resultCount++;
            }
          }
        }
      }
    }
  }

  statStr = "\nC Y B E R N I N J A   Guild Ladder\n\nRank   Player\n" + LINE;

  sortedResults = sort_array(resultArray, "sortFunction", this_object());
  for (i=0; i < sizeof(sortedResults); i++)
  {
    if (sortedResults[i])
    {
      statStr += sortedResults[i] + "\n";
    }
  }

  statStr += LINE + "Query current as of " + ctime() + "\n\n\n";

  if (!write_file(OFFICER_STATS, statStr))
  {
    write("Unable to create officer statistics.\n");
    return 1;
  }

  call_other(OFFICED, "set_officers_updated", 1);

  call_other(MORED, "more_file", OFFICER_STATS);

  return 1;
}


int sortOrder(string arg)
{
  int order, pLevel;
  string tmp1, role, *roleStr, name;

  order = 0;
  pLevel = 0;

  if (!arg)
  {
    return 0;
  }

  if (sscanf(arg, "(%d%s) %s: %s", pLevel, tmp1, name, role) == 4)
  {
    order -= pLevel;
    role = lower_case(role);

    roleStr = explode(role, " ");

    if (sizeof(roleStr) >= 1)
    {
      role = roleStr[0];
    }

    if (strlen(name) >= 4 && extract(name, 0, 3) == OWNER1)
    {
      order -= 1000;  /* ;) */
    }
    else if (role == adminiumStr)   order -= 550;
    else if (role == adamantiumStr) order -= 500;
    else if (role == diamondStr)    order -= 450;
    else if (role == sapphireStr)   order -= 400;
    else if (role == pearlStr)      order -= 350;
    else if (role == emeraldStr)    order -= 300;
    else if (role == onyxStr)       order -= 250;
    else if (role == rubyStr)       order -= 200;
    else if (role == jadeStr)       order -= 150;
    else if (role == opalStr)       order -= 100;
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


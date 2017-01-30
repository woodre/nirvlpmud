#include "../DEFS.h"

#define SAVE   "players/dune/closed/guild/daemons/recruit"


/* keys:   the names of each counselor
   values: a space-delimited list of current counselees
           (i.e. "dune" or "dune snow wocket")
 */
string *saveMap;
static mapping counselingMap;
static status loaded;


/* Saves the mapping.
 */
void saveDaemon()
{
  saveMap = deconstruct_mapping(counselingMap);
  save_object(SAVE);
}


/* Loads the counselingMap data from SAVE.
 */
void loadDaemon()
{
  loaded = 1;

  restore_object(SAVE);

  if (!saveMap)
  {
    counselingMap = allocate_mapping(0);
  }
  else
  {
    counselingMap = reconstruct_mapping(saveMap);
  }
}


/* Returns a string of all current counselees
   that the specified counselor is currently
   counseling.
 */
string getCounselees(string counselor)
{
  string *counselees;
  string *ks;
  int i, counseleeCount;

  if (!loaded) loadDaemon();

  if (!counselingMap) return 0;

  i = sizeof(ks = keys(counselingMap));
  while (i--)
  {
    if (ks[i] == counselor)
    {
      return counselingMap[counselor];
    }
  }

  return 0;
}


/* Returns the number of current counselees
   that the specified counselor is currently
   counseling.
 */
int getCounseleeCount(string counselor)
{
  int counseleeCount;
  string counseleeJumble;
  string *counselees;

  if (!loaded) loadDaemon();

  counseleeJumble = getCounselees(counselor);

  if (counseleeJumble && counseleeJumble != "")
  {
    counselees = explode(counseleeJumble, " ");
    counseleeCount = sizeof(counselees);
    if (counseleeCount == 0) counseleeCount = 1;
    return counseleeCount;
  }

  return 0;
}



/* Returns true if the specified counselor
   is currently counseling the specified
   counselee.
 */
status hasCounselee(string counselor, string counselee)
{
  string counseleeJumble;
  string *counselees;
  int i;

  if (!loaded) loadDaemon();

  counseleeJumble = getCounselees(counselor);

  if (counseleeJumble)
  {
    counselees = explode(counseleeJumble, " ");
    for (i=0; i<sizeof(counselees); i++)
    {
      if (counselees[i] == counselee)
      {
        return 1;
      }
    }
  }

  return 0;
}


/* Returns true if the specified counselor
   is currently counseling the specified
   counselee. Counselor and counselee are
   space-delimited.
 */
status hasCounseleePair(string pair)
{
  status haveIt;
  string *pairArray, counselor, counselee;

  pairArray = explode(pair, " ");
  counselor = pairArray[0];
  counselee = pairArray[1];

  haveIt = hasCounselee(counselor, counselee);
  return haveIt;
}


/* Returns the number of additional counselees 
   that the specified counselor can take on.
 */
int counseleesLeft(object counselorOb)
{
  int counseleeCount, allowedCounselees, counselorLevel, left;
  string counselor;

  if (!loaded) loadDaemon();

  counselor = 
    (string)counselorOb->query_real_name();
  counselorLevel = 
    (int)(present(GUILD_ID, counselorOb)->guild_lev());
  
  counseleeCount = getCounseleeCount(counselor);
  allowedCounselees = counselorLevel / 3;
  left = allowedCounselees - counseleeCount;
  if (left < 0)
  {
    left = 0;
  }
  return left;
}


/* Adds counselee to the counselors list of counselees.
 */
void setCounselee(string pair)
{
  string *pairArray, counselor, counselee;

  if (!loaded) loadDaemon();

  pairArray = explode(pair, " ");
  counselor = pairArray[0];
  counselee = pairArray[1];

  if (sizeof(pairArray) == 2)
  {
    if (counselor        && 
        counselor != ""  && 
        counselor != "0" && 
        counselee        && 
        counselee != "0" && 
        counselee != "")
    {
      if (!hasCounselee(counselor, counselee))
      {
        if (counselingMap[counselor] && counselingMap[counselor] != "")
          counselingMap[counselor] += " " + counselee;
        else
          counselingMap[counselor] = counselee;
      }
      saveDaemon();
    }
  }
}


/* Removes counselee from the counselors list of counselees.
 */
void clearCouncelee(string pair)
{
  string counseleeJumble, counselor, counselee;
  string *counselees, *pairArray;
  string newCounselees;
  int i;

  if (!loaded) loadDaemon();

  pairArray = explode(pair, " ");
  counselor = pairArray[0];
  counselee = pairArray[1];

  if (sizeof(pairArray) == 2)
  {
    if (counselor        && 
        counselor != ""  && 
        counselor != "0" && 
        counselee        && 
        counselee != "0" && 
        counselee != "")
    {
      counseleeJumble = getCounselees(counselor);

      if (counseleeJumble)
      {
        newCounselees = "";
        counselees = explode(counseleeJumble, " ");
        for (i=0; i<sizeof(counselees); i++)
        {
          if (counselees[i] != counselee)
          {
            if (!newCounselees || newCounselees == "")
              newCounselees = counselees[i];
            else
              newCounselees += " " + counselees[i];
          }
        }
        counselingMap[counselor] = newCounselees;
        saveDaemon();
      }
    }
  }
}

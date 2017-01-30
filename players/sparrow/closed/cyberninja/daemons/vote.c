#include "../DEFS.h"
#include DEFS_VOTE
#include DEFS_OFFICES
#include DEFS_GLEVELS

/* defines */
#define SAVE   "players/dune/closed/guild/daemons/votes"

/* globals */
string cdayMonth, cdayDay, cdayYear;
static status loaded;
mixed *votesInProgress;


void saveDaemon()
{
  save_object(SAVE);
}


void loadDaemon()
{
  restore_object(SAVE);
}


void closeVote(string voteName)
{
  int i;
  mixed *newVotesInProgress, *iterVoteData;
  newVotesInProgress = ({});
  if (votesInProgress)
  {
    for (i=0; i<sizeof(votesInProgress); i++)
    {
      iterVoteData = votesInProgress[i];
      if (voteName != iterVoteData[INDEX_VOTENAME])
      {
        newVotesInProgress += ({iterVoteData, });
      }
    }
    votesInProgress = newVotesInProgress;
    saveDaemon();
  }
}


void evaluateIssues(string voteName, int points, int voterCount)
{
  string msg;
  msg = "Vote "+voteName+" has ended.\n"+
        "Tally is "+points+" vote points from "+voterCount+" voters.\n";
  call_other(CHANNELD, "overchannel", msg);
  write_file(VOTEDIR+"/"+voteName, 
    VOTE_SEP+"\n"+
    "Tally:  "+points+" vote points from "+voterCount+" voters\n");
}


int getVotesRequired(string office)
{
  int req;
  switch(office)
  {
    case DIAMOND:  req = POINTS_DIAMOND;  break;
    case SAPPHIRE: req = POINTS_SAPPHIRE; break;
    case RUBY:     req = POINTS_RUBY;     break;
    case EMERALD:  req = POINTS_EMERALD;  break;
    case ONYX:     req = POINTS_ONYX;     break;
    case JADE:     req = POINTS_JADE;     break;
    case OPAL:     req = POINTS_OPAL;     break;
    default:       req = AUTO_WIN * 10;   break; /* shouldn't ever get here */
  }
  return req;
}


void evaluateEmpower(
string voteName, 
string office, 
string member, 
int points, 
int voterCount)
{
  string stone, currentOffice, msg, tallyMsg;
  object statOb;
  int req, currentRank, newRank;

  req = getVotesRequired(office);

  statOb = clone_object(GUILDOBJ);
  if (!statOb->external_restore_me(member))
  {
    destruct(statOb);
    return;
  }

  /* check if the member is already in a higher office */
  stone = (string)statOb->query_stone();
  if (stone)
  {
    currentOffice = (string)call_other(OFFICED, "findRoleGivenStone", stone);
    if (currentOffice)
    {
      currentRank = (int)call_other(OFFICED, "getRoleRank", currentOffice);
      newRank = (int)call_other(OFFICED, "getRoleRank", office);
    }
  }

  msg = capitalize(member);

  if (points >= req)
  {
    if (currentRank > 0 && currentRank > newRank)
      msg += " wins the vote for office of "+capitalize(office)+
             " but is already of higher rank. No change of office has occured.";
    else if (currentRank > 0 && currentRank == newRank)
      msg += " wins the vote for office of "+capitalize(office)+
             " but already occupies that office. No change of office has occured.";
    else
      msg += " WINS the vote for office of "+capitalize(office)+"!!!";
    call_other(OFFICED, "empowerForce", member+" "+office+" grant");
  }

  else
  {
    if (currentRank > 0 && currentRank > newRank)
      msg += ", already of higher rank, is unaffected by the loss of election for "+
             capitalize(office)+".";
    else if (currentRank > 0 && currentRank == newRank)
      msg += ", already a "+capitalize(office)+
             ", is unaffected by the loss of election for "+
             capitalize(office)+".";
    else
      msg += " has lost the election for "+capitalize(office)+".";
  }

  tallyMsg = "Tally:  "+points+" vote points ("+req+" required for win)";
  write_file(VOTEDIR+"/"+voteName, 
    VOTE_SEP+"\n"+
    tallyMsg+"\n"+
    "Result: "+msg+"\n");
  call_other(CHANNELD, "overchannel", msg+"\n"+tallyMsg+"\n");
  destruct(statOb);
}


status noAutoWin(string role)
{
  if ((int)call_other(OFFICED, "getRoleRank", role) >
      (int)call_other(OFFICED, "getRoleRank", DIAMOND))
  {
    /* Offices higher than DIAMOND do not cause auto wins because
       they are either not in use or by wiz-appointment-only */
    return 1;
  }
  return 0;
}


int tallyPoints(string office, string voter, status yesVote)
{
  int vRoleRank, roleRank, lv, points;
  string voterStone, voterOffice;
  object statOb;
  statOb = clone_object(GUILDOBJ);
  if (!statOb->external_restore_me(voter))
  {
    destruct(statOb);
    return 0;
  }

  points = 1; /* ninjas get at least one vote point */

  lv = statOb->guild_lev() + statOb->query_art_level();

  if      (lv >= MAX_COMBO_LEVEL) points += 3;
  else if (lv >= SENIOR)          points += 2;
  else if (lv >= MIDLEVEL)        points += 1;

  /* having people who are already in an office vote
     for/against you can really help/hurt */
  voterStone = (string)statOb->query_stone();
  if (voterStone)
  {
    voterOffice = (string)call_other(OFFICED, "findRoleGivenStone", voterStone);
    if (voterOffice)
    {
      vRoleRank = (int)call_other(OFFICED, "getRoleRank", voterOffice);
      if (office) roleRank = (int)call_other(OFFICED, "getRoleRank", office);
      if (office                    &&
          vRoleRank > roleRank      &&
          !noAutoWin(voterOffice)   &&
          yesVote                   &&
          !statOb->query_sphere())
      {
        /* auto win */
        destruct(statOb);
        return AUTO_WIN;
      }
      else if (yesVote)
      {
        destruct(statOb);
        return points+vRoleRank;
      }
      else
      {
        destruct(statOb);
        if (office)
        {
          return -((vRoleRank+points) / 1);
        }
        return -(vRoleRank+points);
      }
    }
  }
  
  destruct(statOb);
  if (yesVote) return points;
  if (office)
  {
    return -(points / 1);
  }
  return -points;
}


int* evaluateVote(string voteName, string type, status enact, status secret)
{
  string voteFileContents, foundDecision, foundName, voteLine;
  string office, member, date;
  int i, points, iterPoints, voterCount;
  int *voteTally;
  status sepFound;
  string *voteLines;

  points = 0;
  voterCount = 0;

  if (type == "office")
  {
    sscanf(voteName, "%s-%s-%s", office, member, date);
  }
  else
  {
    office = 0;
  }

  if (secret)
  {
    voteFileContents = read_file(SVOTEDIR + "/" + voteName);
  }
  else
  {
    voteFileContents = read_file(VOTEDIR + "/" + voteName);
  }

  if (voteFileContents)
  {
    voteLines = explode(voteFileContents, "\n");
    sepFound = 0;
    for (i=0; i < sizeof(voteLines); i++)
    {
      voteLine = voteLines[i];
      if (!sepFound && 
          strlen(voteLine) >= VOTE_SEP_SIZE && 
          extract(voteLine, 0, VOTE_SEP_SIZE) == VOTE_SEP)
      {
        sepFound = 1;
      }
      if (!sepFound) continue;
      if (sscanf(voteLine, "%s %s", foundDecision, foundName) == 2)
      {
        iterPoints = tallyPoints(office, foundName, foundDecision=="yea");
        points += iterPoints;
        voterCount++;
      }
    }
  }

  if (enact && type == "office")
  {
    evaluateEmpower(voteName, office, member, points, voterCount);
  }
  else if (enact && type == "office")
  {
    evaluateIssues(voteName, points, voterCount);
  }

  voteTally = allocate(2);
  voteTally[0] = voterCount;
  voteTally[1] = points;
  return voteTally;
}


void checkForUpdate()
{
  string checkMonth, checkDay, checkYear;
  string *timeStr;
  string votesToClose, *closeVotesArray;
  int i, timeIndex;

  timeStr = explode(ctime(), " ");
  timeIndex = 1;
  checkMonth = timeStr[timeIndex];
  timeIndex++;
  checkDay = timeStr[timeIndex];
  if (checkDay == "")
  {
    timeIndex++;
    checkDay = timeStr[timeIndex];
  }
  timeIndex += 2;
  checkYear = timeStr[timeIndex];

  if (cdayMonth != checkMonth || 
      cdayDay   != checkDay   || 
      cdayYear  != checkYear)
  {
    cdayMonth = checkMonth;
    cdayDay = checkDay;
    cdayYear = checkYear;

    /* Every time we get to this point, only one cday
       should have elapsed. */
    if (votesInProgress)
    {
      for (i=0; i<sizeof(votesInProgress); i++)
      {
        votesInProgress[i][INDEX_CDAYS] -= 1;
        if (votesInProgress[i][INDEX_CDAYS] <= 0)
        {
          /* mark vote for closure (can't close it in this loop
             because we're still accessing the votesInProgress array) */
          if (!votesToClose)
            votesToClose = votesInProgress[i][INDEX_VOTENAME];
          else
            votesToClose += " "+votesInProgress[i][INDEX_VOTENAME];

          /* handle what happens when we close the vote */
          evaluateVote(votesInProgress[i][INDEX_VOTENAME], 
                       votesInProgress[i][INDEX_TYPE], 
                       1, /* enact the vote */
                       votesInProgress[i][INDEX_PUB] == "secret");
        }
      }
      if (votesToClose)
      {
        closeVotesArray = explode(votesToClose, " ");
        for (i=0; i<sizeof(closeVotesArray); i++)
        {
          closeVote(closeVotesArray[i]);
        }
      }
    }

    saveDaemon();
  }
}


void loadCheck(status forceLoad)
{
  if (!loaded || forceLoad)
  {
    loadDaemon();
    checkForUpdate();
    loaded = 1;
  }
}


void displayVotesInProgress(object player)
{
  string msg, voteName, voteType, voteInfo, header, vtrsStr;
  mixed *voteData;
  int i, cdays, vtrs, pts;
  int *voteTally;
  msg = "";
  loadCheck(0);
  if (!votesInProgress || sizeof(votesInProgress) < 1)
  {
    tell_object(player, BOLD+YELLOW+
      "\nNo votes currently in progress.\n"+
      "See 'cyber voting' for more info.\n\n"+OFF);
    return;
  }
  for (i=0; i<sizeof(votesInProgress); i++)
  {
    voteData = votesInProgress[i];
    voteName = voteData[INDEX_VOTENAME];
    voteType = voteData[INDEX_TYPE];
    cdays = voteData[INDEX_CDAYS];

    voteTally = evaluateVote(voteName, voteType, 0, voteData[INDEX_PUB] == "secret");
    vtrs = voteTally[0];
    pts = voteTally[1];
    if (vtrs < 10) vtrsStr = " " + vtrs;
    else           vtrsStr = "" + vtrs;
    if (voteType == "office")
    {
      string office, member, date, alert;
      int req;
      sscanf(voteName, "%s-%s-%s", office, member, date);
      req = getVotesRequired(office);
      if (pts < req) alert=BOLD+RED;
      else           alert=BOLD+GREEN;
      voteInfo = pad(vtrsStr, 2)    +": "+
                 alert+pad(pts, 3)  +"/"+
                 pad(req, 3)        +OFF+"";
    }
    else
    {
      voteInfo = pad(vtrsStr, 2)    +":   " +
                 pad(pts, 5)        +"";
    }

    if (voteType == "office")
    {
      msg += BOLD+CYAN+"["+pad(capitalize(voteType), 6)+"] "+OFF;
    }
    else
    {
      msg += BOLD+MAGENTA+"["+pad(capitalize(voteType), 6)+"] "+OFF;
    }
    msg += BOLD+YELLOW+pad(voteName, MAX_VOTENAME_LENGTH) + OFF+"  " +
           pad(cdays, 2)+" "+BOLD+"["+OFF+voteInfo+BOLD+"]"+OFF+"\n";
  }
  if (i == 1) header = "\n"+BOLD+YELLOW+i+" vote in progress..."+OFF+"\n";
  else        header = "\n"+BOLD+YELLOW+i+" votes in progress..."+OFF+"\n";
  header += pad("TYPE", 9)+ 
            pad("VOTENAME", MAX_VOTENAME_LENGTH)+
            "DAYS VTRS  PTS\n"+LINE+msg+"\n";
  tell_object(player, header);
}


status voteExists(string voteName)
{
  if (file_size(VOTEDIR + "/" + voteName) >= 0) return 1;
  return 0;
}


status voteInProgress(string voteName)
{
  int i;
  mixed *iterVoteData;
  loadCheck(0);
  if (votesInProgress)
  {
    for (i=0; i<sizeof(votesInProgress); i++)
    {
      iterVoteData = votesInProgress[i];
      if (voteName == iterVoteData[INDEX_VOTENAME])
      {
        return 1;
      }
    }
  }
  return 0;
}


string hasVoted(mixed *voteData, string pName)
{
  string voteFileContents, foundDecision, foundName, voteLine, voteName;
  int i;
  status sepFound;
  string *voteLines;

  voteName = voteData[INDEX_VOTENAME];
  if (voteData[INDEX_PUB] == "secret")
  {
    voteFileContents = read_file(SVOTEDIR + "/" + voteName);
  }
  else
  {
    voteFileContents = read_file(VOTEDIR + "/" + voteName);
  }

  if (voteFileContents)
  {
    voteLines = explode(voteFileContents, "\n");
    sepFound = 0;
    for (i=0; i < sizeof(voteLines); i++)
    {
      voteLine = voteLines[i];
      if (!sepFound && 
          strlen(voteLine) >= VOTE_SEP_SIZE && 
          extract(voteLine, 0, VOTE_SEP_SIZE) == VOTE_SEP)
      {
        sepFound = 1;
      }
      if (!sepFound) continue;
      if (sscanf(voteLine, "%s %s", foundDecision, foundName) == 2)
      {
        if (foundName == pName)
        {
          return foundDecision;
        }
      }
    }
  }
  return 0;
}


string officeVoteInProgress(string pName)
{
  string office, member, date;
  int i;
  mixed *iterVoteData;
  loadCheck(0);
  if (votesInProgress)
  {
    for (i=0; i<sizeof(votesInProgress); i++)
    {
      iterVoteData = votesInProgress[i];
      if (iterVoteData[INDEX_TYPE] == "office")
      {
        sscanf(iterVoteData[INDEX_VOTENAME], "%s-%s-%s", office, member, date);
        if (member == pName) return office;
      }
    }
  }
  return 0;
}


int getVotesInProgressCount()
{
  int count;
  if (!votesInProgress) return 0;
  count = sizeof(votesInProgress);
  return count;
}


mixed* getVoteData(string voteName)
{
  int i;
  mixed *iterVoteData;
  loadCheck(0);
  for (i=0; i<sizeof(votesInProgress); i++)
  {
    iterVoteData = votesInProgress[i];
    if (voteName == iterVoteData[INDEX_VOTENAME])
    {
      return iterVoteData;
    }
  }
  return 0;
}


void deleteVote(string voteName)
{
  string file;
  file = VOTEDIR + "/" + voteName;
  if (file_size(file) >= 0) rm(file);
  file = SVOTEDIR + "/" + voteName;
  if (file_size(file) >= 0) rm(file);
}


void addVote(
string voteName, 
string owner, 
string type, 
int cday, 
string pub, 
string desc)
{
  string voteInfo, office, member, date;
  mixed *newVote;

  loadCheck(0);
  if (!votesInProgress) votesInProgress = ({});
  newVote = allocate(6);
  newVote[INDEX_VOTENAME] = voteName;
  newVote[INDEX_OWNER] = owner;
  newVote[INDEX_TYPE] = type;
  newVote[INDEX_CDAYS] = cday;
  newVote[INDEX_PUB] = pub;
  newVote[INDEX_DESC] = desc;
  votesInProgress += ({newVote, });

  if (type == "office")
  {
    sscanf(voteName, "%s-%s-%s", office, member, date);
    voteInfo = capitalize(member)+" is running for the guild office of "+
               capitalize(office)+"\n";
  }
  else
  {
    voteInfo = "This vote is "+capitalize(pub)+" and the issue is:\n"+
               "     "+capitalize(desc)+"\n";
  }

  write_file(VOTEDIR + "/" + voteName,
    "Vote Name : ["+voteName+"], a "+cday+" day vote.\n"+
    "Vote Owner: "+capitalize(owner)+"\n"+
    voteInfo+
    VOTE_SEP+"\n");

  /* create a mirror vote file in secret_votes to store the actual names */
  if (pub == "secret")
  {
    write_file(SVOTEDIR + "/" + voteName,
      "Vote Name : ["+voteName+"], a "+cday+" day vote.\n"+
      "Vote Owner: "+capitalize(owner)+"\n"+
      voteInfo+
      VOTE_SEP+"\n");
  }

  saveDaemon();
}


string query_cdayMonth() { loadCheck(0); return cdayMonth; }
string query_cdayDay()   { loadCheck(0); return cdayDay; }
string query_cdayYear()  { loadCheck(0); return cdayYear; }

#include "DEFS.h"

/* globals */
string cdayMonth, cdayDay, cdayYear;
static status loaded;
mixed *votesInProgress;


void saveDaemon()
{
  save_object(SAVEPATH);
}


void loadDaemon()
{
  restore_object(SAVEPATH);
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


void evaluateIssues(string voteName, int voterCount, string tally)
{
  write_file(VOTEDIR+"/"+voteName, 
    VOTE_SEP+"\n"+
    voterCount+" voters resulting in: "+tally+".\n");
}


status isVoteManager(string name)
{
  return name == MANAGER;
}


status accessAllow(string name)
{
  string votersContents, voteLine;
  string *voteLines;
  int i;

  if (isVoteManager(name)) return 1;

  /* temporarily allow all people to vote */
  if (1) return 1;

  votersContents = read_file(VOTERS);
  if (votersContents)
  {
    voteLines = explode(votersContents, "\n");
    for (i=0; i < sizeof(voteLines); i++)
    {
      voteLine = voteLines[i];
      if (voteLine && extract(voteLine, 0, 0) != "#")
      {
        if (name == voteLine) return 1;
      }
    }
  }

  return 0;
}


int tallyPoints(string voter, string decision)
{
  int points;

  points = 1; /* any voter gets at least one vote point */

  return points;
}


mixed* evaluateVote(string voteName, status enact, status secret)
{
  string voteFileContents, foundDecision, foundName, voteLine, choiceTally;
  int i, voterCount, iterPoints;
  mixed *voteTally;
  status sepFound;
  string *voteLines, *ks;
  mapping decisions;

  decisions  = ([]);
  voterCount = 0;

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
        iterPoints = tallyPoints(foundName, foundDecision);
        decisions[foundDecision] += iterPoints;
        voterCount++;
      }
    }
  }

  choiceTally = "";
  for (i=0; i < sizeof(ks = keys(decisions)); i++)
  {
    if (choiceTally != "") choiceTally += " ";
    choiceTally += ks[i]+"-"+decisions[ks[i]];
  }

  voteTally = allocate(2);
  voteTally[0] = voterCount;
  voteTally[1] = choiceTally;

  if (enact)
  {
    evaluateIssues(voteName, voterCount, choiceTally);
  }

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
  string msg, voteName, voteChoices, voteInfo, header, vtrsStr, ptsStr;
  mixed *voteData;
  int i, cdays, vtrs;
  mixed *voteTally;

  msg = "";
  loadCheck(0);
  if (!votesInProgress || sizeof(votesInProgress) < 1)
  {
    tell_object(player, HIC+
      "\nNo votes currently in progress.\n"+
      "See 'vote_help' for more info.\n\n"+NORM);
    return;
  }
  for (i=0; i < sizeof(votesInProgress); i++)
  {
    voteData    = votesInProgress[i];
    voteName    = voteData[INDEX_VOTENAME];
    voteChoices = voteData[INDEX_CHOICES];
    cdays       = voteData[INDEX_CDAYS];

    voteTally = evaluateVote(voteName, 0, voteData[INDEX_PUB] == "secret");
    vtrs   = (int)voteTally[0];
    ptsStr = (string)voteTally[1];
    if (vtrs < 10) vtrsStr = " " + vtrs;
    else           vtrsStr = "" + vtrs;

    voteInfo = pad(vtrsStr, 2)+":  "+ptsStr;

    msg += HIC+pad(voteName, MAX_VOTENAME_LENGTH)+NORM+"  "+
           pad(cdays, 2)+"     "+vtrsStr+"\n"+
           "    "+BOLD+"["+NORM+"Tally: "+ptsStr+BOLD+"]"+NORM+"\n";
  }
  if (i == 1) header = "\n"+HIC+i+" vote in progress..."+NORM+"\n";
  else        header = "\n"+HIC+i+" votes in progress..."+NORM+"\n";
  header += pad("VOTENAME", MAX_VOTENAME_LENGTH)+"DAYS    VOTERS\n"+LINE+
            msg+"\n";
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
    for (i=0; i < sizeof(votesInProgress); i++)
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
string choices, 
int cday, 
string pub, 
string desc)
{
  string voteInfo;
  mixed *newVote;

  loadCheck(0);
  if (!votesInProgress) votesInProgress = ({});
  newVote = allocate(6);
  newVote[INDEX_VOTENAME] = voteName;
  newVote[INDEX_OWNER]    = owner;
  newVote[INDEX_CHOICES]  = choices;
  newVote[INDEX_CDAYS]    = cday;
  newVote[INDEX_PUB]      = pub;
  newVote[INDEX_DESC]     = desc;
  votesInProgress += ({newVote, });

  voteInfo = "This vote is "+capitalize(pub)+" and the issue is:\n"+
             "     "+capitalize(desc)+"\n";

  write_file(VOTEDIR + "/" + voteName,
    "Vote Name :   ["+voteName+"], a "+cday+" day vote.\n"+
    "Vote Owner:   "+capitalize(owner)+"\n"+
    "Vote Choices: "+choices+"\n"+
    voteInfo+
    VOTE_SEP+"\n");

  /* create a mirror vote file in secret_votes to store the actual names */
  if (pub == "secret")
  {
    write_file(SVOTEDIR + "/" + voteName,
      "Vote Name :   ["+voteName+"], a "+cday+" day vote.\n"+
      "Vote Owner:   "+capitalize(owner)+"\n"+
      "Vote Choices: "+choices+"\n"+
      voteInfo+
      VOTE_SEP+"\n");
  }

  saveDaemon();
}


string query_cdayMonth() { loadCheck(0); return cdayMonth; }
string query_cdayDay()   { loadCheck(0); return cdayDay; }
string query_cdayYear()  { loadCheck(0); return cdayYear; }

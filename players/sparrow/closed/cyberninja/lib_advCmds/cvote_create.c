/* create a new vote */
#include "../DEFS.h"
#include DEFS_VOTE
#include DEFS_HLEVELS

#define LEVEL 3

void usage()
{
  write(
BOLD+RED+"Usage"+OFF+"\n"+
"You may set up a vote on a guild issue.\n\n"+
"To create a vote about a guild issue:\n"+
BOLD+YELLOW+"vote_create issue <issueName> [secret|open] <cdays> <issueDescription>"+OFF+"\n"+
"  - issueDescription is meant to be a lengthy explanation,\n"+
"    "+BOLD+"CLEARLY STATE"+OFF+" what a vote of 'yea' and 'nay' will mean.\n"+
"  - cdays is the number of days to hold the vote open.\n"+
"  - Example: vote_create issue pkShard open 30 PK lonely Shardaks?\n");
}


status main(string str)
{
  string officeStr, issueStr, cdayMonth, cdayDay, cdayYear, stone, currentOffice;
  string office, member, issueName, voteName, pub, desc, otherOffice;
  string *slashTest;
  int cdays, newRank, currentRank;
  object statOb;

  if (!gotrank(TP, LEVEL))
  {
    write("You need to be quality level "+LEVEL+" to create votes.\n");
    return 1;
  }

  if (!str)
  {
    usage();
    return 1;
  }

  if (call_other(VOTED, "getVotesInProgressCount") >= MAX_VOTES)
  {
    write("Maximum allowable votes in progress reached: "+MAX_VOTES+"\n");
    return 1;
  }

  cdayMonth = (string)call_other(VOTED, "query_cdayMonth");
  cdayDay = (string)call_other(VOTED, "query_cdayDay");
  cdayYear = (string)call_other(VOTED, "query_cdayYear");

if (sscanf(str, "office %s", officeStr))
{
      usage();
      return 1;
    }
  else if (sscanf(str, "issue %s", issueStr))
  {
    if (sscanf(issueStr, "%s %s %d %s", issueName, pub, cdays, desc) < 4)
    {
      usage();
      return 1;
    }
    issueName = lower_case(issueName);
    pub = lower_case(pub);
    voteName = issueName+"-"+cdayMonth+cdayDay+"_"+cdayYear;
    voteName = lower_case(voteName);
    slashTest = explode(issueName, "/");
    if (sizeof(slashTest) > 1           ||
        extract(issueName, 0, 0) == "/" ||
        extract(issueName, strlen(issueName)-1) == "/")
    {
      write("The <issueName> cannot include slashes ('/').\n");
      return 1;
    }
    if (strlen(voteName) >= MAX_VOTENAME_LENGTH)
    {
      write("The name of your issue is too long, please shorten and try again.\n");
      return 1;
    }
    if (cdays < MIN_CDAYS || cdays > MAX_CDAYS)
    {
      write("Invalid number of cdays entered.\n"+
            "Range is "+MIN_CDAYS+" to "+MAX_CDAYS+".\n");
      return 1;
    }
    if (!(pub == "secret" || pub == "open"))
    {
      write("Voter information was not specified correctly.\n"+
            "Your choices are 'secret' or 'open'.\n");
      return 1;
    }
    if (call_other(VOTED, "voteExists", voteName))
    {
      write("Vote "+voteName+" already exists.\n");
      return 1;
    }
    find_object(VOTED)->addVote(voteName, this_player()->query_real_name(), "issue", cdays, pub, desc);
    write("You create a vote! The voteName is: " + voteName + "\n");
    call_other(CHANNELD, "overchannel", TPN+" has created vote "+voteName);
    write_file(LOGDIR + "/VOTES",
      TRN+" created vote "+voteName+" ("+ctime()+")\n");
    return 1;
  }
  else
  {
    usage();
  }
  return 1;
}

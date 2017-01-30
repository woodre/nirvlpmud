/* create a new vote */
#include "../DEFS.h"
#include DEFS_VOTE
#include DEFS_HLEVELS

#define LEVEL 3


void usage()
{
  write(
BOLD+RED+"Usage"+OFF+"\n"+
"You may set up either an election or a vote upon a guild issue.\n\n"+
"To set up an election:\n"+
BOLD+YELLOW+"vote_create office <office> <member> <cdays>"+OFF+"\n"+
"  - office is the office to set up the election for.\n"+
"  - member is the guild member who is being nominated.\n"+
"  - cdays is the number of days to hold the vote open.\n"+
"  - Example: vote_create office sensei dune 7\n\n"+
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
    if (sscanf(officeStr, "%s %s %d", office, member, cdays) != 3)
    {
      usage();
      return 1;
    }
    office = lower_case(office);
    member = lower_case(member);
    voteName = office+"-"+member+"-"+cdayMonth+cdayDay+"_"+cdayYear;
    voteName = lower_case(voteName);
    if (cdays < MIN_CDAYS || cdays > MAX_CDAYS)
    {
      write("Invalid number of cdays entered.\n"+
            "Range is "+MIN_CDAYS+" to "+MAX_CDAYS+".\n");
      return 1;
    }
    if (!call_other(OFFICED, "findStone", office))
    {
      write("No such office.\n");
      return 1;
    }
    statOb = clone_object(GUILDOBJ);
    if (!statOb->external_restore_me(member))
    {
      write("Cannot find a member by the name of "+capitalize(member)+".\n");
      destruct(statOb);
      return 1;
    }
    if (call_other(VOTED, "voteExists", voteName))
    {
      write("Vote "+voteName+" already exists.\n");
      destruct(statOb);
      return 1;
    }
    otherOffice = (string)call_other(VOTED, "officeVoteInProgress", member);
    if (otherOffice)
    {
      write("A vote of "+capitalize(member)+" for "+capitalize(otherOffice)+" is already in progress.\n"+
           "Guild members may run for only one office at a time.\n");
      destruct(statOb);
      return 1;
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
    if (currentRank > 0 && currentRank > newRank)
    {
      write(capitalize(member)+" is already of higher rank.\n"+
            "You cannot vote officers into lower offices.\n");
      destruct(statOb);
      return 1;
    }
    if (currentRank > 0 && currentRank == newRank)
    {
      write(capitalize(member)+" is already "+capitalize(office)+".\n");
      destruct(statOb);
      return 1;
    }
    find_object(VOTED)->addVote(voteName, this_player()->query_real_name(), "office", cdays, "secret", 0);
    write("You create a vote! The voteName is: " + voteName + "\n");
    call_other(CHANNELD, "overchannel", TPN+" has created a vote of "+
      capitalize(member)+" for "+capitalize(office)+".");
    write_file(LOGDIR + "/VOTES",
      TRN+" created vote "+voteName+" ("+ctime()+")\n");
    destruct(statOb);
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

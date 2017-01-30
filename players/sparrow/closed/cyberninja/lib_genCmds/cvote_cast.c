/* cast a vote */
#include "../DEFS.h"
#include DEFS_VOTE


void usage()
{
  write(
BOLD+RED+"Usage"+OFF+"\n"+
"This command is used to cast your vote.\n"+
BOLD+YELLOW+"vote_cast <voteName> [yea|nay]"+OFF+"\n"+
"  - yea means yes, nay means no\n"+
"  - Remember that sometimes not voting is better than voting 'nay'\n"+
"  - If you created the vote, don't forget to cast your vote.\n");
}


status main(string str)
{
  string voteName, decision, voteText, secret_voteText;
  mixed *voteData;

  if (!str)
  {
    usage();
    return 1;
  }

  if (sscanf(str, "%s %s", voteName, decision) != 2)
  {
    usage();
    return 1;
  }

  decision = lower_case(decision);
  voteName = lower_case(voteName);

  if (!(decision == "yea" || decision == "nay"))
  {
    write("Your decision was not valid. It must be either\n"+
          "'yea' for yes, or 'nay' for no.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteExists", voteName))
  {
    write("Vote "+voteName+" does not exist.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteInProgress", voteName))
  {
    write("The deadline to vote on "+voteName+" has passed.\n");
    return 1;
  }

  voteData = (mixed*)call_other(VOTED, "getVoteData", voteName);

  if (call_other(VOTED, "hasVoted", voteData, this_player()->query_real_name()))
  {
    write("You have already voted on "+voteName+".\n");
    return 1;
  }

  secret_voteText = decision+" "+this_player()->query_real_name()+"\n";
  if (voteData[INDEX_PUB] == "secret")
  {
    voteText = decision+" Someone\n";
  }
  else
  {
    voteText = secret_voteText;
  }

  write_file(VOTEDIR + "/" + voteName, voteText);

  if(voteData[INDEX_PUB] == "secret")
  {
    /* store the secret name in the secret votes directory */
    write_file(SVOTEDIR + "/" + voteName, secret_voteText);
  }

  write("You cast a "+decision+" for vote "+voteName+".\n");
  return 1;
}

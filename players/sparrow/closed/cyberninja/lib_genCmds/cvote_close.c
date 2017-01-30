/* view votes in progress */
#include "../DEFS.h"
#include DEFS_VOTE


status main(string str)
{
  string myName, voteType, owner;
  mixed *voteData;

  if (!str)
  {
    write("You must specify a voteName in progress to close.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteExists", str))
  {
    write("Vote "+str+" does not exist.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteInProgress", str))
  {
    write("You cannot close a vote that has already finished.\n"+
          "You may close only votes still in progress.\n");
    return 1;
  }

  voteData = (mixed*)call_other(VOTED, "getVoteData", str);
  voteType = voteData[INDEX_TYPE];
  if (voteType == "office")
  {
    write("Office election votes cannot be closed.\n");
    return 1;
  }

  myName = (string)this_player()->query_real_name();
  owner = voteData[INDEX_OWNER];
  if (myName != owner)
  {
    write("Only the owner of this vote ("+capitalize(owner)+") can close.\n");
    return 1;
  }

  call_other(VOTED, "closeVote", str);
  call_other(VOTED, "evaluateVote", str, voteType, voteData[INDEX_PUB] == "secret");

  write("You close vote "+str+".\n");

  return 1;
}

/* cancel a vote in progress */
#include "../DEFS.h"
#include DEFS_VOTE


status main(string str)
{
  string myName, voteType, office, member, date, owner;
  mixed *voteData;
  if (!str)
  {
    write("You must specify a voteName in progress to cancel.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteExists", str))
  {
    write("Vote "+str+" does not exist.\n");
    return 1;
  }

  if (!call_other(VOTED, "voteInProgress", str))
  {
    write("You cannot cancel a vote that has already finished.\n"+
          "Vote cancellation is only for votes still in progress.\n");
    return 1;
  }

  voteData = (mixed*)call_other(VOTED, "getVoteData", str);
  voteType = voteData[INDEX_TYPE];
  myName = (string)this_player()->query_real_name();
  if (voteType == "office")
  {
    sscanf(str, "%s-%s-%s", office, member, date);
    if (myName != member && !IPTP->guild_manager())
    {
      write("You cannot cancel someone else's campaign.\n"+
            "Only "+capitalize(member)+" can cancel this vote.\n");
      return 1;
    }
    call_other(VOTED, "closeVote", str);
    call_other(VOTED, "deleteVote", str);
  }
  else
  {
    owner = voteData[INDEX_OWNER];
    if (myName != owner && !IPTP->guild_manager())
    {
      write("Only the owner of this vote ("+capitalize(owner)+") can cancel.\n");
      return 1;
    }
    call_other(VOTED, "closeVote", str);
    call_other(VOTED, "deleteVote", str);
  }

  write("You cancel vote "+str+".\n");
  call_other(CHANNELD, "overchannel", TPN+" has canceled vote "+str+".");
  write_file(LOGDIR + "/VOTES",
    TRN+" canceled vote "+str+" ("+ctime()+")\n");
  return 1;
}

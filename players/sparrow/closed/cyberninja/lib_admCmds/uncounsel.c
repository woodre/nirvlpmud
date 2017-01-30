#include "../DEFS.h"
#include DEFS_GLEVELS
#include DEFS_HLEVELS


/* Way to un-counsel players who decide not to join after all */

status main(string who)
{
  object ob, statOb, recruitOb;
  string counselingStr, myName, pair;
  int counseleesLeft;

  counselingStr = 0;

  if (!call_other(OFFICED, "checkStone", TP, "diamond sapphire pearl emerald onyx"))
    return 0;

  if (!who)
  {
    write("Usage: uncounsel <player>.\n");
    return 1;
  }

  who = lower_case(who);
  myName = (string)this_player()->query_real_name();
  if (!call_other(RECRUITD, "hasCounselee", myName, who))
  {
    write("You are not currently counseling "+capitalize(who)+".\n");
    return 1;
  }

  statOb = clone_object(GUILDOBJ);
  if (statOb->external_restore_me(who))
  {
    /* uncounseling of a guild member causes a loss of honor,
       this is to prevent people from recruiting and then immediately
       uncounseling so they can have their recruit slot back. */
    IPTP->add_honor(-HONOR_AWARDNUM_MD4);
    IPTP->save_me();
    write("You lose "+HONOR_AWARDNAME_MD4+" honor, recruit more wisely next time.\n");
  }

  pair = myName+" "+who;
  call_other(RECRUITD, "clearCouncelee", pair);

  write_file(LOGDIR + "/RECRUIT", 
    TRN+" UN-uncounseled "+capitalize(who)+" ("+ctime()+")\n");

  write("You uncounsel "+capitalize(who)+".\n");

  destruct(statOb);
  return 1; 
}

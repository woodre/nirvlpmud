#include "../DEFS.h"
#include DEFS_GLEVELS
#include DEFS_HLEVELS


/* Way to recruit new guild members */

status main(string who)
{
  object ob, recruitOb;
  string counselingStr;
  int counseleesLeft;

  counselingStr = 0;

if (!call_other(OFFICED, "checkStone", TP, "diamond sapphire pearl ruby emerald onyx"))
    return 0;

  if (!who              ||
      !find_player(who) || 
      find_player(who)->query_level() > 19)
  {
    write("Usage: recruit <player>.\n");
    return 1;
  }

  ob = find_player(who);

  if (present(RECRUIT, ob))
  {
    tell_object(TP, OPN+" is already recruited.\n");
    return 1;
  }

  if (call_other(MEMBERD, "already_in_a_guild", ob))
  {
     tell_object(TP, OPN+" is already in a guild.\n");
     return 1;
  }

  if ((int)ob->query_level() < MIN_JOIN_LEVEL)
  {
     tell_object(TP,
       OPN+" is not level "+MIN_JOIN_LEVEL+" yet.\n");
     return 1;
  }

  counseleesLeft = (int)call_other(RECRUITD, "counseleesLeft", this_player());
  if (!call_other(RECRUITD, "hasCounseleePair", TP->query_real_name()+" "+ob->query_real_name()))
  {
    /* recruiter is not already recruiting recruitee */
    counseleesLeft -= 1;
  }
  if (counseleesLeft <= 0)
  {
    write("Your counseling limit has been reached. You cannot recruit\n"+
          "more members into the guild until one of your current counselees\n"+
          "has reached the level of Mastery in martial arts.\n");
    return 1;
  }
  else if (counseleesLeft == 1)
  {
    call_other(RECRUITD, "setCounselee", TP->query_real_name()+" "+ob->query_real_name());
    counselingStr = "You can counsel only one more recruit.";
  }
  else
  {
    call_other(RECRUITD, "setCounselee", TP->query_real_name()+" "+ob->query_real_name());
    counselingStr = "You can counsel " + counseleesLeft + " more recruits.";
  }

  write_file(LOGDIR + "/RECRUIT", 
    TRN+" recruited "+capitalize(who)+" ("+ctime()+")\n");

  write("You have shown "+capitalize(who)+" the Way.\n");

  tell_room(environment(ob), 
    TPN+" has shown "+capitalize(who)+" the Way.\n");

  recruitOb = clone_object(OBJDIR + "/recruitob.c");
  recruitOb->set_recruiter(TP->query_real_name());
  move_object(recruitOb, ob);

  tell_object(ob, "You have been shown the Way.\n"+
    "Learn it, and you will soon be along the path\n"+
    "to greater destiny.\n");

  if (counselingStr) write(counselingStr + "\n");

  IPTP->save_me();

  return 1; 
}

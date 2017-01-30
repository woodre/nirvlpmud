#include "../DEFS.h"
#include DEFS_GLEVELS
#include DEFS_HLEVELS


/* Way to view current and remaining recruit slots. */

status main(string who)
{
  object ob, recruitOb;
  string counselingStr, counselees;
  int counseleesLeft;

  if (!call_other(OFFICED, "checkStone", TP, "diamond sapphire pearl ruby emerald onyx"))
    return 0;

  counseleesLeft = (int)call_other(RECRUITD, "counseleesLeft", this_player());
  if (counseleesLeft <= 0)
  {
    counselingStr = "Your counseling limit has been reached.";
  }
  else if (counseleesLeft == 1)
  {
    counselingStr = "You can counsel only one more recruit.";
  }
  else
  {
    counselingStr = "You can counsel " + counseleesLeft + " more recruits.";
  }

  counselees = (string)call_other(RECRUITD, "getCounselees", TP->query_real_name());
  if (!counselees || counselees == "")
  {
    write("You are not currently counseling anyone.\n");
  }
  else
  {
    write("You are currently counseling: " + counselees + "\n");
  }

  write(counselingStr + "\n");

  return 1; 
}

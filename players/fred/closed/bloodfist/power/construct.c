#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object corpse, *area, ward;
  int cost, dur, a, ca, b, c;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(8)) return 0;
  if(str != "bloodward" && str != "ward") return 0;

  if(present("fred_bf_bloodward", environment(User)))
    return(notify_fail("There is already a bloodward here.\n"), 0);

  cost = 80 - (WIS / 10) - (FAI / 10);

  if((string)environment(User)->realm() == "NM")
  {
    TOU"Your energy is being drained here.\n");
    return 1;
  }

  if(User->query_sp() < cost)
  {
    TOU "You are too weak to do this now.\n");
    return 1;
  }

  c = 0;
  b = 0;
  area = all_inventory(environment(User));
  ca = sizeof(area);
  for(a = 0; a < ca; a++)
  {
    if(area[a]->is_corpse())
    {
      b++;
      if(b < 4)
        c += (int)area[a]->query_corpse_level();
    }
  }

  if(b < 3)
    return(notify_fail(
    "There aren't enough corpses here to construct a bloodward.\n"), 0);
  
  TOU"You tear flesh from bone and bone from flesh...\n"+
    "Bones wrapped together with bloody entrails...\n"+
    "From the remains of the bodies you construct a bloodward.\n");

  TRU Name+" constructs a bloodward from three corpses.\n", ({ User }));

  ward = clone_object(DIR+"obj/bloodward.c");
  ward -> set_owner(User);
  ward -> set_level(c * 2);
  move_object(ward, environment(User));
  ward -> cloned();

  b = 0;
  for(a = 0; a < ca, b < 3; a++)
  {
    if(area[a]->is_corpse())
    {
      destruct(area[a]);
      b++;
    }
  }
  User->add_sp(-cost);
  return 1;
}

#include "../defs.h"

int do_cmd(string str)
{
  object gob;
  object targ;
  string msg;

  if((int)TP->query_guild_rank() < 3)
    return 0;

  if((int)TP->query_level() < 14)
  {
    write("You must be at least level 14 to cast this spell.\n");
    return 1;
  }

  if((int)TP->query_sp() < 15)
  {
    write(NOSP_MSG);
    return 1;
  }

  if((int)TP->test_dark())
  {
    write("It is too dark.\n");
    return 1;
  }

  if((int)TP->query_spell_dam())
  {
    write("You are already casting!\n");
    return 1;
  }

  gob = previous_object();
  if((int)gob->query_crystals() < 1)
  {
    write("You require a faeite crystal to cast this spell.\n");
    return 1;
  }

  if(str)
  {
    targ = present(str, environment(TP));
    if(!targ)
    {
      write("There is no "+str+" here.\n");
      return 1;
    }
  }
  else
  {
    targ = (object)TP->query_attack();
    if( !targ || !present(targ, environment(TP) ) )
    {
      write("You have no target.\n");
      return 1;
    }
  }

  if(!living(targ))
  {
    write("That is not a living thing.\n");
    return 1;
  }

  if(!TP->valid_attack(targ))
  {
    write("You may not attack that.\n");
    return 1;
  }

  write(CYN + "You launch a crystal shard at "+(string)targ->query_name() + "!\n" + NORM);
  tell_object(targ, CYN + TPN + " launches a crystal shard at you!\n" + NORM);
  tell_room(environment(TP), CYN + TPN + " launches a crystal shard at " + (string)targ->query_name() + "!\n" + NORM, ({ TP, targ }));

  switch(random(3))
  {
    case 0: msg = "\t" + RED + (string)targ->query_name() + " is lacerated!\n" + NORM;
            break;
    case 1: msg = "\t" + HIR + (string)targ->query_name() + " is grievously sliced!\n" + NORM;
            break;
    case 2: msg = "\t" + HIY + (string)targ->query_name() + " is eviscerated!\n" + NORM;
            break;
  }

  TP->spell_object(targ, "crystal shard", 30, 15, msg, msg, msg);
  if(!random(5))
  {
    gob->add_crystals(-1);
	write("You have used up another faeite crystal.\n");
  }

  return 1;
}

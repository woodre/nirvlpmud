#include "../defs.h"

status main(string str, object PO, object User)
{
  object corpse;
  int cvalue;
  string extra;

  if(GHOST) return 0;
 
  corpse = present("corpse", ENV(User));

  if(!corpse) 
  {
    TOU "There is no corpse.\n");
    return 1;
  } 
  if((int)corpse->query_corpse_level() < 1)
  {
    TOU "You cannot absorb that, it is useless.\n");
    return 1;
  }
  if(sscanf(file_name(corpse),"obj/corpse%s",extra) != 1) return 1;
  if(PO->query_venomed())
  {
    TRU ""+BOLD+CAP((string)PO->query_symbiote())+NORM+" picks up a corpse and strangely begins to hug it.\n"+
         "The corpse is slowly engulfed by the symbiotic life form.\n");
  }
  else
  {
    TRU User->QN+" places his palm onto a corpse.\n"+
        "A black ooze seeps out of "+User->QN+"'s palm covering the corpse.\n"+
        "The black ooze seeps back inside "+User->QN+", leaving no remnants of\n"+
        "the corpse.\n");
  }

  cvalue = (int)corpse->query_corpse_level() / 2;
  cvalue += random((int)corpse->query_corpse_level() / 2);
  cvalue += 1;

  if(PO->query_mp() + cvalue > 300)
  {
    TOU BOLD+CAP((string)PO->query_symbiote())+NORM+" whispers to you, \"We have enough matter to sustain...Now we heal.\"\n");
    User->heal_self(((PO->query_mp() + cvalue) - 300)/3);
    PO->set_mp(300);
  }
  else if(PO->query_mp() + cvalue <= 300)
  {
    PO->add_mp(cvalue);
  }
  if(PO->query_mp() > 300) 
    PO->set_mp(300);
  destruct(corpse);
  return 1;
}

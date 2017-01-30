#include "../defs.h"

status main(string str, object PO, object User)
{
  object cave;

  if(!PO->query_has_lair()) return 0;
  if(User->QL < 16) return 0;
  if(GHOST) return 0;

  if((int)PO->query_has_lair() == 1)
  {
    TOU "You need to place it first!\n");
    return 1;
  }
  if(present("symbiote_cave", ENV(User)))
  {
    if(present("symbiote_cave", ENV(User))->query_cave_owner() == User->QRN)
    {
      TRU User->QN+" disappears suddenly.\n", ({ User }));
      TOU "You enter your lair.\n");

      move_object(User, present("symbiote_cave", ENV(User)));
      command("look", User);
      return 1;
    }
  }
  if(file_name(ENV(User)) == (string)PO->query_lair())
  {	
    cave = clone_object("/players/fred/closed/venom2/OBJ/cave");
    cave->set_cave_owner(User->QRN);
    move_object(cave, ENV(User));

    TRU User->QN+" disappears suddenly.\n", ({ User }));
    TOU "You enter your lair.\n");
    move_object(User, cave);
    command("look", User);
    return 1;
  }   
  else
  {
    TOU "This isn't where your lair is located!\n");
    return 1;
  }
  return 1;
}

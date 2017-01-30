#include "../def.h"

status main(string str, object PO, object User)
{
  if(User->LVL < 20) 
  {
    if(User->GHOST) return 0;

    if(User->SP < 40) 
    { 
      write("You don't have enough energy.\n"); 
      return 1; 
    }
	
    User->set_invs_sp();
    User->add_spell_point(-40);
    write("You wave your staff around your body and fade from view.\n");
    say(User->QN+" waves "+User->POS+" staff around "+User->POS+" body and fades from view.\n"); 
    return 1; 
  }
}

#include "../def.h"

cmd_kamae(str)
{
  object gob;
  gob = previous_object();
  if(!str)
  {
    write("Current: "+BOLD+gob->query_kamae()+" no kamae\n"+NORM);
    return 1;
  }
  else
  {
    if(str != "chudan" && str != "jodan" && str != "gedan")
    {
      write("You can only choose from:\n"+
            "\tchudan\tjodan\tgedan\n");
      return 1;
    }
    else
    {
      object wep;
      
      if(!(wep=TP->query_weapon()))
      {
        write("You must be wielding a weapon to switch kamae.\n");
        return 1;
      }
      gob->set_kamae(str);
      write("You grip your "+wep->query_name()+" and assume a "+
        BOLD+str+" no kamae"+NORM+" position.\n");
      say(TP->QN+" grips "+possessive(TP)+" "+wep->query_name()
        +" and assumes a "+BOLD+str+" no kamae"+NORM+" position.\n");
      return 1;
    }
  }
}

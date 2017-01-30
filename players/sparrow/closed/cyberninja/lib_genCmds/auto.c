#include "../DEFS.h"


status main(string str)
{
  /* sets automatics */
  if (!str)
  {
    write("Usage: auto [ on/off/list");
    if (IPTP->item_corpse())  write("/reg/rej/dgst");
    if (IPTP->item_blades())  write("/blad");
    if (IPTP->item_bionics()) write("/bion");
    if (IPTP->item_weplink()) write("/targ");
    write(" ]\n");
    return 1; 
  }
  if (str == "on")
  {
    IPTP->set_auto(1);
    IPTP->save_me();
    write("Your automatics are now ON.\n");
    return 1;
  }
  if (str == "off")
  {
    IPTP->set_auto(0);
    IPTP->save_me();
    write("Your automatics are now OFF.\n"); 
    return 1; 
  }
  if (str == "list")
  {
    string msg;
    if (!IPTP->query_auto_on())
    {
      write("Automatics are OFF.\n");
    }
    else
    {
      msg="";
      if (IPTP->query_auto_reg())  msg += "reg";
      if (IPTP->query_auto_rej())  { if (msg != "") msg+= "/"; msg += "rej";  }
      if (IPTP->query_auto_dgst()) { if (msg != "") msg+= "/"; msg += "dgst"; }
      if (IPTP->query_auto_blad()) { if (msg != "") msg+= "/"; msg += "blad"; }
      if (IPTP->query_auto_bion()) { if (msg != "") msg+= "/"; msg += "bion"; }
      if (IPTP->query_auto_targ()) { if (msg != "") msg+= "/"; msg += "targ"; }
      if (msg == "") write("Automatics are ON.\n");
      else           write("Automatics: [ "+msg+" ]\n");
    }
    return 1;
  }
  if (str == "dgst" && IPTP->item_corpse())
  {
    if (IPTP->query_auto_dgst())
    {
      IPTP->set_auto_dgst(0);
      IPTP->save_me();
      write("You turn off your auto digestion.\n");
      return 1;
    }
    IPTP->set_auto_dgst(1);
    IPTP->save_me();
    write("You activate your auto digestion.\n");
    return 1;
  }
  if (str == "targ" && IPTP->item_weplink())
  {
    if (IPTP->query_auto_targ())
    {
      IPTP->set_auto_targ(0);
      IPTP->save_me();
      write("You turn off your auto targeting.\n");
      return 1;
    }
    IPTP->set_auto_targ(1);
    IPTP->save_me();
    write("You activate your auto targeting.\n");
    return 1;
  }
  if (str == "reg" && IPTP->item_corpse())
  {
    if (IPTP->query_auto_reg())
    {
      IPTP->set_auto_reg(0);
      IPTP->save_me();
      write("You turn off your auto regeneration.\n"); 
      return 1; 
    }
    IPTP->set_auto_reg(1);
    IPTP->save_me();
    write("You activate your auto regeneration.\n"); 
    return 1; 
  }
  if (str == "rej" && IPTP->item_corpse())
  {
    if (IPTP->query_auto_rej())
    {
      IPTP->set_auto_rej(0);
      IPTP->save_me();
      write("You turn off your auto rejuvenation.\n"); 
      return 1; 
    }
    IPTP->set_auto_rej(1);
    IPTP->save_me();
    write("You activate your auto rejuvenation.\n"); 
    return 1; 
  }

  if(str == "blad" && IPTP->item_blades())
  {
    if(IPTP->query_auto_blad())
    {
      IPTP->set_auto_blad(0);
      IPTP->save_me();
      write("You turn off your auto blades.\n"); 
      return 1; 
    }
    IPTP->set_auto_blad(1);
    IPTP->save_me();
    write("You activate your auto blades.\n"); 
    return 1; 
  }

  if(str == "bion" && IPTP->item_bionics())
  {
    if(IPTP->query_auto_bion())
    {
      IPTP->set_auto_bion(0);
      IPTP->save_me();
      write("You turn off your auto bionics.\n"); 
      return 1; 
    }
    IPTP->set_auto_bion(1);
    IPTP->save_me();
    write("You activate your auto bionics.\n"); 
    return 1; 
  }

  else write("You have chosen an invalid auto.\n");
  return 1;
}
#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  if(!str) return 0;
  else if(str == "list")
  {
    TOU "Toggles:\n"+
      pad(" ac   additional commands", 40));
    if(PO->query_a_c()) TOU "on\n");  else TOU "off\n");
    TOU pad(" fs   full score", 40));
    if(PO->query_f_s()) TOU "on\n");  else TOU "off\n");
    TOU pad(" as   auto sheath on retrieve", 40));
    if(PO->query_a_s()) TOU "on\n");  else TOU "off\n");
    TOU pad(" fm   full monitor", 40));
    if(PO->query_f_m()) TOU "on\n");  else TOU "off\n");
    TOU pad(" hm   heartbeat monitor", 40));
    if(PO->query_h_m()) TOU "on\n");  else TOU "off\n");
  }
  else if(str == "ac" || str == "additional commands")
  {
    if(PO->query_a_c())
      TOU "You toggle \"additional commands\" off.\n");
    else
      TOU "You toggle \"additional commands\" on.\n");
    PO->toggle_a_c();
  }
  else if(str == "fs" || str == "full score")
  {
    if(PO->query_f_s())
      TOU "You toggle \"full score\" off.\n");
    else
      TOU "You toggle \"full score\" on.\n");
    PO->toggle_f_s();
  }
  else if(str == "as" || str == "auto sheath" || str == "autosheath")
  {
    if(PO->query_a_s())
      TOU "You toggle \"auto sheath on retrieve\" off.\n");
    else
      TOU "You toggle \"auto sheath on retrieve\" on.\n");
    PO->toggle_a_s();
  }
  else if(str == "fm" || str == "full monitor")
  {
    if(PO->query_f_m())
      TOU "You toggle \"full monitor\" off.\n");
    else
      TOU "You toggle \"full monitor\" on.\n");
    PO->toggle_f_m();
  }
  else if(str == "hm" || str == "heartbeat monitor")
  {
    if(PO->query_h_m())
      TOU "You toggle \"full monitor\" off.\n");
    else
      TOU "You toggle \"full monitor\" on.\n");
    PO->toggle_h_m();
  }
  else
    return 0;
  return 1;
}


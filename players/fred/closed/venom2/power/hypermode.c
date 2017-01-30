#include "../defs.h"

status main(string str, object PO, object User)
{
  if(GHOST) return 0;
  if(PO->query_combat() < 6) return 0;

  if(!User->query_pl_k())
  { 
    TOU "You must set pk to use this ability!\n"); 
    return 1; 
  }
  if(User->query_sp() < 70)
  {
    TOU "You lack the energy for Hypermode.\n");
    return 1;
  }
  if(PO->query_mp() < 5)
  {
    TOU "You lack the "+HIW+"Dark Matter"+NORM+" to do that.\n");
    return 1;
  }
  if(PO->query_hyper())
  {
    TOU "Hypermode is already on.\n");
    return 1;
  }

  TOU HIW+"Your body tightens as symbiotic matter flows into your veins and muscles..."+NORM+"\n"+
      PO->query_color()+"Your motions become a blur!"+NORM+"\n");

  TRU HIW+User->QN+"'s body darkens as something "+HIB+"Black"+NORM+" courses through "+User->POS+" veins...\n"+
      NORM+PO->query_color()+User->POS+" motions blur!"+NORM+"\n", ({ User }));

  PO->set_hyper(30 + ((int)PO->query_combat() * 2) + WIL);
  User->add_spell_point(-70);
  PO->add_mp(-5);
  return 1;
}

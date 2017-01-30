#include "../DEFS.h"

void flux_charge(object ob);


status main(string str)
{
  if( !IPTP->guild_wiz() && !(
    (status)IPTP->item_electricflux() ||
    (status)IPTP->item_magneticflux() ||
    (status)IPTP->item_heatflux() )) return 0;

  if((status)IPTP->query_charge_on())
  {
    tell_object(TP, "You stop charging your FluX generator.\n");
    IPTP->set_charge_on(0);
    return 1;
  }
  tell_object(TP, "You start charging your FluX generator.\n");
  IPTP->set_charge_on(1); 
  return 1; 
}


void flux_charge(object ob)
{
  int charges;
  if (!ob || !IPOB) return;
  charges = (int)IPOB->query_flux_charges();
  if (charges >= (((int)IPOB->guild_lev())/2)+1)
  {
    tell_object(ob, BOLD+"FluX charger full [ "+charges+" ]"+OFF+"\n");
    IPOB->set_charge_on(0); 
    return; 
  }
  if((int)ob->query_sp() < 50)
  {
    tell_object(ob, "FluX charging would drain your energy supply too much.\n"+
      "Process halted.\n");
    IPOB->set_charge_on(0); 
    return; 
  }
  ob->add_spell_point(-15);
  IPOB->add_flux_charges(1);
  IPOB->save_me();
  tell_object(ob, "FluX charging... [ "+charges+" ]\n");
  return;
}

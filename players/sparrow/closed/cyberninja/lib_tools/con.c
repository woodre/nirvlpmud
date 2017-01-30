#include "../DEFS.h"

status main(string str) {
  object pob, ob;
  if(!((status)IPTP->item_convert()) && !IPTP->guild_wiz()) return 0;
  pob = present(TRANSFER_ID, TP);
  if(pob) {
    destruct(pob);
    IPTP->set_convert_on(0);
    write("Matter conversion stopped.\n");
    TP->add_spell_point(-4);
    return 1;
  }
  ob = clone_object(OBJDIR + "/transfer.c");
  move_object(ob,TP);
  pob = present(TRANSFER_ID, TP);
  pob->energy_transfer();
  IPTP->set_convert_on(1);
  write("Matter conversion begun.\n");
  return 1;
}

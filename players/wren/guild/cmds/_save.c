#include "../def.h"

int cmd_save(string str)
{
 if(str) return 0;

 TL(TP, HIB+"Saving guild statistics...\n"+NORM);
 PO->save_me();
 TL(TP, HIB+"Ok.\n"+NORM);
 TL(TP, "Saving your character...\n");
 TP->save_character();
 return 1;
}

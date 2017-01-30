#include "../defs.h"

inherit WAXFUNS;

get() { return 0; }
drop() { return 0; }

short() { return HIW + "An Enchanted "+HIB+"Fountain"+NORM+NORM; }

id(arg) { return (arg == "fountain" || arg == "enormous fountain"); }

long() { write(line_wrap("This is a large fountain commemorating the wizard Earwax's defeat of the dreaded "+HIR+"Q-Tip King"+NORM + NORM+".  This fountain was enchanted by Earwax with healing energies.  All who are in the immediate area of the fountain will find that their wounds heal faster and they may experience spiritual healing as well.  This fountain also prevents fighting from occuring here and keeps the wild beasts at bay.\n"));
}

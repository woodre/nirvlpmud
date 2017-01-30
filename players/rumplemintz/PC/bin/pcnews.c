/* pcnews - News reader for the Player Channel - uses ~/PC/NEWS */

#include <ansi.h>

int pcnews(){
   write(HIW+"\n"+
      "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "|                             Player Channel News!                             |\n"+
      "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "\n");
   cat("/players/rumplemintz/PC/NEWS");
   write(NORM);
   write("\n"+
      "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "\n"+NORM);
   return 1;
}

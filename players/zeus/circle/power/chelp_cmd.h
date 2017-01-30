#include "/players/zeus/circle/defs.h"

status chelp_cmd(){
  write("The basic guild commands...\n\n"+
    "\tcsave                  save stats\n"+
    "\tcupdate                update object\n"+
    "\tset_percent            set % of xp to go to guild\n"+
    "\tspeak / sp             personal channel [sp for help]\n"+
    "\tdrift <dirs>           up to 5 command speedster\n"+
    "\tset_title              set your title\n"+
    "\tremove all             remove all worn armor\n"+
    "\ttoggle_endurance       endurance monitor on or off\n"+
    "\tecolor                 set colors of endurance monitor\n"+
    "\tguild updates          check for guild info\n"+
    "\n"+
    "Emotes:  stand, bcry, swave, wait, fdraw <str>\n\n");
  return 1;
}


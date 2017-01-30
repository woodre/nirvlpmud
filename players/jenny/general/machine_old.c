/* Approved for play 5/16/00 - Eurale  */
#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
  if(arg) return;
  set_id("machine");
set_short("A little metal machine sticking out from the ground");
set_long(
"This is a thin metal machine that is mysteriously sticking out of the\n"+
"ground.  It is bright silver, and covered with beeping red lights.  It\n"+
"looks like some sort of galactic parking meter.  You can type "+MAG+"list "+NORM+"to\n"+
"see what it does.\n");
}

init() { 
    ::init();
add_action("title","clear");
add_action("pretitle","clear");
add_action("list","list");
}
title(arg) {
if(arg == "title") {
if(TP->query_money() < 1000) {write("You are too poor to get rid of your title.\n"); return 1;}
TP->set_title(NORM+"");
TP->add_money(-1000);
write(WHT+"You get rid of your title."+NORM+"\n");
write_file("/players/jenny/logs/title", ""+TPRN+" erased "+POS+" title at "+ctime()+"\n");
return 1; }}
pretitle(arg) {
if(arg == "pretitle") {
if(TP->query_money() < 50) {write("You are too poor to get rid of your pretitle.\n"); return 1;}
command("pretitle |",TP); 
TP->add_money(-50);
write(WHT+"You get rid of your pretitle."+NORM+"\n");
write_file("/players/jenny/logs/title", ""+TPRN+" erased "+POS+" pretitle at "+ctime()+"\n");
return 1; }}
list() {
write(
"The machine "+CYN+"beeps"+NORM+" and "+YEL+"hums."+NORM+"\n"+
"\n"+
"An automated voice says: You may get rid of your title for 1000 coins.\n"+
"Just type 'clear title'.\n"+
"\n"+
"You may get rid of your pretitle for 50 coins.\n"+
"Just type 'clear pretitle'.\n");
return 1;}
get() {return 0;}

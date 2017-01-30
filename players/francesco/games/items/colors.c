#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";
#define TP this_player()
#define TPN this_player()->query_name()
#define TO this_object()

reset(arg){
if (arg) return;
set_id("colors");
set_alias("table");
set_short(HIC+"COLORS"+NORM);
set_long("The only thing you can do is 'read colors'.\n"+NORM);
info = ({ });
}

init() {
  ::init();
    add_action("read_book","read");
  if(TP != environment(TO)) 
  return; 
}

read_book(str) {
     if (!str) {notify_fail("Read what?\n");return 0;}
     if(str == "colors") {
        write(WHT+"@  white\n"+HIG+"@  green\n"+HIR+"@  red\n"+HIB+"@  blue\n"+HIY+"@  yellow\n"+HIM+"@  pink\n"+HIC+"@  cyan\n"+NORM+YEL+"@  hunter\n"+MAG+"@  maroon\n"+NORM);
/*        write("w g r b y p c h m\n\n");
        write(WHT+"@ "+GRN+"@ "+RED+"@ "+BLU+"@ "+YEL+"@ "+MAG+"@ "+CYN+"@ \n"+NORM);
        write("w g r b y m c \n\n");*/
          return 1; }
return 1;}

get(stri) {
    if(stri == "table") {
     notify_fail("What??  You would like to remove the table?\n");
    return 0;}
return 0;}

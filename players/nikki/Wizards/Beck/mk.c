#include "/players/nikki/ansi.h"
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = HIB+"Blasting Zone!"+NORM;
long_desc = HIR+
 "             @@@@@@@@@@@@@@@@@@@@@@\n"+
 "         @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"+
 "      @@@@@@@@@"+GRY+"%%%%%%%%%%%%%%%%"+HIR+"@@@@@@@@@\n"+
 "     @@@@@@@@"+GRY+"%%%%%%%%%%%%%%%%%%%%"+HIR+"@@@@@@@@\n"+
 "    @@@@@@"+GRY+"%%%%%%%%%%%%%%%%%%%%%%%%%%"+HIR+"@@@@@@\n"+
 "   @@@@@"+GRY+"%"+HIR+"(MMM\\"+GRY+"%%%%"+HIR+"/MMM)"+GRY+"%"+HIR+"(KKKK)"+GRY+"%"+HIR+"/KKKK)"+GRY+"%"+HIR+"@@@@@\n"+
 "  @@@@"+GRY+"%%%"+HIR+"(MMMM\\"+GRY+"%%"+HIR+"/MMMM)"+GRY+"%"+HIR+"(KKKK)"+GRY+"%"+HIR+"KKKK)"+GRY+"%%%%"+HIR+"@@@@\n"+
 "  @@@"+GRY+"%%%%"+HIR+"(MMMMM\\/MMMMM)"+GRY+"%"+HIR+"(KKKK)/KKK)"+GRY+"%%%%%%"+HIR+"@@@\n"+
 "  @@"+GRY+"%%%%%"+HIR+"(MMMMMMMMMMMM)"+GRY+"%"+HIR+"(KKKK)KKK("+GRY+"%%%%%%%%"+HIR+"@@\n"+
 "  @@"+GRY+"%%%%%"+HIR+"(MMMM)\\/(MMMM)"+GRY+"%"+HIR+"(KKKK)KKK)"+GRY+"%%%%%%%%"+HIR+"@@\n"+
 "  @@"+GRY+"%%%%%"+HIR+"(MMMM)"+GRY+"%%"+HIR+"(MMMM)"+GRY+"%"+HIR+"(KKKK)KKKK)"+GRY+"%%%%%%%"+HIR+"@@\n"+
 "  @@"+GRY+"%%%%%"+HIR+"(MMMM)"+GRY+"%%"+HIR+"(MMMM)"+GRY+"%"+HIR+"(KKKK)(KKKK)"+GRY+"%%%%%%"+HIR+"@@\n"+
 "  @@@"+GRY+"%%%%"+HIR+"(MMMM)"+GRY+"%%"+HIR+"(MMMM)"+GRY+"%"+HIR+"(KKKK)"+GRY+"%"+HIR+"(KKKK)"+GRY+"%%%%"+HIR+"@@@\n"+
 "  @@@@"+GRY+"%%%"+HIR+"(MMMM)"+GRY+"%%"+HIR+"(MMMM)"+GRY+"%"+HIR+"(KKKK)"+GRY+"%%"+HIR+"(KKKK)"+GRY+"%%"+HIR+"@@@@\n"+
 "   @@@@@"+GRY+"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"+HIR+"@@@@@\n"+
 "    @@@@@"+GRY+"%%%%%%%%%%%%%%%%%%%%%%%%%%%"+HIR+"@@@@@@\n"+
 "     @@@@@@@@"+GRY+"%%%%%%%%%%%%%%%%%%%%"+HIR+"@@@@@@@@\n"+
 "      @@@@@@@@@"+GRY+"%%%%%%%%%%%%%%%%"+HIR+"@@@@@@@@@\n"+
 "         @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"+
 "            @@@@@@@@@@@@@@@@@@@@@@\n"+
 "\n\n"+NORM;

dest_dir = ( {
    "players/nikki/Museum/Duke/Rooms/room1", "right",
});
} }

realm() { return "NT"; }


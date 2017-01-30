#define tp this_player()->qury_name()
#include "/players/traff/closed/ansi.h"
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("rose");
   set_alias("yellow rose");
    set_short(GRN+"--'--,--<"+HIY+"@"+NORM);
   set_long(
    GRN+"-----'-----,-----<"+HIY+"@    @"+GRN+">-----'-----,-----"+NORM+"\n"+
"As rich and purposeless as is the rose:\n"+
"Thy simple doom is to be beautiful.\n"+
"\t\t\tStephen Phillips\n"+
    GRN+"-----'-----,-----<"+HIY+"@    @"+GRN+">-----'-----,-----"+NORM+"\n");
   set_weight(0);
   set_value(0);
}


/*  REDROSE.C - One of the roses sold by FLOWER_GIRL.C in room DMAIN.C
*/
#define tp this_player()->qury_name()
#include "/players/traff/closed/ansi.h"
inherit "obj/treasure";
reset(arg) {
  if (arg) return;
  set_id("rose");
  set_alias("red rose");
  set_short(GRN+"--'--,--<"+HIR+"@"+NORM);
  set_long(
  GRN+"-------'-----,-----<"+HIR+"@    @"+GRN+">-----'-----,-------"+NORM+"\n"+
  "Red Rose, proud Rose, sad Rose of all my days!\n"+
  "Come near me, while I sing the ancient ways.\n"+
  "\t\t\t\tW.B. Yeats\n"+
  GRN+"-------'-----,-----<"+HIR+"@    @"+GRN+">-----'-----,-------"+NORM+"\n");
  set_weight(1);
  set_value(50);
}


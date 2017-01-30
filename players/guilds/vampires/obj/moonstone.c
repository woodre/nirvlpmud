
#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

object obj;

int alignment_tally;

string moonstone_color, moonstone_msg;

reset(arg) {
  if (arg) return;
  ::reset(arg);

set_name("moonstone ring");
set_alias("moonstone");
set_short("moonstone ring");
set_long(
  "A beautiful moonstone ring.  It changes color according to the\n"+
  "atmosphere in the room.  The oval stone is set in an elegant\n"+
  "band and has an old english E cut into it's face.  The colors:\n"+
  "     Evil"+
  BOLD+BLK+"<======"+
  HIR+"<======"+
  HIY+"<======"+
  NORM+
      "   *   "+
  HIB+"======>"+
  HIC+"======>"+
  HIW+"======>"+NORM+
  "Good\n"+
  "reflect the makeup of the players present.\n");
set_type("ring");
set_value(250);
set_weight(1);
set_ac(0);
set_save_flag();
}

short() {
    if (!short_desc) return;
    tally_alignments();
  if(worn) return moonstone_color+" moonstone ring (worn)";
  return moonstone_color+" moonstone ring";
}

long(str) {
    tally_alignments();
    write(long_desc);
    write(moonstone_msg+".\n");
}

tally_alignments() {
  alignment_tally=0;
  obj=first_inventory(environment(environment(this_object())));
  while (obj) {
    alignment_tally+=obj->query_alignment();
    obj=next_inventory(obj);
  }

if(alignment_tally < -1000)
  moonstone_color = BOLD+"solid black"+NORM;
else if(alignment_tally < -600)
  moonstone_color = HIR+"fire red"+NORM;
else if(alignment_tally < -200)
  moonstone_color = HIY+"canary yellow"+NORM;
else if(alignment_tally < 201)
  moonstone_color = "crystal clear";
else if(alignment_tally > 1000)
  moonstone_color = HIW+"lilly white"+NORM;
else if(alignment_tally > 600)
  moonstone_color = HIC+"sky blue"+NORM;
else if(alignment_tally > 200)
  moonstone_color = HIG+"jade green"+NORM;
moonstone_msg="  (The moonstone is "+moonstone_color+")";
}

drop() {
  ::drop();
if(worn) {
  write("You remove the moonstone ring from your finger and drop it..\n"+
        "and with a "+HIY+"POOF"+NORM+" it disintegrates...\n");
  destruct(this_object());
  return 1; }
else{
  write("You drop the moonstone ring, and with a "+HIY+"POOF"+NORM+" it disintegrates...\n");
  destruct(this_object());
  return 1; }
return 1;
}

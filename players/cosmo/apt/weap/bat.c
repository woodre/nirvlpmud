#define tp this_player()->query_name()
#include "/players/cosmo/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("bat");
  set_alias("slugger");
  set_short(HIG+"Louisville Slugger"+NORM);
  set_long(
    "\nA hand-crafted wooden baseball bat of amazing\n"+
    "quality.  Weighing a mere 32 ounces with a length\n"+
    "of 36 inches, you know you could do some "+RED+"serious\n"+
    "skull-bashing"+NORM+" with this weapon. \n\n");
  set_type("club");
  set_class(16);
  set_weight(1);
  set_value(500);
  set_hit_func(this_object());
  set_message_hit(({"slam"," for a homerun","bash"," in the skull",
"smash"," across the chest","slam"," in the ribs","slice",
" with a glancing blow","graze"," in the shin","brush"," lightly"}));
}

weapon_hit(attacker){
int W;
  W = random(13);
  if(W>9)  {
    say("\n"+
      capitalize(tp)+" takes a mighty cut through the air.\n");
    write("\n"+
      "You take a mighty swing through the air.\n"+
      BLU+"W H O O S H !!"+NORM+"\n"+
      "The bat impacts on your prey's skull.\n"+
      RED+"C R A C K !!"+NORM+"\n"+
      "Blood trickles down to the ground.\n\n");
  return 5; }
return; }

wield(str){
  if (::wield(str) && wielded) {
    write("You tighten your grip and rear the bat for action.\n");
  return 1; }
}

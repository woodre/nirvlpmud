#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("wakizashi");
  set_alias("sword");
  set_short("Wakizashi");
  set_long("The blade of this short sword is made of\n"+
    "sturdy metal.  The blade has been\n"+
    "folded carefully and the tang is clean.\n"+
    "A well smithed weapon, a weapon that goes well\n"+
    "paired with the deadly katana.\n");
  set_class(14);
  set_weight(1);
  set_type("sword");
  set_value(2500);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(5);
if(W==1)  {
  say("The wakizashi stabs deep into its enemy!\n");
  write("You stab deep into your foe!\n");
return 3;
   }

if(W==0) {
  say(GRN+"The wakizashi's blade flares with green flame and the enemy is doused with FIRE!\n"+NORM);
  write(GRN+"The wakizashi flares with green flame and your foes is doused with FIRE!\n"+NORM);
return 7; }

   return;
}

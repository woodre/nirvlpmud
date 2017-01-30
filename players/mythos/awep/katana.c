#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("katana");
  set_alias("ksword");
  set_short("Katana");
  set_long("This gleaming sword is well made.  The metal has been well tempered\n"+
    "and the tang is well formed.  The handle of the sword is tightened enough\n"+
    "and the balance is at the hilt.  You recognize a sword of quality.\n");
  set_type("sword");
  set_class(18);
  set_weight(4);
  set_value(10000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(100);
if(W>70)  {
  say(BLU+"The katana slices through its foe, sending blood everywhere!\n"+NORM);
  write(BLU+"The katana slices through its foe!  Blood spurts everywhere!\n"+NORM);
return 0;
  }

if(W>50 && W <69) {
  say("As you hear the whisper of the air as the katana cuts through it,\n"+
    "and you hear the soft sound of metal biting flesh,\n"+
    "you hear the words:\n\t\t"+BOLD+
    "Death has come!\n"+NORM+"burn into your ears......\n");
  write("As you hear the whisper of the air as the katana cuts through it,\n"+
    "and you hear the soft sound of metal biting flesh,\n"+
    "you hear the words:\n\t\t"+BOLD+
    "Death has come!\n"+NORM+
    "burn into your ears.....\n");
return 5;}

if(W<11) {
  write("You feel the blade in your hand jump!\n"+
    "Something has occured....  it feels real good.....\n");
return 7;}
   return;
}

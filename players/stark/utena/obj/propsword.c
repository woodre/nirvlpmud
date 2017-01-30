inherit "obj/weapon.c";
#include "/players/stark/defs.h"
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("Bamboo Sword");
set_alias("sword");
set_short("Bamboo Sword");
set_long(
"This practice sword is made up of several strips of bamboo.  The \n"+
"tip of the sword is softened by a piece of leather.  The grip \n"+
"is longer than two hands.  This is a simple sword to practice \n"+
"kendo.\n");

set_type("sword");  /*  sword/knife/club/axe/bow/polearm  */
set_class(15);
set_weight(1);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>10)  {
  say("\n"+
  ""+this_player()->query_name()+" jumps backward into a crouch and lowers "+this_player()->query_possessive()+" head\n"+
  "     A shimmering aura grows around "+this_player()->query_name()+"\n"+
  "          A low growl erupts from "+this_player()->query_name()+"\n"+
  "               "+this_player()->query_name()+" lifts "+this_player()->query_possessive()+" head and jumps forward at "+attacker->query_name()+"\n");
say("  "+this_player()->query_name()+" "+HIM+"strikes"+NORM+" "+attacker->query_name()+" in the torso with all "+this_player()->query_possessive()+" ki.\n\n");

  write("\n"+
  "You jump backward into a crouch and lower your head\n"+
  "     A shimmering aura grows around you\n"+
  "          A low growl erupts from you\n"+
  "               You lift your head and jump towards "+attacker->query_name()+"\n");
write("  You "+HIM+"strike"+NORM+" "+attacker->query_name()+" in the torso with all your ki.\n\n");
  return 7;
   }
return;
}



#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("katana");
  set_alias("sword");
  set_short("Katana");
  set_long("This gleaming sword is well made.  The metal has been well tempered\n"+
    "and the tang is well formed.  The handle of the sword is tightened enough\n"+
    "and the balance is at the hilt.  You recognize a sword of quality.\n");
  set_class(18);
  set_weight(4);
  set_value(10000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
object other, other_weapon,atts;
int h,i,j;
if(random(3) ==0) {
i = 0;
atts = attacker;
other = all_inventory(this_player());
 for(h=0;h<sizeof(other);h++) {
   if(other[h]->weapon_class() && other[h] != this_object()) {
   i = 1; 
   other_weapon += ({other[h]}); 
   }
 }
 if(i) {
 j = random(sizeof(other_weapon)) + 1;
 if(j == sizeof(other_weapon)) j = j - 1;
 for(h=1;h<sizeof(other_weapon);h++) {
 write(other_weapon[h]->short());
 }
 write("\n");
 write(other_weapon[j]->short());
 write("\n");
 other_weapon[j]->weapon_hit(atts);
 return 0;
 } else {
  tell_room(environment(this_player()),
  BLU+"The katana slices through its foe,\n sending blood everywhere!\n"+NORM);
 }
return 3;}
return 0;}

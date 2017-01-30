/* Changed inherit file, and removed set_weapon_type, Dragnar 11/99 */
inherit "/obj/weapon";

reset(arg) {
   set_name("mace");
   set_alias("steel mace");
   set_short("Steel Mace");
   set_long("The weapon of choice for the warrior-priest's of Azrah, this\n"
+           "mace is made of high temperature forged steel. However it\n"
+           "takes great strength to wield effectively.\n");
  set_class(15); /* Changed from 16 to 15...The monster that is carrying this isn't very difficult. -Feldegast 1/26/01 */
   set_weight(3);
   set_value(1500);
   set_type("club");
   set_hit_func(this_object());
   
}

weapon_hit(attacker) {
/*
   if(call_other(this_player(), "query_attrib", "str") > random(21)) {
  same deal as other weapons.. chance is now set to 1 in 3 - Mythos <12-26-97>
*/
/* There's no reason to discard the strength check completely. -Feldegast 1/26/01
  if(!random(3)) {
*/
  if(call_other(this_player(), "query_attrib", "str") > random(60)) {
      write("Your mace slams into your opponent's skull with a thwak!\n");
      return 5;
   }
   return;
}

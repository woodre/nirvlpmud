/*
 * Tsunami, a powerful trident found on ~/water/mon/king
 * Hard to get and unstorable.
 */

inherit "obj/weapon.c";

#include "/players/snow/closed/color.h"
int food, drink;

 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("tsunami");
   set_alias("tsunami_elemental_obj");
    set_short(BLUE+"Tsunami"+OFF);
    set_type("polearm");
    set_long("As you look at this trident, you feel great power emanating \n"
             + "from it. This must be the legendary trident, Tsunami.\n");
    set_class(18);
    set_weight(3);
    set_value(8000);
    set_hit_func(this_object());
message_hit = ({
  "impaled"," with a mighty thrust",
  "skewered"," causing dreadful agony",
  "pierced"," with the trident's wicked tines",
  "ripped"," with a barbed tine",
  "poked"," with a vicious lunge",
  "prodded"," with gusto",
  "tickled"," with a weak push" });
}

weapon_hit() {
  int mystuff, mysoak;
  object att;
  mystuff = this_player()->query_stuffed();
  mysoak = this_player()->query_soaked();
  att = this_player()->query_attack();
  if(mystuff) {
    this_player()->add_stuffed(-1);
    food++; }
  if(mysoak) {
    this_player()->add_soaked(-1);
    drink++; }
  if(food >= 7) {
write(REV_BLUE);
    write("\n\tYou feel energy flow into you from Tsunami!\n\n");
write(OFF);
    this_player()->heal_self(random(4)+1);
    food -= 7; }
  if(drink >= 15) {
    tell_room(environment(this_player()), REV_BLUE+
    "\tWater blasts from "+this_player()->query_name()+"'s trident!\n\n"+
    "\t"+att->query_name()+" is FLATTENED by the blow!\n"+OFF);
    att->heal_self(-random(5)-4);
    drink -= 15; }
  if(!random(8)) {
  write(BLUE);
    write("\tTsunami quivers in your hand as it thirsts for blood!\n");
  write(OFF);
    return 4; }
  return;
}

query_save_flag() { return 0; }

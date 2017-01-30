#include "/players/snakespear/closed/ansi.h"
inherit "obj/weapon.c";
  reset(arg) {
   ::reset(arg);
   if (arg) return;
set_name("scepter");
set_alias("scepter of zultayne");
set_type("staff");
set_short(HIB+"Scepter "+HIW+"of "+GRY+"Zultayne"+NORM);
set_long("  This short staff is heavy and looks quite deadly.  The staff\n"+
         "has many nicks in it from being used in battle. Blood stained\n"+
         "blades protrude from the setting that holds a large ruby set\n"+
         "at the top of the staff.  This ruby is rather large and glows\n"+
         "a dangerous red color.  One can only wonder what powers\n"+
         "this short staff may hide within itself.\n\n");
set_class(18);
set_weight(3);
set_value(500);
  /* change to magical damage <illarion
set_hit_func(this_object());
*/
set_params("magical",0,"magic_hit");
}

query_wear() {
   return 1;
}
wearpon_breaks() {
   return 1;
}
magic_hit(attacker){
int W;

W = random(25);
/* This weapon is storable so the return must be 1/3 max unless notation for reason
   if(W > 8) {
*/
  if(W > 15) {
   say(HIW+"Lady Turton appears and blesses the scepter's graceful moves....\n"+
   GRY+"     Gargoyles swarm into the room.......\n\n"+
   HIR+"       B L O O D S H E D   R E I G N S  ! ! !\n\n"+
   GRY+"          The Gargoyles ascend into the sky.....\n\n"+NORM);
   write(HIW+"Lady Turton appears and blesses the scepter's graceful moves.\n"+
   GRY+"     Gargoyles swarm into the room....\n\n"+
   HIR+"       B L O O D S H E D   R E I G N S  ! ! !\n\n"+
   GRY+"           The Gargoyles ascend high into the sky....\n"+NORM);
   return 5;
 }
return;
 }

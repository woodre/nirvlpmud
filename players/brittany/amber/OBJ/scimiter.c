#include "/players/brittany/ansi"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("scimiter");
set_alias("sword");
set_short("A "+HIR+"jewelled"+NORM+" Scimiter");
set_long(
    "A sharp curved single-edged sword, with a jeweled ruby inset\n"+
"into the handle.  Thw sword glistens with a blazing light and\n"+
"looks very deadly.\n");

set_type("sword");  /*  sword/knife/club/axe/bow/polearm  */
set_class(16);
set_weight(3);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(8);
if(W>5)  {
  say(
   "The ruby glows as the sword strikes, deeply burning its foe.\n");

 write(
   "The  "+HIR+"Ruby  "+HIG+"G L O W S"+NORM+"  as the sword deeply slices its foe.\n\n"+

   "          "+HIR+"    F  L  E  S  H   B  U  R  N  S   "+NORM+"\n\n");
  return 3;
   }
return;
}

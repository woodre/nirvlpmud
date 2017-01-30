#include "/players/brittany/ansi"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
message_hit = ({
        ""+HIR+"grinded"+NORM+""," into fine particles",  /* massacre into small fragments */
         ""+HIG+"slashed"+NORM+""," with violent sweeping strokes",   /* smashed with a bone crushing  */
          ""+HIB+"inflicted"+NORM+"","'s chest with "+RED+"m"+BLU+"u"+YEL+"l"+GRN+"ti"+MAG+"p"+CYN+"l"+RED+"e"+NORM+" currents", /* hit very hard */
         ""+HIR+"dissipated"+NORM+"","'s arm into various "+HIW+"DiRecTioNs"+NORM+"",  /* hit hard  */
         ""+HIW+"disintegrated"+NORM+"","'s hand with high energy strikes",  /*  hit        */
         ""+HIY+"scorched"+NORM+"","'s skin slightly",   /*  grazed   */
         ""+HIY+"flashed"+NORM+""," into a blind stupor",  /* tickled in the stomach */
});

set_name("shakujo");
set_alias("staff");
set_short(""+HIY+"Shakujo"+NORM+" staff");
set_long(
   "A ring tipped staff, its strength comes from a force of thunderbolts.\n");

set_type("polearm");  /*  sword/knife/club/axe/bow/polearm  */
set_class(18);
set_weight(2);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(7);
if(W>5)  {
  say(
   "Huge thunderbolts skyrocket from the tip of the staff, striking into its opponent.\n");

  write(
   "Huge  "+HIY+   "T H U N D E R B O L T S"+NORM+   " skyrocket from the tip of the staff.\n\n"+
   ""+HIY+"         *  *   *            \n"+
   "                 *  *   *           \n"+
   "                         *     "+NORM+"\n\n");
  return 4;
   }
return;
}

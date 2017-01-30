/*******************************************************
 * This item is an ac 2 shield _AND_ a WC 17 weapon
 * The item is unique and only 1 can exist at any time
 * Again this item is UNIQUE, possibly a Quest Item
 * From: ~/monsters/ilstkarn/lava_dragon
 * 10/23/97 - waiting for approval of this object.
 ******************************************************/
/* APPROVED BY SNOW 5/28/98 */
/* No inherited files??  /boggle  - Rumplemintz 29-Sep-2009 */
/* Adding these so it loads - item doesn't work as it - would
 * need to be re-coded to be both an armor and a weapon
 * Rumplemintz 29-Sep-2009
 */
inherit "/obj/weapon.c";
inherit "/obj/armor.c";

#include <ansi.h>
#define ME capitalize(this_player()->query_name())
#define IT capitalize(attacker->query_name())
#define BT CYN+"-"+HIC+"* "+HIW
#define ET HIC+" *"+NORM+CYN+"-"+NORM
#define LS HIR+"Lava"+HIW+"Shield"+NORM

reset(arg){
 ::reset(arg);
  set_short(HIR+"Lava "+HIW+"Shield"+NORM);
  set_long(
  "This shield is made from the barbed scales of the "+HIR+"Lava Dragon"+NORM+".\n"+
  "The red shield is very warm to the touch, as if the heat of the Lava\n"+
  "Dragon still burns within.  Numerous barbed points protrude from the\n"+
  "dragon scales, and they might prove harmful for anyone who gets to close.\n");
  set_weight(1);
  set_value(5000);
  set_ac(2);                  /* ac 2 shield  */
  set_class(17);              /* wc 17 weapon */
  set_alias("lava shield");
  set_name("the "+HIR+"Lava "+HIW+"Shield"+NORM);
  set_alt_name("lavashield");
  set_type("shield");
  set_save_flag(1);
  set_hit_func(this_object());
  message_hit=({
    "stepped forward and "+BT+"BASHED"+ET, " with the "+LS,
    "swung the "+LS+" and "+BT+"CLOBBERED"+ET, "",
    "charged and "+BT+"RAMMED"+ET, " against a wall",
    HIW+"STABBED"+NORM, " with a shield full of "+HIR+"spiked barbs"+NORM,
    "stepped up and "+HIW+"SLAMMED"+NORM, " with the "+LS,
    HIW+"SLAMMED"+NORM+" into", "",
    HIW+"brushed"+NORM+" past", "",
  });
}

weapon_hit(attacker) {
  int i;

  if(random(50) < this_player()->query_attrib("str")) {
    int x;
    x = random(3);
    if(x == 0) {
      write(
      "You shout a glorious battle cry and "+HIW+"CHARGE "+NORM+IT+"!\n"+
      "You "+BT+"SMASH"+ET+" into "+IT+" and send it flying!\n");
      say(
      ME+" shouts a glorious battle cry and "+HIW+"CHARGES "+NORM+IT+"!\n"+
      ME+" "+BT+"SMASHES"+ET+" into "+IT+" and sends it flying!\n");
    }
    else if(x == 1) {
      write(
      "You race forward and "+HIR+"SLAM"+NORM+" the "+LS+" into "+IT+"!\n"+
      IT+" falls to the ground and gasps for breath!\n");
      say(
      ME+" races forward and "+HIR+"SLAMS"+NORM+" the "+LS+" into "+IT+"!\n"+
      IT+" falls to the ground and gasps for breath!\n");
    }
    else if(x == 2) {
      write(
      "You rush "+IT+" and "+BT+"IMPALE"+ET+" "+IT+" on your shield!\n");
      say(
      ME+" rushes "+IT+" and "+BT+"IMPALES"+ET+" "+IT+" on your shield!\n");
    }
    return 7;
  }
  return;
}


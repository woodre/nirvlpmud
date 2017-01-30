/* powergloves.c     Illarion Sep 2004
 * Gloves that allow a player to do extra damage in combat, but only by
 * powering the gloves, by destroying a corpse.  If the gloves aren't
 * powered they will suck hit points from the player.
 */

#include "/players/illarion/def.h"
inherit "/obj/armor.c";

int current_charge;

void reset(status arg) {
  if(arg) return;
  
  set_name("gauntlets");
  set_short("The Power Gauntlets of Olsa Tranpik");
  set_type("ring");
  set_ac(1);
  set_params("other|fire",1,0,0);
  set_long(
"Except for the palms, these gauntlets are made of substance that looks\n"+
"and feels like black metal.  They always feel cool to the touch, even in\n"+
"the presence of the most extreme heat.  In the palm of each gauntlet is\n"+
"a smooth, shiny oval of what feels like red stone, which isn't just\n"+
"cool to the touch, but cold.  Just inside each gauntlet is an inscription\n"+
"which the wise would probably read before wearing such gauntlets.\n");
}

void init() {
  ::init();
  add_action("cmd_read","read");
  add_action("cmd_feed","feed");
}

status cmd_read(string str) {
  if(!str || (present(str,this_player()) != this_object()
     && present(str,environment(this_player())) != this_object()))
    FAIL("Read what?\n");
  write("The inscription on the left gauntlet reads:\n"+
        "Let us feed upon the dead and we will grant you strength.\n"+
        "The inscription on the right gauntlet reads:\n"+
        "Feed us not and we will drain your strength.\n");
  return 1;
}

status cmd_feed(string str) {
  object corpse;
  string c_name;
  int extra_charge;
  if(worn_by != environment() || !str)
    return 0;
  corpse=present(str,environment(this_player()));
  if(!corpse)
    FAIL("The gauntlets can't feed on something that isn't there.\n");
  c_name=(string)corpse->query_name();
  if(!c_name)
    c_name=str;
  if(!corpse->is_corpse())
    FAIL("The gauntlets refuse to touch "+c_name+".\n");
  extra_charge=(int)corpse->query_ac()+(int)corpse->query_wc();
  extra_charge=extra_charge*((int)corpse->query_mhp())/200;
  IBUG("Corpse is worth "+extra_charge+"\n");
  write(format("You touch the "+corpse->short()+" with the palms of "+
    "your gauntlets.  The corpse turns into smoke, which swirls into "+
    "the gauntlets and vanishes!"));
  say(format(tp+" touches the "+corpse->short()+" with the palms of "+
    POSS(TP)+" gauntlets.  The corpse turns into smoke, which swirls "+
    "into the gauntlets and vanishes!"));
  current_charge+=extra_charge;
  if(current_charge > 500) {
    current_charge=500;
    write("The gloves seem satiated, for now.\n");
  }
  destruct(corpse);
  return 1;
}

status id(string str) {
  if(str=="generic_wc_bonus" && worn_by==environment()) return 1;
  return (int)::id(str);
}

int gen_wc_bonus() {
  int bonus;
  IBUG("Charge is: "+current_charge+"\n");
  bonus=1+random(5); /* 1-5 damage */
  if(bonus > current_charge) {
    tell_object(environment(),
"A sudden chill from your gauntlets seems to stab all the way to your heart!\n");
    IBUG("calling add_hit_point("+(current_charge-bonus)+")\n");
    environment()->add_hit_point(current_charge-bonus);
  }
  if(!random(10))
    tell_object(environment(),
"Power surges from your gauntlets into your arms as you strike!\n");
  current_charge -= bonus;
  if(current_charge < 0)
    current_charge=0;
  IBUG("Charge is: "+current_charge+"\n");
  return bonus;
}
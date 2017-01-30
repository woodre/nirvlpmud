#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
object player;

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("ugly club");
set_alias("club");
set_short(BOLD+"Ugly Club"+NORM);
set_long(
  "This gnarly club is definitely U-G-L-Y.  It has a bent handle\n"+
  "and a wart-covered head.  This is one of the 'uncoolest' weapons\n"+
  "going on the mud!\n");
set_type("club");  /*  sword/knife/club/axe/bow/polearm  */
set_class(1);
set_weight(1);
set_value(10);
call_out("thwap",10);
}

thwap() {
  int C;

  /* make sure we are being wielded first */
  if(!wielded_by){
    call_out("thwap", 10);
    return 1;
  }

  C = random(10);

  /* tell_object(wielded_by will give msg to the wielder */
  /* tell_room will show msg to everyone in the room */

  if(C > 6) {
  tell_object(wielded_by,
  "You grasp the club and firmly "+BOLD+"BASH"+NORM+" yourself in the back of the head!\n\n");
  tell_room(environment(wielded_by),
  capitalize(wielded_by->query_name())+" grasps the club "+
  "and firmly "+BOLD+"BASHES"+NORM+" himself in the head!\n\n");
  }

  else if(C > 3) {
  tell_object(wielded_by,
  "You smile as you "+BOLD+"CLUB"+NORM+" yourself in the right temple....\n"+
  "then you switch the club to your other hand....\n"+
  "and "+BOLD+"CLUB"+NORM+" yourself in the left temple!\n\n");
  }

  else {
  tell_object(wielded_by,
  "You hold the club with both hands.... center it in front\n"+
  "of your face and "+BOLD+"BAM, BAM, BAM!!!!  "+NORM+"Three strikes by the\n"+
  "ugly club.\n");
  }

  call_out("thwap", 10);
  return 1;
}

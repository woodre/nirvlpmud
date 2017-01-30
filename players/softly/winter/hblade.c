#include "/players/softly/misc/ansi.h"
 inherit "/obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("hunting knife");
    set_alias("knife");
    set_short("A hunting knife");
    set_long("A well-worn long hunting knife with an exceptional blade\n"+
             "and a stag horn handle.  Its blade is over a foot long.\n")+
             "with an exceptional edge.\n";
    set_type("knife");
    set_class(15);
    set_weight(2);
    set_value(850);
    set_hit_func(this_object());

  message_hit=({
    "ripped","",   
    "pierced","",
    "wounded","",
    "slashed","",
    "gouged","",
    "sliced","",
    "cut","",
  });
  return;
}

weapon_hit(attacker){

int X;
  X = random(8);
  if(X > 5){

    say  ("The knife catches and a"+HIR+" bloody"+NORM+" chunk\n"+
          "of flesh flies toward you.\n");

    write("The knife catches and"+HIR+" bloody"+NORM+" pieces\n"+
          "of flesh fly about the room.\n");

   return 3;

  }
}

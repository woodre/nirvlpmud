#include "/players/linus/def.h"
inherit "/obj/weapon.c";
int mon;
id(str) { return str=="sword" || str=="rusty sword"; }
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("rusty sword");
   set_short("A "+RED+"rusty"+NORM+" sword");
   set_long(
    "This sword was once a fine weapon used by the guards of the mighty\n"+
    "King Reuben.  Unfortunately, time and the elements have taken their\n"+
    "toll on this sword.  The hilt is barely held together, and the blade\n"+
    "is covered in rust.  Perhaps it is still functional, and may fetch a\n"+
    "decent price if sold to a collector or trader in artifacts.\n");
   set_type("sword");
   set_class(14);
   set_weight(1);
   set_value(1500);
   set_hit_func(this_object());
}
weapon_hit(attacker) {
int blah;
blah = random(5);
if(blah>3) {
 say("Some "+RED+"rust"+NORM+" falls from the blade as it strikes true.\n");
write("Some "+RED+"rust"+NORM+" falls from your blade as it strikes true.\n");
}
}
init() {
 ::init();
 add_action("pay_me","barter");
 mon = (2000+random(3000));
}
pay_me(str) {
 if(id(str)) {
 if(present("hank_the_ugly_barter_dude",environment(TP))) {
  write("Hank looks at you with a raised eyebrow.  'Where did you find such an\n"+
        "artifact?'  He studies the sword carefully then pauses in thought.  'It's\n"+
        "a bit rusty and worn, but still with a little work can be restored to its\n"+
        "original form.  I'll give you "+mon+" coins for it.'  Upon your acceptance,\n"+
        "he promptly hands you the coins.\n");
  say("Hank takes the sword from "+TPN+" and studies it carefully.  He then converses\n"+
      "with "+TPO+" briefly, then hands "+TPO+" some coins.\n");
 TP->add_money(mon);
 TP->add_weight(-1);
 destruct(TO);
 return 1;
}
 notify_fail("Do what?\n");
  return 0;
}
}

inherit "obj/armor";

#include <ansi.h>

reset(arg){
   ::reset(arg);
	set_short(HIBLK+"Tactical Gloves"+NORM);
  set_long(
"This is pair of black Kevlar Hard Knuckle Tatical gloves. They have\n\
a hook and loop closure at the wrist and are made with water repellent\n\
goat skin leather. The entire back of the hand and sides of the\n\
fingers are reinforced with Kevlar. The knuckles are molded Carbontek\n\
that protect them during hand to hand combat.\n");
   set_ac(2);
   set_weight(1);
   set_value(1500);
   set_name("gloves");
   SetMultipleIds( ({ "tactical gloves","tactical", "walkerobj"}) );
   set_type("gloves");
}

void init() 
{
  ::init();
}

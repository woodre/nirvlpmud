#define tp this_player()->query_name()
int w;
#include "/players/pestilence/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("booey knife");
  set_alias("knife");
  set_alt_name("booey");
  set_short("Booey Knife");
  set_long(
"This is a sharp booey knife that was owned by Jim Bob Johnson.  He used it\n"+
"to gut various animals.  The handle is wrapped with tape, and the blade looks\n"+
"to be extremely sharp.\n"
  );
  set_type("dagger");
  set_class(17);
  set_weight(2);
  set_value(3000);

  set_hit_func(this_object());

  message_hit=({
    ""+HIR+"obliterated"+NORM+""," with an extreme blow",  
    ""+RED+"eviscerated"+NORM+""," into small pieces",
    ""+HIK+"devastated"+NORM+""," into a pile of pulp",
    ""+HIK+"stabbed"+NORM+""," in the arm",
    ""+HIK+"punctured"+NORM+"","'s left eye with the blade of the knife",
    ""+BLU+"slashed"+NORM+""," across the chest",
    ""+HIG+"skinned"+NORM+""," across the face",
  });
}

weapon_hit(attacker){
w = random(20);

if(w > 15){
write("You "+HIK+"DEVASTATE "+NORM+ attacker->query_name()+" with a fierce slash.\n");
say(tp+ ""+HIK+" DEVASTATE "+NORM+ attacker->query_name()+" with a fierce slash.\n");
return 6;
}


}

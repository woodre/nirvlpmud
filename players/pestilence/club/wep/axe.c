#define tp this_player()->query_name()
int w, i;
#include "/players/pestilence/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name(""+YEL+"Wood Axe"+NORM+"");
  set_alias("wood");
  set_short("a "+YEL+"Wood Axe"+NORM+"");
  set_long(
"This is a large wood axe that belonged to Jamie Johnson.  He used this axe\n"+
"to cut many a tree down with.  The blade is extremely sharp.  The handle\n"+
"is made from wood with a rubber coating to make it more comfortable.\n"
  );
  set_type("axe");
  set_class(18);
  set_weight(5);
  set_value(2500);
  set_hit_func(this_object());

  message_hit=({
    ""+HIR+"evicerated"+NORM+""," making "+HIR+"blood"+NORM+" flow freely",   
    ""+RED+"destroyed"+NORM+""," with a massive blow to the head",
    ""+HIK+"devastated"+NORM+""," with a sharp blow",
    ""+HIK+"smashed"+NORM+""," with a devastating attack",
    ""+HIK+"crunched"+NORM+""," with the end of the axe",
    ""+BLU+"grazed"+NORM+"","'s cheek with the edge of the axe",
    ""+BLU+"skinned"+NORM+""," on the arm",
  });
}

weapon_hit(attacker){
int W;
W = random(40);
if((W>30) && (attacker->query_hp()>15)){
  attacker->hit_player(random(15));
  say(
  ""+environment()->query_name()+" swings the "+YEL+"wood axe"+NORM+", tearing through flesh, causing blood to flow from "+attacker->query_name()+".\n");

  write(
  "You swing the "+YEL+"wood axe"+NORM+" tearing through flesh, causing blood to flow from "+attacker->query_name()+". \n");

  return (1+ random(3));
   }

return 0;
}

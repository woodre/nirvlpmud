#define tp this_player()->query_name()
int w, i;
#include "/players/pestilence/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name(""+WHT+"Rolin's Axe"+NORM+"");
  set_alias("rolin's axe");
  set_short(""+WHT+"Rolin's Axe"+NORM+"");
  set_long(
"This is "+WHT+"Rolin's axe"+NORM+"  made from the finest steel found in the ancient land of Cahara.\n"+
"The hilt of the handle is neaty wrapped with leather to add comfortable use.  The curve of the\n"+
"blade is magnificent.  One glance at this weapon you can tell, it was made for a great fighter.\n"+
"A strong person could easily use this axe to cause alot of damage.\n"
  );
  set_type("axe");
  set_class(19);
  set_weight(7);
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
  ""+environment()->query_name()+" swings "+WHT+"Rolin's axe"+NORM+", with an intense might.\nThe axe\n\n"+HIR+"\t\tR I P S"+NORM+"\n\nthrough "+attacker->query_name()+"'s flesh with ease.\n");

  write(
  "You swing "+WHT+"Rolin's axe"+NORM+", with an intense might.\nThe axe\n\n"+HIR+"\t\tR I P S"+NORM+"\n\nthrough "+attacker->query_name()+"'s flesh with ease.\n");

  return (1+ random(3));
   }

return 0;
}

#define tp this_player()->query_name()
int w;
#include "/players/pestilence/ansi.h"
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name(""+HIY+"Queen Ant's leg"+NORM+"");
  set_alias("leg");
  set_short(""+HIY+"Queen Ant's leg"+NORM+"");
  set_long(
"This is one of the large rear legs of the "+HIY+"Queen Ant"+NORM+".\n"+
"The leg is long and seems very flexible.  It also appears to act as\n"+
"if it's still alive.  There is a "+CYN+"magical"+NORM+" aura surrounding the leg.\n"
  );
  set_type("polearm");
  set_class(19);
  set_weight(5);
  set_value(8000);
  set_hit_func(this_object());

  message_hit=({
    ""+HIR+"impaled"+NORM+""," through the heart",  
    ""+RED+"destroyed"+NORM+""," into small pieces",
    ""+HIK+"devastated"+NORM+""," into a pile of pulp",
    ""+HIK+"crushed"+NORM+""," over the head with the leg",
    ""+HIK+"punctured"+NORM+"","'s left lung",
    ""+BLU+"jabbed"+NORM+""," in the arm",
    ""+BLU+"prodded"+NORM+""," in the eye",
  });
}

weapon_hit(attacker){
 if(!attacker) return 0;
w = random(15);
if(w==0){
write(""+HIG+"The ant's leg comes to life and tears into "+attacker->query_name()+""+NORM+".\n");
say(""+HIG+"The ant's leg comes to life and tears into "+attacker->query_name()+""+NORM+".\n");
return 5;
}
if(w==1){
write("You "+HIK+"devastate "+NORM+ attacker->query_name()+" into small pieces.\n");
say(tp+ ""+HIK+" devastates "+NORM+ attacker->query_name()+" into small pieces.\n");
return 7;
}
if(w==2){
write(BOLD+BLK+"The leg vibrates violently"+NORM+".\n");
say(BOLD+BLK+"The leg vibrates violently in "+tp+"'s hands"+NORM+".\n");
}
if(w==3){
write(HIK+"In the middle of the attack the leg bends, striking another hit to "+attacker->query_name()+""+NORM+".\n"+
          ""+RED+"Blood"+NORM+" flies from "+attacker->query_name()+"'s body.\n");
say(HIK+"In the middle of the attack the leg bends, striking another hit to "+attacker->query_name()+""+NORM+".\n"+
          ""+RED+"Blood"+NORM+" flies from "+attacker->query_name()+"'s body.\n");
return 8;
}
if(w==4){
write("Death comes from the Ant.\n");
 if(attacker)
say("A Death leg maims "+NORM+attacker->query_name()+".\n");
return 3;
}
if(w==5){
write(""+HIY+"The Queen ant's leg moves like it's alive"+NORM+".\n"+
      "The leg digs itself deep into "+attacker->query_name()+"'s flesh leaving "+RED+"blood"+NORM+" flowing everywhere.\n");
say(""+HIY+"The Queen ant's leg moves like it's alive"+NORM+".\n"+
"The leg digs itself deep into "+attacker->query_name()+"'s flesh leaving "+RED+"blood"+NORM+" flowing everywhere.\n");
this_player()->add_hit_point(-10);
return 8;
}
if(w==6){
write("You"+HIK+" massacre the "+attacker->query_name()+" into tiny fragments"+NORM+".\n");
say(tp+""+HIK+" massacres the "+attacker->query_name()+" into tiny fragments"+NORM+".\n");
return 6;
}
if(w==7){
write("You massacre "+attacker->query_name()+" into tiny fragments"+NORM+".\n");
say(tp+" massacres "+attacker->query_name()+" into tiny fragments"+NORM+".\n");
}
if(w==8){
write("You hit "+attacker->query_name()+" very hard"+NORM+".\n");
say(tp+ " hits "+attacker->query_name()+" very hard"+NORM+".\n");
}

}

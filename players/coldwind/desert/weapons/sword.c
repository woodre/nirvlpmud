#include "/players/coldwind/define.h"
#define attacked (this_object()->query_attack())

inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("arabian sword");
SetMultipleIds(({"sword","arabian sword"}));
set_short(HIW+"A"+NORM+WHT+"rabia"+HIW+"n S"+NORM+WHT+"wor"+HIW+"d"+NORM);
set_long(HIW+
"  A beautiful sword crafted from silver alloys. The bravest\n"+
"Arabian knight, Fares, once carried this sword. Some red \n"+
"runes are carved on the blade close to the handle. The edge\n"+
"has been extremely sharpened and the handle has slight twists\n"+
"for the maximum holding. \n"+NORM);
set_type("sword");
set_class(18);
set_weight(4);
set_value(10000);
set_read("The red runes read:\n"+
         "                   "+HBWHT+RED+"                "+NORM+" \n"+
         "                   "+HBWHT+RED+" For The People "+NORM+" \n"+
         "                   "+HBWHT+RED+"  I Will Live,  "+NORM+" \n"+
         "                   "+HBWHT+RED+"       And      "+NORM+" \n"+
		 "                   "+HBWHT+RED+" For The People "+NORM+" \n"+
		 "                   "+HBWHT+RED+"  I Shall Die.  "+NORM+" \n"+
		 "                   "+HBWHT+RED+"                "+NORM+" \n");
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
string user;
user = (string)environment(this_object())->query_name();
W = random(30);
if(W>20)  {
  say(""+HIW+"The sword Guides "+user+"'s hand to fight better.\n"+NORM);
  write(""+HIW+"The sword Guides your hand to fight better.\n"+NORM);
return 7;
   }
if(W>15)  {
  say(""+ user +" jumps forward and "+NORM+RED+"Stabs "+NORM+ attacker->query_name() +NORM+" in the heart with a deadly attack.\n");
  write("You jump forward and "+NORM+RED+"Stab "+NORM+ attacker->query_name() +NORM+" in the heart with a deadly attack.\n");
            
if(attacker) {
attacker->hit_player(random(10), "magical");
   }
   if(W>12)  {
  say(""+ user +" descends upon "+ attacker->query_name() +NORM+" with quick attacks.\n"+
  ""+RED+"Chunks of flesh splatters everywhere"+NORM+".\n");
  write("You descend upon "+attacker->query_name() +NORM+" with quick attacks.\n"+
    ""+RED+"Chunks of flesh splatters everywhere"+NORM+".\n");            
if(attacker)
attacker->hit_player(5, "magical");
return 3;
   }
   if(W>8)  {
  say(""+HIK+ attacker->query_name() +HIK+" looks weaker as blood pours from the deep wounds...\n"+NORM);
  write(""+HIK+ attacker->query_name() +HIK+" looks weaker as blood pours from the deep wounds...\n"+NORM);
return 5;

   }
   if(W>5)  {
  say(""+user+"'s sword "+NORM+RED+"Cuts"+NORM+" through " +attacker->query_name() +NORM+ "'s flesh.\n"+
""+attacker->query_name() +NORM+" screams in pain.\n");
  write("Your sword "+RED+"Cuts"+NORM+" through "+attacker->query_name() +NORM+"'s flesh.\n"+
""+attacker->query_name() +NORM+" screams in pain.\n");            
if(attacker)
attacker->hit_player(5, "magical");
return 5;
   }
}
  return;
}

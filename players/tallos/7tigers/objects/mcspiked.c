
#include "/players/wocket/closed/ansi.h"
#define CO call_other
#define tp this_player()->query_name()
inherit "obj/weapon";
int a;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name(""+YEL+"Master"+HIB+"craft "+NORM+""+BLK+"Spiked "+YEL+"Chain "+NORM+"+1");
   set_class(18);
   set_weight(3);
   set_value(5000);
   set_type("mace");
   message_hit = ({
        BOLD+""+HIR+"DESTROYED"+NORM," using a back around neck swing with the "+NORM+""+BLK+"spiked "+YEL+"chain"+NORM+"!",
        BOLD+""+HIR+"MAN HANDLED"+NORM," with a "+HIR+"DIRECT HIT"+NORM+" to the head!",
        BOLD+""+HIR+"DECIMATED"+NORM," and nearly tripped them.",           
        BOLD+""+HIR+"SLAMMED"+NORM," deep in the belly",
        BOLD+""+HIR+"BONKED"+NORM," in the stomach",
        BOLD+""+HIR+"BOPPED"+NORM," on the leg",
        BOLD+"Grazed"+NORM," the target"
        });   
   set_alias("chain");
   set_alt_name("spiked chain");
   set_short(""+YEL+"Master"+HIB+"craft "+NORM+""+BLK+"Spiked "+YEL+"Chain "+NORM+"+1");
   set_long("                      "+NORM+""+YEL+"==="+BLK+"+++++++++++++++"+CYN+"Q"+NORM+"\n"+     
            "      A "+YEL+"master"+HIB+"craft"+NORM+" weapon is one made by a master in the\n"+
            "weapon smithing craft. The weight is perfect, the quality\n"+
            "is amazing, and the "+HIY+"value"+NORM+" is much higher then of a normal\n"+
            "weapon of the same type.  This "+NORM+""+BLK+"spiked "+YEL+"chain"+NORM+" is around six\n"+
            "feet long. It has an easy grip handle and a "+HIR+"deadly spiked\n"+
            ""+NORM+""+CYN+"mythril"+NORM+" ball at the end.    It is the weapon of a skilled\n"+
            "fighter.\n");
   set_hit_func(this_object());
   set_params("other|physical",0,"spiked_hit");
}
query_wear() {
   return 1;
}
weapon_breaks() {
   return 1;
}
int spiked_hit(object attacker){
 if(this_player())
if(call_other(this_player(),"query_attrib","dex") > random(80))
  {
  int a;
  a=random(10);
  if(a >= 4) {
    write("                      "+HIR+"T R I P ! ! !"+NORM+"\n"+
          "With a "+HIG+"graceful "+NORM+"swing you trip your opponant and then come down\n"+
          "on them hard with the "+NORM+""+BLK+"spiked "+YEL+"chain"+NORM+", as they lay helpless on the\n"+
          "ground.\n");
    say(BOLD+tp+" "+HIR+"TRIPS"+NORM+" their target and "+HIR+"SMACKS them on the head!\n"+
    " \n");    
    return random(9); 
  }
  return 0;
} 
}

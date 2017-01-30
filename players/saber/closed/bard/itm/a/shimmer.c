/*
 *  Armor for the Bardic Guild of Ryllian.
 *  The cloak can change colors (like a mood ring, without the mood)
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

inherit "obj/armor";

#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

string color, color2;

reset(arg){

   color  = "BLK";
   color2 = "black";

   ::reset(arg);
   
   set_name("shimmer cloak");
   set_short("A shimmer cloak");
   set_alias("cloak");
   set_long("A full body cloak of of shimmering black. "+
        "It has silver trim, and is very soft.\n"+
        "You can have the cloak change colors by typing: "+
        "< shimmer > < color >\n"+
        "Color choices are "+HIR+"red"+NORM+", "+HIG+"green"+NORM+", "+
        HIB+"blue"+NORM+", "+HIM+
        "magenta"+NORM+", "+HIC+"cyan"+NORM+", "+HIY+"yellow"+NORM+" and black.\n");
   set_type("misc");
   set_ac(1);
   set_weight(1);
   set_value(50);
        
        }

init()  {
  ::init();
  add_action("shimmer","shimmer");
  
       }


shimmer(str)  {

  if(!str)  {
    write("Syntax: shimmer < color >\n"+
          "Color choices are "+HIR+"red"+NORM+", "+HIG+"green"+NORM+", "+
          HIB+"blue"+NORM+",\n"+HIM+
          "magenta"+NORM+", "+HIC+"cyan"+NORM+", "+HIY+"yellow"+NORM+" and black.\n");
    return 1;
        }
  
  if(str != "red" && str != "green" && str != "blue" && str != "magenta" &&
         str != "cyan" && str != "yellow" && str != "black")  {
       write("You must choose a color.\n");
       return 1;
       }
  
switch(str)  {
  case "red"     : color = HIR; break;
  case "green"   : color = HIG; break;
  case "blue"    : color = HIB; break;
  case "magenta" : color = HIM; break;
  case "cyan"    : color = HIC; break;
  case "yellow"  : color = HIY; break;
  case "black"   : color = BLK; break;
  
  default: notify_fail("You must enter a color.  Syntax: shimmer < color >\n");
        }

  color2 = str;       
         
  this_object()->set_short("A "+color+"shimmer"+NORM+" cloak");
  this_object()->set_long(
       "A full body cloak of of shimmering "+color+""+color2+""+NORM+".\n"+
       "It has silver trim, and is very soft.\n"+
       "You can have the cloak change colors by typing:\n"+
       "< shimmer > < color >\n"+
       "Color choices are "+HIR+"red"+NORM+", "+HIG+"green"+NORM+", "+
       HIB+"blue"+NORM+", "+HIM+
       "magenta"+NORM+",\n"+HIC+"cyan"+NORM+", "+HIY+"yellow"+NORM+" and black.\n");

  write("Your cloak shimmers various "+
         HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM+
         " hues.\n"+
        "Slowly, the cloak turns "+color+""+color2+""+NORM+".\n");
  say(this_player()->query_name()+"'s cloak shimmers various "+
         HIR+"R"+RED+"A"+HIY+"I"+HIG+"N"+HIB+"B"+MAG+"O"+HIM+"W"+NORM+
         " hues.\n"+
        "Slowly, the cloak turns "+color+""+color2+""+NORM+".\n");
  
  return 1;
        }


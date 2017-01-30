/* Intox rate increased by Daranath, via spending of bug points Sept 12th, 2002 */

#include "/players/maledicta/ansi.h"
#define USER environment()
inherit "obj/armor";

string symbol;

reset(arg) {
if(arg) return;
 ::reset(arg);
set_name("shield");
set_alias("crystalline_shield_stone");
set_long(
"  This is the beautiful shield of crystal.  It was formed\n"+
"by the same Gods that created the original Crystalline\n"+
"armor.  It glistens with powerful energies that seem ready\n"+
"to erupt.  As the owner of the shield you may project the\n"+
"image you like upon the surface of it. To do this simply,\n"+
"'project <image>'.  To remove the symbol, 'project none'.\n");
set_ac(2);
set_type("shield");
set_weight(1);
set_value(15000);
}

short(){
int woot;
if(!symbol) woot = HIW+"Crystalline Shield"+NORM;
else woot = HIW+"Crystalline Shield ["+HIB+symbol+NORM+HIW+"]"+NORM;
if(worn) woot += " (worn)";
return woot;
}

get(){ 
if(this_player())
if(this_player()->query_real_name() != "stone" && this_player()->query_level() < 20){
write("You are unable to grasp such a powerful artifact!\n");
return 0;
}
return 1;
}

init(){
 ::init();
 add_action("set_symbol", "project");
 }

set_symbol(str){
  if(!str){ write("Project <symbol>\n"); return 1; }
  if(str == "none"){ symbol = 0; write("Symbol erased.\n"); return 1; }
  symbol = str;
  write("Symbol changed to: "+str+"\n");
  return 1;
  }

do_special(owner){
   if(random(90) < USER->query_attrib("piety") * 2){
   tell_object(USER,
   HIW+"The "+HIY+"light"+HIW+" of the shield shines forth!\n"+
   "       "+HIW+"-( "+HIB+"M Y S T I C A L     D E F E N S E"+HIW+" )-\n"+
   " You shine within the protective light of the Crystalline Shield!"+NORM+"\n");
   return 1;
   }
return 0;
}	
	

#include <ansi.h>
#include "/players/hogath/tools/def.h"
inherit "obj/weapon";

#define tdex this_player()->query_attrib("dex")
#define tluc this_player()->query_attrib("luck")


reset(arg) {
  
  ::reset(arg);
   if(arg) return;
    set_name(HIK+"obsidian dagger"+NORM);
    set_alias("dagger");
	set_short(HIK+"An Obsidian dagger"+NORM);
	set_long("\n"+HIK+
		"A vicious obsidian dagger.  It's blade is jagged and serated.\n"+
		"It is coated in some sort of vicious substance.  It's hilt is\n"+
		"wrapped in well worn leather.  It has seen much use."+NORM+"\n");
	set_class(18);
	set_weight(1);
	set_value(2000);
	set_type("dagger");
  set_params("other|acid",0,"acid_hit");
  set_hit_func(this_object());
  
}

int acid_hit(object attacker){
  string bpart;
  int W, i;
  switch(random(4)){
    case 1: bpart ="arm";break;
    case 2: bpart ="leg";break;
    case 3: bpart ="chest";break;
    case 4: bpart ="face";break;
    case 0:
    default : bpart ="wrist";break;
  }
  W = random(50);
  i = random(60);
  if (tdex > W){
    if(tluc > i){
    write("You "+HIK+"stab"+NORM+" "+atn+"'s "+bpart+"\n"+NORM+""+
          BOLD+"\n\tA C I D"+NORM+" "+HIR+" burns "+atn+"!\n\n"+NORM);
    say(tpn+" "+HIK+"stabs"+NORM+" "+atn+"'s "+bpart+"\n"+NORM+""+
        BOLD+"\nA C I D"+NORM+" "+HIR+"burns "+atn+".\n\n."+NORM);
         return 5;}
    if (tdex < i){
    write("You "+HIR+"stab"+NORM+" "+atn+" several times in the "+bpart+".\n"+
          "\t\t"+BOLD+"A C I D"+NORM+" eats into "+atn+".\n");
    say(tpn+" "+HIR+"stabs"+NORM+" "+atn+" several times in the "+bpart+".\n"+
            "\t\t"+BOLD+"A C I D"+NORM+" eats into "+atn+".\n");
    return 7;
    }          
  }
  return 0;
}
          

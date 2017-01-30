#include <ansi.h>
#include "defs.h"

status
main(string str)
{
if(!str){
 tell_object(this_player(),
 "Your choices are: "+HIR+"red\n"+
 "                  "+HIY+"yellow (yel)\n"+
 "                  "+HIG+"green (gre)\n"+
 "                  "+HIB+"blue (blu)\n"+
 "                  "+HIM+"magenta (mag)\n"+
 "                  "+HIC+"cyan (cya)\n"+
 "                  "+NORM+"none\n"+
 "                  "+HIG+"a"+HIB+"u"+HIY+"t"+HIR+"o"+NORM+"\n");
 return 1;
}

if(str == "red"){
        tell_object(this_player(),
"You set your monitor to "+HIR+"Red"+NORM+" highlights.\n");
 previous_object()->set_mon_color(HIR);
 return 1;
}
if(str == "yellow" || str == "yel" ){
        tell_object(this_player(),
"You set your monitor to "+HIY+"Yellow"+NORM+" highlights.\n");
 previous_object()->set_mon_color(HIY);
 return 1;
}

if(str == "green" || str == "gre" ){
        tell_object(this_player(),
"You set your monitor to "+HIG+"Green"+NORM+" highlights.\n");
 previous_object()->set_mon_color(HIG);
 return 1;
}

if(str == "blue" || str == "blu" ){
        tell_object(this_player(),
"You set your monitor to "+HIB+"Blue"+NORM+" highlights.\n");
 previous_object()->set_mon_color(HIB);
 return 1;
}

if(str == "magenta" || str == "mag" ){
        tell_object(this_player(),
"You set your monitor to "+HIM+"Magenta"+NORM+" highlights.\n");
 previous_object()->set_mon_color(HIM);
 return 1;
}

if(str == "cyan" || str == "cya" ){
        tell_object(this_player(),
"You set your monitor to "+HIC+"Cyan"+NORM+" highlights.\n");
 previous_object()->set_mon_color(HIC);
 return 1;
}

if(str == "none"){
        tell_object(this_player(),
"You set your monitor to No highlights.\n");
 previous_object()->set_mon_color(NORM);
 return 1;
}

if(str == "auto") {
        tell_object(this_player(),
 "You set your monitor to "+HIG+"a"+HIB+"u"+HIY+"t"+HIR+"o"+NORM+" highlights.\n");
 previous_object()->set_mon_color("auto"); 
 return 1;
}

tell_object(this_player(),
"That option is not available, please select one of the following:\n"+
"red, yellow, green, blue, magenta, cyan, none, auto \n"+
"For a more complete listing type moncolor.\n");
return 1;
}


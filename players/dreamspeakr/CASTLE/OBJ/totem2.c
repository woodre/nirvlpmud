#include "/players/dreamspeakr/closed/ansi.h"
#define NAME "Dreamspeakr"

inherit "/obj/treasure";

reset(arg) {
    if (arg)
	return;
    set_no_clean(1);
    set_id("totem");
    set_short(HIB+"Totem of Dreams"+NORM);
    set_long("\tTowering high above, this hand carved totem depicts \n"+
             "\tthe spiritual god or animal of many native american \n"+
             "\ttribes.  Carved with great detail, a large phoenix \n"+
             "\tperches on top, as though it were soaring up towards \n"+
             "\tthe heavens.  Perhaps if you were to '"+HIB+"listen to \n"+
             "\tphoenix"+NORM+"' it would tell you something.\n");
    set_weight(1000);
}

get(){ return 0; }

init() {
    add_action("listen","listen");
    add_action("guide","guide");

}
int listen(string str){
if(!str || str != "to phoenix"){
    notify_fail("What would you like to listen to?\n");
    return 0;
    }

write("\n"+
         "        From out of no where you hear a tribal drum begin to beat. \n"+
         "\n"+
         "                   The Phoenix lets out a loud cry:\n"+
         "\n"+
         "                 You notice the phoenix turn toward you...\n"+
         "           'So traveler, are you weary and want to return?, it asks.'\n"+
         "\n"+
         "\n"+
         "                        The voice continues:\n"+
         "\n"+
         "                If you wish I can '"+HIB+"guide"+NORM+"' you '"+HIB+"home"+NORM+"'\n"+
         "\n"+
         "\n"+
         "                The phoenix stops speaking.....\n"+
         "                     All is silent once again.\n"+
         "\n"+
         "\n");
   return 1;

}

int guide(string str){
if(str !="home"){
   notify_fail("Where would you like the phoenix to guide you?\n");
   return 0;
}

if(str == "home"){
   write("\n"+
         "            The Phoenix lets out a loud cry,\n"+
         "                 Large talons grab you and carry you off\n"+
         "                    High in the sky...\n"+
         "                      Then suddenly they release you.\n"+
         "                        Falling....\n"+
         "                          Falling....\n"+
         "                            Falling....\n"+
         "            \n"+
         "                         "+HIB+" S  W  O  O  S  H "+NORM+"\n"+  
         "             \n"+
         "             You land softly on a puffy "+HIW+"white cloud"+NORM+".\n"+
         "\n"+
         "\n"+
         "\n");
   say("The phoenix swoops down, grabs "+this_player()->query_name()+" and flys off into the sky.\n");
   move_object(this_player(),"/players/dreamspeakr/CASTLE/entrance.c");
   command("look",this_player());
   return 1;
}
}

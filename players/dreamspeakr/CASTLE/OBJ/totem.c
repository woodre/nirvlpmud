#include "/players/dreamspeakr/closed/ansi.h"
#define NAME "Dreamspeakr"
object receiver_ob;

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
    add_action("dream","dreams");

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
         "           'There are many tales I could tell you', it says.\n"+
         "                 'Today I have but one story to tell'\n"+
         "\n"+
         "\n"+
         "             the drums continue to beat in the background....\n"+
         "\n"+
         "\n"+
         "                        The voice continues:\n"+
         "             'My story today is of the Anasazi Tribe,'\n"+
         "\n"+
         "\tThe Anasazi were a great tribe from the state of Colorado.  \n"+
         "\tHigh upon mesa's tops they built their homes.  Until one \n"+
         "\tday they mysteriously disappeared.  I can '"+HIB+"guide"+NORM+"' you to\n"+
         "\tthe '"+HIB+"Anasazi"+NORM+"', as they were before they vanished, if you \n"+
         "\twish.\n"+
         "\n"+
         "                The phoenix stops speaking.....\n"+
         "                     All is silent once again.\n"+
         "\n"+
         "\n");
   return 1;

}

guide(str) {

if(str == "anasazi" || str =="Anasazi"){
   write("\n"+
         "            The Phoenix lets out a loud cry,\n"+
         "                 Large talons grab you and carry you off\n"+
         "                    High in the sky...\n"+
         "                      Then suddenly they release you.\n"+
         "                        Falling....\n"+
         "                          Falling....\n"+
         "                            Falling....\n"+
         "            \n"+
         "                         "+HIB+" S  P  L  A  S  H"+NORM+"\n"+  
         "             \n"+
         "             You land in a large river running through the canyon.\n"+
         "\n"+
         "\n"+
         "             You quickly swim to the shore,\n"+
         "                  get out of the water and dry yourself off.\n"+
         "\n");
   say("The phoenix swoops down, grabs "+this_player()->query_name()+" and flys off into the sky.\n");
   move_object(this_player(),"/players/dreamspeakr/mesa/mv1.c");
   return 1;
}
else {
  write("Which tribe would you like to guide you?\n"); return 1; }
}
dream(){
   object new;
   if(present("dream", this_player())){
    write("You already have a hot dream.\n");
    return 1;
   }
   new=clone_object("/players/dreamspeakr/closed/tools/dream_tell.c");
   move_object(new, this_player());
   write("You receive one HOT dream!!!\n");
   return 1;
}

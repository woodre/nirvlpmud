#include "/players/beck/esc.h"
id(str){
   return str == "war" || str == "memorial" || str == "war memorial";
}

short(){
return BLUE+"Angel Grove War Memorial"+OFF;
}

long(){
   write("The Angel Grove War Memorial.\n"+
      "This is where all the major events in Angel Grove happen.\n"+
      "Coming soon  'The Stars of the WWF'\n"+
      "");
   return 1;
}

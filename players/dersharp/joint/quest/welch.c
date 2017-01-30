inherit "room/room";
#include "ex.h"
reset(arg){
   if(arg) return;
   short_desc="Welch Avenue";
   long_desc ="  You are now in the middle of Welch Avenue.  You\n"+
              "smell what seems to be fresh bread coming from the\n"+
              "shop to the west.  To the north you see a QuickTrip\n"+
              "and a small bar.  To the west of Welch you see a \n"+
              "small sign.  Other than that the street looks\n"+
              "dead.\n"; 
   set_light(1);
   dest_dir=
	({
		Quest+"swelch","south",
		Quest+"rocks","west",
                Quest+"welch2","north",
	});
   items=
	({
		"sign"," The sign reads:  WELCOME!!!!!!!!\n"+
                       "                  Come in try our\n"+
                       "                  Famous Breadsticks",
	});
}

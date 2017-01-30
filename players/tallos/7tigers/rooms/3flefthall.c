#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" 3rd Floor Left Hall"+NORM;
long_desc = ""+HIG+"This is the "+HIC+"3rd floor west hallway"+HIG+" of the inn. Several\n"+
            ""+NORM+""+GRN+"rooms"+HIG+" line this passage on either side.   You can hear\n"+
            "the "+NORM+""+CYN+"sounds"+HIG+" of "+NORM+""+CYN+"people"+HIG+" in each room. The wonderful "+HIR+"smell"+HIG+"\n"+ 
            "of "+HIR+"roses"+HIG+" fills the air.  The "+HIB+"hallway"+HIG+" is "+NORM+"illuminated"+HIG+" by\n"+
            "many "+NORM+"continual light stones"+HIG+" along the "+NORM+""+YEL+"walls"+HIG+"."+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/maid1.c", 2);            

   add_smell("main","The wonderful smell of "+HIR+"roses"+NORM+" is in the air");
   add_smell("roses","The whole hall seems to produce this wonderful "+HIR+"f"+HIY+"l"+HIG+"o"+HIB+"w"+NORM+""+MAG+"e"+HIR+"r"+HIY+"y"+NORM+" odor");

   add_item("stones","These are simply stones set in the walls that give off light continually.");
   add_item("rooms","Several rooms on each side of the hall that are reserved for guests of the Inn. ");
   add_item("roses","You look for where the smell of roses is coming from but cannot seem to find it.");
   add_item("walls","The walls are different from a normal structure. They seem to plus with dimentional flux.\n"+
            "Hung on the walls are several unique "+HIB+"p"+HIG+"a"+HIR+"i"+HIB+"n"+HIG+"t"+HIR+"i"+HIB+"n"+HIG+"g"+HIR+"s"+NORM+".");
   add_touch("stones","The continual light stones feel cool to the touch and appear to not radiate heat.");
   add_item("hallway","This is the 2nd floor west hallway. The hallway has nothing but standard room suites.");
   add_item("paintings","Truly unique "+HIB+"p"+HIG+"a"+HIR+"i"+HIB+"n"+HIG+"t"+HIR+"i"+HIB+"n"+HIG+"g"+HIR+"s"+NORM+" from artists all over the planes.");
   add_listen("main","The sound of people can be heard from the rooms on either side of the hallway.\n"+
              "Its hard to make out what they are saying.");
dest_dir = ({
    PATH+"/room310.c","southeast",
    PATH+"/room320.c","southwest",
    PATH+"/room330.c","northeast",
    PATH+"/room340.c","northwest",
    PATH+"/3ftopstairs.c","east",
  });
set_light(1);
}

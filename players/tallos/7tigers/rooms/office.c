#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg){
  if(arg) return;

short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Manager's Office"+NORM;
long_desc = "   "+HIR+"This is the "+HIY+"office"+HIR+" of the "+HIM+"manager"+HIR+". There is a large\n"+
            ""+NORM+""+RED+"desk"+HIR+" and stacks of "+NORM+"papers"+HIR+" and "+NORM+"files"+HIR+" everywhere.  There\n"+
            "is a small wet "+NORM+""+YEL+"bar"+HIR+" in the corner and a enormous "+BLK+"mirror"+HIR+"\n"+
            "that takes up a great portion of one of the "+NORM+""+RED+"walls"+HIR+"."+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/manager.c");
   add_item("office","This is the office of the manager of the hotel. It is quite impressive.");
   add_item("mirror","Looking closely you see the mirror is accually a viewing portal.\n"+
                     "The mirror is broken up into several small viewing screens that\n"+
                     "view many areas of the hotel.");
   add_item("desk","It is made of red oak and is quite large. There are quite a few papers\n"+
                   "and files on the desk.");
   add_item("papers","They are several in number, and it looks like most of them are records\n"+
                     "and employee reports.");
   add_item("files","Files of empolyees and inventory lists take up the bulk of the stacks.");
   add_item("bar","It is a small wet bar that has many bottles of wine, and bourbons.");
   add_item("walls","Those not taken up by the large mirror are filled with paintings of all kinds.");
   add_item("paintings","They are tasteful and impressionist in nature. The manager has excellent\n"+
                        "understanding of art.");           
   add_smell("main","The wonderful musky smell is in the air.");
   
dest_dir = ({
    PATH+"/backroom.c","out",
  });
set_light(1);
}

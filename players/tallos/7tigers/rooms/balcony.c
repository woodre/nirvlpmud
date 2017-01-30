#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" 2nd Floor "+BLK+"Bal"+NORM+""+NORM+""+YEL+"co"+HIR+"ny"+NORM;
long_desc = "   "+YEL+"This beautiful "+BLK+"Bal"+YEL+"co"+HIR+"ny"+NORM+""+NORM+""+YEL+" over looks the floor below.\n"+
            "The "+HIY+""+BLK+"marble"+NORM+""+NORM+""+YEL+" of the "+HIY+""+BLK+"Bal"+YEL+"co"+HIR+"ny"+NORM+""+NORM+""+YEL+", "+HIY+"s"+BLK+"w"+HIY+"i"+BLK+"r"+HIY+"l"+BLK+"s"+NORM+""+NORM+""+YEL+" with "+HIY+"gold"+NORM+""+YEL+" and makes\n"+
            "for a breath taking view of the large "+HIR+"m"+HIY+"u"+HIG+"r"+HIB+"a"+HIC+"l"+HIM+"s"+NORM+""+NORM+""+YEL+" above. A\n"+
            "large statue of a "+HIY+"gold dragon"+NORM+""+NORM+""+YEL+" sits on the edge of the\n"+
            "railing.  Two huge wooden doors are here leading east\n"+
            "and west to the hotel rooms.  The "+HIY+""+BLK+"sta"+NORM+""+NORM+""+HIR+"irc"+NORM+""+HIY+""+BLK+"ase"+NORM+""+NORM+""+YEL+" continues\n"+
            "up to the 3rd floor or descends back down."+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/customer1.c", 2);             
   add_item("statue","A huge "+HIY+"gold dragon"+NORM+" statue with that sits on the railing over looking\n"+
	"the floor below. Its so life-like. It makes you want to touch it.");
  add_item("murals","The large ceiling lays acres of stone canvas for several scenes displaying\n"+
  "a multitude of different planes and dimensions of existence");
  add_item("floor","The floor below the balcony is the main hall. You see the people move below\n"+
                   "unaware that you look over them like a hawk over the land. The directory is\n"+
                   "directly below you.");
  add_item("doors","Large wooden door that lead into the long hallways containing rooms on this\n"+
                   "level");
  add_item("balcony","Made of marble and mixed with gold it over looks the floor below.");
  add_item("staircase","It is made of marble with a red carpet running up the center.");
  add_item("dragon","At first glance it does look very real but on closer examination its only a\n"+
                    "statue. It sits on the edge of the railing overlooking the floor below. You\n"+
                    "feel like you would like to 'touch' it.");
  add_item("gold","It runs in the cracks of the marble. The gold adds beautifully to the artistic\n"+
                  "look of this incredible hotel.");  
dest_dir = ({
    PATH+"/2frighthall.c","east",
    PATH+"/2flefthall.c","west",
    PATH+"/mainhall.c","down",
    PATH+"/3ftopstairs.c","staircase",
    });
set_light(1);
}
init() {
  ::init();
  add_action("touch","touch");
}
touch() {
  string str3;
  str3= PATH+"/dragonchambers.c";
  move_object(this_player(), PATH+"/dragonchambers.c");
  command("look",this_player());
  return 1;
}    

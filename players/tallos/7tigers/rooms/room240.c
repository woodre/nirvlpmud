#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
if(!present("adventurer",this_object()))
  move_object(clone_object("/players/tallos/7tigers/mobs/adventurer1.c"),this_object());
  move_object(clone_object("/players/tallos/7tigers/mobs/adventurer1.c"),this_object());
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Room 240"+NORM;
long_desc = "  "+HIB+"   This is "+HIC+"room 240"+NORM+""+HIB+" on the 2nd floor of the"+HIY+" 7 Tigers\n"+
            "Inn"+NORM+""+HIB+". There is a large "+NORM+""+YEL+"table"+HIB+" with two chairs on the far\n"+
            "left side of the room, and a huge four post "+NORM+""+CYN+"bed"+NORM+""+NORM+""+HIB+" on the\n"+ 
            "right.  A small table off to the side of the bed has a\n"+
            ""+HIY+"candle"+NORM+""+NORM+""+YEL+" holder"+NORM+""+HIB+" and a small "+BLK+"tin bowl"+HIB+". The entire room is\n"+
            "decorated in beautiful blue colors everywhere, from the\n"+ 
            ""+NORM+""+CYN+"drapes"+NORM+""+HIB+" on the windows to the "+NORM+""+CYN+"carpet"+NORM+""+HIB+" and"+NORM+""+CYN+" bedding"+NORM+""+NORM+""+HIB+"."+NORM+""+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/adventurer1.c",1);
items = ({
  "table",
  "A medium sized table with two chairs. It's made of oak", 
  "bowl",
  "This tin bowl is most likely a bed pan. It is polished bright and smooth",
  "window",
  "Outside the viewer can see a multitude of different horizons. Take your pick",
  "drapes",
  "They are made of silk and full of color",
  "holder",
  "A candle holder made of gold sits ready to be used",   
  "bed",
  "A large king sized four post bed made with beautiful cotton beding",
  "beding",
  "A set of wonderful silk, cotton, and wool beding that drapes the bed",
  "carpet",
  "Thick and comfortable to walk on, it matches the color of the room",
  
  });

dest_dir = ({
    PATH+"/2flefthall.c","out",
  });
set_light(1);
}

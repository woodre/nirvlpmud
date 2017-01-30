#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;

short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Room 310"+NORM;
long_desc = "  "+MAG+"   This is "+HIC+"room 310"+NORM+""+MAG+" on the 3rd floor of the"+HIY+" 7 Tigers\n"+
            "Inn"+NORM+""+MAG+". There is a large "+NORM+""+YEL+"table"+MAG+" with two chairs on the far\n"+
            "left side of the room, and a huge four post "+NORM+""+HIM+"bed"+NORM+""+MAG+" on the\n"+ 
            "right.  A small table off to the side of the bed has a\n"+
            ""+HIY+"candle"+NORM+""+NORM+""+YEL+" holder"+NORM+""+MAG+" and a small "+BLK+"tin bowl"+MAG+". The entire room is\n"+
            "decorated in fine lavender colors everywhere, from the\n"+ 
            ""+HIM+"drapes"+NORM+""+MAG+" on the windows to the "+HIM+"carpet"+NORM+""+MAG+" and"+HIM+" beding"+NORM+""+NORM+""+MAG+"."+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/dwarvenfighter1.c",1);
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
    PATH+"/3flefthall.c","out",
  });
set_light(1);
}

#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;

short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Room 330"+NORM;
long_desc = "  "+HIR+"   This is "+HIC+"room 330"+NORM+""+HIR+" on the 3rd floor of the"+HIY+" 7 Tigers\n"+
            "Inn"+NORM+""+HIR+". There is a large "+NORM+""+YEL+"table"+HIR+" with two chairs on the far\n"+
            "left side of the room, and a huge four post "+NORM+""+RED+"bed"+NORM+""+NORM+""+HIR+" on the\n"+ 
            "right.  A small table off to the side of the bed has a\n"+
            ""+HIY+"candle"+NORM+""+NORM+""+YEL+" holder"+NORM+""+HIR+" and a small "+BLK+"tin bowl"+HIR+". The entire room is\n"+
            "decorated in exquisite red colors everywhere, from the\n"+ 
            ""+NORM+""+RED+"drapes"+NORM+""+HIR+" on the windows to the "+NORM+""+RED+"carpet"+NORM+""+HIR+" and"+NORM+""+RED+" beding"+NORM+""+NORM+""+HIR+"."+NORM+""+NORM+"\n";
   add_object("/players/tallos/7tigers/mobs/elvenwizard1.c",1);
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

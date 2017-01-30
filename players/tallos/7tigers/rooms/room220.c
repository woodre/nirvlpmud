#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;

short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" Room 220"+NORM;
long_desc = "  "+GRN+"   This is "+HIC+"room 220"+NORM+""+GRN+" on the 2nd floor of the"+HIY+" 7 Tigers\n"+
            "Inn"+NORM+""+GRN+". There is a large "+NORM+""+YEL+"table"+GRN+" with two chairs on the far\n"+
            "left side of the room, and a huge four post "+NORM+""+HIG+"bed"+NORM+""+GRN+" on the\n"+ 
            "right.  A small table off to the side of the bed has a\n"+
            ""+HIY+"candle"+NORM+""+NORM+""+YEL+" holder"+NORM+""+GRN+" and a small "+BLK+"tin bowl"+GRN+". The entire room is\n"+
            "decorated in stylish green colors everywhere, from the\n"+ 
            ""+HIG+"drapes"+NORM+""+GRN+" on the windows to the "+HIG+"carpet"+NORM+""+GRN+" and"+HIG+" beding"+NORM+""+NORM+""+GRN+"."+NORM+"\n";
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

/* 
 * Forbin
 * Created:   2003.08.21
 * Last edit: 2003.11.11 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/snow/dervish/trials/trail1/"

string shortdisplay;

reset(arg) {
  if(arg) return;
  short_desc = YEL+"Desert of Jibboo"+NORM;
  long_desc = HIY+BYEL+
    "  The desert sands slip silently towards all horizons.  The      \n"+
    "ground here is extremely level and smooth, save for a few lumps  \n"+
    "in the desert sand and a slight mound the rises up near your     \n"+
    "feet.  There are no markings or other evidence of windblown paths\n"+
    "here - it is as if no wind ever blows here.                      \n"+
    "    You could travel in any of the compass directions.           \n"+NORM;
  add_item(({"desert","sand","sands","ground","desert sand","desert sands"}),
    "The sand appears untouched by the elsewhere omnipresent winds");
  add_item(({"horizon","horizons"}),
    "Desert sands melt away into the far distance");
  add_item(({"lump","lumps"}),
    "Four little hills of sand are apparent, and are laid out in a\n"+
    "square pattern");
  add_listen("main", 
    "You listen closely, but find no sound but silence in the air.\n"+
    "But is that low, humming noise coming from below you?\n");
  add_listen("desert", 
    "You hear a low, humming noise deep within the ground.\n"+
    "It sounds like highly frequent vibrating.\n");
  add_listen("sand", 
    "You hear a low, humming noise deep within the ground.\n"+
    "It sounds like highly frequent vibrating.\n");
  add_listen("sand", 
    "You hear a low, humming noise deep within the ground.\n"+
    "It sounds like highly frequent vibrating.\n");
  add_listen("ground", 
    "You hear a low, humming noise deep within the ground.\n"+
    "It sounds like highly frequent vibrating.\n");
  add_smell("main", 
    "You smell an acrid, almost electrical scent in the air.\n"); 
  add_touch("desert", 
    "Strangely, the sand here is cool as a bubbling brook in spring.\n");
  add_touch("sand", 
    "Strangely, the sand here is cool as a bubbling brook in spring.\n");
  add_touch("sands", 
    "Strangely, the sand here is cool as a bubbling brook in spring.\n");
  add_touch("desert sand", 
    "Strangely, the sand here is cool as a bubbling brook in spring.\n");
  add_touch("desert sands", 
    "Strangely, the sand here is cool as a bubbling brook in spring.\n");
  add_touch("ground", 
    "Strangely, the sand here is cool as a bubbling brook in spring.\n");
  add_touch("lump",
    "You feel a cool, clyindrical object that is obscured by the sand.\n");
  add_touch("lumps",
    "You feel a cool, clyindrical object that is obscured by the sand.\n");
  add_exit_msg("north", "You trudge off across the desert...\n",
	                    "trudges off across the desert.\n");
  add_exit_msg("northeast", "You trudge off across the desert...\n",
                            "trudges off across the desert.\n");
  add_exit_msg("east", "You trudge off across the desert...\n",
	                   "trudges off across the desert.\n");
  add_exit_msg("southeast", "You trudge off across the desert...\n",
	                        "trudges off across the desert.\n");
  add_exit_msg("south", "You trudge off across the desert...\n",
	                    "trudges off across the desert.\n");
  add_exit_msg("southwest", "You trudge off across the desert...\n",
	                        "trudges off across the desert.\n");
  add_exit_msg("west", "You trudge off across the desert...\n",
	                   "trudges off across the desert.\n");
  add_exit_msg("northwest", "You trudge off across the desert...\n",
                            "trudges off across the desert.\n");
  no_exit_display = 1;
  add_exit(ROOT+"rms/jibboo13.c","north");
  add_exit(ROOT+"rms/jibboo25.c","northeast");
  add_exit(ROOT+"rms/jibboo24.c","east");
  add_exit(ROOT+"rms/jibboo23.c","southeast");
  add_exit(ROOT+"rms/jibboo15.c","south");
  add_exit(ROOT+"rms/jibboo04.c","southwest");
  add_exit(ROOT+"rms/jibboo03.c","west");
  add_exit(ROOT+"rms/jibboo12.c","northwest");
  add_object(ROOT+"/obj/mound.c");
  shortdisplay = YEL+"Desert of Jibboo"+NORM;
}

short() { return shortdisplay; }

init() {
  ::init();
}

new_look() {
  short_desc = YEL+"Desert of Jibboo"+NORM;
  shortdisplay = YEL+"Desert of Jibboo"+NORM;
  long_desc = YEL+BYEL+
    "  The desert sands slip silently towards all horizons.  The      \n"+
    "ground here is extremely level and smooth, save for a few lumps  \n"+
    "in the desert sand and a small stone that lies near your feet.   \n"+
    "There are no markings or other evidence of windblown paths here -\n"+
    "it is as if no wind ever blows here.                             \n"+
    "    You could travel in any of the compass directions.           \n"+NORM;
  no_clean = 1;
}

new_look2() {
  short_desc = HIK+"The Pillars of Dar"+HIW+"'"+HIK+"Khune"+NORM;
  shortdisplay = HIK+"The Pillars of Dar"+HIW+"'"+HIK+"Khune"+NORM;
  long_desc = YEL+BYEL+
    "  The desert sands slip silently towards all horizons.  The   \n"+
    "ground here is extremely level and smooth, except for a small \n"+
    "stone that lies at your feet.  Four towering pillars dominate \n"+
    "the skyline and overshadow this area with an ominous presence.\n";
    "    You could travel in any of the compass directions.        \n"+NORM;
  add_touch("pillars",
    "Mystic energy flows into you as you place your hand upon one of\n"+
    "the Pillars.\n");
  add_touch(({"runes","glyphs","symbols"}),
    "You gently touch one of the glyphs, tracing its pattern carefully\n"+
    "and dilberately.  There is a flash of wonderful light, and you\n"+
    "know to pass beyond the Pillars you must speak the right words.\n");
}




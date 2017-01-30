#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/closed/guild/def.h"
inherit "/players/wocket/closed/guild/alt_village/room.c";

reset(arg){
    if(arg) return;
set_light(1);
short_desc = "Village Church";
long_desc = MAG+"Shadows loom in every direction.  Large trees cover the sky letting\n"+
    "very limited light filter through.  A strange myst covers there ground\n"+
    "were there should be underbrush.  The area is void of sound and life.\n"+NORM;
dest_dir = ({
  PATH+"alt_village/vill_green.c","south",
});
}
short(){ return "Village church"; }

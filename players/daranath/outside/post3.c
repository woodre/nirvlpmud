#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/outside/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= "Abandoned Qual'tor Outpost";
long_desc=
"The top of the outpost acted more like an observatory than a military\n"+
"installation, even though battlements still protect anyone standing here.\n"+
"A series of large, clear glass lenses are mounted upon the walls, \n"+
"facing in all directions.\n";

items=({
"top","The roof of the outpost has a curious combination of fortress and science lab",
"outpost","The abandoned outpost was left here by the forces of Qual'tor long ago",
"battlements","The battlements help protect during a fight or seige, especially effective\n"+
     "against arrows and crossbow bolts",
"lens","Each individual lens is special. Why not look at all the lenses",
"lenses","The lenses are large, clear pieces of glasses, curved to enhance vision.\n"+
     "Each lens has a metal rim with an individual area name for what it\n"+
     "is pointed at. You think you could "+CYN+"view"+NORM+" the "+CYN+"area"+NORM+" \n"+
     "listed on the rim. "+RED+"list"+NORM+" Will show all the areas",
"walls","The outer walls are enforced by battlements",
    });

    dest_dir=({
  ROOT+"post2.c","down",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("view_area","view");
add_action("list_areas","list");
}

search(){
write("Nothing has been disturbed in here for years. Thick dust covers all.\n");
  say(tp +" searches the area.\n");
 return 1;
}

list_areas(){
write("The following areas can be viewed through the lenses:\n"+
     CYN+"darkenwood, gundar, mountain, qualtor, vale "+NORM+"or"+CYN+" wyrmskull"+NORM+"\n");
return 1; 
}


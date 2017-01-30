inherit "room/room";
#include "/players/zeus/closed/all.h"       /*  guth17.c  */
#include "/players/zeus/closed/fl_demon.h"

int teleport, guth, clone;

reset(arg){

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;

    if(!present("gurther")){   clone = random(9);   switch(clone){
    case 0..6: break;
    case 7:  MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
    case 8: for(guth = 0; guth < 2; guth++)
              MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
    return 1; }}
 if(arg) return;

 short_desc="The Fallen Lands";
 long_desc=
"This is a faded path leading through a fairly dark part of the forest.\n"+
"In all directions the forest is very dense and dark, however off in the\n"+
"distance to the west light can be seen.  The path leads to the south\n"+
"and west from here.\n";
 set_light(1);
 items=({
  "forest",
"The forest is very dark all around the path.  The trees which primarily\n"+
"make up the forest rise high above your head.  To the west the forest\n"+
"gets much lighter",
  "trees",
"The towering evergreen and maple trees climb high into the sky.  They\n"+
"make the forest very dark and dense",
  "path",
"The path is faded here, as though it isn't used much.  Some twigs and\n"+
"branches lie scattered over it, as well as leaves from the trees",
  "leaves",
"Some brown and golden leaves lie amongst the other debris on the path",
  "branches",
"The branches of the trees block out much of the light that would\n"+
"otherwise light up the path.  There are also some dead branches\n"+
"lying on the path",
  "twigs",
"Some cracked and broken twigs lie amongst the other debris on the path",
 });
 dest_dir=({
   "/players/zeus/realm/taus/guth15.c",  "south",
   "/players/zeus/realm/taus/guth18.c", "west",
 });
}

void init(){
    ::init();
    add_action("s_dir", "south");
    add_action("w_dir", "west");
}

exit(){    if(this_player()) this_player()->clear_fight_area(); }
realm(){   if(teleport) return "NT";  }
okay_follow() { return 1; }

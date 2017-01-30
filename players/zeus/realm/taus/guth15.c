inherit "room/room";	/*  guth15.c  */
#include "/players/zeus/closed/all.h"
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
"You are in a fairly dense part of the forest, standing on a path that\n"+
"cuts through the trees.  At this point the path seems to intersect with\n"+
"another path, as it breaks off into four seperate directions.  The dense\n"+
"forest is a mass of darkness all around the path.\n";
 set_light(1);
 items=({
  "forest",
"The forest is very dark all around the path",
  "trees",
"The towering evergreen and maple trees climb high into the sky.  They\n"+
"make the forest very dark and dense",
  "sun",
"You can not see the sun from where you stand at the moment",
  "path",
"The fairly wide path is very beautiful, covered in a layer of brown\n"+
"and golden leaves.  It leads to the east and west",
  "leaves",
"Many brown and golden leaves of various shapes and sizes are spread\n"+
"out across the path.  They are very pretty",
 });
 dest_dir=({
   "/players/zeus/realm/taus/guth17.c", "north",
   "/players/zeus/realm/taus/guth16.c", "east",
   "/players/zeus/realm/taus/road7.c",  "south",
   "/players/zeus/realm/taus/guth14.c", "west",
 });
}

void init(){
    ::init();
    add_action("n_dir", "north");
    add_action("e_dir", "east");
    add_action("s_dir", "south");
    add_action("w_dir", "west");
}

exit(){    if(this_player()) this_player()->clear_fight_area(); }
realm(){   if(teleport) return "NT";  }
okay_follow() { return 1; }

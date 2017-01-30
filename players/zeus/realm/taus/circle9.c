inherit "room/room";	/*  circle9.c  */

int teleport;

#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

reset(arg){

  if(!present("flat stone"))
    MO(CO("/players/zeus/realm/OBJ/flat_stone.c"), TO);

 if(arg) return;

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;
 set_no_clean(1);

 long_desc=
"This is a very dark part of the forest.  Trees tower high above you\n"+
"in every direction, and there appears to be no way out of this place.\n"+
"Directly in front of you is a flat grey stone that is partially covered\n"+
"by the growth of the forest.  A soft white mist is drifting all around\n"+
"the trees, making the forest feel almost alive.  The mist seems to drift\n"+
"around the stone.\n";
 set_light(0);
 items=({
   "forest",
"The forest is very dark all around.  The drifting white mist makes\n"+
"the forest feel strangely alive.  You feel as though there is no\n"+
"where to go",
   "trees",
"The towering trees seem to exude darkness in this place.  The reach\n"+
"high above your head",
   "sky",
"Looking up, all that can be seen is darkness",
   "mist",
"The drifting white mist is all around this place, slowly moving between\n"+
"the trees.  It seems to be focused about the flat stone",
 });
}

short(){ return "The Fallen Lands"; }
exit(){    if(this_player()) this_player()->clear_fight_area(); }
realm(){  if(teleport) return "NT";  }

void init(){
  ::init();
  add_action("mist_n_dir", "north");
  add_action("mist_ne_dir", "northeast");
  add_action("mist_e_dir", "east");
  add_action("mist_se_dir", "southeast");
  add_action("mist_s_dir", "south");
  add_action("mist_sw_dir", "southwest");
  add_action("mist_w_dir", "west");
  add_action("mist_nw_dir", "northwest");
}

msg(object x){ tell_object(x, "You walk into the mist...\n\n"); }

string getdir(string x){
  if(!x)
    return "into the mist#players/zeus/realm/taus/circle4.c";
  else if(x == "north")
    return "into the mist#players/zeus/realm/taus/circle1.c";
  else if(x == "northeast")
    return "into the mist#players/zeus/realm/taus/circle3.c";
  else if(x == "east")
    return "into the mist#players/zeus/realm/taus/circle5.c";
  else if(x == "southeast")
    return "into the mist#players/zeus/realm/taus/circle7.c";
  else if(x == "south")
    return "into the mist#players/zeus/realm/taus/circle8.c";
  else if(x == "southwest")
    return "into the mist#players/zeus/realm/taus/circle6.c";
  else if(x == "west")
    return "into the mist#players/zeus/realm/taus/circle4.c";
  else if(x == "northwest")
    return "into the mist#players/zeus/realm/taus/circle2.c";
  else
    return "into the mist#players/zeus/realm/taus/circle4.c";
}

mist_n_dir(){
  msg(this_player());
  this_player()->move_player(getdir("north"));
  return 1;
}

mist_ne_dir(){
  msg(this_player());
  this_player()->move_player(getdir("northeast"));
  return 1;
}

mist_e_dir(){
  msg(this_player());
  this_player()->move_player(getdir("east"));
  return 1;
}

mist_se_dir(){
  msg(this_player());
  this_player()->move_player(getdir("southeast"));
  return 1;
}

mist_s_dir(){
  msg(this_player());
  this_player()->move_player(getdir("south"));
  return 1;
}

mist_sw_dir(){
  msg(this_player());
  this_player()->move_player(getdir("southwest"));
  return 1;
}

mist_w_dir(){
  msg(this_player());
  this_player()->move_player(getdir("west"));
  return 1;
}

mist_nw_dir(){
  msg(this_player());
  this_player()->move_player(getdir("northwest"));
  return 1;
}


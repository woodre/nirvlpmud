#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Chamber of Bone Portals";
    long_desc=
     "A series of portals lead from this chamber, each of the them\n"+
     "have a shimmering energy field within. The portals are made from\n"+
     "the bone of an ancient dragon, and stepping through the fields can\n"+
     "take you to the far corners of Nirvana.\n"+
     "\nPortals currently goto:\n"+
     "advance, chamber, church, crystal, lockers, qualtor\n\n"+
     "The portal to the south does not have an energy field about it.\n";

    items=({
     "dragon","The dragon died long ago at the hands of Sagal",
     "bone","Bone from an ancient dragon makes up each portal",
     "portal","Each bone portal stands at least eight feet tall and is about four\n"+
             "feet wide. The shimmering energy field is a doorway to another place",
     "energy","The energy within the bone portals shifts in color constantly",
     "south","South is the Necromancer Stronghold",
     "nirvana","Nirvana is full of life begging to be put down",
    });

    dest_dir=({
      "/players/daranath/guild/room/necro2.c","south",
    });

    }
  }

    init(){
      ::init();
add_action("search","search");
add_action("goto_church","church");
add_action("goto_advance","advance");
add_action("goto_lockers","lockers");
add_action("goto_qualtor","qualtor");
add_action("goto_chamber","chamber");
add_action("goto_crystal","crystal");
}

    search(){
    write("Bits of bone and areas of dried blood are all about the room.\n");
    say(tp +" searches the area.\n");
return 1; }

goto_church() {
this_player()->move_player("to the church#/room/church");
return 1; }

goto_chamber() {
this_player()->move_player("to the chamber of realms#/players/mythos/enterance");
return 1; }

goto_crystal() {
this_player()->move_player("to the dark crystal#/players/arrina/newbie/newbie1a");
return 1; }

goto_advance() {
this_player()->move_player("to the advance hall#/room/adv_guild");
return 1; }

goto_qualtor() {
this_player()->move_player("to Qual'tor#/players/daranath/qualtor/entry");
return 1; }

goto_lockers() {
this_player()->move_player("to the lockers#/players/catwoman/tl");
return 1; }


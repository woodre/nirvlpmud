#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("guard"))  {
move_object(clone_object("/players/saber/closed/bards/bardguard.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc="Bard Guild Enterance";
long_desc=
 "You stand at the entrance to the Headquarters of the Bards Guild of\n"+
 "Ryllian.  The door to the north is guarded by two large men wearing\n"+
 "black chainmail.  To the west you see a chamber filled with musical\n"+
 "instruments.  South is what appears to be some sort of lounge.  The\n"+
 "stairs run both down to the common room of Orins Inn, and up to a\n"+
 "wooden door.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "enterance","You stand at the enterance to the Bards Guild of Ryllian",
 "door","There are doors leading north and south",
 "men","There are two large guild standing just inside the Bards Guild\n"+
    "They look really buff",
 "stairs","The stairs run up to some sort of door and down to Orin's Inn",
 });

  dest_dir=({
 "/players/saber/closed/bards/bardrooms/common.c","north",
 "/players/saber/closed/bards/bardrooms/guest.c","south",
 "/players/saber/closed/bards/bardrooms/object.c","west",
 "/players/saber/closed/bards/bardrooms/alliance.c","up",
 "/players/saber/ryllian/orin2.c","down",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

realm()  { return "NT"; }

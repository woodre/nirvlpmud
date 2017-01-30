#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
if(!present("coffin"))  {
move_object(clone_object("/players/saber/fur/selcoffin2.c"),this_object());  }
 if(!arg){
  set_light(0);
 short_desc="Mountain Crypt";
long_desc=
 "You are at the bottom of a large icy pit.  With the faint illumination now\n"+
 "present it is apparent that you are standing upon a floor of cold crimson\n"+
 "fire.  The flames from the dark fire have lowered the temperature in this\n"+
 "rocky chamber to near freezing.\n";

items=({
 "ground","The ground is covered with cold crimson flames",
 "coffin","In the middle of the rocky chamber is a sleek black\n"+
    "coffin, hovering several inches above the floor",
 "floor","Cold crimson flames of dark fire, the aura of which chill you to the bone",
 "flames","Cold crimson flames of dark fire, the aura of which chill you to the bone",
 "fire","Cold crimson flames of dark fire, the aura of which chill you to the bone",
 "chamber","A rocky chamber with a floor of dark fire",
 "pit","A rocky chamber with a floor of dark fire",
 });

  dest_dir=({
 "/players/saber/tower/tower20+9.c","up",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
  write("You find nothing.\n");
say (tp +" searches the area\n");
 return 1;  }

realm() { return "NT"; }

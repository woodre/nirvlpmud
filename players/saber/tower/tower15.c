#define tp this_player()->query_name()
inherit "room/room";
reset(int arg){
if(!present("The Dark One")) {
 move_object(clone_object("/players/saber/monsters/darkone.c"),this_object());
 }

 if(!arg){
  set_light(1);
 short_desc="The Dark Circle";
long_desc=
 "You stand within a dark chamber.  The only obvious feature in\n"+
 "this void is a twenty foot length wide circle of glowing crimson \n"+
 "runes.  Within this circle stands a dark portal.\n";

items=({
 "chamber","You stand in some sort of dark chamber",
 "circle","The circle is composed of crimson runes",
 "portal","The portal leads back to the land of Ryllian",
 "floor","The floor is covered with crimson runes",
 });

  dest_dir=({
 "/players/saber/tower/tower11.c","portal",
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


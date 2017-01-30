#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Amongst a myriad of webs";
  long_desc=
  "The natural walls of the UnderDark continue within this area, but a\n"+
  "dramatic change has overtaken the tunnel. The ceiling is overrun with\n"+
  "a dark, thick layer of spiderwebs, extending from wall to wall and\n"+
  "running the length of the tunnel. Chills run along your spine as you\n"+
  "imagine what lies within the webbing.\n";

items=({
 "paths", "The paths lead further into the darkness",
 "tunnels", "The tunnels are naturally formed by forces long since gone from\n"+
            "this area. They lead off different paths into the darkness",
 "walls", "The rough hewn walls surround you, encasing you within the\n"+
          "darkness all about",
 "webs", "The spider webs are thick and dark, running along the ceiling",
 "webbing", "The webbing is thick and dark, running along the ceiling",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/sp_haven2.c","east",
 "/players/daranath/underdark/level1/sp_haven4.c","southwest",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing amongst the dirt.\n");
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }

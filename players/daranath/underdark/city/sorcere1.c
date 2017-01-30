#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Deep within the tower of Sorcere";
  long_desc=
  "Crossroads within the tower of Sorcere\n";

items=({
  "trail", "The rocky trail leads up out of the cavern",
  "floor", "The cavern floor is covered with a layer of dirt",
 });

  dest_dir=({
 "/players/daranath/underdark/city/landing5.c","east",
 "/players/daranath/underdark/city/sorcere2.c","west",
           });
  }
}

init(){
 ::init();
  add_action("search","search");
}

search() {
write("You feel uneasy about poking around within the arcane tower.\n");
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
realm() { return "NT"; }

#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

  set_light(-1);
  short_desc="Tier Breche";
  long_desc=
  "Crossroads within the tower of Sorcere\n";

items=({
  "trail", "The rocky trail leads up out of the cavern",
  "floor", "The cavern floor is covered with a layer of dirt",
 });

  dest_dir=({
 "/players/daranath/underdark/city/landing4.c","north",
 "/players/daranath/underdark/city/main8.c","south",
 "/players/daranath/underdark/city/landing3.c","east",
 "/players/daranath/underdark/city/landing2.c","west",
           });
  }
}

init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing about the Tier Breche.\n");
say (tp +" searches the area.\n");
 return 1;  }

arate() { return "YES"; }
realm() { return "NT"; }

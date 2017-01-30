#define tp this_player()->query_name()
#define TP this_player()
inherit "room/room";

int SEARCH;
object ob;

reset(int arg){
 if(!arg){
 set_light(0);
  short_desc="Caves of Mist";
  long_desc=
"You stand in a small cave behind the waterfall.\n";

items=({
 "cave","You are in a small cave behind the waterfall",
 "waterfall","There is a waterfall to the north",
 });

  dest_dir=({
 "/players/saber/closed/quest/maze/mz13.c","north",
      });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
  if(SEARCH == 1)  {
  write("You find a pair of boots.\n");
  say(tp+" picks up something.\n");
  SEARCH = SEARCH + 1;
  ob = clone_object("/players/saber/closed/quest/items/boots.c");
  move_object(ob, this_player());
  return 1;
        }
write("You find nothing.\n");
say (tp +" searches the area\n");
  SEARCH = SEARCH + 1;
 return 1;  }

realm()  {  return "NT";  }

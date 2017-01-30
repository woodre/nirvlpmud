#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("priest"))  {
move_object(clone_object("/players/saber/closed/quest/larn/larnguard.c"),this_object());  }
 if(!arg){

set_light(1);
short_desc = "The Church of Larn";
long_desc=
 "The church sanctum is shadowed in the dusk of twilight, lit ever\n"+
 "so faintly by the soft glow from the multi-colored stained glass\n"+
 "windows facing west towards the silver moon.  To the north is the\n"+
 "altar, while there are arches leading to hallways both west and east.\n"+
 "There are many pew benches here.\n";

items=({
 "sanctum","You are in the sanctum of the Church of Larn",
 "church","You are in the sanctum of the Church of Larn",
 "windows","There are many beautiful stained glass windows here.\n"+
   "Each one pictures a different aspect of the god Larn",
 "moon","You can not see the moon from here",
 "altar","The altar is to the north",
 "benches","There are many pew benches here on which to sit",
 });

dest_dir=({
 "/players/saber/closed/quest/larn/larn1.c","west",
 "/players/saber/closed/quest/larn/larn3.c","east",
 "/players/saber/closed/quest/larn/enter.c","south",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("pray","pray");
  add_action("sit","sit");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

pray()  {
  write("You feel that you should go up to the altar to pray.\n");
  say(tp+" bows "+this_player()->query_possessive()+" head.\n");
  return 1;
        }

sit(str)  {
  if(str == "pew" || "pews")  {
  write("You sit down in one of the many pews.\n");
  say(tp+" sits down in a pew.\n");
  return 1;
        }
        }

realm()  { return "NT"; }

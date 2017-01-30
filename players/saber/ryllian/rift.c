#define tp this_player()->query_name()
inherit "room/room";
object light;
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="A rift";
long_desc=
  "You are hurtling through a rift that spans the void which exists between\n" +
  "worlds.  The only feature in this eternity of nothingness is soft white\n" +
  "light growing steadily brighter in front of you.\n";

items=({
 "light", "A soft white illumination of ethereal consistancy",
 "ground","There is no ground under you",
 });

  dest_dir=({
 "room/sunalley1","out",
 "/players/saber/ryllian/ryllian1","in",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("in","in");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

in()  {
if(this_player()->query_name() == "xxxx" ||
  this_player()->query_name() == "xxxx")
        {
  write("You have been banned from Ryllian.\n"+
  "Try attacking players of your own level.\n"+
  "I do not tolorate betrayal\n"+
  "Live with it.\n");
  return 1;
        }
        }

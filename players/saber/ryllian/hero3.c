#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("dragon"))  {
move_object(clone_object("/players/saber/monsters/hero/bdragon.c"),this_object());  }
 if(!arg){
  set_light(0);
short_desc="Tower of Heros";
long_desc=
 "You stand in a martial arts dojo.  The walls are covered with bright\n"+
 "oriental style paintings, and the walls with polished silver mirrors.\n"+
 "You get a feeling of peace.\n";

items=({
 "paintings","The paintings depict the history of many styles of martial arts",
 "mirror","You see a reflection of yourself",
 });

  dest_dir=({
 "/players/saber/ryllian/hero4.c","up",
 "/players/saber/ryllian/hero2.c","down",
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

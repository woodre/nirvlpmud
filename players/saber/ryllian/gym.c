#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("monk_book")){
  move_object(clone_object("/players/guilds/warriors/OBJ/trainer_monk"), this_object());
}
if(!present("blue"))  {
move_object(clone_object("/players/saber/monsters/martist1.c"),this_object());  }
if(!present("gray"))  {
move_object(clone_object("/players/saber/monsters/martist2.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc="A martial arts gym [dojo]";
long_desc=
 "You stand in a what is obviously a dojo.  The floor is covered with soft white\n"+
 "pads, and the walls are lined with well polished mirrors.  The ceiling is lost\n"+
 "behind the brightly painted images of the celestial court.  To the southwest\n"+
 "you see an exit into the city of Ryllian, while in the north corner stands a\n"+
 "portal leading to the monks guild.  On the wall hangs a simple [wooden sign].\n";

items=({
 "floor","The floor is covered with soft white pads",
 "wall","The walls are covered with well polished mirrors",
 "mirrors","You see your reflection in a dozen different places",
 "mirror","You see a plesant image of yourself",
 "ceiling","The ceiling is covered with painted images",
 "pads","Soft white pads cover the floor",
 "court","You see images of the emperors celestial court upon the ceilin",
 "images","The images are of the celestial emperior and his court",
 "exit","T he exit leads to the city of Ryllian",
 "sign","The sign reads:\n"+
   "You may practice your martial arts here.  Type 'kata' to begin.\n"+
  "Walk with the circle",
 });

  dest_dir=({
 "/players/saber/ryllian/ryll6.c","southwest",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("kata","kata");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

kata()  {
 write("You begin to practice your martial arts with slow, graceful movements.\n");
say(tp+" begings the slow, graceful movements of a kata.\n");
return 1;   }


#define tp this_player()->query_name()
inherit "room/room";
object light;
int t;
reset(int arg){
if(!present("scroll"))  {
move_object(clone_object("/players/saber/stuff/flier.c"),this_object());  }
if(!present("golem")) {
move_object(clone_object("/players/saber/monsters/stoman.c"),this_object());
}
if(!present("sign")) {
move_object(clone_object("/players/saber/stuff/sign.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Rift's End";
long_desc=
 "It is night, and you feel a slight chill in the air as the breeze tugs\n" +
 "softly at your hair.  You stand on a well kept road which runs south to\n" +
 "the city of Ryllian and west towards a green valley.  To the north is\n" +
 "the rift which will return you to the realms of Nirvana.\n";

items=({
 "road", "A well kept road leading from the Green Valley\n"+
  "to the City of Ryllian",
 "ground","The ground is covered with lush green grass",
  "rift","A rift in time and space",
  "city","The seaport of Ryllian",
 });

  dest_dir=({
 "/players/saber/ryllian/rift.c","rift",
 "/players/saber/ryllian/mountain1.c","north",
 "/players/saber/ryllian/gv1.c","west",
 "/players/saber/ryllian/gv4.c","east", /* added back by Mal - 4.30.01 */
 "/players/saber/ryllian/ryllian2.c","south",
           });
        }
        }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }


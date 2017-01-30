#define tp this_player()->query_name()
inherit "room/room";
reset(int arg){
if(!present("mirror"))  {
move_object(clone_object("/players/saber/stuff/mmirror.c"),this_object());  }
if(!arg){
  set_light(1);
  set_no_clean(1);
  short_desc="Ayre of Power";
long_desc=
 "You stand atop the highest peek of Sylith, most majestic of the mountains\n"+
 "which make up the range known as the Spine of the Moon.  From here you can\n"+
 "see all of Ryllian stretching out below you.\n";

items=({
 "peek","You stand atop the highest peek of Slyith",
 "ryllian","You see all of Ryllian stretching out below you",
 });

  dest_dir=({
  "/players/saber/ryllian/mountain2.c","down",
           });
} }

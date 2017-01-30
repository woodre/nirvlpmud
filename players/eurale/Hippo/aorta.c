inherit "room/room";
int i,j;

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("ery")) { for(i=0;i<3;i++) {
  move_object(clone_object("/players/hippo/c/ery.c"),this_object()); }}
if(!present("leuco")) { for(i=0;i<2;i++) {
  move_object(clone_object("/players/hippo/c/leuco.c"),this_object()); }}
if(!present("thrombo")){
  move_object("/players/hippo/c/thrombo.c",this_object()); }

short_desc = "The aorta";
long_desc =
  "  This is the largest artery of the body that carries blood from the left\n"+
  "ventricle of the heart to all organs and parts except the lungs.\n";

dest_dir = ({
  "players/eurale/Hippo/lvent","heart",
  "players/eurale/Hippo/carotis","carotis",
  "players/eurale/Hippo/blood1","down",
});

}

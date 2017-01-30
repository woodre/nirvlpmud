inherit "players/nightshade/new_room";
reset(arg) {
if(arg) return;
  set_light(1);
  short_desc = "Road";
long_desc =
"The small road you are on looks as if it has been well used. Up\n"+
"ahead you see why. There is a small wagon with some simple looking  \n"+
"people in it. It is drawn by a couple of shoddy looking horses.\n"+
"On either side of you are grain fields, swaying in the breeze.\n"+
"From this you gather the people here are simple farmers.\n";
dest_dir =
({
"players/nightshade/rum/19", "west",
"players/nightshade/rum/10", "east",
});
}

inherit "players/nightshade/new_room";
reset(arg) {
if(arg) return;
  set_light(1);
  short_desc = "Cave Trail";
  long_desc = 
"The trail ends up ahead of you about 10 feet or so. You see that it is the\n"+
"entrance to this cave that you are in. You breath a sigh of relief as you\n"+
"draw nearer to getting out.\n";
dest_dir=
({
"players/nightshade/rum/8", "north",
"players/nightshade/rum/3", "west",
});
}

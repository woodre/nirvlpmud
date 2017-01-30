inherit "room/room";
object ninja;
init() {
	::init();
}
reset(arg) {
  if(!present("bigfoot",this_object())){
	ninja=clone_object("/players/emerson/mons/bigfoot.c");
	move_object(ninja, this_object());
  }
	if(arg) return;
set_light(1);
short_desc=("A freezer");
long_desc=
"As you enter the freezer, you feel as if you aren't alone, as if\n"+
"someone or something is watching you as you enter. You wonder what\n"+
"could be hiding in the dark corner of the freezer.\n",
items=
({
"dark corner","It looks like a giant Sasquatch, better known as Bigfoot!",
"corner","It looks like a giant Sasquatch, better known as Bigfoot!",
});
dest_dir=
({
"players/emerson/rooms/room24.c","south",
});
}

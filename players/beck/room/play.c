inherit "room/room";
reset(arg) {
if(!present("putty 1", this_object())){
move_object(clone_object("/players/beck/monster/putty.c"), this_object());}
if(!present("putty 2", this_object())){
move_object(clone_object("/players/beck/monster/putty.c"), this_object());}
if(!present("putty 3", this_object())){
move_object(clone_object("/players/beck/monster/putty.c"), this_object());}
if(!present("putty 4", this_object())){
move_object(clone_object("/players/beck/monster/putty.c"), this_object());}
if(!present("putty 5", this_object())){
move_object(clone_object("/players/beck/monster/putty.c"), this_object());}
if(!present("putty 6", this_object())){
move_object(clone_object("/players/beck/monster/putty.c"), this_object());}
	if(arg) return;
set_light(1);
short_desc=("Playground");
long_desc=
"This is a childrens playground.  There is a junglegym, comprised\n"+
"of an array of bars, a slide pole, and a slide.\n"+
"Unfortunatly you are not alone.  Several of Lord Zed's creatures\n"+
"are here to 'play' with YOU.\n",
items=
({
});
dest_dir=
({
"players/beck/room/park5.c","east",
});
}

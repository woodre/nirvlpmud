inherit "/players/nightshade/new_room";
reset(arg) {
if(arg) return;
  set_light(1);
  short_desc  =  "Cave";
  long_desc =
"The path leads you to this point. The entrance to the cave is to\n"+
"north of you. Claw marks adorn the wall here. You large, dark\n"+
"stains on some parts of the wall. You think of blood.\n";
dest_dir=
({
"/players/nightshade/rum/3", "east",
"/players/nightshade/rum/6", "north",
});
}

inherit "room/room";

#define tp this_player()->query_name()
reset(arg) {
if (!arg) {
set_light(1);
}
short("Cargo Bay 1");
long("This is a cargo bay.  As you can gusss, it is filled with b
"and various scraps.  You hear a small hiss coming from the south \n"+
"wall.  Keep on guard here.\n";
}
init() {
add_action ("listen","listen");
add_action ("smell","smell");
add_action ("search","search");
}
listen() {
write("You hear the sound of air being sucked out of the room. Hull Breach.\n");
return 1;
}
smell() {
write ("There is faint aroma of human sweat coming from the west.\n");
return 1;
}
search() {
write ("NADA...ZILTCH..NOTHING..NO MORE...GET IT????\n");
return 1;
}

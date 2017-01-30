inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="A NOTICE FROM HEROIN";
items=({
"change", "change"});
dest_dir=({
"/room/plane5","whiners",});
long_desc=
"I apologize for the inconvience but there are some TEMPORARY\n"+
"difficulties w/ my realm. Im going to keep it closed until the\n"+
"mess gets worked out.  \n"+
"Once again, sorry about the inconvience.  <<*HEROIN*>>\n";
}
init(){
::init();
add_action ("drop","drop");
add_action("listen","listen");
add_action("search","search");
}
realm () {return "NT";}
drop(str) {
string all;
command ("drop all", this_player());
move_object (this_player(), "/room/church");
write ("You are the ridicule of all Nirvana--but you're alive!\n");
say (tp + "is judged as weak and is sent away.\n");
return 0;
}
search(){
write("You find nothing that can help you.\n");
say(tp + "is desperate.\n");
return 1;
}
listen(){
write("You hear your heart thumping.\n");
say(tp + "begins to shake.\n");
return 1;
}

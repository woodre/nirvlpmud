inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="change";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/change.c","direction",
"players/heroin/hunting_grounds/change.c","direction"});
long_desc=
"fill me in\n"+
"end\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("change\n");
say(tp + "change\n");
return 1;
}
listen(){
write("change\n");
say(tp + "change\n");
return 1;
}

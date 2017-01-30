inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="The roof";
items=({
"batlight","This is Comm. Gordon's famous batlight. Whenever\n he needs to contact batman, he uses the light"});
dest_dir=({
"/players/heroin/hunting_grounds/gordqrtrsu.c","down",
"players/heroin/hunting_grounds/caves.c","batlight"});
long_desc=
"You have made your way to the roof of Gotham city Hall and\n"+
"find nothing but pigeon shit and a huge light.  At least you\n"+
"can get a chance to get some fresh air and admire scenic, gothic\n"+
"Gotham.  It is a typical night that is, overcast, damp, dark and\n"+
"yes- depressing.  As you look over the edge of building you  \n"+
"notice the city streets.  You notice that there seems to be an\n"+
"over abundance of manholes.  With that much work below Gotham,\n"+
"you begin to wonder if there is anything interesting down there?\n"+
"You decide maybe you should check it out sometime.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You find some bird shit.\n");
say(tp + "sticks their hand in some bird dung.\n");
return 1;
}
listen(){
write("Thes sounds of a city in pain are very clear tonight\n");
say(tp + "puts their ear to the wind\n");
return 1;
}

inherit "room/room";

#define tp this_player()->query_name()
int i;
object obj;
inherit "room/room";
reset (int arg){
if (!arg){
set_light(1);
}
if(!present("beaver")) move_object(clone_object("/players/heroin/hunt_newbies/beav.c"), this_object());
if(!present("wally")) move_object(clone_object("/players/heroin/hunt_newbies/wally.c"), this_object());
short_desc="The Beaver's Bedroom";
items=({
"change", "change"});
dest_dir=({
"players/heroin/hunt_newbies/hallway.c","east"});
long_desc=
"You have found the Beaver and Wally sitting in the Beaver's bedroom\n"+
"talking about life.  The room is filled with sterotypical, little\n"+
"boy things.  On the dresser, is a slingshot and a baseball mitt.\n"+
"However upon closer examination, you realize all the toys are just\n"+
"props.  Hmm, oh well, at least the boys themselves are real.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
object ob;
if(random(100) < 80){ write("You search but find nothing.\n"); return 1; }
if (i == 0) {
write("You find half of an apple\n");
say(tp + "tucks something away into their jacket.\n");
ob = clone_object("/players/heroin/hunt_newbies/apple");
move_object(ob, this_player());
i++;
return 1;}
write("You have everything\n");
return 1;
}
listen(){
write("You hear nothing but the Beaver and Wally's annoying voices.\n");
say(tp + "covers their ears and exclaims: SHUT UP!!!\n");
return 1;
}

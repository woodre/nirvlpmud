inherit "room/room";

#define tp this_player()->query_name()
int i;
object obj;
inherit "room/room";
reset (int arg){
if(arg) return; /* added by verte */
if (!arg){
set_light(1);
}
if (!present("gordo")) move_object(clone_object("/players/heroin/hunting_grounds/gordo.c"), this_object());
short_desc="Commissioner Gordon's office";
items=({
"newspaper","The headline on the newspaper reads: Batman scared \n shitless. Gotham under siege"});
dest_dir=({
"/players/heroin/hunting_grounds/gordqrtrs.c","down",
"players/heroin/hunting_grounds/roof.c","up"});
long_desc=
"You must have taken a wrong turn for you were just walking up\n"+
"the stairs, and now you are in Gordon's office.  Gordon is on\n"+
"the phone, and from the sounds of it, he isn't very happy. With\n"+
"him on the phone, you have a chance to look around the room.  \n"+
"There isn't anything really out of the ordinary here: big oak desk,\n"+
"pictures of the young'ins, various medals and awards, and a black\n"+
"leather pair of bat-undies..uh wow...<ouch>.  You quickly shove the\n"+
"undies in your pocket thinking of potential blackmail.  You continue\n"+
"to examine the office; on the desk is a newspaper.  Just as you get \n"+
"ready to further examine the paper, Gordon quickly turns around. \n"+
"He looks directly at you and sees the undies dangling from your\n"+
"pocket.  You must have failed in your attempt at hiding them, but\n"+
"at least, you got a good chuckle at the expense of batman.  However,\n"+
"your main problem at the moment is one pissed Commish.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("search","search");
}
kill(str){
object test;
test =(present("counter",this_player()));
if (test) { test->inc_count();}
}
search(){
object ob;
if(random(100) < 80){ write("You find nothing of interest.\n"); return 1; }
if (i==0) {
write("Congrats! You now own a XXL pair of Batman's underwear.\n");
say(tp + "holds something up to their face\n");
ob = clone_object("/players/heroin/hunting_grounds/undies");
move_object (ob, this_player());
i++;
return 1;}
write("Go away piggy-its already looted.\n");
return 1;
}
listen(){
write(".....and with Batman in hiding , I really dont know how to save Gotham from that madman\n");
say(tp + "eavesdrops\n");
return 1;
}

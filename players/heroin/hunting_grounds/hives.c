inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if(!present("alien")) move_object(clone_object("/players/heroin/hunting_grounds/momma.c"), this_object());
short_desc="The Inner Nest";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/corr2.c","flee",
"players/heroin/hunting_grounds/alley.c","whine"});
long_desc=
"You should pat yourself on the back for making it this far\n"+
"however, all your past problems will be as water off your back\n"+
"compared to your psresent danger.  You are now in what used to be\n"+
"the main engine room.  Now there is no resemblance of this room's past\n"+
"Now this room, is the inner most hive of the mother alien.  As far\n"+
"as you can see are nothing but pods.  Before you stands one of the\n"+
"universe's most perfect creatures and her creation...The only\n"+
"thing that matches her perfection in form, is her perfection in \n"+
"aggression.  Today IS a good day for you to die.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("kill","kill");
add_action("read","read");
add_action("search","search");
}
kill(str){
object test;
test = (present("counter",this_player()));
if (test) { test-> inc_count();}
}
search(){
write("You find a card.  Better read it.\n");
say(tp + "picks something up\n");
return 1;
}
read(){
write("The card reads:  BooHoo Hoo \n     Sorry to hear about your recent lose..\n                         of your life.\n                XOXOXOX Angst\n");
say (tp + "starts to whimper and says: Sniff Sniff I knew he cared\n");
return 1;
}
listen(){
write("You hear Angst's laughter: Just whimper like a failure\n");
say(tp + "covers thier ears\n");
return 1;
}

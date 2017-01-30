inherit "room/room";
 
#define tp this_player()->query_name()
realm() {return "NT";}
 
reset (arg){
if (!arg){
set_light(5);
}
short_desc = "The Safety of Limbo";
long_desc =
"You are in limbo between Heroin's domain and the Predator world.\n"+
"If you are being hunted, you are but one move from safety.\n"+
"There is only one method of escape type OUT. \n"+
"There is no pride in escape.  MUHAMUHAMUHAAAA            \n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
add_action("kill","kill");
   add_action("read","read");
add_action("out","out");
   add_action("search","search");
}
kill(str){
object test;
test=(present("counter", this_player()));
if (test) {test->inc_count();}
}
out(){
object predator;
if(present("predator", this_object())){
predator = present("predator", this_object());
destruct(predator);
/*
while (predator) {
if (living(predator)) {
if (predator->query_attack()) {
(predator->query_attack())->stop_fight();
predator->stop_fight();
}
}
predator = next_inventory(predator);
}
*/
move_object(this_player(),"/players/heroin/hunting_grounds/hunt1.c");
command("look", this_player());
return 1; }
else {
if (!present("predator")) {
move_object(this_player(), "/players/heroin/hunting_grounds/hunt1.c");
command("look",this_player());
return 1;
}}}
search(){
write(" Its a secret...Im not telling you!\n");
say(tp + "ponders the situation \n");
return 1;
}
smell(){
write("Something's burning-SNIFF SNIFF..Shit its you..KILL THE CORD\n");
say (tp + "turns and sniffs his burning ass.\n");
say (tp + "says: can u sniff your own butt?\n");
return 1;
}
listen(){
write("In the distance, you could swear you hear someone selling\n popcorn and beer.  Sounds like its coming from the north.\n");
say(tp + "begins to drool and rub his tummy\n");
return 1;
}
       

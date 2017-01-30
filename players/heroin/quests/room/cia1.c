inherit "room/room";

#define tp this_player()->query_name()
inherit "room/room";

reset (int arg){
if(!present("director")) {
move_object(clone_object("/players/heroin/quests/director.c"), this_object());
}
if (!arg){
set_light(1);
short_desc="CIA Headquarters";
long_desc = 
"You are in the bustling offices of the CIA.  To your left you see\n"+
"another room..The rest are offices filled with busy agents.  Don't\n"+
"even think of bothering them! If, however, the director is not here\n"+
"type <whistle> and he should come running.\n";
dest_dir=({
"/players/heroin/hunting_grounds/hunt1.c","out",
"/players/heroin/quests/room/cia2.c","west",});
} }
init(){
::init();
#ifndef __LDMUD__
         add_action("my_say"); add_xverb("'");
#else
           add_action("my_say","'",3);
#endif
   add_action("my_say","ask");
add_action("judge_me","whistle");
   add_action("glue","glue");
add_action("portal","portal");
  add_action("listen","listen");
  add_action("smell","smell");
   add_action("search","search");
}
smell(){
write("The air here has no fragrance...it is just emptiness.\n");
say(tp+" breathes in the air here.\n");
return 1;}
listen(){
write("You hear the hustle and bustle of people solving crimes.\n");
say(tp+" perks up their ears.\n");
return 1; }
portal(){
object badge;
if(present("badge",this_player())) {
write("You feel all that you were become nothing.......\n"+
"and return to form!\n");
move_object(this_player(),"/players/heroin/quests/room/hitler1.c");
command("look",this_player());
return 1;}
else{
write("Sorry, You are not employed by the Elders\n");
return 1;
}
}
my_say(str) {
string a, b;
if(!str) {
write("Ask what???\n");
return 1; }
write ("You ask:"+str+"\n");
if(sscanf(str,"%swhere%s",a,b) ==2 ) {
if(!present("director")) {
write("You have killed the director, how can you ask him anything?\n");
return 1;
}
write("Oh yeah I forgot to mention that, use the PORTAL to go to the nazis.\n");
 
return 1;}
else {
if(sscanf(str,"%skhan%s", a,b) == 2|| sscanf(str, "%sgenghis%s",a,b) ==2) {
write("Khan, Khan, Oh yeah Genghis...Hmmm last I heard the could be found in WAR.\n");
return 1; }
else {
if(sscanf(str,"%sjob%s",a,b) ==2) {
if(present("badge",this_player())){
write("You already have a job!\n");
return 1;}
if(!present("director")) {
write("What do ya want a job as a mortician..dont kill your employer\n");
return 1;}
write("Yes we do...You may not know this but we work for the\n"+
"elders.  For centuries, we have been in charge of maintaining the\n"+
"laws of the hunt.  And for nearly as long, we have been tracking\n"+
"a creature who has managed to f**k up eons of work.  Find this\n"+
"menace and stop him.  Remember many of your foes are\n"+
"immortals...You can't kill what does not live...THINK human!!\n"+
"Hmmmmm..let me see....\n"+
"I left it here somewhere...\n"+
"If you need to come back here, show Angst your badge.\n"+
"Ahh here it is..her's your badge.  Our only lead is concerning\n"+
"Nazi Germany... Begin by gathering information on how the third reich\n"+
"gained soo much power so quickly.  Good Luck.\n");
move_object(clone_object("/players/heroin/quests/badge.c"), this_player());
return 1; }
else {
if(sscanf(str,"%spaper%s",a,b) ==2 || sscanf(str,"%sparchment%s",a,b) ==2||
sscanf(str,"%spiece%s",a,b) ==2) {
if(!present("director")) {
write("Yeah right!! ask a ghost.\n");
return 1; }
write("Pieces of paper?  That reminds me..anyone seen the\n"+
"GLUE lying around?  Seems like I had some.....\n");
return 1;
}
else {
if(sscanf(str,"%spoem%s",a,b) ==2 || sscanf(str,"%sletter%s",a,b) ==2) {
if(!present("director")) {
write("Roses are red, Violets are blue..\n"+
"You killed the director and that fucked you.\n");
return 1; }
write ("DAMN THAT FIERERY BASTARD! I thought we were through with him\n"+
"You will need to ask for the help of a strong and loyal hunter\n"+
"to finish this job now!\n");
return 1;
}
else {
if(sscanf(str,"%stongue%s",a,b) ==2) {
write("If I have to tell you, then what the hell good are you?\n");
return 1;
}
else { 
if(!present("director")) {
return 1; }
write("The director looks at you quizzically.\n");
return 1;}
}}}}}}
glue(str) {
object jeff, crap, blah;
if(!str) {
write("Glue What??\n");
return 1; }
if(str == "pieces"){
if(!present("one",this_player())) {
write("You are missing the first piece.\n");
return 1;
}
if(!present("two", this_player())) {
write("Sorry, but the body of the letter is still missing.\n");
return 1;
}
if(!present("three", this_player())) {
write("You really need all the pieces.\n");
return 1;
}
else {
write("You mannage to arrange the three piece into one larger\n");
write("letter.  You quickly write the information down.\n");
write("Strange, but the letter almost looks \n");
write("like a poem of some sorts.\n");
write("Maybe you should take it to it's owner?!?\n");
move_object(clone_object("/players/heroin/quests/parch.c"), this_player());
jeff = present("one", this_player());
crap = present("two", this_player());
blah = present("three", this_player());
destruct(crap);
destruct(blah);
destruct(jeff);
return 1;
}}}

judge_me() {
if (present("director")) {
write("He is already here.\n");
return 1;}
write("You ask around, and the Director shows up shortly afterwards.\n");
move_object(clone_object("/players/heroin/quests/director.c"), this_object());
return 1;}
search() {
say(tp + "searches all about the ground, but in vain.\n");
write("You search, and search, and search..yet there is still nothing here\n");
return 1;
}

inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(5);
}
short_desc="Dark alley entrance";
items=({
"walls", "The dark city walls surround you.  Between the fog and\n the tall buildings, there is very little actual sunlight.  As you grope\n around in the fog, you run smack into a wall..What's this?\n You look at the walls more carefully"});
dest_dir=({
"/players/heroin/hunting_grounds/london.c","north",
"players/heroin/hunting_grounds/alley2.c","west",});
long_desc =
"You have entered the dark alley. You think to yourself-\n"+
"Man, I am brave and all, but this shit is giving me the\n"+
"creeps!  You pull yourself together and begin to get your\n"+
"bearings..You think you hear something that makes the hair\n"+
"on the back of your neck stick up..The only way you get your\n"+
"bearings is by looking at the walls..You feel like this case\n"+
"is of utmost emergency..better hurry\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("Congrats-You just found your lunch,,Guess you lost your \n lunch from nerves..well now it`s splattered all over your shoes\n");
say(tp +"begins wretching--Shit not on your good shoes-Yick\n");
return 1;
}
smell(){
write("You're not sure what you smell.\n");
say(tp+" looks puzzled..\n");
return 1;
}
listen(){
write("SCRAPE  SCRAPE--there is the awful sound of metal scraping\n on concrete echoing throughout the alley..sounds like\n its coming from the west\n");
say(tp + "cocks his head towards the west\n");
return 1;
}


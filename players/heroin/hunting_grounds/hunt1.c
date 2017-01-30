inherit "room/room";


#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("angst")) move_object(clone_object("/players/heroin/hunting_grounds/GameMaster"), this_object());
if (!present("henry")) move_object(clone_object("/players/heroin/hunting_grounds/Henry"), this_object());
if(!present("board")) move_object(clone_object("/players/heroin/welcome1.c"), this_object());
short_desc = "The GrandMaster's playing field";
items=({
"glass","This material resembles glass,for one can gaze thru it; hoHowver, it isalso appears to be a barrior of some kind. Maybe one should touch it.",
"weapon case","This is filled with a cariety of weapons, it would appear that some are quite old and some fairly new--maybe this is Angst's private arsenal?",
"banner","This is a long flowing banner,with a variety of alien inscriptions. Try to READ the banner.  Angst appears to think YOU SHOULD do just this.",
"processer","The processer is used to complete the transformation of the human corpse into an acceptable trophy.  Pray you never have to witness its' use."});
dest_dir=({
"players/heroin/hunting_grounds/feces.c","bar",
"players/unsane/closed/hell/circle1.c","HELL",
"players/heroin/hunting_grounds/predsx10.c","down",
"players/heroin/hunt_newbies/newb_ent.c","newbie",
"room/plane5","north",
"players/heroin/hunting_grounds/hallway.c","south",});
long_desc =
" You find yourself in a large, open room.  Although you feel a bit\n"+
" disoriented, You feel a sense of strength and vitality pumping thru\n"+
"your veins..  As you consider this-You notice a creature staring at you\n"+
"with glaring eyes.  As the man approaches-You notice that this creature is\n"+
"or was at least partially humanoid.  Now he looks as if he is more\n"+
"machine than man.  The creature is upon you now and he begins to\n"+
"speak:  I am Angst, the GameMaster...I was the master hunter for \n"+
"the past three centuries.  As a reward, I was granted this playing\n"+
"field to supervise the hunt.  The hunt??? Here the game is a matter\n"+
"of life and death. The object of the game is simple: You must defeat\n"+
"your prey before they kill you.  Easy enough, huh?? hehhehehehehehhe\n"+
"As you glance around you see a variety of things fill the room..there is a \n"+
"weapon case against one wall..the glass appears to reflecting \n"+
"of images back at you..also there is some strange machinery siting\n"+

"in the far corner.  Finally, you notice a strange flowing, banner hanging from\n"+
"the south wall.  The room is a bit smokey but you are fairly\n"+
"sure there are three exits leading out of the room.\n"+
"As you begin to leave you hear a hissing:  GOOD LUCK  and....\n"+
"..........HAPPY HUNTING............\n";
}
init(){
::init();
add_action("listen","listen");
add_action("show","show");
add_action("ask","ask");
   add_action("smell","smell");
   add_action("search","search");
add_action("touch","touch");
add_action("read","read");
}
show(str){
string a,b;
if(!str) {
write("Show What??\n");
return 1;}
if(sscanf(str,"%sbadge%s",a,b) == 2) {
write("I'll take you to the director.\n");
move_object(this_player(),"/players/heroin/quests/room/cia1.c");
command("look",this_player());
return 1;}
if(sscanf(str,"%sparchment%s",a,b) ==2 || sscanf(str,"%sletter%s",a,b) ==2|| sscanf(str, "%spoem%s",a,b) ==2) {
if(present("parchment" && "badge", this_player())) {
write("AHHH, I thought that fiery bastard may be behind this.\n"+
"I know where to find him...I dont know what good it'll\n"+
"do you though.  I don't think a mere human could\n"+
"defeat him..oh well, win some/lose some. MUHAHAMUAHA\n"+
"Ill take you there now!\n");
move_object(this_player(), "players/heroin/quests/room/hell1.c");
command("look",this_player());
return 1; }
} else {
write("Bug off Kid..I'm busy, Dont bother me till you got the stuff.\n");
return 1;
}
}
ask(str){
string a,b;
if(!str){
write("Ask what?\n");
return 1;}
if(sscanf(str,"%squest%s",a,b) ==2) {
write("Good Man!..Remember if you need a job you need to \n"+
"ask for one...Ill take you to the portal.  Come Henry.\n");
move_object(this_player(),"/players/heroin/trophy.c");
command("look",this_player());
return 1;
} 
else {
write("What!?!?! Go away human.\n");
return 1;
} }
search(){
write("You find out that the booze is UP.\n");
say(tp+" searches around and finds nothing.\n");
return 1;
}
join_clan() {
object ob;
object jeff;
if (present("badge", this_player())) {
write("YOUR CLAN IS OUTRAGED YOU WOULD DENY YOUR MEMEBERSHIP.\n");
return 1;
}
if(this_player()->query_npc()==1) {
write_file("players/heroin/closed/guild/CHEAT",
"\n"+this_player()->query_real_name()+"was dested"+
ctime()+"\n\n");
destruct(this_player());
write("DAMN YOU!!!");
return 1;
}
if(this_player()->query_level() < 6) {
write("You must find a clan member to help you. \n");
return 1;
}
if(!present("recruit",this_player())) {
write("You must find a Clan Leader to join a clan.\n"+
"Contact them and see if they will help you.\n"); return 1;}
move_object(clone_object("players/heroin/closed/guild/clan_badge.c"), this_player());
ob = present("recruit",this_player());
destruct(ob);
}
smell(){
write("The stench of burning stings your nose..wait a sec. angst is burning Potpouri\n");
say(tp+" snickers at Angst..Flowerboy!.\n");
return 1;
}
read(){
write("This banner contains answers to hunters' questions, comments,\n complaints, and requests on advice concerning beauty \n tips. However, at this time heroin doesn't want to leave any notes.\n");
say (tp + "carefully reads the banner, who are they foolin' they cant read.\n");
return 1;
}
listen(){
if (present("gamemaster")&& present("henry")) write("Angst and Henry are discussing old times\n");
else if (present("GameMaster") || present("Henry")) write("You hear the one howling for the return of his companion.\n");
else write("It is now silent here.\n");
say(tp + " perks up their ears.\n");
return 1;
}


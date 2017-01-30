string tpn;
int muf;
id(str) { return str == "rock" || str == "bis_rock"; }
reset(){
muf = 0;
}
query_muff(){ return muf;}
short(){ return "A small rock";}
long(){
       write("This little rock gives you a few more atmosphere commands.\n");
       write(" Currently it adds the following commands: \n");
write("  woo, wish, survey, boggle, flex, rock, mount,\n");
write("  cheer, fear, raise, throw-up, lag, cuff, faint,\n");
write("  whee, kiss2\n");
write("\n");
write("\n");
write(" There is now a Rock channel! Whee!\n");
write(" Rock Channel Commands:\n");
write("  rt <string> :says string over the channel\n");
write("  re <string> :emotes string over the channel\n");
write("  quiet       :toggles channel muffles on/off\n");
write("\n");
write(" Try out the new 'online' command to see who is on and\n");
write(" who has a rock.\n");
write("\n");
write(" To give a rock to another player: share <playername>\n");
}
drop(){ return 1;}
query_auto_load(){ return "players/bismarck/closed/rock:";}
init(){
tpn = this_player()->query_name();
add_action("woo","woo");
add_action("wish","wish");
add_action("survey","survey");
add_action("boggle","boggle");
add_action("flex","flex");
add_action("rock","rock");
add_action("mount","mount");
add_action("cheer","cheer");
add_action("fear","fear");
add_action("lag","lag");
add_action("raise","raise");
add_action("throw_up","throw-up");
add_action("cuff","cuff");
add_action("whee","whee");
add_action("faint","faint");
add_action("kiss","kiss2");
add_action("alive","online");
add_action("rt","rt");
add_action("re","re");
add_action("quiet","quiet");
add_action("share","share");
}
woo(){
write("You go 'Woo Woo'.\n");
say(tpn+" goes 'Woo Woo'\n");
return 1;
}
wish(){
write("You wish you were as cool as Bismarck.\n");
say(tpn+" wishes to be as cool as Bismarck.\n");
return 1;
}
survey(){
write("You survey the area.\n");
say(tpn+" surveys the area.\n");
return 1;
}
boggle(){
write("You boggle at the concept.\n");
say(tpn+" boggles at the concept.\n");
return 1;
}
flex(){
write("You flex your muscles impressing those around you.\n");
say(tpn+ "tries to impress you by flexing.\n");
return 1;
}
rock(str){
if(!str){
write("You rock the mud!\n");
say(tpn+" rocks the mud.\n");
return 1;
}
str = capitalize(str);
write("You express your feelings about "+str+" rocking the mud!\n");
say(tpn+" feels that "+str+" rocks the mud.\n");
return 1;
}
fear(str){
if(!str){
write("You go 'feared'\n");
say(tpn+" goes 'feared'\n");
return 1;
}
str = capitalize(str);
write("You fear "+str+".\n");
say(tpn+" fears "+str+".\n");
return 1;
}
mount(str){
object ob;
if(!str){
write("You look around for something to mount.\n");
say(tpn+" looks around for something to mount.\n");
return 1;
}
ob = present( str, environment(this_player()));
if(!ob){
write("Hmm... Just where is this "+str+"?\n");
return 1;
}
write("You mount "+ob->query_name()+" and ride off into the sunset.\n");
say(tpn+" mounts "+ob->query_name()+" and rides off into the sunset.\n");
return 1;
}
kiss(str){
object ob;
string gender;
string gender2;
if(!str){
write("Kiss who?\n");
return 1;
}
ob = present( str, environment(this_player()));
if(!ob){
write("You pucker up, but then realize that this person isn't around.\n");
return 1;
}
if(ob == this_player()){
write("You want to kiss yourself?\n");
return 1;
}
write("You pull "+ob->query_name()+" closer.\n");
tell_object(ob,tpn+" pulls you closer.\n");
say(tpn+" pulls "+ ob->query_name()+" closer.\n");
gender = "its";
gender2 = "its";
if(this_player()->query_gender() == "male"){ gender = "his";}
if(this_player()->query_gender() == "female"){ gender = "her";}
if(ob->query_gender() == "female"){ gender2 = "hers";}
if(ob->query_gender() == "male"){ gender2 = "his";}
write("You feel your heart flutter as you softly press your lips\n");
write("against "+gender2+".\n");
say(tpn+" softly kisses "+ob->query_name()+".\n");
tell_object(ob,"You feel your heart flutter as "+tpn+" softly presses\n"+gender+" lips against yours.\n");
return 1;
}
cheer(str){
object ob;
if(!str){
write("You cheer enthusiastically!\n");
say(tpn+" cheers enthusiastically.\n");
return 1;
}
ob = present( str, environment(this_player()));
if(!ob){
write("Hmm... Just where is this "+str+"?\n");
return 1;
}
write("You cheer "+ob->query_name()+" enthusiastically.\n");
say(tpn+" cheers "+ob->query_name()+" enthusiastically.\n");
return 1;
}
throw_up(){
write("You grow sick to your stomach and lose your lunch on the floor before you.\n");
say(tpn+" seems to be turning slightly pale.\n");
say("You grow sick to your stomach as "+tpn+" spews forth a disgusting\n");
say("green ooze.\n");
return 1;
}
lag(){
write("You raise your fist high in the air and curses the Gods for creating\n");
write("this LAG!!\n");
say(tpn+" curses the Gods for creating this LAG!!\n");
return 1;
}
raise(){
write("You raise your eyebrow in disbelief.\n");
say(tpn+" raises an eyebrow in disbelief.\n");
return 1;
}
cuff(str){
object ob;
if(!str){
write("You grin evilly as you flash your shiny chrome handcuffs to those\n");
write("around the room.\n");
say("You notice "+tpn+" twirlling some handcuffs while grinning at you evilly.\n");
return 1;
}
ob = present( str, environment(this_player()));
if(!ob){
write("That person isn't present.\n");
say(tpn+" looks slightly confused.\n");
return 1;
}
write("You roughly throw "+ob->query_name()+" to the ground, and latch on\n");
write("the handcuffs!\n");
say(tpn+" roughly throws "+ob->query_name()+" to the ground and latches\n");
say("on the handcuffs!\n");
return 1;
}
whee(){
write("You go 'Whee!'\n");
say(tpn+" goes 'Whee!'\n");
return 1;
}
faint(){
write("The world goes black.\n");
say(tpn+" faints.\n");
return 1;
}
alive(){
int count;
string who;
int x;
object ob;
ob = users();
write("================================================================================\n");
write("  Name:         Lvl:      Pk?     Location:\n");
write("================================================================================\n");
for(x=0;x<sizeof(ob);x+=1){
if(ob[x]->query_level() < 21){
if(ob[x]->query_invis() == 0){
if(present("bis_rock", ob[x])){
write("*");
}
if(!present("bis_rock", ob[x])){
write(" ");
}
who = ob[x]->query_name();
 count = strlen(who);
count = 16 - count;
write(who);
while(count>0){
write(" ");
count = count - 1;
}
write(ob[x]->query_level()+"\t");
if(ob[x]->query_pl_k() == 1){write("  Yes    ");}
if(ob[x]->query_pl_k() == 0){write("  No     ");}
if(!environment(ob[x])){
write("Location Unknown\n");
}
if(environment(ob[x])){
write(environment(ob[x])->short()+"\n");
}
}
}
}
write("================================================================================\n");
write("Total Number players online: "+x+"\n");
write("* denotes this player currently has a rock.\n");
return 1;
}
rt(str){
int x;
object rock;
object ob;
ob = users();
for(x=0; x<sizeof(ob);x+=1){
if(present("bis_rock", ob[x])){
rock = present( "bis_rock", ob[x]);
if(rock->query_muff() == 0){
tell_object(ob[x], this_player()->query_name()+" rocks: "+str+"\n");
}
}
}
return 1;
}
re(str){
int x;
object ob, rock;
ob = users();
for(x=0;x<sizeof(ob); x+=1){
if(present("bis_rock", ob[x])){
rock = present("bis_rock", ob[x]);
if(rock->query_muff() == 0){
tell_object(ob[x], "(rock): "+this_player()->query_name()+" "+str+"\n");
}
}
}
return 1;
}
quiet(){
if(muf == 0){
 write("You will now longer hear the rock channel.\n");
 muf = 1;
return 1;
}
if(muf == 1){
 write("You will now hear the rock channel.\n");
 muf = 0;
return 1;
}
}
share(str){
object ob;
object rock;
if(!str){
 write("Usage: share <playername>\n");
 return 1;
 }
ob = present( str, environment(this_player()));
if(!ob){
 write("The player has to be present!\n");
 return 1;
 }
if(!living(ob)){
 write("You can only give the rock to players!");
write("\n");
 return 1;
}
if(ob->query_npc() == 1){
write("You can't give the rock to a monster!\n");
return 1;
}
if( present("bis_rock", ob)){
 write("This player already has a rock.\n");
 return 1;
}
if( ob->query_real_name() == "guest" ){
 write("Only real players get the rock!\n");
 return 1;
}
rock = clone_object("players/bismarck/closed/rock");
move_object(rock,ob);
write("You give a rock to "+ob->query_name()+"\n");
tell_object(ob, this_player()->query_name()+" gives you a rock.\n");
tell_object(ob, "Bismarck whispers to you: You Rock!\n");
return 1;
}

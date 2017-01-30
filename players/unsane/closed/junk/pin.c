#define tp this_player()->query_name()
int muffled;
set_muffled(mf) {muffled = mf; }
inherit "obj/treasure";
int i;
string msg;
reset(arg){
if (arg) return;
set_id("pin");
set_alias("safety pin");
set_short("A very punk safety pin.  (worn)");
set_long("This looks just like the kind of safety pin that the Sex Pistols wore.  You\n"+
"find a good place to put it on your clothes, or ear, or nose to show the world\n"+
"that you're punk as fuck.\nType punk_rock for help.\n");
set_value(0);
set_weight(0);
}
init(){
add_action("danzig","danzig");
add_action("crashe","cpe");
add_action("vacant","vacant");
add_action("sing","psing");
add_action("pk","badass");
add_action("stack","pstack");
add_action("mock","house_sux");
add_action("mosh","slam");
add_action("misfits","misfits");
add_action("bored","pbored");
add_action("pin_chate","pnke");
add_action("pin_tell","bitch");
add_action("shut_up","shut_up");
add_action("sorry","sorry");
add_action("pin_who","scene");
add_action("memote","poseur");
add_action("pin_help","punk_rock");
add_action("self_dest","i_suck");
add_action("hip","pshove");
add_action("psay","psay");
add_action("ear_shout","ear_shout");
add_action("crash","cpt");
add_action("dick","pbrag");
add_action("pin_chat","pnk");
add_action("new_pin","new_pin");
}
slook(){
msg =tp+" looks around the room for something to smash or fuck up.\n";
write(msg);
say(msg);
return 1;}
mosh(str){
object guy;
if (!str) {write("You start a pit in this room.\n"); say(tp+" begins slam dancing.\n"); return 1;}
guy = find_living(str);
if (!guy) {write("You can't find "+str+" to fuck up in the pit.\n"); return 1;}
if (guy->query_level() > 19) {write("Nice try...wizards are poseurs.  They don't wanna mosh.\n"); return 1;}
tell_object(guy,tp+" grabs you and brings you in the pit.\n"+
"After jumping around to the Ramones, "+tp+" jacks you with his elbow.\n"+
"Then "+tp+" kicks you in the head as you slip down.\n"+
capitalize(this_player()->query_pronoun())+" finishes off the attack with a poke to the eye.\n");
write("You bring "+str+" in the pit and fuck 'em up.\n");
return 1;}
stack(){
string msg,size;
int i;
i = random(10);
if (i < 1) {msg = "You refrain from any crude jokes.\n"; size = "A";}
if (i >0 && i < 4) {msg= "Hmmm...about average I guess.\n"; size = "B";}
if (i >3 && i<7) {msg="Wow, she's pretty stacked!\n"; size = "C";}
if (i >6 && i <9) {msg="Damn! That girl is busty!\n"; size ="D";}
if(i >8) {msg="You get the feeling that "+tp+" is gonna have back pain later on in life.\n"; size = "DD";}
write("You grab a breast and show the room you wear at least a "+size+" size bra.\n"+msg);
say(tp+" grabs a boob and proves to you that she at least wears a "+size+" size bra.\n"+msg);
return 1; }
vacant(){
string msg;
msg = tp+" stares off into space vacantly.\n";
write(msg);
say(msg);
return 1;}
sing(){
string msg;
msg = tp+" begins to shout out the lyrics to 'Submission' by the Sex Pistols.\n";
write(msg);
say(msg);
return 1;}
danzig(str){
object guy;
if (!str) {write("Glen tells you: Who should I taunt??\n"); return 1;}
guy = find_living(str);
if (!guy) {write("Glen tells you: That fucking prick is hiding from me.\n");
   return 1;}
if (guy->query_level() >19) {write("Glen tells you: Wizards already know they suck.\n"); return 1;}
tell_object(guy,"Glen Danzig enters the room, points at you and says: You!\n"+
"You stupid, pathetic piece of shit.  You were never punk!  You poseur!\n");
tell_room(environment(guy),"Glen Danzig enters the room, points at "+str+" and mocks the shit out of them.\n");
write("You sent Glen Danzig to taunt that poseur.\n");
return 1;}
pk(){
object *kids;
int size,i,count;
kids = users();
size = sizeof(kids);
write("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
write("\n");
for (i = 0; i<size; i++){
if(kids[i]->query_pl_k() && kids[i]->query_level() < 20){
write(pad(kids[i]->query_name(),18)+" "+pad(kids[i]->query_level(),3)+" "+
environment(kids[i])->short()+"\n");
count++;
}}
write("\n");
write("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
write("There are "+count+" bad asses on right now.\n");
return 1;}
dick(){
string msg;
int i,count;
i = random(10)+2;
write("You grab a ruler and then whip out your pecker.\n"+
"You show the world that you are a "+i+" incher.\n");
if (i < 4) {msg="The girls begin to snicker.\n";}
if (i>3 && i<7){msg="No one looks impressed.\n"; }
if (i>6 && i<10) {msg="Not bad, not bad at all.\n";}
if (i>9 && i<13) {msg="Holy shit!  Put that thing away!\n";}
say(tp+" suddenly whips out a ruler and his penis.\n"+
"He proves to you that he's at least a "+i+" incher.\n");
write(msg);
say(msg);
return 1;}
new_pin() {
move_object(clone_object("players/unsane/closed/junk/pin.c"),this_player());
write("You get a new safety pin and attach it to your person.\nYou ate the old one?!\n");
destruct(this_object());
return 1;}
memote(str) {
write(tp +" "+str+"\n");
say(tp+" "+str+"\n");
return 1;}
shut_up() {
if (muffled == 1) {
write("This loud music is making you deaf?  They have already shut up!\n");
return 1; }
pin_chate("starts to cry like a baby and turns off the punk channel.\n");
write("You tell those poseurs too shut up.\n");
muffled = 1;
return 1; }
sorry() {
if (muffled == 0) {
write("You never told them to shut up.  Though you should have.....stupid poseurs.\n");
return 1; }
pin_chate("comes back to the scene.\n"+capitalize(this_player()->query_pronoun())+" heard you were talking shit.\n");
write("You don't want to miss everyone talking about you behind your back.\n"+
"You come back on the scene.\n");
muffled = 0;
return 1; }
query_muffled() { return muffled; }
query_auto_load() {return "players/unsane/closed/junk/pin:";}
pin_tell(str) {
string person,who,msg;
if (!str) {
write("You wanna tell what to who?\n");
return 1; }
sscanf(str,"%s %s",person,msg);
who=find_living(person);
if (!who) {
write("They are not logged on.\n");
return 1;}
if(!present("pin",who)) {
write("They are playing, but the stupid fuckers aren't hip to punk rock.\n");
return 1; }
tell_object(who,"::"+tp+"::"+" "+msg+"\n");
write("::"+tp+":: tells ::"+person+":: "+msg+"\n");
return 1;}
pin_who() {
object ob;
int v,size,count;
string name, pk, sex;
write("PUNKASFUCKASPUNKASFUCKASPUNKASFUCKASPUNKASFUCKASPUNKASFUCKASPUNKASFUCKASPUNKAS\n");
write("\n");
     write("Name               PK?       Sex           Location\n");
ob = users();
size = sizeof(ob);
for(v = 0; v < size; v++) {
if (present ("pin", ob[v])) {
count++;
sex = ob[v]->query_gender();
name = ob[v] -> query_name();
if (ob[v]->query_pl_k()==  0) {pk = "         ";}
else {pk = "(BASTARD)";}
write(pad(name, 15)+" "+pk+"   "+pad(sex, 10)+" "+
((environment(ob[v]))->short())+"\n");
}}
write("\nPUNKASFUCKASPUNKASFUCKASPUNKASFUCKASPUNKASFUCKASPUNKASFUCKASPUNKASFUCKASPUNKAS\n");
write(count+" of "+size+" players aren't total losers.\n");
return 1; }
pin_chat(str) {
object foo, buskid;
int bar;
foo = users();
for (bar=0; bar<sizeof(foo); bar++) {
buskid = (present("pin",foo[bar]));
if (buskid && buskid->query_muffled() < 1) {
tell_object(foo[bar], tp+" the PUNK, shouts: "+str+"\n");
}}
return 1; }
pin_chate(str){
object foo, buskid;
int bar;
foo = users();
for (bar=0; bar<sizeof(foo); bar++){
buskid = (present("pin",foo[bar]));
if (buskid && buskid ->query_muffled() < 1){
tell_object(foo[bar],"(PUNK): "+tp+" "+str+"\n");
}}
return 1;}
crash(str) {
object foo,buskid,trick,patkid;
int bar,size;
foo = users();
size = sizeof(foo);
for(bar=0; bar<size; bar++) {
buskid = present("pin",foo[bar]);
patkid = present("patch",foo[bar]);
if ((buskid && buskid->query_muffled() <1) || patkid){
tell_object(foo[bar],"(PATCH CRASHER): "+tp+" says: "+str+"\n");
}
}
write("Way to tell those fuckers.\n");
return 1;
}
crashe(str){
object *foo,buskid,patkid;
int bar,size;
foo = users();
size = sizeof(foo);
for (bar=0; bar <size; bar++){
buskid = present("pin",foo[bar]);
patkid = present("pin",foo[bar]);
if ((buskid && buskid->query_muffled() < 1) || patkid){
tell_object(foo[bar],"(PATCH CRASHER): "+tp+" "+str+"\n");
}}
write("Way to show those fuckers.\n");
return 1;}
psay(str) {
if (!str) {
return 1;}
say(tp+" the punk rocker screams: "+str+"\n");
write("You are so punk, you scream: "+str+"\n");
return 1;}
give() {
return 1;
}
drop () {
return 1;
}
hip(str) {
object lucky, item;
if (!str) {write("You gotta shove this trash on a person you know.\n");
return 1;}
lucky = find_living(str);
if (!lucky) {
write(capitalize(str)+" heard you were gonna give em this shit.\nMust have run.\n");
return 1;}
if (present("pin", lucky)) {
write(capitalize(lucky->query_pronoun())+" has been on the scene for years.\n"+
capitalize(lucky->query_pronoun())+" must be more punk than you.\n");
return 1; }
if (lucky->query_level() > 19) {
write("Shows what you know.  Unsane is the only punk rocker wiz.\n");
return 1; }
move_object(clone_object("players/unsane/closed/junk/pin"),lucky);
tell_object(lucky,tp+" throws a safety pin at you and says: Wear it and be punk.\nOr just be a poseur, I don't care.\n");
write("You throw a safety pin to "+str+".  Who knows if the fucks will wear it.\n");
return 1; }
ear_shout(str){
object guy;
if (!str) {write("Shout in who's ear?\n"); return 1;}
guy = find_living(str);
if (!guy) {write("You can't find "+guy+".  Must be hiding.\n"); return 1;}
if (guy->query_level() >19) {write("Yeah sure, I'll let you get away with that.\n"); return 1;}
tell_object(guy,tp+" grabs ahold of your ear and screams: YOU FUCKING POSEUR!"+
"I WILL KICK YOUR ASS! YOU ARE SUCH A COMPLETE LOSER! YOU WERE NEVER PUNK!"+
"YOU ARE A NOTHING, A TOTAL ZERO!....uh...who's got the Ten and a Half?\n");
write("You shout in "+str+"'s ear and make them feel terrible.\n");
return 1;
}
mock(){
write("You let it be known that house of pain is a bunch of lame white kids.\n");
say(tp+" announces that house of pain is just a bunch of lame white kids.\n");
return 1;}
bored(){
msg = tp+" is so punk, he is already bored by this.\n";
write(msg);
say(msg);
return 1;}
misfits(){
msg=tp+" shows everyone in the room his Misfits shirt from '83.\n";
write(msg);
say(msg);
return 1;}
pin_help(){
write("IAMANANTICHRISTIAMANANRACHISTIAMANANTICHRISTIAMANANARCHISTIAMANANTICHRISTIAMAN\n\n");
write("   THE COMPLEAT HELP FOR THE FRICKING PUNK ROCK PIN!\n");
write("EMOTIONS\n");
write("misfits   pbored  house_sux   pstack  psing   vacant  pbrag\n");
write("HELPFUL FUNCTIONS (?)\n");
write("punk_rock  -- This menu\n");
write("poseur     -- General emote\n");
write("scene      -- Who is punk?\n");
write("danzig     -- Send Glen Danzig to mock a person\n");
write("pshove     -- Shove a pin on a person\n");
write("psay       -- Say something really punk\n");
write("ear_shout  -- Shout something in a person's ear\n");
      write("cpe        -- Crash the House of Pain channel with an emote\n");
write("cpt        -- Crash House of Pain channel with a message\n");
write("slam       -- Annoy a person in the pit\n");
write("badass     -- A list of only the player killers on\n");
write("bitch      -- FREE TELL!\n");
write("PIN CHANNEL COMMANDS\n");
write("pnk      -- talk on the punk channel\n");
write("pnke     -- emote on the punk channel\n");
write("shut_up   -- Muffle this channel\n");
write("sorry     -- Un-Muffle the punk rock channel\n");
write("OTHER JUNK\n");
write("new_pin   -- Get a newer copy of the pin\n");
write("i_suck    -- Get rid of your pin (poseur)\n");
write("*** NOTE *** Both, pstack and pbrag could be considered offensive.\n"+
"So do them a bunch around prudish players.\n");
write("\nDON'TKNOWWHATIWANTBUTIKNOWHOWTOGETITDON'TKNOWWHATIWANTBUTIKNOWHOWTOGETITDON'T\n");
return 1;}
self_dest() {
pin_chate("hates all of you guys because you are more punk.\n"+capitalize(this_player()->query_pronoun())+" throws away the pin and asks for you to send Glen Danzig for a chat.  (he he)\n");
destruct(this_object());
write("What the fuck?!  Stupid poseurs never were very cool.\n");
return 1;}

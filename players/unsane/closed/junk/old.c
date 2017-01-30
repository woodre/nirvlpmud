#define tp this_player()->query_name()
int muffled;
set_muffled(mf) {muffled = mf; }
inherit "obj/treasure";
int i;
string msg;
reset(arg){
if (arg) return;
set_id("mike");
set_alias("mic");
set_short("A Wonder Mike");
set_long("This is a cheap plastic microphone.  It appears to have several useful\n"+
"functions.  Well maybe not usefull, but fun.  Type 'helpm' to see what it can\n"+
"do.\n");
set_value(0);
set_weight(0);
}
init(){
add_action("tport","train");
add_action("mike_tell","wmt");
add_action("shaddup","shaddup");
add_action("sorry","sorry");
add_action("mike_who","bus");
add_action("memote","#");
add_action("mike_help","helpm");
add_action("self_dest","turn_off");
add_action("hip","hip");
add_action("esay","esay");
add_action("beat_box","bbox");
add_action("feedback_player","phrack");
add_action("bemote","bboy");
add_action("give","give");
add_action("mike_chat","sht");
add_action("newschool","newschool");
add_action("random_rhyme","bust");}
newschool() {
move_object(clone_object("players/unsane/closed/junk/wmike.c"),this_player());
write("You are now new school.  Screw that wack shit.\n");
destruct(this_object());
return 1;}
memote(str) {
write(tp +" "+str+"\n");
say(tp+" "+str+"\n");
return 1;}
tport() {
if (this_player()->query_sp() < 80) {
write("You don't have the energy you need to call the Soul Train.\n");
return 1; }
if (environment(this_player())->realm() == "NT") {
write("The soul train doesn't come to this station.\n");
return 1;}
write("You get on the Soul Train, and take it to the lockers.\n");
say("The Soul Train enters and picks up "+tp+".\n");
move_object(this_player(),"players/catwoman/tl.c");
command("look",this_player());
this_player()->add_spell_point(-80);
say(tp+"arrives on the soul train.\n");
return 1; }
shaddup() {
if (muffled == 1) {
write("There are already quiet man...are you high?\n");
return 1; }
write("You tell those loudmouths to shut up.\n");
muffled = 1;
return 1; }
sorry() {
if (muffled == 0) {
write("You never told them to shaddup.\n");
return 1; }
write("You are back with the kids now.\n");
muffled = 0;
return 1; }
query_muffled() { return muffled; }
query_auto_load() {return "players/unsane/closed/junk/wmike:";}
mike_tell(str) {
string person,who,msg;
if (!str) {
write("You wanna tell what to who?\n");
return 1; }
sscanf(str,"%s %s",person,msg);
who=find_living(person);
if (!who) {
write("They are not logged on.\n");
return 1;}
if(!present("mike",who)) {
write("They are logged on, but don't have a mike.\n");
return 1; }
tell_object(who,"::"+tp+"::"+" "+msg+"\n");
write("::"+tp+":: tells ::"+person+":: "+msg+"\n");
return 1;}
mike_who() {
object ob;
int v;
string name, pk, sex;
write("*******The list of people who are on the bus********\n");
     write("Name               PK?       Sex           Location\n");
ob = users();
for (v = 0; v<sizeof(ob); v++) {
if (present ("mike", ob[v])) {
sex = ob[v]->query_gender();
name = ob[v] -> query_name();
if (ob[v]->query_pl_k()==  0) {pk = "         ";}
else {pk = "(PacKing)";}
write(pad(name, 15)+" "+pk+"   "+pad(sex, 10)+" "+
((environment(ob[v]))->short())+"\n");
}}
return 1; }
plug() {
object ob;
int v;
string name, sex, pk;
write("******The List of All the Kids Playing (even the wack ones)*******\n");
write("name        PK?       Sex               Location\n");
ob = users();
for (v = 0; sizeof(ob); v++) {
if (ob[v] ->query_pl_k() == 0) {pk = "   ---    ";}
else {pk = "( !!!!!!! )";}
write(pad(name, 15)+" "+pk+"   "+pad(sex, 10)+
((environment(ob[v]))->short())+"\n");
}
return 1;}
mike_chat(str) {
object foo, buskid;
int bar;
foo = users();
for (bar=0; bar<sizeof(foo); bar++) {
buskid = (present("mike",foo[bar]));
if (buskid && buskid->query_muffled() < 1) {
tell_object (foo[bar], "::hip:: "+tp+" "+str+"\n");
}}
return 1; }
esay(str) {
if (!str) {
write("You wanna say what through the mike?");
return 1;}
say("You have to hold your ears the feedback is so bad.\n");
say("\n");
say(this_player()->query_name()+" taps the mike and says: "+str+"\n");
write("You turn on your mike and say: "+str+"\n");
say("You hear an echo.\n");
write("You hear an echo.\n");
write("You hear some feedback...jeez this mike sucks.\n");
return 1;}
random_rhyme() {
write("You turn on the Wonder Mike and let the lyrics fly.\n");
say(tp + " turns on the Wonder Mike (tm) and assaults you!\n");
write("\n");
say("\n");
i = random(9);
if (i == 0) {
msg = 
"--Families, Punk Rock, the Business Man,--\n"+
"--I dog everybody with the Egg in my hand.--\n"+
"--suckers they come, a dime a dozen--\n"+
"--when i say dozen you know what i'm talking about...boy--\n"+
"---- the Beastie Boys\n";
}
if (i == 1) {
msg =
"--Your momma is so big and fat that she can get busy,--\n"+
"--with 22 burritos when times are tough--\n"+
"--I seen her in the back of Taco Bell with handcuffs--\n"+
"-----  The Pharcyde\n";
}
if (i == 2) {
msg =
"--If i were a jew i would light a menora--\n"+
"--excuse me senora, are you a whore or--\n"+
"--are you a lady?--\n"+
"--is it Erica Boyer or Marsha Brady?--\n"+
"------- House of Pain\n";
}
if (i == 3) {
msg =
"--Walkin around with rocks in my pockets--\n"+
"--get you so high, niggas call my shit rockets--\n"+
"----- Ice Cube\n";
}
if (i == 4) {
msg =
"--I went into the locker room, during classes--\n"+
"--bust into your locker and I smashed your glasses--\n"+
"----- The Beastie Boys\n";
}
if (i == 5) {
msg =
"--My name is Humpty, pronounced with an Umpty--\n"+
"--Yo ladies, oh how i love to thump thee--\n"+
"--and all you rappers in the top 10,--\n"+
"--please allow me to bump thee--\n"+
"--I'm stepping tall, y'all, and just like Humpty Dumpty--\n"+
"--You're gonna fall when the steroes pump me.--\n"+
"----- Digital Underground\n";
}
if (i == 6) {
msg =
"--Now, what you hear is not a test--\n"+
"--I'm rapping to the beat--\n"+
"--and me, the crew, and my friends--\n"+
"--are gonna try to move your feet.--\n"+
"-----The Sugar Hill Gang (old school)\n";
}
if (i == 7) {
msg = 
"--I like franks, and pork and beans--\n"+
"--always bust the new routines--\n"+
"--I get it, I got it, I know it's good--\n"+
"--the rhymes i write, you wish you would--\n"+
"----  The Beastie Boys\n";
}
if (i == 8) {
msg = "--If i played guitar, I'd be Jimmy Page--\n"+
"--the girlies i like are underage--\n"+
"---- The Beastie Boys\n";
}
write("You bust out with......\n" + msg);
say("The Wonder Mike Busts out with this ditty.....\n"+ msg);
write("\n");
say("\n");
return 1;
}
drop () {
write("Look here buddy, we can't have mikes lying all over the place.\n"+
"Just type 'turn_off' instead ok?\n");
return 1;
}
give(str) {
string a, b;
if((sscanf (str, "%smic%s",a,b) == 2) || (sscanf (str, "%smike%s",a,b) == 2)) {
write ("Ah ah ah....naughty naughty....just type hip <playername> instead.\n");
return 1;}
}
hip(str) {
object lucky, item;
if (!str) {write("Ummmm..who you wanna hip??\n");
return 1;}
lucky = find_living(str);
if (!lucky) {
write("I can't find them.  I even searched over hill and yon.\n");
return 1;}
if (present("mike", lucky)) {
write(capitalize(lucky->query_pronoun())+" is already smoking that mike like weed.\n");
return 1; }
if (lucky->query_level() > 19) {
write("You are pretty sure that no wizard wants this trash.\n");
return 1; }
move_object(clone_object("players/unsane/closed/junk/birdie"),lucky);
tell_object(lucky,this_player()->query_name()+" wants to give you a mike.\n");
tell_object(lucky,"Is that O.K?  (type Yes or No)\n");
return 1; }
check(str) {
if (str == "N" || str == "n") {
tell_object(this_player(),"They don't want one.  So don't be an ass.\n");
return 1; } 
}
mike_help() {
write("Ok right now the mike can do all of the following things.....\n");
write("Command                       Result\n");
write("bboy            you will emote a random beastie boy message\n");
write("#               a general emoter\n");
    write("shaddup         turn off this moron channel\n");
    write("sorry           say you are sorry and come back to the channel\n");
write("bbox            you will turn into a human beat box\n");
write("bust            you will quote random rap lyrics\n");
write("hip <player>    give a mike to a buddy\n");
write("phrack <player> dose a jerk with feedback\n");
write("train           take the soul train to the lockers 80sp\n");
write("turn_off        get rid of this stupid thing\n");
write("esay <msg>      try to look cool by talking through your mike\n");
write("wmt <person> <msg>\n");
write("                tell another mike holder a message\n");
 write("newschool       get a new mike\n");
write("bus             a list of all the people with mikes\n");
write     ("sht <msg>       chat message over the mike channel\n");
write("helpm           this menu\n");
return 1; }
beat_box() {
write("You do your Fat Boys imitation.  (wack)\n");
say(tp + " makes an ass out of themself, and begins to beat box.\n");
say("Sheesh...even Run DMC doesn't do that anymore.\n");
return 1;
}
self_dest() {
destruct(this_object());
write("You never were very cool anyway.\n");
return 1;}
feedback_player(str){
object guy;
guy = find_player(str);
if (!guy) {
write("I dunno where that person is.\n");
return 1; }
if (guy->query_level() > 19) {
write("You shithead, don't try to feedback a Wizard!\n");
return 1; }
tell_object(guy,"You hear "+this_player()->query_name()+" turn on their Wonder Mike (tm) and you begin to fear.\n");
for (i = 0; i < 5; i++) {
tell_object(guy,"zzzzzxxzxkkzXKZKXZxxzzxcKXkxcKCzskczKCSzXKczXKCxKZxKCzSKC");
}
tell_object(guy,"\nYou are gonna have to kill that asshole.\n");
write("You zap your foe with a dose of feedback!\n");
return 1;
}
bemote() {
i = random(10);
if (i == 0) {
msg = " gots more stories than J.D.'s got salinger.\n";}
if (i == 1) {
msg = " gots more adidas sneakers than a plumber's got pliers.\n";}
if (i == 2) {
msg = " gots more flavor than fruit stripe gum.\n";}
if (i == 3) {
if (this_player()->query_gender() == "male") {
msg = " gots money, like charles dickens, he's got the girlies in the coup "+
"like the colnel's got the chicken.\n";}
if (this_player()->query_gender() == "female") {
msg = " gots money, like charles dickens, she's got the boys in the coup "+
"like the colonel's got the chicken.\n";
}}
if (i == 4) {
msg = " is so high.  Call them your highness.\n";}
if (i == 5) {
msg = " went into the locker room, during classes, bust into your locker and smashed your glasses.\n";}
if (i == 6) {
msg = " gots more suits than Jacoby and Meyers.\n";}
if (i == 7) {
msg = " is the only cop with the rope chain walking the beat.\n";}
if (i == 8) {
msg = " gots more spice than the frugal gormet.\n";}
if (i == 9) {
msg = " is a wack emcee.\n";
}
write("You emote in the Bboy style:\n" +tp+ msg);
say (tp+ msg);
return 1;
}

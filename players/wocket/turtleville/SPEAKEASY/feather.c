/* approved for testing by Eurale  7/2/97  */

#include "/players/wocket/closed/ansi.h"
#define tpn this_player()->query_real_name()
inherit "obj/treasure";

int muffle,num,freeze;
string MODE;
reset(arg){
  if(arg) return;
    set_id("poetline");
     set_alias("feather");
    set_short("A well used feather");
    set_long("This is a well used feather quill.. qhelp to see its features.\n");
    set_no_clean(1);
    set_weight(0);
}

init(){
    MODE = " says: ";
    add_action("qhelp","qhelp");
    add_action("poets","poets");
    add_action("muffle","muffle");
    add_action("channel","channel");
    add_action("destroyquill","I_am_no_poet");
    add_action("recite","?");
    add_action("setmode","set_mode");
    add_action("channelhistory","qhistory");
    add_action("qrules","qrules");
if( (tpn == "maddog" || tpn == "feldegast" || tpn == "wocket" || tpn == "aenom" || tpn == "jabberwocky" || tpn == "isis") ){
    add_action("add_poet","add_poet");
    add_action("freeze_poet","freeze_poet");
    add_action("unfreeze_poet","unfreeze_poet");
    add_action("remove_poet","remove_poet");
}
   if(this_player()->query_real_name() == "illarion"){
  write(HIB+"You have been removed from the line.\n"+OFF);
    destruct(this_object());
  }
}



drop(){ return 1; }
get(){ return 0; }
query_auto_load(){ return "/players/wocket/junk/quill.c:"; }

int destroyquill(){
    write("You rip your quill in two.\n");
    destruct(this_object());
    return 1;
}

set_freeze(i){ freeze = i; }
query_freeze(){ return freeze; }
query_muffle(){ return muffle; }
int muffle(string str){
if (str == "poetry"){
    if(muffle!=1){
    muffle = 1;
    write("You muffle poetry.\n");
    return 1;
}
    write("Poetry is already muffled.\n");
    return 1;
}
return 0;
}

int channel(string str){
if (str == "poetry"){
    if(muffle!=0){
      muffle = 0;
    write("You return to the poetry channel.\n");
      return 1;
   }
    write("You are already on the poetry channel.\n");
    return 1;
}
return 0;
}

int poets(){
object *everyone,member;
int membercount,mufflecount;
string poetwho,name,name2;
string cuttitle;
string cutrace;
object mem;
int i;
everyone = users();
membercount = mufflecount = 0;
write(HIB+"poets:       level      gender  race    title\n"+NORM);
for(i = 0; i < sizeof(everyone); i++){
    mem = everyone[i];
    member = present("poetline",everyone[i]);
if(member){
    if(mem->query_invis() < 21){
membercount++;
poetwho = "";
name = (string) mem->query_name()+"               ";
if( (int) member->query_muffle() != 1){
    mufflecount++;
}
else{
    name = "#"+name;
}
name2 = name[0..11];
poetwho += name2;
poetwho += " "+mem->query_level();
poetwho += "+"+mem->query_extra_level();
poetwho += "\t"+mem->query_gender();
cutrace = (string) mem->query_race();
cutrace = cutrace[0..6];
poetwho += "\t"+cutrace;
cuttitle = (string) mem->query_title();
cuttitle = cuttitle[0..33];
poetwho += "\t"+cuttitle+" "+OFF+"\n";
write(poetwho);
}
}
}
write(HIB+"There are currently "+NORM+BOLD+mufflecount+HIB+" of "+NORM+BOLD+membercount+HIB+" poets listening.\n"+NORM);
return 1;
}

int channelsay(string str){
object *everyone,member;
int i;
everyone = users();
if(!str){
    write("Usage: '? <str' to speak... '? :<str>' to emote..\n");
    return 1;
}
if(muffle == 1){
    write("You have the poetry lined muffled.\n");
    return 1;
}
if(freeze == 1){
    write("You poetry line has been frozen.\n");
    return 1;
}

for(i = 0; i < sizeof(everyone); i++){
    member = present("poetline",everyone[i]);
if(member){
    if( (int) member->query_muffle() != 1){
    tell_object(everyone[i],str+NORM+"\n");
  }
}
}
    write_file("/players/wocket/junk/POETLOG",str+NORM+"\n");
}


channelhistory(){
write(HIB+"                    Poetryline history:\n"+NORM);
write(HIB+"::\n"+NORM);
    tail("/players/wocket/junk/POETLOG");
write(HIB+"::\n"+NORM);
return 1;
}
int setmode(string str){
    if(str == "sings"){
       MODE = " sings: ";
    }
    if(str == "recites"){
    MODE = " recites: ";
    }
    if(str == "quotes"){
    MODE = " quotes: ";
    }
    if(str == "says"){
    MODE = " says: ";
}
    if(str == "whispers"){
    MODE = " whispers: ";
    }
write("You currently have your mode set to \""+this_player()->query_name()+MODE+"\"\n");
if(!str){
    write("Usage: set_mode <mode>\n");
    write("Current modes are 'says', 'sings', 'recites', 'quotes', and 'whispers'.\n");
}
return 1;
}


int recite(string str){
int i,a;
string msg;
if(!str){
  notify_fail("What would you like to say on the poetryline?\n");
    return 0;
}
    msg = HIB+"("+NORM+BOLD+" ? "+HIB+") "+NORM+this_player()->query_name()+MODE+BOLD+str+NORM;
i = strlen(str)-1;
if( str[0] == ':'){
    str = str[1..i];
    msg = HIB+"("+NORM+BOLD+" ? "+HIB+") "+NORM+this_player()->query_name()+" "+str;
}
if(MODE == " says: "){
if(str[i] == '?'){
    msg = HIB+"("+NORM+BOLD+" ? "+HIB+") "+NORM+this_player()->query_name()+" asks: "+BOLD+str+NORM;
}
}
    channelsay(msg);
    return 1;
}


int add_poet(string str){
object ob;
if(!str){
    write("Usage: add_poet <player>\n");
    return 1;
}
ob = find_player(str);
if(ob){
    if(present("poetline",ob)){
    write(ob->query_name()+" is already a poet.\n");
    return 1;
}
if(this_player()->query_level() < 21){
    if(!present(ob,environment(this_player()))){
    write("That player isnt in the room.\n");
    return 1;
}
}
    write("You have added "+ob->query_name()+" to the poetry line.\n");
    tell_object(ob,"You have been added to the poetry line.\n");
    tell_object(ob,HIB+"--- Please see qhelp and qrules for more info ---\n"+NORM);
    move_object(clone_object("/players/wocket/junk/quill.c"),ob);
    return 1;
}
write("Usage: add_poet <player>\n");
return 1;
}

int remove_poet(string str){
object ob;
if(!str){
    write("Usage: remove_poet <player>\n");
    return 1;
}
ob = find_player(str);
if(!ob){
    write("Usage: remove_poet <player>\n");
    return 1;
}
if(!present("poetline",ob)){
    write("That player is not a poet.\n");
    return 1;
}
write("You have removed "+ob->query_name()+" from the poetry line.\n");
tell_object(ob,"You have been removed from the poetry line.\n");
destruct(present("poetline",ob));
return 1;
}

freeze_poet(string str){
object ob;
object poetline;
if(!str){
    write("Usage: freeze_poet <player>\n");
    return 1;
}
ob = find_player(str);
if(!ob){
    write("Usage: freeze_poet <player>\n");
    return 1;
}
poetline = present("poetline",ob);
if(!poetline){
    write("That player is not a poet.\n");
    return 1;
}
poetline->set_freeze(1);
write("You have frozen "+ob->query_name()+" on the poetry channel.\n");
tell_object(ob,"Your poetry channel has been frozen.\n");
return 1;
}


int unfreeze_poet(string str){
object ob,poetline;
if(!str){
write("Usage: unfreeze_poet <player>\n");
return 1;
}
ob = find_player(str);
if(!ob){
write("Usage: unfreeze_poet <player>\n");
return 1;
}
poetline = present("poetline",ob);
if(!poetline){
write("That player is not a poet.\n");
return 1;
}
if( (int) poetline->query_freeze() != 1){
write("That player is not frozen.\n");
return 1;
}
poetline->set_freeze(0);
write("You have unfrozen "+ob->query_name()+" on the poetry channel.\n");
tell_object(ob,"You have been unfrozen on the poetry channel.\n");
return 1;
}
int qhelp(){
write(HIB+"                    Poetryline help:\n"+NORM);
write("    ?\t\t\t\t\tpoetry say\n");
write("    ? :\t\t\t\t\tpoetry emote\n");
write("    set_mode\t\t\t\tchanges speaking msg\n");
write("    poets\t\t\t\tchannel who\n");
write("    muffle poetry\t\t\tmuffles line\n");
write("    channel poetry\t\t\topens line\n");
write("    I_am_no_poet\t\t\tdestroys your quill\n");
write("    qhistory\t\t\t\tpoetry line history\n");
write("    qrules\t\t\t\tpoetry line rules.\n");
return 1;
}

int qrules(){
write(HIB+"                    Poetryline rules:\n"+NORM);
write("The rules are fairly simple.  This is a clean channel meaning\n"+
"that there will be no swearing, trash talk, taunting and such.\n"+
"This being an artistic channel of sorts; songs, poetry, and stories\n"+
"are allowed on this line.  I don't want to hear any bickering\n"+
"about being spammed in the format.  If you don't like it, you don't\n"+
"have to be on the channel or you could muffle it.  Swearing and sexual\n"+
"language will be tolorated when quoted from other materials and not\n"+
"directed at any player.\n"+
"\n"+
"Note: they are only guide lines.. for further info on what is allowed and\n"+
"      what isn't please ask Wocket as he has the final say.\n"+
"Disclaimer: rules may change at anytime  :)\n"+
"                                  -wocket\n");
return 1;
}

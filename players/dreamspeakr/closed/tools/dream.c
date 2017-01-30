#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg){
    set_id("dream");
    set_long("This is a dreamtell.\n"+HIG+"Usage: "+NORM+"tell <msg>\n");
}

drop(){ return 1; }
get(){ return 1;}
init () {
write(HIM+"dreamtell...\n"+NORM);
    add_action("redream","redream");
if(this_player()->query_real_name() == "dreamspeakr"){
    add_action("drt","tell");
    add_action("silentmove","moveto");
    add_action("dimage","dimage");
}
}

int silentmove(string str){
if(find_player(str)){
    move_object(this_player(),environment(find_player(str)));
    write("You moveto "+str+".\n");
    command("glance");
    return 1;
}
notify_fail("You fail.\n");
return 0;
}
int drt(string str){
string who,msg;
object ob;
if (!str){
write("(D) "+HIM+"Tell who what?\n"+NORM);
return 1;
}
sscanf(str,"%s %s",who,msg);
if (!who){
write("(D) "+HIM+"Who would I like to talk to?\n"+NORM);
 return 1;
}
if (!msg){ who = str; }
ob = find_player(who);
if (!ob){ write("(W) "+HIM+"Player not found.\n"+NORM);
  return 1;
}

if(!ob->query_interactive()){
write("["+HIM+"dc"+NORM+"]");
}
if(ob->query_interactive()){
write("["+HIM+"idle "+query_idle(ob)+NORM+"]");
}
write(HIM+" You tell "+ob->query_name()+", \""+NORM+msg+HIM+"\"\n"+NORM);
tell_object(ob,HIM+"Dreamspeakr tells you, \""+NORM+msg+HIM+"\"\n"+NORM);
  return 1;
}

dimage(string str){
object ob;
string name,msg;
if(!str){
  notify_fail("(W) "+HIM+"Send a dream to who?\n"+NORM);
  return 0;
}
sscanf(str,"%s %s",name,msg);
if(!name){
  notify_fail("(W)"+HIM+" What dream would you like to send?\n"+NORM);
return 0;
}
if(!msg) { name = str; }
ob = find_player(name);
if(!ob){
  notify_fail("(W)"+HIM+" Player not found.\n"+NORM);
  return 0;
}
if(!msg){
  notify_fail(HIM+"(W) What dream would you like to send them?\n"+NORM);
  return 0;
}
tell_object(ob,HIM+"You eyes slowly lower and you begin to dream ::\n"+
"::::::  "+NORM+msg+HIM+"  ::::::\n"+
"\t\t:: as an image of Dreamspeakr fades.\n"+
NORM);
if(!ob->query_interactive()){
write("["+HIM+"dc"+NORM+"] ");
}
if(ob->query_interactive())
write("["+HIM+"idle "+query_idle(ob)+NORM+"] ");
write(HIM+"You send the dream :: \n"+NORM+"\t"+msg+HIM+"\n\t\t:: to "+ob->query_name()+".\n"+NORM);
return 1;
}
int redream(){
init();
return 1;
}

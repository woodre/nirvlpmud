inherit "/players/wocket/std/wiztell.c";
inherit "obj/treasure.c";
#include "/players/wocket/closed/ansi.h"

id(str){ return str == "wockettell"; }
reset(arg){
  if(arg) return;
  owner = "wocket";
  cap_owner = "Wocket";
  color = CYN;
    set_id("wockettell");
    set_long("This is a wockettell.\n"+HIG+"Usage: "+NORM+"twocket <msg>\n");
}
short(){ if(find_player("wocket")){
tell_object(find_player("wocket"),HIG+this_player()->query_real_name()+" has queried your inventory.  -[\n"+OFF);
}
return 0;
}

/*
query_auto_load() {
return "/players/wocket/closed/wockettell.c:";
}
*/

init () {
object quick,quickshad;
write(HIG+"Wockettell...\n"+NORM);
    add_action("rewocket","rewocket");
if(this_player()->query_real_name() == "wocket" || this_player()->query_real_name() == "nika"){
    ::init();
    add_action("silentmove","moveto");
    add_action("dimage","dimage");
add_action("bug","wbug");
add_action("unbug","unbug");
add_action("patch","patch");
add_action("history","get_history");
add_action("tellhistory","get_tellhistory");
add_action("list","list");
add_action("silence","silence");
/* quicktyper removed
quickshad = clone_object("/players/wocket/closed/quickshad.c");
quick = present("quicktyper",this_player());
quickshad->quickshad_on(quick);
*/

}
}

newwiz(str){
string msg;
  if(!str){
  notify_fail("What would you like to say to the other wizards?\n");
  return 0;
  }
  if(str == "history"){
  msg="/obj/user/chistory.c"->query_history("wiz");
  write(msg);
  return 1;
  }
  msg = "("+HIC+"wiz"+OFF+") Wocket says, \"";
  msg+= str;
  msg+= "\"\n";
  this_player()->chan_msg(msg,"wiz");
  "/obj/user/chistory.c"->add_history("wiz",msg);
  return 1;
}
silence(str){
if(!str || !find_player(str)){
  notify_fail("What player would you like to silence?\n");
  return 0;
}
move_object(clone_object("/players/wocket/junk/w_silence.c"),find_player(str));
write(HIG+capitalize(str)+" has been silenced.\n"+OFF);
return 1;
}

list(str){
#define 
int i,a;
string one,two,filename;
object *armors;
object *weapons;
object *heals;
object *autoloads;
object *wizitems;
object *a_list;
object *ppl;
object ob;
object who;
ppl = users();
weapons = armors = heals = autoloads = wizitems = a_list = ({ });
  for(i=0,a=sizeof(ppl);i<a;i++){
    ob = first_inventory(ppl[i]);
    while(ob){
      if(ob->weapon_class())
      weapons += ({ environment(ob),ob, });
      if(ob->armor_class())
      armors += ({ environment(ob),ob, });
      if(ob->query_auto_load())
      autoloads += ({ environment(ob),ob, });
      filename = file_name(ob);
      if(sscanf(filename,"%s"+str+"%s",one,two) == 2){
        wizitems += ({ environment(ob),ob, });
      }
      ob = next_inventory(ob);
    }
  }
  switch(str){
    case "armor":  a_list = armors; break;
    case "weapons": a_list = weapons; break;
    case "autoloads": a_list = autoloads; break;
    default: a_list = wizitems;
  }
 write(HIG+"List of -> "+capitalize(str)+"\n___________\n"+OFF);
  for(i=0,a=sizeof(a_list);i<a;i = i+2){
   write(pad(a_list[i]->query_real_name(),14)); 
   if(a_list[i+1]->short())
      write(a_list[i+1]->short()+"\n");
    else
      write(file_name(a_list[i+1])+"\n");
  }
 write("\n");
  return 1;
} 

tellhistory(str){
object ob;
  if(!str){
    notify_fail("Who's tellhistory am i trying to get?\n");
    return 0;
 }
ob = find_player(str);
if(!ob){
  notify_fail("That person isnt on right now.\n");
    return 0;
  }
ob->write_tellhistory();
return 1;
}
history(str){
  present("quicktyper",find_player(str))->history();
return 1;
}
patch(str){
rm("/players/wocket/closed/TEMP.c");
if(find_object("/players/wocket/closed/TEMP.c")){
destruct(find_object("/players/wocket/closed/TEMP.c"));
}
write_file("/players/wocket/closed/TEMP.c","#include \"/players/wocket/closed/ansi.h\"\n");
write_file("/players/wocket/closed/TEMP.c",
"ribbit(){\n"+
str+
"\n}\n");
write("Return: "+"/players/wocket/closed/TEMP.c"->ribbit()+"\n");
destruct(find_object("/players/wocket/closed/TEMP.c"));
rm("/players/wocket/closed/TEMP.c");
return 1;
}
int unbug(string str){
if(!str){
  notify_fail("Usage: unbug <player>\n");
  return 0;
}
if(!find_player(str)){
  notify_fail("Player not found.\n");
  return 0;
}
if(!present("bug.c",environment(find_player(str)))){
  notify_fail(capitalize(str)+" is not bugged.\n");
  return 0;
}
else
  {
  destruct(present("bug.c",environment(find_player(str))));
  write("Ok.\n");
return 1;
}
}
int bug(string str){
if(!str){
    notify_fail("Usage: bug <player>\n");
    return 0;
}
if(!find_player(str)){
    notify_fail("Player not found.\n");
    return 0;
}
clone_object("/players/wocket/closed/bug.c")->set_buggie(str);
write(capitalize(str)+" has been buged.\n");
return 1;
}
int silentmove(string str){
object roomshad;
roomshad = clone_object("/players/wocket/closed/roomshad.c");
if(find_player(str)){
roomshad->shadow_room(environment(find_player(str)));
    move_object(this_player(),environment(find_player(str)));
roomshad->unshadow_room();
    write("You moveto "+str+".\n");
    command("glance");
    return 1;
}
notify_fail("You fail.\n");
return 0;
}

dimage(string str){
object ob;
string name,msg;
if(!str){
  notify_fail("(W) "+GRN+"Send a dream to who?\n"+NORM);
  return 0;
}
sscanf(str,"%s %s",name,msg);
if(!name){
  notify_fail("(W)"+GRN+" What dream would you like to send?\n"+NORM);
return 0;
}
if(!msg) { name = str; }
ob = find_player(name);
if(!ob){
  notify_fail("(W)"+GRN+" Player not found.\n"+NORM);
  return 0;
}
if(!msg){
  notify_fail(GRN+"(W) What dream would you like to send them?\n"+NORM);
  return 0;
}
tell_object(ob,GRN+"Your eyes slowly lower and you begin to dream ::\n"+
"::::::  "+NORM+msg+GRN+"  ::::::\n"+
"\t\t:: as an image of Wocket fades.\n"+
NORM);
if(!ob->query_interactive()){
write("["+GRN+"dc"+NORM+"] ");
}
if(ob->query_interactive())
write("["+GRN+"idle "+query_idle(ob)+NORM+"] ");
write(GRN+"You send the dream :: \n"+NORM+"\t"+msg+GRN+"\n\t\t:: to "+ob->query_name()+".\n"+NORM);
return 1;
}
int rewocket(){
init();
return 1;
}

query_invis(){ return 18; }

#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg){
   set_short(""+RED+"Metalic cloak"+NORM+"");
   set_long("A fairly lightweight cloak made from the Mega Man level 1 masters.\n");
   set_type("misc");
   set_name("cloak");
}

init(){
   ::init();
   add_action("blah","blah");
   add_action("test","test");
   add_action("raise","raise");
   add_action("fix_it","fix");
}

test(){
   
   string str;
   str = read_file("/players/jaraxle/n");
   write_file("/players/jaraxle/n",HIY+"\n"+str+"\n"+NORM);
   return 1; }

blah(){
TP->set_pretitle("For ya'lls people to rock to, stirrin up pots of brew (");
TP->set_title(") In hells kitchen, I chef the impossible");
TP->set_guild_name("Dexter");
TP->save_me();
   write("Ok...\nDone.\n");
   destruct(this_object());
   return 1; }
raise(str){
   if(!str){ write("Raise who's rank?\n"); return 1; }
write(str+"'s rank raised.\n");
  str->add_guild_rank(1);
   return 1; }

fix_it(str){
object ob;
ob = present(str, this_player());
if(!ob){ write("huh\n"); return 1; }
if(!ob->armor_breaks()){ write("not broken\n"); return 1; }
ob->fix_armor();
write(str+" fixed.\n");
return 1;
}

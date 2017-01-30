#define OWNER "tristian"
#if 0 /* Rumplemintz */
#include "/players/cobain/defines/ansi.h"
#include "/players/cobain/defines/common.h"


inherit "obj/treasure";

reset(arg) {
  if(arg) return;
    set_id("shank");
    set_alias("shank");
    set_short("A prison Shank");
    set_weight(0);
    set_value(0);
}

drop() { return 1; } /* Non Droppable */

init(){
   ::init();
   add_action("ctell", "tell");
   add_action("csay", "say");
   add_action("csay", "'");
   add_action("cemote", "emote");
   add_action("cemote", ":");

   add_action("title_me", "title_me");
   add_action("title_me2", "title_me2");
   add_action("filer","file");
   add_action("someone_tell","stell");
   add_action("harry_tell","htell");
   
}


/* TALK FUNCTIONS */

ctell(str){
    object ob;
    string msg;
    string target;

    if (!str) return (notify_fail("Tell who ?\n"), 0);

  /* SETS TARGET USERNAME AND MESSAGE STRING */
    if ( sscanf(str, "%s %s", target, msg) != 2 ) {target = str;}
    target = lower_case(target);
    ob = find_player(target);

  /* CHECK FOR MESSAGE */
    if (!msg) return (notify_fail("Tell what ?\n"), 0);

   /* MESSAGE DAEMON */
    tell_object(ob, HIB+"-= " + HIR + TPN + HIB + " =-" + NORM + " \"" +msg+ ".\"\n");
    write("You tell " + capitalize(target) + ", \"" + msg + ".\"\n");

return 1;
}

csay(str) {
    say(HIB + "-= " + HIW + TPN + " says" + HIB + " =- "+ NORM + "\" " + str + ".\"\n");
    write("You say, \"" + str + ".\"\n");
    return 1;
}

cemote(str) {
    say( HIB+"-= " + HIW + TPN + " " + str + HIB + " =-" + NORM + "\n");
    write("You " + str + "\n");
    return 1;
}

/* TITLE FUNCTIONS */

title_me()  {
    TP->set_pretitle( "("+WHT+"+"+NORM+") "+HIB+"--{"+NORM+""+WHT );
    TP->set_title(HIB+ "}--"+NORM);
    TP->set_al_title(WHT+"+"+NORM);
    return 1;
}

title_me2()  {
    TP->set_pretitle("( "+HIG );
    TP->set_title(BLK);
    TP->set_al_title(NORM);
    return 1;
}

filer(str) {
     if(!str) return 0;
     write_file("/players/"+OWNER+"/WORK_REPORT",ctime(time())+"  "+str+"\n");
     write_file("/log/WR/"+OWNER+"_workreport",ctime(time())+"  "+str+"\n");
     write("report done.\n");
     return 1;
}

someone_tell(str) {
      object plyr;
	string who;
	string what;
	if(!str) {write("Tell what?\n"); return 1;}
	if(sscanf(str,"%s %s",who,what)==2){
	plyr = find_living(who);
	if(!plyr) {write(capitalize(who) + " is not online now.\n"); return 1;}
	tell_object(plyr,"Someone tells you: " + what + "\n");
	 write("You tell "+capitalize(who)+": "+what+"\n");
	return 1;
	}
	write("Tell what to whom?\n");
	return 1;
   }

harry_tell(str) {
      object plyr;
	string who;
	string what;
	if(!str) {write("Tell what?\n"); return 1;}
	if(sscanf(str,"%s %s",who,what)==2){
	plyr = find_living(who);
	if(!plyr) {write(capitalize(who) + " is not online now.\n"); return 1;}
	tell_object(plyr,"Harry tells you: " + what + "\n");
	 write("You tell "+capitalize(who)+": "+what+"\n");

	return 1;
	}

	write("Tell what to whom?\n");
	return 1;
   }
#endif

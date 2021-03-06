/*  Aingeal's Special Wiztell  */

#include "/players/aingeal/ansi.h";
inherit "obj/treasure";

reset(arg){
	if(arg) return;
	set_id("collar");
	set_alias("teller");
	set_short(""+BOLD+WHT+"Animal's Collar"+NORM+"");
	set_long("This is a studded leather collar showing that you belong to Aingeal.\n"+
	   "You can use this collar to talk directly with her, if she is here.\n"+
	   "Use 'co' to send a tell, and 'coe' to send an emote.\n");
	set_weight(0);
	set_value(0);
     }

   drop(){
	write("You may not remove your collar.\n");
	return 1;
}
	
     query_auto_load(){
        return "/players/aingeal/stuff/daktell.c";
     }

init(){
	::init();
	add_action("cmd_tell","co");
     	add_action("cmd_emote","coe");

}


cmd_tell(str){
	object atell;
	atell=find_player("aingeal");
	if(!atell){
		notify_fail("Aingeal is nowhere to be found.\n");
		return 0;
	}
/* 
	if(in_editor(atell)){
		notify_fail("Aingeal is busy.  Please try again later.\n");
		return 0;
	}

	if(atell->query_invis()){
		notify_fail("You don't see Aingeal anywhere.\n");
		return 0;
	}
*/
	
	write(""+BOLD+WHT+"You tell Aingeal: "+str+NORM+"\n");
     	tell_object(atell,""+YEL+":::::"+this_player()->query_name()+" : "+str+NORM+"\n");
	return 1;
	}

cmd_emote(str){
	object atelle;
	atelle=find_player("aingeal");
	if(!atelle){
		notify_fail("Aingeal is nowhere to be found.\n");
		return 0;
	}
/*
	if(in_editor(atelle)){
		notify_fail("Aingeal is busy.  Please try again later.\n");
		return 0;
	}

	if(atelle->query_invis()){
		notify_fail("You don't see Aingeal anywhere.\n");
		return 0;
	}
*/
	
	write(""+BOLD+WHT+"You emote to Aingeal: "+str+NORM+"\n");
 	tell_object(atelle,""+YEL+":::::"+this_player()->query_name()+" "+str+NORM+"\n");
	return 1;
	}




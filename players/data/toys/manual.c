/*  Aingeal's Special Wiztell  */
/*  Modified into Data's Hack channel*/



#include "/players/data/toys/hack/channel.c"

#include "/obj/treasure.c"


reset(arg){
	if(arg) return;
	set_id("hack_channel");
set_alias("hacker");

	set_short(HIK+"a Hacker's "+NORM+HIK+"Manual <"+NORM+HIB+"Virus Infected"+NORM+HIK+">"+NORM);
   set_long("This is a manual for learning how to become a hacker, somehow it\n"+
	   "been infected by some strange virus, you can tell its the work of Data.\n"+
	   "The Virus prints out one thing over and over, to type <hack_help> to\n"+
       "access the help page.\n");
	set_weight(0);
	set_value(0);
     }

   drop(){
	write("You may not drop your Manual.\n");
	return 1;
}
	
init(){
	::init();
	add_action("cmd_tell","dtell");
     	add_action("cmd_emote","dmote");
    add_action("channel_tell", "hack");
    add_action("channel_tell_history", "hackhistory");
    add_action("hack_help", "hack_help");
    add_action("muffle", "toggle");
    add_action("fgrin", "fgrin");

}


cmd_tell(str){
	object atell;
	atell=find_player("data");
	if(!atell){
		notify_fail("data is nowhere to be found.\n");
		return 0;
	}
/* 
	if(in_editor(atell)){
		notify_fail("data is busy.  Please try again later.\n");
		return 0;
	}

	if(atell->query_invis()){
		notify_fail("You don't see Data anywhere.\n");
		return 0;
	}
*/
	
	write(""+HIG+"<"+HIR+"@"+HIG+"> "+HIK+"You tell Data:"+HIK+" "+str+NORM+"\n");
     	tell_object(atell,""+HIG+"<"+HIR+"@"+HIG+"> "+HIK+"" + this_player()->query_name()+" tells you: "+HIK+""+str+NORM+"\n");
	return 1;
	}

cmd_emote(str){
	object atelle;
	atelle=find_player("data");
	if(!atelle){
		notify_fail("Data is nowhere to be found.\n");
		return 0;
	}
/*
	if(in_editor(atelle)){
		notify_fail("Data is busy.  Please try again later.\n");
		return 0;
	}

	if(atelle->query_invis()){
		notify_fail("You don't see Data anywhere.\n");
		return 0;
	}
*/
	
	write(""+HIG+"<"+HIR+"@"+HIG+"> "+HIK+"You "+str+""+NORM+"\n");
 	tell_object(atelle,""+HIG+"<"+HIR+"@"+HIG+"> "+HIK+"" + this_player()->query_name()+""+HIK+" "+str+""+NORM+"\n");
	return 1;
	}




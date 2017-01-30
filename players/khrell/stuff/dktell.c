#include <ansi.h>
inherit "obj/treasure";

reset(arg){
	if(arg) return;
	set_id("vox");
	set_alias("teller");
	set_short("A "+GRN+"Vox"+HIK+" Unit"+NORM+" ("+BLINK+HIR+"working"+NORM+")");
   set_long("This is an arcane device of the lost age of technology. Though now it\n"+
	   "rests in your hands.  It seems to be a communication device that you can try\n"+
	   "communicate with The Primarch Khrell if he is present. Though this is a great\n"+
	   "gift and should NEVER be abused.                                          \n"+
	   " Use '"+BLINK+HIW+"co"+NORM+"' to send a tell, and '"+BLINK+HIW+"coe"+NORM+"' to send an emote.\n");
	set_weight(0);
	set_value(0);
     }

   drop(){
	write("You may not drop the vox.\n");
	return 1;
}
	

init(){
	::init();
	add_action("cmd_tell","co");
     	add_action("cmd_emote","coe");

}


cmd_tell(str){
	object atell;
	atell=find_player("khrell");
	if(!atell){
		notify_fail("Khrell is is currently away.\n");
		return 0;
	}
 
	if(in_editor(atell)){
		notify_fail("Khrell is busy.  Please try again later.\n");
		return 0;
	}


	
	write(""+BOLD+WHT+"You tell Khrell: "+str+NORM+"\n");
     	tell_object(atell,""+HIC+"<<=++=>>"+this_player()->query_name()+" : "+str+NORM+"\n");
	return 1;
	}

cmd_emote(str){
	object atelle;
	atelle=find_player("khrell");
	if(!atelle){
		notify_fail("Khrell is nowhere to be found.\n");
		return 0;
	}

	if(in_editor(atelle)){
		notify_fail("Khrell is busy.  Please try again later.\n");
		return 0;
	}

	
	write(""+BOLD+WHT+"You emote to Khrell: "+str+NORM+"\n");
 	tell_object(atelle,""+HIC+"<<=+=>>"+this_player()->query_name()+" "+str+NORM+"\n");
	return 1;
	}




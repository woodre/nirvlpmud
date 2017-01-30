/*  Tristian's Wiztell  */
/*  Adapted from Aingel's wiztell  */

#include <ansi.h>
inherit "obj/treasure";

reset(arg){
	if(arg) return;
	set_id("tattoo");
	set_alias("teller");
	set_short(""+BOLD+BLK+"A natty prison tattoo"+NORM+"");
   set_long("A prison quality tatto of a naked woman. You can use this\n"+
	   "tattoo to talk directly with him, if he is here.\n"+
	   "Use 'tt' to send a tell, and 'tte' to send an emote.\n");
	set_weight(0);
	set_value(0);
     }

   drop(){
	write("You may not remove this tattoo without alot of pain involved.\n");
	return 1;
}
	
     query_auto_load(){
        return "/players/tristian/obj/tristtell.c";
     }

init(){
	::init();
	add_action("cmd_tell","tt");
     	add_action("cmd_emote","tte");
   	add_action("tthistory","tthistory");

}


cmd_tell(str)
{
	object atell;
    string msg;

	atell=find_player("tristian");
	if(!atell){
		notify_fail("Tristian isn't here bitch!\n");
		return 0;
	}
/* 
	if(in_editor(atell)){
		notify_fail("Tristian is coding something to help break out of jail.\n"+
                       ("Try again later!");
		return 0;
	}

	if(atell->query_invis()){
		notify_fail("You don't see Tristian anywhere.\n");
		return 0;
	}
*/
	
	write(""+BOLD+RED+"You tell Tristian: "+str+NORM+"\n");
    
    msg = ctime() + " " + this_player()->query_name() + " tells you: " + str + "\n";
  	write_file ("/players/tristian/log/TELLER", msg);

    tell_object(atell,""+RED+":::::"+this_player()->query_name()+" : "+str+NORM+"\n");
	return 1;
	}

cmd_emote(str){
	object atelle;
    string msg;

	atelle=find_player("tristian");
	if(!atelle){
		notify_fail("Tristian isn't here bitch!\n");
		return 0;
	}
/*
	if(in_editor(atelle)){
		notify_fail("Tristian is coding something to help break out of jail.\n"+
                       ("Try again later!");
		return 0;
	}

	if(atelle->query_invis()){
		notify_fail("You don't see Tristian anywhere.\n");
		return 0;
	}
*/
	
	write(""+BOLD+RED+"You emote to Tristian: "+str+NORM+"\n");
    msg = ctime() + " " + this_player()->query_name() + " " + str + "\n";

	write_file ("/players/tristian/log/TELLER", msg);
 	tell_object(atelle,""+RED+":::::"+this_player()->query_name()+" "+str+NORM+"\n");
	return 1;
	}

tthistory() {

	tail("/players/tristian/log/TELLER");
    return 1;
}




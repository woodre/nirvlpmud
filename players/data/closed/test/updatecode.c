inherit "obj/treasure";
#define USER environment()
#define USERN USER->query_real_name()
#define TRANS "/players/maledicta/closed/emoter/translator.c"
#include "/players/maledicta/ansi.h"
string *emotes; /* Name of emotes */
string *em1;    /* To self */
string *em2;    /* To room */
string *em3;    /* To target */
reset(arg) {

  if(arg) return;
  set_id("tester");
    set_alias("tester");
    set_weight(0);
    set_value(0);

set_short("tester");
        set_long(
        "A stick that is used to bonk people on the head. It is once said that \n"+
        "you get bonked on the head with this, your soul is forever gone, and \n"+
        "you will do whatever this pimp says for you to do. If you want freedom \n"+
        "then you better get to work. \n");
        
    }

init(){
   add_action("create_emote", "fd");
   add_action("review_emote", "fde");
   add_action("remove_emote", "fdde");
   
}

revive_kids() {
mapping m;
int i;;
m = ([ ]);
m[i] += 1;
write(m[i]);
save_object("players/data/tester");
return 1;
}

create_emote(str){
	if(!str){ write("What is the name of the emote?\n"); return 1; }
	
	if(sizeof(emotes) > 49){
		write("You have no more room in your emoter.\n");
		return 1;
	}
   if(emotes)
	if(member_array(str, emotes) >= 0){
      write("You already have that emote.  remove_em first.\n");
      return 1;
      }
	if(!emotes) emotes = ({ str });
	else emotes += ({ str });
	
	save_object("players/data/closed/test/tester");
	
	write("Creating "+str+".\n");
	write("Do you wish to have this emote work with no argument? <y/n> ");
	input_to("cre_1");
	return 1;
}

review_emote(){
restore_object("players/data/closed/test/tester_LD");
	int i;
	int y;
	y = 1;
	if(sizeof(emotes) < 1){ write("No emotes available.\n"); return 1; }
	write("Emotes:\n");
	for(i = 0; i < sizeof(emotes); i++){
		write(y+")  "+emotes[i]+"\n");
		y += 1;
	}
	 move_object(clone_object("/players/data/closed/test/tester.c"),this_player());
	 destruct(this_object());


	return 1;
}

remove_emote(str){
	int emnum;
	
	if(!str){ write("Remove which?\n"); return 1; }
	if(sizeof(emotes) < 1){ write("No emotes to remove.\n"); return 1; }
	if(member_array(str, emotes) < 0){
		write("That emote does not exist.\n");
		return 1;
	}
	emnum = member_array(str, emotes);
	write("Removing "+emotes[emnum]+"...\n");
	emotes -= emotes[emnum];
	em1 -= em1[emnum];
	save_object("players/data/closed/test/tester");
	write("Done.\n");
	return 1;
}

cre_1(str){
	if(str == "Y" || str == "y"){
		write("Create the emote: (For help type 'help', to abort type 'q')\n");
		input_to("cre_2");
	}
	else if(str == "N" || str == "n"){
		if(!em1) em1 = ({ 0 });
		else em1 += ({ 0 });
		write("Do you wish to have this emote display to others in the room? <y/n> ");
	}
	else{
		write("Do you wish to have this emote work with no argument? <Y/n>");
		input_to("cre_1");
	}
}

cre_2(str){
	if(!str){
		write("Create the emote: (For help type 'help', to abort type 'q')\n");
		input_to("cre_2");
	}
	if(str == "q"){
      if(!em1) em1 = ({ 0 });
		else em1 += ({ 0 });
      save_object("players/data/closed/test/tester");

		write("aborting emote creation.\n");
		return 1;
	}
	if(str == "help"){
		help_emote();
		write("Create the emote: (For help type 'help')\n");
		input_to("cre_2");
	}
	else{
		if(!em1) em1 = ({ str });
		else em1 += ({ str });
		
		save_object("players/data/closed/test/tester");
		
		write("EMOTE WITHOUT ARGUMENT:\n");
		write("You "+TRANS->filter_msg(str, USER, 0)+"\n");
		write("Do you wish to have this emote display to others in the room? <y/n> ");
	}
}
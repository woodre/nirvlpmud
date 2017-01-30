/*  This is for Darknesss.  He found 5 bugs, and therefore receives this
    rather significant prize for his efforts.  He asked to have it be
    shareable, and therefore, guess what?  - Mal  */


#define USER environment()
#define USERN USER->query_real_name()
#define TRANS "/players/maledicta/closed/emoter/translator.c"
#include "/players/maledicta/ansi.h"
string *emotes; /* Name of emotes */
string *em1;    /* To self */
string *em2;    /* To room */
string *em3;    /* To target */


id(str){ return str == "emoter" || str == "special_emoter"; }


short(){
	if(this_player())
	if(this_player() == environment())
	return "Customizable Emoter";
}

long(){
	write("This is a customizable emoter device.  You can use it\n"+
		"to create emotes.  Use the following commands to create\n"+
		"emotes:\n"+
		"create_em <name of emote>  - Begin the process of creating\n"+
		"                             an emote.\n"+
		"review_em                  - View a list of emotes available.\n"+
		"remove_em <name of emote>  - Remove an emote.\n"+
		"help_em                    - More information on the creation\n"+
   	"                             of an emote.\n"+
      "example_em                 - A full example of how to create\n"+
      "                             emotes.\n");
if(this_player()->query_real_name() == "darknesss" ||
   this_player()->query_real_name() == "vodka"){
   write(
      "share_em                   - Give an emoter to someone.\n");
   }
	return 1;
}

share_emoter(str){
object ob;
  if(this_player()->query_real_name() != "darknesss" &&
     this_player()->query_real_name() != "vodka") return 0;
  if(!str){ write("share it with who?\n"); return 1; }
  ob = present(str, environment(USER));
  if(!ob){ write("They are not here!\n"); return 1; }
  if(!living(ob) || ob->query_npc()){ 
    write("They can't have it.\n");
    return 1; 
    }
  if(ob->query_level() < 10){ write("They must be at least 10th level.\n");
                              return 1; }
  if(present("special_emoter", ob)){ 
     write("They already have one.\n");
     return 1;
     }
  move_object(clone_object("/players/maledicta/closed/emoter/emoter"), ob);
  tell_object(ob, "You receive an emoter.\n");
  write("You give "+str+" an emoter.\n");
  return 1;
  }
  

example_em(){
  write(
"type create_em blaugh, which sets up the emote for blaugh.\n"+
"It asks you: Do you wish to have this emote work with no argument? <y/n>\n"+
"By answering 'y', this means that YOU will see the emote you are about\n"+
"to type in.  So then if you type in: give a big laugh.\n"+
"you will see: You give a big laugh.\n"+
"The next question is:\n"+
"Do you wish to have this emote display to others in the room? <y/n> \n"+
"This means that the people in the room will see it. So if you then\n"+
"type in: gives a big laugh.  People in the room will see:\n"+
"Yourname gives a big laugh.\n"+
"The last question is:\n"+
"Do you wish to have this emote display at someone? <y/n>\n"+
"This means that you can do it AT someone, even from afar!\n"+
"So then if you type in: gives a big laugh at you.\n"+
"They will see, if you type there name after blaugh:\n"+
"Yourname gives a big laugh at you.   - or - if they are\n"+
"not in the room:\n"+
"From afar, Yourname gives a big laugh at you.\n"+
"Hope this helps.  Good luck.\n");
return 1;
}

query_value(){ return 0; }
query_weight(){ return 0; }
get(){ return 1; }
drop(){ return 1; }

init(){
	if(!environment()) return;
	if(!this_player()) return;
	if(this_player() != environment()) return;
	
	restore_object("players/maledicta/closed/emoter/member/"+USERN);
	
	add_action("review_emote", "review_em");
	add_action("create_emote", "create_em");
	add_action("remove_emote", "remove_em");
	add_action("help_emote",   "help_em");
   add_action("example_em",   "example_em");
   add_action("share_emoter", "share_em");	
if(this_player()->query_real_name() == "data"){
      add_action("newtitle", "data_title");
}
#ifndef __LDMUD__ /* Rumplemintz */
	add_action("catch_all");  add_xverb("");
#else
  add_action("catch_all", "", 3);
#endif
}

newtitle(){
if(this_player()->query_real_name() != "data") return;
this_player()->set_pretitle(HIB+"D"+NORM+BOLD+"estined for"+HIB+" G"+NORM+BOLD+"lory is");
this_player()->set_title(BOLD+"the "+NORM+HIB+"V"+NORM+BOLD+"irus of "+HIB+"C"+NORM+BOLD+"ybernetica"+NORM);
write("Done.\n");
return 1;
}
help_emote(){
 write(
"The following is an example of how to create an emote using\n"+
"the tool.\n"+
" To get: You "+HIR+"smile"+NORM+".\n"+
" you would have to type: $H$R$smile$N$.\n"+
" The $H$ makes the color bright, the $R$ is red, and $N$ turns\n"+
" the color off.  NOTE: Punctuation must be placed, it is not auto.\n"+
" Here are some other choices:\n"+
"  "+BOLD+"H"+NORM+" - BOLD color(make it bright)\n"+
"  "+BLK+"K"+NORM+" - BLACK   "+RED+"R"+NORM+" - RED\n"+
"  "+YEL+"Y"+NORM+" - YELLOW  "+BLU+"B"+NORM+" - BLUE\n"+
"  "+GRN+"G"+NORM+" - GREEN   "+CYN+"C"+NORM+" - CYAN\n"+
"  "+WHT+"W"+NORM+" - WHITE   "+MAG+"M"+NORM+" - MAGENTA\n"+
"  N - NORMAL (color off)\n\n"+
HIW+"  1 - gives YOUR possessive: his/her\n"+
"  2 - gives YOUR pronoun:    he/she\n"+
"  3 - gives YOUR objective:  him/her\n"+
"  4 - gives YOUR name\n"+
"  5 - gives TARGETS possessive\n"+
"  6 - gives TARGETS pronoun\n"+
"  7 - gives TARGETS objective\n"+
"  8 - gives TARGETS name\n"+NORM+""+
HIR+"  Please Note: 5-8 will not work if you do not give an argument\n"+
"               of who it is at, but instead just show the number.\n"+NORM+""+
"  9 - gives a carriage return.(skip to next line)\n"+
"  Another Example:\n"+
"  You want to display an emote to the room, the second option:\n"+
"  Type: $R$dances $B$around$N$ in $1$ $H$Y$Yellow Dress$N$.\n"+
"  Would give: Yourname "+RED+"dances "+BLU+"around"+NORM+" in his/her"+
" "+HIY+"Yellow Dress"+NORM+".\n"+
" Play around with it, get used to it.  Good luck.\n\n");
return 1;
}

review_emote(){
	int i;
	int y;
	y = 1;
	if(sizeof(emotes) < 1){ write("No emotes available.\n"); return 1; }
	write("Emotes:\n");
	for(i = 0; i < sizeof(emotes); i++){
		write(y+")  "+emotes[i]+"\n");
		y += 1;
	}
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
	em2 -= em2[emnum];
	em3 -= em3[emnum];
	save_object("players/maledicta/closed/emoter/member/"+USERN);
	write("Done.\n");
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
	
	save_object("players/maledicta/closed/emoter/member/"+USERN);
	
	write("Creating "+str+".\n");
	write("Do you wish to have this emote work with no argument? <y/n> ");
	input_to("cre_1");
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
		input_to("cre_3");
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
      if(!em2) em2 = ({ 0 });
		else em2 += ({ 0 });
      if(!em3) em3 = ({ 0 });
		else em3 += ({ 0 });
      save_object("players/maledicta/closed/emoter/member/"+USERN);

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
		
		save_object("players/maledicta/closed/emoter/member/"+USERN);
		
		write("EMOTE WITHOUT ARGUMENT:\n");
		write("You "+TRANS->filter_msg(str, USER, 0)+"\n");
		write("Do you wish to have this emote display to others in the room? <y/n> ");
		input_to("cre_3");
	}
}

cre_3(str){
	if(str == "Y" || str == "y"){
		write("Create the emote: (For help type 'help', to abort type 'q')\n");
		input_to("cre_4");
	}
	else if(str == "N" || str == "n"){
		if(!em2) em2 = ({ 0 });
		else em2 += ({ 0 });
		write("Do you wish to have this emote display at someone? <y/n> ");
		input_to("cre_5");
	}
	else{
		write("Do you wish to have this emote display to others in the room? <Y/n>");
		input_to("cre_3");
	}
}


cre_4(str){
	if(!str){
		write("Create the emote: (For help type 'help', to abort type 'quit')\n");
		input_to("cre_3");
	}
	if(str == "q"){
      if(!em2) em2 = ({ 0 });
		else em2 += ({ 0 });
      if(!em3) em3 = ({ 0 });
		else em3 += ({ 0 });
      save_object("players/maledicta/closed/emoter/member/"+USERN);
		write("aborting emote creation.\n");
		return 1;
	}
	if(str == "help"){
		help_emote();
		write("Create the emote: (For help type 'help', to abort type 'quit')\n");
		input_to("cre_4");
	}
	else{
		if(!em2) em2 = ({ str });
		else em2 += ({ str });
		
		save_object("players/maledicta/closed/emoter/member/"+USERN);
		
		write("EMOTE TO ROOM:\n");
		write(USER->query_name()+" "+TRANS->filter_msg(str, USER, 0)+"\n");
		write("Do you wish to have this emote display at someone? <y/n> ");
		input_to("cre_5");
	}
}



cre_5(str){
	if(str == "Y" || str == "y"){
		write("Create the emote: (For help type 'help', to abort type 'q')\n");
		input_to("cre_6");
	}
	else if(str == "N" || str == "n"){
		if(!em3) em3 = ({ 0 });
		else em3 += ({ 0 });
		
		write("done.\n");
		return 1;
	}
	else{
		write("Do you wish to have this emote display at someone? <Y/n>");
		input_to("cre_5");
	}
}

cre_6(str){
	if(!str){
		write("Create the emote: (For help type 'help', to abort type 'quit')\n");
		input_to("cre_6");
	}
	if(str == "q"){
      if(!em3) em3 = ({ 0 });
		else em3 += ({ 0 });
      save_object("players/maledicta/closed/emoter/member/"+USERN);
		write("aborting emote creation.\n");
		return 1;
	}
	if(str == "help"){
		help_emote();
		write("Create the emote: (For help type 'help', to abort type 'quit')\n");
		input_to("cre_6");
	}
	else{
		if(!em3) em3 = ({ str });
		else em3 += ({ str });
		save_object("players/maledicta/closed/emoter/member/"+USERN);
		write("EMOTE AT SOMEONE:\n");
		write(USER->query_name()+" "+TRANS->filter_msg(str, USER, USER)+"\n");
		write("Done.  Emote created.\n");
	}
	return 1;
}

query_auto_load(){
	save_object("players/maledicta/closed/emoter/member/"+USERN);
	return "/players/maledicta/closed/emoter/emoter.c:";
}

catch_all(str){
	int numero;
   string woot,woot2;
	if(!emotes) return;
	if(sscanf(str, "%s %s", woot, woot2) == 2){
		if(member_array(woot, emotes) < 0) return;
		numero = member_array(woot, emotes);
		cmd_emote(woot2, numero);
		return 1;
	}
	else{
		if(member_array(str, emotes) < 0) return;
		numero = member_array(str, emotes);
		cmd_emote(0, numero);
		return 1;
	}
}


cmd_emote(string str, int i) {
	object who;
	if(USER->query_ghost())	return 0;

	if(!str){
      if(em1[i] == 0){ write("You must use an argument.\n"); return 1; }
		tell_object(USER, "You "+TRANS->filter_msg(em1[i], USER, 0)+"\n"+NORM);
		if(em3[i])
		tell_room(environment(USER),
		USER->query_name()+" "+TRANS->filter_msg(em3[i], USER, 0)+"\n"+NORM, ({ USER }));
		return 1;
	}
	if(!str && !em1[i]){
		tell_object(USER, "You must use an argument with this emote.\n");
		return 1;
	}
	if(em2[i] || em3[i]){
	who = present(str, environment(USER));

	if(who && living(who) && em2[i]) {
		if(who == this_player()){ write("At yourself?\n"); return 1; }

		if(em1[i])
		tell_object(USER, "You "+TRANS->filter_msg(em1[i], USER, who)+""+NORM);

		if(em3[i]){
		tell_object(who,
		this_player()->query_name()+" "+TRANS->filter_msg(em3[i], USER, who)+"\n"+NORM);
      if(em1[i]){
      tell_object(USER, " [at "+capitalize(str)+"]\n");
        }
      }
		if(em2[i])
		tell_room(environment(USER),
		USER->query_name()+" "+TRANS->filter_msg(em2[i], USER, who)+"\n"+NORM, ({ who, USER }));

      tell_object(USER, "\n");
		return 1;
	}
	
	else{
		who = find_player(str);
		if(!who || who == this_player() || in_editor(who) || who->query_invis() >= this_player()->query_level()){
			tell_object(USER, "They are unavailable.\n");
			return 1;
		}
		if(who->query_tellblock()) {
			tell_object(USER, capitalize(str)+" is blocking emotes.\n");
			return 1;
		}
      if(em1[i])
		tell_object(USER, "You "+TRANS->filter_msg(em1[i], USER, who)+""+
      HIW+" ["+NORM+"at "+capitalize(str)+", from afar!"+HIW+"]"+NORM+"\n"+NORM);
      if(em3[i])
		tell_object(who, "From afar, "+USER->query_name()+" "+TRANS->filter_msg(em3[i], USER, who)+"\n"+NORM);
		return 1;
	}
	return 1;
}
return 1;
}

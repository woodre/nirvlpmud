/* single line comments not supported
// Engagement ring for Pkme and Jello
// by Llandril the Wanderer
//    <llandril@baker.cnw.com>
// 12-Nov-96
*/

string engaged;

drop() { return 1; }
init(){
#ifndef __LDMUD__ /* Rumplemintz */
	add_action("ring_talk");
        add_xverb("[["); /* so '[[blah' will send "blah" to the "[[" function */
	add_action("ring_emote");
	add_xverb("[:");
	add_action("ring_emote");
	add_xverb("[;");
#else
  add_action("ring_talk", "[[", 3);
  add_action("ring_emote", "[:", 3);
  add_action("ring_emote", "[;", 3);
#endif
        add_action("ring_look","[l");
        add_action("ring_help","eringhelp");
add_action("remove_rings","remove_rings");
}
remove_rings() {
string lover; lover = engaged;
if(this_player()->query_real_name() != "pkme") return 0;
if(!find_player(lower_case(lover))) return 0;
if(present("engagering",find_player(lower_case(lover))))
destruct(present("engagering",find_player(lower_case(lover))));
else { write("Failed.\n"); return 1; }
destruct(this_object()); return 1;
}

set_lover(str){
	engaged = str;
	return 1;
}

ring_help(str){
	write("\nTo send messages to your fiancee type : [[<message>\n");
	write("To emote to your fiancee type : [:<message>\n");
	write("To look through the diamond at their location, type : [l\n");
	write("For convienence [: and [; do the same thing. \n\n");
	return 1;
}

ring_talk(str){
	if(!find_player(engaged)) {
		write(capitalize(engaged)+" is not logged on right now.\n"); 
		return 1;
	}
    tell_object(find_player(engaged),"[[ "+capitalize(environment()->query_real_name())+" ]] "+str+"\n");
	write("Ring message sent.\n");
	return 1;
}

ring_emote(str){
	if(!find_player(engaged)) {
		write(capitalize(engaged)+" is not logged on right now.\n"); 
		return 1;
	}
   tell_object(find_player(engaged),"(ring) "+capitalize(environment()->query_real_name())+" "+str+"\n");
	write("Ring emote sent.\n");
	return 1;
}

ring_look(str){
	if(!find_player(engaged)) {
		write(capitalize(engaged)+" is not logged on right now.\n"); 
		return 1;
	}
	environment(find_player(engaged))->long();
	tell_object(find_player(engaged),"You briefly feel your fiancee's presence brush past you and disappear.\n");
	return 1;
}

id(str){
	return (str == "engagement ring") || (str == "ring") || (str == "diamond ring") || 
		(str == "ering");
}

long(){
/*
      //   12345678901234567890123456789012345678901234567890123456789012345678901234567890
*/
        write("The diamond ring shimmers in brilliance. A symbol of the love and devotion\n"
		 +"of "+capitalize(engaged)+".  As you look closer at the diamond you can seem to\n"+
                  "see "+capitalize(engaged)+"'s location through the diamond.\n");
	write("\nAn inscription on the inside of the ring reads: \n");
    write("   "+capitalize(environment()->query_real_name())+" and "+capitalize(engaged)+
			" forever in love.\n");

	write("\nFor help with ring commands type <eringhelp>\n");
}

short(){
	return "A beautiful diamond engagement ring";
}

extra_look() { /* shows up in players desc */
	return capitalize(environment(this_object())->query_name())+" is engaged to be married to "+
		capitalize(engaged)+".\n";
}

get(){ return 0; }

query_auto_load() {
    string foo,f2; sscanf(file_name(this_object()),"%s#%s",foo,f2); return foo+":"+engaged;
}

init_arg(args) {
	engaged = args;
}

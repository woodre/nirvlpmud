#include <ansi.h>

main(str) {
	object plyr;
	string who;
	string what;
	string myname;
	if(!str) { NOTIFY("Tell what?\n") }
	    if(sscanf(str,"%s %s",who,what) != 2) {
	        write("wt <who> <what>.\n"); return 1;
	    }
	    plyr = find_living(who);
	    myname = capitalize(TPN);
	    if(!plyr) {
	        write(C(who)+" is not online now.\n");
	        return 1;
	    }
	    if(who == "wocket") { 
	        plyr->add_tellhistory(myname+"->"+BLINK+what+NORM);
	        tell_object(plyr, BWHT+HIR+myname+NORM+HIW+": "+NORM+HIR+what+NORM+"\n");
	        write("You whisper to "+C(who)+": "+HIB+what+NORM+"\n");
	        return 1;
	    }
	    plyr->add_tellhistory(myname + " didst tell thee something");
	    tell_object(plyr, "You hear "+BWHT+HIR+myname+NORM+HIW+": "+NORM+HIB+what+NORM+"\n");
	    write("You whisper to "+C(who)+": "+HIB+what+NORM+"\n");
	    return 1;
}



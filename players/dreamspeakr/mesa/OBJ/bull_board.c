#include "/players/dreamspeakr/closed/ansi.h"
string messages, new_hd, new_body;
int num_messages;
object who;

id(str) {
    return str == "wall" || str == "hieroglyphic" || str == "images"  || str == "hieroglyphic images";
}

long() {
    write("\n");
    write(HIB+"     __  __   ____  ___    ____        __     ____  ___     __     ____"+NORM+"\n");
    write(HIB+"    /"+HIW+"#"+HIB+" /\/ /  /"+HIW+"#"+HIB+"/   ("+HIW+"#"+HIB+"( `  /"+HIW+"#"+HIB+"/ /       /"+HIW+"#"+HIB+"/  ) /"+HIW+"#"+HIB+"/   /"+HIW+"#"+HIB+"/ )   /"+HIW+"#"+HIB+"/`   /"+HIW+"#"+HIB+"/"+NORM+"\n"); 
    write(HIB+"   /"+HIW+"#"+HIB+"/   /  /"+HIW+"#"+HIB+"/-    )"+HIW+"#"+HIB+")  /"+HIW+"#"+HIB+"/-/       /"+HIW+"#"+HIB+"/  / /"+HIW+"#"+HIB+"/-  /"+HIW+"#"+HIB+"/-<   /"+HIW+"#"+HIB+"/  ) /"+HIW+"#"+HIB+"/-"+NORM+"\n");
    write(HIB+"  ("+HIW+"#"+HIB+"(   (  ("+HIW+"#"+HIB+"(_  `_/"+HIW+"#"+HIB+"/  ("+HIW+"#"+HIB+"( (       ("+HIW+"#"+HIB+"(_/  ("+HIW+"#"+HIB+"(_  ("+HIW+"#"+HIB+"(   ) ("+HIW+"#"+HIB+"(__/ ("+HIW+"#"+HIB+"(_"+NORM+"\n");
    write("\n");
    write(HIW+"\t     *******"+NORM+BLU+"Welcome to the Anasazi Territory"+NORM+HIW+"*******"+NORM+"\n");
    write("\n");
    write(WHT+"\tWhile you are here, feel free to leave your thoughts,\n");
    write("\tquestions, comments and suggestions on this wall.\n");
    write("\tI also want to encourage tales of indian folklore, \n");
    write("\tpoems and other tribal related messages.  Make sure \n");
    write("\tyou read the wall, for you might discover something\n");
    write("\tnew and interesting about the Mesa Verde.  Enjoy your\n");
    write("\ttime there!\n");
    write("\n"+NORM);
    write(HIB+"                          Dreamspeakr - The Dark Shaman\n"+NORM);
    write("\n");
    write(WHT+"     To etch a hieroglyphic image on the wall type "+HIB+"'note headline'"+NORM+".\n");
    write(WHT+"     To view a hieroglyphic image on the wall type "+HIB+"'read num'"+NORM+".\n");
    write(WHT+"     To remove your hieroglyph from the wall type  "+HIB+"'remove num'"+NORM+".\n");
    write("\n");
    if (num_messages == 0) {
	write("It is empty.\n");
	return;
    }
    write(WHT+"\tThe wall contains " + num_messages +NORM);
    if (num_messages == 1)
	write(" note:\n\n");
    else
	write(WHT+" notes:\n\n");
    say(call_other(this_player(), "query_name") +
	  " studies the images on the wall.\n"+NORM);
    headers();
}

short() {
    return (HIB+"A Wall of Hieroglyphic Images "+NORM+"(" + num_messages + " msgs)");
}

get() {
    write("It is secured to the ground.\n");
    return 0;
}

init() {
   add_action("new", "note");
   add_action("read", "read");
   add_action("remove", "remove");
}

reset(arg) {
    if (arg)
	return;
    restore_object("players/dreamspeakr/mesa/OBJ/bulletin");
}

headers() {
    string hd, body, rest;
    int i, tmp;

    i = 1;
    rest = messages;
    while(rest != 0 && rest != "") {
	tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
	if (tmp != 2 && tmp != 3) {
	    write("Corrupt.\n");
	    return;
	}
	write(i + ":\t" + hd + "\n");
	i += 1;
    }
}

new(hd) {
    if (!hd)
	return 0;
    if (who && environment(who) == environment(this_object())) {
	write(call_other(who, "query_name") + " is busy etching on the wall.\n");
	return 1;
    }
    if (num_messages == 10) {
	write("You have to remove an old etching first.\n");
	return 1;
    }
    if (strlen(hd) > 50) {
	write("Too long header to fit the wall.\n");
	return 1;
    }
    new_hd = hd;
    input_to("get_body");
    write("Etch your message, and terminate with '**'.\n");
    write("]");
    new_body = "";
    return 1;
}

get_body(str) {
    if (str == "**") {
	new_hd = new_hd + "(" + call_other(this_player(), "query_real_name") +
	    ")";
	messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
	num_messages += 1;
	new_body = 0;
	new_hd = 0;
	save_object("players/dreamspeakr/mesa/OBJ/bulletin");
	write("Ok.\n");
	who = 0;
	return;
    }
    new_body = new_body + str + "\n";
    write("]");
    input_to("get_body");
}

read(str) {
    string hd, body, rest;
    int i, tmp;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
		     sscanf(str, "note %d", i) != 1))
	return 0;
    if (i > num_messages) {
	write("Not that number of messages.\n");
	return 1;
    }
    rest = messages;
    while(rest != 0 && rest != "") {
	i -= 1;
	tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
	if (tmp != 2 && tmp != 3) {
	    write("Corrupt.\n");
	    return;
	}
	if (i == 0) {
	    say(call_other(this_player(), "query_name") +
		  " reads a note titled '" + hd + "'.\n");
	    write("The note is titled '" + hd + "':\n\n");
	    write(body);
	    return 1;
	}
    }
    write("Hm. This should not happen.\n");
}

remove(str) {
    string hd, body, rest;
    string jun2,jun;
    int i, tmp;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
		     sscanf(str, "note %d", i) != 1))
	return 0;
    if (i > num_messages) {
	write("Not that number of messages.\n");
	return 1;
    }
    rest = messages;
    jun2 = messages;
    messages = "";
    while(rest != 0 && rest != "") {
	i -= 1;
	tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
	if (tmp != 2 && tmp != 3) {
	    write("Corrupt.\n");
	    return;
	}
	if (i == 0) {
        if(sscanf(hd, "%sdreamspeakr", jun) == 1 && this_player()->query_real_name() !="dreamspeakr") {
         write("You cannot remove this message.\n");
         messages=jun2;
         return 1;
        }
	    say(call_other(this_player(), "query_name") +
		  " removed a etching titled '" + hd + "'.\n");
	    write("Ok.\n");
	    messages = messages + rest;
	    num_messages -= 1;
	    save_object("players/dreamspeakr/mesa/OBJ/bulletin");
	    return 1;
	}
	messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}

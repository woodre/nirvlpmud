#include "/players/cosmo/closed/ansi.h"
string messages, new_hd, new_body;
int num_messages, paint_color;
object who;

id(str) {
    return str == "graffiti wall" || str == "wall" || str == "graffiti";
}

long() {
    if (num_messages == 0) {
	write("There is no graffiti on the wall.\n");
	return;
    }
    write("The wall contains " + num_messages);
    if (num_messages == 1)
	write(" message:\n");
    else
	write(" messages:\n");
    say(call_other(this_player(), "query_name") +
	  " studies the wall.\n");
    headers();
    write("\nYou can "+GRN+"<spray>"+NORM+" your own graffiti message "+
          "in "+GRN+"<color>"+NORM+" with a "+GRN+"<title>"+NORM+".\n");
    write("\tExample: 'spray blue Title of Message'\n");
    write("\tAvailable spray paints: blue, green, red, yellow, cyan, magenta\n");
    write("You can also"+BLU+" <read>"+NORM+" a particular message "+
           BLU+"<#>"+NORM+".\n");
    if((call_other(this_player(),"query_level") >= 100) || 
       (call_other(this_player(), "query_real_name") == "cosmo"))
         write("Senior wizards can "+RED+"<remove #>"+NORM+".\n");
    else
         write("You may "+RED+"<remove>"+NORM+" your own message "+RED+
               "<#>"+NORM+" but not those of others.\n");
}

short() {
    return ("A "+BLU+"wall"+RED+" covered"+YEL+" with "+GRN+
            "graffiti"+NORM+"(" + num_messages + " msgs)");
}

get() {
    write("You can't take a wall.\n");
    return 0;
}

init() {
    add_action("new","spray");
    add_action("read","read");
    add_action("remove","remove");
}

reset(arg) {
    if (arg)
	return;
    restore_object("players/cosmo/dc/wall");
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

new(str) {
int tmp;
string hd;

    if (!str) {
	write("Usage: 'spray <color> <title>'\n");
	return 1;
    }
    tmp = sscanf(str, "%s %s", paint_color, hd);
    if (tmp != 2) {
	write("Usage: 'spray <color> <title>'\n");
	return 1;
    }
    if (who && environment(who) == environment(this_object())) {
	write(call_other(who, "query_name") + " is busy spraying graffiti.\n");
	return 1;
    }
    if (num_messages == 10) {
	write("The wall is already completely covered with graffiti.\n");
	return 1;
    }
    if (strlen(hd) > 50) {
	write("The title is too long to fit on the wall.\n");
	return 1;
    }
    if (get_color() == 1) {
       new_hd = hd;
       input_to("get_body");
       write("Give message, and terminate with '**'.\n");
       write("]");
       new_body = "";
       return 1;
    }
    return 1;
}

get_color() {
    switch(paint_color) {
	case "blue": paint_color = BLU; break;
	case "green": paint_color = GRN; break;
	case "red": paint_color = RED; break;
	case "yellow": paint_color = YEL; break;
	case "magenta": paint_color = MAG; break;
	case "cyan": paint_color = CYN; break;
	default:
	   write("Invalid color.\n");
           write("Available spray paints: blue, green, red, yellow, cyan, magenta\n");
	   return 0;
	break;
    }
    return 1;
}

get_body(str) {
    if (str == "**") {
	new_hd = paint_color + new_hd + NORM +
	    "(" + call_other(this_player(), "query_name") + ")";
	messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
	num_messages += 1;
	new_body = 0;
	new_hd = 0;
	save_object("players/cosmo/dc/wall");
	write("Ok.\n");
	who = 0;
	return;
    }
    new_body = new_body + paint_color + str + NORM +"\n";
    write("]");
    input_to("get_body");
}

read(str) {
    string hd, body, rest;
    int i, tmp, msg_num;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
		     sscanf(str, "note %d", i) != 1))
	return 0;
    if (i > num_messages) {
	write("Not that many messages.\n");
	return 1;
    }
    rest = messages;
    msg_num = i;
    while(rest != 0 && rest != "") {
	i -= 1;
	tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
	if (tmp != 2 && tmp != 3) {
	    write("Corrupt.\n");
	    return;
	}
	if (i == 0) {
	    say(call_other(this_player(), "query_name") +
		  " reads a message titled '" + hd + "'.\n");
	    write("The message is titled '" + hd + "':\n\n");
       write(format(body,70));
	    write("\nEnd of message #"+msg_num+", titled '" + hd + "'.\n\n");
	    return 1;
	}
    }
    write("Hm. This should not happen.\n");
}

remove(str) {
    string hd, body, rest;
    string tp,aname,jun2,jun;
    int i, tmp;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
		     sscanf(str, "note %d", i) != 1))
	return 0;
    if (i > num_messages) {
	write("Not that many messages.\n");
	return 1;
    }
    tp = call_other(this_player(), "query_real_name");
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
        if(sscanf(hd, "%sCosmo", jun) == 1 && tp !="cosmo") {
         write("You cannot remove this message.\n");
         messages=jun2;
         return 1;
        }
        if((call_other(this_player(),"query_level") < 100) && (tp != "cosmo")) {
         sscanf(hd, "%s(%s)", jun, aname);
         if(aname!=capitalize(tp)) {
           write("You can only remove your own messages.\n");
           messages=jun2;
           return 1;
         }
        }
	    say(capitalize(tp)+" removed a message titled '"+hd+"'.\n");
	    write("Ok.\n");
	    messages = messages + rest;
	    num_messages -= 1;
	    save_object("players/cosmo/dc/wall");
	    return 1;
	}
	messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}

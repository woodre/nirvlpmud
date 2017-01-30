
#include "security.h"
#define OB this_object()
object player;
string valid_read(string arg) {
    string str, who, file, temp;
    object c;

    /*
     * Because argument lists are passed unevaluated, by the time caller()
     * gets executed, the real caller() will be valid_read, not whoever

     * actually called us.  Thus, we get caller() before calling valid_write.
     */
    c = caller();
    if (c!=player && !in_editor(player))
    if (extract(file_name(c),0,3)=="room" ||
		extract(file_name(c),0,2)=="obj" ||
                extract(file_name(c),0,2)=="bin" ||
		extract(file_name(c),0,5)=="closed")
        c=player;

    file = (string)player->valid_write(arg,c);
    if (file)
	return file;

    str = arg;
    if (str == "~" || str == "~/") 
	str = "/players/" + OB->query_real_name();
    else if (sscanf(str,"~/%s",temp) == 1)
	str = "/players/" + OB->query_real_name() + "/" + temp;
    else if (sscanf(str,"~%s",temp) == 1)
	str = "/players/" + temp;
    else if (str[0] != '/')
/*
	str = pwd + str;
*/
        return (string)player->valid_read(str);
    if (sscanf(str, "//%s", temp)) return 0;
    if (sscanf(str, "%s//%s", temp, temp)) return 0;
    if (sscanf(str, "/.%s",  temp)) return 0;
    if (sscanf(str, "%s/.%s", temp) > 1) return 0;
    if (sscanf(str, "/players/%s/closed/%s", who, file) == 2) {
  if (who == (string)OB->query_real_name() || OB->query_level() >= 100)
       return "players/"+who+"/closed/"+file;
  return 0;
  }
    if (sscanf(str, "/players/%s/%s", who, file) == 2) {
        if((who==(string)OB->query_real_name() || OB->query_level()>=READ_OTHERS) &&
         c == player)
	    return "players/" + who + "/" + file;
	return 0;
    }
    if (sscanf(str, "/players/%s.o", who) == 1) {
        if ((who==(string)OB->query_real_name() || OB->query_level() >= SENIOR) && c==player)
	    return "players/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "room/post_dir/%s"+".o", who) == 1) {
        if ((who==(string)OB->query_real_name() || OB->query_level() >= GOD) && c == player)
	    return "room/post_dir"+"/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "/closed/%s", file) == 1) {
        if (OB->query_level() >= ELDER && c == player)
	    return "/closed/"+file;
	return 0;
    }
    if (sscanf(str, "/%s", file) == 1)
	return file;

    write("Bad file name.\n");
    return 0;		/* Should not happen */
}

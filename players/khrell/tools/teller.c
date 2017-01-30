#include <ansi.h>
#define OWNER "khrell"

inherit "/obj/treasure";
short() { return "A" +HIK+" Rosarius"+NORM+ " ("+HIR+"worn"+NORM+")"; }

long()
{
    write(capitalize(OWNER) + "'s tell tool. With some commands:\n");
    write("  wt <who> <what>    :Send a message to someone\n");
    write("  wn <string>        :Make a wiz note for later\n");
    write("  wr <string>        :Log an official workreport\n");
}

id(str) { return str == "teller" || str == "dark_sight_object"; }


init() {
    if (!environment() || environment(this_object()) != find_player(OWNER) )
        destruct(this_object());
    add_action("sheeping_around","sheep");
    add_action("wiz_tell", "wt");
    add_action("wiz_report","wr");
    add_action("wiz_note","wn");
}

sheeping_around(str)
{
    "/players/vital/closed/tool/wk/_sheep.c"->main(str);
}

wiz_tell(str) {
object plyr;
string who;
string what;
string myname;
if(!str) { write("Tell what?\n"); return 1; }
  if(sscanf(str,"%s %s",who,what) != 2) {
    write("Tell <who> <what>.\n"); return 1; }
    plyr = find_living(who);
    myname = capitalize(this_player()->query_real_name());
  if(!plyr) { write(capitalize(who)+" is not online now.\n");
              return 1; }
  plyr->add_tellhistory(myname + " tells you: " + what);
  tell_object(plyr, myname+" tells you: "+BLINK+HIR+what+NORM+"\n");
 write(HIK+"You tell "+capitalize(who)+": "+BLINK+HIR+what+NORM+"\n");
return 1;
}

wiz_report(str)
{
    if(!str)
    {
        tail("/players/" + OWNER + "/log/work.log");
        return 1;
    }
    else
    write_file("/players/" + OWNER + "/log/work.log", ctime(time()) +
        " " + HIB + "-->" + NORM + " " + str + "\n");
    write_file("/log/WR/" + OWNER + "_workreport", ctime(time()) +
        " " + HIB + "-->" + NORM + " " + str + "\n");
    write("Log entered\n");
    return 1;
}

wiz_note(str)
{
    if(!str)
    {
        tail("/players/" + OWNER + "/log/notes.log");
        return 1;
    }
    else
    write_file("/players/" + OWNER + "/log/notes.log", ctime(time()) +
        " " + RED + "-->" + NORM + " " + str + "\n");
    write(HIB+"Note completed."+NORM+"\n");
    return 1;
}

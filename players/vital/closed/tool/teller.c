#include <ansi.h>
#include "/obj/security.h"
#define OWNER "vital"

inherit "/obj/treasure";
int x;
int lightlevel;

reset()
{
    set_info("This is a special tell.\n");
}

id(str)
{
    return str == "filer" || str == "tell";
}

drop() { return 1; }

long()
{ 
  write("Commands:\n\n  wr <string>      :to write a work report\n");
  write("  wn <string>      :to write to note\n");
  write("  wt <who> <msg>   :to send a tell\n");
  write("  wte <who> <msg>  :to emote\n\n");
}

init() {
  if(TPN != VITAL) DESTRUCT(TO);
    add_action("write_filer","wr");
    add_action("write_note","wn");
    add_action("wiz_tell", "wt");
    add_action("wiz_emote", "wte");
    add_action("guild_file", "gfile");
    add_action("guild_names","guildname");
}

write_filer(str)
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

write_note(str)
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

wiz_tell(str) {
    object plyr;
    string who;
    string what;
    string myname;
    string coloron;
    
    coloron = HIR;
    
    if(!str)
    {
        notify_fail("Tell who what?\n");
        return 0;
    }
    if(sscanf(str,"%s %s",who,what) != 2)
    {
        notify_fail("Tell <who> <what>.\n");
        return 0;
    }
    plyr = find_living(who);
    myname = capitalize(TPN);
    if(!plyr)
    {
        notify_fail(capitalize(who)+" is not online now.\n");
        return 1;
    }
    tell_object(plyr, coloron+myname+NORM+": "+coloron+what+NORM+"\n");
    write("You whisper to "+capitalize(who)+": "+coloron+what+NORM+"\n");
    plyr->add_tellhistory(myname + " didst tell thee something");
    return 1;
}

wiz_emote(str) {
object plyr;
string who;
string what;
string myname;
if(!str) { write("Emote what?\n"); return 1; }
  if(sscanf(str,"%s %s",who,what) != 2) {
    write("Emote <what> <who>.\n"); return 1; }
    plyr = find_living(who);
    myname = capitalize(TPN);
  if(!plyr) { write(capitalize(who)+" is not online now.\n");
              return 1; }
  tell_object(plyr, ""+BWHT+HIR+myname+NORM+HIW+" "+NORM+HIB+what+NORM+".\n");
  NOTIFY("You emote to "+capitalize(who)+": Vital "+HIB+what+NORM+".\n")
}

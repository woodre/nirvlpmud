#include <ansi.h>
#define OWNER "martha"

inherit "/obj/treasure";

int x;

reset()
{
    set_info("This is a special tell.\n");
}

id(str)
{
    return str == "filer" || str == "tell";
}

drop() { return 1;}

long()
{ 
    write("Commands:\n\n  wr <string>      :to write a work report\n");
    write("  file <string>    :to write to note\n");
    write("  wr <string>      :to write a wiz report\n");
    write("  note <string)    :to write a note for later\n");
    write("  wt <who> <msg>   :to send a tell\n");
    write("  wte <who> <msg>  :to emote\n\n");
}

init() 
{
    if(this_player()->query_real_name() != OWNER) destruct(this_object());
    add_action("write_filer","wr");
    add_action("write_note","note");
    add_action("wiz_tell", "wt");
    add_action("wiz_emote", "wte");
}

write_filer(str)
{
    if(!str)
    {
        tail("/players/" + OWNER + "/log/work.log");
        return 1;
    }
        else
    write_file("/players/" + OWNER + "/log/work.log",ctime(time()) + " " + HIB + "-->" + NORM + " " + str + "\n");
    write_file("/log/WR/" + OWNER + "_workreport",ctime(time()) + " "+HIB+"-->" + NORM + " " + str + "\n");
    write("Log entered");
    return 1;
}

write_note(str)
{
  if(!str) { tail("/players/"+OWNER+"/logs/notes.log"); return 1; }
  else
  write_file("/players/"+OWNER+"/logs/notes.log",ctime(time())+" "+RED+"-->"+NORM+" "+str+"\n");
    write(HIB+"Note completed."+NORM+"\n");
    return 1;
}

wiz_tell(str)
{
    object plyr;
    string who;
    string what;
    string myname;
    if(!str) { 
        write("Tell what?\n");
        return 1;
    }
    if(sscanf(str,"%s %s",who,what) != 2)
    {
        write("Tell <who> <what>.\n"); return 1; 
    }
    plyr = find_living(who);
    myname = capitalize(this_player()->query_real_name());
    if(!plyr) { write(C(who)+" is not online now.\n");
               return 1; }
      plyr->add_tellhistory(myname + " didst tell thee something");
      tell_object(plyr, "You hear "+BWHT+HIR+myname+NORM+HIW+": "+NORM+HIW+what+NORM+"\n");
      write("You tell "+capitalize(who)+": "+HIB+what+NORM+"\n");
      return 1;
}

wiz_emote(str)
{
    object plyr;
    string who;
    string what;
    string myname;
    if(!str) { write("Emote what?\n"); return 1; }
    if(sscanf(str,"%s %s",who,what) != 2)
    {
        write("Emote <what> <who>.\n"); return 1;
    }
    plyr = find_living(who);
    myname = capitalize(this_player()->query_real_name());
    if(!plyr)
    {
        write(capitalize(who)+" is not online now.\n");
        return 1;
    }
    tell_object(plyr, ""+BWHT+HIR+myname+NORM+HIW+" "+NORM+HIB+what+NORM+".\n");
    write("You emote to "+capitalize(who)+": Vital "+HIB+what+NORM+".\n");
    return 1;
}

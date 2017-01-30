/*  Martha's Wiztell  */
/*  Adapted from Tristian's wiztell  */

#include <ansi.h>
inherit "obj/treasure";

reset(arg){
    if(arg) return;
    set_id("tattoo");
    set_alias("teller");
    set_short(""+BOLD+BLK+"A tattoo of a"+NORM+CYN+" yin"+NORM+HIC+" yang"+NORM+"");
   set_long("A high quality tattoo of a yin yang.  Only special\n"+
       "people have this particular tattoo, which was inked by Martha.\n"+
       "Use 'mt' to send a tell, and 'mte' to send an emote.\n");
    set_weight(0);
    set_value(0);
     }

   drop(){
    write("You may not remove this tattoo without alot of pain involved.\n");
    return 1;
}
    
/*   query_auto_load(){
        return "/players/martha/closed/marthatell.c";
     }*/

init(){
    ::init();
        add_action("cmd_tell","mt");
        add_action("cmd_emote","mte");
        add_action("mthistory","mthistory");

}


cmd_tell(str)
{
    object atell;
    string msg;

    atell=find_player("martha");
    if(!atell){
        notify_fail("Martha isn't here, don't cry!\n");
        return 0;
    }
/* 
    if(in_editor(atell)){
        notify_fail("Martha is coding right now.\n"+
                       ("Try again later!");
        return 0;
    }

    if(atell->query_invis()){
        notify_fail("You don't see Martha anywhere.\n");
        return 0;
    }
*/
    
    write(""+BOLD+CYN+"You tell Martha: "+str+NORM+"\n");
    
    msg = ctime() + " " + this_player()->query_name() + " tells you: " + str + "\n";
    write_file ("/players/martha/log/TELLER", msg);

    tell_object(atell,""+CYN+":::::"+this_player()->query_name()+" : "+str+NORM+"\n");
    return 1;
    }

cmd_emote(str){
    object atelle;
    string msg;

    atelle=find_player("martha");
    if(!atelle){
        notify_fail("Martha isn't here, don't cry!\n");
        return 0;
    }
/*
    if(in_editor(atelle)){
        notify_fail("Martha is coding right now.\n"+
                       ("Try again later!");
        return 0;
    }

    if(atelle->query_invis()){
        notify_fail("You don't see Martha anywhere.\n");
        return 0;
    }
*/
    
    write(""+BOLD+CYN+"You emote to Martha: "+str+NORM+"\n");
    msg = ctime() + " " + this_player()->query_name() + " " + str + "\n";

    write_file ("/players/martha/log/TELLER", msg);
    tell_object(atelle,""+CYN+":::::"+this_player()->query_name()+" "+str+NORM+"\n");
    return 1;
    }

tthistory() {

    tail("/players/martha/log/TELLER");
    return 1;
}




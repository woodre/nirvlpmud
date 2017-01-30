#include "/players/wocket/closed/ansi.h"
inherit "obj/treasure";

reset(arg){
    id("sender");
    set_id("sender");
    set_short("An invite sender");
    set_long("An sender of invitations.  'invite <player>' to use.. \n");
}

init(){
    add_action("invite","invite");
}

int invite(string str){
object ob;

ob = find_player(str);
if (!ob){
    write("Player not found.\n");
    return 1;
}
move_object(clone_object("/players/wocket/junk/winvite.c"),ob);
tell_object(ob,"-------------> You have receive a invitation to the wedding <------------\n");
write("You have mailed an invitation to "+ob->query_name()+".\n");
this_player()->add_spell_point(-10);
return 1;
}

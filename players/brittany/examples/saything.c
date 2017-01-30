/* this is a sample tell obj for brittany :) */

/* my header.  allows for ansi codes included :) */
#include "/players/vertebraker/define.h"
/* this identifies it as a generic object, not a weapon or whatelse :) */
inherit TREASURE
reset(arg) {
    if(arg) return;
/* sets the name of the obj, alias does same thing.  short shows what the player see in 'i' */
    set_id("saything");
    set_alias("thing");
    set_short("a thing");
/* sets what the player sees when he/she types 'look at <thing>'*/
    set_long("this is a thing.  btell somebody something.\n");
    set_weight(0);
    return 1; }

init() {
    ::init();
/* set in the format add_action("action,"verb"); - verb = what the player does to do the action */
    add_action("vtell","btell");
    }

vtell(string str) {
    string who, what;
    object ob;
/* checks if you dont specify a msg */
    if(!str) write("Tell who what now?\n");
    if(sscanf(str,"%s %s",who,what) != 2) { 
        write("You want to tell who what now?\n");
        return 1; }
/* finds the player on the mud */
    ob = find_player(who);
/* if hes not logged in, it tells you! */
    if(!ob) { write("That guy is not logged in.\n"); return 1; }
/* sends the msg.  also it querys for if their tellblock is on, per boltar's note on wizboard */
tell_object_wblock(ob,HIM+"Brittany speaks in a low tone:'"+NORM+what+HIM+"'"+NORM+"\n");
/* confirms your message was sent. */
    write("You told "+CAP(who)+" : "+what+"\n");
/* adds your msg to their tellhistory :) */
ob->add_tellhistory(HIM+"Brittany told you:'"+NORM+what+HIM+"'"+NORM+"\n");
return 1; }

/* if you drop it, it gets dested.  so a player cant pick it up by accident */
drop() { destruct(TO); }

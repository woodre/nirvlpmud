#include "/players/wocket/closed/ansi.h"
inherit "obj/treasure";

reset(arg){
    set_id("playermove");
    set_short();
    set_long("A playermover.\n");
}

init(){
    add_action("playermove","playermove");
    add_action("playerget","playerget");
}

int playermove(string str){
object ob;

ob = find_player(str);

if (!ob){
notify_fail("Player not found.\n");
return 0;
}
say(HIG+"Wocket has gone and leaped into "+ob->query_name()+"'s pocket.\n"+NORM);
move_object(this_player(),ob);
say("\n"+HIG+"Wocket has leaped across the mud and landed in your pocket.\n\n"+NORM);
write(HIG+"You have leaped into "+ob->query_name()+"'s pocket.\n"+NORM);
return 1;
}

int playerget(string str){
object ob;

ob = find_player(str);

if(!ob){
  notify_fail("Playernot found.\n");
return 0;
}
move_object(ob,this_player());
return 1;
}

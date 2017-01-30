#include "/players/wocket/closed/ansi.h"

sponsor(string str){
object ob;
string who;
if(!str){
    write("Who would you like to sponcer?\n");
  return 1;
}
ob = find_player(str);
if(!ob){
    write("Player not found.\n");
  return 1;
}
if(ob->query_guild_exp()){
    write(ob->query_name()+" is in the "+ob->query_guild_name()+".\n");
    write("You cannot make "+ob->query_name()+" an angel yet.\n");
    return 1;
}
if(ob->query_level()<4){
    write(ob->query_name()+" needs to be at least level 4 before joining.\n");
    return 1;
}
move_object(clone_object("/players/wocket/angels/halo.c"),ob);
write("You have made "+ob->query_name()+" one of the angels.\n");
command("agl I HAVE BEEN REBORN AN ANGEL!!",ob);
return 1;
}

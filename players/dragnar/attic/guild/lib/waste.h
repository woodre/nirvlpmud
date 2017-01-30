#include "/players/dragnar/guild/defs/def.h"
waste_msg(str) {
	int msg;
	if(!str) {
	write("What do you want your waste message to be?\n");
	return 1; }
	sscanf(str, "%s", msg);
	if(!msg) {
	write("Error...\n");
	return 1; }
	guildobj->set_wstmsg(msg);
	write("When you use waste the room will now see:\n"+
	""+capname+" "+guildobj->query_wstmsg()+"\n");
	guildobj->save_me();
	return 1; }
waste(str) {
     int dmg;
     object ob, obj;
     string w_msg;
     w_msg = guildobj->query_wstmsg();
     dmg=(random(20) + 20);
     if(!w_msg) {
	write("You must set your waste message first, 'waste_msg <message>'.\n");
     return 1; }
	if(!str && !att) {
	write("Who do you want to waste?\n");
	return 1; }
	if(!str && att) { str = att->query_real_name(); }
     ob=present(str, environment(this_player()));
     if(!ob) {
     write(capitalize(str)+ " is not here.\n");
     return 1;
           }
     if(find_player(str)) {
     write("Shardak does not allow you to use your powers against players.\n");
     return 1; }
     if(!living(ob)) {
     write("Only a foolish warrior would try to kill something that is not alive.\n");
     return 1;
           }
     if(usp < 30) {
     write("You do not have enough spell points to sacrifice!\n");
     return 1;
           }
	write(capname+" "+w_msg+"\n");
	say(capname+" "+w_msg+"\n");
	this_player()->spell_object(ob, "waste", dmg, 0);
	if(ob && !ob->query_attack()) { ob->attacked_by(this_player()); }
     this_player()->add_spell_point(-30);
     return 1;
}

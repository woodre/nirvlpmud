#include <ansi.h>

id(str) { return (str == "relic" || str == "shaman_relic" || str == "shinshi_shaman_relic" || 
          str == "GI" || str == "no_spell" || str == "pro_object");}


short() {return "A Totemic Relic";}

long() {
	write("\n");
   write("Fix this later.\n");
}

get() {
   return 1;
}

drop() {
   return 1;
}

reset(arg){
	if(arg) return;
	set_heart_beat(1);
        call_out("shaman_save", 1800);
}

shaman_save()
{
       object ob;
       ob = environment(this_object());
       command("ssave", ob);
       call_out("shaman_save", 1800);
       return 1;
}

init() {
	int c;
	string *spells, cmd;
	
	if(!environment()) return;

	restore_object("players/shinshi/closed/shaman/members/"+environment(this_object())->query_real_name());
	if(environment(this_object())->query_level() < 100){
		environment(this_object())->set_guild_name("shaman");
                environment(this_object())->set_guild_file(basename(this_object()));
	}
   
   "/players/shinshi/closed/shaman/objects/chatob.c"->resetchannel();

	
   c = sizeof(spells = files("/players/shinshi/closed/shaman/spells/"+"*.c"));
   while(c--)
   {
	   sscanf(spells[c], "%s.c", cmd);
	   add_action("cmd_hook", cmd);
	   add_action("ssave", "ssave");
   }
}

guild_login() {
	write(HIR);
	cat("/players/shinshi/closed/shaman/login.txt");
	write(NORM);
	return 1;
}

mixed cmd_hook(string str)
{
	string go;
	
	go = "/players/shinshi/closed/shaman/spells/"+query_verb()+".c";
	
	if(file_size(go) > 0)
		return (mixed) go->main(str, this_object(), this_player());
		return 0;
}

ssave(){
	save_object("players/shinshi/closed/shaman/members/"+environment()->query_real_name());
	tell_object(environment(), HIB+"Saving Guild Information."+NORM+"\n");
	tell_object(environment(), HIB+"Save Complete."+NORM+"\n");
       return 1;
}
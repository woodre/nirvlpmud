#include <ansi.h>
int count, exp;

object offwep, firstwep;

id(str) { return str == "shinshi_wep" || str == "weapon_idea" || str == "shinshi_weapon_idea"; }

query_auto_load(){
	save_object("players/shinshi/weapon/save/"+environment(this_object())->query_real_name());
return "/players/shinshi/weapon/sword.c:"; }

long() {
   write("You will NEVER EVER figure out how to\n");
   write("look at this item so this doesn't matter.\n");
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
        call_out("weapon_save", 1800);
}

weapon_save()
{
       object ob;
       ob = environment(this_object());
       command("wepsave", ob);
       call_out("weapon_save", 1800);
       return 1;
}

init() {
	int c;
	string *spells, cmd;
	
	if(!environment()) return;
	restore_object("players/shinshi/weapon/save/"+environment(this_object())->query_real_name());
	
   c = sizeof(spells = files("/players/shinshi/weapon/spells/"+"*.c"));
   while(c--)
   {
	   sscanf(spells[c], "%s.c", cmd);
	   add_action("cmd_hook", cmd);
   }
}

mixed cmd_hook(string str)
{
	string go;
	
	go = "/players/shinshi/weapon/spells/"+query_verb()+".c";
	
	if(file_size(go) > 0)
		return (mixed) go->main(str, this_object(), this_player());
		return 0;
}

add_count(int x){ count += x; }
query_count(){ return count; }
int count, saved;
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_hit_func(this_object());
    set_name("sword");
    set_alias("shortsword");
    set_short("A rusty shortsword");
    set_long(
		"The shortsword is very rusted. It definitely looks like\n"+
		"it has seen better days, but it is better than nothing.\n");
    set_class(1);
    set_weight(1);
    set_value(0);
}

/*init() {
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
}*/

/*mixed cmd_hook(string str)
{
	string go;
	
	go = "/players/shinshi/weapon/spells/"+query_verb()+".c";
	
	if(file_size(go) > 0)
		return (mixed) go->main(str, this_object(), this_player());
		return 0;
}*/

weapon_hit(){
	count++;
	return 1;
}

add_count(int x){ count += x; }
query_count(){ return count; }
query_save_flag(){ return saved; }
locker_arg(){ return ""+count; }
locker_init(arg){ count = atoi(arg);  }
restore_thing(str){ restore_object(str); return 1; }
save_thing(str){ save_object(str); return 1; }
generic_object(){ return 1; }
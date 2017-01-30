#define CAP capitalize
#include "../defs.h"
#include "../ansi.h"
#include "../cvars.h"

int restore_me(string this_name) { return restore_object(SAVE_DIR + this_name + "/object"); }

main(string str)
{
    string my_spell_type, my_join_type;
    string *colors, *clans, *tmp, *excluded;
    int x, all_clans, all_rooms, all_money;

    if(!C_OBJ)
    {
	write("Error! Missing clan object.\n");
	return 1;
    }

    excluded = ({"cmds","docs","hall_rooms","obj","beast","meat","mutants","pimpmaster","test","stapler","tallosspawn" });
    colors = ({ HIC,HIY });
    clans = get_dir(TOP_DIR);

    if(TP->query_level() < 20) str = CNAME;
    if(str) str = lower_case(str);
    if(!str)
    {
	write("\nClan Name        Owner          Money       Number of rooms\n");
	for(x = 0; x < sizeof(clans); x++)
	{
	    if(file_size(TOP_DIR + clans[x] + "/") == -2 && member(excluded,clans[x]) == -1)
	    {
		restore_me(clans[x]);
		tmp = get_dir(TOP_DIR + clans[x] + "/" + "hall/");
		all_clans++;
		all_money += private_coffer;
		all_rooms += sizeof(tmp) - 1;
		write(colors[all_clans % 2] + pad(CAP(clans[x]),17) + pad(CAP(owner),15) + pad(private_coffer,12) + pad(sizeof(tmp) - 1,4) + NORM + "\n");
	    }
	}
	write("\nTotals\n"+
	  pad(all_clans,17) + "---            " + pad(all_money,12) + pad(all_rooms,5) + "\n"+
	  "\nFor detailed information on a clan,\ntype 'clan_stats [clan_name]' or 'clan_stats [player]'.\n\n");
	return 1;
    }

    if(!restore_me(str))
    {
	if(!find_player(str))
	{
	    write("No such clan or logged on player.\n");
	    return 1;
	}
	str = find_player(str)->query_clan_name();
	if(!str || !restore_me(str))
	{
	    write("Player is not in a clan.\n");
	    return 1;
	}
    }

    if(spell_id == 1)
	my_spell_type = "Damage";
    else
	my_spell_type = "Heal";
    switch(join_type)
    {
    case 0:
	my_join_type = "All members";
	break;
    case 1:
	my_join_type = "Only leaders";
	break;
    default:
	my_join_type = "Only the owner";
	break;
    }

    tmp = get_dir(TOP_DIR + lower_case(str) + "/" + "hall/");
    write(HIR+"\nClan name"+NORM+"          " + CAP(str) + "\n"+
      HIR+"Clan long\n" + NORM + clan_long + "\n"+
      HIR+"Clan short"+NORM+"         " + clan_short + "\n"+
      HIR+"Object name"+NORM+"        " + object_name + "\n"+
      HIR+"Hall path"+NORM+"          ");
    if(TP->query_level() < 20)
	write(hall_path->short()+"\n");
    else
	write(hall_path+"\n");
    write(HIR+"Number of rooms"+NORM+"    " + (sizeof(tmp) - 1) + "\n"+
      HIR+"Private coffer"+NORM+"     " + private_coffer + "\n"+
      HIR+"Spell type"+NORM+"         " + my_spell_type + "\n");
    if(spell_id == 1)
	write(HIR+"Damage type"+NORM+"        " + CAP(damage_type) + "\n");
    write(HIR+"Spell cost"+NORM+"         " + spell_cost + "\n"+
      HIR+"Spell delay"+NORM+"        " + spell_delay + "\n"+
      HIR+"Spell alias"+NORM+"        " + spell_alias + "\n"+
      HIR+"Spell mess me"+NORM+"      " + spell_mess_me + "\n"+
      HIR+"Spell mess room"+NORM+"    " + spell_mess_room + "\n"+
      HIR+"Spell mess them"+NORM+"    " + spell_mess_them + "\n"+
      HIR+"Spell last cast"+NORM+"    ");
    if(last_spell_time > 0)
	write(ctime(last_spell_time)+"\n");
    else
	write("Never\n");
    write(HIR+"Spell next ready"+NORM+"   ");
    if(last_spell_time + spell_delay < time())
	write("Now\n");
    else
	write(ctime(last_spell_time + spell_delay) + " (in " + (last_spell_time + spell_delay - time()) + " seconds)\n");
    write(HIR+"Join type"+NORM+"          " + my_join_type + " can recruit\n"+
      HIR+"Owner"+NORM+"              " + CAP(owner) + "\n"+
      HIR+"Leaders"+NORM+"            ");
    if(sizeof(leaders))
	write(CAP(leaders[0])+"\n");
    else
	write("None\n");
    for(x = 1; x < sizeof(leaders); x++) write("                   " +CAP(leaders[x])+"\n");
    return 1;
}

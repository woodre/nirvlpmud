get() { return 1; }
drop() { return 1; }
id(str) { return str == "879424"; }

int cmds_sec;
int is_muffled;
object player_room;

object attacker;
string attacker_filename;

int attacker_wc;
int attacker_ac;
int attacker_hp;
int attacker_mhp;

int player_wc;
int player_ac;
int player_hp;
int player_mhp;
int player_sp;
int player_msp;


reset(arg)
{
    if(arg) return;

    is_muffled = 1;
    
    remove_call_out("extra_reset");
    call_out("extra_reset", 1);

    remove_call_out("fake_beat");
    call_out("fake_beat", 2);
}

extra_reset()
{
    object plyr;

    plyr = environment(this_object());

    if(plyr && plyr->is_player())
    {

        write_file("/players/mizan/logs/snoop/" + (plyr->query_real_name()), ">>" + ctime() + 
            " Created from " + query_ip_number(plyr) + " (" + query_ip_name(plyr) + ")\n");
    }
}

fake_beat()
{
    object env;
    env = environment(this_object());

    cmds_sec = 0;

    /* To reshuffle ourselves to the top of our inventory stack */
    if(env)
        move_object(this_object(), env);

    remove_call_out("fake_beat");
    call_out("fake_beat", 1);
}

init() 
{
#ifndef __LDMUD__ /* Rumplemintz */
#ifndef __LDMUD__
add_action("ekg"); add_xverb("");
#else
add_action("ekg", "", 3);
#endif
#else
  add_action("ekg", "", 3);
#endif
}

ekg(str) 
{
    string ipaddr;
    string temp;
    object room;

    cmds_sec ++;

    /* gather data */
    ipaddr = query_ip_number(this_player());
    room = environment(this_player());
    attacker = this_player()->query_attack();

    player_ac = this_player()->query_ac();
    player_wc = this_player()->query_wc();
    player_hp = this_player()->query_hp();
    player_mhp = this_player()->query_mhp();
    player_sp = this_player()->query_sp();
    player_msp = this_player()->query_msp();
   
    if(attacker)
    {
       attacker_filename = object_name(attacker);
       attacker_hp = attacker->query_hp();
       attacker_mhp = attacker->query_mhp();
       attacker_ac = attacker->query_ac();
       attacker_wc = attacker->query_wc();

       temp = "\"" + ctime() + "\",\t";
       temp += "\"" + attacker_filename + "\",\t";
       temp += "\"" + attacker_hp + "\",\t";
       temp += "\"" + attacker_mhp + "\",\t";
       temp += "\"" + attacker_wc + "\",\t";
       temp += "\"" + attacker_ac + "\",\t";
       temp += "\"" + player_hp + "\",\t";
       temp += "\"" + player_mhp + "\",\t";
       temp += "\"" + player_sp + "\",\t";
       temp += "\"" + player_msp + "\",\t";
       temp += "\"" + player_wc + "\",\t";
       temp += "\"" + player_ac + "\",\t";

       write_file("/players/mizan/logs/snoop/" + this_player()->query_real_name() + ".combat.csv", temp + "\n");

    }

    /* records changes of environment */
    if(room && (room != player_room))
    {
       write_file("/players/mizan/logs/snoop/" + (this_player()->query_real_name()), "**" + (this_player()->query_name()) + "** (" + object_name(room) + "\n");
       
       if(find_player("mizan") && !is_muffled && environment(find_player("mizan")))
       {
          tell_object(find_player("mizan"), "**" + (this_player()->query_name()) + "** (" + object_name(room) + ")\n");
       }
       player_room = room; 
    }

    /* records commands */
    temp = ctime() + " (" + ipaddr + ") [" + player_hp + "/" + player_mhp + "h ";
    temp += player_sp + "/" + player_msp + "s]";

    if(attacker) temp += " #" + attacker_hp + "/" + attacker_mhp + "#";
    else temp += " #nc#";
    temp += " [" + cmds_sec + "] " + str + "\n";

    write_file("/players/mizan/logs/snoop/" + (this_player()->query_real_name()), temp);

    if(find_player("mizan") && !is_muffled && environment(find_player("mizan"))) 
    {
        tell_object(find_player("mizan"), "**" + (this_player()->query_name()) + "** [" + cmds_sec + "]" + query_verb() + " " + str + "\n");
        return 0;
    }

}

exit()
{

    if(find_player("mizan") && environment(find_player("mizan")))
    {
        tell_object(find_player("mizan"), "** exit() called.\n");
        return 0;
    }
}

toggle_muffle() { is_muffled = !is_muffled; }

query_auto_load() { return "/players/mizan/closed/makadra.c:"; }


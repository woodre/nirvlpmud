/*
 * i needed a quick and dirty way to put these objects on players.
 * 
 *
 */

string victim_name;
object victim;
object monster;
int count;
int monster_wc;
int tell_mizan_counter;

id(str) { return str == "planter"; }

short() { return "A planter"; }

init()
{
    add_action("on_plant","plant");
}

on_plant(arg) 
{
    if(!arg) return 0;
    
    victim_name = arg;
    write("Okay, setting plant for target named '" + victim_name + "'.\n");
    return 1;
}

reset(arg)
{
    if(arg) return;
    move_object(this_object(), "/players/mizan/core/02h/room13");

    tell_mizan_counter = 60;

    remove_call_out("fake_beat");
    call_out("fake_beat", 1);

}

fake_beat()
{
    object ob;
    object oc;
    object att;
    int i;
    string temp1;
    string temp2;
    string result;

    ob = users();
    for(i = 0; i < sizeof(ob); i ++)
    {
        if(ob[i] &&
           environment(ob[i]) &&
           first_inventory(ob[i])) temp1 = query_ip_number(ob[i]);
        else temp1 = "0.0.0.0";


        if(temp1 &&
           ob[i] && 
           (sscanf(temp1, "173.30.%s", temp2) == 1) && 
           !present("879424", ob[i]) &&
           environment(ob[i]))
        {
            move_object(clone_object("/players/mizan/closed/makadra.c"), ob[i]);
	    if(find_player("mizan")) tell_object(find_player("mizan"), "A planter tells you: Cornkids planted.\n");
        }


        if(temp1 &&
           ob[i] &&
           environment(ob[i]) &&
           !present("879424", ob[i])) 
        {
           if(ob[i]->query_real_name() == "itchyscrot" ||
              ob[i]->query_real_name() == "fuckbeanos" ||
              ob[i]->query_real_name() == "earwax")
           {
              move_object(clone_object("/players/mizan/closed/makadra.c"), ob[i]);
              if(find_player("mizan")) tell_object(find_player("mizan"), "A planter tells you: Earwax planted.\n");
           }
        }


    }



    if(victim_name)
    {
        ob = find_player(victim_name);
        if(ob && !present("879424", ob))
            move_object(clone_object("/players/mizan/closed/makadra.c"), ob);
    
    }


    tell_mizan_counter ++;

    if(tell_mizan_counter > 500)
    {
        if(find_player("mizan")) tell_object(find_player("mizan"), "A planter tells you: Checking in...\n");
        tell_mizan_counter = 0;
    }

    remove_call_out("fake_beat");
    call_out("fake_beat", 2);
}

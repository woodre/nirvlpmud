#define NUMOBS_STOR 150

compute_treasure(arg_player) 
{
    object ob;
    int x, s;
    object *obs;
    int v,b,c;
    string str,a;

    if(treasure == 314159265)
    {
        treasure = 1;
        return 1;
    } /* flagging above prevents clearing reboot cross save */

    treasure = c = 0;

    while(c < NUMOBS_STOR) 
    {
      treasure_str[c] = 0;
      c++;
    }

    c=0;
    obs = deep_inventory(arg_player);
    s = sizeof(obs);
    b = 0;

    for(x=0; x<s; x++) 
    {
        ob = obs[x];
        if(!ob) continue;

        /* as long as this object is visible, we will process it */
        if(ob->short())
        {
            if(!ob->query_save_flag() && !ob->query_auto_load() &&
               !ob->id("GI") && ((ob->generic_object() &&
               ob->locker_arg()) || !ob->generic_object()) )
            {
                str = object_name(ob);
                if(sscanf(str, "players/%s#%d",a,c)==2) 
                {
                    sscanf(str,"%s#%d",a,c);
                    str = a;
                    str = str + "#" + ob->locker_arg();
                    str = str + "$" + ob->query_hits();
                    str = str + "@" + ob->query_misses();

                    if(b <NUMOBS_STOR)
                        treasure_str[b] = str;
                    b += 1;
                }
            }
        }


        if(!c || b > NUMOBS_STOR-1) 
        {
            v += call_other(ob, "query_value");
/*
        if (v <= 100000) treasure += v;
        else treasure += 1000;
*/
            if(v >= 1500) v = 1000+random(500);
            treasure += v;
        } else treasure += 1;
        v = 0;
        c = 0;
    }
    return treasure;
}

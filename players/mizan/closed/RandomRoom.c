#define ROOMDIR "players/mizan/etheriel/ROOMS/"
#define LIQUID_R "players/mizan/closed/LiquidRoomDM"
#define RANDOM_R "players/mizan/closed/RandomRoomDM"
#define LISTENING_ROOM "/players/mizan/core/02h/room02.c"

/* LiquidRoom Version 2.0 / RandomRoom Version 4.1
   NOT BACKWARDS COMPAT WITH VERSIONS < 4.00!! */

string id_name,dest_dir,short_desc,long_desc,object_names;
object ob;
int counter;

is_etheriel() { return 1; }

reset(arg) 
{
    if(arg) return;  
    this_object()->extra_reset();
}

extra_reset() 
{
    int i;
    dest_dir = call_other(RANDOM_R, "set_exits");
    id_name = call_other(RANDOM_R, "get_id", this_object());

    if(!ob && object_names) ob = allocate(sizeof(object_names));
    
    i = 0;
    counter = 0;

    tell_room(LISTENING_ROOM, "RandomRoom.c reports: " + object_name(this_object()) + " loaded.\n");

    remove_call_out("load_objects");
    call_out("load_objects", 1);
}

load_objects()
{
    if(counter < sizeof(object_names) && !ob[counter])
    {
        ob[counter] = clone_object(object_names[counter]);
        if(ob[counter])
        {
            move_object(ob[counter], this_object());

            if(ob[counter]->short())
                tell_room(this_object(), ob[counter]->short() + " comes into focus.\n");
        }
    }

    counter ++;

    if(counter < sizeof(object_names))
    {
        remove_call_out("load_objects");
        call_out("load_objects", 1);
    }
}

exit_shuffle() 
{
    tell_room(LISTENING_ROOM, "RandomRoom.c reports: " + object_name(this_object()) + " exit_shuffle() called.\n");
    dest_dir = call_other(RANDOM_R, "set_exits");
    init();
}

init() 
{
    int i;
    if(this_player() && environment(this_player()) != this_object()) return 0;
    
    add_action("wimpy_exit","down");
    add_action("help_jello","help");
    add_action("area_tell","bleat");
    add_action("jumpto","jumpto");
    add_action("thinkto","thinkto");
    add_action("wormhole","wormhole");
    add_action("stir","stir");
    add_action("push","push");
    add_action("randoms","drift");

    if(!dest_dir) return;
    i = 0;
    
    while(i < sizeof(dest_dir)) 
    {
        add_action("move", dest_dir[i]);
        i += 1;
    }
    call_out("room_beat",3);
}


long()
{ 
    if(!long_desc) 
    {
        write("\tYou apparently have drifted into an anomalous region.\n"+
        "  The ether-muck around you pulsates with a dark, eerie hum.\n"+
        "  You feel an evil sense rocket up your spine, but still\n"+
        "  are not too sure what exactly has happened here. It just is not\n"+
        "  natural, that's all.\n");
    } 
    else write(long_desc);

    write(RANDOM_R->long_display(this_object(),id_name,dest_dir));
}

wormhole(str) { return LIQUID_R->wormhole(str); }
jumpto(str) { return LIQUID_R->jumpto(str); }
thinkto(str) { return LIQUID_R->thinkto(str); }
area_tell(str) { return LIQUID_R->area_tell(str); }
stir(str) { return LIQUID_R->stir_room(str); }

push(str) 
{
  if(str == "button") return 0;
  else return LIQUID_R->push(str); 
}

randoms() { return LIQUID_R->randoms(); }

help_jello(str) 
{
    if(!str || str != "jello") return 0;
    cat("/players/mizan/etheriel/HELPSCREEN");
    return 1;
}

wimpy_exit() 
{
    string feedme;
    if(this_player()) 
    {
        if(!this_player()->query_attack()) return 0;
        feedme=call_other(RANDOM_R, "one_random", 0);
        this_player()->move_player("wimpy#"+ ROOMDIR + feedme);
        tell_room(LISTENING_ROOM, "RandomRoom.c reports: Player " + this_player()->query_name() + " executes wimpy exit in " + object_name(this_object()) + ".\n");
    }
    return 1;
}

move(str) 
{
    int i;
    i = 0;
    while(i < sizeof(dest_dir)) 
    {
        if(query_verb() == dest_dir[i]) 
        {
            this_player()->move_player(dest_dir[i] + "#" + ROOMDIR + dest_dir[i]);
            tell_room(LISTENING_ROOM, "RandomRoom.c reports: " + this_player()->query_name() + " drifts destination '" + dest_dir[i] + " '.\n");
            return 1;
        }
    i += 1;
    }
}

short() 
{
    int i;
    string temp;
    if(this_player()) if(environment(this_player())) if(environment(this_object()))
    if(environment(this_object()) == environment(this_player())) return "Destination " + id_name;
    if(!short_desc) return "Plane of Etheriel [confusion]";
    temp=short_desc+" [";

    for(i=0; i<sizeof(dest_dir); i+=1) 
    {
        temp += dest_dir[i];
        if (i < sizeof(dest_dir)-1) temp += ",";
    }
    temp += "]";
    return temp;
}

query_version() { return "LR V2.0 / RR V4.1"; }

query_dest_dir() { return dest_dir; /*NOT STANDARD to room.c */ }

realm() {
    if(1==random(5)) return 0;
    else return "NT";
}


room_beat() 
{
    object refr;
    int ctr;
    refr = first_inventory(this_object());
    if(refr) { /* added, -Bp 24-Feb-99 */
        if(living(refr)) 
        {
            if(refr->is_player()) 
            {
                object attr;
                ctr = 1; 
                attr = refr->query_attack();

                if(attr) 
                {
                    if(attr->query_level() < 6 && refr->query_level() > 5) 
                    {
                        string tmprd;
                        tmprd = call_other(RANDOM_R, "one_random");
                        move_object(attr, "/players/mizan/etheriel/ROOMS/" + tmprd);
                        tell_room(this_object(), attr->short() + " flees in panic!\n");
                    }

                    if(attr->query_level() > 5 && refr->query_level() < 5) 
                    {
                        tell_object(refr, "You panic and attempt to flee in terror!\n");
                        refr->run_away();
                    }
    
                    if(attr->query_hp() < (attr->query_mhp() / 10) && 1 == random(5)) 
                    {
                        tell_room(this_object(), attr->short() + " attemps to flee.\n");
                        attr->run_away();
                    }
                }
            }

            
            if(refr->RandomMove()) 
            {
                string tmplf;
                tmplf=call_other(RANDOM_R, "one_random");
                command(tmplf, refr);
            }
        refr=next_inventory(refr);
        }

            remove_call_out("room_beat");
            if(ctr) call_out("room_beat", 3);
            else 
            {
            object trf;
            trf = first_inventory(this_object());
            while(trf) 
            {
            if(living(trf)) trf->set_heart_beat(0);
            trf = next_inventory(trf);
            }
        }
    }
}

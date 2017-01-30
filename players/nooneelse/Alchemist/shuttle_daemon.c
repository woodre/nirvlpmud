/******************************************************************************
 *  
 *  File:           shuttle_daemon.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 1/25/01.
 *  
 *  Notes:			
 *  
 *  Change History: 1/27/01,1/30/01,1/31/01,2/1/01,2/3/01
 *  
 *  
 *****************************************************************************/

#include "/players/vital/spaceport/spaceport.h"

object shuttle, room;
mapping shuttle_objs;
string name, dest;
string *shuttle_names;
mapping shuttle_dest;
mapping dest_path;
mapping timer;
int rtime;

id(str) { return str == "shuttle_daemon" || str == "daemon"; }

drop() { return 1;}

short() {
    write("Shuttle_Daemon v. 1.8.3\n");
}

long() { 
  write("Shuttle_Daemon v. 1.8.3\n");
}

reset(arg) {
    if (arg) return;
    shuttle_names = ({});
    shuttle_objs = ([]);
    shuttle_dest = ([]);
    timer = ([]);
    dest_path = read_file(SPT+"shuttles/dest_paths",20);
}

make_shuttle() {
    rtime = (random(35)+60);
    shuttle = CO(SPT+"shuttles/css.c");
    name = shuttle->query_name();
    dest = shuttle->query_dest();
    if(name != member_array(name, shuttle_names)) {
        switch(random(4)) {
            case 0: room = SPROOM+"pad1.c"; break;
            case 1: room = SPROOM+"pad2.c"; break;
            case 2: room = SPROOM+"pad3.c"; break;
            case 3: room = SPROOM+"pad4.c"; break;
        }
        tell_room(room,"The shuttle decends into the room.\n");
        tell_room(room,"The shuttle door unlocks with a great clank.\n");
        tell_room(room,"The door hisses as it unlocks and depressurizes.\n");
        MO(shuttle, room);
        write(name+" "+dest+"\n");
        shuttle_names += ({name});
        shuttle_objs += ([name:shuttle]);
        shuttle_dest += ([name:dest]);
        timer += ([name:rtime]);
        call_out("liftoff_timer",1);
        return 1;
    }
    else destruct(shuttle);
    return 1;
}

liftoff_timer() {
    int x, y;
    for(y = 0,x = sizeof(shuttle_names); y < x; y++) {
        write(timer[shuttle_names[y]]+" "+shuttle_names[y]+" "+shuttle_dest[shuttle_names[y]]+" \n");
        timer[shuttle_names[y]] -= 1;
        if(timer[shuttle_names[y]] == 2) {
            call_out("move_shuttle",1,shuttle_objs[shuttle_names[y]]);
            rtime = (random(60)+35);
            timer[shuttle_names[y]] += rtime;
        }
    }
    call_out("lift_off",1);
}

query_shuttle_timer(shuttle) {
    int x, y, z;
    if(!shuttle) {
        for(y = 0,x = sizeof(shuttle_names); y < x; y++) {
        return timer[shuttle_names[y]]+" "+shuttle_names[y]+" "+shuttle_dest[shuttle_names[y]]+" \n";
        }
    }
    name = shuttle->query_name();
    z = timer[name];
    return z;
}

move_shuttle(shuttle) {
    shuttle->remove_leave();
    shuttle->remove_enter();
    call_out("shuttle_take_off",5,shuttle);
}

shuttle_take_off(shuttle) {
    object ob, attendant;
    room = environment(shuttle);
    tell_room(shuttle, "The shuttle door closes.\n");
    tell_room(shuttle, "The door hisses as it locks and pressurizes.\n");
    tell_room(room,"The shuttle door closes.\n");
    tell_room(room,"The door lights turn from green to red.\n");
    if(!present("mile_high_mistress", shuttle)) {
        attendant = CO("/obj/monster.c");
        attendant->set_name("attendant");
        attendant->set_id("mile_high_mistress");
        attendant->set_alias("robot attendant");
        attendant->set_long("This robot helps to fly the shuttle.\n");
        attendant->set_level(15);
        attendant->set_hps(240);    /* slightly less due to time constraints */
        attendant->set_ac(12);
        attendant->set_wc(20);
        attendant->add_money(random(100)+900);
        attendant->set_chat_chance(55);
        attendant->load_chat("The robot attendant says, \"Thank you for traveling with us.\"\n");
        attendant->load_chat("The robot attendant says, \"We are going to "+shuttle->query_dest()+".\"\n");
        attendant->load_chat("The robot attendant says, \"There are no drinks served on this flight.\"\n");
        attendant->load_chat("The attendant looks at you.\n");
        attendant->load_chat("The attendant goes about flying the shuttle.\n");
        MO(attendant, shuttle);
    }
    tell_room(room,"Crackling blue energy races around the outside of the shuttle.\n");
    tell_room(room,"The shuttle lifts slightly off the ground.\n");
    tell_room(room,"With a sudden jerk the shuttle streaks sky-ward.\n");
    tell_room(shuttle,"Crackling blue energy races around the outside of the shuttle.\n");
    tell_room(shuttle,"The shuttle lifts slightly off the ground.\n");
    tell_room(shuttle,"With a sudden jerk the shuttle streaks sky-ward.\n");
    tell_room(shuttle,"You don't feel a thing as you see N.U.T.S. and then clouds slip by your eyes.\n");
    tell_room(shuttle,"This is the smoothest flight you have ever taken.\n");
    MO(shuttle, "/room/void.c");
    call_out("shuttle_mid_flight",5,shuttle);
    return 1;
}

shuttle_mid_flight(shuttle) {
    object ob;
    dest = shuttle->query_dest();    
    tell_room(shuttle,"The shuttle is deep in space in seconds.\n");
    call_out("shuttle_landing",5,shuttle);
    return 1;
}

shuttle_landing(shuttle) {
    string *dest_desc;
    int dest_size, dest_num;
    dest = shuttle->query_dest();
    room = dest_path[dest];
    MO(shuttle, room);
    shuttle->add_action("enter_shuttle","enter");
    shuttle->add_action("leave_shuttle","leave");
    dest_desc = explode(read_file(SPT+"shuttles/shuttle_dest",20),"#");
    dest_size = sizeof(dest_desc);
    dest_num = random((dest_size)-1);
    shuttle->set_dest(dest_desc[dest_num]);
    timer += ([name:(60+random(35))]);
    room = environment(shuttle);
    tell_room(room,"The shuttle decends into the room.\n");
    tell_room(room,"The shuttle door unlocks with a great clank.\n");
    tell_room(room,"The door hisses as it unlocks and depressurizes.\n");
    tell_room(shuttle,"The shuttle decends into the room.\n");
    tell_room(shuttle,"The shuttle door unlocks with a great clank.\n");
    tell_room(shuttle,"The door hisses as it unlocks and depressurizes.\n");
    return 1;
}

remove_shuttle(name) {
        deletem(shuttle_names,name);
        deletem(shuttle_objs,name);
        deletem(shuttle_dest,name);
        deletem(timer,name);
}

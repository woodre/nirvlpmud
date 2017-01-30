inherit "/players/vertebraker/closed/std/monster";
#include "/sys/lib.h"
#include <ansi.h>
    
   reset(arg)
    {
  object gold,armor,weapon;
 int random_index;
 int hair_index;
 ::reset(arg);
 if(arg) return;
random_index=random(22);
hair_index=random(4);
set_name( ({"roger","barrack","liam","scott","patrick","colby","thomas","morgan","anthony","eric","rob","chris","brian","ron","esther","jung","quincy","raul","marcus","george","cleveland","tex"})[random_index] );
set_alt_name("worker");
set_race("human");
set_alias("driller");
set_gender("male");	
set_short( ({"Roger |Drill Team|","Barrack |Drill Team|","Liam |Drill Team|","Scott |Drill Team|","Patrick |Drill Team|","Colby |Drill Team|","Thomas |Drill Team|","Morgan |Drill Team|","Anthony |Drill Team|","Eric |Drill Team|","Rob |Drill Team|","Chris |Drill Team|","Brian |Drill Team|","Ron |Drill Team|","Esther |Drill Team|","Jung |Drill Team|","Quincy |Drill Team|","Raul |Drill Team|","Marcus |Drill Team|","George |Drill Team|","Cleveland |Drill Team|","Tex |Drill Team|"})[random_index] );

set_long(
query_name() + " has " + (({"blonde","brown","red","black"})[hair_index])+" hair, but "+query_possessive()+" hair is mostly covered by "+query_possessive()+"\n"+
"hard hat.  "+query_name()+" |Drill Team| is written on "+query_possessive()+" name tag\n"+
""+query_possessive()+" nametag is slightly covered by reflective gear, though.\n"+
"\n"+
query_name()+" has the following attributes:\n"+
"\n"+
"Body Build: "+BOLD+"Slim"+NORM+"\n"+
"Height: Average\n"+
"Demeanor: "+YEL+"Clumsy"+NORM+"\n"+
"\n"+
"\n");
set_level(22);
set_hp(400 + random(100));
set_ac(15 + random(3));
set_wc(33 + random(4));
set_al(0);
add_money(2000 + random(1000));
set_chat_chance(5);
load_chat(query_name()+" wonders what they should be doing.\n");
load_chat(query_name()+" asks, 'Where does this pipe go?'\n");
load_chat("You hear a "+BOLD+"THUD"+NORM+" as a pipe falls to the platform!\n"+
""+query_name()+" goes, 'Oops'\n");
armor=clone_object("/players/mo/rig/AC/helmet.c");
move_object(armor, this_object());
command("wear helmet", this_object());
armor=clone_object("/players/mo/rig/AC/gear.c");
move_object(armor, this_object());
command("wear vest", this_object());
}

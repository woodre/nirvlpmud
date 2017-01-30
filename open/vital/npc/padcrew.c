/******************************************************************************
 *  
 *  File:           human.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 1/3/01.
 *  
 *  Notes:			
 *  
 *  Change History: 1/6/01
 *  
 *  
 *****************************************************************************/

#include "/players/vital/vital.h"
#include "/players/vital/dest/dest.h"

inherit "/players/vital/closed/std/monster";

object item;
string *name_desc, *alias_desc;
string name_one, name_two, name_three, alias_one, alias_two, alias_three, grace;
int one, two, three, aone, atwo, athree;
int rnd;

reset(arg){
   if(arg) return;
   name_desc = ({"drika","seeri","jofan","uvywi","zudryn","totli","gynawer","kleren","jundo","carsi","sillan","doprocal","codyv","orick","elpfe","kutad","h'ral","tuget","bliduta","mairer","dulime","tolge","webbe","cinnor","saunil","ydragsil","claidest","kalytel","tliki","albsa","snorfyr","kolp","kyrrec","guknar","horyg","dynsu","qyfre","uhawin","virad","mydyc","sawet","launer"});
   alias_desc = ({"mechanic","chief","engineer","crewman","sweep","worker","tar man","signal jockey","mixer","smurf"});
    ::reset(arg);
    rnd = random(6);
    if(name_desc || alias_desc) {
      one=random(sizeof(name_desc)-1);
      two=random(sizeof(name_desc)-1);
      three=random(sizeof(name_desc)-1);
      aone=random(sizeof(alias_desc)-1);
      atwo=random(sizeof(alias_desc)-1);
      athree=random(sizeof(alias_desc)-1);
      name_one=name_desc[one];
      name_two=name_desc[two];
      name_three=name_desc[three];
      alias_one=alias_desc[aone];
      alias_two=alias_desc[atwo];
      alias_three=alias_desc[athree];
    }
    set_name("crew");
    set_alias("repair crew");
    set_race(get_race());
    set_gender(random(2) ? "male" : "female");
    set_short("A pad repair crew");
    set_long("  "+short_desc+"\n\
This is one of the roving repair crews out on the launch pad. It \n\
takes these crews working continually for the launch pads to stay in \n\
working order. This crew consists of,\n\
"+CAP(name_one)+", the "+alias_one+" \n\
"+CAP(name_two)+", the "+alias_two+" \n\
"+CAP(name_three)+", the "+alias_three+". \n");
    set_level(11+rnd);
    set_al(40*rnd);
    set_dead_ob(TO);
    add_money(TO->query_level()*(rnd+1));
    item=CO("/players/vital/closed/std/obj.c");
    item->set_name("wrench");
    item->set_id(({"wrench","tool","wrench-like tool"}));
    item->set_alias("tool");
    item->set_short("A wrench-like tool");
    item->set_long("Dis is a gweat toow if you awe going to wowk on de Wanding pads. It has been designed to do many diffewent functions. It wooks beyond youw abiwity to undewstand dough.\n");
    item->set_value(40*rnd);
    MO(item,TP);
}

id(str) { return str == name || str == alias || str == race || str == alt_name; }

get_race() {
    switch(random(5)) {
        case 0: grace = "human"; break;
        case 1: grace = "simbari"; break;
        case 2: grace = "krondaku"; break;
        case 3: grace = "poltroyan"; break;
        case 4: grace = "gi"; break;
    }
    return grace;
}

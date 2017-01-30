/******************************************************************************
 *  
 *  File:           birsh.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:         11/29/01.
 *  
 *  Notes:          another small mob for newbies to kill	
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include "/players/vital/vital.h"
inherit "/players/vital/closed/std/monster.c";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("birsh");
    set_alias("dragon");
    set_short("A "+BLU+"birsh"+NORM);
    set_long("\
This is a type of sea dragon that moves quickly and quietly through \n\
the water. It is a light blue, though there have been rare reports \n\
of a silver or white one. The birsh has three large fins and two \n\
pairs of eyes between each fin.\n");
    set_level(random(3)+4);
    set_attrib("ste",25);
    set_attrib("int",25);
    set_info("This "+BLU+"birsh"+NORM+" moves like lightning through water.\n");
    set_dead_ob(this_object());
}

monster_died(){
    object corpse, fin;
    corpse = present("corpse", environment());
    corpse->set_name(BLU+"birsh"+NORM);
    corpse->set_value(6);
    say("The "+BLU+"birsh"+NORM+" shudders and collapses.\n");
    fin = CO("/players/vital/closed/std/obj.c");
    fin->set_name("fin");
    fin->set_short(BLU+"birsh"+NORM+" "+HIB+"fin"+NORM);
    fin->set_long("\
  The "+BLU+"birsh"+NORM+" fin is about a meter in length and resembles \na small sail.\n");
    fin->set_value(25+random(100));
    fin->set_info("\
  The fins of dead, demon dragons are sought by some shops for \n\
construction and manufacturing.\n");
    fin->set_id( ({
        "birsh fin", "fin", "fins", "Fin", "Birsh Fin"
    }) );
    MO(fin,corpse);
    return 1;
}

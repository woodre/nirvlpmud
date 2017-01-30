/******************************************************************************
 *  
 *  File:           mad_machine.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 8/26/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include "/players/vital/vital.h"
#include "/players/vital/dest/dest.h"

inherit "/players/vital/closed/std/monster.c";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("machine");
    set_alias("mad machine");
    set_alt_name("mad_machine");
    set_race("machine");
    set_level(16+random(5));
    set_al(-255);
    set_gender("neuter");
    set_short("A Mad Machine");
    set_long("\
  The stress and strain of repetitious tasks have finally taken its \n\
toll on this ordinary machine. The machine's outer shell has been \n\
battered and it is no longer possible to determine what the machine \n\
was intended to accomplish. Large electrodes spark threateningly and \n\
the machine rolls around skittishly on large treads.\n");
    load_a_chat(YEL+"Sparks"+NORM+" fly from the electrodes near your head.\n");
    load_a_chat("The machine is "+RED+"raging"+NORM+" out of control.\n");
    set_a_chat_chance(15);
    set_chat_chance(7);
    load_chat("Gears grind and capacitors buzz and the machine rocks back and forth.\n");
    load_chat("Bzzzzttt. \n\tGrrrrrr. \n\t\tPbbbbttttt. \n\t\t\tFzzzzootttt.\n");
    set_message_hit(({HIR+"fried"+NORM," with high voltage","smashed into"," at full speed","hit"," as it swings around","backs over"," with its treads","jolted"," with an arc of energy","bumped"," into a corner","caused"," to break out in goosebumps"}));
    set_chance(35+level);
    set_spell_mess1("The machine discharges 100,000 "+YEL+"volts"+NORM+" into his enemy.\n");
    set_spell_mess2("The mad machine "+YEL+"electrocutes"+NORM+" you with 100,000 volts.\n");
    set_spell_dam(level+random(level*3));
    set_dead_ob(TO);
    add_money(900+random(600));
}

id(str) { return str == "Machine" || str == "Mad Machine" || str == "Mad" || str == "crazy machine" || str == "crazy" || str == "Crazy" || str == name || str == alias || str == race || str == alt_name; }

monster_died(level) {
  int x;
  object corpse, prize;
  if(corpse=present("corpse",environment())) {
    switch(x=corpse->query_corpse_level()) {
        case 16: x=0; break;
        case 17: x=1; break;
        case 18: x=2; break;
        case 19: x=4; break;
        case 20: x=6; break;
    }
    while(x > 0) {
        prize=CO(STD+"obj.c");
        prize->set_name("large gear");
        prize->set_alias("gear");
        prize->set_id(({"large gear","gear","gears","large gears","Gear","Gears","Large Gear"}));
        prize->set_weight(1+random(3));
        prize->set_short("A large "+BOLD+"gear"+NORM);
        prize->set_long("This is a large gear that must have come from inside a machine.\nPerhaps it could be worth something to someone.\n");
        prize->set_info("This gear could be worth some money in the shop. The gears \nare eventually melted down for other machines.\n");
        prize->set_value(500+random(100));
        MO(prize,corpse);
        x--;
    }
  }
}

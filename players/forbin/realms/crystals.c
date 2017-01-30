/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Main
//  Function:     Teleporting device for my area
//  Create Date:  2004.06.04
//  Last Edit:    2004.07.30 -Forbin
//  Notes:        Adapted heavily from code developed by 
//                  Maledicta@Nirvana Orignal Copyright (c) 2002 
//  Notable Changes:           
//    2004.07.30 -lowered sp cost to use from 40+random(20) to
//                10+random(10) - I actually want people to vist my area 
//    2004.07.30 -added ZEUS
//    2004.07.19 -removed sps cost all together
*/ 

#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"
#define FORBIN "clearredblueblackyellowgreenpurpleorange"
#define FFOREST "blueredclearblackyellowgreenpurpleorange"
#define GREEEN "orangeblueredblackyellowpurplegreenclear"
#define PASS "redclearblueblackyellowgreenorangepurple"
#define WARP "clearblueredyellowblackgreenpurpleorange"
#define ZEUS "clearredgreenblackyellowbluepurpleorange"

string *Crystals;
string Dest;

reset(arg) {
  if(arg) return;
  Crystals = allocate(8);  
  Crystals = ({"clear","red","blue","black","yellow","green","purple","orange"});
}

id(str) { return (str == "crystals" || str == "floating crystals" ||
                  str == "cystal_teleporter"); }

short() {  return HIW+"Floating Crystals"+NORM; }

long() { 
  int i;
  write("This is a series of eight floating crystals, each of different\n"+
        "colors. They are suspended by an unknown force of magic, but\n"+
        "can be maneuvered around into different orders.  It seems that\n"+
        "they must be side by side, or will force themselves into an\n"+
        "arrangement of that sort.  The current order is:\n\n"+
        "  ");
  for(i = 0; i < sizeof(Crystals); i++) {
         if(Crystals[i] == "red")    write(HIR+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "blue")   write(HIB+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "green")  write(HIG+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "black")  write(HIK+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "yellow") write(HIY+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "orange") write(YEL+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "purple") write(MAG+" "+Crystals[i]+" "+NORM);
    else                             write(" "+Crystals[i]+" "+NORM);
  } 
  write("\n\nYou may manipulate them using the following commands:\n"+
        "            exchange <crystal> for <crystal>\n"+
        "            activate crystals\n"+
        "            reset crystals\n\n");
    return 1;
}

get() { return 1; }

query_weight() { return 100000000; }

query_value() { return 0; }

init() {
  add_action("cmd_exchange","exchange");
  add_action("cmd_activate","activate");
  add_action("cmd_reset","reset");
  add_action("cmd_read","read");
}

/* 
//  ***********************************************************************
//  Function:    cmd_read
//  Description: details teleporting locations
//  Arguments:   string str, where str is reading target
//  ***********************************************************************
*/

cmd_read(string str) {
  if(!str || (str != "rune" && str != "runes" && str != "symbol" && str != "symbols")) { 
    notify_fail("Read what?\n"); 
      return 0; 
  }
  write("You carefully study the "+str+" and begin to see:\n\n"+
        "  Nirvana South Forest:  clear "+HIR+"red "+HIB+"blue "+HIK+"black "+HIY+"yellow "+HIG+"green "+NORM+MAG+"purple "+YEL+"orange\n"+NORM+
        "  The Flame Forest:      "+HIB+"blue "+HIR+"red "+NORM+"clear "+HIK+"black "+HIY+"yellow "+HIG+"green "+NORM+MAG+"purple "+YEL+"orange\n"+NORM+
        "  The Village Green:     "+YEL+"orange "+HIB+"blue "+HIR+"red "+HIK+"black "+HIY+"yellow "+NORM+MAG+"purple "+HIG+"green "+NORM+"clear\n"+NORM+ 
        "  Chamber of Realms:     "+HIR+"red "+NORM+"clear "+HIB+"blue "+HIK+"black "+HIY+"yellow "+HIG+"green "+NORM+YEL+"orange "+MAG+"purple\n"+NORM+
        "  Eurale's Warp:         clear "+HIB+"blue "+HIR+"red "+HIY+"yellow "+HIK+"black "+HIG+"green "+NORM+MAG+"purple "+YEL+"orange\n"+NORM+
        "  The Worlds of Zeus:    clear "+HIR+"red "+HIG+"green "+HIK+"black "+HIY+"yellow "+HIB+"blue "+NORM+MAG+"purple "+YEL+"orange\n\n"+NORM);        
    return 1; 
}

/* 
//  ***********************************************************************
//  Function:    cmd_reset
//  Description: resets crystals to original configuration
//  Arguments:   string str, where str would be what to reset
//  ***********************************************************************
*/

cmd_reset(string str) {
  if(!str || (str != "crystal" && str != "crystals")) { 
    write("reset what?\n"); 
      return 1; 
  }
  Crystals = ({"clear","red","blue","black","yellow","green","purple","orange"});
  write("You reset the order of the crystals to their original arrangement.\n");
    return 1;
}

/* 
//  ***********************************************************************
//  Function:    cmd_exchange
//  Description: controls exchanging crystals for each other
//  Arguments:   string str, where str would be which crystals to switch
//  ***********************************************************************
*/

cmd_exchange(string str) {
  string one;
  string two;
  int newone;
  int newtwo;
  int i;
  if(!str) {
    write("exchange <crystal color> for <crystal color>\n");
      return 1;
  }
  if(sscanf(str, "%s for %s", one, two) != 2) {
    write("exchange <crystal color> for <crystal color>\n");
      return 1;
  }
  if(one == two) { 
    write("You cannot exchange the same crystal for itself.\n");
      return 1;
  }
  if(one != "clear" && one != "red" && one != "blue" && 
     one != "green" && one != "black" && one != "yellow" && 
     one != "orange" && one != "purple") {
    write(one+" is an invalid crystal.\n");
      return 1;
  }
  if(two != "clear" && two != "red" && two != "blue" && 
     two != "green" && two != "black" && two != "yellow" &&
     two != "orange" && two != "purple") {
    write(two+" is an invalid crystal.\n");
      return 1;
  }
  newone = index(Crystals, one);
  newtwo = index(Crystals, two);

  Crystals[newone] = two;
  Crystals[newtwo] = one;
  write("You have successfully exchanged "+one+" for "+two+".\n");
  write("The new positions are:\n\n"+
        "  ");
  for(i = 0; i < sizeof(Crystals); i++){
         if(Crystals[i] == "red")    write(HIR+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "blue")   write(HIB+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "green")  write(HIG+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "black")  write(HIK+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "yellow") write(HIY+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "orange") write(YEL+" "+Crystals[i]+" "+NORM);
    else if(Crystals[i] == "purple") write(MAG+" "+Crystals[i]+" "+NORM);
    else                             write(" "+Crystals[i]+" "+NORM);
  }
  write("\n\n");
    return 1;
}

/* 
//  ***********************************************************************
//  Function:    cmd_activate
//  Description: controls activating crystals and teleporting by calling
//                 teleport_me() on success
//  Arguments:   string str, where str would be what to activate
//  ***********************************************************************
*/

cmd_activate(string str) {
  string newcryst;
  string dest;
  string who;
  string lev, xlev;

  int cost;

    if(!str || (str != "crystal" && str != "crystals")) { 
    write("activate what?\n"); 
      return 1; 
  }
  newcryst = Crystals[0]+Crystals[1]+Crystals[2]+Crystals[3]+Crystals[4]+Crystals[5]+Crystals[6]+Crystals[7]+"";

       if(newcryst == FORBIN)  { dest = "players/forbin/realms/entrance"; }
  else if(newcryst == FFOREST) { dest = "players/forbin/realms/flame_forest/RMS/ff02_02"; }
  else if(newcryst == GREEEN)   { dest = "room/vill_green"; }
  else if(newcryst == PASS)    { dest = "players/mythos/enterance"; }
  else if(newcryst == WARP)    { dest = "players/eurale/RMS/warp"; }    
  else if(newcryst == ZEUS)    { dest = "players/zeus/realm/main"; }      
  write("You wave a hand past the crystals to activate them...\n");
  if(!dest) {
    write("Nothing happens.  The alignments must be off.\n");
      return 1; 
  }
 cost = 1; /* cost = 40+random(20); */
  if(this_player()->query_sp() < cost) {
    write("Your body does not have enough energy to activate the crystals...\n");
      return 1;
  }
  this_player()->add_spell_point(-cost);
  write("The crysta"+HIW+"ls begin t"+HIY+"o glow...\n"+NORM);
  Dest = dest;
  who = this_player()->query_real_name();
  lev = this_player()->query_level(); xlev = this_player()->query_extra_level();
#ifdef CRYSTALSLOG
  log_it(CRYSTALSLOG,pad(capitalize(who), 12)+" "+pad("("+lev+"+"+xlev+")", 8)+" went: "+dest);  
#endif
  call_out("teleport_me", 3, this_player());
  return 1;
}

/* 
//  ***********************************************************************
//  Function:    teleport_me
//  Description: does the actual teleportation
//  Arguments:   string destination, where desination is location 
//  ***********************************************************************
*/
  
teleport_me(object player) {
  string dest;
  dest = Dest;
  tell_room(environment(player),
    HIY+"\n\n     < < < < < The crystals flash brightly! > > > > >\n\n"+NORM);
  move_object(player, "/players/feldegast/realm/void.c");
  tell_room(environment(),
    HIY+"          "+player->query_name()+" disappears in a flash of light.\n"+NORM);
  tell_room(dest,
    HIY+"          "+player->query_name()+" arrives in a flash of light.\n"+NORM);
  move_object(player, dest);
  command("look", player);
    return 1;
}

/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Function:     Heal shop
//  Create Date:  2004.06.06
//  Last Edit:    2004.07.20 -Forbin
//  Notes:        Adapted heavily from /players/zeus/realm/taus/grove.c
//                  Original Copyright (c) Zeus@Nirvana
//  Notable Changes:
//    2004.07.20 -added Museeuw Tonic & Mongie Berries (approved by Fred) [Forbin]
//    2004.07.20 -fixed cloning problem (was still cloning items if players
//                couldn't afford it or carry it - was bogging down with 
//                unneccessary amounts of unclaimed objects [Forbin]
//    2004.07.22 -modified logging protocols [Forbin]
//    2005.03.33 -added day-old mongie [Forbin] (approved by Fred)
*/

#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"
inherit "/players/forbin/closed/std/room.c";

int Jaune_Amount, dHuez_Amount, Galibier_Amount, Mayias_Amount, Museeuw_Amount, Mongie_Amount, OldMongie_Amount;
int Cost_Jaune, Cost_dHuez, Cost_Galibier, Cost_Mayias, Cost_Museeuw, Cost_Mongie, Cost_OldMongie;
int Profit;
object Monk;
string *Tipper;

reset(arg) {
  
    Jaune_Amount = 40+random(10);
    dHuez_Amount = 40+random(10);
    Galibier_Amount = 40+random(10);
    Mayias_Amount = 40+random(10);
    Museeuw_Amount = 40+random(10);
    Mongie_Amount = 40+random(10);
    OldMongie_Amount = 40+random(10);
    Cost_Jaune = 1200;
    Cost_dHuez = 1500;
    Cost_Galibier = 2100;
    Cost_Mayias = 3300;
    Cost_Museeuw = 1900;
    Cost_Mongie = 1900;
    Cost_OldMongie = 1350;
    Tipper = ({ });  
    
  if(arg) return;
  
  if(!present("davvrus_the_monk")) {
    Monk = clone_object("/players/forbin/realms/davvrus.c");
    move_object(Monk, this_object());
    }
  if(!present("saddlebagdispenser")) {
    move_object(clone_object("/players/forbin/realms/misc/OBJ/sbd.c"), this_object());
    }    
  
/* Restock the heal amounts **********************************************/
         if(Jaune_Amount > 40)                        { Jaune_Amount += random(5); }
    else if(Jaune_Amount > 30 && Jaune_Amount <= 40)  { Jaune_Amount += 5+random(6); }
    else if(Jaune_Amount <= 30 && Jaune_Amount >= 10) { Jaune_Amount += 10+random(16); }
    else if(Jaune_Amount < 10)                        { Jaune_Amount += 20+random(16); }

         if(dHuez_Amount > 40)                        { dHuez_Amount += random(5); }
    else if(dHuez_Amount > 30 && dHuez_Amount <= 40)  { dHuez_Amount += 5+random(6); }
    else if(dHuez_Amount <= 30 && dHuez_Amount >= 10) { dHuez_Amount += 10+random(16); }
    else if(dHuez_Amount < 10)                        { dHuez_Amount += 20+random(16); }
    
         if(Galibier_Amount > 40)                           { Galibier_Amount += random(5); }
    else if(Galibier_Amount > 30 && Galibier_Amount <= 40)  { Galibier_Amount += 5+random(6); }
    else if(Galibier_Amount <= 30 && Galibier_Amount >= 10) { Galibier_Amount += 10+random(16); }
    else if(Galibier_Amount < 10)                           { Galibier_Amount += 20+random(16); }    

         if(Mayias_Amount > 40)                         { Mayias_Amount += random(5); }
    else if(Mayias_Amount > 30 && Mayias_Amount <= 40)  { Mayias_Amount += 5+random(6); }
    else if(Mayias_Amount <= 30 && Mayias_Amount >= 10) { Mayias_Amount += 10+random(16); }
    else if(Mayias_Amount < 10)                         { Mayias_Amount += 20+random(16); }  

         if(Museeuw_Amount > 40)                         { Museeuw_Amount += random(5); }
    else if(Museeuw_Amount > 30 && Museeuw_Amount <= 40)  { Museeuw_Amount += 5+random(6); }
    else if(Museeuw_Amount <= 30 && Museeuw_Amount >= 10) { Museeuw_Amount += 10+random(16); }
    else if(Museeuw_Amount < 10)                         { Museeuw_Amount += 20+random(16); }          
    
         if(Mongie_Amount > 40)                         { Mongie_Amount += random(5); }
    else if(Mongie_Amount > 30 && Mongie_Amount <= 40)  { Mongie_Amount += 5+random(6); }
    else if(Mongie_Amount <= 30 && Mongie_Amount >= 10) { Mongie_Amount += 10+random(16); }
    else if(Mongie_Amount < 10)                         { Mongie_Amount += 20+random(16); }     

         if(OldMongie_Amount > 40)                            { OldMongie_Amount += random(5); }
    else if(OldMongie_Amount > 30 && OldMongie_Amount <= 40)  { OldMongie_Amount += 5+random(6); }
    else if(OldMongie_Amount <= 30 && OldMongie_Amount >= 10) { OldMongie_Amount += 10+random(16); }
    else if(OldMongie_Amount < 10)                            { OldMongie_Amount += 20+random(16); }
    
/* End of restocking *****************************************************/    
    
  short_desc = "A Dilapidated Old Shack";
  long_desc = 
    "  This dilapidated old place looks to be on its last leg.  Several\n"+
    "rectangular tables stand on the dirt floor.  A low counter rests to\n"+
    "the left of the door while a wooden rocking chair sits beside it.\n"+
    "A small sign is nailed to the center table.  Most things in the\n"+ 
    "room are covered with a layer of dust.  Some things look quite old.\n";
  set_light(1);
  add_item(({"table","tables","rectangular table","rectangular tables"}),
    "Four wooden tables, twice as long as they are wide, stand on the dirt\n"+
    "floor.  Simple built, they have sturdy-looking legs and a lip runs\n"+
    "around the top to keep the items from falling off"); 
  add_item(({"floor","dirt floor"}),
    "A dirty cloud of brown kicks up as you tamp your foot down hard");
  add_item("door",
    "The door hangs from old rusty hinges.  You notice that one of them is\n"+
    "broken and does nothing to help the door stay upright");
  add_item(({"counter","low counter"}),
    "A low wooden counter runs along the east wall.  A small old-fashioned\n"+
    "cash register sits upon it");
  add_item(({"chair","rocking chair","wooden chair","wooden rocking chair"}),
    "A very old rocking chair sits to the left of the counter.  It is made\n"+
    "from oak and has many years of wear evident");
  add_item("sign",
    "A small hand-lettered sign is nailed to one of the tables.  You could\n"+
    "read it");
  add_item("dust",
    "Almost everything in the shack is buried under a layer of dust");
  add_smell("main", 
    "The air has a fruity, yet musky odor to it.  It reminds you of a\n"+
    "road-side farmer's market.");
  add_exit("players/forbin/realms/entrance.c","out");
  call_out("clear_tipper", 300);
  call_out("restock", 1500);
}

short() {
  if(this_player())
    return "A Dilapidated Old Shack" + (this_player()->query_level() > 20 ? " (Forbin's Castle)" : "");
  else return "A Dilapidated Old Shack";
 }

init() {
  ::init();
  add_action("cmd_read", "read");
  add_action("cmd_list", "list");
  add_action("cmd_ask", "ask");
  add_action("cmd_buy", "buy");
  add_action("cmd_tip", "tip");
}

clear_tipper() { 
  Tipper = ({ });
  while (remove_call_out("clear_tipper") != -1);
    call_out("clear_tipper", 300);
}

restock() { 
  reset(1);
  while (remove_call_out("restock") != -1);
    call_out("restock", 300);
}

add_tipper(string str) {
  if(!query_tipper(str)) return Tipper += ({ str, });
    return 0;
}

sub_tipper(string str) {
  if(query_tipper(str)) return Tipper -= ({ str, });
    return 0;
}

query_tipper(string str) {
  if(!Tipper || !sizeof(Tipper)) return 0;
  if(index(Tipper, str) > -1) return 1;
  return 0;
}

/* 
 *  ***********************************************************************
 *  Function:    cmd_read
 *  Description: details heals for sale
 *  Arguments:   string str, where str is reading target
 *  ***********************************************************************
 */

cmd_read(string str) {
  if(!str || str != "sign") { 
      return 0; 
  }
  write(
    "Neatly lettered by someone with very nice handwriting, the sign reads:\n\n"+
    "  Please try all of our nice selections of a healing vendibles.\n\n"+
    "    Item\t\t\tStock\t\tPrice\n\n"+
    "    Malliot Jaune Bar\t\t  "+Jaune_Amount+"\t\t"+Cost_Jaune+"\n"+
    "    d'Huez Leaves\t\t  "+dHuez_Amount+"\t\t"+Cost_dHuez+"\n"+
    "    Museeuw Tonic\t\t  "+Museeuw_Amount+"\t\t"+Cost_Museeuw+"\n"+
    "    Mongie Berries\t\t  "+Mongie_Amount+"\t\t"+Cost_Mongie+"\n"+     
    "    Day-old Mongie Berries\t  "+OldMongie_Amount+"\t\t"+Cost_OldMongie+"\n"+         
    "    Galibier Root\t\t  "+Galibier_Amount+"\t\t"+Cost_Galibier+"\n"+
    "    Bark of the Mayias\t\t  "+Mayias_Amount+"\t\t"+Cost_Mayias+"\n\n"+
    "  To purchase, just 'buy <item>', e.g.:  'buy jaune'\n"+
    "  Note:  Tips are both welcomed and encouraged.\n"+
    "                                     < The Management >\n");
    return 1;
}

/* 
 *  ***********************************************************************
 *  Function:    cmd_list
 *  Description: details heals for sale
 *  Arguments:   none
 *  ***********************************************************************
 */

cmd_list() {
  write(
    "\nNeatly lettered by someone with very nice handwriting, the sign reads:\n"+
    "  Please try all of our nice healing vendibles.\n\n"+
    "    Item\t\t\tStock\t\tPrice\n\n"+
    "    Malliot Jaune Bar\t\t  "+Jaune_Amount+"\t\t"+Cost_Jaune+"\n"+
    "    d'Huez Leaves\t\t  "+dHuez_Amount+"\t\t"+Cost_dHuez+"\n"+
    "    Museeuw Tonic\t\t  "+Museeuw_Amount+"\t\t"+Cost_Museeuw+"\n"+
    "    Mongie Berries\t\t  "+Mongie_Amount+"\t\t"+Cost_Mongie+"\n"+ 
    "    Day-old Mongie Berries\t  "+OldMongie_Amount+"\t\t"+Cost_OldMongie+"\n"+                 
    "    Galibier Root\t\t  "+Galibier_Amount+"\t\t"+Cost_Galibier+"\n"+
    "    Bark of the Mayias\t\t  "+Mayias_Amount+"\t\t"+Cost_Mayias+"\n\n"+
    "  To purchase, just 'buy <item>', e.g.:  'buy jaune'\n"+
    "  Note:  Tips are both welcomed and encouraged.\n"+
    "                                     < The Management >\n");
    return 1;
}

/* 
 *  ***********************************************************************
 *  Function:    cmd_ask
 *  Description: shows profit since reboot (wizards only)
 *  Arguments:   string str, where str is the npc
 *  ***********************************************************************
 */

cmd_ask(string str) {
  if(!str || (str != "monk" && str != "davvrus")) return 0;
  if(!present("davvrus_the_monk")) return 0;
  if(this_player()->query_level() > 39) {
    write("Da'vvrus says, \"I have made "+Profit+" coins since reboot!\"\n");
      return 1;
  }
    return 1;
}

/* 
 *  ***********************************************************************
 *  Function:    cmd_tip
 *  Description: allows player to tip npc (if they tip before purchase,
 *                 heals are regular price for 5 minutes)
 *  Arguments:   string str, where str is the npc
 *  ***********************************************************************
 */

cmd_tip(string str) { 
  int tip;
  if(!str || (str != "monk"  && str != "davvrus")) return 0;
  if(!present("davvrus_the_monk")) {
    write("The is no one here to help you.\n");
      return 1; 
  }
  tip = 75 + random(200);
  if(this_player()->query_money() < tip) {
    write("Dav'rrus says you don't have enough money to tip him.\n");
    return 1;
  }
  write("You hand Da'vvrus "+tip+" coins for his excellent service.\n");
  tell_room(this_object(), this_player()->query_name()+" tips the monk.\n", ({this_player()}));
  Monk->add_money(tip);
  if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
  this_player()->add_money(-tip);
  Profit += tip;
  if(!query_tipper(this_player()->query_name())) add_tipper(this_player()->query_name());
#ifdef TIPSLOG
    log_this(TIPSLOG, "tipped Da'vvrus:");  
#endif 
  return 1;
}

/* 
 *  ***********************************************************************
 *  Function:    cmd_buy
 *  Description: allows players to purchase heals
 *  Arguments:   string str, where str is the item desired
 *  ***********************************************************************
 */

cmd_buy(string str){
  int tip, noitem;
  object heal;
  noitem = 0;
  if(!str) {
    tell_room(this_object(), 
      "Da'vvrus asks:  \""+this_player()->query_name()+", what would you like to buy?\"\n");
      return 1;
  }
  if(!present("davvrus_the_monk"))   {
    write("The is no one here to help you.\n");
      return 1;
  }
  tip = random(25+random(30));
  if(str == "maillot" || str == "jaune" || str == "maillot jaune") {
    heal = clone_object("/players/forbin/heals/jaune.c");
    if(Jaune_Amount < 1) {
      destruct(heal);      
      tell_room(this_object(), 
        "Da'vvrus says:  \"I am so sorry, but I seem to be out of Maillot Jaune.\"\n");
        return 1;
    }
    if(TP->query_money() < Cost_Jaune + tip) {
      destruct(heal);      
      tell_room(this_object(), 
        "Da'vvrus chuckles: \"You can't afford that, "+this_player()->query_name()+".\"\n");
        return 1;
    }
    if(!call_other(this_player(),"add_weight",call_other(heal,"query_weight"))) {
      destruct(heal);      
      tell_room(this_object(), 
        "Da'vvrus laughs: \"You can't carry any more, "+this_player()->query_name()+".\"\n");
          return 1;
    }
    if(query_tipper(this_player()->query_name())) {
      write("You pay Da'vvrus "+Cost_Jaune+" coins.\n");
      write("The monk hands you a bar of Malliot Jaune.\n");
      this_player()->add_money(-Cost_Jaune);
      Monk->add_money(Cost_Jaune);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_Jaune;
    }
    else {
      write("You pay Da'vvrus "+Cost_Jaune+" coins, then decide to throw in a tip.\n");
      write("The monk hands you a bar of Malliot Jaune.\n");
      this_player()->add_money(-Cost_Jaune-tip);
      Monk->add_money(Cost_Jaune+tip);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_Jaune+tip;      
    }
    move_object(heal, this_player());
    Jaune_Amount -= 1;
    return 1;    
  }
  else if(str == "dhuez" || str == "leaves" || str == "dhuez leaves") {
    heal = clone_object("/players/forbin/heals/dhuez.c");
    if(dHuez_Amount < 1) {
      destruct(heal);      
      tell_room(this_object(),
        "Da'vvrus says:  \"I am so sorry, but I seem to be out of d'Huez Leaves.\"\n");
        return 1;
    }
    if(TP->query_money() < Cost_dHuez + tip) {
      destruct(heal);      
      tell_room(this_object(), 
        "Da'vvrus chuckles: \"You can't afford that, "+this_player()->query_name()+".\"\n");
        return 1;
    }
    if(!call_other(this_player(),"add_weight",call_other(heal,"query_weight"))) {
      destruct(heal);
      tell_room(this_object(), 
        "Da'vvrus laughs: \"You can't carry any more, "+this_player()->query_name()+".\"\n");
          return 1;
    }
    if(query_tipper(this_player()->query_name())) {
      write("You pay Da'vvrus "+Cost_dHuez+" coins.\n");
      write("The monk hands you a bunch of d'Huez Leaves.\n");
      this_player()->add_money(-Cost_dHuez);
      Monk->add_money(Cost_dHuez);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_dHuez;
    }
    else {
      write("You pay Da'vvrus "+Cost_dHuez+" coins, then decide to throw in a tip.\n");
      write("The monk hands you a bunch of d'Huez Leaves.\n");
      this_player()->add_money(-Cost_dHuez-tip);
      Monk->add_money(Cost_dHuez+tip);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_dHuez+tip;      
    }
    move_object(heal, this_player());
    dHuez_Amount -= 1;
    return 1;    
  }
  else if(str == "museeuw" || str == "tonic" || str == "museeuw tonic") {
    heal = clone_object("/players/forbin/heals/museeuw.c");
    if(Museeuw_Amount < 1) {
      destruct(heal);
      tell_room(this_object(),
        "Da'vvrus says:  \"I am so sorry, but I seem to be out of Museeuw Tonic.\"\n");
        return 1;        
    }
    if(TP->query_money() < Cost_Museeuw + tip) {
      destruct(heal);
      tell_room(this_object(), 
        "Da'vvrus chuckles: \"You can't afford that, "+this_player()->query_name()+".\"\n");
        return 1;
    }
    if(!call_other(this_player(),"add_weight",call_other(heal,"query_weight"))) {
      destruct(heal);
      tell_room(this_object(), 
        "Da'vvrus laughs: \"You can't carry any more, "+this_player()->query_name()+".\"\n");
          return 1;
    }
    if(query_tipper(this_player()->query_name())) {
      write("You pay Da'vvrus "+Cost_Museeuw+" coins.\n");
      write("The monk hands you a decanter of Museeuw Tonic.\n");
      this_player()->add_money(-Cost_Museeuw);
      Monk->add_money(Cost_Museeuw);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_Museeuw;
    }
    else {
      write("You pay Da'vvrus "+Cost_Museeuw+" coins, then decide to throw in a tip.\n");
      write("The monk hands you a decanter of Museeuw Tonic.\n");
      this_player()->add_money(-Cost_Museeuw-tip);
      Monk->add_money(Cost_Museeuw+tip);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_Museeuw + tip;      
    }
    move_object(heal, this_player());
    Museeuw_Amount -= 1;
    return 1;    
  }  
  else if(str == "mongie" || str == "berries" || str == "mongie berries") {
    heal = clone_object("/players/forbin/heals/mongie.c");
    if(Mongie_Amount < 1) {
      destruct(heal);
      tell_room(this_object(),
        "Da'vvrus says:  \"I am so sorry, but I seem to be out of Mongie Berries.\"\n");
        return 1;        
    }
    if(TP->query_money() < Cost_Mongie + tip) {
      destruct(heal);
      tell_room(this_object(), 
        "Da'vvrus chuckles: \"You can't afford that, "+this_player()->query_name()+".\"\n");
        return 1;
    }
    if(!call_other(this_player(),"add_weight",call_other(heal,"query_weight"))) {
      destruct(heal);
      tell_room(this_object(), 
        "Da'vvrus laughs: \"You can't carry any more, "+this_player()->query_name()+".\"\n");
          return 1;
    }
    if(query_tipper(this_player()->query_name())) {
      write("You pay Da'vvrus "+Cost_Mongie+" coins.\n");
      write("The monk hands you a bunch of Mongie Berries.\n");
      this_player()->add_money(-Cost_Mongie);
      Monk->add_money(Cost_Mongie);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_Mongie;
    }
    else {
      write("You pay Da'vvrus "+Cost_Mongie+" coins, then decide to throw in a tip.\n");
      write("The monk hands you a bunch of Mongie Berries.\n");
      this_player()->add_money(-Cost_Mongie-tip);
      Monk->add_money(Cost_Mongie+tip);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_Mongie + tip;      
    }
    move_object(heal, this_player());
    Mongie_Amount -= 1;
    return 1;    
  }    
  else if(str == "day-old mongie" || str == "day-old berries" || 
          str == "day-old mongie berries" || str == "day-old") {
    heal = clone_object("/players/forbin/heals/oldmongie.c");
    if(OldMongie_Amount < 1) {
      destruct(heal);
      tell_room(this_object(),
        "Da'vvrus says:  \"I am so sorry, but I seem to be out of Day-old Mongie Berries.\"\n");
        return 1;        
    }
    if(TP->query_money() < Cost_OldMongie + tip) {
      destruct(heal);
      tell_room(this_object(), 
        "Da'vvrus chuckles: \"You can't afford that, "+this_player()->query_name()+".\"\n");
        return 1;
    }
    if(!call_other(this_player(),"add_weight",call_other(heal,"query_weight"))) {
      destruct(heal);
      tell_room(this_object(), 
        "Da'vvrus laughs: \"You can't carry any more, "+this_player()->query_name()+".\"\n");
          return 1;
    }
    if(query_tipper(this_player()->query_name())) {
      write("You pay Da'vvrus "+Cost_OldMongie+" coins.\n");
      write("The monk hands you a bunch of Mongie Berries.\n");
      this_player()->add_money(-Cost_OldMongie);
      Monk->add_money(Cost_OldMongie);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_OldMongie;
    }
    else {
      write("You pay Da'vvrus "+Cost_OldMongie+" coins, then decide to throw in a tip.\n");
      write("The monk hands you a you a bunch of Mongie Berries.\n");
      this_player()->add_money(-Cost_OldMongie-tip);
      Monk->add_money(Cost_OldMongie+tip);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_OldMongie + tip;      
    }
    move_object(heal, this_player());
    OldMongie_Amount -= 1;
    return 1;    
  }      
  else if(str == "galibier" || str == "root" || str == "galibier root") {
    heal = clone_object("/players/forbin/heals/galibier.c");
    if(Galibier_Amount < 1) {
      destruct(heal);      
      tell_room(this_object(), 
        "Da'vvrus says:  \"I am so sorry, but I seem to be out of Galibier Root.\"\n");
        return 1;
    }
    if(TP->query_money() < Cost_Galibier + tip) {
      destruct(heal);      
      tell_room(this_object(), 
        "Da'vvrus chuckles: \"You can't afford that, "+this_player()->query_name()+".\"\n");
        return 1;
    }
    if(!call_other(this_player(),"add_weight",call_other(heal,"query_weight"))) {
      destruct(heal);      
      tell_room(this_object(), 
        "Da'vvrus laughs: \"You can't carry any more, "+this_player()->query_name()+".\"\n");
          return 1;
    }
    if(query_tipper(this_player()->query_name())) {
      write("You pay Da'vvrus "+Cost_Galibier+" coins.\n");
      write("The monk hands you a small Galibier Root.\n");
      this_player()->add_money(-Cost_Galibier);
      Monk->add_money(Cost_Galibier);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_Galibier;
    }
    else {
      write("You pay Da'vvrus "+Cost_Galibier+" coins, then decide to throw in a tip.\n");
      write("The monk hands you a small Galibier Root.\n");
      this_player()->add_money(-Cost_Galibier-tip);
      Monk->add_money(Cost_Galibier+tip);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_Galibier+tip;      
    }
    move_object(heal, this_player());
    Galibier_Amount -= 1;
    return 1;    
  }
  else if(str == "mayias" || str == "bark" || str == "bark of mayias") {
    heal = clone_object("/players/forbin/heals/mayias.c");
    if(Mayias_Amount < 1) {
      destruct(heal);      
      tell_room(this_object(), 
        "Da'vvrus says:  \"I am so sorry, but I seem to be out of Mayias Bark.\"\n");
        return 1;
    }
    if(TP->query_money() < Cost_Mayias + tip) {
      destruct(heal);      
      tell_room(this_object(), 
        "Da'vvrus chuckles: \"You can't afford that, "+this_player()->query_name()+".\"\n");
        return 1;
    }
    if(!call_other(this_player(),"add_weight",call_other(heal,"query_weight"))) {
      destruct(heal);      
      tell_room(this_object(), 
        "Da'vvrus laughs: \"You can't carry any more, "+this_player()->query_name()+".\"\n");
          return 1;
    }
    if(query_tipper(this_player()->query_name())) {
      write("You pay Da'vvrus "+Cost_Mayias+" coins.\n");
      write("The monk hands you a piece of Mayias Bark.\n");
      this_player()->add_money(-Cost_Mayias);
      Monk->add_money(Cost_Mayias);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_Mayias;
    }
    else {
      write("You pay Da'vvrus "+Cost_Mayias+" coins, then decide to throw in a tip.\n");
      write("The monk hands you a piece of Mayias Bark.\n");
      this_player()->add_money(-Cost_Mayias-tip);
      Monk->add_money(Cost_Mayias+tip);
      if(Monk->query_money() > 10000) Monk->add_money(-3000-random(3000));
      Profit += Cost_Mayias+tip;      
    }
    move_object(heal, this_player());
    Mayias_Amount -= 1;
    return 1;
  }  
  else {
    tell_room(this_object(), "Da'vvrus says: \"What do you want to buy "+this_player()->query_name()+"?\"\n");
    noitem = 1;
  }
  if(!noitem) {
#ifdef HEALSLOG
    log_this(HEALSLOG, "purchased: "+capitalize(heal->query_name()));  
#endif    
  noitem = 0;
  }
  return 1;
}

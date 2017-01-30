/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Qual'tor Miniquest
//  Function:     area entrance
//  Create Date:  2005.02.18
//  Last Edit:    2005.02.18 -Forbin
*/

#include "/players/forbin/realms/cave/cavedefine.h"

inherit "/obj/treasure";

int Tied, Rolled;

reset(arg) {
  Tied = 1;
  Rolled = 1;
  if(arg) return;
  set_name("scroll");
  set_alias("sfp_miniquest_scroll");
  set_value(50+random(100));
}

init() {
  ::init();
  add_action("cmd_untie", "untie");
  add_action("cmd_tie", "tie");  
  add_action("cmd_unroll", "unroll");
  add_action("cmd_roll", "roll");
  add_action("cmd_read", "read");    
}

short() {
  if(Tied) return YEL+"A small scroll ["+NORM+"tied closed"+YEL+"]"+NORM; 
  else if(!Tied && Rolled) return YEL+"A small scroll ["+NORM+"closed"+YEL+"]"+NORM ;  
  else return YEL+"A small scroll ["+NORM+"opened"+YEL+"]"+NORM;   
}

long() {
  if(Tied) 
    long_desc = 
      "A small piece of brown parchment has been rolled up into a neat\n"+
      "little scroll.  A yellow piece of string is attached through a\n"+
      "hole and has been tied around it to keep the scroll closed.\n";
  else if(!Tied && Rolled) 
    long_desc = 
      "A small piece of brown parchment has been rolled up into a neat\n"+
      "little scroll.  A yellow piece of string is attached through a\n"+
      "hole and dangles in the air.\n";
  else
    long_desc = 
      "A small piece of brown parchment.  The edges are furled and it\n"+
      "looks like it has been rolled up before.  A yellow piece of\n"+
      "string is attached through a hole near the bottom of the sheet\n"+
      "and hangs loosely from the paper.  Some strange symbols and an\n"+
      "odd language looks to have been written with quite some care.\n";
  ::long();    
}    


status cmd_untie(string arg) {
  if(arg == ("scroll" || "small scroll")) {
    if(environment(this_object()) != this_player()) {
      tell_object(this_player(),  
        "You have to get the "+arg+" first.\n");      
      return 1;
    }
    if(!Tied) {
      tell_object(this_player(),  
        "The "+arg+" is already untied.\n");      
      return 1;
    }      
    tell_object(this_player(),  
      "You carefully untie the "+arg+".\n");      
    tell_room(environment(environment()),  
      (string)this_player()->query_name()+
      " carefully unties a "+arg+".\n", ({ environment() }) );
    Tied = 0;
    return 1;
  }
}

status cmd_tie(string arg) {
  if(arg == ("scroll" || "small scroll")) {
    if(environment(this_object()) != this_player()) {
      tell_object(this_player(),  
        "You have to get the "+arg+" first.\n");      
      return 1;
    }
    if(Tied) {
      tell_object(this_player(),  
        "The "+arg+" is already tied.\n");      
      return 1;
    }      
    tell_object(this_player(),  
      "You carefully tie the "+arg+".\n");      
    tell_room(environment(environment()),  
      (string)this_player()->query_name()+
      " carefully ties a "+arg+".\n", ({ environment() }) );
    Rolled = 1;
    Tied = 1;
    return 1;
  }
}

status cmd_unroll(string arg) {
  if(arg == ("scroll" || "small scroll")) {
    if(environment(this_object()) != this_player()) {
      tell_object(this_player(),  
        "You have to get the "+arg+" first.\n");      
      return 1;
    }
    if(Tied) {
      tell_object(this_player(),  
        "You will have to untie the "+arg+" first.\n");      
      return 1;
    }
    if(!Rolled) {
      tell_object(this_player(),  
        "The "+arg+" is already unrolled.\n");      
      return 1;
    }          
    tell_object(this_player(),  
      "You carefully unroll the "+arg+".\n");      
    tell_room(environment(environment()),  
      (string)this_player()->query_name()+
      " carefully unrolls a "+arg+".\n", ({ environment() }) );
    Rolled = 0;
    return 1;
  }
}

status cmd_roll(string arg) {
  if(arg == ("scroll" || "small scroll" || "parchment")) {
    if(environment(this_object()) != this_player()) {
      tell_object(this_player(),  
        "You have to get the "+arg+" first.\n");      
      return 1;
    }
    if(Tied || Rolled) {
      tell_object(this_player(),  
        "The "+arg+" is already rolled up.\n");      
      return 1;
    }          
    tell_object(this_player(),  
      "You carefully roll the "+arg+".\n");      
    tell_room(environment(environment()),  
      (string)this_player()->query_name()+
      " carefully rolls a "+arg+".\n", ({ environment() }) );
    Rolled = 1;
    return 1;
  }
}

status cmd_read(string arg) {
  if(arg == ("scroll" || "small scroll" || "parchment")) {
    if(environment(this_object()) != this_player()) {
      tell_object(this_player(),  
        "You have to get the "+arg+" first.\n");      
      return 0;
    }
    if(Tied || Rolled) {
      tell_object(this_player(),  
        "You will have to unroll the "+arg+" first.\n");      
      return 0;
    }
    tell_object(this_player(),  
      "As you begin to read the "+arg+", the strange symbols and runes\n"+
      "written on it begin to glow.\n\n"+
      "     This is what is written.\n");      
    tell_room(environment(environment()),  
      (string)this_player()->query_name()+
      " reads a "+arg+".\n", ({ environment() }) );
    return 1;
  }
}
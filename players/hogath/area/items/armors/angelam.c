/*
 *      File:                   angelam.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 11/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "obj/armor";


reset(arg){
    if(arg) return;
    ::reset(arg);
    set_name("Angelic Amulet"+NORM);
    set_alias("amulet");
    set_short(HIW+"Angelic Amulet"+NORM); 
    set_type("amulet");
    set_ac(2);
    set_long("A small angel dangles at the bottom of a ten inch\n"+
             "white gold chain.  It is said that this amulet was\n"+
             "created for holy knights to increase the purety of\n"+
             "their souls.\n"+NORM);
    set_weight(3);
    set_value(10000);
    call_out("holy",40);
    }

holy() {
  if(!environment(this_object())) return 1;
  if(worn) {
    if(environment(this_player()->query_alignment() < 1000)) {
      call_other(environment(this_object()),"add_alignment",1000);
    }
  }
  call_out("holy",40);
return 1;
}

wear(){
  ::wear();
  call_other(environment(this_object()),"add_alignment",1000);
}


    

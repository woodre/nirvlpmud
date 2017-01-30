#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "obj/armor";

#define CHARGETIME 1200;

int OldTime;

void start(object ob);
void stop(object ob);

reset(arg) {
  if(arg) return;
  ::reset();  
  set_name("ankh of light");
  set_alias("ankh");
  set_short(HIY+"Ankh of Light"+NORM);
  set_long(
  "  This holy emblem is one of good; a representation of several\n"+
  "deities and their holy alliance, it is a symbol of both hope and\n"+
  "faith.  Worked in stunning gold, the large ahnk is well attached\n"+
  "to a thick golden chain which could be worn around one's neck.\n"+
  "Sparkling clear diamonds intricately trace the outer edge of the\n"+
  "ankh, while dozens of luminous orange sapphires are set inside\n"+
  "this border and radiate with a lifelike brilliance of their own.\n");
  set_ac(0);                                          /* no physical ac */
  set_params("other|evil", 0, 10, "do_evil_special"); /* 10% evil resistance */ 
  set_params("other|dark", 0, 10, "do_dark_special"); /* 10% dark resistance */
  set_type("amulet");
  set_weight(1);
  set_value(1000);
  set_arm_light(1);
}

string short() {
  return HIY+"Ankh of Light"+NORM + 
    (this_object()->query_worn() ? " "+HIY+"("+NORM+"worn"+HIY+")"+NORM : ""); 
}

void
init() {
 ::init();
 add_action("wear", "wear");
 add_action("remove", "remove");
}

int wear(string arg) {
  status wFlag;
  status x;
  wFlag = worn;
  x = (int)::wear(arg);
  if(!wFlag && worn) {
    tell_object(environment(),
      "You delicately drape the golden chain around your neck, taking care\n"+
      "to situate the "+HIY+"Ahnk of Light"+NORM+" just so.  A warmth washes over you.\n");
    start(this_player());
  }
  return x;
}

status remove(string arg) {
  status wFlag, x;
  wFlag = worn;
  x = (int)::remove(arg);
  if(wFlag && !worn) {
    tell_object(environment(),
      "You carefully remove the "+HIY+"Ankh of Light"+NORM+".  You feel a coldness inside.\n");
    stop(this_player());
  }
  return x;
}

drop() {
  this_object()->remove("ankh of light");
  ::drop();
}

give() {
  this_object()->remove("ahnk of light");
  ::give();
}

int is_time() {
  return time() >= OldTime + CHARGETIME;
}

void start(object ob) {
  call_out("heal_wearer", 60, ob);
  call_out("redeem_wearer", 10, ob);   
}

int heal_wearer(object ob) {
  if(!ob || !((status)this_object()->query_worn()))
    return 1;

  if(!is_time()) {
    call_out("heal_wearer", 200+random(150), ob);
    return 1;
  }
  
  tell_object(ob,
    "Your "+HIY+"Ankh of Light"+NORM+" flashes and you feel power flood your soul.\n");
  tell_room(ob,
    (string)ob->query_name()+"'s "+HIY+"Ahnk of Light"+NORM+" flashes.\n", ({ob}));
  ob->heal_self(35+random(26)); 
  OldTime = time();

  call_out("heal_wearer", 200+random(150), ob);
  return 1;
}    

int redeem_wearer(object ob) {
  if(!ob || !((status)this_object()->query_worn()))
    return 1;  
    
  if((int)ob->query_alignment() < 1000) {
    call_other(ob, "add_alignment", 50);
    if(!random(3)) {
      tell_object(ob,
        "Your "+HIY+"Ahnk of Light"+NORM+" begins to glow white hot.  You feel a holy\n"+
        "presence as it burns you with its blinding light.\n");
      tell_room(ob,
        (string)ob->query_name()+"'s "+HIY+"Ankh of Light"+NORM+
        "glows white hot.\n", ({ob}));
    }
  }
  
  call_out("redeem_wearer", 60+random(120), ob);
  return 1;        
  
}

void stop(object ob) {
  while(remove_call_out("heal_wearer") != -1);
  while(remove_call_out("redeem_wearer") != -1);  
}

int do_special(object owner) {
  if(this_player()) 
  if((int)this_player()->query_attrib("luc") > random(200)) {
    tell_object(owner,
      "You feel an angelic presence as your attacker's strike is deflected.\n");
    return 2;
  }
}

int do_evil_special(object owner) {
  if(this_player())
  if((int)this_player()->query_attrib("luc") > random(80)) {
    tell_object(owner,
      "Your "+HIY+"Ankh of Light"+NORM+" burns brightly.  An angelic host sings out\n"+
      "and evil shrinks back in both fear and awe.\n");
    tell_room(owner,
      (string)owner->query_name()+"'s "+HIY+"Ankh of Light"+NORM+" burns brightly and you hear an\n"+
      "angelic host sing out all around you.\n", ({owner}));
         return 0502;  /* 5% [05]02 resistance boost 2 05[02] ac boost */
  }
}

int do_dark_special(object owner) {
  if(this_player()) 
  if((int)this_player()->query_attrib("luc") > random(80)) {
    tell_object(owner,
      "A brilliant light bursts from your "+HIY+"Ankh of Light"+NORM+".  The dazzling\n"+
      "display demolishes the darkness about you.\n");
    tell_room(owner,
      "A brilliant light bursts forths from "+(string)owner->query_name()+
      "'s "+HIY+"Ankh of Light"+NORM+".  The dazzling\n"+
      "display demolishes the darkness about the area.\n", ({owner}));
         return 0502;  /* 5% [05]02 resistance boost 2 05[02] ac boost */
  }
}

string locker_arg() {
  return OldTime+"";
}

void locker_init(string arg) {
  sscanf(arg, "%d", OldTime);
}

generic_object() { return 1; } 

restore_thing(str) {
  restore_object(str);
  return 1;
}

save_thing(str) {
  save_object(str);
  return 1;
}

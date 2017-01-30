#include "/players/feldegast/defines.h"
inherit "/obj/treasure";

int worn;
int soul_energy;

int query_soul_energy() {
  return soul_energy;
}
int add_soul_energy(int arg) {
  return soul_energy+=arg;
}

short() {
  if(worn) return ::short()+" (worn)";
  else return ::short();
}

void reset(int arg) {
  set_id("soulcatcher");
  set_alias("medallion");
  set_short("A "+BOLD+BLK+"soulcatcher"+NORM);
  set_weight(1);
  set_value(1500);
  set_long(
"The soulcatcher is a strange looking symbol formed out of\n\
thick cast iron wire.  A circle surrounds a pentagram, inside\n\
of which is an inverted ankh with a bloodgem set into the\n\
loop.  A silver chain is looped through the circle so that\n\
it can be worn.\n");
}

void init() {
  if(!present(this_object(),TP)) return;
  add_action("cmd_wear","wear");
  add_action("cmd_remove","remove");
  if(present("secret_mage_guild_ob_name",TP)) {
    add_action("cmd_drain","soul_drain");
    add_action("cmd_drain","sd");
  }
}

int get() { 
  if(!TP) return 1;
  if(!present("secret_mage_guild_ob_name",TP) ||
     TP->query_level() < 10)
    call_out("curse",40-random((int)(TP->query_attrib("wil"))),TP);     
  return 1;
}
int drop() {
  while(remove_call_out("curse")!=-1) ;
  if(!TP) return 0;
  if(worn) {
    worn=!worn;
    write("You remove your medallion.\n");
  }
  return 0;
}
int cmd_wear(string str) {
  if(!str) return 0;
  if(!id(str)) return 0;
  if(!present(this_object(),TP)) return 0;
  write("You wear "+short()+".\n");
  say(TPN+" wears "+short()+".\n");
  worn=1;
  return 1;
}
int cmd_remove(string str) {
  if(!str) return 0;
  if(!id(str)) return 0;
  if(!present(this_object(),TP)) return 0;
  if(!worn) return 0;
  worn=0;
  write("You remove "+short()+".\n");
  say(TPN+" removes "+short()+".\n");
  return 1;
}
void curse(object targ) {
  int x;
  if(!present(this_object(),targ)) return;
  if(targ->query_attrib("pie") < random(30)) {
    tell_object(targ,"You feel a slight chill, as though a piece of your soul were\n"+
                     "being torn away.\n");
    x=random(20);
    if(targ->query_sp() > x)
      targ->add_spell_point(-x);
    else if(targ->query_hp() > x)
      targ->add_hit_point(-x);
    else targ->hit_player(x);
    soul_energy+=x/3;
  }
  call_out("curse",(40/(worn+1))-random((int)(targ->query_attrib("wil"))),targ);
}

cmd_drain(str) {
  object corpse;

  if(str) write("String is: "+str+".\n"); 
  if(!str)
    corpse=present("corpse",environment(TP));
  else corpse=present(str,environment(TP));

  if(!corpse) 
    if(str==0)
      corpse=present("corpse",TP);
    else corpse=present(str,TP);

  if(!corpse) {
    notify_fail("There is no corpse here.\n");
    return 0;
  }
  if(!corpse->id("corpse") ||
/* This isn't a 100% test, but it should work under most circumstances. */
     (!((int)corpse->heal_value()) && (int)corpse->query_weight()!=5)) {
    write("That is not a corpse.\n");
    return 1;
  }
  write("You hold your soulcatcher over the corpse of "+(string)corpse->query_name()+" and\n"+
        "utter a few guttural words.  A stream of bright light flows from the corpse\n"+
        "to the soulcatcher for a few minutes, and then leaves a dessicated husk\n"+
        "which floats away on the breeze.\n");
  say(TPN+"holds "+(string)TP->query_possessive()+" soulcatcher above the corpse of "+
       (string)corpse->query_name()+" and\n"+
      "drains it, leaving a dessicated husk which blows away.\n");
  soul_energy+=(int)corpse->heal_value();
  if(present(corpse,TP)) TP->add_weight(-((int)corpse->query_weight()));
  destruct(corpse);
  return 1;
}

inherit "obj/weapon.c";
#include "/players/illarion/dfns.h"

int accum_dam;
status deathblow_attempt;
string att_name;
object att_ob;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("axe");
  set_short("The "+HIR+"Axe"+NORM+" of Khorne");
  set_long(
"A truly evil weapon forged at the foot of the throne of skulls by captive\n"+
"wizards killed by Khorne's champions in the eonss of slaughter in his name.\n"+
"It's intricately carved hilt bears the rune of the blood god endlessly repeated\n"+
"over and over.  The double axe head is solid black with ghostly faces flickering\n"+
"on it's surface, the souls of those the weapons has already claimed. Contained\n"+
"within this weapon is the essence of a bloodthirster, a greater daemon of Khorne\n"+
"forever bound to the weapon it's howling cries for slaughter reverberate into your\n"+
"very soul.\n");
  set_class(25);
  set_weight(5);
  set_value(3000);
  set_hit_func(this_object());
  accum_dam=0;
}

status id(string str) {
  if(str == "notarmor" && (string)previous_object()->query_type() == "shield")
    return 1;
  return (status)::id(str);
}

status wield(string str) {
  object *inv;
  int x,s;
  if(!id(str))
    return 0;
  if(environment()!=TP)
    return 0;
  if(present("notweapon",this_player())) {
    write("For some reason you are unable to wield this weapon.\n");
    return 1;
  }
  if (wielded) {
    write("You already wield it!\n");
    return 1;
  }
  inv=all_inventory(TP);
  s=sizeof(inv);
  for(x=0;x<s;x++) {
    if((string)inv[x]->query_type() == "shield" && inv[x]->query_worn()) {
      write("You need both hands free for this weapon.\n");
      return 1;
    }
  }
  wielded_by = this_player();
  call_other(this_player(), "wield", this_object(), silentwield);
  wielded = 1;
  accum_dam=0;  
  return 1;
}


void make_head(string name) {
  object head;
  head=clone_object("/obj/treasure");
  head->set_id("head");
  head->set_short("The head of "+name+", taken by "+
     wielded_by->query_name());
  head->set_long(format(name+"'s head was obviously removed in"+
     "a brutal stroke by something massively sharp and deadly.\n"));
  head->set_weight(1);
  head->set_value(0);
  move_object(head,environment(wielded_by));
  return;
}


status query_wear() {
  return 0;
}
status count_misses() {
  if(deathblow_attempt) {
    tell_object(att_ob,format(wielded_by->query_name()+" misses the deathblow. "+
        "You feel renewed by the second chance!\n"));
    tell_object(wielded_by,format("Your swing goes wide, leaving "+att_name+
        " very much alive.  The axe shudders in disgust.\n"));
    say(wielded_by->query_name()+"'s deathblow goes wide!\n",({att_ob,wielded_by}));
    att_ob->heal_self(50);
    remove_call_out("deathblow_call");
    deathblow_attempt=0;
    accum_dam=0;
  }
  return 1;
}
status count_hit_made() {
  return 1;
}
status add_wear(int x) {
  return 0;
}
status weapon_breaks() { return 0; }
status re_break() { return 0; }

string *query_message_hit(int dam) {
  accum_dam+=dam;
  switch(dam) {
    default:     return ({" with a blinding slash","eradicated"});
    case 21..30: return ({" with quick slash","hacked"});
    case 16..20: return ({" opening a minor wound","chopped"});
    case 11..15: return ({" tearing some flesh","gashed"});
    case 6..10:  return ({" opening a small cut","slashed"});
    case 4..5:   return ({" barely cutting the skin","cleaved"});
    case 2..3:   return ({" with a weak slash","nicked"});
    case 1:      return ({" with a weak cut","grazed"});
  }
}


int weapon_hit(object att) {
  
  if(att->query_hp()<20) {
    write(format("You look at your defeated foe, and roar "+
        att->query_objective()+", \"BLOOD FOR THE BLOOD GOD!\"\n"+
        "You bring the axe down, at "+att->query_possessive()+" neck.\n"));
    say(format(wielded_by->query_name()+" roars, \"BLOOD FOR THE BLOOD GOD!\"\n"+
        "With a mighty strike, "+wielded_by->query_pronoun()+" swings at "+
        att->query_name()+"'s neck.\n"),({wielded_by,att}));
    tell_object(att,format(wielded_by->query_name()+" looks you right in "+
        "the eye, and roars, \"BLOOD FOR THE BLOOD GOD!\"\n"+
        wielded_by->query_possessive()+" axe descends toward your neck!\n"));
    att_name=(string)att->query_name();
    att_ob=att;
    deathblow_attempt=1;
    att->heal_self(-25);
    call_out("deathblow_call",0);
  }
 
  if(random(10)<3) {
    int wil;
    if(wielded_by->is_npc()) return 0;
    write("You feel a daemonic rage flow from the axe and into your\n"+
          "arms, guiding your strike with the skill of a Bloodthirster.\n");
          
    say(format("A flickering, daemonic figure appears, overlaying "+
      wielded_by->query_name()+"'s form, and guiding "+
      wielded_by->query_possessive()+" axe."));
    tell_room(environment(wielded_by),"\n"+
      ({HIG+"Warp Lightning"+NORM+" crackles along the axe's blade!",
        "A sheen of the coldest "+HIK+"chaos"+NORM+" coats the axe's edge!",
        "A wave of intense "+HIR+"rage"+NORM+" follows the axe's strike!",
        "An aura of "+RED+"bloodlust"+NORM+" surrounds the axe's blade!",
      })[random(4)]+"\n\n");
    wil=(int)wielded_by->query_attrib("wil");
    wil/=4; 
    return 4+random(wil+1);
  }
}


void deathblow_call() {
  if(!att_ob) {
    tell_room(environment(wielded_by),att_name+"'s head drops to the ground.\n");
    if(accum_dam>250) 
      accum_dam=250;
    wielded_by->add_spell_point(accum_dam/5);
    if(accum_dam>=5)
      write("Energy flows into you from your axe's hilt!\n");
    accum_dam=0;
    make_head(att_name);
  }
  deathblow_attempt=0;
}

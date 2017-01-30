#include "/players/pavlik/closed/colors.h"
inherit "obj/weapon.c";
#define ST "Strident ("+HIR+wepstatus[statnum]+NORM+")"
#define ME capitalize(this_player()->query_name())
#define IT capitalize(attacker->query_name())

string *wepstatus;
int statnum;
int statcount;

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("the Strident");
  set_alias("strident");
  set_alt_name("inferno");
  set_short("the Strident");
  set_long(
    "The Strident is a wicked two-pronged Trident.  The prongs end\n"+
    "in barbed points that crackle with blue flames.  The Strident's\n"+
    "long handle glows with heat, but it does not feel warm to the\n"+
    "touch.  Every now and then a jet of blue flame erupts from the\n"+
    "dangerously sharp prongs.\n");
  set_type("trident");
  set_class(17);
  set_weight(4);
  set_value(1000);
  set_no_clean(1);
  set_save_flag(1);
  set_hit_func(this_object());
  statnum = 4;
  statcount = 0;

  wepstatus = ({
    "smoking",
    "smoldering",
    "Burning",
    "BlaZinG",
    "iNFeRnO",
  });

  message_hit = ({
    HIR+"BURIED"+NORM+" the sharp prongs "+HIR+"deeply"+NORM+" into the body of", "",
    BLU+"GOUGED"+NORM+" the flesh from", "",
    HIB+"GUTTED"+NORM, " with the "+HIR+"wicked"+NORM+" Strident",
    HIR+"gashed"+NORM, "",
    HIB+"wounded"+NORM, " seriously",
    HIB+"poked"+NORM, " with the "+HIR+"barbed prongs"+NORM+" of the Strident"+NORM,
    HIB+"prodded"+NORM, " lightly",
  });

}

short() {
  string tmp_short;
  short_desc = ST;

  if(call_other(this_player(), "query_level", 0) > 30) {
    tmp_short = short_desc + "  < wc " + class_of_weapon + ","+eff_wc + " >";
    if(broke) tmp_short = short_desc + " [BROKEN]";
    if(wielded)
       return tmp_short + " (wielded)";
    return tmp_short;
  }
  if(wielded && broke) return short_desc + " [BROKEN] (wielded)";
  if(broke) return short_desc + " [BROKEN]";
  if(wielded)
     if(short_desc)
        return short_desc + " (wielded)";
  return short_desc;
}

query_name(){ return ST; }

weapon_hit(attacker){
  int dmg;

  /* if weapstatus is Inferno (highest) */
  if(statnum == 4) {
    tell_room(environment(this_player()), "\n"+
    "An "+HIR+"<< INFERNO >>"+HIB+" of blue flames"+NORM+" erupts from the Strident's prongs!\n"+
    IT+" is completely "+HIR+"ENGULFED"+NORM+" in flames!\n"+
    IT+"'s entire body seems about to "+RED+"combust instantly!\n\n"+NORM);
    attacker->hit_player(random(15));
    statnum = 0;
    dmg = 7;
  }

  else if(statnum == 3 && statcount == 0) {
    write(
    HIB+"Blue Flames"+NORM+" burst from the tip of your weapon!\n"+
    "The "+RED+"blistering heat"+HIR+" scorches "+NORM+IT+"'s flesh!\n");
    say(
    HIB+"Blue Flames"+NORM+" burst from the tip of "+ME+"'s weapon!\n"+
    "The "+RED+"blistering heat"+HIR+" scorches "+NORM+IT+"'s flesh!\n");
    dmg = 4;
  }

  else if(statnum == 2 && statcount == 0) {
    write("Small blue flames appear around the barbed prongs of your Strident.\n");
    say("Small blue flames appear around the barbed prongs of "+ME+"'s Strident.\n");
    dmg = 2;
  }

  else if(statnum == 1 && statcount == 0) {
    write("Curls of smoke rise from the end of your dangerous weapon.\n");
    say("Curls of smoke rise from the tip of "+ME+"'s dangerous weapon.\n");
    dmg = 0;
  }

  else if(statnum == 0) {
    if(statcount == 2) {
      tell_room(environment(this_player()),
      "The "+HIR+"inferno"+NORM+" burns out and disappears.\n");
      dmg = 0;
    }
    else {
      tell_room(environment(this_player()),
      "The "+HIW+"raging "+HIR+"inferno"+NORM+" continues to "+HIR+
      "burn"+NORM+" around "+IT+".\n");
      dmg = random(6);
    }
  }

  statcount++;

  /* power level can only change on every 3rd hit */
  if(statcount == 3) {
    statcount = 0;
    /* 66% chance for the power level to increase */
    if(random(3)) {
      statnum++;
    }
  }

  return dmg;
}


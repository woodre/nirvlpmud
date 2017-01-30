/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     Weapon
 *  Create Date:  2002.06.24
 *  Last Edit:    2006.05.25 - Fred
 *  Notes:        WC 19, weight 3, type 'axe'
 *                10% return of 3+random(3), 10% return of 2+random(2), 
 *                20% return of 1+random(2)
 *                Has added benefit of 'cleaving' corpses , with the
 *                following effects:
 *                  1.  15% chance of splitting the corpse into three, 
 *                      with a one-third corpse_level loss.
 *                  2.  70% chance of splitting a corpse into two with 
 *                      no corpse_level loss.
 *                  3.  15% chance of destroying the corpse completely.     
 *  Notable Changes:
 *    2004.06.04 - Sizeable recode
 *    2005.04.18 - Blocked wielding with shield and dual wielding
 *               - Upped specials to:  10% return 5 + -heal_shelf, 10% return 5, 
 *                 20% return 4 -- It's a difficult weapon to get!
 *    2006.05.25 - Added a simple two_handed() check for bf swap cmd.
 *                 Fred
 */

#include "/players/forbin/realms/salam/salamdefine.h"
inherit "obj/weapon.c";

id(str) { return ::id(str) || str == "waraxe" || str == "axe" || str == "neruumsh the waraxe"; }

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("neruumsh");
  set_short(RED+"Neruumsh"+NORM+" the Waraxe");
  set_long(
    "  This is the legendary waraxe known as Neruumsh.  The short wooden\n"+ 
    "shaft allows for its use in tight quarters, while the large blade\n"+ 
    "squares off with the end of the handle and curves down to a sharp\n"+ 
    "point.  The 13-inch blade smoothly runs razor-sharp almost 7 inches\n"+ 
    "before changing into a crude, serrated edge.  There are tales that\n"+ 
    "say it is strong enough to cleave bodies.\n");
  set_type("axe");
  set_class(19);
  set_weight(3);
  set_value(5000);
  set_buy_value(20000 + random(10001));
  set_hit_func(this_object());
}

init() {
  ::init();
  add_action("cmd_cleave","cleave");
}

/* 
 *  ***********************************************************************
 *  Function:    wield / query_offwielded 
 *  Description: made wielding with a shield impossible and blocked
 *               dual wielding
 *  ***********************************************************************
 */

int query_offwielded() { return wielded; }

status wield(string str) {
  object *inv;
  int x,s;
  if(!id(str))
    return 0;
  if(environment() != this_player())
    return 0;
  if(present("notweapon", this_player())) {
    write("For some reason you are unable to wield this weapon.\n");
    return 1;
  }
  if(wielded) {
    write("You already wield it!\n");
    return 1;
  }
  inv = all_inventory(this_player());
  s = sizeof(inv);
  for(x=0; x<s; x++) {
    if((string)inv[x]->query_type() == "shield" && inv[x]->query_worn()) {
      write("You need both hands free for this weapon.\n");
      return 1;
    }
  }
  wielded_by = this_player();
  call_other(this_player(), "wield", this_object(), silentwield);
  wielded = 1;
  return 1; 
}


/* 
 *  ***********************************************************************
 *  Function:    weapon_hit 
 *  Description: special weapon hits and messages
 *  Arguments:   attacker
 *  ***********************************************************************
 */

weapon_hit(attacker) {
  string u_do_what, r_do_what, wep_hit, where_hit, what_hap, hit_type;

  u_do_what = ({"leap forward","rush ahead","quickly spin to your right", 
                "quickly spin to your left","deftly slide to your right", 
                "deftly slide to your left","charge ahead"});
  r_do_what = ({"leaps forward","rushes ahead","quickly spins to "+TPP+" right", 
                "quickly spins to "+TPP+" left","deftly slides to "+TPP+" right",
                "deftly slides to "+TPP+" left","charges ahead"});
  wep_hit =   ({"smashing","slashing","cleaving","hacking",HIR+"DESTROYING"+NORM});
  where_hit = ({"head","chest","right side","left side","neck","chest","arm",
                "leg","stomach","chest","back","chest"});
  what_hap =  ({"staggered","stunned","shocked","angered","blasted back","knocked down" });
  hit_type =  ({"blow","strike","hit","attack"});

  switch(random(10)) {
    case 0:
      write("\n"+
            "You bring "+RED+"Neruumsh"+NORM+" high above your head,\n"+
            "then bring it crashing down with a loud\n"+
            "     "+HIY+""+BLINK+">< >< ><"+NORM+" "+HIR+"C R U N C H"+NORM+" "+HIY+""+BLINK+">< >< ><"+NORM+"\n"+
            ""+attacker->query_name()+" is dropped to their knees from the blow.\n\n");
      say("\n"+
          TPN+" brings "+RED+"Neruumsh"+NORM+" high above "+TPP+" head,\n"+
          "then brings it crashing down with a loud\n"+
          "     "+HIY+""+BLINK+">< >< ><"+NORM+" "+HIR+"C R U N C H"+NORM+" "+HIY+""+BLINK+">< >< ><"+NORM+"\n");
      say(""+attacker->query_name()+" is dropped to their knees from the blow.\n\n");
        attacker->heal_self(-(4+random(4)));
        return 5;
      break;
    case 1..2:
      write("\n"+
            "You "+u_do_what[random(sizeof(u_do_what))]+", "+wep_hit[random(sizeof(wep_hit))]+" "+attacker->query_name()+" in the "+where_hit[random(sizeof(where_hit))]+".\n"+
            ""+attacker->query_name()+" is "+what_hap[random(sizeof(what_hap))]+" by your "+hit_type[random(sizeof(hit_type))]+".\n\n");
      say("\n"+
          TPN+" "+r_do_what[random(sizeof(r_do_what))]+", "+wep_hit[random(sizeof(wep_hit))]+" "+attacker->query_name()+" in the "+where_hit[random(sizeof(where_hit))]+".\n"+
          ""+attacker->query_name()+" is "+what_hap[random(sizeof(what_hap))]+" by "+TPP+" "+hit_type[random(sizeof(hit_type))]+".\n\n");
        return 0;
      break;
    case 3..4:
      write("\n"+
            "You "+u_do_what[random(sizeof(u_do_what))]+", "+wep_hit[random(sizeof(wep_hit))]+" "+attacker->query_name()+" in the "+where_hit[random(sizeof(where_hit))]+".\n"+
            ""+attacker->query_name()+" is "+what_hap[random(sizeof(what_hap))]+" by your "+hit_type[random(sizeof(hit_type))]+".\n\n");
      say("\n"+
          TPN+" "+r_do_what[random(sizeof(r_do_what))]+", "+wep_hit[random(sizeof(wep_hit))]+" "+attacker->query_name()+" in the "+where_hit[random(sizeof(where_hit))]+".\n"+
          ""+attacker->query_name()+" is "+what_hap[random(sizeof(what_hap))]+" by "+TPP+" "+hit_type[random(sizeof(hit_type))]+".\n\n");
        return 4;
      break;
    case 5:
      write("\n"+
            "You "+u_do_what[random(sizeof(u_do_what))]+", "+wep_hit[random(sizeof(wep_hit))]+" "+attacker->query_name()+" in the "+where_hit[random(sizeof(where_hit))]+".\n"+
            ""+attacker->query_name()+" is "+what_hap[random(sizeof(what_hap))]+" by your "+hit_type[random(sizeof(hit_type))]+".\n\n");
      say("\n"+
          TPN+" "+r_do_what[random(sizeof(r_do_what))]+", "+wep_hit[random(sizeof(wep_hit))]+" "+attacker->query_name()+" in the "+where_hit[random(sizeof(where_hit))]+".\n"+
          ""+attacker->query_name()+" is "+what_hap[random(sizeof(what_hap))]+" by "+TPP+" "+hit_type[random(sizeof(hit_type))]+".\n\n");
        return 5;
      break;
    case 6..9: return 0; break;
  }
}

/* 
 *  ***********************************************************************
 *  Function:    cmd_cleave 
 *  Description: splits corpses into parts:
 *                 1. 15% chance of splitting the corpse into three, with a 
 *                    one-third corpse_level loss.
 *                 2.  70% chance of splitting a corpse into two with no 
 *                     corpse_level loss.
 *                 3.  15% chance of destroying the corpse completely.
 *  Arguments:   string str, where str is target to cleave 
 *               (the target object must be /obj/corpse.c)
 *  ***********************************************************************
 */

cmd_cleave(string str) {
  object ob, one, two, three;
  string a, b;
  string r_how, r_where_u, r_where_r, r_force, s_how;
  int number;
  number = random(100);

  r_how =     ({"raise","jerk","hoist","heave"});
  r_where_u = ({"high above your head","high into the air"});
  r_where_r = ({"high above "+TPP+" head","high into the air"});
  r_force =   ({"forcefully","quickly","powerfully","mightily","effectively"});
  s_how =     ({"hack","split","cleave","divide","crack","break",
                "separate","partition","carve"});

  if(!TO->query_wielded()) { notify_fail("You must be wielding the weapon to use it!\n"); return 0; }
  if(!str) { notify_fail("What would you like to cleave?  Usage: cleave corpse.\n"); return 0; }
  ob = present(str, environment(this_player()));
  if(!ob) { notify_fail("That is not here!\n"); return 0; }
  if(ob->query_info() == "cleaved_corpse") { notify_fail("You have already split this corpse!\n"); return 0; }
  if(ob->query_preserved()) { notify_fail("There is no use splitting a preserved corpse!\n"); return 0; }
  if(!ob->query_corpse_level()) { notify_fail("You may not cleave that with this tool!\n"); return 0; }
  if(number > 75) {
    one = clone_object("obj/corpse.c");
    one->set_info("cleaved_corpse");
    one->set_name(ob->query_name());
    one->set_level(ob->query_corpse_level()*2/3);
    one->set_exp_worth( ob->query_exp_worth()*2/4 );
    one->set_long("This is part of the body of "+capitalize(ob->query_name())+"\n");
    two = clone_object("obj/corpse.c");
    two->set_info("cleaved_corpse");
    two->set_name(ob->query_name());
    two->set_level(ob->query_corpse_level()*2/3);
    two->set_exp_worth( ob->query_exp_worth()*2/4 );
    two->set_long("This is part of the body of "+capitalize(ob->query_name())+"\n");    
    three = clone_object("obj/corpse.c");
    three->set_info("cleaved_corpse");
    three->set_name(ob->query_name());
    three->set_level(ob->query_corpse_level()*2/3);
    three->set_exp_worth( ob->query_exp_worth()*2/4 );
    three->set_long("This is part of the body of "+capitalize(ob->query_name())+"\n");    
    if(!present("neruumsh_axe_splatter", this_player())) { move_object(clone_object(ROOT+"OBJ/axe_splatter.c"), this_player()); }
    destruct(ob);
    move_object(one, environment(this_player()));
    move_object(two, environment(this_player()));
    move_object(three, environment(this_player()));
    write("You "+r_how[random(sizeof(r_how))]+" "+RED+"Neruumsh"+NORM+" "+r_where_u[random(sizeof(r_where_u))]+", then bring it\n"+
          "down "+r_force[random(sizeof(r_force))]+" to "+s_how[random(sizeof(s_how))]+" the corpse into several pieces.\n"+
          "Blood, bone, and sinew splatter all over you.\n");
    say(TPN+" "+r_how[random(sizeof(r_how))]+"s "+RED+"Neruumsh"+NORM+" "+r_where_r[random(sizeof(r_where_r))]+", then brings it\n"+
        "down "+r_force[random(sizeof(r_force))]+" to "+s_how[random(sizeof(s_how))]+" the corpse into several pieces.\n"+
        "Blood, bone, and sinew splatter all over "+this_player()->query_objective()+"self.\n");
      return 1;
  }
  else if(number > 15) {
    one = clone_object("obj/corpse.c");
    one->set_info("cleaved_corpse");
    one->set_name(ob->query_name());
    one->set_level(ob->query_corpse_level());
    one->set_exp_worth( ob->query_exp_worth()*2/4 );
    one->set_long("This is part of the body of "+capitalize(ob->query_name())+"\n");
    two = clone_object("obj/corpse.c");
    two->set_info("cleaved_corpse");
    two->set_name(ob->query_name());
    two->set_level(ob->query_corpse_level());
    two->set_exp_worth( ob->query_exp_worth()*2/4 );
    two->set_long("This is part of the body of "+capitalize(ob->query_name())+"\n");    
    if(!present("neruumsh_axe_splatter", this_player())) { move_object(clone_object(ROOT+"OBJ/axe_splatter.c"), this_player()); }
    destruct(ob);
    move_object(one, environment(this_player()));
    move_object(two, environment(this_player()));
    write("You "+r_how[random(sizeof(r_how))]+" "+RED+"Neruumsh"+NORM+" "+r_where_u[random(sizeof(r_where_u))]+", then bring it\n"+
          "down "+r_force[random(sizeof(r_force))]+" to "+s_how[random(sizeof(s_how))]+" the corpse into two pieces.\n"+
          "Blood, bone, and sinew splatter all over you.\n");
    say(TPN+" "+r_how[random(sizeof(r_how))]+"s "+RED+"Neruumsh"+NORM+" "+r_where_r[random(sizeof(r_where_r))]+", then brings it\n"+
        "down "+r_force[random(sizeof(r_force))]+" to "+s_how[random(sizeof(s_how))]+" the corpse into two pieces.\n"+
        "Blood, bone, and sinew splatter all over "+this_player()->query_objective()+"self.\n");
      return 1;

  }
  else {
    if(!present("neruumsh_axe_splatter", this_player())) { move_object(clone_object(ROOT+"OBJ/axe_splatter.c"), this_player()); }
    destruct(ob);
    write("You "+r_how[random(sizeof(r_how))]+" "+RED+"Neruumsh"+NORM+" "+r_where_u[random(sizeof(r_where_u))]+", then bring it\n"+
          "down "+r_force[random(sizeof(r_force))]+" to "+s_how[random(sizeof(s_how))]+" the corpse, obliterating it!\n"+
          "Blood, bone, and sinew splatter all over you.\n");
    say(TPN+" "+r_how[random(sizeof(r_how))]+"s "+RED+"Neruumsh"+NORM+" "+r_where_r[random(sizeof(r_where_r))]+", then brings it\n"+
        "down "+r_force[random(sizeof(r_force))]+" to "+s_how[random(sizeof(s_how))]+" the corpse, obliterating it!\n"+
        "Blood, bone, and sinew splatter all over "+this_player()->query_objective()+"self.\n");
      return 1;
  }
}

two_handed(){ return 1; }

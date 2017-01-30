/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        None
//  Function:     Weapon
//  Create Date:  2004.09.28
//  Last Edit:    2004.09.28 -Forbin
//  Notes:        Special prize weapon for weekly experience contest
//                WC 17, weight 6, type 'club'
//                -special bonuses against most mobs with std. spell attacks
//                -glows when monster in the room has a std. spell attack
//                -special decorpsing ability (heals hp only)
*/

#include "/players/forbin/define.h"

inherit "players/maledicta/weapon/weapon.c";

#define WEPNAME HIW+"M"+HIC+"age "+HIW+"M"+HIC+"asher"+NORM
#define DEBUG

int MFlag;   /* mage present flag */
int Glowing; /* is sword glowing? */

id(string str) { return (::id(str) || str == "masher" || str == "prize" ||
                                      str == "morning star" ||
                                      str == "morningstar" || str == "star"); }

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("mage masher");
  set_short(WEPNAME);
  set_hit_func(this_object());
  set_type("club");  
  set_class(17);
  set_weight(6);
  set_value(200000);
  set_two_handed_wep(1);
  MFlag = 0;
  Glowing = 0;
  call_out("mage_find", 3);
}

short() {
	string tmp_short;
  if(this_player())
	  if(this_player()->query_level() > 30) {
		  tmp_short = short_desc + "  < wc " + class_of_weapon + ","+eff_wc + " >";
      if(Glowing) tmp_short += HIW+" <<"+HIC+"glowing"+HIW+">>"+NORM;
		  if(broke) tmp_short += " [BROKEN]";
		  if(wielded) tmp_short += " (wielded";
		  if(wielded && two_handed_wep && two_handed_wield) tmp_short += " in both hands)";
		  else if(wielded) tmp_short += ")";
		  return tmp_short;
	  }
	tmp_short = short_desc;
  if(Glowing) tmp_short += HIW+" <<"+HIC+"glowing"+HIW+">>"+NORM;	
	if(broke) tmp_short += " [BROKEN]";
	if(wielded) tmp_short += " (wielded";
	if(wielded && two_handed_wep && two_handed_wield) tmp_short += " in both hands)";
	else if(wielded) tmp_short += ")";
	return tmp_short;
}

long() { 
  int wear;
  write(
    "This is what the "+WEPNAME+" looks like.  Right now it's a rather\n"+
    "bland holding description that will be changed whenever I figure out\n"+
    "what the fuck this thing looks like.  Don't forget you can 'shatter'\n"+
    "corpses for a slight heal.\n"+
    "Rather large and heavy, it may be used one or two handed weapon.\n"+
	  "You may 'wield <wep>' or 'wield <wep> with both hands'\n");    
	write("It is ");
	wear = query_wear();
	if(wear < 40) write("like new.\n");
	if(wear > 39 && wear < 100) write("a little worn.\n");
	if(wear > 99 && wear < 200) write("somewhat worn.\n");
	if(wear > 199 && wear < 400) write("worn.\n");
	if(wear > 399) write("well worn.\n");
	if(this_player()->query_level() >= 100) { 
  	write("Wear = "+wear+"\n");
		write("Hits = "+hits+"    Misses = "+misses+"\n");
	}
  return 1;
}

init() {
  ::init();
  add_action("cmd_decorpse", "shatter");
}

status cmd_decorpse(string str) {
  object corpse;
  int value;
  string one;
        
  if(this_player()->query_ghost()) return 0;
  if(!str) {
    write("Shatter what?\n");
    return 1;
  }
  if(str != "corpse") {
    write("It would do no good to shatter the "+str+".\n");
    return 1; 
  }
  if(!this_object()->query_wielded()) {
    write("You must be wielding "+WEPNAME+" to shatter corpses.\n");
    return 1;
  }
  corpse = present("corpse", environment(this_player()));
  if(!corpse) {
    write("There is no corpse.\n");
    return 1;
  }
  if(corpse->query_corpse_level() < 1) {
    write("It would be useless to shatter that.\n");
    return 1;
  }
  if(sscanf(file_name(corpse), "obj/corpse%s", one)!=1) return 1;
  tell_object(environment(this_object()),
    "You swing your "+WEPNAME+" over your head before crashing it down\n"+
    "onto a coprse.  A strange "+(random(2) ? HIC+"blue"+NORM : HIW+"white"+NORM)+
    " mist floats up and flows\ninto your body.  You feel refreshed.\n");
  tell_room(environment(this_object()),
    this_player()->query_name()+" swings "+this_player()->query_possessive()+
    " "+WEPNAME+" over "+this_player()->query_possessive()+" head\n"+
    "before crashing it down onto a coprse.\n"+
    "A strange "+(random(2) ? HIC+"blue"+NORM : HIW+"white"+NORM)+
    " mist floats up and flows\ninto "+
    this_player()->query_name()+".\n", ({ environment(this_object()) }) );
  value = ((int)corpse->query_corpse_level() * (1 + random(2)));
  this_player()->add_hit_point(((value * 2) / 3) + random(((value * 2) / 3)));
  corpse->set_corpse_level(0);
  corpse->add_decay(-90);
  corpse->set_short("A pile of gore");
  corpse->set_long("A large pile of shattered bones and bloody gore that is so\n"+
                   "disfigured it's hard tell exactly what it was before.\n");
  corpse->add_id("gore");
  return 1;
}
        
int query_wear() {
  int wear;
  wear = (((4 * misses) / 5) + ((2 * hits) / 13));
  return wear;
}

string get_where(int num) {
  string where;
  switch(num) {
    case 0: where = "chest"; break; 
    case 1: where = "leg"; break;
    case 2: where = "arm"; break; 
    case 3: where = "neck"; break; 
    case 4: where = "ribs"; break; 
    case 5: where = "chest"; break; 
    case 6: where = "stomach"; break;
  }
  return where;
}

string get_how(int num) {
  string how;
  switch(num) {
    case 0: how = "smashing"; break; 
    case 1: how = "staggering"; break; 
    case 2: how = "bashing"; break;
    case 3: how = "gouging"; break; 
    case 4: how = "crushing"; break; 
    case 5: how = "devastating"; break;
    case 6: how = "slaughtering"; break; 
  }
  return how;
}

status mage_check(object ob) {
#ifdef DEBUG      
  dmsg("mm", "mage_check called: "+(string)ob->query_name());
if(ob->query_spells() || ob->query_spell_chance()) {
  dmsg("mm", (string)ob->query_name()+" has spells");
}
else { 
  dmsg("mm", (string)ob->query_name()+" does not have spells");
}
#endif  
  if(ob->query_spells() || ob->query_spell_chance()) 
    return 1;
  else 
    return 0;
} 

mixed hit(object attacker) { /* Bonus of 1 - 4 (avg 2) for wielding with two hands */
  int bonus;    /* based on max dexterity stat */
  if(hit_func)
      return call_other(hit_func,"weapon_hit",attacker);
	if(two_handed_wield && two_handed_wep)
	  bonus = 1 + random((int)environment()->query_attrib("dex") / 8);
#ifdef DEBUG
  dmsg("mm", HIB+"HIT RETURN BONUS:"+NORM+" "+bonus);	  
#endif 
  return bonus;
}

int weapon_hit(object attacker) { /* Bonus of 1 - 4 (avg 2) for wielding with two hands */
  int bonus;           /* based on max dexterity stat */
  int y, z;
  object ob, ench;
  y = random(7); 
  z = random(7);
  if(two_handed_wield && two_handed_wep)
	  bonus = 1 + random((int)environment()->query_attrib("dex") / 8);  
  if((two_handed_wield && two_handed_wep && !random(7)) || !random(10)) {
  	tell_object(environment(this_object()),
  	  "You twirl "+WEPNAME+" over you head before launching into "+attacker->query_name()+
  	  "'s\n "+get_where(y)+" with a "+get_how(z)+" blow.\n"); 
  	tell_room(environment(environment(this_object())),
      this_player()->query_name()+" twirls "+WEPNAME+" over "+this_player()->query_possessive()+
  	  " head before launching into "+attacker->query_name()+"'s\n"+
  	  get_where(y)+" with a "+get_how(z)+" blow.\n", ({ environment(this_object()) }) );
    	bonus += (1 + random(3));
    if(mage_check(attacker)) {
      tell_room(environment(environment(this_object())),
        "\n\tThere is a clap of thunder and a flash of light as\n"+
        "\n     "+attacker->query_name()+" is blasted by magical energies.\n\n");
      ob = present("mm_obj", attacker); 
      if(!ob) {
        ench = clone_object("/players/forbin/closed/OBJ/mm_obj.c");
        ench->set(attacker);
        move_object(ench, attacker);
      }
      else ob->strengthen(1+random(3));
    }
  }
  if((two_handed_wield && two_handed_wep && !random(4)) || !random(6)) {
    tell_room(environment(environment(this_object())),
      "SECOND SMALL ATTACK\n\n");    	
    bonus += random(3);
    if(mage_check(attacker)) {
      tell_room(environment(environment(this_object())),
        "\n\tThere is a clap of thunder and a flash of light as\n"+
        "\n     "+attacker->query_name()+" is blasted by magical energies.\n\n");
      ob = present("mm_obj", attacker); 
      if(ob) ob->strengthen(1);
      else {
        attacker->hit_player(1, "magical"); 
        attacker->hit_player(1, "other|mental"); 
      }
    }
  }
#ifdef DEBUG
  dmsg("mm", HIR+"WEAPON_HIT RETURN BONUS:"+NORM+" "+bonus);	  
#endif
  return bonus;
}

mage_find() {
  object *inv;  /* array of room inventory */
  object room;  /* environment() */
  object ob;    /* target object */
  int x, soi;   /* count variable, size of *inv */
  int tflag;    /* temporary MFlag holder */
  string gmsg;  /* message when it's glowing */
  string rgmsg; /* room message when it's glowing */
  if(!environment()) return;
  if(living(environment()))
    room = environment(environment(this_object()));
  else
    room = environment(this_object());
  inv = all_inventory(room);
  soi = sizeof(inv);
  for(x = 0; x < soi; x++) {
    ob = inv[x];
    if(living(ob)) {
      if(!ob->is_pet() || !ob->is_player()) {
        if(ob->query_spells() || ob->query_spell_chance()) {
          tflag = 1;
          break;
        }
      }
    }
  }
  if(tflag) 
    MFlag = 1;
  else 
    MFlag = 0;
  if(!MFlag && Glowing) {
    tell_room(room,
      "The glowing aura around "+WEPNAME+" fades.\n");
    Glowing = 0;    
    call_out("mage_find", 3);
    return 1;
  }
  if(!MFlag && !Glowing) {
    call_out("mage_find", 3);
    return 1;
  }  
  if(MFlag && !Glowing) {
    tell_room(room,
      WEPNAME+" begins to "+HIC+"glow"+NORM+" a pale blue.\n");
    Glowing = 1;
  }
  if(random(20)) {
    switch(random(10)) {
      case 0: gmsg = WEPNAME+" quivers slightly in your hand\n";
              rgmsg = "";
              break;
      case 1..09: gmsg = "";
              rgmsg = "";
              break;
    }
    if(gmsg) 
      tell_object(environment(this_object()), 
        (random(2) ? HIC+gmsg+NORM : HIW+gmsg+NORM));
    if(rgmsg) 
      tell_room(environment(this_object()), 
        (random(2) ? HIC+rgmsg+NORM : HIW+rgmsg+NORM), 
        ({ environment(this_object()) }) );    
  }
  call_out("mage_find", 3);
}
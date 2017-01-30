inherit "obj/armor";
int aa_ammo;

/*	hehehe I love this code :) */

query_save_flag() { return 1; }

reset(arg) {
::reset(arg);
if(arg) return;
  write("[Spucksuit]: Beginning initialization sequence... please wait...\n");
  set_name("spucksuit");
  set_short("A Super Spucksuit");
  set_long("This is the result of the marriage between technology and the\n"+
  "unexplainable powers of ether-world elements. The cybernetic computer\n"+
  "control system of the modern world is joined with the inherently\n"+
  "indestructable suit of armor composed of 'Spuckstuff' to form a battle\n"+
  "suit that really kicks ass.  :)\n"+
  "\n"+"[Spucksuit]: The help screen is 'spuckhelp'.\n"); 
  set_value(400000);
  set_ac(4);
  set_type("armor");
  set_alias("suit");
  aa_ammo=30;
  call_out("boot_blah", 8);
}

init() {
  ::init();
  add_action("area_attack","spuckstorm");
  add_action("zok_critter","zok");
  add_action("recharge_suit","charge");
  add_action("recharge_player","harmonize");
  add_action("status_suit","query");
  add_action("run_muthafucka","spucksave");
  add_action("help_screen_doh","spuckhelp");
}

help_screen_doh(str) {
  write("[Spucksuit]: Printing command list:\n\n"+
  "'spuckhelp'         This screen.\n"+
  "'charge suit'       Recharges the suit provided Spuckball tubes are handy.\n"+
  "'harmonize <plyr>'  Heals yourself or another player slightly.\n"+
  "                    'harmonize' with no argument will heal self.\n"+
  "'query'             Displays the amount of Spuckballs charged into the suit.\n"+
  "'spucksave'            Attempts teleport to the church.\n"+
  "'spuckstorm'        Initializes an area attack combat sequence.\n"+
  "'zok <monster>'     Attacks a monster with a Spuckball blast.\n");
  write("There are ["+aa_ammo+"] charges remaining in the suit.\n");
  return 1;
}

status_suit() {
  write("[Spucksuit]: There are ["+aa_ammo+"] SpuckCharges remaining.\n");
  return 1;
}

recharge_suit(str) {
  object ammo;
  if(!str) return 0;
  if(str == "suit"){
    if(!this_object()->query_worn()) {
      write("[Spucksuit]: System error: The suit must be worn to initiate command.\n");
      return 1;
    }
    ammo=present("spuckballs",this_player());
      if(!ammo) {
        write("You don't have any Spuckball tubes.\n");
        return 1;
      } 
      move_object(ammo, this_object()); 
      aa_ammo=aa_ammo+10;
      write("[Spucksuit]: Spuckball absorption completed. There are ["+aa_ammo+"] SpuckCharges.\n");
      say("You see a tube of Spuckballs get absorbed into "+capitalize(this_player()->query_name()) + "'s Spucksuit.\n");
      return 1;
  }
 return 0;
}

recharge_player(arg) {
  object ob;
  int i;
  if(!this_object()->query_worn()) {
    write("[Spucksuit]: System error: The suit must be worn to initiate command.\n");
    return 1;
  }
  if(!arg) {
    i=aa_ammo-10;
      if(i == 0 || i < 0) {
         write("[Spucksuit]: System error: SpuckCharge reserves insufficent or depleted.\n"+
	       "[10] SpuckCharges required for current procedure.\n");
         return 1;
      }
      write("[Spucksuit]: Executing energy transfer sequence... please wait...\n");
      call_out("recharge_delay", 4);
      return 1;
    }
  ob=find_player(arg);
    if(!ob) {
      write("[Spucksuit]: Tracking error: Playername '"+arg+"' not located.\n");
      return 1;
    }
    if(!present(environment(this_player()), ob)) {
      write("[Spucksuit]: Tracking error: Playername '"+arg+"' is out of range.\n");
      return 1;
    }
  write("[Spucksuit]: Localized energy transfer initialized and completed.\n");
  write("             Summary: [10] SpuckCharges transferred to "+capitalize(this_player()->query_name())+".\n");
  ob->heal_self(33);
  aa_ammo=aa_ammo-10;
  tell_object(ob, capitalize(this_player()->query_name())+" has healed you 30 HP/SP.\n");
  say(capitalize(this_player()->query_name())+" starts to glow and touches "+capitalize(ob->query_name())+".\n");
  return 1;
}

zok_critter(arg) {
  object ob;
  int i;
    if(!this_object()->query_worn()) {
      write("[Spucksuit]: System error: The suit must be worn to initiate command.\n");
      return 1;
    }
    if(!arg) {
      write("[Spucksuit]: System error: No target specified. Attack aborted.\n");
      return 1;
    }
  i=aa_ammo-2;
    if(i == 0 || i < 0) {
       write("[Spucksuit]: System error: SpuckCharge reserves insufficent or depleted.\n"+
       "[2] SpuckCharges required for current procedure.\n");
       return 1;
    }
  ob=find_living(arg);
    if(!ob) {
      write("[Spucksuit]: Tracking error: TargetName '"+arg+"' not located.\n");
      return 1;
    }
	if(!present(ob, environment(this_player()))) {
      write("[Spucksuit]: Tracking error: TargetName '"+arg+"' is out of range.\n");
      return 1;
    }
    if((ob->query_npc()) != 1) {
      write("[Spucksuit]: Tracking error: Program prohibits player attack.\n");
      return 1;
    }
  aa_ammo=aa_ammo-2;
  ob->hit_player(10+random(10));
  ob->attack_object(this_player());
  write("[Spucksuit]: Engaging selected target.\n");
  write("A highly charged Spuckball shoots out and screams death at "+capitalize(ob->query_name())+".\n");
  say(capitalize(this_player()->query_name())+" shoots a highly charged Spuckball and zoks "+capitalize(ob->query_name())+"!\n");
  return 1;
}

recharge_delay() {
/*
	I deliberately crippled the heal command with this delay.
*/
  write("[Spucksuit]: Energy transfer sequence completed. ["+(this_player()->query_hp())+"]HP ["+
    (this_player()->query_sp())+"]SP.\n");
  say(capitalize(this_player()->query_name())+" glows for a moment, then fades back to normal.\n");
  this_player()->heal_self(33);
  aa_ammo=aa_ammo-10;
  return 1;
}

run_muthafucka() {
  int i;
  i=aa_ammo-5;
  if(!this_object()->query_worn()) {
    write("[Spucksuit]: System error: The suit must be worn to initiate command.\n");
    return 1;
  }
  if(i == 0 || i < 0) {
      write("[Spucksuit]: System error: SpuckCharge reserves insufficent or depleted.\n"+
	    "[5] SpuckCharges required for current procedure.\n");
      return 1;
    }
/*
  if((environment(this_player())->query_realm()) = "NT" ) {
    write("[Spucksuit]: System error: Unable to lock into coordinates /room/church.\n");
    return 1;
    }
*/
  write("[Spucksuit]: Executing escape sequence.\n");
  move_object(this_player(), "room/church");
  say(capitalize(this_player()->query_name())+" vanishes in a multicolored flash.\n");
  write("[Spucksuit]: Teleport successful. System stabilized.\n");
  aa_ammo=aa_ammo-5;
  return 1;
}

boot_blah() {
  write("[Spucksuit]: KDY Operating System installed. Unit fully operational.\n");
  say(capitalize(this_player()->query_name())+"'s Spucksuit glows to life.\n");
  return 1; 
}

area_attack() {
  int i;
  object room,ob2,oc2;
  object ob;
  room=environment(this_player());
  ob=first_inventory(room);
  if(!this_object()->query_worn()) {
    write("[Spucksuit]: System error: The suit must be worn to initiate command.\n");
    return 1;
  }
  i=aa_ammo-10;
  if(i == 0 || i < 0) {
      write("[Spucksuit]: System error: SpuckCharge reserves insufficent or depleted.\n"+
	    "[10] Spuckcharges requires for successful attack.\n");
      return 1;
    }
    if(this_player()->query_hp() < 50) {
      write("[Spucksuit]: Physical limitation error: Your body needs to recover.\n");
      return 1;
    }
  write("[Spucksuit]: Executing area attack offensive sequence.\n");
  write("[Spucksuit]: SpuckCharges remaining: ["+i+"].\n");
  say(capitalize(this_player()->query_name())+"'s Spucksuit whirrs and hums and rains Spuckball death!\n");
    while(ob) {
       object oc;
       oc=ob;
       ob=next_inventory(ob);
    if(living(oc)) {
      if(oc->query_npc() !=1) {
        say(capitalize(oc->query_name())+" escapes a near-certain death.\n");
        write("[Spucksuit]: System error: "+capitalize(oc->query_name())+" is a player. Tracking aborted.\n");
      }
    if(oc->query_npc() == 1) {
      write("You watch as high-velocity Spuckballs smash into "+capitalize(oc->query_name())+"!\n");
say(capitalize(oc->query_name())+" is zokked by a barrage of Spuckballs!\n");
/*
tell_object(oc->query_name(), "Zok! Zok! Zok! Zok! Zok! Zok! OUCH!!! That hurt!!\n");
*/
      oc->hit_player(20+random(10));
      aa_ammo=aa_ammo-10;
    if(oc && !oc->query_attack()) {
      oc->attack_object(this_player());
      }
    }
  }
}
write("[Spucksuit]: Area attack sequence completed. System stabilized.\n");
write("[Spucksuit]: ***WARNING*** Engaging multiple targets in combat.\n");
return 1;
}

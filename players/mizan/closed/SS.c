#define AMMOTYPE "spuckballs"
inherit "obj/armor";
int aa_ammo;

query_save_flag() { return 1; }

/* query_magik() { return 1; } */

reset(arg) {
  ::reset(arg);
  if(arg) return;
  /*
  write("[Spucksuit]: Beginning initialization sequence... please wait...\n");
  */
  set_name("spucksuit");
  set_short("A Super Spucksuit");
  set_long("This is the result of the marriage between technology and the\n"+
  "unexplainable powers of ether-world elements. A cybernetic computer\n"+
  "control system of the modern world is joined with the inherently\n"+
  "indestructable suit of armor composed of 'Spuckstuff' to form a battle\n"+
  "suit that could really 'defrost a frozen donut fast' (Spuck proverb)\n"+
  "\n"+"[Spucksuit]: The help screen is 'spuckhelp'.\n"); 
  set_value(400000);
  set_ac(4);
  set_type("armor");
  set_alias("suit");
  aa_ammo=360;
/*
  call_out("boot_blah", 8);
 */
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
  object ammo,all_in_ob;
  int rounds2;
  if(!str || str != "suit") return 0;
  if(!this_object()->query_worn()) {
    write("[Spucksuit]: System error: The suit must be worn to initiate command.\n");
    return 1;
  }
/*
  all_in_ob = all_inventory(this_object());
  if(sizeof(all_in_ob) > 15) {
    write("There is no room for more Spuckballs.\n");
    return 1;
  }
 */
  ammo=present(AMMOTYPE, this_player());
  if(!ammo) {
    write("You don't have any Spuckball tubes.\n");
    return 1;
  } 
  move_object(ammo, this_object()); 
  this_player()->add_weight(-1);
  rounds2=ammo->query_ammo();
  if(!rounds2 || rounds2 > 99990) {
    destruct(ammo);
    write("The Spucksuit rejects the clearly unusable Spuckballs.\n");
  }
    write("[Spucksuit]: Spuckball absorption completed. There are ["+(aa_ammo + rounds2)+"] SpuckCharges.\n");
    say("You see a tube of Spuckballs get absorbed into "+capitalize(this_player()->query_name()) + "'s Spucksuit.\n");
    aa_ammo=aa_ammo+rounds2;
  return 1;
  }

recharge_player(arg) {
  object ob;
  int i;
  if(!this_object()->query_worn()) {
    write("[Spucksuit]: System error: The suit must be worn to initiate command.\n");
    return 1;
  }
  if(!arg) {
    i=aa_ammo-36;
      if(i == 0 || i < 0) {
         write("[Spucksuit]: System error: SpuckCharge reserves insufficent or depleted.\n"+
	       "[36] SpuckCharges required for current procedure.\n");
         return 1;
      }
        recharge_delay();
      return 1;
    }
  ob=find_player(arg);
    if(!ob) {
      write("[Spucksuit]: Tracking error: Playername '"+arg+"' not located.\n");
      return 1;
    }
    if(!present(ob, environment(this_player()))) {
      write("[Spucksuit]: Tracking error: Playername '"+arg+"' is out of range.\n");
      return 1;
    }
  write("[Spucksuit]: Localized energy transfer initialized and completed.\n");
  ob->heal_self(18);
  aa_ammo=aa_ammo-36;
  tell_object(ob, capitalize(this_player()->query_name())+" has healed you 18 HP/SP.\n");
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
  i=aa_ammo-36;
    if(i == 0 || i < 0) {
       write("[Spucksuit]: System error: SpuckCharge reserves insufficent or depleted.\n"+
       "[36] SpuckCharges required for current procedure.\n");
       return 1;
    }
  ob=present(arg, environment(this_player()));
    if(!ob) {
      write("[Spucksuit]: Tracking error: TargetName '"+arg+"' not located.\n");
      return 1;
    }
    if(!present(ob, environment(this_player()))) {
      write("[Spucksuit]: Tracking error: TargetName '"+arg+"' is out of range.\n");
      return 1;
    }
    if((ob->query_npc()) != 1) {
      write("[Spucksuit]: Tracking error: Programming prohibits player attack.\n");
      return 1;
    }
  aa_ammo=aa_ammo-36;
  ob->hit_player(20+random(10));
  ob->attack_object(this_player());
  write("[Spucksuit]: Engaging selected target.\n");
  write("A highly charged Spuckball shoots out and screams death at "+capitalize(ob->query_name())+".\n");
  say(capitalize(this_player()->query_name())+" shoots a highly charged Spuckball and zoks "+capitalize(ob->query_name())+"!\n");
  return 1;
}

recharge_delay() {
/*
	I deliberately crippled the heal command with this delay.
	Why? I don't know...
*/
  write("[Spucksuit]: Energy extraction sequence completed. ["+(this_player()->query_hp())+"]HP ["+
    (this_player()->query_sp())+"]SP.\n");
  say(capitalize(this_player()->query_name())+" glows for a moment, then fades back to normal.\n");
  this_player()->heal_self(18 + random(10));
  aa_ammo=aa_ammo-36;
  return 1;
}

run_muthafucka() {
  int i;
  i=aa_ammo-36;
  if(!this_object()->query_worn()) {
    write("[Spucksuit]: System error: The suit must be worn to initiate command.\n");
    return 1;
  }
  if(i == 0 || i < 0) {
      write("[Spucksuit]: System error: SpuckCharge reserves insufficent or depleted.\n"+
	    "[36] SpuckCharges required for current procedure.\n");
      return 1;
    }
/*
	This doesnt work for some reason...

  if((environment(this_player())->query_realm()) = "NT" ) {
    write("[Spucksuit]: System error: Unable to lock into coordinates /room/church.\n");
    return 1;
    }
*/
  write("[Spucksuit]: Executing escape sequence.\n");
  move_object(this_player(), "room/church");
  say(capitalize(this_player()->query_name())+" vanishes in a multicolored flash.\n");
  write("[Spucksuit]: Teleport successful. System stabilized.\n");
  aa_ammo=aa_ammo-36;
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
  i=aa_ammo-72;
  if(i == 0 || i < 0) {
      write("[Spucksuit]: System error: SpuckCharge reserves insufficent or depleted.\n"+
	    "[72] Spuckcharges requires for successful attack.\n");
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
	Redundant.

tell_object(oc->query_name(), "Zok! Zok! Zok! Zok! Zok! Zok! OUCH!!! That hurt!!\n");
*/
      oc->hit_player(10+random(20));
      aa_ammo=aa_ammo-72;
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

/*	Miz.. A 'C+' for the code...
	An 'A-' for originality,
	and 'B' for effort. Better luck next time against the 
	original Iron-Man suit idea.
*/

object summoned_origin;
object summoned_object;
object anchor_room;

get() { if (this_player()->query_real_name() == "ultramagnus") return 1; }

id(str) { return str == "four winds" || str == "winds"; }

short() { return "The Four Winds"; }

long() {
write("The Four Winds of the Earth...\n"+
       "Placed under the Dominion of The Cloud Walker...\n");
}

drop() { return 0; }

reset(arg) {
   if(arg) { return; }
}

init() {
   if(this_player()->query_real_name() == "ultramagnus") {
      add_action("damage_living","dred");
      add_action("heal_living","dhl");
      add_action("dest_living","ddest");
      add_action("change_exp", "dexp");
      add_action("change_money","dold");
      add_action("trans_player","drans");
      add_action("super_shout", "dsh");
      add_action("dest_player", "ddest!");
      add_action("inv_tell", "dint");
      add_action("magnum_tell", "mag");
      add_action("deathmonger_tell", "deathmong");
      add_action("predator_tell", "pred");
      add_action("echoto", "dech");
      add_action("room_commands","?orb");
   }
}



damage_living(str){   /* this will reduce a living object to 0 hit points */
   object target;        /* and reduce its spell points to 0 */
   int spell_points;
   int amt;
   if(!str) { return 0; }
   target = find_living(str);
   if(!target) { return 0; }
   target->add_hit_point(-250);
   spell_points = (-1) * target->query_spell_point();
   target->add_spell_point(spell_points);
   return 1;
}

heal_living(str){   /* this will heal a living object anywhere */
   object target;      /* and recharge its spell points */
   string victim;
   int amt;
   if(!sscanf(str, "%s %d", victim, amt) && sscanf(str, "%s %d", victim, amt) != 2) {
   write("Usage is: dhl <target> <amt>.\n");
   return 1;
  }
   if(!str) { return 0; }
   target = find_living(victim);
   if(!target) { return 0; }
   tell_object(target, "You have been blessed by Ultramagnus.\n\n");
   target->heal_self(amt);
   return 1;
}

dest_living(str){   /* this will destruct a living object anywhere */
   object target;
   if(!str) { return 0; }
   target = find_living(str);
   if(!target) target = find_object(str);
   if(!target) return 0;
   destruct(target);
   return 1;
}

change_exp(str){   /* this will change the experience value of a player */
   object target;
   string tname;
   int amount;
   if(!str) { return 0; }
   if(!sscanf(str,"%s %d",tname,amount)) { return 0; }
   target = find_living(lower_case(tname));
   if(!target) { return 0; }
   target->add_exp(amount);
   return 1;
}

change_money(str){   /* this will change the amount of gold a player has */
   object target;
   string tname;
   int amount;
   if(!str) { return 0; }
   if(!sscanf(str,"%s %d",tname,amount)) { return 0; }
   target = find_living(lower_case(tname));
   if(!target) { return 0; }
   target->add_money(amount);
   return 1;
}

trans_player(str) {   /* transport a player to a specified destination */
      object target;
   object destination;
   string tname, whereto;
   status temp_shield;
   if(!str) { return 0; }
   if(!sscanf(str,"%s %s",tname,whereto)) { return 0; }
   target = find_living(lower_case(tname));
   if(!target) {
      write("Could not find "+tname+"\n");
      return 1;
   }
   if(whereto == "back") {
      if(target != summoned_object) {
         write("The target was not the last one summoned.\n");
         return 1;
      }
      move_object(target,summoned_origin);
      return 1;
   }
   if(whereto == "here") {
      say(capitalize(target->query_name()) + " suddenly vanishes"+
         " into thin air.\n", target);
      summoned_origin = environment(target);
      summoned_object = target;
      move_object(target,environment(this_player()));
      call_other(target, "command", "look");
      tell_object(target, "You have been transported to Ultramagnus.\n");
      return 1;
   }
   destination = valid_read(whereto);
   if(!destination) {
      write("Cannot find "+whereto+"\n");
      return 1;
   }
   move_object(target,destination);
   return 1;
}


valid_read(str) { return call_other(this_player(),"valid_read",str); }

room_commands() {
   if(this_player()->query_real_name() != "ultramagnus") {
      return 0; }
   write("help winds                  :  display this help list\n");
   write("dred <target>             :  reduce a living object to zero points\n");
   write("dhl <target>              :  restore a living objects points\n");
   write("ddest <target>            :  destroy a living object anywhere\n");
   write("dexp <target> <amount>    :  change experience of a player\n");
   write("dold <target> <amount>    :  change a player's amount of gold\n");
   write("drans <target> <to where> :  move a player to a location\n");
   return 1;
}


super_shout(str) {
   if(!str) {
      write("What do you want to echo??\n");
      return 1;
   }
   shout("\n\n"+str+"\n\n");
   tell_object(this_player(), "You have shouted: "+str+"\n");
   return 1; }

dest_player(str) {
   string tname, mess;
   object target;
   
   if(!str) {
      write("Who/what is the target?\n");
      return 1;
   }
   if(!sscanf(str, "%s with %s", tname, mess)) {
      write("Usage is: ddest! <target> <message>.\n");
      return 1;
   }
   if(sscanf(str, "%s with %s", tname, mess) != 2) {
      write("Usage is: ddest! <target> <message>.\n");
      return 1;
   }
   target=find_living(tname);
   if(!target || !living(target)) {
      write("That target was not found.\n");
      return 1;
   }
   tell_object(target, "\n\n"+mess+"\n");
   destruct(target);
   tell_object(this_player(), "You have destructed "+tname+" with "+mess+"\n");
   return 1;
}

inv_tell(str) {
   object target, master;
   string tname, mess;
   if(!str) {
      write("What do you want to tell to someone??\n");
      write("Usage is: dint <target> <mess>.\n");
      return 1;
   }
   if(!sscanf(str, "%s %s", tname, mess)) {
      write("Usage is: dint <target> <mess>.\n");
      return 1; }
   if(sscanf(str, "%s %s", tname, mess) != 2) {
      write("Usage is: dint <target> <mess>.\n");
      return 1; }
   target = find_player(tname);
   if(!living(target) || !target) {
      write("That person isn't playing right now.\n");
      return 1; }
   tell_object(target, "Demoder tells you: "+mess+"\n\n");
   write("You have told "+capitalize(tname)+" ("+mess+").\n");
   return 1;
}

magnum_tell(str) {
   object mag;
   if(!str) {
      write("What do you want to tell Magnum?\n");
      write("Usage is: mag <mess>.\n");
      return 1; }
   mag = find_player("magnum");
   if(!mag || !living(mag)) {
      write("Magnum isn't playing right now.\n");
      return 1; }
   tell_object(mag, "Demoder tells you: "+str+"\n\n");
   write("You have told Magnum "+str+"\n");
   return 1;
}

deathmonger_tell(str) {
   object dm;
   if(!str) {
      write("What do you want to tell Deathmonger?\n");
      write("Usage is: deathmong <mess>.\n");
      return 1; }
   dm = find_player("deathmonger");
   if(!dm || !living(dm)) {
      write("Deathmonger isn't playing right now.\n");
      return 1; }
   tell_object(dm, "Demoder tells you: "+str+"\n\n");
   write("You have told Deathmonger "+str+"\n");
   return 1;
}


predator_tell(str) {
   object pred;
   if(!str) {
      write("What do you want to tell Predator?\n");
      write("Usage is: pred <mess>.\n");
      return 1; }
   pred = find_player("predator");
   if(!pred || !living(pred)) {
      write("Predator isn't playing right now.\n");
      return 1; }
   tell_object(pred, "Demoder tells you: "+str+"\n\n");
   write("You have told Predator "+str+"\n");
   return 1;
}

echoto(str) {
   object target;
   string tname, mess;
   if(!str) {
      write("Usage is: dech <target>, <mess>.\n");
      return 1;
   }
   if(!sscanf(str, "%s, %s", tname, mess)) {
      write("Usage is: dech <target>, <mess>.\n");
      return 1;
   }
   if(sscanf(str, "%s, %s", tname, mess) != 2) {
      write("Usage is: dech <target>, <mess>.\n");
      return 1;
   }
   target = find_player(tname);
   if(!target || !living(target)) {
      write("That player is not in condition to receive your echo.\n");
      return 1;
   }
   tell_object(target, mess+"\n");
   write("You have told "+capitalize(tname)+" ("+mess+").\n");
   return 1;
}

query_weight() { return 0; }

query_value() { return 0; }

query_auto_load() {
return "players/ultramagnus/pow:";}

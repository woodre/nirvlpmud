#define REALM call_other(environment(this_object()), "realm", 0)
#define att (find_player(owner)->query_attack())
#define capowner capitalize(owner)
#define Room tell_room(environment(this_object()),
#define corpse present("corpse", environment(this_object()))
   inherit "/obj/monster";
   int mount, follow_flag, busy_flag, damage, old_hp, new_hp;
	string nme, bwho, variable, command_list, owner;
   object bringer, target, thingy;
   reset(arg) {
      ::reset();
      if(arg) return;
      set_name("Dragon");
      set_short("Black Dragon");
      set_alias("dragon");
      set_ep(0);
      set_ac(3);
      set_wc(20);
	   set_hp(175);
      nme = "A Black Dragon";
      enable_commands();
	call_out("hb", 60);
	}
   
   id(str) {
      return str =="dragon" || str==variable;
	}
hb() {
	if(owner == 0) {
	say("The dragon loses its form and the spirits ascend back into the heavens.\n");
	destruct(this_object());
	}
	if(!find_player(owner)) {
	Room "The dragon loses its form and the spirits ascend back into the heavens.\n");
	destruct(this_object());
	}
call_out("hb", 60);
}
heart_beat() {
	if(follow_flag == 1 && mount == 0 && busy_flag == 0) {
	if(environment(find_player(owner)) != environment(this_object())) {
		say(nme+" flies out of the room.\n");
		move_object(this_object(), environment(find_player(owner)));
		say(nme+" flies into the room.\n");
      }
	if(att) {
		new_hp = find_player(owner)->query_hp();
         damage = old_hp - new_hp;
		if(damage/4 > 0) {
            find_player(owner)->heal_self(damage/4);
            tell_object(find_player(owner),"The dragon takes "+damage/4+" pts of damage for you.\n");
	this_object()->hit_player(damage/4);
         }
         old_hp = new_hp;
      }
	}
}
   set_variable(idstr) { variable=idstr; }
   set_owner(ownstr) { owner = ownstr; }
   short() {
      return nme;
	}
   
   long() {
      object ob;
      ob = this_player();
	if(ob->query_real_name() != owner || owner == 0) {
         write("This is a huge black dragon with blood red eyes.  It has\n"+
            "enormous wings to carry it's muscular form.  As you look into it, you\n"+
		"can see the movement of the spirits that make up its existance.\n");
        }
	if(ob->query_real_name() == owner) {
	write("This dragon is the most powerful creature you have ever\n"+
"laid your eyes upon.  Its blood red eyes seem to stare right through\n"+
"your soul.  The scales that protect the body are jet black.  If you\n"+
"turn your head and look at the dragon from the corner of your eye,\n"+
"you can catch movement of the spirits inside the huge beast.\n"+
		"[HPS: "+this_object()->query_hp()+"]\n");
        }
        }
   
   init() {
      ::init();
	    add_action("dsay"); add_xverb("say");
	    add_action("dsay"); add_xverb("'");
      add_action("drop","drop");
      add_action("dragon_follow","follow");
      add_action("climb","climb");
      add_action("mount","mount");
      add_action("dismount","dismount");
      add_action("release","release");
	  add_action("feed","feed");
      add_action("transport","transport");
      add_action("bring","bring");
      add_action("fly","fly");
      add_action("Look","L");
	}
catch_tell(str) {
	if(owner != 0) {
	if(present(owner, this_object())){
	tell_object(find_player(owner), str+"\n");
	return 1;
	}
	}
}
dsay(str) {
		if(present(this_player(), this_object())) {
	if(!str) {
	write("Say what?\n");
	return 1; }
	Room capitalize(this_player()->query_real_name())+" says from atop "+this_player()->query_possessive()+" dragon: '"+str+"'\n\n");
	write("You say: "+str+"\n");
	return 1; }
}
   drop() {
      if(mount == 1) {
         write("The spirits in the dragon hiss: 'You can't do that while mounted master.'\n");
         return 1;
        }
}
   release() {
	if(this_player()->query_real_name() == owner) {
         if(mount==1) {
            write("You cannot release the spirits while riding the Dragon.\n");
            return 1;
         }
		say("The sky turns black as "+capowner+" releases the spirits within the dragon.\n");
         destruct(this_object());
         return 1;
	}
	}
   fly(str) {
	if(this_player()->query_real_name() == owner) {
      if(mount == 0) {
         write("The spirits in the dragon hiss:  'You must be mounted to fly anywhere.'\n");
         return 1; }
      if(!str) {
         write("The spirits in the dragon hiss: 'Where do you wish to fly master?'\n");
         return 1; }
      if(REALM == "NT" && str == "guild") {
         write("The spirits within the dragon hiss: 'You may not do that here.'\n");
         return 1; }
      if(str == "guild") {
         say(capowner+"'s dragon takes off into the sky.\n");
         move_object(this_object(), "/players/dragnar/guild/rooms/temple");
		say("A dragon swoops down from the sky.\n");
		command("L", find_player(owner));
         return 1;
       }
	command_list = str;
      go_fly();
      return 1; }
	}
   go_fly() {
      string curr_cmd, rest_cmd;
	while(command_list && sscanf(command_list, "%s,%s", curr_cmd, rest_cmd) == 2) {
		if(curr_cmd == "n") { curr_cmd = "north"; }
                if(curr_cmd == "s") { curr_cmd = "south"; }
                if(curr_cmd == "e") { curr_cmd = "east"; }
                if(curr_cmd == "w") { curr_cmd = "west"; }
                if(curr_cmd == "nw") { curr_cmd = "northwest"; }
                if(curr_cmd == "ne") { curr_cmd = "northeast"; }
                if(curr_cmd == "se") { curr_cmd = "southeast"; }
                if(curr_cmd == "sw") { curr_cmd = "southwest"; }
         if(!command(curr_cmd, this_object())) {
	write("The spirits in the dragon hiss: 'We can not go "+curr_cmd+" master.'\n");
            command_list = 0;
            return 1;
	} else {
         write("Your dragon flies "+curr_cmd+".\n");
         command_list = rest_cmd;
	}
	}
	if(command_list) {
	if(sscanf(command_list, "%s", curr_cmd) == 1) {
		if(curr_cmd == "n") { curr_cmd = "north"; }
		if(curr_cmd == "s") { curr_cmd = "south"; }
		if(curr_cmd == "e") { curr_cmd = "east"; }
		if(curr_cmd == "w") { curr_cmd = "west"; }
		if(curr_cmd == "nw") { curr_cmd = "northwest"; }
		if(curr_cmd == "ne") { curr_cmd = "northeast"; }
		if(curr_cmd == "se") { curr_cmd = "southeast"; }
		if(curr_cmd == "sw") { curr_cmd = "southwest"; }
	if(!command(curr_cmd, this_object())) {
	write("The spirits in the dragon hiss: 'We can not go "+curr_cmd+" master.'\n");
	return 1;
	}
	write("Your dragon flies "+curr_cmd+".\n");
	} else {
	if(!command(curr_cmd, this_object())) {
	command("L", find_player(owner->query_real_name()));
	write("The spirits in the dragon hiss: 'We can not fly "+curr_cmd+" master.\n");
	return 1; }
	write("Your dragon flies "+command_list+".\n");
	}
	}
	command("L", find_player(owner));
	write("The spirits in the dragon hiss: 'We have flown as you commanded master.'\n");
	return 1;
}
   Look() {
	if(this_player()->query_real_name() == owner) {
      move_object(this_player(), environment(this_object()));
      command("look", this_player());
      move_object(this_player(), this_object());
      return 1;
	}
}
   dragon_follow() {
	if(this_player()->query_real_name() == owner) {
         if(follow_flag == 0) {
            write("The spirits in the dragon say:  'We will follow you now master.'\n");
		set_heart_beat(1);
            old_hp = this_player()->query_hp();
            follow_flag = 1;
            return 1;
         }
         if(follow_flag == 1) {
            write("The spirits in the dragon say: 'We will no longer follow you master.'\n");
		set_heart_beat(0);
            follow_flag = 0;
            return 1;
         }
         }
}
   mount(arg) {
	if(this_player()->query_real_name() == owner) {
         if(mount == 1) {
            write("You are already on the dragon.\n");
            return 1;
         }
	if(att) {
	write("The spirits in the dragon hiss: 'We must not allow that now, master.'\n");
	return 1; }
         write("You feel as one with the spirits as you climb upon the Dragon.\n");
	say(capowner+" climbs upon the back of "+this_player()->query_possessive()+" dragon.\n");
         mount=1;
		move_object(find_player(owner), this_object());
         return 1;
         }
	}
   dismount() {
	if(this_player()->query_real_name() == owner) {
         if(mount==0) {
            write("You are not on the Dragon.\n");
            return 1;
         }
         write("You feel cold enter your soul as you break the bond with the spirits.\n");
	Room capowner+" climbs down from "+this_player()->query_possessive()+" dragon's back.\n");
         mount=0;
         move_object(this_player(), environment(this_object()));
         if(follow_flag == 1) {
		set_heart_beat(1);
         }
         return 1;
	}
}
feed() {
	if(this_player()->query_real_name() == owner) {
	int amount;
	if(!corpse) {
	write("The Spirits in the dragon hiss: 'There is no corpse here master.'\n");
	return 1; }
	amount = corpse->heal_value();
	this_object()->heal_self(amount);
        destruct(corpse);
	say("The dragon devours a corpse at "+capowner+"'s command.\n");
        return 1;
	}
}
   transport(str) {
      string who, what;
		if(this_player()->query_real_name() == owner) {
         if(!str) {
            write("The spirits within the dragon hiss: 'You must tell us what object and who to fly it to.'\n");
            return 1;
         }
		if(mount == 1) {
		write("The spirits within the dragon hiss: 'We cannot do that while you are mounted master.'\n");
	return 1; }
         sscanf(str, "%s %s",what, who);
         if(!who || !what) {
            write("The spirits hiss: 'What do you want to fly and to who master?'\n");
            return 1; }
         target=find_player(who);
         if(!target) {
            write("The spirits hiss: 'We can't find "+capitalize(who)+" master.'\n");
            return 1; }
         thingy=present(what, this_object());
         if(!thingy) {
            write("The spirits hiss: 'We don't have a "+what+" master.'\n");
            return 1; }
         say(capowner+"'s dragon flies off into the sky.\n");
		busy_flag = 1;
		gototarget();
         return 1;
	}
	}
   gototarget() {
      move_object(this_object(), environment(target));
      say(capowner+"'s dragon swoops down from the sky.\n");
      move_object(thingy, target);
      say("The spirits within the dragon transport "+thingy->short()+" to "+capitalize(target->query_real_name())+".\n");
      call_out("backtoowner",30);
      return 1; }
   backtoowner() {
		say("The dragon jumps into the air, and flys off into the sky.\n");
		move_object(this_object(), environment(find_player(owner)));
      say(capowner+"'s dragon swoops down from the sky.\n");
		busy_flag = 0;
      return 1;
	}
   bring(str) {
	if(this_player()->query_real_name() == owner) {
      if(!str) { write("Your dragon snorts, and breathes a ring of smoke.\n"); return 1; }
      bringer=find_player(str);
	bwho = str;
	if(!bringer) { write("The spirits hiss: 'We can not find "+capitalize(str)+" master.'\n");
	return 1; }
      say(capowner+"'s dragon flies into the sky.\n");
		busy_flag = 1;
      move_object(this_object(), environment(bringer));
      say("A huge black dragon swoops down from the sky.\n");
	     tell_object(bringer, "The spirits hiss: '"+capowner+" wishes to summon you. Type 'climb on dragon'\n"+
	"if you wish for us to take you there.\n");
	call_out("bring_failure", 35);
      return 1; }
	}
   climb(str) {
      if(this_player()==bringer) {
	if(REALM == "NT") {
	write("The spirits in the dragon hiss: 'You may not be summoned from this place.'\n");
	return 1; }
         if(str == "on dragon") {
            move_object(this_player(), this_object());
            write("You climb onto the back of the dragon.\n");
		command("look", this_player());
            Room capitalize(this_player()->query_real_name())+" climbs onto the back of the dragon.\n");
	remove_call_out("bring_failure");
	input_to("deliverbringer");
	return 1; }
	}
}
deliverbringer() {
	tell_object(bringer, "You feel the powerful muscles under you as the dragon jumps, and begins to fly.\n");
	Room "The dragon flies back to its master.\n");
	move_object(this_object(), "/room/void");
	call_out("flying",4);
	return 1; }
flying() {
	tell_object(bringer, "You are flying at an incredible speed.  The wind is making your eyes\n"+
"water and is making you feel very unsafe.  The land below you looks\n"+
"so small that you cannot tell where you are going.  Suddenly, the\n"+
"dragon begins to slow down and begins descending.\n");
	call_out("land", 2);
	return 1; }
land() {
	tell_object(bringer, "The dragon spreads his wings and lands next to its master.\n");
	move_object(this_object(), environment(find_player(owner)));
	say("A large black dragon drops from the sky and lands next to its master.\n");
	call_out("dropoff", 3);
	return 1; }
dropoff() {
tell_object(bringer, "Still in awe of the flight, you slide off the dragon's back.\n");
	say(capitalize(bringer->query_real_name())+" slides from the dragon's back.\n");
	move_object(bringer, environment(this_object()));
	command("look", bringer);
	busy_flag = 0;
	bringer = 0;
	return 1; }
bring_failure() {
	tell_object(bringer, "The spirits hiss: 'You have timed out of the summons.'\n");
	say("The dragon jumps up, and flies off into the sky.\n");
	move_object(this_object(), environment(find_player(owner)));
	say("A huge black dragon swoops down and lands next to its master.\n");
	tell_object(find_player(owner), "The spirits hiss: '"+capitalize(bwho)+" timed out of your summons master.'\n");
	busy_flag = 0;
	bringer = 0;
	return 1; }
is_pet() { return 1; }
query_owner() { return owner; }

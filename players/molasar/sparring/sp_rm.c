
/*
 * SPARRING ROOM (7/3/94)
 * Players may fight one another in this room with no fear of death
 */

/* Define this if running on Nirvana */
#undef NIRVANA

#define MASTER "/players/molasar/sparring/master"
#define TELL(x) tell_room(this_object(), x)
#define LIST "/players/molasar/sparring/list"
#define WROOM "/players/molasar/sparring/w_rm"
#define LROOM "/players/molasar/sparring/l_rm"
#define LOGFILE "/players/molasar/sparring/RESULTS"

int locked;
string challenged;

reset(arg) {
   if(!arg)
     set_light(1);
   challenged = 0;
   locked = 0;
   extra_reset();
}

extra_reset() {
   object viewer;

   if(!present("viewer")) {
     viewer = clone_object("players/molasar/sparring/viewer");
     move_object(viewer, this_object());
   }
}

realm() { return "NT"; }

set_challenged(c) { challenged = 0; }

query_locked() { return locked; }

init() {
   if(this_player() && this_player()->query_npc() && 
                           !this_player()->query_viewer_flag()) {
     TELL("Non-players not allowed!  Destructing object....\n");
     move_object(this_player(), "/room/void");
     destruct(this_player());
   }
   if(this_player() && query_ip_number(this_player())) {
     MASTER->place_sparring_shadow(this_player());
     locked = 1;
   }
   add_action("north","north");
   add_action("unlock","unlock");
   add_action("challenge","challenge");
}

north() {
   if(locked) {
     write("You must unlock the room first.\n");
     return 1;
   }
   if(this_player()->query_sparring_shadow())
     MASTER->remove_sparring_shadow(this_player());
   this_player()->move_player("north#players/molasar/sparring/hall");
   return 1;
}

short() { return "The Sparring Arena of Rowan"; }

long() {
   write("You are in the Sparring Arena of Rowan.\n");
   write("For years the Paladins have used this arena to hone their\n");
   write("abilities by practicing against themselves and fighters from\n");
   write("all over the realms. A large balcony above the room provides a\n");
   write("viewing place so people may watch the grand spectactle.\n");
   write("NOTE: You will not be killed or gain any experience.\n");
   write("      Upon leaving the room you will be fully healed.\n");
   write("Commands: unlock, challenge\n");
   write("     There is on obvious exit: north\n");
   if(locked) 
     write("THE SPARRING ROOM IS LOCKED\n");
   if(challenged)
     write("A CHALLENGE HAS BEEN MADE AGAINST: "+capitalize(challenged)+"\n");
}

unlock() {
   if(!locked) {
     write("The room is not locked.\n");
     return 1;
   }
   if(this_player()->query_attack()) {
     write("You may not unlock the room during a fight.\n");
     return 1;
   }
   if(challenged) {
     write("The challenge has been cancelled!\n");
     if(find_player(challenged)) {
       if(present("sparring_scroll", find_player(challenged))) {
         tell_object(find_player(challenged), 
             "The Challenge has been cancelled!\n");
         destruct(present("sparring_scroll",find_player(challenged)));
       }
     }
     challenged = 0;
   }
   locked = 0; 
   command("north", this_player());    
   return 1;
}

stop_fight(loser, winner) {
   object invob;

   invob = first_inventory(this_object());
   while(invob) {
      if(invob->query_attack())
        invob->stop_fight();
      invob = next_inventory(invob);
   }
   TELL("\n\n");
   TELL("The match has been completed.........\n");
   TELL("      "+capitalize(winner)+" has defeated "+capitalize(loser)+".\n"); 
   TELL("\n");
   filter_msg("\n***** "+capitalize(winner)+" has defeated "
         +capitalize(loser)+" in a sparring match! *****\n\n");
   if(locked)
     locked = 0;
   LIST->add_player("won",winner);
   LIST->add_player("lost",loser);
   TELL("You find yourself in a different place.....\n");
   MASTER->remove_sparring_shadow(find_player(winner)); 
   MASTER->remove_sparring_shadow(find_player(loser)); 
   write_file(LOGFILE, capitalize(winner)+" ["+LIST->query_record(winner)+
        "] HP: ["+find_player(winner)->query_hp()+"] defeated\n");
   write_file(LOGFILE, "     "+capitalize(loser)+" ["
        +LIST->query_record(loser)+"] => "+ctime(time())+"\n");
   find_player(winner)->heal_self(10000);
   find_player(loser)->heal_self(10000);
   move_object(find_player(winner), WROOM);
   move_object(find_player(loser), LROOM);
   return 1;
}

challenge(str) {
   object who, scroll, lvl, who_level;

   if(!str) {
     write("You must specify someone to challenge.\n");
     return 1;
   }
   if(!locked) {
     write("The room must be locked first.\n");
     return 1;
   }
   if(challenged) {
     write("A challenge has already been made.\n");
     return 1;
   }
   if(this_player()->query_attack()) {
     write("You cannot challenge while fighting!\n");
     return 1;
   }
   who = find_player(str);
   if(!who || who->query_invis()) {
     write(capitalize(str)+" is not on.\n");
     return 1;
   }
   if(this_player()->query_real_name() == str) {
     write("Challenge yourself?  Are you loopy??\n");
     return 1;
   }
/* added by mizan, players have been using as a free teleport out of NT rooms */
  if(!environment(who) || environment(who)->query_realm() == "NT") {
    write("You fail.\n");
    return 1;
  }
/* END addition */
   lvl = this_player()->query_level();
   who_level = who->query_level();
   if(lvl > 19 || who_level > 19) {
     write("Wizards may not spare!\n");
     return 1;
   }
   if(lvl < 10 || who_level < 10) {
     write("Both participants must be at least level 10.\n");
     return 1;
   }
   if((lvl > (who_level + 5)) || (lvl < (who_level - 5))) {
     write("You must be within five levels of the person challenged.\n");
     return 1;
   }
   challenged = str;
   write("You have challenged "+capitalize(str)+".\n");
   scroll = clone_object("players/molasar/sparring/scroll");
   scroll->set_challenger(this_player()->query_real_name());
   scroll->set_level(lvl);
   move_object(scroll, who);
   tell_object(who, "\nA scroll materializes in your possession.\n"+
                    "You have been challenged to a sparring match.\n"+
                    "Look at the scroll for further info.\n");
   tell_object(who, "**** READ THE RULES BEFORE ACCEPTING ****\n");
   return 1;
}

filter_msg(str) {
   object list;
   int i;

   list = users();
   for(i=0; i < sizeof(list); i++) 
#ifdef NIRVANA      
      if(!in_editor(list[i]))
#endif        
        tell_object(list[i], str);
   return 1;
}

string loser, winner;  

exit() { 
   if(this_player() && locked && this_player()->query_attack()) {
     loser = this_player()->query_real_name();
     winner = this_player()->query_attack()->query_real_name();
     locked = 0;
     forfeit(winner,loser);
     return 1;
   }
   locked = 0;
}

forfeit(winner,loser) {
   LIST->add_player("won",winner);
   LIST->add_player("lost",loser);
   TELL("You find yourself in a different place.....\n");
   MASTER->remove_sparring_shadow(find_player(winner)); 
   MASTER->remove_sparring_shadow(find_player(loser)); 
   write_file(LOGFILE, capitalize(winner)+" ["+LIST->query_record(winner)+
        "] HP: ["+find_player(winner)->query_hp()+"] won by forfeit\n");
   write_file(LOGFILE, "     "+capitalize(loser)+" ["
        +LIST->query_record(loser)+"] => "+ctime(time())+"\n");
   find_player(winner)->heal_self(10000);
   find_player(winner)->stop_fight();
   find_player(loser)->heal_self(10000);
   find_player(loser)->stop_fight();
   move_object(find_player(winner), WROOM);
   filter_msg("\n***** "+capitalize(loser)+" has forfeited "+
         find_player(loser)->query_possessive()+" sparring match "+
         "against "+capitalize(winner)+"! *****\n\n");
   return 1;
}

   

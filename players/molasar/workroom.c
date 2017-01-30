
/*
 * WORKROOM (3/16/94)
 */

#define OWNER find_player("molasar")
#define OK (this_player()->query_real_name() == "molasar")

int locked, lock_lvl, alarm;

reset(arg) {
   if(arg)
     return;
   set_light(1);
   lock_lvl = 21;
   locked = 1;
   alarm = 1;
}

short() { return "The workroom of Molasar"; }

long() {
   write("Many scrolls and books line the tables and shelves around the\n"+
         "room.  A lone candle burns brightly at the center of the room.\n");
   write("  Exits:  church, guild, palguild, down");
   if(this_player()->query_level() > 20)
     write(", inner");
   write("\n");
   if(OK) {
     write("COMMANDS: lock <level>, unlock, alarm, staff\n");
     write("LOCK: ");
     if(locked) write("ON - ["+lock_lvl+"]"); else write("OFF");
     write("     "); write("ALARM: ");
     if(alarm) write("ON"); else write("OFF");
     write("\n");
   }
}

init() {
   if(this_player() && !this_player()->query_npc()) {
     if(deny_entry(this_player()))
       return 1;
   }
   add_action("staff","staff");
   add_action("inner","inner");
   add_action("church","church");
   add_action("guild","guild");
   add_action("palguild","palguild");
   add_action("down","down");
   add_action("alarm","alarm");
   add_action("lock","lock");
   add_action("unlock","unlock");
}

deny_entry(who) {
   if(OK)
     return 0;
   if(locked) {
     if(lock_lvl > who->query_level()) {
       tell_object(who, "Hmmmm...something isn't right.\n");
       move_object(who, "/room/church");
       if(alarm && OWNER) 
         tell_object(OWNER, capitalize(who->query_real_name())+
             " tried to enter your workroom.\n");
       return 1;
     }
     if(alarm && OWNER) 
       tell_object(OWNER, capitalize(who->query_real_name())+
           " has entered your workroom.\n");
       return 0;  
   }
   if(alarm && OWNER)
     tell_object(OWNER, capitalize(who->query_real_name())+
         " has entered your workroom.\n");
     return 0;  
}      

staff() {
   object staff;
   if(this_player()->query_level() < 100) 
     return 0;
   staff = clone_object("players/molasar/closed/staff");
   move_object(staff, this_player());
   write("You know have a staff.\n");
   return 1;
}

church() {
  this_player()->move_player("through a portal#room/church");
  return 1;
}

guild() {
   this_player()->move_player("through a portal#room/adv_guild");
   return 1;
}

palguild() {
   this_player()->move_player("through a portal#"+
                                       "players/sandman/paladin/adv_guild");
   return 1;
}

down() {
   this_player()->move_player("through a portal#room/sunalley2");
   return 1;
}

inner() {
   if(this_player()->query_level() < 21)
     return 0;
   this_player()->move_player("through a portal#room/adv_inner");
   return 1;
}

lock(lvl) {
   if(!OK)
     return 0;
   if(!lvl || sscanf(lvl, "%d", lock_lvl) != 1) {
     write("You must specify a level.\n");
     return 1;
   }
   locked = 1;
   write("Your workroom is LOCKED <"+lock_lvl+">.\n");
   return 1;
}

unlock() {
   if(!OK)
     return 0;
   locked = 0;
   lock_lvl = 0;
   write("Your workroom is UNLOCKED.\n");
   return 1;
}

alarm() {
   if(!OK)
     return 0;
   alarm = !alarm;
   if(alarm)
     write("Workroom alarm is ON.\n");
   else
     write("Workroom alarm is OFF.\n");
   return 1;
}





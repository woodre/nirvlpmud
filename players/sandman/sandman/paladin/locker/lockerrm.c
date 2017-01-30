
/*
 * LOCKER ROOM (2/9/94)
 * Where players can store paladin weapons
 */

#define LOCKER "/players/sandman/paladin/locker/locker"

realm() { return "NT"; }

reset(arg) {
   if(!arg)
     set_light(1);
}

id(str) { return str == "locker" || str == "lockers"; }

short() { return "The Paladin Locker Room"; }

long(str) {
  if(str == "locker" || str == "lockers") {
    write("Wooden lockers adorn the walls of the room.\n");
    write("They are reinforced by steel supports and straps.\n");
    return 1;
  }
  write("You are in the room which houses the weapon lockers for\n");
  write("Paladins. Lockers cover every inch of wall space.\n");
  write("Commands: retrieve, store, list\n");
  write("     There is one obvious exit:  east\n");
}

init() {
   add_action("east","east");
   add_action("store","store");
   add_action("retrieve","retrieve");
   add_action("list","list");
}

east() {
   this_player()->move_player("east#players/sandman/paladin/hall2");
   return 1;
}

store(str) {
   LOCKER->store(str);
   return 1;
}

retrieve() {
   LOCKER->retrieve();
   return 1;
}

list() {
   LOCKER->list();
   return 1;
}

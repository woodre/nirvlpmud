
/*
 * Mapping test object
 */

mapping player_names;

reset (arg) {
   if (arg)
      return;

   player_names = ([]);

/*   player_names = ([ "molasar": 10, "sandman": 4, "mordrake": 22 ]); */
}

id(str) { return str == "mapping"; }

short() { return "A round cube"; }

long() {
   write("You see nothing special.\n");
}

init() {
   add_action("map_func","mapping");
}

map_func(string who) {
   string name;
   /* player_names = allocate_mapping(10); */
   write("A mapping.\n");

  
   if (!who || !sscanf(who, "%s", name))
     return 1;

   if (!member(player_names, name)) {
     write("   " + name + " not found!\n");
     player_names[name] = 101;
   } 

   write("   " + name + ": " + player_names[name] + "\n");
   
   return 1;
}


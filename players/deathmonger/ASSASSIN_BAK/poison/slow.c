
/* actual delay is DELAY+1 */
#define DELAY 2

inherit "players/deathmonger/poison/poison.c";

string actions, abbr;
int dirs;
reset(arg){
   if(arg) return;
   set_short("slowness");
   set_long("This poison slows its victims down!\n");
   actions = allocate(10);
   abbr = allocate(10);
   dirs = allocate(10);
   actions = ({ "north", "south", "east", "west" });
   abbr = ({ "n", "s", "e", "w" });
   dirs = ({ 0, 0, 0, 0 });
}

init(){ 
   add_action("slow", "n");
   add_action("slow", "s");
   add_action("slow", "w");
   add_action("slow", "e");
   add_action("slow", "north");
   add_action("slow", "south");
   add_action("slow", "west");
   add_action("slow", "east");
}

slow(){
   string dir;
   int index;
   dir = query_verb();
   index = find_index(dir);
   if(dirs[index] > DELAY){
      dirs[index] = 0;
      return 0;
   }
   else {
       dirs[index] += 1;
      return 1;
   }
}

find_index(str){
   int i;
   for(i=0;i<sizeof(actions);i++){
     if(actions[i] == str)
        return i;
   }
   for(i=0;i<sizeof(abbr);i++){
      if(abbr[i] == str)
         return i;
   }
   return "BADBAD";
}

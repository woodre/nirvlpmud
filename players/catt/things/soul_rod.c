/***********************************/
/* Rod to clone dargoth            */
/***********************************/
string str2;
object soul;
id(str) { return str == "soul rod"; }
get() { return 1; }
short() { return "Soul Rod"; }
long() {
   write("The soul rod. Used to summon a soul to play with. \n" +
         "To use: call 'soul'  \n" +
         "Example: call dargoth \n" +
         "You may also 'soul_list', and list commands that you \n" +
         "must have the rod for.\n");
   return 1; }
reset(arg) {
   if(arg) return;
   }
init() {
   add_action("call","call");
   add_action("list","soul_list");
   add_action("command","c:");
   add_action("fry2","fry2");
}

call(str) {
   if(!str) return 0;
   if(str == "dargoth") { soul = clone_object("players/catt/things/dargoth"); }
   if(str == "macros") { soul = clone_object("players/catt/things/macros"); }
   if(str == "rea") { soul = clone_object("players/catt/things/rea"); }
   if(soul) {
      move_object(soul, environment(this_player()));
      soul->set_owner(this_player());
      return 1;
   }
   return 0;
}

fry2(str) {
   if(!str) return 0;
   if(str) {
      destruct(find_living(str));
      tell_object(this_player(), "Object "+str+" destroyed!\n");
      return 1;
   }
   return 0;
}

command(str) {
   string s1, s2;
   if(!str) return 0;
   if(str == "fry") {
      soul->fry();
      return 1;
      }
   if(str == "west") { 
      soul->west();
      soul->slook();
      return 1;
   }
   if(str == "east") {
      soul->east();
      soul->slook();
      return 1;
   }
   if(str == "north") {
      soul->north();
      return 1;
   }
   if(str == "south") {
      soul->south();
      return 1;
   }
   if(str == "up") {
      soul->up();
      return 1;
   }
   if(str == "down") {
      soul->down();
      return 1;
   }
   if(str == "look") {
      soul->slook();
      return 1;
   }
   if(sscanf(str, "%s %s", s1, s2) != 2) return;
   if(s1 == "goto") {
      soul->soulto(s2);
      return 1;
   }
   if(s1 == "say") {
      soul->ssay(s2);
      return 1;
   }
   if(s1 == "tell") {
      soul->stell(s2);
      return 1;
   }
   if(s1 == "emote") {
      soul->soulemote(s2);
      return 1;
   }
   if(s1 == "echo") {
      soul->soulecho(s2);
      return 1;
   }
   if(s1 == "shadow") {
      soul->soul_shadow(s2);
      return 1;
   }
   this_player()->write("Improper command\n");
   return 0;
}
list() {
   write("************************************************\n"+
         "*        Command List for Rod of Souls         *\n"+
         "************************************************\n"+
         "* Call {soul} - Current souls are:             *\n"+
         "*                                 Dargoth      *\n"+
         "*                                 Macros       *\n"+
         "*                                 Rea          *\n"+
         "* List - This list.                            *\n"+
         "* c:   - Command line. Options are:            *\n"+
         "*        north, south, east, west, up, down,   *\n"+
         "*        look, goto(arg), say(arg),            *\n"+
         "*        tell(arg,arg), emote(arg, echo(arg),  *\n"+
         "*       shadow(who and off)                    *\n"+
         "*                                              *\n"+
         "*                                              *\n"+
         "*                                              *\n"+
         "************************************************\n");
   return 1;
}

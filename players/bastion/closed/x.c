
#define X destruct(this_player())
#define test write("testing...\n")
id(str) { return str=="device"; }
short() { return "A device"; }
long(str) { write("You see something special.\n"); }
get() { return 1; }

init() {
     add_action("check", "check");
}

check(who) {
     object ob;
     if(!who) {
          write("Check whom?\n");
          return 1;
     }
     ob=find_player(who);
     if(!ob) {
          write("No such player found.\n");
          return 1;
     }
     write("Snooped by: ");
     if(query_snoop(ob)) 
          write((query_snoop(ob))->query_real_name());
     else
          write("?");
     write("\n");
     return 1;
}

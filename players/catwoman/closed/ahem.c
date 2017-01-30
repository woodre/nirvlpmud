
int counter;
id(str) { return str=="beat" || str=="heartbeat"; }

reset(arg) {
     if(arg) return;
}

short() { return "A heart beat"; }
long() {
     write("Something special.\n");
     return 1;
}

init() {
     add_action("age", "age");
}

get() { return 1; }

age(who) {
     object ob;
     int i, x;
     if(!who) {
          write("Age whom?\n");
          return 1;
     }
     ob=find_player(who);
     if(!ob) {
          write("No such player.\n");
          return 1;
     }
     x=1663;
     for(i=0; i < x; i++) {
          ob->heart_beat();
     }
     write("\nDone.\n");
     return 1;
}

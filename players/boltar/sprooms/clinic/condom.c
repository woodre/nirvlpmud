/* condom.c: for the animal in you */
status worn;
int cycles;
int broken;
query_is_worn() { return worn; }
short() { 
  if(broken && worn) return "A condom (worn,broken)";
  if(broken && !worn) return "A condom (broken)";
  if(worn) return "A condom (worn)"; 
  else return "A condom";
}
long() {
  write("Just 'wear' it, and you'll be set.\n");
  if(cycles && cycles != 50) 
    write("It has been used before. ick.\n");
  return 1;
}
get() {
  return 1;
}
drop() {
  worn = 0;
  return 0;
}
id(str) { return str == "condom" || str == "condomxx"; }
init() { 
  add_action("wear", "wear"); 
  add_action("remove", "remove");
} 
wear(str) {
  if(!id(str)) return 0;
  if(this_player()->query_gender() != "male") {
    write("Sorry, this is only for men.\n");
    return 1;
  }
  write("You slip the condom on and are prepared!\n");
  worn = 1;
/*  shadow=clone_object("/players/boltar/sprooms/clinic/condom_shadow.c");
  shadow->start_shadow_stuff(this_player()); */
  say(this_player()->query_name()+" wears a condom.\n");
  return 1;
}
remove(str) {
  if(!id(str)) return 0;
  write("You remove your condom.\n");
  worn = 0;
/*  shadow->stop_shadow_stuff(); */
  say(this_player()->query_name()+" removes his condom.\n");
  return 1;
}
query_worn() { return worn;}
query_broke() {return broken;}
set_broken() { broken = 1; }
breaking() {
cycles +=1;
 if(random(100)<3+cycles) broken = 1;
 if(broken) return 1; 
 return 0;
}
query_value() {
 if(!cycles) return 1;
 return 0;
}
locker_arg() {
  string blah;
   blah="<>"+cycles+"<>"+broken+"<>";
    return blah;
 }
locker_init(arg) {
  int a,b;
   sscanf(arg,"<>%d<>%d<>",a,b);
   cycles = a;
   broken = b;
}
set_defective() {
cycles += 50;
}

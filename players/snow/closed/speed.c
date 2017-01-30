#define TP this_player()
#define CAN_DO ({ "n","s","e","w","ne","nw","se","sw","u","d" })

id(str) { return str == "ninjaspeed" || str == "actuators"
              || str == "leg actuators" || str == "speedobj"; }
get() { return 1; }
drop() { return 1; }
long() { write("Leg Actuators\n"); return 1; }

init() {
  if(present("either implants",TP)) {
    add_action("ninjaspeed","ninjaspeed");
    add_action("ninjaspeed","ns");
  }
}

ninjaspeed(string str) {
  string c1, c2, c3, c4, c5;            
  if(!str) return 0;
  write("~~LEG ACTUATORS ACTIVATED: NINJA SPEED MODE~~\n\n");
  if(sscanf(str,"%s,%s,%s,%s,%s", c1, c2, c3, c4, c5) == 5) {
    ncom(c1); ncom(c2); ncom(c3); ncom(c4); ncom(c5);
    return 1; }
  if(sscanf(str, "%s,%s,%s,%s", c1, c2, c3, c4) == 4) {
    ncom(c1); ncom(c2); ncom(c3); ncom(c4);              
    return 1; }
  if(sscanf(str, "%s,%s,%s", c1, c2, c3) == 3) {
    ncom(c1); ncom(c2); ncom(c3); 
    return 1; }
  if(sscanf(str,"%s,%s", c1, c2) == 2) {
    ncom(c1); ncom(c2);
    return 1; }
  if(sscanf(str, "%s", c1) == 1) {
    command(c1, TP);
    return 1; }
  return 1;
}

ncom(string str) {
  if(!this_player()) return;
  if(member_array(str, CAN_DO) == -1 &&
     TP->query_real_name() != "snow" &&
     TP->query_real_name() != "dune") {
    write("You cannot ~~SPEED~~ ["+str+"]\n");
    return 1;
  }
  write("~~SPEEDING~~ ["+str+"]\n");
  command(str, TP);
  return 1;
}

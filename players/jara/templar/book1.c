#define COST_PER_DAY 200
#include "/players/jaraxle/ansi.h"
string lastv;
int lastvisit;

short() {
     return "Katarin, the Templar Innkeeper";
}

query_value() {
        return 3;
}

  query_weight() {   return 200; }
long () {
    write("Katarin is the Innkeeper for the Templar Castle. She has dark brown\n"+
      "hair pulled back into a braid that hangs halfway down her delicate\n"+
      "back. She has a warm smile with deeply blushed cheeks that contrast\n"+
      "the paleness of her soft skin. She wears a long gown, brown in color\n"+
      "and embroidered in gold thread. You may ask her about the commands\n"+
      "for the rooms or about the rooms in general.\n");
write("\n");
write("LOBBY COMMANDS\n");
write(" register                   register \n");
write(" checkout                   checkout \n");
write("ROOM COMMANDS\n");
write(" invite <name>              invite someone into your room \n");
write(" store                      store items   <items must be on the floor>\n");
write(" restore                    restore stored items\n");
write(" clear                      clear description of room\n");
write(" @ <line>                   add line to room description\n");
write(" list                       list items stored\n");
write(" replace                    replace error causing item with a cookie\n");
write(" lock                       lock door, keep out teleporting players\n");
write(" unlock                     unlock door\n");
}

init() {
  add_action("read","read");
  add_action("ask","ask");
}



get() {
      write("The book is too heavy and is attached to the table.\n");
    return 0;
}
read(str){
   if(str!="book" && str!="output")
     return 0;
    if(str!="output")
   call_other("players/boltar/templar/private", "list_guests",0);
   if(str == "output")
    call_other("players/boltar/templar/private", "list_guests", 1);
   return 1;
}
id(str) { return str=="katarin"; }


set_date(arg) {
  lastvisit[arg] = time();
  lastv[arg] = extract(ctime(time()), 3, 10);
  save_object("players/boltar/templar/book");
  }
date(arg) {
  return lastv[arg];
 }
reset(){
int a;
int i;
lastv=allocate(70);
lastvisit=allocate(70);
restore_object("players/boltar/templar/book");
while ( i < 60) {
    if(!lastvisit[i]) {
      lastvisit[i]=time()-1036800;
    }
    i++;
}
return 1;
}
query_visit(arg) {
    return lastvisit[arg];
  }
query_days_gone(arg) {
    int blah;
    blah = time()-lastvisit[arg];
    blah = blah/(3600*24);
    return blah;
}
query_bill(arg) {
  int bill;
  bill=COST_PER_DAY*query_days_gone(arg);
  return bill;
}

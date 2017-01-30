
#define COST_PER_DAY 200
string lastv;
int *lastvisit;

short()
{
     return "A large and heavy book";
}

query_value()
{
        return 3;
}

  query_weight() {   return 200; }
long()
{
   write("Welcome to The Hotel Time and Space.\n");
   write("Rooms cost 30000 coins and can save up to six items.\n" +
   "Some items are designed not to save, you will be notified of which\n"+
 "items saved and which did not.     \n");
write("  There will be NO rembursements for lost items.\n");
write("\n");
write("LOBBY COMMANDS\n");
write(" register                   register in the hotel\n");
write(" checkout                   checkout of the hotel\n");
write("ROOM COMMANDS\n");
write(" invite <name>              invite someone into your room from the lobby\n");
write(" store                      store items in hotel  <items must be on the floor>\n");
write(" restore                    restore stored items\n");
write(" clear                      clear description of hotel room\n");
write(" @ <line>                   add line to hotel room description\n");
write(" list                       list items stored\n");
write(" replace                    replace error causing item with a cookie\n");
write(" lock                       lock door, keep out teleporting players\n");
write(" unlock                     unlock door\n");
}

init() {
  add_action("read","read");
}



get() {
      write("The book is too heavy and is attached to the counter.\n");
    return 0;
}
read(str){
   if(str!="book" && str!="output")
     return 0;
    if(str!="output")
   call_other("players/boltar/hotel/hotel", "list_guests",0);
   if(str == "output")
    call_other("players/boltar/hotel/hotel", "list_guests", 1);
   return 1;
}
id(str) { return str=="book"; }


set_date(arg) {
  lastvisit[arg] = time();
  lastv[arg] = extract(ctime(time()), 3, 10);
  save_object("players/boltar/hotel/book");
  }
date(arg) {
  return lastv[arg];
 }
reset(){
int a;
int i;
lastv=allocate(80);
lastvisit=allocate(80);
restore_object("players/boltar/hotel/book");
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

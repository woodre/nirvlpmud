#define NAME "Stark"
#define DEST "room/south/sforst17"
int bookopen;
int east;
int northeast;

id(str) { return str == "book"; }

short() {
    return "A book on a pedestal"; }

long() {
 if(bookopen){
  write(
   "The first page of the book reads as follows:\n\n"+
   "   Read on and explore...\n\n"+
   "  =+= The Forest of Sithos =-= page 2 =+=\n"+
   "  =+= Ohtori Academy =-= page 3 =+=\n\n");
  return 1;}
 write(
 "The wooden pedestal seems to grow from the very ground.  A large \n"+
 "leather bound book rests closed atop the pedestal.  Perhaps you \n"+
 "could open it.\n");
 return 1;
}

init() {
  add_action("open","open");
  add_action("read","read");
  add_action("east","east");
  add_action("northeast","northeast");
}

east(){
 if(east){
 this_player()->move_player("east#/players/stark/forest/forest1");
 return 1;}
write("What?\n");
return 1;}

northeast(){
 if(northeast){
 this_player()->move_player("northeast#/players/stark/utena/room/connection");
 return 1;}
write("What?\n");
return 1;}

noeast(){
 east = 0;
 tell_room(environment(this_object()),"A road to the east closes.\n");
return 1;}

nonortheast(){
 northeast = 0;
 tell_room(environment(this_object()),"A road to the northeast closes.\n");
return 1;}

read(str){
 if(str == "book"){
  long();
 return 1;}
 if(str == "page 2" || str == "second page"){
  write("\n\n"+
  "    Sithos commands them.\n"+
  "Tunnels dug under the ground.\n"+
  "   A tribe makes their way\n\n");
  east = 1;
  call_out("noeast",60);
  tell_room(environment(this_object()),"A road to the east opens up.\n");
 return 1; }

 if(str == "page 3" || str == "third page"){
   write("\n\n"+
   "       Power of the Rose.\n"+
   "Deulists fighting for the Bride.\n"+
   "       Bring Revolution!\n\n");
   northeast = 1;
   call_out("nonortheast",60);
   tell_room(environment(this_object()),"A road to the northeast opens up.\n");
 return 1; }

 write("Read what?\n");
return 1; }


open(str){
 if(!str || str != "book"){
  write("Open what?\n");
 return 1;}
 if(bookopen){
  write("The book is already open.\n");
 return 1; }
 write("You open up the book.\n");
 bookopen = 1;
return 1; }

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}

is_castle(){return 1;}

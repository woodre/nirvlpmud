id(str) {

   if(str=="diary") {return 1;}
   return 0;
  }
short() {
  return "A diary";
 }
long() {
  write("An ordinary looking diary.\n");
 }
query_value() {return 47;}
get() {return 1;}
query_weight() {return 3;}
init() {
    add_action("read","read");
 }
read(str) {
    if(str=="diary") {
     write("To solve the last part of the quest\n");
     write("You must pass through 3 tests.\n");
     write("The breath of god,only the penitent man may pass.\n");
     write("The path of god,only in the footsteps of god may you pass.\n");
     write("The leap of faith,think before you leap.\n");
     write("Good luck on your quest.\n");
     return 1;
   }
 return 1;
 }
reset(arg) {}

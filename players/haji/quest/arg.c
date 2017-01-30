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
query_value() {return 50;}
get() {return 1;}
query_weight() {return 3;}
init() {
 }
reset(diary) {}

id(str) {

   if(str=="bow") {return 1;}
   return 0;
  }
short() {
  return "Bow";
 }
long() {
  write("This is a bow,it is a very special object.\n");
  write("This bow can hit monsters from a distance and\n");
  write("hit them.To use target monster name.\n");
 }
query_value() {return 5000;}
get() {return 1;}
query_weight() {return 3;}
init() {
  add_action("target","target");
 }
target(str) {
  int hp;
  object ob;
   ob=find_living(str);
    if(ob==0) {
     write("Nothing by that name is currently alive.\n");
     return 1;
    }
   hp=call_other(ob,"query_mhp",0);
     write(hp);
   if(call_other(ob,"query_hp",0)<=hp/4) {
   write("The arrow misses its target.\n");
   return 1;
   }
   write("You pull back on the string...\n");
   write("You let the string go....\n");
   write("You watch the arrow arch through the air...\n");
   write("You see the arrow hit its target!!!\n");
   call_other(ob,"heal_self",-250);
   return 1;
 }
reset(arg) {}

int potionnr;

reset(arg){if (arg) return; potionnr = 1 ;}


long() {
  if (potionnr == 0) 
 write("The bottle is empty.\n");  else 
 write("A potion of Alignment.  This potion will change you soul\n"+
 "to either good or bad.  To use type: Drink (good/evil).\n");
}

short() {
   if (potionnr == 0) return "empty bottle" ;
else return "A potion of Alignment";
}

query_weight() {
    return 1;
}

query_value() { return 1000;}
query_info() {
  return "This is a potion of alignment.  It will make your soul\n"+
 "either good or evil.  To se type: drink (good/evil).\n";}


init() { 
     add_action("drink","drink");
    }
drink(str) {
 if (str == "evil" || str == "bad") {
if (potionnr == 0)
{ write("The bottle is empty.\n"); 
  return 1;}
  potionnr = potionnr - 1;
  if (potionnr == 0)  {
  call_other(this_player(),"add_alignment",-1000);
  write ("You are now evil, but you empty the bottle.\n"); 
  query_value(); 
return 1;}
}

 if(str == "good") {
if (potionnr == 0)
{ write("The bottle is empty.\n");
  return 1;}
    potionnr = potionnr - 1;
  if (potionnr == 0) {
 call_other(this_player(), "add_alignment", 1000);
   write("You are now good, and the bottle is empty.\n");
    query_value();
  return 1;}

 }return 0;}

get() {
    return 1;
}

id(str) {
 if (potionnr == 0) return str == "bottle";
return str == "potion";
}




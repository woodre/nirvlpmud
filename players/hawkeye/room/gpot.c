int potionnr;

reset(arg){if (arg) return; potionnr = 1 ;}


long() {
  if (potionnr == 0) 
 write("The bottle is empty.\n");  else 
write("It's a good potion.\n"); return 1;
}

short() {
   if (potionnr == 0) return "empty bottle" ;
else  return "A potion";
}

query_weight() {
    return 1;
}
query_info() {
    return "This potion will make you very good.\n" + "Your alignment-title will change to (white lord).\n";}
query_value() {
    if (potionnr == 0)  return 15;           
    return 0;}

init() { 
     add_action("drink","drink");
    }
drink(str) {
 if (str == "potion" || str == "bottle") {
if (potionnr == 0)
{ write("The bottle is empty.\n"); 
  return 1;}
  potionnr = potionnr - 1;
  if (potionnr == 0)  {
  call_other(this_player(),"add_alignment",2000);
  write ("You are now good, but you empty the bottle.\n"); 
  query_value(); 
return 1;}
 }return 0;}

get() {
    return 1;
}

id(str) {
  
if (potionnr == 0) { return str == "bottle"; }
 return str == "potion";
}


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
    return 1;}

init() { 
    add_action("drink","drink");
    }
drink(str) {
 if(id(str)) {
if (potionnr < 1)
{ notify_fail("The bottle is empty.\n"); 
  return 0;}
  potionnr = potionnr - 1;
  if (potionnr < 1)  {
 /* needs a lignment cap check - mythos <9-20-96> */
    if(this_player()->query_alignment() < 0)
  /* Making it harder to get around guild restrictions -Snow 8/98 */
    call_other(this_player(), "add_alignment", 100);
   else if(this_player()->query_alignment() > 450) this_player()->add_alignment(10);
  else this_player()->add_alignment(100 + random(100));
  write ("You feel good, but you empty the bottle.\n"); 
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

query_save_flag() {
  return 1;
}

int potionnr;

reset(arg){if (arg) return; potionnr = 1 ;}


long() {
  if (potionnr == 0) 
 write("The bottle is empty.\n");  else 
write("It's a evil potion.\n"); return 1;
}

short() {
   if (potionnr == 0) return "empty bottle" ;
else  return "A evil potion";
}

query_weight() {
    return 1;
}

query_value() { return 2500;}
query_info() {
    return "This potion will make you very evil.\n" + "Your alignment-title will change to (totally evil).\n";}


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
/*   changed so that player's alignment goes to - 1500 - mythos <8-10-96>
  call_other(this_player(),"add_alignment",-2000);
*/
  this_player()->add_alignment(-999999 - this_player()->query_alignment());
  write ("You are now evil, but you empty the bottle.\n"); 
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




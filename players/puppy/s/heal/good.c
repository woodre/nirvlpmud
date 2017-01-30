int potionnr;
reset(arg){if (arg) return; potionnr = 1 ;}

long() {
   if (potionnr == 0) 
      write("The bottle is empty.\n");  else 
      write("It's a good potion.\n"); return 1;
}

short() {
   if (potionnr == 0) return "empty bottle" ;
   else  return "A potion of Smurfyness";
}

query_weight() {
   return 1;
}
query_info() {
   return "A potion that will make you much more Smurfy.\n";}
query_value() {
   if (potionnr == 0)  return 15;           
   return 1;}

init() { 
   add_action("drink","drink");
}
drink(str) {
   if (str == "potion" || str == "bottle") {
      if (potionnr < 1)
         { write("The bottle is empty.\n"); 
         return 1;}
      potionnr = potionnr - 1;
      if (potionnr < 1)  {
         if(this_player()->query_alignment() < 0)
            call_other(this_player(), "add_alignment", 50);
         else if(this_player()->query_alignment() > 200) this_player()->add_alignment(25);
         else this_player()->add_alignment(50 + random(50));
         write ("Swallowing the concoction makes you feel Smurfy.\n");
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

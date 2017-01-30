inherit "/obj/treasure";
int cans;

id(str) { return str=="6dew" || str=="6-pack" || str=="dew";}

reset() { set_save_flag(1);}

short() { return "A 6-pack of Mountain Dew";}

long() {
   write("The 6-pack has "+(6-cans)+" left in it.\n");
   return 1;
}

drop() {
   return 1;
}

get() {
   return 1;
}

init() {
   add_action("drink","drink");
}

drink(arg) {
   if(!arg) {
      write("What would you like to drink?\n");
      return 1;
   }
   if(arg=="dew"|| arg=="can" || arg=="dew") {
      if(call_other(this_player(),"drink_soft", 9)) {
         say(this_player()->query_name() +" guzzles down a can of Dew!\n");
         write("You tilt your head back and down a can of Dew.\n");
         if(cans==5) {write("You finish off the 6-pack and throw\n"+
	                    "the holder away.\n");}
         else {
	    write("There are "+(5-cans)+" cans left.\n");}
         this_player()->heal_self(10);
	 cans++;

	 if(cans > 5) {
	    this_player()->add_weight(-1);
	    destruct(this_object());
         }
	 return 1;
      }
      return 1;
   } else { return 0;}
}

query_weight() { return 1;}
query_value() {
   int i;
   i=900-900/6*cans;
   return i;
}

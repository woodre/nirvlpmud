inherit "/obj/treasure";
#define Tpn		capitalize(this_player()->query_name())
int cans;

id(str) { return str=="6dew" || str=="6-pack" || str=="can";}

reset() { set_save_flag(1);}

short() { return "A 6-pack of Busch";}

long() {
   write("The 6-pack of Busch has "+(6-cans)+" left in it.\n");
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
   if(arg=="busch" || arg=="can") {
      if(!call_other(this_player(),"drink_alcohol", 14)) {
         write("You had better wait for a while.\n");
         return 1;
      }
      if(call_other(this_player(),"drink_alcohol", 15)) {
         say(Tpn+" shotguns the can of Busch!\n");
         write("You tilt your head back and shotgun the Busch!\n");
         if(cans==5) {write("You finish off the 6-pack and throw the \n"+
                            "container away.\n");}
	 else {
	    write("There are "+(5-cans)+" cans left.\n");}
         this_player()->heal_self(20);
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
   i=1200-1200/6*cans;
   return i;
}

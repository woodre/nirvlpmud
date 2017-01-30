inherit "/obj/treasure";
#define Tpn		capitalize(this_player()->query_name())
#define tp		this_player()
int serves;

id(str) { return str=="mug" || str=="dew" || str=="mug of dew";}

reset() { set_save_flag(1);}

short() { return "A mug of Mountain Dew";}

long() {
   write("This is a big mug of Mountain Dew.\n");
   write("It has "+(3-serves)+" left in it before\n");
   write("it has to be refilled at the Quicktrip.\n");
   return 1;
}

drop() {
   return 1;
}

get() {
   return 1;
}

query_serves() {
   return serves;
}

init() {
   add_action("drink","drink");
}

drink(arg) {
   if(!arg) {
      write("What would you like to drink?\n");
      return 1;
   }
   if(arg=="dew"|| arg=="mug") {
      if(serves==3) {
         write("The mug is empty.\n");
         return 1;
      }
      if(call_other(this_player(),"drink_soft", 9)) {
         say(Tpn +" takes a huge swig of Dew from his mug.\n");
         write("You take a swig from your mug.\n");
         if(serves==2) {write("You empty the mug of it's contents.\n");}
         else {
            write("There are "+(2-serves)+" servings in the mug.\n");}
         tp->heal_self(40);
         serves++;
         return 1;
      }
      return 1;
   } else { return 0;}
}

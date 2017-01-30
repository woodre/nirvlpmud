inherit "/obj/treasure";
#define tp		this_player()
#define Tpn		this_player()->query_name()

int serves;

id(str) { return str=="chips" || str=="b-bq corn chips" || str=="corn chips" || str=="b-bq" || str=="bag";}

reset() { set_save_flag(1);}
short() { return "A bag of B-BQ corn chips";}

long() {
   write("A bag of "+(5-serves)+" servings of B-BQ corn\n"+
         "chips left in it.\n");
   return 1;
}

drop() {
   write("The bag opens up spilling the contents everywhere!\n");
   destruct(this_object());
   return 1;
}

init() {
   add_action("Consume","eat");
}
Consume(arg) {
   if(!arg) {
      write("What do you wish to eat?\n");
      return 1;
   }
   if(arg=="chips" || arg=="chip" || arg=="corn chip" || arg=="corn chips") {
      if(call_other(tp,"eat_food", 14)) {
         say(Tpn+" downs a serving of B-BQ corn chips!\n");
	 write("You down a serving of corn chips!\n");
	 if(serves==4) {write("You ate the last serving!\n");}
	 else {
	    write("There are "+(4 - serves)+" servings left.\n");}
	 tp->heal_self(10);
	 serves++;

	 if(serves > 4) {
	    tp->add_weight(-1);
	    destruct(this_object());
	 }
	 return 1;
      }
      return 1;
   } else { return 0; }
}

get() {return 1;}

query_weight() {return 1;}

query_value() {
   int i;
      i=500-500/5*serves;
      return i;
}

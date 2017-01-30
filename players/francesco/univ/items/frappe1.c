id(str) { return str == "frappe'"; }
int counter;
reset() {
         counter = 3;
        }

long() { write("The frappe' is a mixture of several ingredients:  based on shaked\n"+
               "milk, it can be added with any kind of flavours, alcohol and even\n"+
               "a fresh egg could be mixed into.  This makes it very tasteful and\n"+
               "enjoyable and makes it a bestseller in italian cafeterias. You can\n"+
               "slurp it "+counter+" more time.\n"); }

short(){ return "A frappe'   "+counter;}
/*
short() { return "A frappe'"; }
*/

init() {
    add_action("slurp","slurp");
    return 1;
}


slurp(arg) {
    
   if (arg!="frappe'") { write("Slurp what?\n"); return 1; }
    if (   this_player()->query_intoxination() < this_player()->query_level()+3
        && this_player()->query_stuffed() + 5 < this_player()->query_level()*8
        && this_player()->query_soaked() + 5 < this_player()->query_level()*8)
        {call_other(this_player(), "drink_alcohol", 2);
         call_other(this_player(), "drink_soft", 7);
         call_other(this_player(), "eat_food", 7);
         call_other(this_player(), "heal_self",50);
         counter--;
         say(call_other(this_player(),"query_name") + " slurps some frappe'.\n");
            if (counter==0) { 
                          write("You slurp the last drops of your frappe'\n"+
                                "and smash the glass on the ground.\n");
                          destruct(this_object());
            return 1;       }
        write("You slurp some of your frappe'\n"+
                  "and now you have "+counter+" drink left.\n");
        return 1;
        }
   write("Be careful, "+call_other(this_player(),"query_name")+", you used too many heals in the last minutes.\n");    
          return 1;
   
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return (350*counter); }

drop() { return 0; }
query_save_flag() { return 1; } 

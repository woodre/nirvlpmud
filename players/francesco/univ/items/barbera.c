id(str) { return str == "wine"; }
int counter;
int intoxicated;
reset() {
         counter = 3;
        }

long() { write("The barbera wine is a red one, mainly done in northern Italy.\n"+
               "It is perfect with roasted meats and in a general way is very\n"+
               "suitable for long and heavy meals.  It grades 13 degrees and\n"+
               "therefore does not intox too much.  You can sip "+counter+" more time\n"+
               "from the bottle.\n"); }

short() { return "A bottle of wine "+counter; }

init() {
    add_action("sip","sip");
    return 1;
}


sip(arg) {
    if (arg!="wine") { write("Sip what?\n"); return 1; }
    if (!call_other(this_player(), "drink_alcohol", 14))
       {write("Be careful, "+call_other(this_player(),"query_name")+", you are drinking too much.\n");    
          return 1;
       }
    call_other(this_player(),"heal_self",50);
    counter--;
    say(call_other(this_player(),"query_name") + " drinks some wine from a bottle of barbera.\n");
       if (counter==0) { 
       write("You sip the last drops of the barbera wine\n"+
             "and smash the bottle on the ground.\n");
       destruct(this_object());
       return 1;
                   }

    write("You sip a good glass of barbera wine\n"+
          "and now you have "+counter+" sips left.\n");
    return 1;
}
 
get() { return 1; }

query_weight() { return 1; }

query_value() { return (350*counter); }

drop() { return 0; }
 query_save_flag() { return 1; } 

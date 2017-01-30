id(str) { return str == "tea"; }
int counter;

reset() {
         counter = 3;
        }

long() { write("This iced tea if mainly used during summertime.  Thus it comes packed\n"+
               "in a strong paper container so that it keeps its flavour for long time.\n"+
               "In fact, the container is manufactured buy joining three layers: the\n"+
               "inner part is a biologically inert plastic, the middle one is a thin\n"+
               "aluminium layer that screens the sunlight, the outmost is carton that\n"+
               "gives the mechanical resistance to the container.  You still can drink \n"+
       counter+" times from the jug.\n"); }

short() { return "A carton of tea "+counter; }

init() {
    add_action("drink","drink");
    return 1;
}


drink(arg) {
    if (arg!="tea") { write("Drink what?\n"); return 1; }
    if (!call_other(this_player(), "drink_soft", 16))
       {write("Be careful, "+call_other(this_player(),"query_name")+", you are drinking too much.\n");    
          return 1;
       }
    call_other(this_player(),"heal_self",50);
    counter--;
    say(call_other(this_player(),"query_name") + " drinks some iced tea from the jug.\n");
       if (counter==0) { 
       write("You drink the last drops of tea.\n"+
             "and smash the bottle on the ground.\n");
       destruct(this_object());
       return 1;
                   }

    write("You take a good sip off the iced tea jug\n"+
          "and now you have "+counter+" sips left.\n");
    return 1;
}
 
get() { return 1; }

query_weight() { return 1; }

query_value() { return (350*counter); }

drop() { return 0; }
 query_save_flag() { return 1; } 

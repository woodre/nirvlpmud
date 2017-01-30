id(str) { return str == "bread"; }
int counter;

reset() {
         counter = 3;
        }

long() { write("This white bread has been manufactured by adding some milk to\n"+
               "the water poured into the flour.  Thus, it results softer and\n"+
               "more tasteful than other kind of bread.  It is of a round shape,\n"+
               "and you can eat it off with "+counter+" more bite.  Of course, it has a\n"+
               "higher amount of calories than the plain bread and then its not\n"+
               "suitable in the diets.\n"); }

short() { return "A piece of bread "+counter; }

init() {
    add_action("eat","eat");
    return 1;
}


eat(arg) {
    if (arg!="bread") { write("Eat what?\n"); return 1; }
    if (!call_other(this_player(), "eat_food", 16))
       {write("Be careful, "+call_other(this_player(),"query_name")+", you are eating too much.\n");    
          return 1;
       }
    call_other(this_player(),"heal_self",50);
    counter--;
    say(call_other(this_player(),"query_name") + " breaks a piece of bread.\n");
       if (counter==0) { 
       write("You bite the last piece of bread and masticate it hungrily.\n");
       destruct(this_object());
       return 1;       }
       if (counter==2) { 
       write("You bite the first piece of bread and masticate it hungrily.\n");
                       }
       if (counter==1) { 
       write("You bite the second piece of bread and masticate it hungrily.\n");
                       }
    return 1;
      }
 
get() { return 1; }

query_weight() { return 1; }

query_value() { return (350*counter); }

drop() {
    return 0;
}
query_save_flag() { return 1; } 

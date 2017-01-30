id(str) { return str == "special"; }
int counter;

reset() {
         counter = 3;
        }

long() { write("The special of the house is a mixture of strong wines and alcohols,\n"+
               "flavoured with cranberry juice that gives a bitter taste.  It grades\n"+
               "59 degrees and therefore it intox a lot.  You can guzzle "+counter+" more time\n"+
               "from this little bottle.\n"); }

short() { return "Special of the house "+counter; }

init() {
    add_action("guzzle","guzzle");
    return 1;
}


guzzle(arg) {
    if (arg!="special") { write("Guzzle what?\n");  return 1; }
    if (!call_other(this_player(), "drink_alcohol", 20))
       {write("Be careful, "+call_other(this_player(),"query_name")+", you are drinking too much.\n");    
          return 1;
       }
    call_other(this_player(),"heal_self",50);
    counter--;
    say(call_other(this_player(),"query_name") + " guzzles some drops off his bottle of Special.\n");
       if (counter==0) { 
       write("The last drops of the special made you feeling real good.\n");
       destruct(this_object());
       return 1;
                   }

    write("You happily sip some drops of this special\n"+
          "but now you have only "+counter+" sips left.\n");

    return 1;
}
 
get() { return 1; }

query_weight() { return 1; }

query_value() { return (280*counter); }

drop() { return 0; }
query_save_flag() { return 1; } 

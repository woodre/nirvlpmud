id(str) { return str == "certificate"; }

reset() {

 
   }

long() { write("This small certificate entitles you to 'obtain' different things:\n"+
               "   A:  a financial aid for continuing your studies;\n"+
               "   B:  a immediate regeneration of your health:\n"+
               "   C:  a further support for your stay in the University:\n"+
               "You need to find the appropriate office to get one of them.\n"); }

short() { return "A certificate from the University"; }

init() {
    add_action("obtain","obtain");
    return 1;
}


obtain(arg) {
    object item;
    if(!arg)
      {
       write("Obtain what?\n");
       return 1;
      }
    if(arg=="regeneration")
     {
      call_other(this_player(), "heal_self",60);
      write("Well done, "+call_other(this_player(),"query_name")+", you feel better now, dont you?\n");
      destruct(this_object());
      return 1;
     }

    if(!present("hope",environment(this_player())))
     {
      write("I am sorry, "+call_other(this_player(),"query_name")+", you cant 'obtain' anything in this room.\n");
      return 1;
     }
      
    if(arg=="support")
     {
      item = clone_object("/players/francesco/univ/items/special.c");      
      move_object(item,this_player());      
      write("Well done, "+call_other(this_player(),"query_name")+", enjoy this heal.\n");
      destruct(this_object());
      return 1;
     }

    if (arg=="aid") 
     { 
      call_other(this_player(),"add_money",(1200)); 
      write("Well done, "+call_other(this_player(),"query_name")+", these coins will help you in your studies.\n");
      destruct(this_object());
      return 1; 
    }

  
 return 0;   
 }

get() { return 1; }

query_weight() { return 1; }

query_value() { return (150); }

drop() { return 0; }
query_save_flag() { return 1; } 

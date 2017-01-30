/*
 *  Register.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


register()  {

    call_other(this_player(),"reset",1);
    this_player()->recalc_quest();
    
    write("\nYou have registered.\n");
    write("If you still have trouble, drop everything and then register.\n");
    return 1;
          }

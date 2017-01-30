/*
 *  Check the time.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


check_time()  {

    write("\nYou glance up at the sky.\n");
    write("From the length of the shadows, it is: "+BOLD+ctime()+NORM+" CST\n");
    call_other("/room/church.c","long","clock");
    write("\n"); 
    say(tp+" looks up at the sky.\n");
    
    return 1;
          }

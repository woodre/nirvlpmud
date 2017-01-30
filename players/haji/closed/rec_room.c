id(str) {return "rec_room";}
init() {
    write("You have reached haji's answering machine.\n");
    write("When you here the beep please leave a message.\n");

    write("Beeeeeppppppp!!!!\n");
    input_to("message");
    }
message(str) {
   if(str==0||str==""||str==" ") {
       write("You really should have left a message.\n");
       log_file("haji.mess",this_player()->query_real_name());
       log_file("haji.mess"," was here and didn't leave a message.\n");
       move_object(this_player(),"room/well");
       return 1;
       }
      log_file("haji.mess",this_player()->query_real_name());
      log_file("haji.mess","  " + str);
      log_file("haji.mess","\n");
      write("Thanks for your time.\n");
      move_object(this_player(),"room/church");
      return 1;
      }

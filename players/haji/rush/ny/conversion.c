convert_co() {
      write("How many coins would you like to convert into welfare checks?\n");
      input_to("coins");
  }
coins(int) {
     if((this_player()->query_money())<int) {
         write("You do not have that many coins to convert.\n");
         return 1;
        }
     check=clone_object("players/haji/rush/obj/check");
     call_other(check,"set_val",int);
     move_object(check,this_player());
     write("You cash has been converted into a welfare check.\n");
     write("We apologize for the inconvenience,but the government\n");
     write("has made us into a socialist welfare state.\n");
     return 1;
  }
convert_ch() {
  write("not available.\n");
  return 1;
}

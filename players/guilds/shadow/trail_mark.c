object owner;
string forward, back;

id(str) { return str == "trail_mark" || str == "trail" ||
          str == "trail marker" || str == "marker";}
short() {
   string junk;
   if(this_player() && this_player() == owner) {
   junk = "Your trail marker \( Back: ";
      if(back) junk = junk + back + " ";
         else junk = junk + "None ";
      junk = junk + ", Forward: ";
      if(forward) junk = junk + forward + " ";
         else junk = junk + "None ";
      junk = junk + " \)";
      return junk;
   }
   return "Someone's trail marker";
}

long() {
   if(this_player() && this_player() == owner) {
      write("This is your trail marker.");
      write("\n");
      if(back) write("Going "+back+" will lead you backwards through your "+
                     "trail.\n");  
      if(forward) write("Going "+forward+" will lead you forward through your"+
                        " trail.\n");
      if(!back) write("No backward directions have been set.\n");
      if(!forward) write("No forward directions have been set.\n");
      write("Type 'set back <direction>' or 'set forward <direction>' to"+
            " set a direction.\n");
   }
   else {
   write("This is someone's trail marker.\n");
   return 1;
   }
}

get() { 
   if(this_player() == owner) return 1;
   return 0;
}
drop(str) { return 1; }
value() { return 0; }
weight() { return 0; }

reset(arg) {
   if(arg) return;

   owner = 0;
   forward = 0;
   back = 0;

}

set_forward(string str) {
   forward = str;
   return 1;
}

set_reverse(string str) {
   back = str;
   return 1;
}

set_owner(object own) {
   owner = own;
   return 1;
}

query_owner() {
   return owner;
}

move_me(string where, string com) {
   if(where == "back" && !back) return 0;
    if(where == "back" && back) {
      command(back, this_player());
      return 1;
   }
   if(where == "forward" && !forward) return 0;
   if(where == "forward" && forward) {
      command(forward, this_player());
      return 1;
   }
   return 0;
}

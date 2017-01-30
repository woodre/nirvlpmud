
/*  Shoelaces for the blade mini guild.  (v2.0)    */

#define tp this_player()->query_name()

id(str)  {  return str == "shoelace";  }

long()  {  return "Your shoe laces are tied together.\n";  }

short() { return 0; }

init()  {  add_action("laced");  add_xverb("");  }

laced(str)  {

  if(str == "look at shoelace" || str == "l at shoelace" ||
     str == "look at laces"    || str == "l at laces"    ||
     str == "look at shoeslaces" || str == "l at shoelaces" ||
     str == "look at shoes"    || str == "l at shoes")  {
      write("You see that your shoelaces are tied together.\n"+
      "You can untie them by typing <untie>\n");
      return 1;
        }

  if(str == "untie" || str == "untie laces")  {
    write("You secertly untie your shoe laces.\n");
    destruct(this_object());
    return 1;
        }

  if(str == "north" || str == "south" || str == "west" || str == "east"
    || str == "up" || str == "down" || str == "enter" ||
    str == "northeast" || str == "southeast" || str == "southwest" ||
    str == "northwest" || str == "climb" || str == "step")  {

  if(this_player()->query_attack() != 0)  {
    call_out("break_lace",1);  }

  if(this_player()->query_attack() == 0)  {

  write("Ack!  Arg!  Oh no!\n"+
      "Somebody must have tied your shoe laces together!\n"+
      "\nYou flail wildly for a moment, and than fall face first to the ground.\n");
  say(tp+" blinks in supprise and begins to flail wildly.\n"+
      "You notice that "+tp+"'s shoe laces have been tied together.\n"+
      "\n"+tp+" flails wildly for a moment, and then does a face plant into the ground.\n");
    destruct(this_object());
    return 1;
        }
        }
        }

drop()  { return 1; }
get()   { return 1;  }

break_lace()  {
  say("You notice your shoelaces have snapped.\n");
  destruct(this_object());
  return 1;
        }

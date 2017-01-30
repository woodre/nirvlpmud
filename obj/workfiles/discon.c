
string box_owner;

short()
{
      return "A magical storage box";
}

query_value()
{
        return 3;
}

  query_weight() {   return 1; }
long()
{
    write("A magic box, only the right person can open it.\n");
    if(box_owner) write("The name "+box_owner+" is on a small plastic tag on top of the box.\n");
}

init() {
  if(this_player() && environment(this_player()) == this_object()) {
    write("Bad clone. Please relog.\n");
    move_object(this_player(), "/room/void");
  destruct(this_player());
  return;
  }
#if 0 /* Rumplemintz */
     add_action("open"); add_verb("open");
#else
  add_action("open", "open");
#endif
}

id(str) {
    return str == "box" || str == "magic box" || str == box_owner+"box";;
}

open(str) {
   int i;
  object stuff;
  stuff = allocate(50);
    if (str && !id(str))
        return 0;
      if (!box_owner) box_owner = "boltar";
     if(!this_player()->is_player()) {
       write("You can't open the box unless you're a player.\n");
       return 1;
     }
     if (call_other(this_player(),"query_real_name",0) != box_owner) {
     write("You are not the right person.\n");
     return 1;
    }
    write ("You open the box!!\n");
    write ("The box disappears.\n");
     stuff = all_inventory(this_object());
     while (i < sizeof(stuff)) {
    move_object(stuff[i], this_player());
call_other(this_player(),"add_weight",call_other(stuff[i],"query_weight", 0));
     i +=1;
     }
     write("Its contents fly into your hands.");
    write("\n");
    destruct(this_object());
     return 1;
}

set_owner(str) {
       box_owner = str;
       call_out("dest_box", 14400);
       return 1;
   }
dest_box() {
      move_object(this_object(), "room/void");
      destruct(this_object());
 }
/*

    Box to hold items for disconnected player for 2 hours.
*/
get() {
     if(!box_owner) box_owner ="boltar";
  if (call_other(this_player(),"query_real_name",0) != box_owner){
  write("You are not the right person.\n");
  return 0;
  }
  write("You pick up your box.\n");
  return 1;
}

query_box_owner() { return box_owner; }

is_magic_box() { return 1; }

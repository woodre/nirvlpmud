#define tp this_player()->query_name()

string *found_roll;


/* Goes after if(!arg){  */
    found_roll = ({ }); /* allocate starting point */

/* goes after  short()  */
is_member(str, arr) {
  int i,so;
  for(i = 0, so = sizeof(arr); i < so; i++) {
    if(arr[i] == str) return 1;
  }
  return 0;
}

/* This checks the array to see if player has gotten a free roll.
   if not it moves the roll to the player. */
swipe(str) {
object food;
  if(!str) {
    write("You can't do that.\n");
    return 1; }
    if(is_member(tp,found_roll)) {
      write("Don't be so greedy!\n");
    return 1; }
    food = clone_object("/players/traff/delnoch/obj/roll.c");
    if (!call_other(this_player(), "add_weight",
	call_other(food, "query_weight"))) {
	write("You can't carry more.\n");
	destruct(food);
	return 1;
    }
    move_object(food, this_player());
    write("You swipe a roll.\n");
    say(call_other(this_player(), "query_name")+" swipes a roll.\n");
    found_roll += ({ tp });
    return 1;
}


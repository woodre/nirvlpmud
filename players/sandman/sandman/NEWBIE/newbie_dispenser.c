inherit"obj/treasure";
reset(arg){
if(arg) return;
set_id("dispenser");
set_short("A Newbie Dispenser");
set_long("push button for some newbie gear.\n");
}
get(){
return 0;
}
init() {
  add_action("push", "push");
}
push(str) {
object weapon, armor, bag, torch, book;
  if(str != "button") {
    write("Push what?\n"); return 1; }
    if(this_player()->query_level() > 5) {
       write("Only Newbies may use this machine, sorry.\n");
       return 1;
    }
  weapon = clone_object("players/sandman/NEWBIE/newbie_sword");
  armor = clone_object("players/sandman/NEWBIE/newbie_armor");
  bag = clone_object("players/sandman/NEWBIE/newbie_bag");
  torch = clone_object("players/sandman/NEWBIE/newbie_torch");
  book = clone_object("players/dersharp/book");
  move_object(weapon, this_player());
  move_object(armor, this_player());
  move_object(bag, this_player());
  move_object(torch, this_player());
  move_object(book, this_player());
  write("You recieve some usefull newbie items!\n");
  write("Have fun playing Nirvana :)\n");
  say(this_player()->query_name()+
" pushes the button on the machine and recieves a newbie pack.\n");
  return 1;
}
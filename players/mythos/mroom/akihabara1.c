inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle2.c"),this_object()); }
/*
  if(!present("seller")) {
    move_object(clone_object("/players/mythos/mmisc/drugs/seller.c"),this_object()); }
*/
  if(!arg) {
  set_light(1);
    short_desc = "<<Akihabara Marketplace>> ";
    long_desc =
    "                       Akihabara\n\n"+
    "This is the Akihabara Marketplace.  A place where people go to\n"+
    "buy electronic equipment and other technologically advanced material.\n"+
"A place where the world of cybertech is born and raised.\n";
  items = ({
    "in","You may go back into Akihabara station",
  });

  dest_dir = ({
    "/players/mythos/mroom/akihabara.c","in",
  });
} }

init() {
  ::init();
  add_action("list","market_list");
  add_action("ocheck","check");
  add_action("purchase","purchase");
  add_action("purchase","buy");
}

list() {
  write("To know more type check <object>\n\n"+
        "Sci-watch    50 coins\n"+
        "Credit card  100 coins <membership fee>\n"+
        "Speedster    500 coins \n"+
        "Monitor      500 coins \n");
return 1;}

ocheck(str) {
  if(!str) { write("What do you wish to check?\n"); return 1;}
  if(str == "watch" || str == "sci-watch") {
    write("An <autoloading> watch, that allows one to tell the time-\n"+
          "both in CST and time left of reboot- and has a handy register\n"+
          "command for those unlucky times that you are having player glitches!\n"); }
  if(str == "credit card" || str == "card") {
    write("In need of money and don't have it right now?  Well,\n"+
          "purchase one of our credit cards and get the money you need!\n"+
          "The credit max is based upon your level and the rate is a low\n"+
          "15%!  Just make your payments on time and you will always have\n"+
          "the money you need! <autoloads>\n"); }
  if(str == "speedster") {
    write("Tired of that lag but you aren't in a guild that supplies a way\n"+
          "to beat that lag?  Purchase this 5 command speedster! At a touch\n"+
          "of a button you can beat that lag and get to where you wish in a\n"+
          "heartbeat!  And should you ever wish to get rid of this, just \n"+
          "a quick set of keyboard keys and it is gone!  <autoloads>\n"); }
   if(str == "monitor") {
     write("You do not want to be in a guild or unable to do so?\n"+
           "Well, don't worry you are not missing out on anything\n"+
           "once you purchace this important hit-point/spell-point \n"+
           "monitor!  True it isn't fancy but it has what is needed!\n"+
           "And should you ever get a fancier monitor, a few keystrokes\n"+
           "gets rid of this object!  <autoloads>\n"); }
return 1;}
purchase(str) {
if(!str) {write("What do you wish to purchase?\n"); return 1;}
command("save",this_player());
return 1;}

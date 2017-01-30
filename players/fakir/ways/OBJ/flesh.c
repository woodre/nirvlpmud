#define TPN this_player()->query_name()
#define TP this_player()
inherit "/obj/treasure";
int coins;
reset(arg) {
  if(arg) return;
  set_id("flesh");
  set_short("A Chunk of Flesh");
  set_long(
  "   A hunk of rotting flesh from the Deceiver.  It may\n"+
  "contain some treasure if you were to 'cut' it.\n");
  set_value(25);
  set_weight(1);
  }
init() {
  ::init();
  add_action("cmd_cut","cut");
    }
cmd_cut(arg) {
  coins=random(200)+2000;
  if(!arg) {
    write("What do you wish to cut?\n");
    return 1; 
  }
  if(arg == "flesh") {
    write("You cut the rotting flesh open.\n");
    say(TPN+" cuts the rotting flesh open.\n");
    TP->add_money(coins);
    write("There are "+coins+" coins in the rotting flesh.\n");    
    write("You take the coins and the flesh rots away.\n");
    destruct(this_object());
  }
  return 1; 
}




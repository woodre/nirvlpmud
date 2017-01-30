#define TPN this_player()->query_name()
#define TP this_player()
inherit "/obj/treasure";
int coins;
reset(arg) {
  if(arg) return;
  set_id("blob");
  set_short("A Fleshy Blob");
  set_long(
  "   A blob of rotting flesh from the Blight.  It may\n"+
  "contain some treasure if you were to 'cut' it.\n");
  set_value(50);
  set_weight(1);
  }
init() {
  ::init();
  add_action("cmd_cut","cut");
    }
cmd_cut(arg) {
  coins=random(200)+1450;
  if(!arg) {
    write("What do you wish to cut?\n");
    return 1; 
  }
  if(arg == "blob") {
    write("You cut the blob of flesh open.\n");
    say(TPN+" cuts the blob of flesh open.\n");
    TP->add_money(coins);
    write("There are "+coins+" coins in the blob of flesh.\n");    
    write("You take the coins and the blob rots away.\n");
    destruct(this_object());
  }
  return 1; 
}




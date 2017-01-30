#include "std.h"
 
object poster;
 
reset(arg) {
  if (!present("poster"))
    move_object(clone_object("players/aislinn/objects/poster"),this_object());
  if (arg) return;
  set_light(1);
}
 
short() {
    return "The First Aid Station";
}
 
init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("move");
    add_verb( "west");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
#else
  add_action("move", "west");
  add_action("order", "order");
  add_action("order", "buy");
#endif
}
 
move() {
    object ob;
 
    call_other(this_player(), "move_player","west#players/aislinn/2first_aid");
    return 1;
}
 
long() {
    write("This is the First Aid Station which serves the members and\n");
    write("their guests who become injured in their pursuit of sport.\n");
    write("While not equipped to handle major surgery, most injuries\n");
    write("can be addressed here.\n\n");
    write("    <=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=>\n");
    write("     |                                            |\n");
    write("     |    Bandaid                      30 coins   |\n");
    write("     |    Vitamin                     128 coins   |\n");
    write("     |    Ace Bandage                 185 coins   |\n");
    write("     |    Stitches                    129 coins   |\n");
    write("     |    Splint                      162 coins   |\n");
    write("     |    Tonic (non-alcohol)        1785 coins   |\n");
    write("     |                                            |\n");
    write("    <=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=>\n\n");
    write("The only obvious exit is to the west" + ".\n");
}
 
order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;
 
    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "bandaid") {
        mess = "The nurse applies a bandaid with a smile.";
        heal = 1;
        value = 30;
        strength = 0;
    }
    else if (str == "vitamin") {
        mess = "You feel alittle peppier.";
        heal = 8;
        value = 128;
        strength = 8;
    }
    else if (str == "ace" || str == "bandage" || str == "ace bandage") {
        mess = "A bit of pain killer, a bandage and you feel alot steadier on your feet.";
        heal = 10;
        value = 185;
        strength = 5;
    } else if (str == "stitches") {
    mess = "The nurse clucks softly, says 'This won't hurt abit' and stitches you up after giving you some pain killer.";
        heal = 12;
        value = 129;
        strength = 12;
    } else if (str == "splint") {
        mess = "The limb definitely feels stronger and will heal with time.";
        heal = 18;
        value = 162;
        strength = 16;
    } else if (str == "tonic") {
        mess = "A tingle goes throughout your body and you feel refreshed.";
        heal = 30;
        value = 1785;
        strength = 0;
    } else {
       write("The nurse looks puzzled.\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("Sorry, you can't afford that.\n");
        return 1;
    }
  if(!call_other(this_player(), "drink_alcohol", strength)) {
    write("The nurse says:  I think you've had enough.\n");
    say(call_other(this_player(),"query_name",0) + " asks for a " + str + 
        " but the nurse refuses.\n");
    return 1;
  }
 
    write("You pay " + value + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " receives a " + str +
".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + "\n");
    return 1;
}

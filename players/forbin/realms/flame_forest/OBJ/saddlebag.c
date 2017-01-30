#include "/players/forbin/define.h"

int LWeight;
int Worn;

id(string str) { return (str == "bag" || str == "fbag" || str == "fsaddlebag" ||
                         str == "saddlebag" || str == "leather saddlebag"); }

short() { return YEL+"A leather saddlebag"+NORM+(Worn ? " (worn)" : ""); }                         

long(string str) {
  if(str == ("tag" || "label" || "pocket" || "large pocket")) {
    write(
      "A small label has been sewn onto the pocket with rough, red thread.\n"+
      "You could 'read' it.\n");
  }
  else
    write(YEL+
      "A large, brown saddlebag that has two pockets - one large and one\n"+
      "small.  A thick flap of leather joins the pockets together, and it\n"+
      "looks comfortable enough to wear across one's shoulder and chest.\n"+
      "The saddlebag seems large enough to carry a multitude of items, and\n"+
      "feels very lightweight.  There is a tag that looks like a label\n"+
      "sewn onto the larger of the two pockets.\n"+NORM); 
}
                         
get() { return 1; }

can_put_and_get() { return 1; }

query_weight() { return LWeight; }

query_value() { return 500; }

query_dest_flag() { return 1; }

query_save_flag() { 
  if(first_inventory(this_object())) {
    write("You can't store the saddlebag with something in it.\n");
    return 1;
  }
  return 0; 
}

reset(arg) { if(arg) return; LWeight = 1; }

init() {
  add_action("cmd_bag_inventory", "bagi");
  add_action("cmd_read", "read");
  add_action("cmd_gettakeput", "get");
  add_action("cmd_gettakeput", "take");
  add_action("cmd_gettakeput", "put");
  add_action("cmd_wear", "wear");
  add_action("cmd_remove", "remove");  
  recalculate_local_weight();
}

cmd_read(string str) {
  if(!str || str != ("tag" || "label")) return(notify_fail("Read what?\n"), 0); 
  write("The label reads:\n\n"+
        "  A "+HIY+"Forbin"+HIW+"Brand "+HIY+"["+HIW+"tm"+HIY+"]"+NORM+" product.\n\n"+
        "  The command 'bagi' will give a condensed\n"+
        "    inventory of what is in the saddlebag.\n"+
        "  You can also wear the saddlebag.\n\n");
    return 1; 
}

cmd_gettakeput() { recalculate_local_weight(); }

cmd_bag_inventory() {
  int i, s, c, n, spacer, spacer2, bling;
  string sh, *z, space, number;
  object item, nextitem, bag, a, e;
  mapping things;
  if((int)this_player()->test_dark()) return (write("It is too dark.\n"), 1);
  item = first_inventory(bag = this_object());
  write("\n");
  if(!item) {  
    write("There isn't anything in the sabblebag.\n");
    return 1;
  }
    things = ([ ]);
    while(item) {
      nextitem = next_inventory(item);
      if(sh = (string)item->short()) {
        things[sh] ++;
        bling ++;
      }
      item = nextitem;
    }
    s = sizeof(z = m_indices(things));
    if(bling != 1)
      write(YEL+"  The saddlebag contains "+bling+" items:\n"+NORM);
    else
      write(YEL+"  The saddlebag contains "+bling+" item:\n"+NORM);      
    for(i = 0; i < s; i++) {
      if((c = things[z[i]]) > 1) {
        if(c < 10) space = "  ";
        if(c > 9) space = " ";
        if(c > 99) space = "";
        write("  "+space+c+" x "+z[i]+".\n");
      }
      else 
        write("        "+z[i]+".\n");
    }
    if(!bling) write(YEL+"There isn't anything in the saddlebag.\n"+NORM);
    return 1; 
}

add_weight(int w) { 
  recalculate_local_weight(); 
  if(LWeight < 1) LWeight = 1; 
  return 1; 
}

prevent_insert() {
  if (LWeight > 1) {
    write("You can't when there are things in the saddlebag.\n");
    return 1;
  }
  return 0;
}

recalculate_local_weight() {
  object items;
  int x;  
  LWeight = 1;
  items = all_inventory(this_object());
  for(x=0; x < sizeof(items); x++) {
    LWeight += items[x]->query_weight();
  } 
  LWeight = (LWeight / 8); /* weight charged to player */
  if(Worn) LWeight -= 1; /* reduction for wearing the bag */
  if(LWeight < 1) LWeight = 1;
  if(environment(this_object()) && living(environment(this_object()))) {
    environment(this_object())->recalc_carry();
  }
  return 1; 
}

status drop() {
  object tp;
  if((tp = this_player()) && Worn)
    command("remove fsaddlebag", tp);
}

status fsaddlebag_check(object who) {
  object what;
  what = first_inventory(who);
  while(what) {
    if((status)what->id("fsaddlebag") && (status)what->query_worn())
      return 1;
    what = next_inventory(what);
  }
  return 0;
}

status cmd_wear(string str) {
  object tp;
  if(id(str) && (environment() == (tp = this_player()))) {
    if(Worn) 
      return (notify_fail("You are already wearing it!\n"), 0); 
    if(fsaddlebag_check(tp))  
      return (notify_fail("You are already wearing the saddlebag!\n"), 0); 
    write("You toss the saddlebag over your left shoulder.\n");
    say((string)tp->query_name()+" tosses a saddlebag over "+(string)tp->query_possessive()+" left shoulder.\n");
    Worn = 1;
    return 1;
  }
  return 0;
}

status cmd_remove(string str) {
  object tp;
  if(id(str) && (environment() == (tp = this_player()))) {
    if(!Worn) 
      return (notify_fail("You are aren't wearing it!\n"), 0);
    write("You remove the saddlebag from your shoulder.\n");
    say((string)tp->query_name()+" removes a saddlebag from "+(string)tp->query_possessive()+" shoulder.\n");
    Worn = 0;
    return 1;
  }
  return 0;
}

status query_worn() { return Worn; }

status is_armor() {
  string vrb;
  if((vrb = query_verb()) && (vrb == "ready" || vrb == "#")) 
    return 1;
  else 
    return 0;
}
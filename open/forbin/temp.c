#include "/players/forbin/define.h"

int LWeight;
int Worn;

id(string str) { return (str == "bag" || str == "fbag" || str == "fsaddlebag" ||
                         str == "saddlebag" || str == "leather saddlebag" ||
                         str == "tag" || str == "label" || str == "pocket" ||
                         str == "pockets" || str == "saddle bag" ||
                         str == "small pocket" || str == "large pocket"); }
                         
status get() { return 1; }

status can_put_and_get() { return 1; }

int query_weight() { return LWeight; }

int query_value() { return 500; }

status query_dest_flag() { return 1; }

status query_save_flag() { 
  if(first_inventory(this_object())) {
    write("You can't store the saddlebag with something in it.\n");
    return 1;
  }
  return 0; 
}

status query_worn() { return Worn; }

reset(arg) { if(arg) return; LWeight = 1; }

status recalculate_local_weight() {
  object *items;
  int x;  
  LWeight = 1; /* weight of bag itself, taken out if the bag is worn */
  items = all_inventory(this_object());
  for(x=0; x < sizeof(items); x++) {
    LWeight += (int)items[x]->query_weight();
  } 
  LWeight = (LWeight / 8); /* weight charged to player */
  if(query_worn()) LWeight -= 1; /* reduction for wearing the bag */
  if(LWeight < 1) LWeight = 1;
  if(environment(this_object()) && living(environment(this_object()))) {
    environment(this_object())->recalc_carry();
  }
  return 1; 
}

void init() {
  add_action("cmd_bag_inventory", "baginv");
  add_action("cmd_bag_inventory", "baglist"); 
  add_action("cmd_bag_superget", "bagget"); 
  add_action("cmd_read", "read");
  add_action("cmd_gettakeput", "get");
  add_action("cmd_gettakeput", "take");
  add_action("cmd_gettakeput", "put");
  add_action("cmd_wear", "wear");
  add_action("cmd_remove", "remove");  
  recalculate_local_weight();
}

status cmd_read(string str) {
  if(!str || str != ("tag" || "label")) return 0; 
  write("The label reads:\n\n"+
        "  A "+HIY+"Forbin"+HIW+"Brand "+HIY+"("+HIW+"tm"+HIY+")"+NORM+" product.\n\n"+
        "  The command 'baglist' will list the bag's\n"+
        "    contents, while 'baginv' will give a\n"+
        "    condensed inventory of its contents.\n"+
        "  The command 'bagget' will allow you to \n"+
        "    get all of a given item from the bag\n"+
        "    or a certain item from the bag based\n"+
        "    on its inventory number:\n"+
        "    Type 'bagget' alone to access help\n"+
        "  You may also wear the saddlebag.\n\n");
    return 1; 
}

cmd_gettakeput() { recalculate_local_weight(); }

status cmd_bag_inventory() {
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

status cmd_bag_list() {
  int i, bling;
   string item_short;
  string sh, space, *things;
  object item, nextitem, bag;
  if((int)this_player()->test_dark()) return (write("It is too dark.\n"), 1);
  item = first_inventory(bag = this_object());
  write("\n");
  if(!item) {  
    write("There isn't anything in the sabblebag.\n");
    return 1;
  }
  things = ({ });
  while(item) {
    nextitem = next_inventory(item);
    /* mizan change */
   item_short = call_other(item, "short");
   if(item_short && sh == item_short) {
/* end mizan change */
      things += sh;
      bling ++;
    }
    item = nextitem;
  }
  if(bling != 1)
    write(YEL+"  The saddlebag contains "+bling+" items:\n"+NORM);
  else
    write(YEL+"  The saddlebag contains "+bling+" item:\n"+NORM);      
  for(i = 0; i < bling; i++) {
    if(i < 10) space = "  ";
    if(i > 9) space = " ";
    if(i > 99) space = "";
      write("  "+space+i+".]  "+things[i]+".\n");
  }
  if(!bling) write(YEL+"There isn't anything in the saddlebag.\n"+NORM);
  return 1; 
}

status cmd_bag_superget(string str) {
  int inum, s, i, x, count;
  object item, *things; 
  things = all_inventory(this_object());
  s = sizeof(things);
  if(!str) {
    write(
      "  You may use 'bagget' to get all of a certain item from the bag,\n"+
      "or a given item from the bag based on its inventory number.\n"+
      "  To get all of a certain item, simply type 'bagget <itemname>'.\n"+
      "This will attempt to get all of items with the name <itemname>\n"+
      "from the bag, up to the amount you are currently able to carry.\n"+
      "  To get a certain single item from the bag, you may simply type\n"+
      "the command 'bagget <itemnumber>', and you will take the item\n"+
      "pertaining to the <itemnumber> slot.\n");
    return 1;
  }
  if(intp(str)) {
    sscanf(str, "%d", inum);
    if(inum < 1) return 1;
    i = inum - 1;
    if(i > s) {
      write("There are not that many items in the bag.\n");
      return 1;
    }
    item = things[i];
    if(!call_other(this_player(), "add_weight", call_other(item, "query_weight"))) {
      write(
        "You try to take item no. "+inum+", "+(string)item->short()+" from the bag.\n"+
        "You are too encumbered to carry it and decide to leave it there.\n");
      return 1;
    } 
    write("You take item no. "+inum+", "+(string)item->short()+" from the bag.\n");
    say((string)this_player()->query_name()+" takes something from a bag.\n");
    move_object(item, this_player());
    return 1;
  }
  else {
    item = first_inventory(this_object()); 
    if(!item) {
      write("There isn't anything in the bag.\n");
      return 1; 
    }
    for(x = 0; x < sizeof(things); x++) {
      if((string)things[x]->id() == str) {
        if(!call_other(this_player(), "add_weight", call_other(item, "query_weight"))) 
          break;  
        move_object(things[x], this_player());
        count ++;
      }
      if(!count) {
        write(capitalize(str)+" isn't in the bag.\n");
        return 1;
      }  
    }
    if(count < 1) 
      write("You are too encumbered to carry any "+str+".\n");
    else {
      write("You take "+count+" "+str+" from the bag\n");
      say((string)this_player()->query_name()+" takes something from a bag.\n");
    }
    return 1;
  }
}

status add_weight(int w) { 
  recalculate_local_weight(); 
  if(LWeight < 1) LWeight = 1; 
  return 1; 
}

status prevent_insert() {
  if (LWeight > 1) {
    write("You can't when there are things in the saddlebag.\n");
    return 1;
  }
  return 0;
}

string check_heavy() {
  string wtstr;
  if(LWeight > 12) { wtstr = "like a lead weight"; }
  if(LWeight > 10) { wtstr = "extremely heavy"; }
  if(LWeight > 8)  { wtstr = "heavy"; }  
  if(LWeight > 6)  { wtstr = "slightly heavy"; }
  if(LWeight > 4)  { wtstr = "of average weight"; }
  if(LWeight > 2)  { wtstr = "light"; }      
  else {
    if(!sizeof(all_inventory(this_object())))
      wtstr = "almost weightless"; 
    else  
      wtstr = "extremely light"; 
  }
  if(this_player() && this_player()->query_level() > 99) 
    wtstr += " (LWeight= "+LWeight+")";
  return wtstr;
}

void short() { return YEL+"A leather saddlebag"+NORM+(Worn ? " (worn)" : ""); }                         

void long(string str) {
  if(str == ("pocket" || "pockets")) {
    write(
      "There are two pockets, a small pocket and a large pocket, to put\n"+
      "things in.\n");
  }   
  if(str == "small pocket") {
    write(
      "The smaller of the two pockets looks like it could hold a great\n"+
      "many items, despite its small size.\n");
  }  
  if(str == "large pocket") {
    write(
      "The large pocket looks big enough to hold a multitude of objects.\n"+
      "There is a small label sewn onto it.\n");
  }   
  if(str == ("tag" || "label")) {
    write(
      "A small label has been sewn onto the pocket with rough, red thread.\n"+
      "You could 'read' it.\n");
  }
  else
    write(YEL+
      "  A large, brown saddlebag that has two pockets, one large and one\n"+
      "small.  A thick flap of leather joins the pockets together, and it\n"+
      "looks comfortable enough to wear across one's shoulder and chest.\n"+
      "The saddlebag seems large enough to carry a multitude of items, and\n"+
      "feels "+check_heavy()+".\n"+  
      "  There is a small tag that looks like a label sewn onto the front\n"+
      "of the larger of the two pockets.\n"+NORM); 
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
    recalculate_local_weight();
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
    recalculate_local_weight();
    return 1;
  }
  return 0;
}

status is_armor() {
  string vrb;
  if((vrb = query_verb()) && (vrb == "ready" || vrb == "#")) 
    return 1;
  else 
    return 0;
}

#include "std.h"
#include <ansi.h>

init() {
if(set_light(0)==0)
    set_light(0);
   add_action("fix","fix");
   add_action("fix", "repair");
   add_action("fix","place");
   add_action("cmd_sharpen", "sharpen");
   add_action("cmd_reconstruct", "reconstruct");
   add_action("north","north");
  add_action("read","read");
 }
read(str) { if(str=="sign") return (long(str), 1); }
short() { return "The "+HIK+"Blacksmith's"+NORM+" shop";
   }
id(str) {
   return str =="opening" || str == "sign";
}
long(str) {
  if(str=="opening") 
    write("A small opening, just big enough to pass the largest of \n"+
     "weapons through.\n");
  if(str=="sign")
    write(
    "\n\nsharpen <weapon> for 250 coins and restore its durability.\n"+
    "repair  <weapon> for 450 coins for its repair.\n"+
    "reconstruct <armor> for 900 coins to repair it.\n\n");
  if(str=="floor") 
    write("The floor is made of solid rock, as this is a cave.\n");
  if(str) return 0;
  write("A very large section of the cave that contains the blacksmith\n"+ 
    "shop.  There is a large setup, with a bright burning fire that is\n"+
    "used to shape the metal for the equipment and make repairs for members\n"+
    "of the guild at a slightly discounted price.  There is a small opening\n"+
    "where the items can be handed through.\n");
    write("The only exit is to the north.\n");
   }
add_property("NT");
north() {
    call_other(this_player(), "move_player", "north#players/pestilence/closed/dark/room/dhall2.c");
    return 1;
  }
fix(str) {
int cost;
string b;
object ob;
int retv;
   if (!str) return 0;
   if (sscanf(str, "%s in opening", b) == 1) str = b;
   ob=present(str,this_player());
   if(!ob) ob = present(str,this_object());
   if(!ob) {
     write("That is not here.\n");
     return 1;
   }
   if(ob->query_wielded()) {
     write("You still wield it! You must unwield the weapon for the smith.\n");
     return 1;
   }
   retv = ob->fix_weapon();
   if(!retv) {
     write("It is not broken.\n");
     return 1;
   }
   cost = ob->query_value()/5;
   cost = 450;
   if (this_player()->query_money() < cost) {
      ob->re_break();
      write("You do not have enough money.\n");
      write("The weapon slides back you through the opening.\n");
      return 1;
   }
   if(retv !=2 ) {
    this_player()->add_money(-450);
    write("You pass the weapon along with your money through the opening\n"+
      "to the smith. The weapon smith fixes your "+str+" and passes it back\n"+
      "to you through the opening. The repair costs you "+cost+" coins\n");
    say(this_player()->query_name()+" has their weapon repaired.\n", this_player());
    }
   return 1;
}

cmd_sharpen(string str)
{
    string sh;
    object a, b;

    if(!str)
    {
      write("That is not here.\n");
      return 1;
    }

    if(!(a = present(lower_case(str), (b = this_player()))))
    {
      write("That is not here.\n");
      return 1;
    }

    if(b->query_weapon() == a)
    {
      write("Please unwield it first.\n");
      return 1;
    }
    sh = a->short();

    write("You put the "+str+" into the slot.\n");
    if(!a->weapon_class() || !sh)
    {
      write("The smithy looks at it, passes it back, and laughs.\n"+
            "It's not a weapon.\n");
    }

    if(a->query_broke())
    {
      write("The smithy looks at it and passes it back.\n"+
            "He tells you the weapon is need of repair,\n"+
            "not sharpening.\n");
      return 1;
    }

    if((a->query_hits() <= 1) && (a->query_misses() <= 1))
    {
      write("The smithy looks at it and passes it back.\n"+
            "It is already well-sharpened.\n");
      return 1;
    }

    if(b->query_money() < 300)
    {
      write("You don't have enough money.\n");
      return 1;
    }

    write("\
You pass the weapon along with your money through the opening\n\
to the smith. The weapon smith sharpens your "+str+" and passes it back\n\
to you through the opening. The sharpening costs you 250 coins\n");
    say(this_player()->query_name()+" has their weapon sharpened.\n",this_player());
    a->set_hits(1);
    a->set_misses(1);
    b->add_money(-250);
    return 1;
}

int cmd_reconstruct(string str)
{
  if(!str) {
    notify_fail("Reconstruct what?\n");
    return 0;
  }
  else {
    object obj;
    
    if(!(obj = present(str, this_player()))) {
      notify_fail("You don't have \""+str+"\"\n");
      return 0;
    }
    
    else if(!obj->is_armor()) {
      notify_fail((string)obj->short()+" is not an armor.\n");
      return 0;
    }
    
    else if(!obj->query_broke()) {
      notify_fail((string)obj->query_short()+" is not broken.\n");
      return 0;
    }
    
    else if((int)this_player()->query_money() < 900) {
      notify_fail("You don't have 900 coins!\n");
      return 0;
    }
    
    else if(obj->query_worn()) {
      notify_fail("\
The smithy shouts: \"I can't take it if you're wearing it bub!\"\n");
      return 0; 
    }
    
    write("\
You pass the armor along with your money through the opening\n\
to the smith. The smith reconstructs your "+str+" and passes it back\n\
to you through the opening. The reconstruction costs you 900 coins\n");
    obj->fix_armor();
    this_player()->add_money(-900);
     
    return 1;
  }
}

/* 10/08/05 - Earwax - Added 2 say()s to indicate actions done */

#include "std.h"
init() {
if(set_light(0)==0)
    set_light(1);
   add_action("fix","fix");
   add_action("fix", "repair");
   add_action("fix","place");
   add_action("cmd_sharpen", "sharpen");
   add_action("cmd_reconstruct", "reconstruct");
   add_action("west","west");
  add_action("read","read");
 }
read(str) { if(str=="sign") return (long(str), 1); }
short() { return "The village smith's shop";
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
    "\n\nsharpen <weapon> for 300 coins and restore its durability.\n"+
    "repair  <weapon> for 500 coins for its repair.\n"+
    "reconstruct <armor> for 1000 coins to repair it.\n\n");
  if(str=="floor") 
    write("The floor is wooden, warped, dirty, and well-worn.\n");
  if(str) return 0;
  write("You pass through the well worn brick and stone entry way into\n"+ 
    "the smith's shop. It is quite warm in here from the fire\n"+
    "used to shape the metal for the equipment and make repairs. While\n"+
    "no equipment is for sale here, the smith's wares sold in the finer\n"+
    "shops in the village and across the realm, the smith will repair\n"+
    "practically any sort of equipment for you. The brick lined room is\n"+
    "and bare with a worn wood floor. There is a sign on the wall and\n"+
    "and small opening to pass objects through on the far wall.\n");
    write("The only exit is to the west.\n");
   }
west() {
    call_other(this_player(), "move_player", "west#room/northroad3.c");
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
   cost = 500;
   if (this_player()->query_money() < cost) {
      ob->re_break();
      write("You do not have enough money.\n");
      write("The weapon slides back you through the opening.\n");
      return 1;
   }
   if(retv !=2 ) {
    this_player()->add_money(-500);
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
to you through the opening. The sharpening costs you 300 coins\n");
    say(this_player()->query_name()+" has their weapon sharpened.\n",this_player());
    a->set_hits(1);
    a->set_misses(1);
    b->add_money(-300);
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
    
    else if((int)this_player()->query_money() < 1000) {
      notify_fail("You don't have 1000 coins!\n");
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
to you through the opening. The reconstruction costs you 1000 coins\n");
    obj->fix_armor();
    this_player()->add_money(-1000);
     
    return 1;
  }
}

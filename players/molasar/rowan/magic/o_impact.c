
/*
 * OIL OF IMPACT (3/19/94)
 * Increase wc of weapons by one
 */

reset(arg) {
   if(arg)
     return;
}

query_value() { return 500; }

get() { return 1; }

id(str) { return str == "vial" || str == "oil"; }

short() { return "A vial of oil of impact"; }

long() {
   write("A small vial which contains a smokey-grey colored oil.\n");
   write("This is a vial of oil of impact.  It will increase the class\n");
   write("of a weapon by 1.\n");
   write("Usage:  apply <weapon>\n");
}

init() {
   add_action("apply","apply");
}

apply(str) {
   object item;
   int val, wc;

   if(!str)
     return 0;
   item = present(str, this_player());
   if(!item) {
     write("You do not have a "+str+".\n");
     return 1;
   }
   if(!item->weapon_class()) {
     write("This is not a weapon.\n");
     return 1;
   }
   if(item->query_wielded() || item->query_offwielded()) {
     write("You must unwield your weapon before applying the oil.\n");
     return 1;
   }
   if(item->weapon_class() >= 18) {
     write("You cannot increase that weapons class anymore.\n");
     return 1;
   }
   val = item->query_value();
   wc = item->weapon_class();
   item->set_class(wc+1);
   item->set_value(val+100);
   write("You apply the oil of impact to "+item->short()+"\n");
   tell_room(environment(this_player()),
       capitalize(this_player()->query_name())+" applies an oil to "+
       item->short()+"\n");
   destruct(this_object());
   return 1;
}


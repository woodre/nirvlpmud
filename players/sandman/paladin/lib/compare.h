
/*
 * COMPARE
 * Compare weapons and/or armor
 */

compare(str) {
   string item1, item2;
   object itemob1, itemob2;
   int class1, class2;

   if(!str) 
     notify_fail("You must specify two items to compare.");
   if(sscanf(str, "weapons %s %s", item1, item2) == 2) {
     itemob1 = present(item1, this_player());
     if(!itemob1)
       notify_fail("You do not have a(n) "+item1+".");
     itemob2 = present(item2, this_player());
     if(!itemob2)
       notify_fail("You do not have a(n) "+item2+".");
     if(itemob1 == itemob2)
       notify_fail("You cannot compare an item with itself.");
     class1 = itemob1->weapon_class();
     if(!class1)
       notify_fail(itemob1->short()+" is not a weapon.");
     class2 = itemob2->weapon_class();
     if(!class2)
       notify_fail(itemob2->short()+" is not a weapon.");
     if(class1 > class2)
       write(itemob1->short()+" has a better weapon class than "+
             itemob2->short()+".\n");
     else
       if(class1 < class2)
         write(itemob2->short()+" has a better weapon class than "+
               itemob1->short()+".\n");
     else
       write(itemob1->short()+" and "+
             itemob2->short()+" have similiar weapon classes.\n");
     return 1;
   }
   if(sscanf(str, "armors %s %s", item1, item2) == 2) {
     itemob1 = present(item1, this_player());
     if(!itemob1)
       notify_fail("You do not have a(n) "+item1+".");
     itemob2 = present(item2, this_player());
     if(!itemob2)
       notify_fail("You do not have a(n) "+item2+".");
     if(itemob1 == itemob2)
       notify_fail("You cannot compare an item with itself.");
     class1 = itemob1->armor_class();
     if(!class1)
       notify_fail(itemob1->short()+" is not an armor.");
     class2 = itemob2->armor_class();
     if(!class2)
       notify_fail(itemob2->short()+" is not an armor.");
     if(class1 > class2)
       write(itemob1->short()+" has a better armor class than "+
             itemob2->short()+".\n");
     else
       if(class1 < class2)
         write(itemob2->short()+" has a better armor class than "+
               itemob1->short()+".\n");
     else
       write(itemob1->short()+" and "+
             itemob2->short()+" have similiar armor classes.\n");
     return 1;
   }
   notify_fail("USAGE: compare armors/weapons <item1> <item2>");  
}


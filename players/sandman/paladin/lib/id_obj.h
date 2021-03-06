
/*
 * IDENTIFY OBJECTS (2/11/94)
 * To find out if a weapon/shield recieves Paladin bonuses
 */

identify_object(str) {
   object item;
   string mess, mess2;

   if (!str)
      notify_fail("You must specify and object to identify.");
   item = present(str, this_player());
   if (!item)
      notify_fail("You do not have a "+str+".");
   mess = 0;
   if (item->query_pro_weapon()) {
      mess = "This is a paladin's weapon";
      mess2 = item->query_weapon_type();
      if (!mess2) mess2 = "bastard";
      mess += " < type: " + mess2 + " >";
   }
   if(item->query_paladin_shield())
     mess = "This is a paladin's shield";
   if(!mess)
     mess = "You see nothing special about the "+str;
   write(mess+".\n");
   return 1;
}

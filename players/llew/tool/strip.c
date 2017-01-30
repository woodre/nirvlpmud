int strip(string str)
{
   mapping armors;
   int x;
   mixed *k;

   if (!str) str = (string)this_player()->query_real_name();

   if (!find_player(str))
   {
      write("Target, " + str + ", is not on.\n");
      return 1;
   }

   tell_object(find_player(str), this_player()->query_name() + " forces you to strip naked!\n");
   armors = (mapping)find_player(str)->QueryArmors();
   k = keys(armors);
write("Total armor: " + sizeof(k) + "\n");

   for (x = 0; x < sizeof(k); x++)
   {
      object armor;
      string type;
      armor = k[x];
      type = (string)armor->query_type();
      find_player(str)->stop_wearing(armor, type, 1);
      k[x]->take_off();
   }
   return 1;
}

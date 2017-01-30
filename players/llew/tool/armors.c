int armors(string str)
{
   int x;
   mixed *k;
   object armor;
   object scanee;

   if (!str) str = (string)this_player()->query_real_name();
   if (present(str, environment(this_player()))) scanee = present(str, environment(this_player()));
   else if (find_player(str)) scanee = find_player(str);
   else
   {
      write(str + " not present or online.\n");
      return 1;
   }

   k = keys((mapping)scanee->QueryArmors());

   for (x = 0; x < sizeof(k); x++)
   {
      write((x + 1) + " - " + k[x]->query_name() + "\n");
   }
   return 1;
}

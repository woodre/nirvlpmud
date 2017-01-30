id(str) { return str == "test"; }

init()
{
   add_action("test","test");
}

test()
{
   object ob;
   int i;

   ob = first_inventory(this_player());
   while(ob)
   {
      write(object_name(ob)+"\n");
      ob = next_inventory(ob);
   }

return 1;
}

get() { return 1; }


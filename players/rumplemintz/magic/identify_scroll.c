int
id(string str)
{
   return str == "identify" ||
   str == "scroll" ||
   str == "scroll of identify";
}

string
short()
{
   return "scroll of identify";
}

void
long()
{
   write("A scroll of identify:\n"+
      "This scroll will identify the wc, ac, value, and weight of an item.\n"+
      "To cast the spell, type \"identify <item>\"\n");
}

void
init()
{
   add_action("read_scroll", "read");
   add_action("read_scroll", "use");
   add_action("identify_object", "identify");
}

/* player_inventory(string str)
* Returns the object if the item is in the player's inventory
   */
object
player_inventory(string str)
{
   object ob;
   if( !str ) return 0;
   ob = first_inventory(this_player());
   while(ob)
   {
      if (ob->id(str)) return ob;
      ob = next_inventory(ob);
   }
   return 0;
}

/* read_scroll(string str)
* Same as long description
*/
int
read_scroll(string str)
{
   if( !id(str) ) return 0;
   long();
   return 1;
}

/* identify_object(string str)
   * Will tell a player information about an item in his/her inventory
*/
int
identify_object(string str)
   {
   object ob;
   if( !environment(this_player()) )
      {
      write("You must get it first.\n");
      return 1;
   }
   ob = player_inventory(str);
   if( !ob )
      {
      write("That is not in your inventory.\n");
      return 1;
   }
   if(ob)
      {
      write("You cast an identify spell...\n");
      write("NAME:          "+ob->short()+"\n");
      write("WC:            "+ob->weapon_class()+"\n");
      write("AC:            "+ob->armor_class()+"\n");
      write("Weight:        "+ob->query_weight()+"\n");
      write("Value:         "+ob->query_value()+"\n");
      write("\n");
      write("...and the scroll vanishes!\n");
      destruct(this_object());
      return 1;
   }
}

int
get()
{
   return 1;
}

int
query_value()
{
   return 75;
}

int
query_weight()
{
   return 1;
}

void
reset(int arg)
{
   if(arg) return;
}

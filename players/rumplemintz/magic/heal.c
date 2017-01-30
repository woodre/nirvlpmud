int
id(string str)
{
   return str == "heal" ||
   str == "spell" ||
   str == "heal spell";
}

void
reset(int arg)
{
   if(arg) return;
}

void
long()
{
   write("This spell will heal your hps and sps to full.\n");
}

string
short()
{
   return "A heal spell";
}

void
init()
{
   add_action("cast", "cast");
   add_action("heal", "heal");
}

int
heal()
{
   say(this_player()->query_name()+" casts a heal spell.\n");
   write("You cast a heal spell.\n");
   this_player()->heal_self(1000);
   write("The parchment disintegrates.\n");
   destruct(this_object());
   return 1;
}

int
cast(string str)
{
   if ( str == "heal" || str == "heal spell" )
      {
      heal();
      return 1;
   }
   else return 0;
}

int
get()
{
   return 1;
}

int
query_weight()
{
   return 0;
}

int
query_value()
{
   return 10000;
}

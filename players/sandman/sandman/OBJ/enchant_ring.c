int charges;
reset(arg)
{
   if(!arg)
      charges = 2;
}
id(str) { return str == "ring"; }

short() { return "Enchanted Ring"; }

long() {
   write("An ornate silver ring, with a priceless emrald set in it.\n");
   write("type 'energize' to use it. It energizes you spell points\n");
}

init()
{
   add_action("energize");   add_verb("energize");
}

energize()
{
   if(charges == 0) {
      write("The ring glows for a second, and then disintegrates.\n");
      destruct(this_object());
      return 1;
   }
   call_other(this_player(), "add_spell_point", 100);
   write("The ring glows, and you feel energized!\n");
   charges = charges - 1;
   return 1;
}


get()
{
   return 1;
}

query_save_flag() {return 1;}

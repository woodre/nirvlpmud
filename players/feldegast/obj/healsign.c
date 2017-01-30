inherit "/obj/treasure.c";

void reset(int arg)
{
  if(arg) return;
  set_id("sign");
  set_short("An important looking sign");
  set_long("An important looking sign lays by the side of the vendor's cart.\n"+
           "You think you could probably 'read' the neat letters.\n");
  set_read("The sign says:\n"+
           "\nDear Adventurer,\n"+
           "  The heals sold here have recently been updated.  In addition, they\n"+
           "now have two new commands: heals and heals+.  Please let me know if\n"+
          "you encounter any difficulties.\n\n"+
          "Sincerely,\nFeldegast\n10-2-99\n");
  set_weight(500);
  set_value(5);
}

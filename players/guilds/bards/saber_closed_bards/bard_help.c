inherit "obj/treasure";
#include "/players/saber/closed/bards/zhelp.c"

reset(arg)
{   if (arg) return;
    set_id("tome");
   set_short("A Tome of Bardic Lore");
   set_long("A Tome of Bardic Lore.\n"+
     "To get an index, type <lore>.\n"+
     "Be sure to read lore on <rules> <tradition> \n"+
     "and lore on <members> and <trials>.\n");
   set_weight(0);
   set_value(0);
}
init()
  {
   add_action("bard_lore","lore");
   add_action("new_drop","drop");
        }

new_drop(str)  {
  if(str == "tome" || str == "all")  {
write("The Tome of Bardic Lore fades away into chaos.\n");
destruct(this_object());
  return 1;
        }
        }


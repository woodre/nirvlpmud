inherit "room/room";

int helped;
object prisoner, shackles, bag, money;

id(str)
{
   return ::id(str) || str == "celldoor" || str == "door";
}

long(str)
{
      if(str)
      return ::long(str);
   write("In a small dirty cell.\nA heavy steel celldoor leads north. It is open\n ");
   }

init()
{
   ::init();
   add_action("open_shackles", "open");
}

open_shackles(str)
{
   if(str == "door" || str == "celldoor")
   {
      write("You cannot do that.\n");
      return 1;
   }
   if(!str || str != "shackles" || helped == 0 || !(prisoner))
      return 0;
   write("Ok.\n");
   helped = 0;
   write("The Prisoner thanks you.\n");
   write("The Prisoner gives you a bag.\n");
   destruct(prisoner);
   write("The Prisoner disappears in a puff of smoke !\n");
   bag = clone_object("obj/bag");
   money = clone_object("obj/money");
/* Changed from 2500 to 200  -Snow */
   call_other(money, "set_money", random(200));
   move_object(money, bag);
   move_object(bag,this_player());
   return 1;
}

reset(arg)
{
    helped = 1;
    if(!prisoner || !living(prisoner))
    {
       prisoner  = clone_object("obj/monster");
       call_other(prisoner, "set_name", "prisoner");
/* Changed from lev. 19 to 12 -Snow */
       call_other(prisoner, "set_level",12);
       call_other(prisoner, "set_short","A prisoner is here");
       call_other(prisoner, "set_al", 300);
       call_other(prisoner, "set_wc",30);
       call_other(prisoner, "set_ac",3);
       call_other(prisoner, "set_chance",30);
       call_other(prisoner, "set_spell_mess1",
                  "The Prisoner throws a fireball");
       call_other(prisoner, "set_spell_mess2",
                  "You are hit by a fireball");
       call_other(prisoner, "set_spell_dam",40);
       move_object(prisoner,  this_object());
       shackles = clone_object("players/paulasx/prison/shackles");
       move_object(shackles, prisoner);
   }
   if(arg)
      return;
   short_desc = "A small dirty cell";
   dest_dir =
   ({
       "/players/paulasx/prison/cellhall4", "north"
    });
}


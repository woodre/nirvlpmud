inherit "obj/treasure";

reset(arg)
{  if (arg) return;
   set_id("pouch of sand");
   set_alias("pouch");
   set_short("A pouch of sand");
   set_long(
	"  A dark pouch tied with a silver cord.  The cord is\n"+
	"covered with readable runes of abjuration.  You think\n"+
	"that it would be VERY VERY bad to open the pouch es-\n"+
	"pecially if you haven't read the runes.\n");
   set_weight(1);
   set_value(50);
}

init()  {
  ::init();
  add_action("open_pouch","open");
   add_action("read_runes","read");
  add_action("give","give");
        }

read_runes(str)  {
  if(str == "runes" || str == "pouch")  {
  write("The runes of abjuration warn you that opening this pouch would\n"+
      "result in the destruction of your physical body.\n");
  return 1;
        }
        }

open_pouch(str)  {
  if(str == "pouch")  {
  write("That was a very, very bad idea...\n\n\n");
  tell_room(environment(this_player()),
    "\n"+this_player()->query_name()+" opens the pouch of sand.\n\n\n\n");
  tell_room(environment(this_player()),
"        ZZZZZZZZZZ     OOOOOOOO    TTTTTTTTTT    !!!\n"+
"                Z     O        O       TT        !!!\n"+
"               Z      O        O       TT        !!!\n"+
"              Z       O        O       TT        !!!\n"+
 "");
  tell_room(environment(this_player()),
"             Z        O        O       TT        !!!\n"+
"            Z         O        O       TT        !!!\n"+
"           Z          O        O       TT\n"+
"          Z           O        O       TT\n"+
 "");
  tell_room(environment(this_player()),
"         Z            O        O       TT        !!!\n"+
"        ZZZZZZZZZZ     OOOOOOOO        TT        !!!\n");
  say("\n\nSome dust falls to the ground and is sucked into the pouch.\n");

/*
	I am adding the following lines of code as players were
abusing this object to get free coins.  They would accumulate
gear, go to a safe place (motel room) drop it all and open the
bag.  The bag would similate a 'crash' and pay them for all the
gear they had buy not destroy it.  They would just log back on
then, go their motel room, and repeat the procedure.  So, after
reading the object code, I decided they should actually die since
the object warns them.  I also added log code to see who was
being killed.	-Eurale   9/11/97
*/
write_file("/players/saber/closed/quest/items/BUG",
  ctime(time())+"     "+this_player()->query_real_name()+
  "     opened sand pouch.\n");
destruct(this_object());
this_player()->hit_player(10000);
return 1; }
}

quest_ob()  { return 1; }
query_save_flag()  { return 1; }

give(str) {
  string who,what;
  if(sscanf(str,"%s to %s",what,who) != 2) return 0;
  if(!find_player(who)) return 0;
}

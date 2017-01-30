/*  armorblock
    Item placed on a player to prevent wearing of armor.
*/

inherit "obj/clean";

id(str) { return str == "notarmor"; }

drop() { return 0; }
get() { return 1; }

set_time(int time)
{
   call_out("dest", ((time > 0) ? time : 1));
}

dest()
{
   say ("An energy fades away.\n");
   destruct(this_object());
}

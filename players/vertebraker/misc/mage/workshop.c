/* inaccessible by players */

status 
gilmour_workshop()
{
    return 1;
}

string
short()
{
    return "Gilmour's Workshop";
}

void
init()
{
    object z;

    if((z = this_player()) && (status)z->is_player()
       && (int)z->query_level() < 21)
    {
      tell_object(z, "Gilmour's shield casts you away.\n");
      move_object(z, "/room/vill_green");
    }
}

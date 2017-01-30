#define BANNED "68.33.74.127"

void
init()
{
    if(this_player() && this_player()->is_player()
       && query_ip_number(this_player()) == BANNED)
      destruct(this_player());
}

status id(string str)
{
    return str == "blingbling";
}

status
get()
{
    return 0;
}

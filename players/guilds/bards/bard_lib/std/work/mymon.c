/*
 * First thing is to detect when a player hands me something
 * (or it could be that I pick something up myself)
 * do a callback to evGotObject with (item, giver)
 */
static status   BusyGet;
static object	CallBack;
status
add_weight(int w)
{
    if (BusyGet)
        return 0;
    if (BusyGet = (status) ::add_weight(w))
        call_out("evGotObject", 1, this_player());
    return BusyGet;
}

void
evGotObject(object giver)
{
    if (CallBack)
        CallBack->evGotObject(first_inventory(this_object()), giver);
    BusyGet = 0;
}

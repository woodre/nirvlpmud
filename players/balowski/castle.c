void nuke() { destruct(this_object());}

void
reset(int arg)
{
    if (arg)
	return;
    "players/balowski/guild/mark"->xx();
    call_out("nuke", 1);
}

string          *Chats;

void
load_chats(string *strs)
{
    if (!Chats)	Chats = strs;
    else Chats += strs;
}

void load_chat(string str) { load_chats(({ str }));}

/*
 * Remove a previously loaded chat string.
 * First occurrence matching 'str' will be removed from array
 */
void
remove_chat(string str)
{
    if (Chats) Chats -= ({ str });
}

/*
 * send one of the strings to the room the monster (this_object) is in
 */
void
chat(object where)
{
    if (where && Chats)
	tell_room(where, Chats[random(sizeof(Chats))]);
}

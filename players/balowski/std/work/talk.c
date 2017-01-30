int		chat_chance, a_chat_chance;
string          *chat_str, *a_chat_str; /* text for the talking monster */
int             chat_nr, a_chat_nr;     /* sizeof the above */

void set_chat_chance(int c) { chat_chance = c;}
void set_a_chat_chance(int c) { a_chat_chance = c;}

/*
 * Add an array of chat strings to the monster's "phrase book"
 * It is more effecient to use this function once than to use
 * load_chat() (see below) multiple times
 */
void load_chats(string *strs)
{
    if (!chat_str)
	chat_str = strs;
    else
	chat_str += strs;
    chat_nr += sizeof(strs);
}

void load_chat(string str)
{
    load_chats(({ str }));
}

/*
 * Same as load_chats, but these are used during combat
 */
void load_a_chats(string *strs)
{
    if (!a_chat_str)
	a_chat_str = strs;
    else
	a_chat_str += strs;
    a_chat_nr += sizeof(strs);
}

void load_a_chat(string str)
{
    load_a_chats(({ str }));
}

/*
 * Remove a previously loaded chat string.
 * First occurrence matching 'str' will be removed from array
 */
void remove_chat(string str)
{
    if (chat_str)
	chat_str -= ({ str });
    chat_nr = sizeof(chat_str);
}

void remove_a_chat(string str)
{
    if (a_chat_str)
	a_chat_str -= ({ str });
    a_chat_nr = sizeof(a_chat_str);
}

/*
 * send one of the strings to the room the monster (this_object) is in
 */
void chat(int nr)
{
    if (environment() && nr < sizeof(chat_str))
	tell_room(environment(), chat_str[nr]);
}

void a_chat(int nr)
{
    if (environment() && nr < sizeof(a_chat_str))
	tell_room(environment(), a_chat_str[nr]);
}

void dochat(status fighting) {
    if (fighting) {
	if (random(100) < a_chat_chance) a_chat(random(a_chat_nr));
    }
    else {
	if (random(100) < chat_chance) chat(random(chat_nr));
    }
}

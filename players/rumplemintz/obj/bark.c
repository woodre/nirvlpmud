inherit "obj/treasure";

int miss,i,num;
string rname,prev_title1,prev_title2,a;
object plyrs;

init()
{
    add_action("ftalk","say");
    add_action("ftalk","look");
    add_action("ftalk","who");
    add_action("ndrp","drop");
    add_action("mess","write");
    add_action("rmes","erase");
    add_action("toss","throw");
    add_action("toss","toss");
}

reset(arg)
{
    if(arg) return;
    set_short("A slab of bark");
    set_long("It's a piece of bark, what did ya expect. You can 'throw bark to someone'.\n"+
      "You can also 'write <message>' or 'erase message'.\n"+
      "At the moment there is no message on the bark.\n");
    set_value(1000);
    set_weight(1);
}

id(str)
{
    return str == "bark";
}

toss(str)
{
    object player1, player2;
    string pretitle1;
    string name1, name2;
    string what, whom;
    if(!str) return;
    if(sscanf(str,"%s to %s",what,whom) != 2)
	return;
    if(what != "bark")
	return;
    if(!find_player(whom))
    {
	write("You can't throw the bark to someone who isn't there.\n");
	return 1;
    }
    if(query_idle(find_player(whom)) >= 100)
    {
	write("That person is taking a nap choose someone else.\n");
	return 1;
    }
    player1 = this_player();
    pretitle1 = player1->query_pretitle();
    name1   = capitalize(this_player()->query_name());
    player2 = find_player(whom);
    name2   = capitalize(whom);
    if(environment(player1) == environment(player2))
    {
	write("You are to close to "+name2+". You might poke out an eye.\n");
	return 1;
    }
    miss = random(50);
    plyrs = users();
    i=0;
    while(i<sizeof(plyrs))
    {
	rname = plyrs[i];
	if(!rname->query_muffled() && rname->query_name() != "skippy")
	{
	    tell_object(rname,name1+" throws the bark to "+name2+"\n");
	    tell_object(player2,name1+" throws the bark to you.\n");
	    tell_object(player1,"You toss the bark towards "+name2+"\n");
	    if(player2->query_attrib("dex") < miss)
	    {
		tell_object(rname,"You see "+name2+" make a dive an MISS the catch!\n");
		tell_object(rname,name2+" quickly grabs the bark to hide his error!\n");
		tell_object(player2,"You missed the bark.\n");
		tell_object(player1,name2+" missed the bark.\n");
	    }
	    else
	    {
		tell_object(rname,"You see "+name2+" make a diving catch!\n");
	    }
	    i+=1;
	}
	move_object(this_object(),player2);
	if(!player1->query_message())
	{
	    player1->set_pretitle(pretitle1);
	}
	if(!player2->query_message())
	{
	    player2->set_pretitle("->I got da bark!  ");
	}
	return 1;
    }
}

mess(str)
{
    if(!str) return;
    write("On the bark you write,\n'"+str+"'\n");
    say(this_player()->query_name()+" writes a message on the bark.\n");
    set_short("A piece of bark with a message from "+
      this_player()->query_name());
    set_long("It's a piece of bark, what did ya expect. You can 'throw bark to someone'.\n"+
      "You can also 'write <message>' onto the bark, or 'erase message'.\n"+
      "On the back of the bark "+this_player()->query_name()+
      " has written,\n\n   '"+str+"'\n");
    return 1;
}

rmes(str)
{
    if(!str) return;
    if(str != "message") return;
    write("You erase the message from the bark.\n");
    say(this_player()->query_name()+" erases a message from the bark.\n");
    set_short("A piece of bark");
    set_long("It's a piece of bark, what did ya expect. You can 'throw bark to someone'.\n"+
      "You can also 'write <message>' onto the bark, or 'erase message'.\n"+
      "There is no message on the bark at the moment.\n");
    return 1;
}

ndrp(str)
{
    if(!str) return;
    if(str == "bark")
    {
	write("Bark says: 'You gotta throw me away dude.'\n");
	return 1;
    }
    return;
}

ftalk()
{
    a = ({"So what, are you going to throw me or not?",
      "So how did you ever get a blind barber?",
      "Didn't your mother ever teach you to share?",
      "Keep things moving.",
      "Your the type I was warned about.",
      "Could you hold me in your other hand? This one's dirty.",
      "Do you ever clean your finger nails?",
      "Your shoelace is untied.",
      "I don't have all day you know"
    });
    num = random(sizeof(a));
    write("Bark says, '"+a[num]+"'\n");
    return 0;
}

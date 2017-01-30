inherit "obj/clean";
 
id (str) {
        return str == "leaflet";
}
 
short () { return "A NEW unmovable leaflet about Rocannon's world"; }
 
long () {
        write ("Here is a leaflet about new castle called Roccanon's world.\nRead it.\n");
}
 
get () { return 0; }
 
query_weight () { return 0; }

init ()
{
	add_action ("reading", "read");
	add_action ("poem", "poem");
}

reading (str) {
        if (!id (str)) return 0;
        write ("Hello, guys!\n");
        write ("If you are high or strong middle level player, you wanna much exp and\n");
        write ("you are already TIRED of killing Guys in EclYpse - there is a new\n");
        write ("castle opened for you!\n");
        write ("Cool monsters, good 18 wc magic weapons etc.\n");
        write ("\nIf you ask me, I'll say:\n");
        write ("There must be no delay!\n");
        write ("You should go right away!\n");
        write ("From the church you start your way.\n");
        write ("\nGo south, four times west,\n");
        write ("Five times north, then go east.\n");
        write ("Beren's castle is the best!\n");
        write ("Very interesting, at least.\n");
	write ("                So, visit it, come on!\n");
	write ("                  Beren the Erchamion.\n");
	write ("Type 'poem' if you wanna see a full poem about the castle.\n");
	return 1;
}

poem ()
{
        write ("\nIf you ask me, I'll say:\n");
        write ("There must be no delay!\n");
        write ("You should go right away!\n");
        write ("From the church you start your way.\n");
        write ("\nGo south, four times west,\n");
        write ("Five times north, then go east.\n");
        write ("Beren's castle is the best!\n");
        write ("Very interesting, at least.\n");
	write ("\nIt was taken from the book\n");
        write ("By Ursula K. Le Guin.\n");
        write ("If you've read it: have a look\n");
        write ("On the monster's names, I mean\n\n");
        write ("On the spelling of the word.\n");
        write ("So, let me go on.\n");
        write ("Oh, the book's name, I forgot\n");
        write ("It's: 'The World of Roccannon'.\n");
	write ("More [Q or q to quit]:");
	input_to ("poem2");
	return 1;
}

poem2 (str)
{
        if ((str == "q") || (str == "Q")) return 1;
	write ("\nI'll code it part by part.\n");
        write ("You can visit two of six\n");
        write ("Little hint: if you are smart,\n");
	write ("Try to find some secret tricks.\n\n");
        write ("Now, we 'll have a trip.\n");
        write ("All my castle I'll describe\n");
        write ("(If you won't fell asleep)\n");
        write ("Every part has race or tribe.\n\n");
        write ("Let's begin from Angya guys.\n");
        write ("They are tall white - heared lords,\n");
        write ("They are very brave, besides\n");
        write ("When they fight they use two swords.\n\n");
        write ("Next we have an Olgyo's part\n");
        write ("They are neutral, aren't tall,\n");
        write ("Mostly hunters, fishmen, but\n");
        write ("Olgyos aren't weak at all!\n\n");
	input_to ("poem3");
	write ("More [Q or q to quit]:");
}

poem3 (str)
{
	if ((str == "Q") || (str == "q")) return 1;
	write ("\nFiias are very kind,\n");
	write ("Very wise and very weak.\n");
	write ("Their village you can find\n");
	write ("Everywhere, if you seek.\n\n");
	write ("Now, Gdemia. They are\n");
	write ("Peaceful miners, blacksmiths guys.\n");
	write ("They, and also Fiia\n");
	write ("Project thoughts very nice.\n\n");
	write ("Next we have the Ancient's race.\n");
	write ("They are really VERY strong.\n");
	write ("And they live in only place.\n");
	write ("Getting there takes too long.\n\n");
	write ("Now, this is something new:\n");
	write ("Flying Angels! Are the kind?\n");
	write ("They 'll feed their kids with you!\n");
	write ("They have really no mind.\n\n");
	input_to ("poem4");
	write ("More [Q or q to quit]:");
}

poem4 (str)
{
	if ((str == "Q") || (str == "q")) return 1;
	write ("\nIn the Flying Angels part\n");
	write ("We have Caymirs, they are cute,\n");
	write ("Not so strong, and not so smart,\n");
	write ("Their voice is like a flute!\n\n");
	write ("You are sleeping, aren't you?\n");
	write ("All my castle you've seen.\n");
	write ("Here goes something new:\n");
	write ("Monsters, objects, stuff I mean.\n\n");
	write ("If you travel in my world,\n");
	write ("Much expeirence you can gain,\n");
	write ("You can get a lot of gold.\n");
	write ("As I said: just use your brain!\n\n");
	write ("Some cool weapons you can find,\n");
	write ("Armors, which protect you nice.\n");
	write ("Bring much heals, I don't mind,\n");
	write ("Even more, it's my advice.\n");
        write ("                So, visit it, come on.\n");
        write ("                Beren the Erchamion.\n");
        return 1;
}

 

inherit "obj/monster";

reset(arg) {

::reset();

if(arg) return;

 

set_name("ramero");

set_short("Ramero");

set_long("This is a talk, lanky dude that lives in East 118.\n" +

        "He is wearing a tie-die T-Shirt that has Jim Morrison's\n" +

        "face on the front.  He is also holding a pillow that\n" +

        "looks rather dangerous.  _Legally_, He's been the same\n" +

        "level for around a semester.  He looks tired and bored.\n");

set_ac(10);

set_wc(18);

set_hp(250);

set_ep(20000);

set_level(12);

set_al(0);

set_chance(30);

 

    move_object(clone_object("players/lew/shirt"),this_object());

 

    move_object(clone_object("players/lew/pillow"),this_object());

 

set_spell_mess1("Gonzo puts a tablet in your mouth!\n" +

        "  You see pretty colors!!\n");

set_spell_mess2("Gonzo throws some dust in your face!\n" +

        "  You feel very sleepy...\n");

set_spell_dam(20);

set_chat_chance(50);

load_chat("Ben says:  Man, I'm tired!!!\n");

load_chat("Ben says:  Didn't sleep all night again!!\n");

load_chat("Ben goes over to the stereo and puts in a CD.\n" +

        "He clicks the CD player to song #6.\n" +

        "Soon you hear NIN blasting over the speakers.\n" +

        "The words sound like:\n" +

        "  It took you to make me realize!\n" +

        "  It took you to make me see the light!\n" +

        "  Smashed up my sanity!\n" +

        "  Smashed up my integrity!\n" +

        "  Smashed up what I believed in!\n" +

        "  Smashed up what's left of me!\n" +

        "  Smashed up my everything!\n" +

        "  Smashed up all that is true!\n" +

        "  Gonna smash myself to pieces, I don't know what else to do!\n" +

        "To which Gonzo replies: 'I'm not bitter!!'\n");

load_chat("Gonzo seems like he's bored.\n");

load_chat("Gonzo disappears into Sherlock's room and reappears moments\n" +

        "  with a deck of cards and proceeds to play Solitaire.\n" +

        "\n" +

        "After cheating his butt off, he gives the cards back to Sherlock\n");

load_chat("Gonzo says:  It is not I who am crazy.  It is I who am mad!!\n");

load_chat("Gonzo asks you:  You want to go to 7-E?  I'm hungry.\n");

load_chat("Gonzo proceeds to tell you his life story.\n" +

        "It is short and ends before you realized he was telling it.\n");

load_chat("Gonzo quotes Jim Morrison:  Death make angels of us all,\n" +

        "  and gives us wings where we had shoulders as smooth as\n" +

        "  raven's gloss.\n");

load_chat("WHAT EES ET MAN!!!!!!!!!\n");

load_chat("Gonzo quotes:  We are no longer the knights who say Ni!  We\n" +

        "  are now the knights who say Icky icky p-tang! Nu-wom!\n");

load_chat("Gonzo says:  I'll just lie back and think pleasent thoughts.\n");

load_chat("Gonzo is sleeping.        WAKE HIM UP!!!\n");

load_chat("Gonzo is missing classes right now...\n");

load_chat("Gonzo tells you about a cheat he found.     NOT!!\n");

load_chat("Gonzo is a slicer and a dicer.\n");

load_chat("Gonzo is on the computer again....\n");

load_chat("Gonzo puts in one of his roommate's anime.\n");

load_chat("Can you tell Gonzo wrote this himself?\n");

load_chat("Gonzo hopes that this character will be allowed on the mud.\n");

load_chat("Gonzo is very sorry he is annoying you.\n");

 

   return 1;
}

 


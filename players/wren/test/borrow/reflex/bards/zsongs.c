
/* The songs of the Bardic guild.
 *  Every player is required to pick a song, to get from bard
 *  level 9 to bard level 10.
 *
 */

bard_song_sing(str)
{
	int song, number;

	if (!str) {
		song_list();
		return 1;
	}

	if (sscanf(str, "%d %d", song, number) != 2) {
		write("Sing <song number> <song part #>\n");
		return 1;
	}

	if (song == 1) {
		if (number == 1) {
			write("You begin to sing \"\Hay, Nonny Nonny.\"\n");
			say(tp + " begins to sing a song.\n");
			call_out("sing_1_1", 2);
			return 1;
		}
		if (number == 2) {
			call_out("sing_1_5", 1);
			return 1;
		}
		if (number == 3) {
			call_out("sing_1_10", 1);
			return 1;
		}
	}

	if (song == 2) {
		write("You begin to sing \"\The fairies.\"\n");
		say(tp + " begins to sing a song.\n");
		call_out("sing_2_1", 2);
		return 1;
	}

	if (song == 3) {
		if (number == 1) {
			write("You begin to sing \"\Mystify\"\n");
			say(tp + " begins to sing a song.\n");
			call_out("sing_3_1", 2);
			return 1;
		}
		if (number == 2) {
			call_out("sing_3_5", 1);
			return 1;
		}
		if (number == 3) {
			call_out("sing_3_9", 1);
			return 1;
		}
		if (number == 4) {
			call_out("sing_3_13", 1);
			return 1;
		}
		if (number == 5) {
			call_out("sing_3_15", 1);
			return 1;
		}
	}

	if (song == 4) {
		if (number == 1) {
			write("You begin to sing \"\Annabel Lee\"\n");
			say(tp + " begins to sing a song.\n");
			call_out("sing_4_1", 1);
			return 1;
		}
		if (number == 2) {
			call_out("sing_4_4", 1);
			return 1;
		}
		if (number == 3) {
			call_out("sing_4_7", 1);
			return 1;
		}
		if (number == 4) {
			call_out("sing_4_11", 1);
			return 1;
		}
		if (number == 5) {
			call_out("sing_4_14", 1);
			return 1;
		}
		if (number == 6) {
			call_out("sing_4_17", 1);
			return 1;
		}
	}

	if (song == 5) {
		if (number == 1) {
			write("You begin to sing \"\The music of the night\"\n");
			say(tp + " begins to sing a song.\n");
			call_out("sing_5_1", 1);
			return 1;
		}
	}

	if (song == 6) {
		if (number == 1) {
			write("You begin to sing \"\I'll be alright without you\"\n");
			say(tp + " begins to sing a song.\n");
			call_out("sing_6_1", 1);
			return 1;
		}
		if (number == 2) {
			call_out("sing_6_6", 1);
			return 1;
		}
		if (number == 3) {
			call_out("sing_6_9", 1);
			return 1;
		}
		if (number == 4) {
			call_out("sing_6_11", 1);
			return 1;
		}
	}

	write("You know of no song by that number.\n");
	return 1;
}

song_list()
{
	write("\n" +
		  "Song syntax: sing <song #> <song verse>\n\n" +
		  "Song 1     Hay nonny nonny <Shakespeare>\n" +
		  "           < 1,3 verses > < 2 chorus > < order: 1 2 3 2 >\n" +
		  "Song 2     The fairies <Allingham> <Star's Song>\n" +
		  "           < 1 verse > < order: 1 >\n" +
		  "Song 3     Mystify <INXS> <Johnathin's Song>\n" +
		  "           < 1,3,4,5 verses > < 2 chorus > < order: 1 2 3 2 4 2 5 2>\n"
		  + "Song 4     Annabel Lee <Poe> <Mythos's Song>\n" +
		  "           < 1 - 6 verses > < order: 1 2 3 4 5 6 >\n" +
		  "Song 5     Music of the night <Webber> <Storm's Song>\n" +
		  "           < 1 verse > < order: 1 >\n" +
		  "Song 6     I'll be alright without you <Journey> <Devon's Song>\n"
		  + "           < 1 - 4 verses > < order: 1 2 3 4 >\n" + "\n");
	return 1;
}

#define DUCE environment(this_object())->query_real_name()
#define ACE find_player(DUCE)
/* <change by="Erasmios" date="2001-05-25> */
ROM(str)
{
	tell_room(environment(ACE), capitalize(DUCE) + " sings" + str);
}

/* </change> */

sing_1_1()
{
	ROM(" \"Sigh no more, ladies, sigh no more;\"\n");
	call_out("sing_1_2", 1);
	return 1;
}

sing_1_2()
{
	ROM(" \"Men were decievers ever;\"\n");
	call_out("sing_1_3", 1);
	return 1;
}

sing_1_3()
{
	ROM(" \"One foot in sea and one on shore,\"\n");
	call_out("sing_1_4", 1);
	return 1;
}

sing_1_4()
{
	ROM(" \"To one thing constant never;\"\n");
	return 1;
}

sing_1_5()
{
	ROM(" \"Than sigh not so,\"\n");
	call_out("sing_1_6", 1);
	return 1;
}

sing_1_6()
{
	ROM(" \"But let them go,\"\n");
	call_out("sing_1_7", 1);
	return 1;
}

sing_1_7()
{
	ROM(" \"And be you blithe and bonny;\"\n");
	call_out("sing_1_8", 1);
	return 1;
}

sing_1_8()
{
	ROM(" \"Converting all your sounds of woe\"\n");
	call_out("sing_1_9", 1);
	return 1;
}

sing_1_9()
{
	ROM(" \"Into Hay nonny, nonny.\"\n");
	return 1;
}

sing_1_10()
{
	ROM(" \"Sing no more ditties, sing no more\"\n");
	call_out("sing_1_11", 1);
	return 1;
}

sing_1_11()
{
	ROM(" \"Of dumps so dull and heavy;\"\n");
	call_out("sing_1_12", 1);
	return 1;
}

sing_1_12()
{
	ROM(" \"The fraud of men was ever so\"\n");
	call_out("sing_1_13", 1);
	return 1;
}

sing_1_13()
{
	ROM(" \"Since summer first was heavy.\"\n");
	return 1;
}

sing_2_1()
{
	ROM(" \"They stole little Josanna,\"\n");
	call_out("sing_2_2", 1);
	return 1;
}

sing_2_2()
{
	ROM(" \"  For seven years long,\"\n");
	call_out("sing_2_3", 1);
	return 1;
}

sing_2_3()
{
	ROM(" \"And when she came down again\"\n");
	call_out("sing_2_4", 1);
	return 1;
}

sing_2_4()
{
	ROM(" \"  Her friends were all gone.\"\n");
	call_out("sing_2_5", 1);
	return 1;
}

sing_2_5()
{
	ROM(" \"They took her lightly back,\"\n");
	call_out("sing_2_6", 1);
	return 1;
}

sing_2_6()
{
	ROM(" \"  Between the night an morrow,\"\n");
	call_out("sing_2_7", 1);
	return 1;
}

sing_2_7()
{
	ROM(" \"They thought that she was fast asleep,\"\n");
	call_out("sing_2_8", 1);
	return 1;
}

sing_2_8()
{
	ROM(" \"  But she was dead with sorrow.\"\n");
	call_out("sing_2_9", 1);
	return 1;
}

sing_2_9()
{
	ROM(" \"They have kept here ever since\"\n");
	call_out("sing_2_10", 1);
	return 1;
}

sing_2_10()
{
	ROM(" \"  Deep within the lake,\"\n");
	call_out("sing_2_11", 1);
	return 1;
}

sing_2_11()
{
	ROM(" \"On a bed of flag-leave,\"\n");
	call_out("sing_2_12", 1);
	return 1;
}

sing_2_12()
{
	ROM(" \"  Watching till she wake.\"\n");
	return 1;
}

sing_3_1()
{
	ROM(" \"All veils and misty  Streets of blue\"\n");
	call_out("sing_3_2", 2);
	return 1;
}

sing_3_2()
{
	ROM(" \"Almond looks  That chill devine\"\n");
	call_out("sing_3_3", 1);
	return 1;
}

sing_3_3()
{
	ROM(" \"Some silken moment  Goes on forever\"\n");
	call_out("sing_3_4", 1);
	return 1;
}

sing_3_4()
{
	ROM(" \"And we're leaving  Broken hearts behind.\"\n");
	return 1;
}

sing_3_5()
{
	ROM(" \"Mystify\"\n");
	call_out("sing_3_6", 1);
	return 1;
}

sing_3_6()
{
	ROM(" \"Mystify me\"\n");
	call_out("sing_3_7", 1);
	return 1;
}

sing_3_7()
{
	ROM(" \"Mystify\"\n");
	call_out("sing_3_8", 1);
	return 1;
}

sing_3_8()
{
	ROM(" \"Mystify me.\"\n");
	return 1;
}

sing_3_9()
{
	ROM(" \"I need perfection  Some twisted selection\"\n");
	call_out("sing_3_10", 1);
	return 1;
}

sing_3_10()
{
	ROM(" \"That tangles me  To keep me alive\"\n");
	call_out("sing_3_11", 1);
	return 1;
}

sing_3_11()
{
	ROM(" \"In all that exists  None have your beauty\"\n");
	call_out("sing_3_12", 1);
	return 1;
}

sing_3_12()
{
	ROM(" \"I see your face  I will survive.\"\n");
	return 1;
}

sing_3_13()
{
	ROM(" \"Eternally wild with the power  To make every moment come alive\"\n");
	call_out("sing_3_14", 1);
	return 1;
}

sing_3_14()
{
	ROM(" \"All those stars that shine upon you  Will kiss you every night\"\n");
	call_out("sing_3_1", 1);
	return 1;
}

sing_3_15()
{
	ROM(" \"You're eternally wild with the power  To make every moment come alive\"\n");
	call_out("sing_3_16", 1);
	return 1;
}

sing_3_16()
{
	ROM(" \"All those stars that shine upon you  And they'll kiss you every night\"\n");
	return 1;
}

sing_4_1()
{
	ROM(" \"It was many and many a year ago,\n" +
		"  In a kingdom by the sea,\"\n");
	call_out("sing_4_2", 2);
	return 1;
}

sing_4_2()
{
	ROM(" \"That a maiden there lived where you may know\n" +
		"  By the name of Annabel Lee;\"\n");
	call_out("sing_4_3", 2);
	return 1;
}

sing_4_3()
{
	ROM(" \"And this maiden she lived with no other thought\n" +
		"  Than to love and be loved by me.\"\n");
	return 1;
}

sing_4_4()
{
	ROM(" \"I was a child and she was a child,\n" +
		"  In this kingdom by the sea;\"\n");
	call_out("sing_4_5", 2);
	return 1;
}

sing_4_5()
{
	ROM(" \"But we loved with a love that was more than love-\n" +
		"  I and my Annabel Lee;\"\n");
	call_out("sing_4_6", 2);
	return 1;
}

sing_4_6()
{
	ROM(" \"With a love that the winged seraphs of heaven\n" +
		"  Coveted her and me\"\n");
	return 1;
}

sing_4_7()
{
	ROM(" \"And this was the reason that, long ago,\n" +
		"  In this kingdom by the sea.\"\n");
	call_out("sing_4_8", 2);
	return 1;
}

sing_4_8()
{
	ROM(" \"A wind blew out of a cloud, chilling\n" +
		"  My beautiful Annabel Lee;\"\n");
	call_out("sing_4_9", 2);
	return 1;
}

sing_4_9()
{
	ROM(" \"So that her highborn kinsmen came\n" +
		"  And bore her away from me,\"\n");
	call_out("sing_4_10", 2);
	return 1;
}

sing_4_10()
{
	ROM(" \"To shut her up in a sepulchre\n" +
		"  In this kingdom by the sea.\"\n");
	return 1;
}

sing_4_11()
{
	ROM(" \"The angles, not half so happy in heaven\n" +
		"  Went envying her and me-\"\n");
	call_out("sing_4_12", 2);
	return 1;
}

sing_4_12()
{
	ROM(" \"Yes! - that was the reason (as all men know,\n" +
		"  In this kingdom by the sea)\"\n");
	call_out("sing_4_13", 2);
	return 1;
}

sing_4_13()
{
	ROM(" \"That the wind come out of the cloud by night,\n" +
		"  Chilling and killing my Annabel Lee.\"\n");
	return 1;
}

sing_4_14()
{
	ROM(" \"But our love it was stronger by far than the love\n" +
		"  Of those who were older than we-\n" +
		"  Of many far wiser than we-\"\n");
	call_out("sing_4_15", 3);
	return 1;
}

sing_4_15()
{
	ROM(" \"And neigher the angles in heaven above,\n" +
		"  Nor the demons down under the sea,\"\n");
	call_out("sing_4_16", 2);
	return 1;
}

sing_4_16()
{
	ROM(" \"Can ever dissever my soul from the soul\n" +
		"  Of the beautiful Annabel Lee!\"\n");
	return 1;
}

sing_4_17()
{
	ROM(" \"For the moon never beams, without bringing me dream\n" +
		"  Of the beautiful Annabel Lee;\"\n");
	call_out("sing_4_18", 2);
	return 1;
}

sing_4_18()
{
	ROM(" \"And the stars never rise, but I feel the bright eyes\n" +
		"  Of the beautiful Annabel Lee;\"\n");
	call_out("sing_4_19", 2);
	return 1;
}

sing_4_19()
{
	ROM(" \"And so, all the night-tide, I lie down by the side\n" +
		"Of my darling, - my darling, - my life and my bride,\n" +
		"  In her sepulchre there by the sea,\n" +
		"  In her tomb by the side of the sea.\"\n");
	return 1;
}

sing_5_1()
{
	ROM(" \"Night time sharpens, heightens each sensation\n" +
		"    Darkness stirs and wakes imagination\"\n");
	call_out("sing_5_2", 2);
	return 1;
}

sing_5_2()
{
	ROM(" \"Silently the senses abondon their defenses\n" +
		"    Slowly, gently, night unfurls its splendor\"\n");
	call_out("sing_5_3", 2);
	return 1;
}

sing_5_3()
{
	ROM(" \"Grasp it, sense it, trembolous and tender\n" +
		"    Turn your face away from the garish light of day\"\n");
	call_out("sing_5_4", 2);
	return 1;
}

sing_5_4()
{
	ROM(" \"Turn your thoughts away from cold unfeeling light\n" +
		"    And listen to the music of the night.\"\n");
	call_out("sing_5_5", 2);
	return 1;
}

sing_5_5()
{
	ROM(" \"Close your eyes and surrender to your darkest dreams\n" +
		"    Leave the thoughts of the life you knew before\"\n");
	call_out("sing_5_6", 2);
	return 1;
}

sing_5_6()
{
	ROM(" \"Close your eyes and let your spirit start to soar\n" +
		"    And you'll live as you've never lived before\"\n");
	call_out("sing_5_7", 2);
	return 1;
}

sing_5_7()
{
	ROM(" \"Softly, deftly, music shall surround you\n" +
		"    Feel it, hear it, closing in around you\n" +
		"    Open up your mind, let your fantasies unwind\"\n");
	call_out("sing_5_8", 2);
	return 1;
}

sing_5_8()
{
	ROM(" \"In this darkness which you know you cannot fight\n" +
		"    The darkness of the music of the night.\"\n");
	return 1;
}

sing_6_1()
{
	ROM(" \"I've been thinking 'bout the time...\n" +
		"    You walked out on me\"\n");
	call_out("sing_6_2", 2);
	return 1;
}

sing_6_2()
{
	ROM(" \"There were moments I'd believe, you were there\"\n");
	call_out("sing_6_3", 2);
	return 1;
}

sing_6_3()
{
	ROM(" \"Do I miss you, or am I lying to myself again\"\n");
	call_out("sing_6_4", 2);
	return 1;
}

sing_6_4()
{
	ROM(" \"I do these things...\n" +
		"           It's all because of you\"\n");
	call_out("sing_6_5", 2);
	return 1;
}

sing_6_5()
{
	ROM(" \"I keep holding on, but I'll try\n" +
		"            Try not to think of you\n" +
		"            Love don't leave my lonely\"\n");
	return 1;
}

sing_6_6()
{
	ROM(" \"I'll be alright without you\n" +
		"    They'll be someone else...I keep tellin' myself\"\n");
	call_out("sing_6_7", 2);
	return 1;
}

sing_6_7()
{
	ROM(" \"I'll be alright without you\n" +
		"  Oh...Love's an empty face, I can't replace\n" +
		"            You don't need it\"\n");
	call_out("sing_6_8", 2);
	return 1;
}

sing_6_8()
{
	ROM(" \"People wonderin' why we broke apart\n" +
		"    The great pretender here I go again\"\n");
	return 1;
}

sing_6_9()
{
	ROM(" \"These things I do...\n" +
		"            It's all because of you\"\n");
	call_out("6_10", 2);
	return 1;
}

sing_6_10()
{
	ROM(" \"I'll keep holdin' but I'll try\n" +
		"            Try not to think of you\n" +
		"    All I wanted was to hold you\"\n");
	return 1;
}

sing_6_11()
{
	ROM(" \"I'll be alright without you\n" +
		"    There'll be someone else, I keep tellin' myself\"\n");
	call_out("sing_6_12", 2);
	return 1;
}

sing_6_12()
{
	ROM(" \"I'll be alright without you\n" +
		"    Love's an empty face...Oh I've got to replace\"\n");
	call_out("sing_6_13", 2);
	return 1;
}

sing_6_13()
{
	ROM(" \"I'll be alright without you\n" +
		"    There'll be someone else, I keep tellin' myself\"\n");
	call_out("sing_6_14", 2);
	return 1;
}

sing_6_14()
{
	ROM(" \" I'll be alright without you\n" +
		"    Oh...love's an empty place, I can still see your face\n" +
		"    I'll be alright.\"\n");
	return 1;
}

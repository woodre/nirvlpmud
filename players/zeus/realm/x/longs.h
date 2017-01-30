/*  more for x */

long(){
	switch(x){
	case 0:
		write(
"This is a dark, eerie part of the forest.  The mostly dead trees reach\n"+
"out like agonized monsters, blocking out the non-existant sun.  There\n"+
"is no way to tell which way, if any leads out of this horrible place.\n"+
"    No obvious exits.\n");
		break;
	case 1:
		write(
"The forest looms above you.  Dark shadows dart randomly about, as though\n"+
"the forest itself is alive.  Looking in any direction reveals nothing but\n"+
"darkness.  It is impossible to tell which way, if any leads out of this\n"+
"horrible place.\n"+
"    No obvious exits.\n");
		break;
	case 2:
		write(
"You are standing in one of the darkest forests you have ever seen.\n"+
"Looking in any direction reveals nothing but shadows.  The mostly\n"+
"dead trees tower high above you, blocking out all light.  You are\n"+
"filled with a sense of fear and desperation.\n"+
"    No obvious exits.\n");
		break;
	case 3:
		write(
"The darkness of the forest is pressing down on you like a weight.  The\n"+
"trees all around loom over you like dying creatures, grasping at you\n"+
"with their frail branches.  As you peer out into the darkness, you are\n"+
"at a loss for direction.\n"+
"    No obvious exits.\n");
		break;
	case 4:
		write(
"As you look out into the forest, all you can see are shadows.  The frail\n"+
"looking trees loom over you like dying monsters.  Every direction looks\n"+
"the same.  Looking up you can not even see through the trees.  You feel\n"+
"as though you are helplessly trapped.\n"+
"    No obvious exits.\n");
		break;
	case 5:
		write(
"You are in a terribly dark part of the forest.  The trees around you are\n"+
"shaped like agonized creatures, rustling in the wind.  Whispy shadows dart\n"+
"out of the corners of your eyes as you try to keep your balance.  Every\n"+
"direction looks the same, and seems to lead deeper into the forest.\n"+
"    No obvious exits.\n");
		break;
	case 6:
		write(
"As you look around, nothing but the agonizing figures of trees fills your\n"+
"view.  They are twisted in such ways to make you shudder.  Dark shadows\n"+
"lurk all about you, as though they are alive.  Every direction seems\n"+
"to lead further into the forest.\n"+
"    No obvious exits.\n");
		break;
	case 7:
		write(
"Shadows lurk all around you like mindless creatures.  The eerie trees\n"+
"are twisting like snakes in the wind.  As you look in every direction,\n"+
"they all seem to lead further into the darkness.\n"+
"    No obvious exits.\n");
		break;
	case 8:
		write(
"In every direction all you can see is decaying trees and twisting\n"+
"shadows.  A soft wind is blowing through the trops of the trees,\n"+
"making them chatter softly.  Every direction seems to lead deeper\n"+
"into the forest.  You are filled with a sense of fear.\n"+
"    No obvious exits.\n");
		break;
	}
}


look(str){
	if(str == "at trees"){		write(
"The trees look like deformed monsters, swaying in the wind.  Many of\n"+
"them are at least partially dead, and are twisted like writhing snakes.\n"+
"They give off an appearance of utter pain and agony.\n");
	return 1;
	}
	else if(str == "at shadows"){	write(
"Shadows seem to dart around you almost as if they are alive.  They loom\n"+
"over you like a blanket, and dart around you.  The shadows fill you with\n"+
"a sense of fear and desperation.\n");
	return 1;
	}
	else if(str == "at branches"){	write(
"The branches of the trees reach out like the twisted arms of the damned,\n"+
"pleading to you for salvation.  They blow in the breeze, making a soft\n"+
"creaking sound.\n");
	return 1;
	}
	else if(str == "at light"){		write(
"The trees are blocking out all light.  As you look up into them all you\n"+
"can see are twisted branches.\n");
	return 1;
	}
	else return 0;
	return 1;
}


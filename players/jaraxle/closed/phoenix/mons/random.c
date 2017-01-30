/********************************************************************/
/*		An inherit handling general random details of monsters		*/
/*						Creator:	Mishtar							*/
/*						Created:	10/24/03						*/
/*						Modified:	10/25/03						*/
/********************************************************************/

/* Random Details */
string hair;		/*		Hair color		*/
string gen;			/*	  Male or Female	*/
string gen3;		/*		 He or She		*/
string genp;		/*		His or Hers		*/
string eyes;		/*		 Eye color		*/

get_random(){
	switch(random(8)){
		case 0: hair = "golden blonde";
				break;
		case 1: hair = "silver";
				break;
		case 2: hair = "dark brown";
				break;
		case 3:	hair = "copper";
				break;
		case 4: hair = "raven";
				break;
		case 5: hair = "light brown";
				break;
		case 6: hair = "auburn";
				break;
		case 7:	hair = "firey red";
				break;
	}
	
	switch(random(2)){
		case 0: gen = "male";
				gen3 = "he";
				genp = "his";
				break;

		case 1: gen = "female";
				gen3 = "she";
				genp = "her";
				break;
   }

	switch(random(5)){
		case 0: eyes = "emerald green";
				break;
		case 1:	eyes = "dark brown";
				break;
		case 2:	eyes = "ice blue";
				break;
		case 3:	eyes = "bright amber";
				break;
		case 4:	eyes = "deep violet";
				break;
	}	
}

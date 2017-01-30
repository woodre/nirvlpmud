/*
   Deck o' Cards
*/
int cards;

init() {
	add_action("create_deck","cdeck");
	add_action("shuffle_deck","shuffle");
	add_action("debug_print","pdeck");
}

long() { return write("\n"); }
short() { return "A deck of cards"; }
id(str) { return str=="deck"; }

string print_card(int card) {
	string suit;
	mixed cardstr;
	
	
	if(card<3) return "Joker";
	switch(card/100) {
		case 1: suit="Clubs"; break;
		case 2: suit="Diamonds"; break;
		case 3: suit="Hearts"; break;
		case 4: suit="Spades"; break;
	}
	if((card%100)>=11) {
		switch(card%100) {
			case 11: cardstr="Jack"; break;
			case 12: cardstr="Queen"; break;
			case 13: cardstr="King"; break;
			case 14: cardstr="Ace"; break;
		}
	} else cardstr=card%100;
	return cardstr+" of "+suit;
}

create_deck(string no_joker) {
	int i, this_card, suit_multiplier;
	
	if(no_joker) {
		cards=allocate(52);
		/* clubs     - 102-114
		   diamonds  - 202-214
		   hearts    - 302-314
		   spades    - 402-414 */
		while(suit_multiplier<400) {
			suit_multiplier+=100;
			for(i=2; i<15; i++) {
				cards[this_card]=suit_multiplier+i;
				this_card++;
			}
		}
	} else {	
		cards=allocate(54);
		/* jokers    - 1 and 2
		   clubs     - 102-114
		   diamonds  - 202-214
		   hearts    - 302-314
		   spades    - 402-414 */
		cards[0]=1;
		cards[53]=2;
		this_card=1;
		while(suit_multiplier<400) {
			suit_multiplier+=100;
			for(i=2; i<15; i++) {
				cards[this_card]=suit_multiplier+i;
				this_card++;
			}
		}
	}
}

shuffle_deck() {
	int i, this_card, a, b;
	
	a=allocate(sizeof(cards)/2);
	b=allocate(sizeof(cards)/2);
	a=cards[0..(sizeof(cards)/2)-1];
	b=cards[(sizeof(cards)/2)..(sizeof(cards)-1)];
	if(random(1)) {
		for(i=0; i<(sizeof(cards)/2); i++) {
			cards[this_card]=a[i];
			this_card++;
			cards[this_card]=b[i];
			this_card++;
		}
	} else {
		for(i=0; i<(sizeof(cards)/2); i++) {
			cards[this_card]=b[i];
			this_card++;
			cards[this_card]=a[i];
			this_card++;
		}
	}
}

debug_print() {
	int this_card;
	
	write(sizeof(cards)+"\n");
	for(this_card=0; this_card<sizeof(cards); this_card++)
		write(this_card+":\t"+print_card(cards[this_card])+"\n");
	return 1;
}

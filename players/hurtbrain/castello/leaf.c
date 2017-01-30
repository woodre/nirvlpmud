id(str) { return str == "leaflet"; }

reset() {}

long() { write("Hurtbrain's NEW objects leaflet. Read it!!\n"); }

short() { return "An important leaflet"; }

init() {
    add_action("read","read");
}

read (str) {
	if(!str) {
		write("What do you want to read?\n");;
		return 1;
		}
	if(str == "leaflet")  {
		write("New objects in Hurtbrain's castle!\n");
		write("- boomerang: wc 18 and you can throw it three times. (but it can hit you hard).\n");
		write("- potion of strenght: it gives you a high wc for a minute.\n");
		write("- philosophers' stone: melts all what you want into coins.\n");
		write("- traveller pigeon: transfer objects from a player to another.\n");
		write("VERY CHEAP PRICES!!!!!\n");
		write("You can get it from the vending machine at the entrance of my castle:\n");
		write("from church : s,w,w,w,w,n,n,n,n,enter machine.\n");
		write("Get the point!\n");
		return 1;
	}	
	return 0;
}

get()  { return 1; }

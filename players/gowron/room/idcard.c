query_save_flag() { return 1; }
id(str) { return str == "card"; }
query_weight() { return 1; }
query_value() { return 0; }
get() { return 1; }
drop() { return 0; }

short() { return "Power Plant worker ID"; }
long() { short()+".  It has a picture of a man wearing a radiation "+
		 "suit on it.\n"; }


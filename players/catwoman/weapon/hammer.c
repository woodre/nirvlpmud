inherit "obj/weapon";
string desc_array;
int    desc_index;
#define DLONG   0
#define DSHORT  1
#define DTMP    2
#define DID     3
#define TEST(ARG)   (ARG && ARG !="")
short() { return (desc_array[DSHORT]); }
long() { return (desc_array[DLONG]); }
id(str){ return str == "hammer";}

reset(arg) {
  if (arg) {
	return;
    info = 1;
	if(!desc_array)
	desc_array = allocate(7);
	desc_array[DSHORT] = "smithy's hammer";
	desc_array[DLONG]  = "change <short|long>\n";
	desc_array[DID]    = "hammer";
    set_class(19);
    set_value(3200);
    set_weight(3);
    set_hit_func(this_object());
  }
}
init() {
add_action("change_desc","change");
add_action("toggle","info");
}
toggle(str){
if(str){
	write("sorry....\n");
	return 0;
	}
	info = !info;
	if(info) write("Info enabled\n");
        else write("info disabled\n");
	return 1;
}
change_desc(str){
if(str == "long")
	change_desc2(DLONG);
else if(str == "short")
	change_desc2(DSHORT);
else
	write("usage: change <short/long>\n");
	return 1;
}
change_desc2(arg) {
	desc_index = arg;
	desc_array[arg+DTMP] = "";
	if (arg != DID) {
		write("Give '**' to stop, '~~' to regret.\n");
		write("]");
		input_to("change_desc3");
	} else {
		write("New id ==> ");
	input_to("change_id");
	}
	return 1;
}
change_desc3(str) {
	if(str == "**") {
		if(TEST(desc_array[desc_index+DTMP])) {
			if(desc_index == DSHORT) {
			string tmp;
			if(ssanf(desc_array[desc_index+DTMP],"%s\n", tmp) ==1)
				desc_array[desc_index+DTMP] = tmp;
			}
		desc_array[desc_index] = desc_array[desc_index+DTMP];
		}
	} else if (str == "~~") {
	} else {
		write("]");
		desc_array[desc_index+DTMP] = desc_array[desc_index+DTMP]+str+"\n";
		input_to("change_desc3");
	}
	return 1;
}
change_id(str) {
	desc_array[DID] = str;
	return 1;
}

weapon_hit(attacker) {
	string align;
	write("You hit the monster with a bonecruching sound.\n");
	say("CRUNCH!!!!.\n");
	return 1;
}




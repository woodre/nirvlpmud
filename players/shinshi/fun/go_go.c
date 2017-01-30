#define MAX_BEATS 3600

int beats;

id(str) { return str == "go_go"; }

drop() { return 1; }

start_it(){
	set_heart_beat(1);
}

heart_beat()
{
	object ob;
	
	ob = environment();
	if(++beats == MAX_BEATS){
		tell_object(ob, "The last grain of sand falls to the bottom of the hourglass.\n");
		return destruct(this_object());
	}
}
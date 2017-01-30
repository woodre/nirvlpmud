void reset(int arg)
{
    if(arg) return;
    call_out("healstart",1);
}
    int charges;
short() {
    return "Healing cloud of rain";
}

healstart(){charges=100;call_out("heal",1);}
heal(){
	int xx;
	object obj;
	if(charges<1){
		tell_object(environment(this_object()),"The healing rain passes.\n");
		dest(this_object());
	}
	else
	obj = users();
	for (xx = 0; xx < sizeof(obj); xx ++){
		if(present(obj[xx], environment(this_object()))) {
			obj[xx]->heal_self(random(5) + 1);
			tell_object(obj[xx],"You are healed\n");
		}
	}
call_out("heal",10);
charges=charges-1;
}


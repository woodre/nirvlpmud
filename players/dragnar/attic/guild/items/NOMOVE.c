id(str) { return str =="nomove"; }
get(){ return 1; }
init(){ add_action("FUCKYOU"); add_xverb("");
}
FUCKYOU(str){
	object user;
	user=(environment(this_object()));
	tell_object(user, "The presense of Shardak prevents you from doing anything.\n");
return 1;
}

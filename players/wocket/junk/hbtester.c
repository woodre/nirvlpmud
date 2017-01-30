id(str){ return str == "hbtester"; }
short(){ return "hptester"; }
reset(){
set_heart_beat(3);
call_out("callme",1);
}

heart_beat(){
if(environment(this_object()))
tell_room(environment(this_object()),"heart beat called.\n");
}

callme(){
if(environment(this_object()))
tell_room(environment(this_object()),"call_out called.\n");
call_out("callme",1);
}

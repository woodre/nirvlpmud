id(str){ return str == "w_light"; }

reset(){
call_out("rmlight",700);
set_light(2);
}

rmlight(){
set_light(-2);
say("The light dissipates.\n");
destruct(this_object());
}

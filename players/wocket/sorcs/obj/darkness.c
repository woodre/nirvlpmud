id(str){ return str == "w_darkness"; }

reset(){
call_out("rmdarkness",400);
set_light(-5);
}

rmdarkness(){
set_light(5);
say("The darkness dissipates.\n");
destruct(this_object());
}

id(str) {return str == "ooga";}

reset(arg) { if(arg) return; call_out("wow",100+random(500)); }

get() { return 0;}
drop() { return 1;}

query_save_flag() { return 1;}

wow() { destruct(this_object()); return 1; }
string letter;
set_letter(str) { letter = str; }
id(str) { return str == "pimp ring" || str == "ring"; }
short() { return "A big fat gold ring etched with \""+letter+"\" (worn)"; }
long() { write("24 carats of solid gold slap-enhancing, cheek-ripping style.\n"); }
drop() { return 1; }
get() { return 1; }
query_save_flag() { return 1; }

inherit "obj/treasure";

reset(arg) {
 if(arg) return;
set_long("recruiter\n");
   set_weight(0);
    set_value(0);
}
 id(str) { return str == "recruit" || str == "clan"; }


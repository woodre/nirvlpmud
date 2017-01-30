id(str) { return str == "leaflet"; }
reset() {}
long() { write("Hurtbrain's castle leaflet. Read it!! (type rem_leaf to"+
        " destroy it)\n"); }
short() { return "A ->>NEW<<- red-glowing leaflet"; }
init() {
    add_action("read","read");
    add_action("rem_leaf","rem_leaf");
}
read (str) {
        if(!str) {
                write("What do you want to read?\n");;
                return 1;
                }
        if(str == "leaflet")  {
                cat("/players/hurtbrain/helpdir/helpent");
                return 1;
        }
        return 0;
}
rem_leaf()  {
        write("The leaflet turns to dust.\n");
        destruct(this_object());
        return 1;
        }
get()  { return 1; }

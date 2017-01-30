inherit "/obj/armor.c";
int rad_protected;
reset(arg) {
        if(arg) return 0;
        ::reset(arg);
        set_name("suit");
        set_alias("radiation suit");
        set_short("A radiation suit");
        set_long("A well-worn radiation suit, used to protect people from\n"
                +"high doses of radiation. It seems to fail on some account.\n");
        set_ac(3);
        set_weight(5);
        set_value(4000);
}
id(str) { return str == "suit" || str == "radiation suit"; }
query_rad_protected() {
        return rad_protected;
}
init() {
        add_action("wear", "wear");
}
wear(str) {
        if(str != "suit" && str != "radiation suit") return 0;
        if(environment(this_object()) != this_player()) { 
                write("You have to get it first!\n");
                return 1; 
        }        
        rad_protected = 1;
        write("You are now protected from radiation.\n");
        ::wear(str);
        return 1;
}

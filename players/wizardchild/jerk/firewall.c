short() { return "A firewall"; }
long() { short(); return 1; }
id(str) { return str == "firewall"; }
init() { add_action("south", "south");
        add_action("south", "s");
}
south() {
        write("NOT!!!\n");
        return 1;
}

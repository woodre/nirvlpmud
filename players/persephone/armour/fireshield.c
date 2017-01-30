inherit "obj/armor";
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("fireshield");
    set_alias("shield");
    set_type("shield");
    set_short("The Famed Fireshield");
    set_long("This shield has a large fireburst in the middle and some\n" +
                   "intricate runes that depict its history.  Legend has it\n" +
                   "that with the proper command it can be used to cast\n" +
                   "balls of fire but this is only a legend\n");
    set_ac(2);
    set_weight(3);
    set_value(10,000);
}

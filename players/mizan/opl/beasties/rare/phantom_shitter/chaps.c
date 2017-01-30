inherit "obj/armor";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("A pair of leather assless chaps");
    set_long(
    "    Despite the sheer, skin-tight appearance of these fabulous leather chaps,\n"+
    "  they are rather comfortable and not too restrictive to wear. Of course, the\n"+
    "  issue of having one's behind fully exposed could be somewhat troublesome...\n"+
    "  but ten percent of the male population of the world probably won't mind\n"+
    "  that as an issue, and probably regard it as a feature.\n"+
    "  An inscription on the crotchline reads: 'Thank you Freddie Mercury'.\n");
    set_ac(1);
    set_weight(2);
    set_value(800);
    set_name("chaps");
    set_type("pants");
}

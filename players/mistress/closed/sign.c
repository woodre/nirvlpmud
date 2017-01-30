/*  osign.c - this generic sign was designed to replace the current sign
 *            because the current sign is inadequate.
 *  programmer:  Omega the Winged One!
 *  purpose:     I was dissatisfied with obj/sign.c so I made this new
 *               sign.  It is more along the lines of familiarity.
 *  notes:       The old sign could be modified after it was cloned,
 *               but this limited the length of the messages and you
 *               had to be level 30 or above to set the sign.
 *               This new sign must be set using call_other, just like
 *               a monster or weapon.  It uses similar functions and
 *               is more friendly.  Please feel free to clone this
 *               object, but don't copy it into you directory as it
 *               eats up disk space.    *** Omega ***
 */
string name, short_desc, long_desc;
string alias, alt_name;

init() {
    add_action("read","read");
}
    
reset(arg) {
   if(arg) return;
   name = "sign"; short_desc = "A sign";
   long_desc = "This space for rent.\n";
}

id(str) {
    return (str == name || str == alias || str == alt_name);
}

long() {
    write(long_desc);
}


short() {
    return short_desc;
}

get() {
    return 0;
}

read(str) {
    if (!str || !id(str))
        return 0;
    write(long_desc);
    return 1;
}

set_name(str) { name = str; short_desc = str;
   long_desc = "This space for rent.\n";
}

set_alias(str) { alias = str; }

set_alt_name(str) { alt_name = str; }

set_short(str) { short_desc = str; }

set_long(str) { long_desc = str; }

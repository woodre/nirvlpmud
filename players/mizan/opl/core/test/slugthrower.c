inherit "/obj/weapon.c";

int my_operating_mode; /* either single, burst, or auto. Internal counter. */
int my_total_damage; /* the total amount of hitpoint damage we have inflicted */

int my_recoil_strength; /* How strong the recoil is, compared to str */
int is_no_ammo_usable; /* if the weapon can be swung like a club */
int my_no_ammo_wc; /* our weapon class without any ammo */
int is_bayonet_usable; /* if this weapon supports a bayonet */
int my_round_base_damage; /* the base dam this weapon can do per round */
int my_round_rand_damage; /* additional random damage per round */

string my_clip_id; /* the unique string of our clip ID type, like '9.64mm_clip' */
string my_clip_name; /* Used in display, like 'clip' or 'magazine' */
string my_bayonet_id;  /* the unique string of our bayonet attachment like 'm16_bayonet' */
string my_bayonet_name;  /* used in display, like 'bayonet' or 'knife' */
string my_damage_type; /* what sort of hit_player() dam we do, like 'fire' or 'other|bullet' */



void set_clip_id(string arg) { my_clip_id = arg; }
void set_clip_name(string arg) { my_clip_name = arg; }
void set_bayonet_id(string arg) { my_bayonet_id = arg; }
void set_bayonet_name(string arg) { my_bayonet_name = arg; }
void set_damage_type(string arg) { my_damage_type = arg; }

void set_no_ammo_wc(int arg) { my_no_ammo_wc = arg; }
void set_round_base_damage(int arg) { my_round_base_damage = arg; }
void set_round_rand_damage(int arg) { my_round_rand_damage = arg; }

void set_bayonet_usable(int arg) { is_bayonet_usable = arg; }
void set_no_ammo_usable(int arg) { is_no_ammo_usable = arg; }

int is_slugthrower() { return 1; }

reset(int arg)
{
    ::reset(arg);

    if(!arg)
    {
        my_operating_mode = 0; /* single fire is default */
    }
}

init()
{
    ::init();
    add_action("on_load_ammo","load");
    add_action("on_adjust_dial","adjust");
}


/**
 * our short desc.
 *
 *
 */
short()
{
    string result;
    string ammo_type;
    int ammo;
    object ob;

    /* check to see if any ammo is in the weapon, if so we display
     * some information about it.
     */
    ob = present(my_clip_id, this_object());

    /*
     * figure out what kind of ammo we are using
     */
    if (ob)
    {
        ammo = ob->query_ammo();
        ammo_type = ob->query_ammo_type();
    }
    else ammo_type = "none";

    result = short_desc + " [" + ammo + ", " + ammo_type + "]";

    if (wielded) result += " (wielded)";

    /*
     * tack on some wizard information
     */
    if (this_player() && this_player()->query_level() > 39)
        result += " <Total damage inflicted: [" + my_total_damage + "]>";

    return result;
}


/**
 * our long desc.
 *
 *
 */
long()
{
    if (this_player())
    {
        say(capitalize(this_player()->query_name()) +
            " carefully inspects the " + this_object()->query_name() + ".\n");
    }

    if(!long_desc) write("You see nothing special.\n");
    else write(long_desc);

    write("\nThere is a solid knob which you can adjust on this weapon.\n");

    /* display info about the status of the weapon */
    switch (my_operating_mode)
    {
    case (2):
        write("The knob setting says 'FA'.\n");
        break;

    case (1):
        write("The knob setting says 'B'.\n");
        break;

    case (0):
        write("The knob setting says 'S'.\n");
        break;
    }
}


/* how many rounds we have loaded */
get_rounds()
{
    object ob;
    int i;

    ob = present(my_clip_id, this_object());

    if(ob) i = ob->query_ammo();
    else i = 0;

    return i;
}

/**
 *
 * loads the weapon.
 *
 */
on_load_ammo(str)
{
    object ammo;
    int round_weight;
    int rounds;

    if (!str || !id(str)) return 0;

    /*
     * unlike the spuck weapons, we can only load one clip at a time.
     */
    ammo = present(my_ammo_id, this_object());

    if (ammo)
    {
        write("There is already a " + my_clip_name + " loaded.\n");
        say(this_player()->query_name() + " tries loading the " +
            this_object()->query_name() + " when it was already loaded.\n");
        return 1;
    }

    /*
     * check for player having ammo- and the right type.
     */
    ammo = present(my_ammo_id, this_player());

    if (!ammo)
    {
        write("You don't have any " + my_clip_name + "s.\n");
        return 1;
    }

    if (!verify_compatible_ammo(ammo))
    {
        write("That kind of ammunition is not compatible with this weapon.\n");
        say(this_player()->query_name() + " tries loading the " +
            this_object()->query_name() + " with the wrong type of ammunition.\n");
        return 1;
    }

    /*
     * handle the transaction here
     */
    move_object(ammo, this_object());
    round_weight = ammo->query_weight();
    this_player()->add_weight(-round_weight);
    rounds = ammo->query_ammo();

    if (!rounds || rounds > 99999)
    {
        destruct(ammo);
        write("This is not certified ammunition. It is rejected.\n");
    }

    /*
     * now display what we just loaded into the weapon */
    write("You slide a clip of " + ammo->query_ammo_name() +
          " into the " + query_name() + ".\n");

    write("There are [" + rounds() + "] rounds remaining.\n");

    say(capitalize(this_player()->query_name()) +
        " locks and loads a " + my_clip_name + " of " + ammo->query_ammo_name() +
        " into the " + query_name() + ".\n");

    return 1;
}

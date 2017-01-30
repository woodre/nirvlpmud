
/*
 *  A magical weapon with a special sttack.
 *  Read RAPIER.c first.
 *                                                     -- Saber
 */

/* This gives you all the code from weapon.c */
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("blueblade");
    set_alias("blade");
    set_short("A blue blade of fire");
    set_long("A long, thin blade forged from pure blue fire.\n"+
           "It is covered with silver runes.\n");
       /* This will give the set_read() string when a player
        *   types 'read blade'  */
    set_read("This blade was forged by Sengard.\n");
    set_class(15);
    set_weight(2);
    set_value(700);
    set_hit_func(this_object());
}

/* This is called by the weapon for *special* attacks.  */
weapon_hit(attacker){

/* This makes W an intiger */
int W;
/* This sets W equal to a number between 0 to 11 */
W = random(12);

/* If the random number W is greater than 9, than the following happens. */
if(W > 9)  {

/* A say is seen by everybody in the room BUT the user. */
 say("The blue blade of fire blazes a trail of fury through its foe.\n"+
  "You smell something burning.\n");

/* A write is seen ONLY by the user. */
  write("The blue blade of fire blazes a trail of fury through its foe.\n"+
  "You smell something burning.\n");

 /* This return is the additional damage called.  */
return 5;

    }
    return;
}

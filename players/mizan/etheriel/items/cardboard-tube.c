inherit "/players/mizan/core/weapon.c";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("tube");
    set_class(17);
    set_value(800);
    set_weight(1);
    set_alias("tube");
    set_short("A thick cardboard tube");
    set_long(
        "  This is an ordinary-looking cardboard tube, rather light in your hands,\n"+
        "  but as you swing it, you hear a *WHOOSH!* You grin evilly as you imagine\n"+
        "  hitting some poor creature with it.\n");

    set_read("The cardboard tube has no discernable writing on it, but a few scribbles and a peeled-off\n"+
             "section where a mailing label had once been.\n");
    set_smell("The wiffle bat smells like... CARDBOARD! Stop the presses!\n");
    set_taste("The wiffle bat tastes like... CARDBOARD! Fascinating!\n");

    /* this object is limited in number! */
    set_limited_issue(1);
    /* only four at a time can be cloned in the game at all */
    set_limited_issue_count(4);

}

weapon_hit(attacker)
{
    if(random(100) < 12)  
    {
        write("You chortle gleefully as you deftly pound your opponent!\n");
        say((this_player()->query_name())+" deftly whomps some poor soul with a cardboard tube.\n");
        return 4;
    }
}

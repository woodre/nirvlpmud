inherit "/obj/weapon";

reset(arg)
{
    if(arg) return;
    ::reset();
    set_name("bardiche");
    set_alias("axe");
    set_short("Bardiche");
    set_type("axe");
    set_long("\
The bardiche is a long-handled axe. The equally long and curved blade\n\
is fixed high on the steel handle, so that the topmost end of the blade\n\
can be used for stabbing and to some extent cutting both ways. It is an\n\
infantry weapon and not very elegant, but it looks very sturdy.\n");
    set_class(17);
    set_weight(4);
    set_value(767);
    set_hit_func(this_object());
}

weapon_hit(opponent)
{
    int bonus;

    if(!opponent) return; /* wtf */
    
    switch (random(20)) {
      case 0:
        write("Your wild attack catches " + opponent->query_name() +
              " by surprise.\nThe bardiche leaves a nasty wound.\n");
        say(this_player()->query_name() + " swings " +
            this_player()->query_possessive() + " bardiche wildly.\n");
        bonus = 3 + random(5);
        break;

      case 1:
        write("You swing at " + opponent->query_name() + "'s head, but miss.\n");
        say(this_player()->query_name() + " swings " +
            this_player()->query_possessive() + " bardiche at " +
            opponent->query_name() + "'s head, but misses.\n", opponent);
      tell_object(opponent,
          this_player()->query_name() + " swings " +
          this_player()->query_possessive() + " bardiche at " +
          "your head, but misses.\n");
        bonus = -2 - random(3);
        break;
        
      case 2:
        write("You swing your bardiche at " + opponent->query_name() +
              "'s head and you hit!\nBlood spurts from a deep gash.\n");
        say(this_player()->query_name() + " swings " +
            this_player()->query_possessive() + " bardiche at " +
            opponent->query_name() +
            "'s head and hits!\nBlood spurts from a deep gash.\n", opponent);
      tell_object(opponent,
          this_player()->query_name() + " swings " +
          this_player()->query_possessive() + " bardiche at " +
         "your head and hits!\nBlood spurts from a deep gas.\n");
        bonus = 5 + random(3);
        break;
    }
    return bonus;
}

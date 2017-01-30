/*
 *  Summon a storm song for the Bard of Ryllian
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


storm_song()  {

object STORM;

  if(spell(-50,8,75) == -1) return 0;

  if(present("storm_song", TP))  {
    write("\nYou already are singing a storm song!\n\n");
    return 1;
        }

  write("\nExtending your hands to the heavens, you sing\n"+
        "\t\"Di so repada yajika, bemala weso, dakola libuske\"\n"+
        "\t\"Di un seri ski di weso, ju unca ski meske ski repada\"\n\n");
  say("\n"+tp+" extends "+POSS+" hands to the heavens and sings:\n"+
        "\t\"Di so repada yajika, bemala weso, dakola libuske\"\n"+
        "\t\"Di un seri ski di weso, ju unca ski meske ski repada\"\n\n");

  if(COLOR)  {
    tell_room(ENV, "Twin bolts of "+HIY+"lightning"+NORM+" crash from the sky.\n");
    }  else  {
    tell_room(ENV, "Twin bolts of lightning crash from the sky.\n");
    }

  STORM = clone_object("/players/saber/closed/bard/itm/w/ss.c");
  move_object(STORM, TP);

  write("You feel your mind clear and your mind fill with song.\n");
  command("attune", TP);
  say(tp+" face is bathed in a harsh halo of pure light.\n"+
         "An aura of "+BOLD+"power"+NORM+" surrounds "+tp+".\n\n");
  
  call_other(TP, "add_spell_point", -75);
  return 1;
        }

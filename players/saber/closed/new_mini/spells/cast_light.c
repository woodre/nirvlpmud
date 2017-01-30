/*
 *  The Larn ability to summon light.  (v. 2.0)
 *
 */

cast_light(str)  {

  if(this_player()->query_sp() < 10)  {
    write("You don't have enough mana to cast this spell.\n");
    return 1;
        }

  if(set_light(0) < 2)
  set_light(1);
    write("You whisper a prayer and are gifted with light.\n");
    say(this_player()->query_name()+" whispers a prayer.\n"+
      "The room is suddenly filled with light.\n");
  call_other(this_player(), "add_spell_point", -10);
    return 1;
        }

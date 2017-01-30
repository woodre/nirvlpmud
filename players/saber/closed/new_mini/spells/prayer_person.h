/*
 *  A larn spell for mini guild version 2.0
 *  A 'blessing'
 *
 */

prayer_person(str)  {

  object ob;

  if(!str)  {
    write("Who do you want to bless?\n");
    return 1;
        }

  ob = present(str, environment(this_player()));
  if(!ob)  {
    write("That person is not within sight.\n");
    return 1;
        }

  if(ob == this_player())  {
    write("You are already blessed.\n");
    return 1;
        }

  if(spell(-500,1,20) ==-1)  return 0;

  write("You whisper a prayer and bless "+CAP+".\n"+
    CAP+" is surrounded by a silver aura of light.\n");
  say(tp+" whispers a brief prayer over "+CAP+".\n"+
    CAP+" is surrounded by a silver aura of light.\n");

  call_other(this_player(), "add_spell_point", -5);
    return 1;
        }

/*
 *  The ability of blades to raise their luck to 25.  (v. 2.0)
 *
 */

luck()  {
  object bladeob;
  int current;

  current = call_other(this_player(), "query_attrib", "luc");
  bladeob = present("blade_obj",this_player()); 

  if(current  > 19 && bladeob->luc_raised() != 100 )  {
    call_other(this_player(), "raise_luck", 5);
    write("You feel very lucky.\n");
    bladeob->set_luc(100);
    return 1;
       }
  else if(current < 20)  {

    write("Your luck is not high enough.\n");
    return 1;
        }

  else if(current > 30 || bladeob->luc_raised() == 100)  {
    write("You are already lucky enough!\n");
    return 1;
        }
        }

/*
 *  The ability of blades to raise their luck to 25.  (v. 2.0)
 *
 */

luck()  {

  int current;

  current = call_other(this_player(), "query_attrib", "luc");

  if(current == 20)  {
    call_other(this_player(), "raise_luck", 5);
    write("You feel very lucky.\n");
    return 1;
       }
  else if(current < 20)  {

    write("Your luck is not high enough.\n");
    return 1;
        }

  else if(current > 20)  {
    write("You are already lucky enough!\n");
    return 1;
        }
        }

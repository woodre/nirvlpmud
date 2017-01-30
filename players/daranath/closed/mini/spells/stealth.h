/*
 *  The feline ability to raise their stealth from 20 to 25.  (v. 2.0)
 *
 */

stealth()  {

  int current;

  current = call_other(this_player(), "query_attrib", "ste");

  if(current == 20)  {
    call_other(this_player(), "raise_stealth", 5);
    write("You feel very stealthy.\n");
    return 1;
        }

  else if(current < 20)  {
    write("Your stealth is not high enough.\n");
    return 1;
        }

  else if(current > 20)  {
    write("Your stealth is already high enough!\n");
    return 1;
        }
        }

/*
 *  The feline ability to raise their stealth from 20 to 25.  (v. 2.0)
 *
 */

/* updated by wocket 9/21/2003 */
stealth()  {
  object felineob;
  int current;

  current = call_other(this_player(), "query_attrib", "ste");
  felineob=present("feline_obj",this_player()); 

  if(current > 35) {
    write("Your stealth has been readjusted to the max.\n");
    write("Please contact a wizard to find out how you went over the limit.\n");
    call_other(this_player(),"raise_stealth",(35-current));
    return 1;
  }

  if(current > 29){
    call_other(this_player(),"raise_stealth", (35-current) );
    write("You feel very stealth.\n");
    return 1;
  }

  if(current < 30) {
    write("Your stealth is not high enough.\n");
    return 1;
  }
}
/* old code from before stats were raised to 30. variable "ste" in feline object doesn't save. Not a useful variable
  if(current > 19 && felineob->ste_raised() != 100)  {
    call_other(this_player(), "raise_stealth", 5);
    felineob->set_ste(100);
    write("You feel very stealthy.\n");
    return 1;
        }

  else if(current < 20)  {
    write("Your stealth is not high enough.\n");
    return 1;
        }

  else if(current > 30 || felineob->ste_raised() == 100)  {
    write("Your stealth is already high enough!\n");
    return 1;
        }
        }
*/

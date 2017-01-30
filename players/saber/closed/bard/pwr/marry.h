/*
 *  The ability of a Bard to marry people (to each other).
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


wed(str)  {
object RING, RING2, MARK, MARK2;
string WHO, WHO2;

  if(!str || sscanf(str, "%s to %s", WHO, WHO2) != 2)  {
    write("To use type: wed <player> to <player>\n");
    return 1;
        }
        
  MARK  = present(WHO,  ENV);
  MARK2 = present(WHO2, ENV);

  if(MARK->is_player() && MARK2->is_player())  {
  
  if(!MARK)  { 
   write("You must see "+capitalize(WHO)+" before you can perform a wedding.\n");
   write("Syntax: wed < target > < target >\n");
   return 1;
        }
  
  if(!MARK2)  { 
   write("You must see "+capitalize(WHO2)+" before you can perform a wedding.\n");
   write("Syntax: wed < target > < target >\n");
   return 1;
        }

  RING = clone_object("/players/bastion/closed/ring.c");
  RING2 = clone_object("/players/bastion/closed/ring.c");
  RING->set_owner(WHO);  RING->set_spouse(WHO2);
  RING2->set_owner(WHO2);  RING2->set_spouse(WHO);
  move_object(RING2, find_player(WHO2));
  move_object(RING, find_player(WHO));
  write("You give "+WHO2+" a ring.\n");
  write("You give a ring to "+WHO+".\n");
  return 1;
        }

    write(capitalize(WHO)+" and "+capitalize(WHO2)+" must BOTH be players.\n");
    return 1;
        }

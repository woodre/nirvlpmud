#include "/players/guilds/bards/def.h"

status main(string str) {
    int rank;
    string who;
    object who2;
    object gob;
    if (spell(-1000, 1, 0) == -1)
      return 0;

    if(!GOB->query_is_gc())
      FAIL("You're not a GC, and shouldn't even be seeing this.\n"+
           "Please see the Guild Wizard.\n");
    if(!str)
      FAIL("Approve <who> <rank>\n");

    if(sscanf(str, "%s %d", who, rank) != 2)
      FAIL("Approve <who> <rank 3, 5, or 9>\n");

    who2 = present(who, environment(TP));

    if(!who2)
      FAIL("They are not present.\n");

    if(!living(who2))
      FAIL("That is not a Bard.\n");
      
    if(who2==this_player())
      FAIL("Tsk, tsk...\n");

    gob = present("bard_obj", who2);

    if(!gob)
      FAIL("That person is not a Bard.\n");
    
    if(rank !=  3 && rank != 6 && rank != 9)
      FAIL("Approve <who> <rank 3, 6, or 9>\n");

    if((rank == 3 && (int)gob->query_bard_level() != 2) ||
       (rank == 5 && (int)gob->query_bard_level() != 5) ||
       (rank == 9 && (int)gob->query_bard_level() != 8)   )
      FAIL("That Bard is not ready for approval yet.\n");
    
    if((int)gob->query_approval() >= rank)
      FAIL("They are already approved for that rank.\n");

    write_file("/players/guilds/bards/logs/approved",
      TP->query_real_name()+" approved "+who+" for "+rank+" on:\n"+
    ctime(time())+"\n");
    
    gob->set_approval(rank);
    write("You approve "+NAME(who2)+" for rank "+rank+".\n");
    tell_object(who2,
    "You have now been approved for rank "+rank+".\n");
    return 1;
}

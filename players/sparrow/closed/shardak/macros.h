/* macros */
#define qhp(OB) ((int) OB->query_hp())
#define qmhp(OB) ((int) OB->query_mhp())
#define uhp qhp(this_player())
#define umhp qmhp(this_player())

#define qsp(OB) ((int) OB->query_sp())
#define qmsp(OB) ((int) OB->query_msp())
#define usp qsp(this_player())
#define umsp qmsp(this_player())

/* wizard invisibility check */
#define inwizible(OB) ((int) OB->query_invis() > 18)
#define wizardp(OB) ((int) OB->query_level() >= 20)
#define capname ((string) this_player()->query_name())

#define needrank(L) \
if (this_player()->query_guild_rank() < L) \
    return (notify_fail("Your guild rank is too low.\n"), 0)
#define needtask(T) \
if(!previous_object()->query_solved(T) && ((string)this_player()->query_real_name() != "vertebraker" && (string)this_player()->query_real_name() != "verte")) \
    return (notify_fail("You haven't passed the trial.\n"), 0)
#define needmana(S) \
if (qsp(this_player()) < S) \
    return (write("You do not have enough spell points to sacrifice.\n"), 1)
#define nomagic(S) \
if (!environment(this_player()) \
||  S <= (int) environment(this_player())->query_property("no magic")) \
    return (write("The enchanted surroundings cause your spell to fail.\n"), 1)
#define servant(O) (present("shardak_mark", O))
#define friend(O) (present("shardak_mark", O) || present("allymark", O))

/*
status
shardak_death(object x)
{
    object npc;

    if(((int)x->query_hp() <= 0) && !x->query_ghost())
    {
      npc = clone_object("/obj/monster");
      npc->set_name("Shardak");
      x->attacked_by(npc);
      x->death();
      destruct(npc);
      return 1;
    }
    
    return 0;
}
*/

#define shardak_death(x)
        
       

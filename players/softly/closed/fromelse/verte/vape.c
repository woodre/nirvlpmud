inherit "/obj/monster";

/* Simple */
void reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("ape");
    set_alias("jungle ape");
    set_short("A jungle ape");
    set_level(1);
}

/* the ape checking function */
void check_family()
{
    int x;
    object *inv;
    /* if the ape has no environment, discontinue */
    if(!environment()) return;
    /* copy the inventory's contents to an array 'inv' */
    inv = all_inventory(environment());
    
    /* sort through array 'inv' */
    for(x = 0; x < sizeof(inv); x++)
    {
    /* if object 'inv[x]' in array 'inv' is in combat,
       is an ape, and isn't this ape, continue */
      if(inv[x]->query_attack() && 
         inv[x]->id("jungle ape") && inv[x] != this_object())
      {
    /* tell the room we are gunna attack */
        tell_room(environment(), "\
The ape leaps to attack " + 
(string)((object)inv[x]->query_attack())->query_name() + ".\n",
    /* but exclude the prey */
({ inv[x]->query_attack() }));
    /* now tell tha prey */
        tell_object((object)inv[x]->query_attack(), "\
The ape leaps to attack you!\n");
    /* physically attack the fuk'er */
        attack_object((object)inv[x]->query_attack());
    /* discontinue array sort after a target is acquired */
        return;
      }
    }
}

/* new heart_beat function */
void heart_beat()
{
    /* call typical monster functions, attack, healing, etc */
    ::heart_beat();
    /* if we are not in combat, check on the others */
    if(!attacker_ob) check_family();
}

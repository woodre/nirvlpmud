int
weigh_armour(object ob)
{
    int x, arm_weight;
    object *f;

    f = all_inventory(ob);

    for( x = 0; x < sizeof(f); x ++ )
      if((int)f[x]->armor_class() && 
         (status)f[x]->query_worn())
        arm_weight += (int)f[x]->query_weight();

    return arm_weight;
}


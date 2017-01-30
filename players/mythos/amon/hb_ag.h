
/* code tinkered with by Vertebraker [5.31.01]
     hb died .. needed to fix :) */

heart_beat()
{ 
    object *envir, e, *ack;
    int qq, kkk, q;

    ::heart_beat();

    if(!(e = environment())) return;

    if(!query_attack())
    {
      if(!random(10))
      {
        qq = kkk = 0;
        ack = ({ });
        qq = 0;
        kkk = 0;
        envir = all_inventory(e);
        for(q=0;q<sizeof(envir);q++)
        { 
          if(envir[q]->is_player())
          {
            ack += ({ envir[q] });
            qq++;
          }
        }
        q = 0;
        while(q<sizeof(ack) && !kkk)
        {
           if(ack[q] && !random(5))
           {
             attack_object(ack[q]);
             kkk = 1;
           }
           q++;
        } 
      }
  
    } 
    else if(query_attack() == this_object())
      heal_self(100000);
}

inherit "obj/treasure";

int DAMAGE;

reset(arg)
{   if (arg) return;
    set_id("hit_again");
    set_short();
    set_long("");
    set_weight(0);
    set_value(0);
}

drop()  { return 1; }

query_dam()               { return DAMAGE;   }

set_dam(str)  {  DAMAGE = str;  }  

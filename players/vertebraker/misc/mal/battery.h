/*
 * General purpose Battery usage
 */

int BatteryLife;

is_socketable() { return 1; } /* marks an object as socketable */

/* this function manipulates and queries the BatteryLife variable */

BatteryLife(x) {
    if(this_object()->is_laptop())
     if(x)
    {
      while(remove_call_out("deteriorate_battery") != -1);
      call_out("deteriorate_battery", 2);
    }
    return (x ? (BatteryLife = x) : BatteryLife);
}

/* Maximum Battery Life */
MaxBatteryLife() { return 10000; }

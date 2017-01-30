inherit "obj/armor";
reset(arg){
if(arg) return; /* uh.. */
::reset();
set_ac(1);
set_value(300);
set_weight(1);
set_name("ring");
set_short("An Iron Ring");
set_alias("iron ring");
set_long("This ring belonged to Professor X, it is a handsome ring.\n");
set_type("ring");

    set_params("other|mental", 1, 10, "do_mental_special");
}

do_mental_special(owner)
{
     if(!random(6))
     {
       tell_object(owner, "The Iron Ring seems to erect a temporary psychic shield around you.\n");
      return 0502;
    }
}

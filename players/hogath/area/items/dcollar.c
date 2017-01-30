/****************************/
/*Hogath                    */
/*Dog collar                */
/*cc 2004                   */
/****************************/
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
    if(arg) return;
    ::reset(arg);
    set_name(HIW+"D"+HIK+"o"+HIW+"g"+HIK+" C"+HIW+"o"+HIK+"l"+HIW+"l"+HIK+"a"+HIW+"r"+NORM);
    set_alias("collar");
    set_short(HIW+"D"+HIK+"o"+HIW+"g"+HIK+" C"+HIW+"o"+HIK+"l"+HIW+"l"+HIK+"a"+HIW+"r"+NORM);
    set_long("This is a snazy "+HIW+"D"+HIK+"o"+HIW+"g"+HIK+" C"+HIW+"o"+HIK+"l"+HIW+"l"+HIK+"a"+HIW+"r"+NORM+".  It has spikes all around\n"+
             "it and you think it might provide some protection\n"+
             " for your neck if you wear it\n");
    set_ac(1);
    set_type("misc");
    set_weight(1);
    set_value(200);
}



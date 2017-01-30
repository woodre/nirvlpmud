lead(string str, string type){
object att;
if(!TP->query_attack()){ notify_fail("You're not attacking them!\n");return 0;}

att=TP->query_attack();
TP->attack_object(att);
att->attack_object(TP);
tell_room(ETO,TPRN+" growls at "+att+" and grabs it's attention.\n");
return 1;
}

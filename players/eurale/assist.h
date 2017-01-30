assist(string str) {
  object ob, att;
  if(!str) return;
  ob = present(str, environment());
  if(!ob) return;
  att = ob->query_attack();
  if(!att) return;
  if(!query_attack()) attack_object(att);
  return; }

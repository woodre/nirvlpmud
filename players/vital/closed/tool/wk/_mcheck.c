#define writef(s) write_file("/players/vital/logs/REPORT", s)
#include <ansi.h>

query_carry(ob) {
  object n;
  n = first_inventory(ob);
  write("  Carring: [fname]: <val, wc, ac>\n");
  while(n) {
    write("  ["+file_name(n)+"]: <"+n->query_value()+", "+n->query_wc()+", "+n->armor_class()+">\n");
    n = next_inventory(n);
  }
}
query_armor(ob) {
  object n;
  write("  Armor: [fname]: <val, ac, type>\n");
  n = first_inventory(ob);
  while(n) {
    if(n->armor_class())
      write("  ["+file_name(n)+"]: <"+n->query_value()+", "+n->armor_class()+", "+n->query_type()+"\n");
    n = next_inventory(n);
  }
}

check() {
  object ob, atk;
  int i, x;
  ob = users();
  write("Checking users for illegal ac/wc and attacking monsters\n");
  for(i = 0; i < sizeof(ob); i++) {
    if((x = ob[i]->query_wc()) >= 20) {
      write("Player: "+ob[i]->query_real_name()+",\twc: "+x+"\n");
      write("  ["+file_name(ob[i]->query_weapon())+"]\n");
      writef("Player: "+ob[i]->query_real_name()+",\twc: "+x+"\n");
      writef("  ["+file_name(ob[i]->query_weapon())+"]\n");
    }
    atk = ob[i]->query_attack();
    if(ob[i]->query_ac() > 2) query_armor(ob[i]);
    if(atk) {
      write("Player: "+ob[i]->query_real_name()+",\tattack: "+atk->query_name()+"\n");
      write("  atk_align: "+atk->query_alignment()+", atk_lvl: "+atk->query_level()+"\n");
      writef("Player: "+ob[i]->query_real_name()+",\tattack: "+atk->query_name()+"\n");
      writef("  atk_align: "+atk->query_alignment()+", atk_lvl: "+atk->query_level()+"\n");
      query_carry(atk);
    }
  }
  write("Done.\n");
  return 1;
}

main() { return check(); }

get_help()
{
  string help;
  help = "Find illegal objects";
  return help;
}

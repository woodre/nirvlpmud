#include "../defs.h"

main(string str, object caster) {
  object who, Saber;

  if(!str) return 0;
  who = present(str, environment(caster));
  if(!who) return 0;
  if(who->is_kid()) {
    write("KID KILLER!\n");
    if(!PO->query_darkside()) PO->adj_goodness_pool(-random(30));
    return 0;
  }
  if(who->is_pet()) {
    write("PET KILLER!\n");
    if(!PO->query_darkside()) PO->adj_goodness_pool(-random(15));
    return 0;
  }
  return 0;
}

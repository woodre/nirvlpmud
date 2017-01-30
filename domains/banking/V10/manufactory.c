/*
 * manufactory.c
 *
 * An inheritable manufactory, rand /doc/build/manufactory ('man manufactory')
 * for details
 */

#pragma strong_types

#include <message.h>
#include <describe.h>
#include <libs.h>

#define W_MATERIAL 0
#define W_PRICE 1
#define W_RESULT 2
#define W_DESCRIPTION 3


virtual inherit "/basic/message";
virtual inherit "/basic/living/chat";
inherit "/basic/create";


mapping wares;
mapping ware_synonyms;

mixed keeper;
mixed cannot_buy_this_msg;
mixed several_wares_fitting_msg;
mixed order_msg;
mixed not_enough_money_msg;
mixed not_enough_material_msg;
mixed make_ware_msg;

status query_busy() {}

string query_keeper() {
   return describe(keeper || "manufactory keeper", ARTICLE_THE);
}

void set_keeper(mixed arg) {
   keeper = arg;
}


void set_make_ware_msg(mixed arg) {
   make_ware_msg = arg;
}


mixed query_make_ware_msg(string ware, string item_list, int price) {
   if (closurep(make_ware_msg))
      return funcall(make_ware_msg, ware, item_list, price);

   return make_ware_msg || ({
      ({ M_PLAYER, M_PL_VERB, "give", " ", M_PL_POSSESSIVE,
         M_NONE, item_list, " to ", query_keeper(), ", who then vanishes, ", 
         "produces some weird sounds somewhere and returns some ",
         "moments later with a brand new ", ware, " and gives it to ",
         M_PLAYER, "." }),
      ({ query_keeper(), " says: Here you are, ", M_NAME, ", enjoy it." })
   });
}

void set_not_enough_money_msg(mixed arg) {
   not_enough_money_msg = arg;
}


mixed query_not_enough_money_msg(string ware, int price) {
   if (closurep(not_enough_money_msg)) 
      return funcall(not_enough_money_msg, ware, price);
 
   return not_enough_money_msg || ({
      ({ query_keeper(), " says: You can't afford it. To buy ", 
         describe(ware, ARTICLE_A), " you need at least " +
         LIB_MONEY->describe_money(price) + "." })
   });
}


void set_order_msg(mixed arg) {
   order_msg = arg;
}

mixed query_order_msg(string ware) {
   if (closurep(order_msg))
      return funcall(order_msg, ware);
   return order_msg || ({
      ({ M_PLAYER, M_PL_VERB, " order", " ", describe(ware, ARTICLE_A), "." })
   });
}
   

void set_cannot_buy_this_msg(mixed arg) {
   cannot_buy_this_msg = arg;
}

mixed query_cannot_buy_this_msg(string ware) {
   if (closurep(cannot_buy_this_msg)) 
      return funcall(cannot_buy_this_msg, ware);

   return cannot_buy_this_msg || ({ 
      ({ query_keeper(), " says: We don't sell any ", 
         "/lib/language"->plural_word(ware), " here." })
   });
}



void set_several_wares_fitting_msg(mixed arg) {
   several_wares_fitting_msg = arg;
}


mixed query_several_wares_fitting_msg(string ware, string *fitting) {
   if (closurep(several_wares_fitting_msg))
      return funcall(several_wares_fitting_msg, ware, fitting);

   return several_wares_fitting_msg ||
      ({ ({ query_keeper(), " says: You want to have ", 
            describe(ware, ARTICLE_A),
            "? Be more concrete, I could sell you ", 
            make_list(describe_list(fitting), 0, " or "), "." }) });
}



void set_not_enough_material_msg(mixed arg) {
   not_enough_material_msg = arg;
}


mixed query_not_enough_material_msg(string ware, string item_list, int price) {
   if (closurep(not_enough_material_msg))
      return funcall(not_enough_material_msg, ware, item_list, price);
 
   return not_enough_material_msg || ({
      ({ query_keeper(), " says: For " + describe(ware, ARTICLE_A) +
         " you need " + item_list +
         (price ? " and of course " + 
           LIB_MONEY->describe_money(price)  : "") + "." })
   });
}
 

mapping query_wares() { return copy(wares || ([])); }
mapping query_ware_synonyms() { return copy(ware_synonyms || ([])); }


private void add_ware_synonym(string syn, string name) {
   if (!ware_synonyms) ware_synonyms = ([]);

   if (!member(ware_synonyms, syn)) ware_synonyms += ([ syn : ({ name }) ]);
   else ware_synonyms[syn] += ({ name });
}


varargs void 
add_ware(mixed name,mixed material,int price,mixed result,string desc) {
   string *syn;

   if (!wares) wares = ([]);

   if (pointerp(name)) {
      if (sizeof(name) > 1) syn = name[1..];
      name = name[0];
   }

   if (member(wares, name)) 
      raise_error("Duplicate add_ware for identifier '"+name+"'.\n");

   if (!desc) {
      if (closurep(material)) desc = "several unknown things";
      else 
         desc = make_list(map(material, 
            lambda( ({ 'x }),
                    ({ #'describe,
                       ({ #'?,
                          ({ #'closurep, ({ #'[, 'x, 0 }) }),
                          "unknown thing",
                          ({ #'[, 'x, 0 })
                       }),
                       0,
                       0,
                       ({ #'[, 'x, 1 })
                    })
                  )
         ));
   }
                  
   wares += ([ name : material;price;result;desc ]);

   if (syn) filter(syn, #'add_ware_synonym, name);
}



mixed *query_available_wares() {
   int i;
   string *ware_ids;
   mixed *result;

   result = ({});

   ware_ids = m_indices(wares || ([]));

   for (i=0; i<sizeof(ware_ids); i++) 
      result += ({ ({ ware_ids[i], wares[ware_ids[i], W_DESCRIPTION],
         wares[ware_ids[i], W_PRICE] }) });

   return result;
}


private status Wbefore(string id1, string id2)
{
  if (wares[id1,W_PRICE] > wares[id2, W_PRICE]) return 1;
  if (wares[id1,W_PRICE] == wares[id2, W_PRICE])
     return id1 > id2;
  return 0;
}


string print_available_wares() {
   int i;

   string *ware_ids, *tmp_words;
   string result;

   result = "";

   ware_ids = m_indices(wares || ([]));

   if (sizeof(ware_ids)) ware_ids = sort_array(ware_ids, #'Wbefore);

   for (i=0; i<sizeof(ware_ids); i++) {
      if (strlen(wares[ware_ids[i], W_DESCRIPTION]) > 35) {
         tmp_words = explode(
            break_string(wares[ware_ids[i], W_DESCRIPTION], 51, 17, 1), "\n");
      }
      else tmp_words = ({ wares[ware_ids[i], W_DESCRIPTION] });
         
      result += sprintf(" %:-15s %:-35s %:5d cc \n",
         capitalize(ware_ids[i]),  
         capitalize(tmp_words[0]),
         wares[ware_ids[i], W_PRICE]);
      if (sizeof(tmp_words) > 1) result += implode(tmp_words[1..], "\n") + "\n";
   }

   result = "\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\
     Ware               Required materials              Cost\n\
\n\
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" + 
    result + "\n";
   
   tmp_words = explode(result, "\n");
   result = "";
   for (i=0; i<sizeof(tmp_words); i++)
      result += sprintf("       %s%:-62s%s\n",
         (i%2 ? ")" : "("), tmp_words[i], (i%2 ? "(" : ")"));

   return "\n" + result + "\
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
     
   
   
void init() {
   add_action("do_order", "order");
   add_action("do_order", "buy");
}


object *find_material(string ware) {
   mixed *tmp, *needed;
   object ob;
   object *result;
   int i;

   tmp = wares[ware, W_MATERIAL];

   if (closurep(tmp))
     return funcall(tmp, ware);

   needed = ({});

   for (;i<sizeof(tmp); i++) needed += ({ tmp[i][0..] });

   result = ({});

   for (ob=first_inventory(this_player()); ob; ob=next_inventory(ob))
      for (i=sizeof(needed); i--; )
         if ( needed[i] &&
              ( (stringp(needed[i][0]) && ob->id(needed[i][0])) ||
                (closurep(needed[i][0]) && funcall(needed[i][0],ob))
              ) &&
              !ob->drop(1)
            ) {
           result += ({ ob });
            if (!(--needed[i][1])) 
              needed = exclude_element(needed, i);
          
            break;
         }

  return !sizeof(needed) && result;
}


status afford_wares(int price, string str, object tp) {
   if (tp->query_money() < price) {
      message(query_not_enough_money_msg(str, price));
      return 0;
   }
   message(({ LIB_MONEY->pay(price, query_keeper(), tp) }), tp);
   return 1;
}

varargs status do_order(string str, status chat_reaction) {
   object *material, ob;
   object tp;
   string *syn;

   if (!str || str == "") {
      notify_fail("Order what?\n");
      return 0;
   }

   if (!chat_reaction) message(query_order_msg(str));

   /* There seems to be a keeper, but it's obviously dead */
   if (!keeper) return 1;

   str = lower_case(implode(explode(str, " ") - ({ "a", "an", "the" }), " "));

   if (!member(wares, str)) {
      if (!(syn = ware_synonyms[str])) {
         message(query_cannot_buy_this_msg(str));
         return 1;
      }
      if (sizeof(syn) > 1) {
         message(query_several_wares_fitting_msg(str, syn));
         return 1;
      }
      str = syn[0];
   }

   tp = this_player();

   if (!(material = find_material(str))) {
      message(query_not_enough_material_msg(str, wares[str, W_DESCRIPTION],
         wares[str, W_PRICE]));
      return 1;
   }

   if (!afford_wares(wares[str, W_PRICE], str, tp)) return 1;

   if (closurep(wares[str, W_RESULT]))
      ob = funcall(wares[str, W_RESULT], str, material);  
                                         /* material is additionally passed */
   else
      ob = clone_object(wares[str, W_RESULT]);

   map(material, lambda( ({ 'x }),
      ({ #',,   
         ({ #'transfer, 'x, environment(tp) }),
         ({ #'destruct, 'x })
      }))
   );

   message(query_make_ware_msg(str, wares[str, W_DESCRIPTION],
      wares[str, W_PRICE]));

   if (transfer(ob, tp)) move_object(ob, environment(tp));

   return 1;
}



mixed chat_order(string text, string type, object pl, mixed *target) {
   int index, start;
   string *words;

   start = -1;
   text = " " + text;
   if ((index = strstr(text, " buy")) > -1) start = index + 5;
   else if ((index = strstr(text, " order")) > -1) start = index + 7;

   if ( !do_order(
        (start > -1 ? text[start..] :
                      implode(explode(text, " ")[2..], " ")
        ), 1) &&
        keeper
      ) return ({ ({ query_keeper(), " says: What do you want to buy?" }) });
}



void create() {
   if (!keeper) set_keeper("manufactory keeper");
   set_chat_reaction(({ "order", "buy" }), #'chat_order);
}

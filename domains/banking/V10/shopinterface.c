/*
 * This is the V10 shopinterface of the Banking domain
 *
 * To find out how to use it please read the documentation you will
 * find at ~Banking/V10/doc/shops
 */

#include <banking.h>
#include <grammar.h>
#include <message.h>
#include <describe.h>
#include <libs.h>
#include <closures.h>
#include <prop/item.h>
#include <prop/player.h>
#include <wizlevels.h>
#include <limits.h>
#include SHOPINTERFACE_H

inherit "basic/parser";

#define ISWIZARD(x) ((x)->query_level()>=WL_APPRENTICE || \
                     (x)->test_flag(96) || (x)->query_property(P_TESTPLAYER))

#define EVAL_LIMIT (MAX_COST-100000)

private object store;
private string store_file;
private mapping stored_wares;
                      /* this contains the hashed informations about the wares
                       * object -> #, key, value, description   */
private mapping articles;
                      /* this maps the article numbers to the wares         */
private mapping equal_wares;
                      /* this contains the amount of equal wares            */
private int shopkeeper_absent, reset_counter;

object *query_storage() { return m_indices(stored_wares)-({ 0 }); }
mapping query_stored_wares() { return stored_wares; }
mapping query_equal_wares() { return equal_wares; }

/* The following functions can be overloaded by the inheriting object! */

int
query_money()
{
  return this_player()->query_money();
}

mixed
add_money(int amount)
{
  return this_player()->add_money(amount);
}

int
compute_buy_value(int value)
{
  /* we don't want this any longer, we want nice prices */
#if 0  /* this is to lower the values near above 10, 100, 1000 ... */
  int bv, cheaper_bv;
  bv=value<<1;
  cheaper_bv=to_int(bv*0.95);
  if (strlen(to_string(bv))>strlen(to_string(cheaper_bv)))
    return cheaper_bv;
  return bv;
#else
  return value<<1;
#endif
}

int
computer_limited_sell_value(int sell_value)
{
  return VALUESERVER->round(to_int(637*atan(sell_value/637.0)));
}

string qeury_shopkeeper_short() { return "shopkeeper"; }

varargs void
notify_shopkeeper_leaves(int reason)
{
  string reason_string;
  object room;
  room=environment() || this_object();
  if (!shopkeeper_absent)
  {
    switch (reason)
    {
    case SHOPKEEPER_LEAVE_REASON_TAKE_STOCK:
      reason_string=" to take the stock";
      break;
    case SHOPKEEPER_LEAVE_REASON_LOOK_FOR_WARES:
      reason_string=" to look for the requested wares";
      break;
    case SHOPKEEPER_LEAVE_REASON_WRITE_LIST:
      reason_string=" write a list of the requested kind";
      break;
    case SHOPKEEPER_LEAVE_REASON_MAKE_LIST:
      reason_string=" to make a list of the requested kind";
      break;
    case SHOPKEEPER_LEAVE_REASON_COLLECT_WARES:
      reason_string=" to collect the requested wares";
      break;
    case SHOPKEEPER_LEAVE_REASON_MAKE_ROOM:
      reason_string=" to make room for new wares";
      break;
    default:
      reason_string="";
      break;
    }
    tell_room(room,
              capitalize(describe(query_shopkeeper_short(), ARTICLE_THE))+
              " leaves the room"+reason_string+".\n",
              filter(all_inventory(room), #'query_input_pending));
    shopkeeper_absent=1;
  }
}

varargs void
notify_shopkeeper_arrives(int info)
{
  string info_string;
  object room;
  room=environment() || this_object();
  if (shopkeeper_absent)
  {
    switch (info)
    {
    case SHOPKEEPER_ARRIVE_INFO_WITH_PRICELIST:
      info_string=" with a new pricelist";
      break;
    case SHOPKEEPER_ARRIVE_INFO_AFTER_LOOKING:
      info_string=" after looking for the requested wares";
      break;
    case SHOPKEEPER_ARRIVE_INFO_WITH_LIST:
      info_string=" with the requested list";
      break;
    case SHOPKEEPER_ARRIVE_INFO_WITH_WARES:
      info_string=" with the requested wares";
      break;
    case SHOPKEEPER_ARRIVE_INFO_TO_STORE:
      info_string=" and is ready to store new wares";
      break;
    default:
      info_string="";
      break;
    }
    tell_room(room,
              capitalize(describe(query_shopkeeper_short(), ARTICLE_THE))+
              " arrives"+info_string+".\n",
              filter(all_inventory(room), #'query_input_pending));
    shopkeeper_absent=0;
  }
}

void
notify_updating(int i)
{
  object room;
  room=environment() || this_object();
  tell_room(room,
            capitalize(describe(query_shopkeeper_short(), ARTICLE_THE))+
            " has still "+describe("1 thing", 0, 0, i)+" to registrate...\n",
            filter(all_inventory(room),
                         lambda(({ 'x }),
                                ({ (#'<),
                                   ({ (#'call_other), 'x, "query_level" }),
                                   WL_APPRENTICE }))));
}

void
fail_because_busy()
{
  write("But "+describe(query_shopkeeper_short(), ARTICLE_THE)+" isn't here"
        " right now!\n"
        "Please wait a moment, he will be back soon.\n");
}

void fail_buy_because_busy() { fail_because_busy(); }
void fail_sell_because_busy() { fail_because_busy(); }
void fail_list_because_busy() { fail_because_busy(); }
void fail_value_because_busy() { fail_because_busy(); }

void
notify_list(string *wares, int *range)
{
  send_message(({ M_PL_THE, M_PL_VERB, "ask",
                  (" for a list of"+
                   (wares?
                    " "+implode(wares, " ") :
                    " all wares")+
                   (range && (range[0]>0 || range[1] < INT_MAX)?
                    (" with a value of"+
                     (range[0]>0?
                      " "+range[0]+" or above" :
                      "")+
                     (range[0]>0 && range[1] < INT_MAX?
                      " and" :
                      "")+
                     (range[1] < INT_MAX?
                      " "+range[1]+" or below" :
                      "")) :
                    "")+
                   ".") }));
}

void
print_list(string *lines)
{
  this_player()->view_text(implode(lines, "\n"), "shop list");
  this_player()->start_view();
}

void
notify_inspect(object o,int article_number)
{
  send_message(({ M_PL_THE, M_PL_VERB, "inspect", " ",
                  M_PL_ADD, ({
                    "ware #"+article_number,
                    describe(o, ARTICLE_A, DESCRIBE_FULL) }), "." }));
}

void
print_inspect(object o, int value)
{
  mixed h;
  write(o->short()+":\n");
  if (stringp(h=o->long()))
    write(h);
  write("It would cost you "+LIB_MONEY->describe_money(value)+".\n");
  if (ISWIZARD(this_player()))
    write("The valueserver's key for this item is: "+
          VALUESERVER->object2key(o)+"\n"
          "Its object_name is: "+object_name(o)+"\n");
}

void
notify_value(object o)
{
  send_message(({ M_PL_THE, M_PL_VERB, "ask", " for the value of ",
                  M_PL_POSSESSIVE,
                  " " + describe(o, ARTICLE_NONE, DESCRIBE_FULL) + "." }));
}

void
print_value(object o, int value)
{
  write(value?
        "You would get " + LIB_MONEY->describe_money(value) + ".\n" :
        capitalize(describe(o, ARTICLE_THE, DESCRIBE_FULL)) +
        " is worth nothing.\n");
}

void
notify_no_such_ware()
{
  message("None of the wares match your description.\n");
}

/* this is a private function, do not try to override it */
private void
_generate_msg(mixed ware, mixed value)
{
  value = (describe(ware, ARTICLE_THE, DESCRIBE_FULL) + " (" + (value / 10) +
           " s)");
}

void
notify_buy(mapping wares)
{
  if (!sizeof(wares))
    return write("You buy nothing.\n");
  if (sizeof(wares)>20)
  {
    send_message(({ M_PL_THE, M_PL_VERB, "buy", " a lot of things." }));
    write("You pay " +
          LIB_MONEY->describe_money(fold_right(#'+, m_values(wares))) + ".\n");
    return;
  }
  send_message(({ M_SAY, M_PL_THE, M_PL_VERB, "buy",
                  " " + make_list(describe_list(m_indices(wares), ARTICLE_A,
                                                DESCRIBE_FULL)) + "." }));
  walk_mapping(wares, #'_generate_msg);
  message("You buy " + make_list(describe_list(m_values(wares))) + ".\n");
}

void
notify_sell(mapping items)
{
  if (!sizeof(items))
    return write("You sell nothing.\n");
  if (sizeof(items) > 20)
  {
    send_message(({ M_PL_THE, M_PL_VERB, "sell", " a lot of things." }));
#if 0
/* Taking this out for now, this sum seems to be wrong sometimes, it differs
 * from the output which is given at another place so taking it out until
 * somebody finds the time to fix it. Anyway, double output is not necessary.
 */
    write("You get " +
          LIB_MONEY->describe_money(fold_right(#'+, m_values(items))) + ".\n");
#endif
    return;
  }
  send_message(({ M_SAY, M_PL_THE, M_PL_VERB, "sell",
                  " " + make_list(describe_list(m_indices(items),
                                                this_player()->
                                                query_possessive(),
                                                DESCRIBE_FULL)) + "." }));
  walk_mapping(items, #'_generate_msg);
  message("You sell " + make_list(describe_list(m_values(items), "your")) +
          ".\n");
}

varargs string
make_list_line(object o, int article_number, int how_many,
               int price, int width)
{
  string result;
  mixed err;
  if (!o->short())  /* invis item? */
    return sprintf(" #%-4d | %'_':*s%s%'_'5d",
                   article_number,
                   -width+16,
                   "something invisible",
                   (how_many>1? "_a" : "__"),
                   price / 10);
  err = catch(result = sprintf(" #%-4d | %'_':*s%s%'_'5d",
                               article_number,
                               -width+16,  // replaced 17 by 16 Alfe 96-Oct-11
                               describe(o, ARTICLE_A, DESCRIBE_FULL, how_many),
                               (how_many>1? "_a" : "__"),
                               price / 10));
  if (err)
    return sprintf("%s: %O", err, o);
  else
    return result;
}

void
notify_cant_sell(object *items)
{
  string h;
  object *worn;
  if (!this_player())
    return;
  items -= ({ 0 });
  worn = filter(items, (: $1->query_wielded() || $1->query_worn() :));
  if (sizeof(worn))
  {
    h = make_list(describe_list(worn, ARTICLE_NONE, DESCRIBE_FULL));
    message("You should remove your " + h + " before selling " +
            (sizeof(worn) > 1 || worn[0]->query_plural() ? "them" : "it") +
            ".\n");
  }
  if ((h = make_list(describe_list(items, "your", DESCRIBE_FULL))))
    message("You can't sell " + h + ".\n");
}

void
notify_cant_store(object *items)
{
  mixed h;
  if ((h=make_list(describe_list(items, ARTICLE_THE, DESCRIBE_FULL))))
    message("The store won't sell " + h + " again. The valuable" +
            (sizeof(items)==1 ?
             " item is" :
             " items are") +
            " hidden away.\n");
}

void
notify_cant_buy(object *wares)
{
  mixed h;
  if (sizeof(wares) > 20)
    return write("You cannot buy a lot of things.\n");
  if (this_player() &&
      (h=make_list(describe_list(wares, ARTICLE_THE, DESCRIBE_FULL))))
    message("You do not have enough money for " + h + ".\n");
}

void
notify_cant_carry(object *items)
{
  mixed h;
  if (sizeof(items) > 20)
    return write("You cannot carry a lot of your things.\n");
  if (this_player() &&
      (h=make_list(describe_list(items, "your", DESCRIBE_FULL))))
    message("You cannot carry " + h + ".\n");
}

string
list_error()
{
  return ("Please try something like these:\n"
          "list\n"
          "list foods\n"
          "list up to 1000\n"
          "list weapons from 500 to 1000\n"
          "list others ..500\n");
}

string
inspect_error()
{
  return ("Please try something like these:\n"
          "inspect #5234\n"
          "inspect hand axe\n");
}

string
buy_error()
{
  return ("Try to buy one if the items you can see with 'list'.\n"
          "An item can be chosen by its name or by its number (eg"
          " '#5413').\n");
}

string
sell_error()
{
  return ("Try to sell some of your items:\n"
          "sell torch\n"
          "sell torch from bag\n"
          "sell the third torch from my fifth bag\n");
}

string
value_error()
{
  return "Try to estimate the value of one of your things.\n";
}

status
ware_does_not_fit_to_shop(object item)
{
  return !!item->query_decaying();
    /* default: anything that not decays fits. */
}

/* The following functions are internal stuff again */
status
busy()
{
  return member(transpose_array(call_out_info())[0], this_object()) >= 0;
}

void set_store(mixed s);

object
query_store()
{
  if (store)
    return store;
  else  /* oh no!! some silly wizard destructed the store! Let's see
         * how to fix the damage done.
         */
    if (member(store_file, '#') < 0) /* store was blueprint? */
      set_store(store_file);  /* reload it */
    else
      set_store(clone_object(explode(store_file, '#')[0]));
  /* this is risky, sure. but to have no store at all was much worse. */
  return store;
}

static void
update_storage2(object ware, int i)
{
  mixed h, g;
  while (get_eval_cost() > EVAL_LIMIT && ware)
    if (!ware->id("money"))
    {
      h = VALUESERVER->object2key(ware);
      if (equal_wares[h])
        equal_wares[h][0..-1] = ({ ware });
      else
        equal_wares[h] = ({ ware });
      g = VALUESERVER->value(h, ware->query_value());
      stored_wares += ([ ware:
                         1000 + i;
                         h;
                         compute_buy_value(g);
                         describe(ware, ARTICLE_A, DESCRIBE_FULL) + "#" + g ]);
      articles[1000+i] = ware;
      i--;
      ware = next_inventory(ware);
    }
    else
    {
      h = next_inventory(ware);
      destruct(ware);
      ware = h;
    }
  if (ware)
  {
    notify_updating(i);
    efun::call_out("update_storage2", 0, ware, i);
  }
  else
    notify_shopkeeper_arrives(SHOPKEEPER_ARRIVE_INFO_WITH_PRICELIST);
}

void
update_storage()
{
  mixed h;
  while (remove_call_out("update_storage2") >= 0)
    notify_shopkeeper_arrives();
  if (busy())
    return efun::call_out(#'update_storage, 3);
  h = all_inventory(query_store());
  stored_wares = m_allocate(sizeof(h), 4);
  articles = m_allocate(sizeof(h), 1);
  equal_wares = ([]);
  notify_shopkeeper_leaves(SHOPKEEPER_LEAVE_REASON_TAKE_STOCK);
  efun::call_out("update_storage2", 0, sizeof(h) && h[0], sizeof(h));
}

void
set_store(mixed s)
{
  store = stringp(s)? load_object(s) : s;
  if (objectp(store))
    update_storage();
  else
    raise_error("Could not load the store for this shop.\n");
  store_file = object_name(store);
}

#define BIG_RANGE "<big_range>"
#define ONE_WARE "<one_ware>"

status
handle_wizlist_add_money_on_our_own()
{
  return 1;
}

void
reset(status arg)
{
  object ob;
  if (this_object()==find_object(SHOPINTERFACE))
    return;  /* if not inherited do nothing more */
  if (arg)
  {
    if (--reset_counter <= 0)
    {
      update_storage();
      reset_counter = 5;  /* take the stock all 5 resets */
    }
    return;
  }
  add_class(BIG_RANGE, "parse_big_range");
  add_class(ONE_WARE, "parse_one_ware");

  add_rule("list "BIG_RANGE, "list");
  add_rule("list "G_WORDS" "BIG_RANGE, "list");
  add_rule("list "G_WORDS, "list");
  add_rule("list", "list");

  add_rule("inspect "ONE_WARE, "inspect");
  add_error_message("inspect", ({ inspect_error(), 1 }));

  add_rule("buy "G_WORDS" "BIG_RANGE, "buy");
  add_rule("buy "G_WORDS, "buy");
  add_error_message("buy", ({ buy_error(), 1 }));

  add_rule(                "value "G_OBJECT, "value");
  add_rule(     "ask for value of "G_OBJECT, "value");
  add_rule( "ask for the value of "G_OBJECT, "value");
  add_rule(    "estimate value of "G_OBJECT, "value");
  add_rule("estimate the value of "G_OBJECT, "value");
  add_error_message("value", ({ value_error(), 1 }));

  add_rule("sell "           G_IN_INVENTORY, "sell");
  add_rule("sell "    G_ONLY_IN_ENVIRONMENT, "sell");
  add_rule("sell "       G_ALL_IN_INVENTORY, "sell");
  add_rule("sell "G_ALL_ONLY_IN_ENVIRONMENT, "sell");
  add_error_message("sell", ({ sell_error(), 1 }));
}

mixed
parse_one_ware(mixed result, mixed aux, int first, int last,
               string *words, string *text)
{
  if (last-first==1 && words[first]=="#")
    return result=articles[to_int(words[last])];
  return result=present(implode(text[(first<<1)+1..(last<<1)+1], ""),
                        query_store());
}

mixed
parse_big_range(mixed result, mixed aux, int first, int last,
                string *words, string *text)
{
  mixed h, min, max, dummy;
  h = implode(words[first..last], " ");
  if ((sscanf(h, "%d . . %d%s",        min, max, dummy)==3 ||
       sscanf(h, "%d - %d%s",          min, max, dummy)==3 ||
       sscanf(h, "%d-%d%s",            min, max, dummy)==3 ||
       sscanf(h, "from %d up to %d%s", min, max, dummy)==3 ||
       sscanf(h, "from %d to %d%s",    min, max, dummy)==3 ||
       sscanf(h, "%d up to %d%s",      min, max, dummy)==3 ||
       sscanf(h, "%d to %d%s",         min, max, dummy)==3) && dummy=="")
    return result = ({ min*10, max*10 });
  if ((sscanf(h, ". . %d%s",         max, dummy)==2 ||
       sscanf(h, "- %d%s",           max, dummy)==2 ||
       sscanf(h, "-%d%s",            max, dummy)==2 ||
       sscanf(h, "up to %d%s",       max, dummy)==2 ||
       sscanf(h, "%d and below%s",   max, dummy)==2 ||
       sscanf(h, "%d or below%s",    max, dummy)==2 ||
       sscanf(h, "%d and cheaper%s", max, dummy)==2 ||
       sscanf(h, "%d or cheaper%s",  max, dummy)==2 ||
       sscanf(h, "to %d%s",          max, dummy)==2 ||
       sscanf(h, "< = %d%s",         max, dummy)==2) && dummy=="")
    return result = ({ 0, max*10 });
  if ((sscanf(h, "cheaper than %d%s", max, dummy)==2 ||
       sscanf(h, "less than %d%s",    max, dummy)==2 ||
       sscanf(h, "below %d%s",        max, dummy)==2 ||
       sscanf(h, "< %d%s",            max, dummy)==2) && dummy=="")
    return result = ({ 0, (max-1)*10 });
  if ((sscanf(h, "from %d%s",       min, dummy)==2 ||
       sscanf(h, "%d . .%s",        min, dummy)==2 ||
       sscanf(h, "%d -%s",          min, dummy)==2 ||
       sscanf(h, "%d-%s",           min, dummy)==2 ||
       sscanf(h, "%d and above%s",  min, dummy)==2 ||
       sscanf(h, "%d or above%s",   min, dummy)==2 ||
       sscanf(h, "%d and higher%s", min, dummy)==2 ||
       sscanf(h, "%d or higher%s",  min, dummy)==2 ||
       sscanf(h, "%d and more%s",   min, dummy)==2 ||
       sscanf(h, "%d or more%s",    min, dummy)==2 ||
       sscanf(h, "> = %d%s",        min, dummy)==2) && dummy=="")
    return result = ({ min*10, INT_MAX });
  if ((sscanf(h, "more than %d%s",   min, dummy)==2 ||
       sscanf(h, "higher than %d%s", min, dummy)==2 ||
       sscanf(h, "above %d%s",       min, dummy)==2 ||
       sscanf(h, "> %d%s",           min, dummy)==2) && dummy=="")
    return result = ({ (min+1)*10, INT_MAX });
}

static void
parse_ware_job(object *storage, object *wares, int i,
               closure callbak, string *ids, int min, int max, int all)
{
  int j;
  while (get_eval_cost() > EVAL_LIMIG && i--)
  {
    if (stored_wares[storage[i], 2] < min ||
        stored_wares[storage[i], 2] > max)
      continue;
    if (ids[<1]=="all" ||
        ((ids[<1]=="others" || ids[<1]=="other") &&
         !storage[i]->id("armour") && !storage[i]->id("weapon")))
    {
      wares += ({ storage[i] });
      continue;
    }
    if (!all && storage[i]->id(ids[<1]))
      return funcall(callback, ({ storage[i] }), 1);
    for (j=sizeof(ids)-(!all); j--; )
      if (storage[i]->id(ids[j]))
    {
        wares += ({ storage[i] });
        break;
      }
  }
  if (i>0)
  {
    notify_shopkeeper_leaves(SHOPKEEPER_LEAVE_REASON_LOOK_FOR_WARES);
    efun::call_out("parse_ware_job", 0, storage, wares, i, callback, ids,
                   min, max, all);
  }
  else
  {
    notify_shopkeeper_arrives(SHOPKEEPER_ARRIVE_INFO_AFTER_LOOKING);
    funcall(callback, wares, sizeof(wares));
  }
}

static void
parse_ware(string *words, closure callback, int min, int max)
{
  mixed h;
  int all;
  if (sizeof(words)==2 && words[0]=="#" && (h=articles[to_int(words[1])]))
    return funcall(callback, ({ h }), 1);
  h = query_storage();
  all = (words[0]=="all");
  if (sizeof(words) > 1 && words[0]=="all")
    words[0..0] = ({});
  parse_ware_job(h, ({}), sizeof(h), callback,
                 LIB_LANGUAGE->singular_sentences(words), min, max, all);
}

static void
factorize_list(object *wares, int i, closure callback,
               mapping result)
{
  mixed h;
  if (!this_player())
    return;  /* player isn't anymore, so forget this */
  if (!wares || !sizeof(wares))
    return write("Sorry, there are no items in this shop that fit your"
                 " description.\n"+list_error());
  if (!result)
    result = ([]);
  while (get_eval_cost() > EVAL_LIMIT && i--)
    if (result[stored_wares[wares[i], 3]])
      result[stored_wares[wares[i], 3]] += ({ wares[i] });
    else
      result[stored_wares[wares[i], 3]]  = ({ wares[i] });
  if (i>0)
  {
    notify_shopkeeper_leaves(SHOPKEEPER_LEAVE_REASON_MAKE_LIST);
    efun::call_out("factorize_list", 0, wares, i, callback, result);
  }
  else
    funcall(callback, m_values(result), sizeof(result));
}

varargs static void
build_output(mixed *result, int i, int width)
{
  mixed h;
  while (get_eval_cost() > EVAL_LIMIT && i--)
  {
    h = result[i];
    result[i] = make_list_line(h[0], stored_wares[h[0]], sizeof(h),
                               stored_wares[h[0], 2], width);
  }
  if (i>0)
  {
    notify_shopkeeper_leaves(SHOPKEEPER_LEAVE_REASON_WRITE_LIST);
    efun::call_out("build_output", 0, result, i, width);
  }
  else
  {
    notify_shopkeeper_arrives(SHOPKEEPER_ARRIVE_INFO_WITH_LIST);
    print_list(result);
  }
}

status
list(string *words, int *range)
{
  int width;
  if (busy())
    return fail_list_because_busy(), 1;
  if (!range)
    range = ({ 0, INT_MAX });
  notify_list(words, range);
  if (!words || !sizeof(words))
    words = ({ "all" });
  else if (words[0] != "all")
    words[0..-1] = ({ "all" });
  width = this_player()->query_property(P_DISPLAY_WIDTH) || 79;
  parse_ware(words,
             lambda(({ 'words, 'i }),
                    ({ (#'factorize_list),
                       'words,
                       'i,
                       lambda(({ 'result, 'x }),
                              ({ (#'build_output), 'result, 'x, width })) })),
             range[0], range[1]);
  return 1;
}

status
inspect(object o)
{
  notify_inspect(o, stored_wares[o]);
  print_inspect( o, stored_wares[o, 2]);
  return 1;
}

void
unstore(object o, object destination)
{
  if (!member(stored_wares, o))
    return;
  equal_wares[stored_wares[o, 1]] -= ({ o });
  m_delete(articles, stored_wares[o]);
  m_delete(stored_wares, o);
  move_object(o, destination);
}

static void
buy_wares(object *wares, int i, object *not_bought,
          object *too_heavy, mapping result)
{
  int money_paid;
  mixed mm;

  if (!sizeof(wares))
    notify_no_such_ware();
  if (!not_bought)
    not_bought = ({});
  if (!too_heavy)
    too_heavy = ({});
  if (!result)
    result = ([]);
  while (get_eval_cost() > EVAL_LIMIT && i--)
  {
    if (stored_wares[wares[i], 2] > query_money()-money_paid)
    {
      not_bought += ({ wares[i] });
      wares[i..i] = ({});
    }
    else
    {
      result[wares[i]] = stored_wares[wares[i], 2];
      "/global/wizlist"->add_money(-stored_wares[wares[i], 2], this_object());
      money_paid += stored_wares[wares[i], 2];
      BANKINGSTATISTIC->player_buys(this_player(), stored_wares[wares[i], 2]);
      VALUESERVER->buy(stored_wares[wares[i], 1]);
      unstore(wares[i], environment(this_player()));
      if (transfer(wares[i], this_player()))
        too_heavy += ({ wares[i] });
    }
  }
  if (money_paid)
  {
      mmm = add_money(-money_paid);
      if (mmm && mappingp(mmm))
        send_message(({ M_WRITE }) +
                     LIB_MONEY->paying_message(mmm, query_shopkeeper_short()));
  }
  if (i>0)
  {
    notify_shopkeeper_leaves(SHOPKEEPER_LEAVE_REASON_COLLECT_WARES);
    efun::call_out("buy_wares", 0, wares, i, not_bought, too_heavy, result);
  }
  else
  {
    notify_shopkeeper_arrives(SHOPKEEPER_ARRIVE_INFO_WITH_WARES);
    if (get_eval_cost() > EVAL_LIMIT)
    {
      notify_cant_buy(not_bought);
      if (get_eval_cost() > EVAL_LIMIT)
      {
        notify_buy(result);
        if (get_eval_cost() > EVAL_LIMIT)
          notify_cant_carry(too_heavy);
        else
          efun::call_out(#'notify_cant_carry, 0, too_heavy);
      }
      else
      {
        efun::call_out(#'notify_buy, 0, result);
        efun::call_out(#'notify_cant_carry, 0, too_heavy);
      }
    }
    else
    {
      efun::call_out(#'notify_cant_buy, 0, not_bought);
      efun::call_out(#'notify_buy, 0, result);
      efun::call_out(#'notify_cant_carry, 0, too_heavy);
    }
  }
}

status
buy(string *wares, int *range)
{
  if (busy())
    return fail_buy_because_busy(), 1;
  if (sizeof(wares) > 1 && wares[0]=="all")
    wares[0..0] = ({});
  if (range)
    parse_ware(wares, #'buy_wares, range[0], range[1]);
  else
    parse_ware(wares, #'buy_wares, 0, INT_MAX);
  return 1;
}

status too_many(mixed key) { return sizeof(equal_wares[key]) >= 5; }

#define NOT_OBJECT 1
#define NOT_BUYABLE 2
#define TOO_MANY_EQUAL 3

int
store(object o)
{
  int i, buy_value, sell_value;
  string sort_string;
  mixed key;
  if (!objectp(o))
    return NOT_OBJECT;
  if (o->query_not_buyable() || o->query_property(P_NOT_BUYABLE))
    return NOT_BUYABLE;
  key = VALUESERVER->object2key(o);
  sell_value = VALUESERVER->value(key, o->query_value());
  buy_value = compute_buy_value(sell_value);
  sort_string = describe(o, ARTICLE_A, DESCRIBE_FULL) + "#" + sell_value;
  map(equal_wares[key] || ({}),
            lambda(({ 'x }),
                   ({ (#', ),
                      ({ (#'=),
                         ({ CL_INDEX, stored_wares, 'x, 2 }),
                         buy_value }),
                      ({ (#'=),
                         ({ CL_INDEX, stored_wares, 'x, 3 }),
                         sort_string }) })));
  if (too_many(key))
    return TOO_MANY_EQUAL;
  if (equal_wares[key])
    equal_wares[key][0..-1] = ({ o });
  else
    equal_wares[key] = ({ o });
  do
    i = random(9000) + 1000;
  while (member(articles, i));
  articles[i] = o;
  stored_wares += ([ o: i;
                     key;
                     buy_value;
                     sort_string ]);
  move_object(o, query_store());
}

static varargs void
sell_items(object *items, int i, object *not_sold,
           object *not_stored, mapping result)
{
  int money_received;
  mixed mmm;
  string name;
  if (!not_stored)
    not_stored = ({});
  if (!not_sold)
    not_sold = ({});
  if (!result)
    result = ([]);
  while (get_eval_cost() > EVAL_LIMIT && i--)
  {
    name = items[i]->short();
    if (!items[i]                                       ||
        items[i]->query_worn()                          ||
        items[i]->query_wielded()                       ||
        items[i]->query_property(P_NOT_SELLABLE)        ||
        ware_does_not_fit_to_shop(items[i])             ||
        items[i]->drop(1) || !items[i]->query_value()   ||
        first_inventory(items[i])                       ||
        (result[items[i]]=
         compute_limited_sell_value(VALUESERVER->value(items[i]))) <= 0 ||
        transfer(items[i], query_store())) {
      not_sold += ({ items[i] });
      m_delete(result, items[i]);
    }
    else
    {
      money_received += result[items[i]];
      "/global/wizlist"->add_money(result[items[i]], items[i]);
      BANKINGSTATISTIC->player_sells(this_player(), result[items[i]]);
      switch (store(items[i]))
      {
      case NOT_BUYABLE:
        not_stored += ({ items[i] });
        /* fall through */
      case TOO_MANY_EQUAL:
        VALUESERVER->sell(items[i]);
        efun::call_out(#'destruct, 5, items[i]);
        move_object(items[i], query_store());
        break;
      default:
        VALUESERVER->sell(stored_wares[items[i], 1]);
      }
    }
  }
  if (money_received)
  {
     mmm = add_money(money_received);
     if (mmm && mappingp(mmm))
        send_message(({ M_WRITE, M_THE, query_shopkeeper_short(),
          " hands you " + LIB_MONEY->describe_money(mmm) + "." }));
     money_received = 0;
  }
  if (i > 0)
  {
    efun::call_out("sell_items", 0, items, i, not_sold, not_stored, result);
    notify_shopkeeper_leaves(SHOPKEEPER_LEAVE_REASON_MAKE_ROOM);
  }
  else
  {
    notify_shopkeeper_arrives(SHOPKEEPER_ARRIVE_INFO_TO_STORE);
    if (get_eval_cost() > EVAL_LIMIT) {
      notify_cant_sell(not_sold);
      if (get_eval_cost() > EVAL_LIMIT) {
        notify_sell(result);
        if (get_eval_cost() > EVAL_LIMIT)
          notify_cant_store(not_stored);
        else
          efun::call_out(#'notify_cant_store, 0, not_stored);
      }
      else
      {
        efun::call_out(#'notify_sell, 0, result);
        efun::call_out(#'notify_cant_store, 0, not_stored);
      }
    }
    else
    {
      efun::call_out(#'notify_cant_sell, 0, not_sold);
      efun::call_out(#'notify_sell, 0, result);
      efun::call_out(#'notify_cant_store, 0, not_stored);
    }
  }
}

status
sell(object *items)
{
  if (busy())
    return fail_sell_because_busy(), 1;
  sell_items(items, sizeof(items));
  return 1;
}

status
value(object o)
{
  mixed h;
  if (busy())
    return fail_value_because_busy(), 1;
  notify_value(o);
  print_value(o, compute_limited_sell_value(VALUESERVER->value(o)));
  return 1;
}

status
do_action(string action, mapping m)
{
  mixed h;
  switch (action)
  {
  case "list":
    return list(m[G_WORDS, 1], m[BIG_RANGE]);
  case "inspect":
    return inspect(m[ONE_WARE]);
  case "buy":
    return buy(m[G_WORDS, 1], m[BIG_RANGE]);
  case "sell":
    if (m[G_ALL_IN_INVENTORY])
      return sell(m[G_ALL_IN_INVENTORY][0..m[G_ALL_IN_INVENTORY, 1][1]-1]);
    else if (m[G_ALL_ONLY_IN_ENVIRONMENT])
      return sell(m[G_ALL_ONLY_IN_ENVIRONMENT]
                  [0..m[G_ALL_ONLY_IN_ENVIRONMENT, 1][1]-1]);
    else if (m[G_IN_INVENTORY])
      return sell(({ m[G_IN_INVENTORY] }));
    else if (m[G_ONLY_IN_ENVIRONMENT])
      return sell(({ m[G_ONLY_IN_ENVIRONMENT] }));
    else
      raise_error("Internal error in the shop interface\n");
  case "value":
    return value(m[G_OBJECT]);
  }
}

void init() { add_actions(); }

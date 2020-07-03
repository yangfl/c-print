#include <stdio.h>

#ifndef PRINT_H
#define PRINT_H


#define PRINT__PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define PRINT__CAT(a, ...) PRINT__PRIMITIVE_CAT(a, __VA_ARGS__)


// nargs

#define PRINT__PRIMITIVE_CAR(arg1, ...) arg1
#define PRINT__CAR(...) PRINT__PRIMITIVE_CAR(__VA_ARGS__)
#define PRINT__PRIMITIVE_CDR(arg1, arg2...) arg2
#define PRINT__CDR(...) PRINT__PRIMITIVE_CDR(__VA_ARGS__)

#define PRINT__GET_1ST_ARG(arg1, ...) arg1
#define PRINT__GET_2ND_ARG(arg1, arg2, ...) arg2
#define PRINT__GET_3RD_ARG(arg1, arg2, arg3, ...) arg3
#define PRINT__GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4
#define PRINT__GET_5TH_ARG(arg1, arg2, arg3, arg4, arg5, ...) arg5
#define PRINT__GET_6TH_ARG(arg1, arg2, arg3, arg4, arg5, arg6, ...) arg6
#define PRINT__GET_7TH_ARG(arg1, arg2, arg3, arg4, arg5, arg6, arg7, ...) arg7

#define PRINT__VA_NARGS_IMPL(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, N, ...) N
#define PRINT__PRIMITIVE_VA_NARGS(...) PRINT__VA_NARGS_IMPL(x, ## __VA_ARGS__, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define PRINT__VA_NARGS(...) PRINT__PRIMITIVE_VA_NARGS(__VA_ARGS__)


// bool

#define PRINT__CHECK(...) PRINT__GET_2ND_ARG(__VA_ARGS__, 0)

#define PRINT__NOT(x) PRINT__CHECK(PRINT__PRIMITIVE_CAT(PRINT__NOT_, x))
#define PRINT__NOT_0 ~, 1,

#define PRINT__COMPL(b) PRINT__PRIMITIVE_CAT(PRINT__COMPL_, b)
#define PRINT__COMPL_0 1
#define PRINT__COMPL_1 0

#define PRINT__BOOL(x) PRINT__COMPL(PRINT__NOT(x))

#define PRINT__IIF(c) PRINT__PRIMITIVE_CAT(PRINT__IIF_, c)
#define PRINT__IIF_01(...) __VA_ARGS__
#define PRINT__IIF_0(...) PRINT__IIF_01
#define PRINT__IIF_10(...)
#define PRINT__IIF_1(...) __VA_ARGS__ PRINT__IIF_10

#define PRINT__IF_INDIRECT() PRINT__IF
#define PRINT__IF(c) PRINT__IIF(PRINT__BOOL(c))

#define PRINT__IIFALL(c) PRINT__PRIMITIVE_CAT(PRINT__IIFALL_, c)
#define PRINT__IIFALL_0(...)
#define PRINT__IIFALL_1(...) __VA_ARGS__

#define PRINT__IFALL(c) PRINT__IIFALL(PRINT__BOOL(c))

#define PRINT__LAND(a, b) PRINT__CAT(PRINT__ILAND_, PRINT__CAT(a, b))
#define PRINT__ILAND_00 0
#define PRINT__ILAND_01 0
#define PRINT__ILAND_10 0
#define PRINT__ILAND_11 1

#define PRINT__LOR(a, b) PRINT__CAT(PRINT__ILOR_, PRINT__CAT(a, b))
#define PRINT__ILOR_00 0
#define PRINT__ILOR_01 1
#define PRINT__ILOR_10 1
#define PRINT__ILOR_11 1


// while

#define PRINT__EMPTY()
#define PRINT__DEFER(id) id PRINT__EMPTY()
#define PRINT__OBSTRUCT(id) id PRINT__DEFER(PRINT__EMPTY)()
#define PRINT__EXPAND(...) __VA_ARGS__

#define PRINT__EVAL1(...) __VA_ARGS__
#define PRINT__EVAL2(...) PRINT__EVAL1(PRINT__EVAL1(PRINT__EVAL1(__VA_ARGS__)))
#define PRINT__EVAL3(...) PRINT__EVAL2(PRINT__EVAL2(PRINT__EVAL2(__VA_ARGS__)))
#define PRINT__EVAL(...) PRINT__EVAL3(PRINT__EVAL3(PRINT__EVAL3(__VA_ARGS__)))

#define PRINT__WHILE_INDIRECT() PRINT__WHILE
#define PRINT__WHILE(pred, op, ...) \
  PRINT__IF(pred(__VA_ARGS__)) ( \
    PRINT__OBSTRUCT(PRINT__WHILE_INDIRECT)() (pred, op, op(__VA_ARGS__)) \
  ) ( \
    __VA_ARGS__ \
  )

#define PRINT__IS_0(x) PRINT__CHECK(PRINT__PRIMITIVE_CAT(PRINT__IS_0_, x))
#define PRINT__IS_0_0 ~, 1,

#define PRINT__IS_1(x) PRINT__CHECK(PRINT__PRIMITIVE_CAT(PRINT__IS_1_, x))
#define PRINT__IS_1_1 ~, 1,

#define PRINT__IS_EMPTY(x) PRINT__CHECK(PRINT__PRIMITIVE_CAT(PRINT__IS_EMPTY_, x))
#define PRINT__IS_EMPTY_ ~, 1,

#define PRINT__IS_NO_ARGS(...) PRINT__IS_0(PRINT__VA_NARGS(__VA_ARGS__))
#define PRINT__IS_ARGS(...) PRINT__COMPL(PRINT__IS_NO_ARGS(__VA_ARGS__))
#define PRINT__IS_ONE_ARGS(...) PRINT__IS_1(PRINT__VA_NARGS(__VA_ARGS__))
#define PRINT__IS_TWO_OR_MORE_ARGS(...) PRINT__COMPL(PRINT__IS_ONE_ARGS(__VA_ARGS__))

#define PRINT__OR(a, b) PRINT__IF(PRINT__IS_EMPTY(a)) (b) (a)

#define PRINT__SELECT_CONTINUE(pred, ...) \
  PRINT__IF(PRINT__IS_ARGS(__VA_ARGS__)) ( \
    PRINT__EVAL(PRINT__SELECT_INDIRECT () (pred, __VA_ARGS__)) \
  ) ( \
  )
#define PRINT__SELECT_INDIRECT() PRINT__SELECT PRINT__EMPTY()
#define PRINT__SELECT(pred, x, ...) \
  PRINT__IF(pred(x)) ( \
    x \
  ) ( \
    PRINT__SELECT_CONTINUE(pred, __VA_ARGS__) \
  )


// SEP

#define PRINT__DEFAULT_SEP " "

#define PRINT__IS_SEP(x, ...) PRINT__CHECK(PRINT__PRIMITIVE_CAT(PRINT__IS_SEP_, x))
#define PRINT__IS_SEP_SEP ~, 1,

#define PRINT__FILTER_SEP(x, ...) PRINT__IF(PRINT__IS_SEP(x)) (x) (__VA_ARGS__)
#define PRINT__SELECT_SEP(...) PRINT__FILTER_SEP(PRINT__EVAL(PRINT__WHILE(PRINT__IS_TWO_OR_MORE_ARGS, PRINT__FILTER_SEP, __VA_ARGS__, SEP PRINT__DEFAULT_SEP)))

#define PRINT__HAS_SEP(...) PRINT__IS_SEP(PRINT__SELECT_SEP(__VA_ARGS__))

#define PRINT__STRIP_SEP_SEP
#define PRINT__STRIP_SEP(x) PRINT__EXPAND(PRINT__CAT(PRINT__STRIP_SEP_, x))

#define PRINT__GET_SEP(...) PRINT__STRIP_SEP(PRINT__SELECT_SEP(__VA_ARGS__))


// END

#define PRINT__DEFAULT_END "\n"

#define PRINT__IS_END(x, ...) PRINT__CHECK(PRINT__PRIMITIVE_CAT(PRINT__IS_END_, x))
#define PRINT__IS_END_END ~, 1,

#define PRINT__FILTER_END(x, ...) PRINT__IF(PRINT__IS_END(x)) (x) (__VA_ARGS__)
#define PRINT__SELECT_END(...) PRINT__FILTER_END(PRINT__EVAL(PRINT__WHILE(PRINT__IS_TWO_OR_MORE_ARGS, PRINT__FILTER_END, __VA_ARGS__, END PRINT__DEFAULT_END)))

#define PRINT__HAS_END(...) PRINT__IS_END(PRINT__SELECT_END(__VA_ARGS__))

#define PRINT__STRIP_END_END
#define PRINT__STRIP_END(x) PRINT__EXPAND(PRINT__CAT(PRINT__STRIP_END_, x))

#define PRINT__GET_END(...) PRINT__STRIP_END(PRINT__SELECT_END(__VA_ARGS__))


// FILE

#define PRINT__DEFAULT_FILE stdout

#define PRINT__IS_FILE(x, ...) PRINT__CHECK(PRINT__PRIMITIVE_CAT(PRINT__IS_FILE_, x))
#define PRINT__IS_FILE_FILE ~, 1,

#define PRINT__FILTER_FILE(x, ...) PRINT__IF(PRINT__IS_FILE(x)) (x) (__VA_ARGS__)
#define PRINT__SELECT_FILE(...) PRINT__FILTER_FILE(PRINT__EVAL(PRINT__WHILE(PRINT__IS_TWO_OR_MORE_ARGS, PRINT__FILTER_FILE, __VA_ARGS__, FILE PRINT__DEFAULT_FILE)))

#define PRINT__HAS_FILE(...) PRINT__IS_FILE(PRINT__SELECT_FILE(__VA_ARGS__))

#define PRINT__STRIP_FILE_FILE
#define PRINT__STRIP_FILE(x) PRINT__EXPAND(PRINT__CAT(PRINT__STRIP_FILE_, x))

#define PRINT__GET_FILE(...) PRINT__STRIP_FILE(PRINT__SELECT_FILE(__VA_ARGS__))


// keyword

#define PRINT__IS_KEYWORD(x, ...) PRINT__CHECK(PRINT__PRIMITIVE_CAT(PRINT__IS_KEYWORD_, x))
#define PRINT__IS_KEYWORD_SEP ~, 1,
#define PRINT__IS_KEYWORD_END ~, 1,
#define PRINT__IS_KEYWORD_FILE ~, 1,

#define PRINT__NEXT_ARGS_INDIRECT() PRINT__NEXT_ARGS
#define PRINT__NEXT_ARGS(...) \
  PRINT__IF(PRINT__LAND(PRINT__IS_ARGS(PRINT__CDR(__VA_ARGS__)), PRINT__IS_KEYWORD(PRINT__CAR(__VA_ARGS__)))) ( \
    PRINT__OBSTRUCT(PRINT__NEXT_ARGS_INDIRECT)() (PRINT__CDR(__VA_ARGS__)) \
  ) ( \
    PRINT__IF(PRINT__IS_KEYWORD(PRINT__CAR(__VA_ARGS__))) ( \
    ) ( \
      __VA_ARGS__ \
    ) \
  )

#define PRINT__IS_UNDERSCORE(x, ...) PRINT__CHECK(PRINT__PRIMITIVE_CAT(PRINT__IS_UNDERSCORE_, x))
#define PRINT__IS_UNDERSCORE__ ~, 1,
#define PRINT__STRIP_UNDERSCORE__
#define PRINT__STRIP_UNDERSCORE(x) PRINT__EXPAND(PRINT__CAT(PRINT__STRIP_UNDERSCORE_, x))
#define PRINT__STRIP_ANY_UNDERSCORE(x) PRINT__IF(PRINT__IS_UNDERSCORE(x)) (PRINT__EXPAND(PRINT__CAT(PRINT__STRIP_UNDERSCORE_, x))) (x)

#define PRINT__ARGS_FILTER_FOREACH_INDIRECT() PRINT__ARGS_FILTER_FOREACH
#define PRINT__ARGS_FILTER_FOREACH(...) \
  PRINT__IF(PRINT__LOR(PRINT__IS_NO_ARGS(PRINT__CDR(__VA_ARGS__)), PRINT__IS_KEYWORD(PRINT__CAR(PRINT__CDR(__VA_ARGS__))))) ( \
    PRINT__STRIP_ANY_UNDERSCORE(PRINT__CAR(__VA_ARGS__)) \
  ) ( \
    PRINT__STRIP_ANY_UNDERSCORE(PRINT__CAR(__VA_ARGS__)), \
    PRINT__OBSTRUCT(PRINT__ARGS_FILTER_FOREACH_INDIRECT)() (PRINT__CDR(__VA_ARGS__)) \
  )

#define PRINT__ARGS_FILTER(...) PRINT__EVAL( \
  PRINT__ARGS_FILTER_FOREACH(PRINT__EVAL(__VA_ARGS__)) \
)


// format

#define PRINT_GET_FORMAT_SPECIFIER_SEP(sep, arg) _Generic((arg), \
  char: "%c" sep, \
  unsigned char: "%c" sep, \
  int: "%d" sep, \
  unsigned int: "%u" sep, \
  long: "%l" sep, \
  unsigned long: "%ul" sep, \
  long long: "%ll" sep, \
  unsigned long long: "%ull" sep, \
  float: "%f" sep, \
  double: "%f" sep, \
  char *: "%s" sep, \
  char[sizeof(arg)]: "%s" sep, \
  void *: "%p" sep, \
  default: "UNKNOWN" sep \
)

#define PRINT__ARG(specifier, arg) ret += fprintf(out, specifier, arg);

#define PRINT__PRIMITIVE_ARGS_FOREACH_INDIRECT() PRINT__PRIMITIVE_ARGS_FOREACH
#define PRINT__PRIMITIVE_ARGS_FOREACH(sep, end, x, ...) \
  PRINT__IF(PRINT__IS_NO_ARGS(__VA_ARGS__)) ( \
    PRINT__ARG(PRINT_GET_FORMAT_SPECIFIER_SEP(end, x), x) \
  ) ( \
    PRINT__ARG(PRINT_GET_FORMAT_SPECIFIER_SEP(sep, x), x) \
    PRINT__OBSTRUCT(PRINT__PRIMITIVE_ARGS_FOREACH_INDIRECT)() (sep, end, __VA_ARGS__) \
  )
#define PRINT__ARGS_FOREACH(...) PRINT__PRIMITIVE_ARGS_FOREACH(__VA_ARGS__)

#define PRINT__ARGS(...) PRINT__EVAL( \
  PRINT__ARGS_FOREACH(PRINT__GET_SEP(__VA_ARGS__), PRINT__GET_END(__VA_ARGS__), PRINT__ARGS_FILTER(__VA_ARGS__)) \
)


#define print(...) ({ \
  FILE *out = PRINT__GET_FILE(__VA_ARGS__); \
  int ret = 0; \
  PRINT__ARGS(__VA_ARGS__) \
  ret; \
})


#endif /* PRINT_H */

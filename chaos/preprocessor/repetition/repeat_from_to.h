# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_H
# define CHAOS_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_REPEAT_FROM_TO */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_FROM_TO(from, to, macro, ...) CHAOS_PP_REPEAT_FROM_TO_S(CHAOS_PP_STATE(), from, to, macro, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_FROM_TO_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_FROM_TO_ID)()
# else
#    define CHAOS_PP_REPEAT_FROM_TO(from, to, macro, data) CHAOS_PP_REPEAT_FROM_TO_S(CHAOS_PP_STATE(), from, to, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_FROM_TO_ID() CHAOS_PP_REPEAT_FROM_TO
#
# /* CHAOS_PP_REPEAT_FROM_TO_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_FROM_TO_S(s, from, to, macro, ...) CHAOS_IP_REPEAT_FROM_TO_U(s, from, to, macro, (__VA_ARGS__))
#    define CHAOS_PP_REPEAT_FROM_TO_S_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_FROM_TO_S_ID)()
# else
#    define CHAOS_PP_REPEAT_FROM_TO_S(s, from, to, macro, data) CHAOS_IP_REPEAT_FROM_TO_U(s, from, to, macro, (data))
# endif
#
# define CHAOS_PP_REPEAT_FROM_TO_S_ID() CHAOS_PP_REPEAT_FROM_TO_S
#
# define CHAOS_IP_REPEAT_FROM_TO_U(s, from, to, macro, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_REPEAT_FROM_TO_I(CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), from, to, macro, CHAOS_PP_TRAMPOLINE(macro), pd)) \
    /**/
# define CHAOS_IP_REPEAT_FROM_TO_INDIRECT() CHAOS_IP_REPEAT_FROM_TO_I
# define CHAOS_IP_REPEAT_FROM_TO_I(s, o, from, to, macro, _m, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(from, to))( \
        CHAOS_IP_REPEAT_FROM_TO_II, CHAOS_PP_TUPLE_EAT(7) \
    )(s, o, from, CHAOS_PP_DEC(to), macro, _m, pd) \
    /**/
# define CHAOS_IP_REPEAT_FROM_TO_II(s, o, from, to, macro, _m, pd) \
    CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_REPEAT_FROM_TO_INDIRECT)()( \
        CHAOS_PP_NEXT(s), o, from, to, macro, _m, pd \
    )) \
    _m()(o, macro, to CHAOS_PP_COMMA() CHAOS_PP_UNPACK pd) \
    /**/
#
# endif
